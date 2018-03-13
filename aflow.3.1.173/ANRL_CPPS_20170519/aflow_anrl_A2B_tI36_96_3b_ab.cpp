// ***************************************************************************
// *                                                                         *
// *           Aflow STEFANO CURTAROLO - Duke University 2003-2018           *
// *                                                                         *
// ***************************************************************************
// Written by Stefano Curtarolo - David Hicks - 2016
// FILE "ANRL/aflow_arnl_A2B_tI36_96_3b_ab.cpp"

#ifndef _AFLOW_ANRL_A2B_tI36_96_3b_ab_CPP
#define _AFLOW_ANRL_A2B_tI36_96_3b_ab_CPP
#include "../aflow.h"


namespace aflowlib {
  uint PrototypeLibrariesANRL_A2B_tI36_96_3b_ab(ostream &oss,stringstream &web,xstructure& str,string parameters,string proto_line,bool LDEBUG) {
    // system A2B_tI36_96_3b_ab

    if(XHOST.vflag_control.flag("WWW")) {
      #ifdef _ANRL_NOWEB_
      cout << "no web" << endl;
      #else
      cout << web.str() << endl;
      #endif
      exit(0);
    }

    vector<double> vparameters;
    aurostd::string2tokens(parameters,vparameters,",");

    uint nspecies,natoms,spacegroup,nunderscores,nparameters;
    string label,Pearson_symbol,params,Strukturbericht,prototype;

    aflowlib::vproto_line2tokens(proto_line,label,nspecies,natoms,spacegroup,nunderscores,nparameters,Pearson_symbol,params,Strukturbericht,prototype);

    if(!aflowlib::PrototypeLibrariesANRL_Consistency(oss,vparameters.size(),nparameters,prototype,label,
                 Strukturbericht,Pearson_symbol,spacegroup, params)) exit(0);    

    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: FOUND" << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: label=" << label << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: nspecies=" << nspecies << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: natoms=" << natoms << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: spacegroup=" << spacegroup << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: nunderscores=" << nunderscores << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: nparameters=" <<  nparameters << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: Pearson_symbol=" << Pearson_symbol << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: params=" << params << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: Strukturbericht=" << Strukturbericht << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: prototype=" << prototype << endl;
    if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: vparameters.size()=" << vparameters.size() << endl;

    xvector<double> xn(3);   xn(1)=1.0;xn(2)=0.0;xn(3)=0.0;
    xvector<double> yn(3);   yn(1)=0.0;yn(2)=1.0;yn(3)=0.0;
    xvector<double> zn(3);   zn(1)=0.0;zn(2)=0.0;zn(3)=1.0;
    xvector<double> a1(3),a2(3),a3(3);

    _atom atom;

    uint i=0;
    double a=vparameters.at(i++);                  if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: a=" << a << endl;
    double covera=vparameters.at(i++),c=covera*a;  if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: c=" << c << " (c/a=" << covera << ")" << endl;
    
    double x1=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: x1=" << x1 << endl;
    double x2=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: x2=" << x2 << endl;
    double y2=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: y2=" << y2 << endl;
    double z2=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: z2=" << z2 << endl;
    double x3=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: x3=" << x3 << endl;
    double y3=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: y3=" << y3 << endl;
    double z3=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: z3=" << z3 << endl;
    double x4=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: x4=" << x4 << endl;
    double y4=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: y4=" << y4 << endl;
    double z4=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: z4=" << z4 << endl;
    double x5=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: x5=" << x5 << endl;
    double y5=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: y5=" << y5 << endl;
    double z5=vparameters.at(i++);                 if(LDEBUG) cerr << "aflowlib::PrototypeLibrariesANRL_A2B_tI36_96_3b_ab: z5=" << z5 << endl;
        
    str.iomode=IOVASP_AUTO;
    str.title=label+" params="+parameters+" SG#="+aurostd::utype2string(spacegroup)+DOI_ANRL;
    str.scale=1.0;

    a1=-(1.0/2.0)*a*xn+(1.0/2.0)*a*yn+(1.0/2.0)*c*zn;
    a2=(1.0/2.0)*a*xn-(1.0/2.0)*a*yn+(1.0/2.0)*c*zn;
    a3=(1.0/2.0)*a*xn+(1.0/2.0)*a*yn-(1.0/2.0)*c*zn;
    
    str.lattice(1,1)=a1(1);str.lattice(1,2)=a1(2);str.lattice(1,3)=a1(3);
    str.lattice(2,1)=a2(1);str.lattice(2,2)=a2(2);str.lattice(2,3)=a2(3);
    str.lattice(3,1)=a3(1);str.lattice(3,2)=a3(2);str.lattice(3,3)=a3(3);

    str.FixLattices(); // Reciprocal/f2c/c2f
    
    atom.name="A"; atom.type=0;                                       // atom B13
    atom.fpos(1)=x3;atom.fpos(2)=y3;atom.fpos(3)=z3;                     // atom B13
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B13 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B13
    
    atom.name="A"; atom.type=0;                                       // atom B14
    atom.fpos(1)=-x3;atom.fpos(2)=-y3;atom.fpos(3)=((1.0/2.0)+z3);                     // atom B14
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B14 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B14
    
    atom.name="A"; atom.type=0;                                       // atom B15
    atom.fpos(1)=((1.0/2.0)-y3);atom.fpos(2)=((1.0/2.0)+x3);atom.fpos(3)=((3.0/4.0)+z3);                     // atom B15
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B15 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B15
    
    atom.name="A"; atom.type=0;                                       // atom B16
    atom.fpos(1)=((1.0/2.0)+y3);atom.fpos(2)=((1.0/2.0)-x3);atom.fpos(3)=((1.0/4.0)+z3);                     // atom B16
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B16 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B16
    
    atom.name="A"; atom.type=0;                                       // atom B17
    atom.fpos(1)=((1.0/2.0)-x3);atom.fpos(2)=((1.0/2.0)+y3);atom.fpos(3)=((3.0/4.0)-z3);                     // atom B17
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B17 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B17
    
    atom.name="A"; atom.type=0;                                       // atom B18
    atom.fpos(1)=((1.0/2.0)+x3);atom.fpos(2)=((1.0/2.0)-y3);atom.fpos(3)=((1.0/4.0)-z3);                     // atom B18
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B18 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B18
    
    atom.name="A"; atom.type=0;                                       // atom B19
    atom.fpos(1)=y3;atom.fpos(2)=x3;atom.fpos(3)=-z3;                     // atom B19
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B19 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B19
    
    atom.name="A"; atom.type=0;                                       // atom B20
    atom.fpos(1)=-y3;atom.fpos(2)=-x3;atom.fpos(3)=((1.0/2.0)-z3);                     // atom B20
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B20 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B20
    
    atom.name="A"; atom.type=0;                                       // atom B21
    atom.fpos(1)=x4;atom.fpos(2)=y4;atom.fpos(3)=z4;                     // atom B21
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B21 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B21
    
    atom.name="A"; atom.type=0;                                       // atom B22
    atom.fpos(1)=-x4;atom.fpos(2)=-y4;atom.fpos(3)=((1.0/2.0)+z4);                     // atom B22
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B22 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B22
    
    atom.name="A"; atom.type=0;                                       // atom B23
    atom.fpos(1)=((1.0/2.0)-y4);atom.fpos(2)=((1.0/2.0)+x4);atom.fpos(3)=((3.0/4.0)+z4);                     // atom B23
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B23 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B23
    
    atom.name="A"; atom.type=0;                                       // atom B24
    atom.fpos(1)=((1.0/2.0)+y4);atom.fpos(2)=((1.0/2.0)-x4);atom.fpos(3)=((1.0/4.0)+z4);                     // atom B24
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B24 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B24
    
    atom.name="A"; atom.type=0;                                       // atom B25
    atom.fpos(1)=((1.0/2.0)-x4);atom.fpos(2)=((1.0/2.0)+y4);atom.fpos(3)=((3.0/4.0)-z4);                     // atom B25
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B25 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B25
    
    atom.name="A"; atom.type=0;                                       // atom B26
    atom.fpos(1)=((1.0/2.0)+x4);atom.fpos(2)=((1.0/2.0)-y4);atom.fpos(3)=((1.0/4.0)-z4);                     // atom B26
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B26 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B26
    
    atom.name="A"; atom.type=0;                                       // atom B27
    atom.fpos(1)=y4;atom.fpos(2)=x4;atom.fpos(3)=-z4;                     // atom B27
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B27 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B27
    
    atom.name="A"; atom.type=0;                                       // atom B28
    atom.fpos(1)=-y4;atom.fpos(2)=-x4;atom.fpos(3)=((1.0/2.0)-z4);                     // atom B28
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B28 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B28
    
    atom.name="A"; atom.type=0;                                       // atom B29
    atom.fpos(1)=x5;atom.fpos(2)=y5;atom.fpos(3)=z5;                     // atom B29
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B29 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B29
    
    atom.name="A"; atom.type=0;                                       // atom B30
    atom.fpos(1)=-x5;atom.fpos(2)=-y5;atom.fpos(3)=((1.0/2.0)+z5);                     // atom B30
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B30 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B30
    
    atom.name="A"; atom.type=0;                                       // atom B31
    atom.fpos(1)=((1.0/2.0)-y5);atom.fpos(2)=((1.0/2.0)+x5);atom.fpos(3)=((3.0/4.0)+z5);                     // atom B31
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B31 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B31
    
    atom.name="A"; atom.type=0;                                       // atom B32
    atom.fpos(1)=((1.0/2.0)+y5);atom.fpos(2)=((1.0/2.0)-x5);atom.fpos(3)=((1.0/4.0)+z5);                     // atom B32
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B32 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B32
    
    atom.name="A"; atom.type=0;                                       // atom B33
    atom.fpos(1)=((1.0/2.0)-x5);atom.fpos(2)=((1.0/2.0)+y5);atom.fpos(3)=((3.0/4.0)-z5);                     // atom B33
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B33 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B33
    
    atom.name="A"; atom.type=0;                                       // atom B34
    atom.fpos(1)=((1.0/2.0)+x5);atom.fpos(2)=((1.0/2.0)-y5);atom.fpos(3)=((1.0/4.0)-z5);                     // atom B34
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B34 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B34
    
    atom.name="A"; atom.type=0;                                       // atom B35
    atom.fpos(1)=y5;atom.fpos(2)=x5;atom.fpos(3)=-z5;                     // atom B35
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B35 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B35
    
    atom.name="A"; atom.type=0;                                       // atom B36
    atom.fpos(1)=-y5;atom.fpos(2)=-x5;atom.fpos(3)=((1.0/2.0)-z5);                     // atom B36
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B36 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B36
    
    atom.name="B"; atom.type=1;                                       // atom B1
    atom.fpos(1)=x1;atom.fpos(2)=x1;atom.fpos(3)=0.0;                     // atom B1
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B1 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B1
    
    atom.name="B"; atom.type=1;                                       // atom B2
    atom.fpos(1)=-x1;atom.fpos(2)=-x1;atom.fpos(3)=(1.0/2.0);                     // atom B2
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B2 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B2
    
    atom.name="B"; atom.type=1;                                       // atom B3
    atom.fpos(1)=((1.0/2.0)-x1);atom.fpos(2)=((1.0/2.0)+x1);atom.fpos(3)=(1.0/4.0);                     // atom B3
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B3 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B3
    
    atom.name="B"; atom.type=1;                                       // atom B4
    atom.fpos(1)=((1.0/2.0)+x1);atom.fpos(2)=((1.0/2.0)-x1);atom.fpos(3)=(3.0/4.0);                     // atom B4
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B4 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B4
    
    atom.name="B"; atom.type=1;                                       // atom B5
    atom.fpos(1)=x2;atom.fpos(2)=y2;atom.fpos(3)=z2;                     // atom B5
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B5 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B5
    
    atom.name="B"; atom.type=1;                                       // atom B6
    atom.fpos(1)=-x2;atom.fpos(2)=-y2;atom.fpos(3)=((1.0/2.0)+z2);                     // atom B6
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B6 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B6
    
    atom.name="B"; atom.type=1;                                       // atom B7
    atom.fpos(1)=((1.0/2.0)-y2);atom.fpos(2)=((1.0/2.0)+x2);atom.fpos(3)=((3.0/4.0)+z2);                     // atom B7
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B7 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B7
    
    atom.name="B"; atom.type=1;                                       // atom B8
    atom.fpos(1)=((1.0/2.0)+y2);atom.fpos(2)=((1.0/2.0)-x2);atom.fpos(3)=((1.0/4.0)+z2);                     // atom B8
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B8 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B8
    
    atom.name="B"; atom.type=1;                                       // atom B9
    atom.fpos(1)=((1.0/2.0)-x2);atom.fpos(2)=((1.0/2.0)+y2);atom.fpos(3)=((3.0/4.0)-z2);                     // atom B9
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B9 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B9
    
    atom.name="B"; atom.type=1;                                       // atom B10
    atom.fpos(1)=((1.0/2.0)+x2);atom.fpos(2)=((1.0/2.0)-y2);atom.fpos(3)=((1.0/4.0)-z2);                     // atom B10
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B10 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B10
    
    atom.name="B"; atom.type=1;                                       // atom B11
    atom.fpos(1)=y2;atom.fpos(2)=x2;atom.fpos(3)=-z2;                     // atom B11
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B11 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B11
    
    atom.name="B"; atom.type=1;                                       // atom B12
    atom.fpos(1)=-y2;atom.fpos(2)=-x2;atom.fpos(3)=((1.0/2.0)-z2);                     // atom B12
    str.comp_each_type.at(atom.type)+=1.0;                            // atom B12 // if we need partial occupation
    str.atoms.push_back(atom);                                        // atom B12
    

    return str.atoms.size();  
  }
} // namespace aflowlib::

#endif

// ***************************************************************************
// *                                                                         *
// *           Aflow STEFANO CURTAROLO - Duke University 2003-2018           *
// *                                                                         *
// ***************************************************************************
