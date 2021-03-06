// ***************************************************************************
// *                                                                         *
// *           Aflow STEFANO CURTAROLO - Duke University 2003-2015           *
// *                Aflow PINKU NATH - Duke University 2014-2018             *
// *                                                                         *
// ***************************************************************************
// Written by Pinku Nath
// pn49@duke.edu

/*
   This class computes Gruneisen parameters using QHA method [Ref. Comp. Mat. Sci. 125, 82–91 (2016)]
*/

#include "aflow_apl.h"
#include <iterator>

#define _isnegative(a) (a<MIN_EIGEN_TRESHOLD) ? true : false

#undef AFLOW_APL_MULTITHREADS_ENABLE

#if GCC_VERSION >= 40400   // added two zeros
#define AFLOW_APL_MULTITHREADS_ENABLE 1
#include <thread>
#else
#warning "The multithread parts of APL will be not included, since they need gcc 4.4 and higher (C++0x support)."
#endif

namespace apl
{
  // ***************************************************************************************
  QHA::QHA( IPhononCalculator& pc, QHA_AFLOWIN_CREATOR& runeos, Logger& l): _pc(pc),_runeos(runeos),_logger(l)
  {
    //clear all memories before using
    clear();
  }
  // ***************************************************************************************
  QHA::~QHA()
  {
    this->clear();
  }
  // ***************************************************************************************
  void QHA::clear()
  {
    _is_negative_freq=false;
    _DMp.clear();
    _DMm.clear();
    _DM0.clear();
    _nBranches=0;
    _kpoints.clear();
    _gp_path_test.clear();
    _gp_mesh_test.clear();
    _qha_gp_mesh.clear();
    _qha_gp_path.clear();
    _freqs_path.clear();
    _freqs_pathM.clear();
    _freqs_pathP.clear();
    _freqs_mesh.clear();
    _qha_gpdir.clear();
    _qha_gpvol.clear();
    _delta_V=0.0;
    _V0=0.0;
    _tmp_dir="";
    _cutoff_freq=0.0;
  }
  // ***************************************************************************************
  void QHA::get_tmp_dir_name(const string dir)
  {
    _tmp_dir=dir;
  }
  // ***************************************************************************************
  bool QHA::calculation_gruneisen(const std::vector< aurostd::xvector<double> > &kpoints)
  {
    _logger<<"Quasiharmonic Gruneisen along high symmetry is calculating"<<apl::endl;
    _kpoints=kpoints;

    if(_kpoints.size()==0)
      {
	_logger<< apl::error <<"_kpoints.size()==0"<<apl::endl;
	return false;
      }

    if(!cal_gp_along_path()) return false;
    return true;
  }
  // ***************************************************************************************
  bool QHA::calculation_gruneisen(apl::UniformMesh* umesh)
  {
    _kpoints.clear(); _weights.clear();
    _kpoints=umesh->get_kpoints();
    _weights=umesh->get_weights();
   
    if(_kpoints.size()==0)
      {
	_logger<< apl::error <<"_kpoints.size()==0"<<apl::endl;
	return false;
      }
    if(_weights.size()==0)
      {
	_logger<< apl::error <<"_weights.size()==0"<<apl::endl;
	return false;
      }
     
    if(!cal_gp_in_mesh()) return false;
    return true;
  }
  // ***************************************************************************************
  bool QHA::cal_gp_along_path()
  {
    if(_kpoints.size()==0)
      {
        _logger<<apl::error<<"QHA::cal_gp_along_path() kpoints.size()=0"<<apl::endl;
        return false;
      }
    return get_dynamicalmatrices_along_path();
  }
  // ***************************************************************************************
  bool QHA::set_imported_variables()
  {
    _logger <<"Importing variables"<<apl::endl;
    _nBranches=_pc.getNumberOfBranches();
    _qha_gpdir = _runeos.get_gp_dir_names();
    _qha_gpvol = _runeos.get_gp_volumes();

    if( (_qha_gpdir.size()==0) || (_qha_gpvol.size()==0)) 
      {
        _logger<<  apl::warning <<"directory sizes are zero remove LOCK and apl.xml and run again"<<apl::endl;
	return false;
      }
    if((_qha_gpvol.size()!=3)) 
      {
        _logger<<"_qha_gpvol.size() should be equal to 3"<<apl::endl;
	return false;
      }

    _delta_V=0.5*((_qha_gpvol[2]-_qha_gpvol[1])+(_qha_gpvol[1]-_qha_gpvol[0]));
    _V0=_qha_gpvol[1];

    return true;
  }
  // ***************************************************************************************
  bool QHA::cal_gp_in_mesh()
  {
    return get_dynamicalmatrices_in_mesh();
  }
  // ***************************************************************************************
  bool QHA::get_dynamicalmatrices_in_mesh()
  {
    _DMp.clear(); _DMm.clear(); _DM0.clear();

    xmatrix< xcomplex<double> > dd(_nBranches,_nBranches,1,1);
    _DMp.resize(_kpoints.size(), dd);
    _DMm.resize(_kpoints.size(), dd);
    _DM0.resize(_kpoints.size(), dd);

    //dynamic matrix file names
    string DMmfile=string(_tmp_dir)+string("/")+string("DM_")+string("mesh.")+string(_qha_gpdir[0]);
    string DMpfile=string(_tmp_dir)+string("/")+string("DM_")+string("mesh.")+string(_qha_gpdir[1]);

    _logger <<"Reading dynamical matrices "<<apl::endl;
    //else if(_is_scqha)_logger<<_SCQHA_MSG <<"Reading dynamical matrices "<<apl::endl;

    //reading dynamical matrices
    if(!read_matrix(_DMp,DMpfile)) return false;
    if(!read_matrix(_DMm,DMmfile)) return false;

    _qha_gp_mesh.clear();
    _freqs_mesh.clear();
    xvector<double> d(_nBranches,1);
    _qha_gp_mesh.resize(_kpoints.size(),d);
    _freqs_mesh.resize(_kpoints.size(),d);

    bool gppass=false;
    _gp_mesh_test.clear();
#ifdef AFLOW_APL_MULTITHREADS_ENABLE
    // Get the number of CPUS
    int ncpus = sysconf(_SC_NPROCESSORS_ONLN);// AFLOW_MachineNCPUs;
//    int qpointsPerCPU = _kpoints.size() / ncpus;  OBSOLETE ME180801
    _gp_mesh_test.resize(ncpus, false);
    // Show info
    string msg=""; 
    if( ncpus == 1 )
      {
	msg="Calculating Gruneisen parameters in mesh";
	//else if(_is_scqha)msg=_SCQHA_MSG+"Calculating Gruneisen parameters in mesh";
	_logger.initProgressBar(msg);
      }
    else
      {
	msg="Calculating Gruneisen parameters in mesh (" + stringify(ncpus) + " threads)";
	//else if(_is_qha)msg=_SCQHA_MSG+"Calculating Gruneisen parameters in mesh (" + stringify(ncpus) + " threads)";
	_logger.initProgressBar(msg);
      }

    // Distribute the calculation
    int startIndex, endIndex;
    std::vector< std::thread* > threads;
    vector<vector<int> > thread_dist = getThreadDistribution((int) _kpoints.size(), ncpus);
    for (int icpu = 0; icpu < ncpus; icpu++) {
      startIndex = thread_dist[icpu][0];
      endIndex = thread_dist[icpu][1];
      threads.push_back( new std::thread(&QHA::calculate_gp_in_mesh,this,startIndex,endIndex, icpu) );
    }

/* OBSOLETE ME180801
    for(int icpu = 0; icpu < ncpus; icpu++) {
      startIndex = icpu * qpointsPerCPU;
      endIndex = startIndex + qpointsPerCPU;
      if( ( (uint)endIndex > _kpoints.size() ) ||
          ( ( icpu == ncpus-1 ) && ( (uint)endIndex < _kpoints.size() ) ) )
        endIndex = _kpoints.size();
      threads.push_back( new std::thread(&QHA::calculate_gp_in_mesh,this,startIndex,endIndex, icpu) );
    }
*/

    // Wait to finish all threads here!
    for(uint i = 0; i < threads.size(); i++) {
      threads[i]->join();
      delete threads[i];
    }

    // Done
    _logger.finishProgressBar();

    uint bool_size=0;
    for(uint id=0; id!=_gp_mesh_test.size(); id++)
      bool_size+=_gp_mesh_test[id];
    if(bool_size==(uint)ncpus)gppass=true;
    _gp_mesh_test.clear();
    //clear all dynamical matrices
    _DMp.clear();
    _DM0.clear();
    _DMm.clear();
#else
    _gp_mesh_test.resize(1, false);
    calculate_gp_in_mesh(0, (int)_kpoints.size(), 0);
    uint bool_size=0;
    for(uint id=0; id!=_gp_mesh_test.size(); id++)
      bool_size+=_gp_mesh_test[id];
    if(bool_size==1)gppass=true;
    //clear all dynamical matrices
    _DMp.clear();
    _DM0.clear();
    _DMm.clear();
#endif
    return gppass;
  }
  // ***************************************************************************************
  //read dynamical matrices generated by other directories
  bool QHA::get_dynamicalmatrices_along_path()
  {
    xmatrix< xcomplex<double> > dd(_nBranches,_nBranches,1,1);
    _DMp.resize(_kpoints.size(), dd);
    _DMm.resize(_kpoints.size(), dd);
    _DM0.resize(_kpoints.size(), dd);

    //dynamic matrix file names
    string DMmfile=string(_tmp_dir)+string("/")+string("DM_")+string("path.")+string(_qha_gpdir[0]);
    string DMpfile=string(_tmp_dir)+string("/")+string("DM_")+string("path.")+string(_qha_gpdir[1]);

    _logger <<"Reading dynamical matrices "<<apl::endl;
    //else if(_is_scqha)_logger<<_SCQHA_MSG <<"Reading dynamical matrices "<<apl::endl;

    if(!read_matrix(_DMp,DMpfile)) return false;
    if(!read_matrix(_DMm,DMmfile)) return false;

    xvector<double> d(_nBranches,1);
    _qha_gp_path.resize(_kpoints.size(),d);
    _freqs_path.resize(_kpoints.size(),d);
    _freqs_pathM.resize(_kpoints.size(),d);
    _freqs_pathP.resize(_kpoints.size(),d);

    bool gppass=false;

#ifdef AFLOW_APL_MULTITHREADS_ENABLE
    // Get the number of CPUS
    int ncpus = sysconf(_SC_NPROCESSORS_ONLN);// AFLOW_MachineNCPUs;
    if(ncpus<1) ncpus=1;
//    int qpointsPerCPU = _kpoints.size() / ncpus;  OBSOLETE ME180801
    _gp_path_test.resize(ncpus, false);
    // Show info 
    string msg="";
    if( ncpus == 1 )
      {
	msg="Calculating Gruneisen parameters along path";
	//else if(_is_scqha)msg=_SCQHA_MSG+"Calculating Gruneisen parameters along path";
	_logger.initProgressBar(msg);
      }
    else
      {
	msg="Calculating Gruneisen parameters along path (" + stringify(ncpus) + " threads)";
	//else if(_is_scqha)msg=_SCQHA_MSG+"Calculating Gruneisen parameters along path (" + stringify(ncpus) + " threads)";
	_logger.initProgressBar(msg);
      }

    // Distribute the calculation
    int startIndex, endIndex;
    std::vector< std::thread* > threads;
    vector<vector<int> > thread_dist = getThreadDistribution((int) _kpoints.size(), ncpus);
    for (int icpu = 0; icpu < ncpus; icpu++) {
      startIndex = thread_dist[icpu][0];
      endIndex = thread_dist[icpu][1];
      threads.push_back( new std::thread(&QHA::calculate_gp_in_path,this,startIndex,endIndex, icpu) );
    }

/* OBSOLETE ME180801
    for(int icpu = 0; icpu < ncpus; icpu++) {
      startIndex = icpu * qpointsPerCPU;
      endIndex = startIndex + qpointsPerCPU;
      if( ( (uint)endIndex > _kpoints.size() ) ||
          ( ( icpu == ncpus-1 ) && ( (uint)endIndex < _kpoints.size() ) ) )
        endIndex = _kpoints.size();
      threads.push_back( new std::thread(&QHA::calculate_gp_in_path,this,startIndex,endIndex, icpu) );
    }
*/

    // Wait to finish all threads here!
    for(uint i = 0; i < threads.size(); i++) {
      threads[i]->join();
      delete threads[i];
    }

    // Done
    _logger.finishProgressBar();


    uint bool_size=0;
    for(uint id=0; id!=_gp_path_test.size(); id++)
      bool_size+=_gp_path_test[id];
    if(bool_size==(uint)ncpus)gppass=true;
    _gp_path_test.clear();
#else
    _gp_path_test.resize(1, false);
    calculate_gp_in_path(0, (int)_kpoints.size(), 0);
    uint bool_size=0;
    for(uint id=0; id!=_gp_path_test.size(); id++)
      bool_size+=_gp_path_test[id];
    if(bool_size==1)gppass=true;  
#endif 
    return gppass;
  }
  // ***************************************************************************************
  void QHA::calculate_gp_in_mesh(int startIndex, int endIndex, int cpuid)
  {
    for(int In=startIndex;In<endIndex;In++)
      {
	xvector<double> qpoint;
	xmatrix<xcomplex<double> >  DM0(_nBranches,_nBranches,1,1);//at volume 0
	qpoint=_kpoints[In];
	DM0=_pc.getDynamicalMatrix(qpoint);
	_DM0[In]=DM0;

	xvector<double> eigenvalues(_nBranches, 1);
	xmatrix<xcomplex<double> > eigenvectors(_nBranches, _nBranches, 1,1);

	//calculate eigenvalue and eigenvectors of a dynamical matirx
	apl::aplEigensystems e;
	e.eigen_calculation(DM0, eigenvalues, eigenvectors, APL_MV_EIGEN_SORT_VAL_ASC);

	for(uint j=1; j<=_nBranches; j++)
	  {
	    if(_iszero(eigenvalues[j]))eigenvalues[j]=0.0;
	    if(eigenvalues[j]<0){
              if(_isnegative(eigenvalues[j]))
		{
		  _logger<<  apl::warning <<"gruneisen negative eigenvalue: = " <<eigenvalues[j]<<apl::endl;
                  _is_negative_freq=true;
		  return;
		}else eigenvalues[j]=0.00;
	    }
	    _freqs_mesh[In][j]=sqrt(eigenvalues[j])*RAW2Hz;
	  }// nBranch loop end

	//calculate gruneisen
	_qha_gp_mesh[In]=calculate_gruneisen(DM0, _DMp[In], _DMm[In], _delta_V, _V0);
      }

    _gp_mesh_test[cpuid]=true;
  }//fn end
  // ***************************************************************************************
  void QHA::calculate_gp_in_path(int startIndex, int endIndex, int cpuid)
  {
    for(int In=startIndex;In<endIndex;In++)
      {
	xvector<double> qpoint;
	xmatrix<xcomplex<double> >  DM0(_nBranches,_nBranches,1,1);//at volume 0
	qpoint=_kpoints[In];
	DM0=_pc.getDynamicalMatrix(qpoint);
        _DM0[In]=DM0;

	xvector<double> eigenvalues(_nBranches, 1);
	xmatrix<xcomplex<double> > eigenvectors(_nBranches, _nBranches, 1,1);

	xvector<double> eigenvaluesM(_nBranches, 1);
	xmatrix<xcomplex<double> > eigenvectorsM(_nBranches, _nBranches, 1,1);

	xvector<double> eigenvaluesP(_nBranches, 1);
	xmatrix<xcomplex<double> > eigenvectorsP(_nBranches, _nBranches, 1,1);

	apl::aplEigensystems e;
	e.eigen_calculation(DM0, eigenvalues, eigenvectors, APL_MV_EIGEN_SORT_VAL_ASC);


	apl::aplEigensystems eM;
	eM.eigen_calculation(_DMm[In], eigenvaluesM, eigenvectorsM, APL_MV_EIGEN_SORT_VAL_ASC);

	apl::aplEigensystems eP;
	eP.eigen_calculation(_DMp[In], eigenvaluesP, eigenvectorsP, APL_MV_EIGEN_SORT_VAL_ASC);

	for(uint j=1; j<=_nBranches; j++)
	  {
	    if(_iszero(eigenvalues[j]))eigenvalues[j]=0.0;
	    if(eigenvalues[j]<0){
              if(_isnegative(eigenvalues[j]))
		{
		  _logger<<  apl::warning <<"gruneisen negative eigenvalue: = " <<eigenvalues[j]<<apl::endl;
                  _is_negative_freq=true;
		  return;
		}else eigenvalues[j]=0.00;
	    }
	    _freqs_path[In][j]=sqrt(eigenvalues[j])*RAW2Hz;
	  }// nBranch loop end

	for(uint j=1; j<=_nBranches; j++)
	  {
	    if(_iszero(eigenvaluesM[j]))eigenvaluesM[j]=0.0;
	    if(eigenvaluesM[j]<0){
              if(_isnegative(eigenvaluesM[j]))
		{
		  _logger<<  apl::warning <<"gruneisen negative eigenvalueM: = " <<eigenvaluesM[j]<<apl::endl;
                  _is_negative_freq=true;
		  return;
		}else eigenvaluesM[j]=0.00;
	    }
	    _freqs_pathM[In][j]=sqrt(eigenvaluesM[j])*RAW2Hz;
	  }// nBranch loop end

	for(uint j=1; j<=_nBranches; j++)
	  {
	    if(_iszero(eigenvaluesP[j]))eigenvaluesP[j]=0.0;
	    if(eigenvaluesP[j]<0){
              if(_isnegative(eigenvaluesP[j]))
		{
		  _logger<<  apl::warning <<"gruneisen negative eigenvalueP: = " <<eigenvaluesP[j]<<apl::endl;
                  _is_negative_freq=true;
		  return;
		}else eigenvaluesP[j]=0.00;
	    }
	    _freqs_pathP[In][j]=sqrt(eigenvaluesP[j])*RAW2Hz;
	  }// nBranch loop end

	_qha_gp_path[In]=calculate_gruneisen(DM0, _DMp[In], _DMm[In], _delta_V, _V0);
      }

    _gp_path_test[cpuid]=true;
  }//fn end
  // ***************************************************************************************
  void QHA::write_gruneisen_parameter_path(const vector <double> &path, const vector <int> &path_seg)
  {
    if(_qha_gp_path.size()==0)
      {
        _logger<<apl::error <<"_qha_gp_path size is zero "<<apl::endl; return;
      }
    else if(path.size()==0)
      {
        _logger<<apl::error <<"path size is zero "<<apl::endl; return;
      }
    else if(path_seg.size()==0)
      {
        _logger<<apl::error <<"path_seg size is zero "<<apl::endl; return;
      }

    if(_is_negative_freq) return;
      
    string msg="Writing aflow.qha.gpdis.out file ,";

    _logger <<msg << apl::endl;

    vector<string> hash_lines;
    if(!read_PDIS(hash_lines))return ;

    //writing to a file
    stringstream os_gp;
    uint isize=_qha_gp_path.size();
    uint jsize=_qha_gp_path[0].rows;

    os_gp<<"#Gruneisen Paramaters along high-symmetry q-points. File format is same as PDIS file"<<"\n";
    for(uint i=1; i!=hash_lines.size(); i++)
      os_gp<<hash_lines[i]<<"\n";

    for(uint j=1; j<=jsize; j++){
      if(j==1) os_gp<<"#"<<setw(10)<<"        "<<setw(10) <<"q-path"<<setw(10)<<string("Br")+aurostd::utype2string<int>(j);
      else os_gp<< setw(15)<<string("Br")+aurostd::utype2string<int>(j);
    }
    os_gp<<"\n";

    for(uint i=0; i<isize; i++){
      os_gp<< setw(5) << path_seg[i];
      os_gp<< setprecision(6)<<std::fixed << std::showpoint
	   << setw(15) << path[i];

      for(uint j=1; j<=jsize; j++){
	os_gp<<setprecision(6)<<std::fixed << std::showpoint
	     <<setw(15)<<_qha_gp_path[i][j];
      }os_gp<<"\n";}

    string outfile =  "aflow.qha.gpdis.out";
    if(!aurostd::stringstream2file(os_gp, outfile, "WRITE")) {
      throw APLRuntimeError("Cannot write aflow.qha.gpdis.out");
    }
    aurostd::StringstreamClean(os_gp);
  }//fn end
  // ***************************************************************************************
  void QHA::write_gruneisen_parameter_mesh()
  {
    if(_qha_gp_mesh.size()==0)
      {
	_logger<<apl::error <<"average GP can't be calculated since GP sizes are zero"<<apl::endl;
	return;
      }
    _logger<<"Writing aflow.qha.gp.mesh.out file, " << apl::endl;

    stringstream os_gp;
    uint isize=_qha_gp_mesh.size();
    uint jsize=_qha_gp_mesh[0].rows;
    std::string STAR = std::string(10*_nBranches, '*');
    std::string STAR50 = std::string(50, '*');

    os_gp<<"[AFLOW] "<<STAR<<"\n";
    os_gp << "[AFLOW_QHA_GRUNEISEN_MESH]START" <<"\n";

    os_gp<<"#"<<setw(15)<<"Gruneisen"<<setw(15)<<"Freq (THz)"<<setw(15)<<"phonon_mode"<<'\n';

    for(uint i=0; i<isize; i++){
      os_gp<<"#k-point"<<setw(15)<<_kpoints[i][1]<<setw(15)<<_kpoints[i][2]<<setw(15)<<_kpoints[i][3]<<'\n';
      for(uint j=1; j<=jsize; j++){
	os_gp<<setprecision(6)<<std::fixed << std::showpoint
	     <<setw(15)<<_qha_gp_mesh[i][j]<<setw(15)<<_freqs_mesh[i][j]<<setw(15)<<j<<'\n';
      }}
    os_gp << "[AFLOW_QHA_GRUNEISEN_MESH]END" <<"\n";
    os_gp<<"[AFLOW] "<<STAR<<"\n";
 
    string outfile =  "aflow.qha.gp.mesh.out";
    if(!aurostd::stringstream2file(os_gp, outfile, "WRITE")) {
      throw APLRuntimeError("Cannot write aflow.qha.gp.mesh.out");
    }
    aurostd::StringstreamClean(os_gp);
  }//fn end
  // ***************************************************************************************
  void QHA::Writeaverage_gp(double USER_TP_TSTART, double USER_TP_TEND, double USER_TP_TSTEP)
  {
    if(_qha_gp_mesh.size()==0)
      {
	_logger<<apl::error<<"_qha_gp_mesh size is zero"<<apl::endl;
	return;
      }

    _logger<<"Writing aflow.qha.avg_gp.out file, "<<apl::endl;
    //else if(_is_scqha)_logger<<_SCQHA_MSG <<"Writing Gruneisen into file aflow.apl.avg_gp.out ,"<<apl::endl;

    std::string STAR40 = std::string(40, '*');

    stringstream os_avg;
    os_avg<<"[AFLOW] "<<STAR40<<"\n";
    os_avg<<"#gamma = Gruneisen parameter \n";
    os_avg<<"[AFLOW] "<<STAR40<<"\n";
    //os_avg<<"[AFLOW] "<<STAR40<<"\n";
    os_avg << "[AFLOW_QHA_AVG_GRUNEISEN]START" <<"\n";
    os_avg<<"#"<<aurostd::PaddedPRE("T(K)",14," ")
	  <<aurostd::PaddedPRE("gamma",10," ")<<"\n";
    //<<aurostd::PaddedPRE("ac_gamma",18," ")<<"\n";

    int n = (int)( ( USER_TP_TEND - USER_TP_TSTART ) / USER_TP_TSTEP );
    for(int i = 0; i <= n; i++)
      {
        double TEMPERATURE_IN_K = USER_TP_TSTART + i * USER_TP_TSTEP;
        double avg_gp=average_gruneisen_parameter(TEMPERATURE_IN_K);
        //double ACavgGP=AcousticAverageGP(TEMPERATURE_IN_K);
        os_avg<<setw(15)<<setprecision(2) << std::fixed << std::showpoint << TEMPERATURE_IN_K 
	      <<setw(15)<<setprecision(8) << std::fixed << std::showpoint 
	      <<avg_gp<<"\n";
      }

    os_avg << "[AFLOW_QHA_AVG_GRUNEISEN]END" <<"\n";
    os_avg<<"[AFLOW] "<<STAR40<<"\n";
    string avg_out =  "aflow.qha.avg_gp.out";
    if(!aurostd::stringstream2file(os_avg, avg_out, "WRITE")) {
      throw APLRuntimeError("Cannot write aflow.qha.avg_gp.out");
    }
    aurostd::StringstreamClean(os_avg);
    //gruneisen_parameter_300K();
  }
  // ***************************************************************************************
  double QHA::average_gruneisen_parameter(double temperature_in_kelvins)
  {
    if(temperature_in_kelvins<0.1) return 0.0;
    if(_qha_gp_mesh.size()==0){_logger<<apl::error<<"_qha_gp_mesh.size()==0"<<apl::endl;exit(0);}
    if(_freqs_mesh.size()==0){_logger<<apl::error<<"_freqs_mesh.size()==0"<<apl::endl;exit(0);}
    //if cutoff is not set then set it to 0.001 to avoid numerical error
    if(_iszero(_cutoff_freq)) _cutoff_freq=1.0e-3;
                

    double hnu=4.135667516E2;// h*10^(12)*10^(5) = h*10^(2) 
    double kB =8.6173324;
    double beta = 1./(kB*temperature_in_kelvins);

    double cv=0.00;
    double gpcv=0.00;

    for(uint i=0; i<_freqs_mesh.size(); i++){
      for(int j=1; j<=_freqs_mesh[i].rows; j++){
        // 1/(2*pi) * sqrt(eV/A^2* Mass) ---> 15.6333046177 sec^(-1)
        double f= _freqs_mesh[i][j];
        if(f<_cutoff_freq)continue;
        double x =  hnu * f *  beta;
        double ex= exp(x);
        double  cvij = x * x * ex * _weights[i]/((1.-ex)*(1.-ex)) ;
        cv+=cvij;
        gpcv+=_qha_gp_mesh[i][j]*cvij ;
      }
    }
    //if(std::isnan(gpcv/cv)) return 0.00;
    return gpcv/cv;
  }
  // ***************************************************************************************
  void QHA::gruneisen_parameter_300K()
  {
    _logger<<"Writing aflow.qha.avg_gp300K.out file ,"<<apl::endl;
    std::string STAR40 = std::string(40, '*');
    stringstream os_avg;
    os_avg<<"[AFLOW] "<<STAR40<<"\n";
    os_avg<<"#gamma = Gruneisen parameter \n";
    os_avg<<"[AFLOW] "<<STAR40<<"\n";
    os_avg<< "[APL_GRUNEISEN_300K]START" <<"\n";
    os_avg<<"apl_average_gruneisen_300K = "<<average_gruneisen_parameter(300.0)<<"\n";
    os_avg << "[APL_GRUNEISEN_300K]STOP" <<"\n";
    os_avg <<"[AFLOW] "<<STAR40<<"\n";
    os_avg << "[APL_GRUNEISEN]STOP" <<"\n";
    string avg_out =  "aflow.qha.avg_gp300K.out";
    if(!aurostd::stringstream2file(os_avg, avg_out, "WRITE")) {
      throw APLRuntimeError("Cannot write aflow.qha.avg_gp300K.out");
    }
    aurostd::StringstreamClean(os_avg);
  }
  // ***************************************************************************************
  bool QHA::read_matrix(vector<xmatrix<xcomplex<double> > >&A, const string file)
  {
    if (!exists_test0(file) && !aurostd::EFileExist(file)) {
      throw apl::APLRuntimeError("QHA::read_matrix() Missing file: "+file);
    }

    ifstream in;
    in.open(file.c_str(),ios_base::binary);
    if (!in.is_open()){_logger<<apl::error <<file<<" not able to open "<<apl::endl; return false;}
    for(uint I=0;I<A.size();I++){
      for(uint J=1;J<=_nBranches;J++){
	in.read( (char *)(&A[I][J][1]), _nBranches*sizeof(xcomplex<double>) );
      }}
    in.clear();
    in.close();
    return true;
  }
  // ***************************************************************************************
  bool QHA::read_PDIS(vector<string> &hash_lines)
  {
    string file="PDIS";

    if (!exists_test0(file) && !aurostd::EFileExist(file)) {
      throw apl::APLRuntimeError("QHA::read_PDIS() Missing file: "+file);
    }
    
    vector<string> vlines;
    aurostd::efile2vectorstring(file, vlines);
    if (!vlines.size()) {
      throw apl::APLRuntimeError("QHA::read_PDIS() Missing file: "+file);
    }

    hash_lines.clear();
    string line;
    uint line_count = 0;

    while (line_count < vlines.size()) {
      line = vlines[line_count++];
      if(line=="")continue;
      if(line[0]=='#')
	hash_lines.push_back(line);
      else break;
    }
    return true;
  }
  // ***************************************************************************************
  bool QHA::exists_test0 (const std::string& name)
  {
    ifstream f(name.c_str());
    if (f.good()) {
      f.close();
      return true;
    } else {
      f.close();
      return false;
    }
  }
  // ***************************************************************************************
}//apl end
