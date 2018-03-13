// ***************************************************************************
// *                                                                         *
// *           Aflow STEFANO CURTAROLO - Duke University 2003-2018           *
// *                                                                         *
// ***************************************************************************
// Ohad Levy - 2009 Duke

// based on the Pauling File

#ifndef _AFLOW_MIX_EXPERIMENTS_CPP
#define _AFLOW_MIX_EXPERIMENTS_CPP
#include "aflow.h"

// ***************************************************************************
int MiscibilityExperimentsCheck(string system_in) {  // (nomix,unknown,mix)
  string system=KBIN::VASP_PseudoPotential_CleanName(system_in);
  if(system.length()<2) return MISCIBILITY_SYSTEM_MISCIBLE; // pure element is miscible with itself
  int UNKNOWN=MISCIBILITY_SYSTEM_UNKNOWN;
  int NOTSTUDIED=MISCIBILITY_SYSTEM_NOT_STUDIED;
  int COMPOUND=MISCIBILITY_SYSTEM_MISCIBLE;
  int NOMIX=MISCIBILITY_SYSTEM_NOMIX;
  if(system=="AcBe") return UNKNOWN; // Pauling
  if(system=="AgAu") return NOMIX; // Pauling
  if(system=="AgBi") return COMPOUND; //Pauling JUNKAI
  if(system=="AgBe") return COMPOUND; // Pauling
  if(system=="AgCd") return COMPOUND; // Pauling
  if(system=="AgCo") return NOMIX; // Pauling
  if(system=="AgCr") return NOMIX; // Pauling
  if(system=="AgCu") return NOMIX; // Pauling
  if(system=="AgFe") return NOMIX; // Pauling
  if(system=="AgHf") return COMPOUND; // Pauling
  if(system=="AgHg") return COMPOUND; // Pauling
  if(system=="AgIr") return COMPOUND; // Pauling
  if(system=="AgLa") return COMPOUND; // Pauling
  if(system=="AgMg") return COMPOUND; // Pauling
  if(system=="AgMn") return NOMIX; // Pauling
  if(system=="AgMo") return NOMIX; // Pauling
  if(system=="AgNb") return NOMIX; // Pauling
  if(system=="AgNi") return NOMIX; // Pauling
  if(system=="AgOs") return NOMIX; // Pauling
  if(system=="AgPd") return NOMIX; // Pauling
  if(system=="AgPt") return COMPOUND; // Pauling
  if(system=="AgRe") return NOMIX; // Pauling
  if(system=="AgRh") return NOMIX; // Pauling
  if(system=="AgRu") return NOMIX; // Pauling
  if(system=="AgSc") return COMPOUND; // Pauling
  if(system=="AgTa") return NOMIX; // Pauling
  if(system=="AgTc") return NOMIX; // Pauling
  if(system=="AgTi") return COMPOUND; // Pauling
  if(system=="AgV")  return NOMIX; // Pauling
  if(system=="AgW")  return NOMIX; // Pauling
  if(system=="AgY")  return COMPOUND; // Pauling
  if(system=="AgZn") return COMPOUND; // Pauling
  if(system=="AgZr") return COMPOUND; // Pauling
  if(system=="AlBe") return NOMIX; // Pauling
  if(system=="AlCo") return COMPOUND; // Pauling
  if(system=="AlHf") return COMPOUND; // Pauling
  if(system=="AlMg") return COMPOUND; // Pauling
  if(system=="AlPd") return COMPOUND; // Pauling
  if(system=="AlPt") return COMPOUND; // Pauling
  if(system=="AlSc") return UNKNOWN; // Pauling
  if(system=="AmBe") return COMPOUND; // Pauling
  if(system=="AsBe") return COMPOUND; // Pauling
  if(system=="AuBe") return COMPOUND; // Pauling
  if(system=="AuBi") return COMPOUND; //Pauling JUNKAI
  if(system=="AuCd") return COMPOUND; // Pauling
  if(system=="AuCo") return NOMIX; // Pauling
  if(system=="AuCr") return COMPOUND; // Pauling
  if(system=="AuCu") return COMPOUND; // Pauling
  if(system=="AuFe") return NOMIX; // Pauling
  if(system=="AuHf") return COMPOUND; // Pauling
  if(system=="AuHg") return COMPOUND; // Pauling
  if(system=="AuIr") return NOMIX; // Pauling
  if(system=="AuLa") return COMPOUND; // Pauling
  if(system=="AuMg") return COMPOUND; // Pauling
  if(system=="AuMn") return COMPOUND; // Pauling
  if(system=="AuMo") return NOMIX; // Pauling
  if(system=="AuNb") return COMPOUND; // Pauling
  if(system=="AuNi") return NOMIX; // Pauling
  if(system=="AuOs") return NOMIX; // Pauling
  if(system=="AuPd") return NOMIX; // Pauling
  if(system=="AuPt") return NOMIX; // Pauling
  if(system=="AuRe") return NOMIX; // Pauling
  if(system=="AuRh") return NOMIX; // Pauling
  if(system=="AuRu") return NOMIX; // Pauling
  if(system=="AuSc") return COMPOUND; // Pauling
  if(system=="AuTa") return COMPOUND; // Pauling
  if(system=="AuTc") return NOMIX; // Pauling
  if(system=="AuTi") return COMPOUND; // Pauling
  if(system=="AuV")  return COMPOUND; // Pauling
  if(system=="AuW")  return NOMIX; // Pauling
  if(system=="AuY")  return COMPOUND; // Pauling
  if(system=="AuZn") return COMPOUND; // Pauling
  if(system=="AuZr") return COMPOUND; // Pauling
  if(system=="BBe") return COMPOUND; // Pauling
  if(system=="BaBe") return COMPOUND; // Pauling
  if(system=="BaMg") return COMPOUND; // Pauling
  if(system=="BaHf") return UNKNOWN; // Pauling
  if(system=="BaMg") return COMPOUND; // Pauling
  if(system=="BaPd") return COMPOUND; // Pauling
  if(system=="BaPt") return COMPOUND; // Pauling
  if(system=="BeBi") return NOMIX; // Pauling
  if(system=="BeBk") return UNKNOWN; // Pauling
  if(system=="BeBr") return UNKNOWN; // Pauling
  if(system=="BeC") return COMPOUND; // Pauling
  if(system=="BeCa") return COMPOUND; // Pauling
  if(system=="BeCd") return UNKNOWN; // Pauling
  if(system=="BeCe") return COMPOUND; // Pauling
  if(system=="BeCl") return COMPOUND; // Pauling
  if(system=="BeCm") return COMPOUND; // Pauling
  if(system=="BeCo") return COMPOUND; // Pauling
  if(system=="BeCr") return COMPOUND; // Pauling
  if(system=="BeCs") return UNKNOWN; // Pauling
  if(system=="BeCu") return COMPOUND; // Pauling
  if(system=="BeDy") return COMPOUND; // Pauling
  if(system=="BeEr") return COMPOUND; // Pauling
  if(system=="BeEu") return COMPOUND; // Pauling
  if(system=="BeF") return COMPOUND; // Pauling
  if(system=="BeFe") return COMPOUND; // Pauling
  if(system=="BeGa") return NOMIX; // Pauling
  if(system=="BeGd") return COMPOUND; // Pauling
  if(system=="BeGe") return NOMIX; // Pauling
  if(system=="BeH") return COMPOUND; // Pauling
  if(system=="BeHf") return COMPOUND; // Pauling
  if(system=="BeHg") return NOMIX; // Pauling
  if(system=="BeHo") return COMPOUND; // Pauling
  if(system=="BeI") return UNKNOWN; // Pauling
  if(system=="BeIn") return NOMIX; // Pauling
  if(system=="BeIr") return COMPOUND; // Pauling
  if(system=="BeK") return UNKNOWN; // Pauling
  if(system=="BeLa") return COMPOUND; // Pauling
  if(system=="BeLi") return NOMIX; // Pauling
  if(system=="BeLu") return COMPOUND; // Pauling
  if(system=="BeMg") return COMPOUND; // Pauling
  if(system=="BeMn") return COMPOUND; // Pauling
  if(system=="BeMo") return COMPOUND; // Pauling
  if(system=="BeN") return COMPOUND; // Pauling
  if(system=="BeNa") return NOMIX; // Pauling
  if(system=="BeNb") return COMPOUND; // Pauling
  if(system=="BeNd") return COMPOUND; // Pauling
  if(system=="BeNi") return COMPOUND; // Pauling
  if(system=="BeNp") return COMPOUND; // Pauling
  if(system=="BeO") return COMPOUND; // Pauling
  if(system=="BeOs") return COMPOUND; // Pauling
  if(system=="BeP") return COMPOUND; // Pauling
  if(system=="BePa") return COMPOUND; // Pauling
  if(system=="BePb") return UNKNOWN; // Pauling
  if(system=="BePd") return COMPOUND; // Pauling
  if(system=="BePm") return UNKNOWN; // Pauling
  if(system=="BePo") return COMPOUND; // Pauling
  if(system=="BePr") return COMPOUND; // Pauling
  if(system=="BePt") return COMPOUND; // Pauling
  if(system=="BePu") return COMPOUND; // Pauling
  if(system=="BeRb") return UNKNOWN; // Pauling
  if(system=="BeRe") return COMPOUND; // Pauling
  if(system=="BeRh") return COMPOUND; // Pauling
  if(system=="BeRu") return COMPOUND; // Pauling
  if(system=="BeS") return COMPOUND; // Pauling
  if(system=="BeSb") return COMPOUND; // Pauling
  if(system=="BeSc") return COMPOUND; // Pauling
  if(system=="BeSe") return COMPOUND; // Pauling
  if(system=="BeSi") return NOMIX; // Pauling
  if(system=="BeSm") return COMPOUND; // Pauling
  if(system=="BeSn") return NOMIX; // Pauling
  if(system=="BeSr") return COMPOUND; // Pauling
  if(system=="BeTa") return COMPOUND; // Pauling
  if(system=="BeTb") return COMPOUND; // Pauling
  if(system=="BeTc") return COMPOUND; // Pauling
  if(system=="BeTe") return COMPOUND; // Pauling
  if(system=="BeTh") return COMPOUND; // Pauling
  if(system=="BeTi") return COMPOUND; // Pauling
  if(system=="BeTl") return UNKNOWN; // Pauling
  if(system=="BeTm") return COMPOUND; // Pauling
  if(system=="BeU") return COMPOUND; // Pauling
  if(system=="BeV") return COMPOUND; // Pauling
  if(system=="BeW") return COMPOUND; // Pauling
  if(system=="BeY") return COMPOUND; // Pauling
  if(system=="BeYb") return COMPOUND; // Pauling
  if(system=="BeZn") return NOMIX; // Pauling
  if(system=="BeZr") return COMPOUND; // Pauling
  if(system=="BiCd") return NOMIX; //Massalski JUNKAI
  if(system=="BiCo") return NOMIX; //Massalski JUNKAI
  if(system=="BiCr") return NOMIX; //Massalski JUNKAI
  if(system=="BiCu") return NOMIX; //Massalski JUNKAI
  if(system=="BiFe") return NOMIX; //Massalski JUNKAI
  if(system=="BiHf") return COMPOUND; // Pauling
  if(system=="BiHg") return NOMIX; // Pauling
  if(system=="BiIn") return COMPOUND; // Pauling
  if(system=="BiIr") return COMPOUND; // Pauling
  if(system=="BiLa") return COMPOUND; //Pauling JUNKAI
  if(system=="BiMn") return COMPOUND; //Pauling JUNKAI
  if(system=="BiMo") return NOMIX; //Massalski JUNKAI
  if(system=="BiNb") return NOMIX; //Massalski JUNKAI
  if(system=="BiNi") return COMPOUND; //Pauling JUNKAI
  if(system=="BiOs") return NOMIX; //Massalski JUNKAI
  if(system=="BiPd") return COMPOUND; //Pauling JUNKAI
  if(system=="BiPt") return COMPOUND; //Pauling JUNKAI
  if(system=="BiRe") return NOMIX; //Massalski JUNKAI
  if(system=="BiRh") return COMPOUND; //Pauling JUNKAI
  if(system=="BiRu") return NOMIX; //Massalski JUNKAI
  if(system=="BiSc") return COMPOUND; //Pauling JUNKAI
  if(system=="BiTa") return NOMIX; //Massalski JUNKAI
  if(system=="BiTc") return UNKNOWN; //Massalski JUNKAI
  if(system=="BiTi") return COMPOUND; //Pauling JUNKAI
  if(system=="BiV") return NOMIX; //Massalski JUNKAI
  if(system=="BiW") return UNKNOWN; //Massalski JUNKAI
  if(system=="BiY") return COMPOUND; //Massalski JUNKAI
  if(system=="BiZn") return NOMIX; //Massalski JUNKAI
  if(system=="BiZr") return COMPOUND; //Pauling JUNKAI
  if(system=="BHf")  return COMPOUND; // Pauling
  if(system=="CaHf") return UNKNOWN; // Pauling
  if(system=="CaMg") return COMPOUND; // Pauling
  if(system=="CaPd") return COMPOUND; // Pauling
  if(system=="CaPt") return COMPOUND; // Pauling
  if(system=="CdCo") return NOMIX; // Pauling
  if(system=="CdCr") return NOMIX; // Pauling
  if(system=="CdCu") return COMPOUND; // Pauling
  if(system=="CdFe") return NOMIX; // Pauling
  if(system=="CdHf") return COMPOUND; // Pauling
  if(system=="CdHg") return COMPOUND; // Pauling
  if(system=="CdIr") return NOTSTUDIED; // Massalsky
  if(system=="CdLa") return COMPOUND; // Pauling
  if(system=="CdMg") return COMPOUND; // Pauling
  if(system=="CdMn") return NOMIX; // Pauling
  if(system=="CdMo") return NOMIX; // Pauling
  if(system=="CdNb") return COMPOUND; // Pauling
  if(system=="CdNi") return COMPOUND; // Pauling
  if(system=="CdOs") return NOMIX; // Pauling
  if(system=="CdPd") return COMPOUND; // Pauling
  if(system=="CdPt") return COMPOUND; // Pauling
  if(system=="CdRe") return NOMIX; // Pauling
  if(system=="CdRh") return NOMIX; // Pauling
  if(system=="CdRu") return NOTSTUDIED; // Massalsky
  if(system=="CdSc") return COMPOUND; // Pauling
  if(system=="CdTa") return NOTSTUDIED; // Massalsky
  if(system=="CdTc") return NOTSTUDIED; // Massalsky
  if(system=="CdTi") return COMPOUND; // Pauling
  if(system=="CdV")  return NOMIX; // Pauling
  if(system=="CdW")  return NOMIX; // Pauling
  if(system=="CdY")  return COMPOUND; // Pauling
  if(system=="CdZn") return NOMIX; // Pauling
  if(system=="CdZr") return COMPOUND; // Pauling
  if(system=="CNi")  return NOMIX; // Pauling
  if(system=="CoCr") return COMPOUND; // Pauling
  if(system=="CoCu") return NOMIX; // Pauling
  if(system=="CoFe") return COMPOUND; // Pauling
  if(system=="CoHf") return COMPOUND; // Pauling
  if(system=="CoHg") return NOMIX; // Pauling
  if(system=="CoIr") return NOMIX; // Pauling
  if(system=="CoLa") return COMPOUND; // Pauling
  if(system=="CoMn") return COMPOUND; // Pauling
  if(system=="CoMo") return COMPOUND; // Pauling
  if(system=="CoNb") return COMPOUND; // Pauling
  if(system=="CoNi") return NOMIX; // Pauling
  if(system=="CoOs") return NOMIX; // Pauling
  if(system=="CoPd") return NOMIX; // Pauling
  if(system=="CoPt") return COMPOUND; // Pauling
  if(system=="CoRe") return NOMIX; // Pauling
  if(system=="CoRh") return NOMIX; // Pauling
  if(system=="CoRu") return NOMIX; // Pauling
  if(system=="CoSc") return COMPOUND; // Pauling
  if(system=="CoTa") return COMPOUND; // Pauling
  if(system=="CoTc") return NOMIX; // Pauling
  if(system=="CoTi") return COMPOUND; // Pauling
  if(system=="CoV")  return COMPOUND; // Pauling
  if(system=="CoW")  return COMPOUND; // Pauling
  if(system=="CoY")  return COMPOUND; // Pauling
  if(system=="CoZn") return COMPOUND; // Pauling
  if(system=="CoZr") return COMPOUND; // Pauling
  if(system=="CrCu") return NOMIX; // Pauling
  if(system=="CrFe") return COMPOUND; // Pauling
  if(system=="CrHf") return COMPOUND; // Pauling
  if(system=="CrHg") return NOMIX; // Pauling
  if(system=="CrIr") return COMPOUND; // Pauling
  if(system=="CrLa") return NOMIX; // Pauling
  if(system=="CrMn") return COMPOUND; // Pauling
  if(system=="CrMo") return COMPOUND; // Pauling
  if(system=="CrNb") return COMPOUND; // Pauling
  if(system=="CrNi") return COMPOUND; // Pauling
  if(system=="CrOs") return COMPOUND; // Pauling
  if(system=="CrPd") return COMPOUND; // Pauling
  if(system=="CrPt") return COMPOUND; // Pauling
  if(system=="CrRe") return COMPOUND; // Pauling
  if(system=="CrRh") return COMPOUND; // Pauling
  if(system=="CrRu") return COMPOUND; // Pauling
  if(system=="CrSc") return NOMIX; // Pauling
  if(system=="CrTa") return COMPOUND; // Pauling
  if(system=="CrTc") return COMPOUND; // Pauling
  if(system=="CrTi") return COMPOUND; // Pauling
  if(system=="CrV") return NOMIX; // Pauling
  if(system=="CrW") return NOMIX; // Pauling
  if(system=="CrY") return NOMIX; // Pauling
  if(system=="CrZn") return COMPOUND; // Pauling
  if(system=="CrZr") return COMPOUND; // Pauling
  if(system=="CuFe") return NOMIX; // Pauling
  if(system=="CuHf") return COMPOUND; // Pauling
  if(system=="CuHg") return COMPOUND; // Pauling
  if(system=="CuIr") return NOMIX; // Pauling
  if(system=="CuLa") return COMPOUND; // Pauling
  if(system=="CuMg") return COMPOUND; // Pauling
  if(system=="CuMn") return COMPOUND; // Pauling
  if(system=="CuMo") return NOMIX; // Pauling
  if(system=="CuNb") return NOMIX; // Pauling
  if(system=="CuNi") return NOMIX; // Pauling
  if(system=="CuOs") return NOMIX; // Pauling
  if(system=="CuPd") return COMPOUND; // Pauling
  if(system=="CuPt") return COMPOUND; // Pauling
  if(system=="CuRe") return NOMIX; // Pauling
  if(system=="CuRh") return NOMIX; // Pauling
  if(system=="CuRu") return NOMIX; // Pauling
  if(system=="CuSc") return COMPOUND; // Pauling
  if(system=="CuTa") return NOMIX; // Pauling
  if(system=="CuTc") return NOMIX; // Pauling
  if(system=="CuTi") return COMPOUND; // Pauling
  if(system=="CuV")  return NOMIX; // Pauling
  if(system=="CuW")  return NOMIX; // Pauling
  if(system=="CuY")  return COMPOUND; // Pauling
  if(system=="CuZn") return COMPOUND; // Pauling
  if(system=="CuZr") return COMPOUND; // Pauling
  if(system=="FeHf") return COMPOUND; // Pauling
  if(system=="FeHg") return NOMIX; // Pauling
  if(system=="FeIr") return NOMIX; // Pauling
  if(system=="FeLa") return NOMIX; // Pauling
  if(system=="FeMn") return NOMIX; // Pauling
  if(system=="FeMo") return COMPOUND; // Pauling
  if(system=="FeNb") return COMPOUND; // Pauling
  if(system=="FeNi") return COMPOUND; // Pauling
  if(system=="FeOs") return NOMIX; // Pauling
  if(system=="FePd") return COMPOUND; // Pauling
  if(system=="FePt") return COMPOUND; // Pauling
  if(system=="FeRe") return COMPOUND; // Pauling
  if(system=="FeRh") return COMPOUND; // Pauling
  if(system=="FeRu") return NOMIX; // Pauling
  if(system=="FeSc") return COMPOUND; // Pauling
  if(system=="FeTa") return COMPOUND; // Pauling
  if(system=="FeTc") return COMPOUND; // Pauling
  if(system=="FeTi") return COMPOUND; // Pauling
  if(system=="FeV") return COMPOUND; // Pauling
  if(system=="FeW") return COMPOUND; // Pauling
  if(system=="FeY") return COMPOUND; // Pauling
  if(system=="FeZn") return COMPOUND; // Pauling
  if(system=="FeZr") return COMPOUND; // Pauling
  if(system=="GaHf") return COMPOUND; // Pauling
  if(system=="GaMg") return COMPOUND; // Pauling
  if(system=="GaNi") return COMPOUND; // Pauling
  if(system=="GaPd") return COMPOUND; // Pauling
  if(system=="GaPt") return COMPOUND; // Pauling
  if(system=="GeMg") return COMPOUND; // Pauling
  if(system=="GePd") return COMPOUND; // Pauling
  if(system=="GePt") return COMPOUND; // Pauling
  if(system=="HfHg") return COMPOUND; // Pauling
  if(system=="HfIn") return COMPOUND; // Pauling
  if(system=="HfIr") return COMPOUND; // Pauling
  if(system=="HfK")  return NOMIX; // Pauling
  if(system=="HfLa") return NOMIX; // Pauling
  if(system=="HfLi") return NOMIX; // Pauling
  if(system=="HfMg") return NOMIX; // Pauling
  if(system=="HfMn") return COMPOUND; // Pauling
  if(system=="HfMo") return COMPOUND; // Pauling
  if(system=="HfNa") return NOMIX; // Pauling
  if(system=="HfNb") return NOMIX; // Pauling
  if(system=="HfNi") return COMPOUND; // Pauling
  if(system=="HfOs") return COMPOUND; // Pauling
  if(system=="HfPb") return NOMIX; // Pauling
  if(system=="HfPd") return COMPOUND; // Pauling
  if(system=="HfPt") return COMPOUND; // Pauling
  if(system=="HfRe") return COMPOUND; // Pauling
  if(system=="HfRh") return COMPOUND; // Pauling
  if(system=="HfRu") return COMPOUND; // Pauling
  if(system=="HfSc") return NOMIX; // Pauling
  if(system=="HfSn") return COMPOUND; // Pauling
  if(system=="HfSr") return NOMIX; // Pauling
  if(system=="HfTa") return NOMIX; // Pauling
  if(system=="HfTc") return COMPOUND; // Pauling
  if(system=="HfTi") return NOMIX; // Pauling
  if(system=="HfTl") return NOMIX; // Pauling
  if(system=="HfV") return COMPOUND; // Pauling
  if(system=="HfW") return COMPOUND; // Pauling
  if(system=="HfY") return NOMIX; // Pauling
  if(system=="HfZn") return COMPOUND; // Pauling
  if(system=="HfZr") return NOMIX; // Pauling
  if(system=="HgIr") return NOMIX; // Pauling
  if(system=="HgLa") return COMPOUND; // Pauling
  if(system=="HgMg") return COMPOUND; // Pauling
  if(system=="HgMn") return COMPOUND; // Pauling
  if(system=="HgMo") return NOMIX; // Pauling
  if(system=="HgNb") return NOMIX; // Pauling
  if(system=="HgNi") return COMPOUND; // Pauling
  if(system=="HgOs") return NOMIX; // Pauling
  if(system=="HgPd") return COMPOUND; // Pauling
  if(system=="HgPt") return COMPOUND; // Pauling
  if(system=="HgRe") return NOMIX; // Pauling
  if(system=="HgRh") return COMPOUND; // Pauling
  if(system=="HgRu") return NOMIX; // Pauling
  if(system=="HgSc") return COMPOUND; // Pauling
  if(system=="HgTa") return COMPOUND; // Pauling
  if(system=="HgTc") return NOTSTUDIED; // Massalsky
  if(system=="HgTi") return COMPOUND; // Pauling
  if(system=="HgV") return NOMIX; // Pauling
  if(system=="HgW") return NOMIX; // Pauling
  if(system=="HgY") return COMPOUND; // Pauling
  if(system=="HgZn") return COMPOUND; // Pauling
  if(system=="HgZr") return COMPOUND; // Pauling
  if(system=="InMg") return COMPOUND; // Pauling
  if(system=="InPd") return COMPOUND; // Pauling
  if(system=="InPt") return COMPOUND; // Pauling
  if(system=="IrLa") return COMPOUND; // Pauling
  if(system=="IrMg") return COMPOUND; // Pauling
  if(system=="IrMn") return COMPOUND; // Pauling
  if(system=="IrMo") return COMPOUND; // Pauling
  if(system=="IrNb") return COMPOUND; // Pauling
  if(system=="IrNi") return NOMIX; // Pauling
  if(system=="IrOs") return NOMIX; // Pauling
  if(system=="IrPd") return NOMIX; // Pauling
  if(system=="IrPt") return NOMIX; // Pauling
  if(system=="IrRe") return NOMIX; // Pauling
  if(system=="IrRh") return NOMIX; // Pauling
  if(system=="IrRu") return NOMIX; // Pauling
  if(system=="IrSc") return COMPOUND; // Pauling
  if(system=="IrTa") return COMPOUND; // Pauling
  if(system=="IrTc") return NOMIX; // Pauling
  if(system=="IrTi") return COMPOUND; // Pauling
  if(system=="IrV") return COMPOUND; // Pauling
  if(system=="IrW") return COMPOUND; // Pauling
  if(system=="IrY") return COMPOUND; // Pauling
  if(system=="IrZn") return COMPOUND; // Pauling
  if(system=="IrZr") return COMPOUND; // Pauling
  if(system=="KMg") return NOMIX; // Pauling
  if(system=="KPd") return NOMIX; // Pauling
  if(system=="KPt") return NOMIX; // Pauling
  if(system=="LaMn") return NOMIX; // Pauling
  if(system=="LaMo") return NOMIX; // Pauling
  if(system=="LaNb") return NOMIX; // Pauling
  if(system=="LaNi") return COMPOUND; // Pauling
  if(system=="LaOs") return COMPOUND; // Pauling
  if(system=="LaPd") return COMPOUND; // Pauling
  if(system=="LaPt") return COMPOUND; // Pauling
  if(system=="LaRe") return NOMIX; // Pauling
  if(system=="LaRh") return COMPOUND; // Pauling
  if(system=="LaRu") return COMPOUND; // Pauling
  if(system=="LaSc") return NOMIX; // Pauling
  if(system=="LaTa") return NOMIX; // Pauling
  if(system=="LaTc") return NOTSTUDIED; // Massalsky
  if(system=="LaTi") return NOMIX; // Pauling
  if(system=="LaV") return NOMIX; // Pauling
  if(system=="LaW") return NOMIX; // Pauling
  if(system=="LaY") return COMPOUND; // Pauling
  if(system=="LaZn") return COMPOUND; // Pauling
  if(system=="LaZr") return NOMIX; // Pauling
  if(system=="LiMg") return NOMIX; // Pauling
  if(system=="LiPd") return COMPOUND; // Pauling
  if(system=="LiPt") return COMPOUND; // Pauling
  if(system=="MgPd") return COMPOUND; // Pauling
  if(system=="MgPt") return COMPOUND; // Pauling
  if(system=="MgTc") return NOMIX; // Pauling
  if(system=="MnMo") return COMPOUND; // Pauling
  if(system=="MnNb") return COMPOUND; // Pauling
  if(system=="MnNi") return COMPOUND; // Pauling
  if(system=="MnOs") return NOTSTUDIED; // Massalsky
  if(system=="MnPd") return COMPOUND; // Pauling
  if(system=="MnPt") return COMPOUND; // Pauling
  if(system=="MnRe") return COMPOUND; // Pauling
  if(system=="MnRh") return COMPOUND; // Pauling
  if(system=="MnRu") return NOMIX; // Pauling
  if(system=="MnSc") return COMPOUND; // Pauling
  if(system=="MnTa") return COMPOUND; // Pauling
  if(system=="MnTc") return COMPOUND; // Pauling
  if(system=="MnTi") return COMPOUND; // Pauling
  if(system=="MnV") return COMPOUND; // Pauling
  if(system=="MnW") return NOMIX; // Pauling
  if(system=="MnY") return COMPOUND; // Pauling
  if(system=="MnZn") return COMPOUND; // Pauling
  if(system=="MnZr") return COMPOUND; // Pauling
  if(system=="MoMg" || system=="MgMo") return UNKNOWN; // Pauling
  if(system=="MoNb") return NOMIX; // Pauling
  if(system=="MoNi") return COMPOUND; // Pauling
  if(system=="MoOs") return COMPOUND; // Pauling
  if(system=="MoPd") return COMPOUND; // Pauling
  if(system=="MoPt") return COMPOUND; // Pauling
  if(system=="MoRe") return COMPOUND; // Pauling
  if(system=="MoRh") return COMPOUND; // Pauling
  if(system=="MoRu") return COMPOUND; // Pauling
  if(system=="MoSc") return NOTSTUDIED; // Massalsky
  if(system=="MoTa") return NOMIX; // Pauling
  if(system=="MoTc") return COMPOUND; // Pauling
  if(system=="MoTi") return NOMIX; // Pauling
  if(system=="MoV") return NOMIX; // Pauling
  if(system=="MoW") return NOMIX; // Pauling
  if(system=="MoY") return NOMIX; // Pauling
  if(system=="MoZn") return COMPOUND; // Pauling
  if(system=="MoZr") return COMPOUND; // Pauling
  if(system=="NaMg" || system=="MgNa") return UNKNOWN; // Pauling
  if(system=="NaPd") return COMPOUND; // Pauling
  if(system=="NaPt") return COMPOUND; // Pauling
  if(system=="NbMg" || system=="MgNb") return UNKNOWN; // Pauling
  if(system=="NbNi") return COMPOUND; // Pauling
  if(system=="NbOs") return COMPOUND; // Pauling
  if(system=="NbPd") return COMPOUND; // Pauling
  if(system=="NbPt") return COMPOUND; // Pauling
  if(system=="NbRe") return COMPOUND; // Pauling
  if(system=="NbRh") return COMPOUND; // Pauling
  if(system=="NbRu") return COMPOUND; // Pauling
  if(system=="NbSc") return NOMIX; // Pauling
  if(system=="NbTa") return NOMIX; // Pauling
  if(system=="NbTc") return COMPOUND; // Pauling
  if(system=="NbTi") return NOMIX; // Pauling
  if(system=="NbV") return NOMIX; // Pauling
  if(system=="NbW") return NOMIX; // Pauling
  if(system=="NbY") return NOMIX; // Pauling
  if(system=="NbZn") return COMPOUND; // Pauling
  if(system=="NbZr") return NOMIX; // Pauling
  if(system=="NiOs") return NOMIX; // Pauling
  if(system=="NiPd") return NOMIX; // Pauling
  if(system=="NiPt") return COMPOUND; // Pauling
  if(system=="NiRe") return NOMIX; // Pauling
  if(system=="NiRh") return NOMIX; // Pauling
  if(system=="NiRu") return NOMIX; // Pauling
  if(system=="NiSc") return COMPOUND; // Pauling
  if(system=="NiTa") return COMPOUND; // Pauling
  if(system=="NiTc") return NOMIX; // Pauling
  if(system=="NiTi") return COMPOUND; // Pauling
  if(system=="NiV") return COMPOUND; // Pauling
  if(system=="NiW") return COMPOUND; // Pauling
  if(system=="NiY") return COMPOUND; // Pauling
  if(system=="NiZn") return COMPOUND; // Pauling
  if(system=="NiZr") return COMPOUND; // Pauling
  if(system=="OsMg" || system=="MgOs") return UNKNOWN; // Pauling
  if(system=="OsPd") return NOMIX; // Pauling
  if(system=="OsPt") return NOMIX; // Pauling
  if(system=="OsRe") return NOMIX; // Pauling
  if(system=="OsRh") return NOMIX; // Pauling
  if(system=="OsRu") return NOMIX; // Pauling
  if(system=="OsSc") return COMPOUND; // Pauling
  if(system=="OsTa") return COMPOUND; // Pauling
  if(system=="OsTc") return NOMIX; // Pauling
  if(system=="OsTi") return COMPOUND; // Pauling
  if(system=="OsV") return COMPOUND; // Pauling
  if(system=="OsW") return COMPOUND; // Pauling
  if(system=="OsY") return COMPOUND; // Pauling
  if(system=="OsZn") return NOMIX; // Pauling
  if(system=="OsZr") return COMPOUND; // Pauling
  if(system=="PbMg" || system=="MgPb") return COMPOUND; // Pauling
  if(system=="PbPd") return COMPOUND; // Pauling
  if(system=="PbPt") return COMPOUND; // Pauling
  if(system=="PdMg" || system=="MgPd") return COMPOUND; // Pauling
  if(system=="PdPt") return NOMIX; // Pauling
  if(system=="PdRe") return NOMIX; // Pauling
  if(system=="PdRh") return NOMIX; // Pauling
  if(system=="PdRu") return NOMIX; // Pauling
  if(system=="PdSc") return COMPOUND; // Pauling
  if(system=="PdTa") return COMPOUND; // Pauling
  if(system=="PdTc") return NOMIX; // Pauling
  if(system=="PdTi") return COMPOUND; // Pauling
  if(system=="PdV") return COMPOUND; // Pauling
  if(system=="PdW") return NOMIX; // Pauling
  if(system=="PdY") return COMPOUND; // Pauling
  if(system=="PdZn") return COMPOUND; // Pauling
  if(system=="PdZr") return COMPOUND; // Pauling
  if(system=="PtMg" || system=="MgPt") return COMPOUND; // Pauling
  if(system=="PtRe") return NOMIX; // Pauling
  if(system=="PtRh") return NOMIX; // Pauling
  if(system=="PtRu") return NOMIX; // Pauling
  if(system=="PtSc") return COMPOUND; // Pauling
  if(system=="PtTa") return COMPOUND; // Pauling
  if(system=="PtTc") return NOMIX; // Pauling
  if(system=="PtTi") return COMPOUND; // Pauling
  if(system=="PtV") return COMPOUND; // Pauling
  if(system=="PtW") return NOMIX; // Pauling
  if(system=="PtY") return COMPOUND; // Pauling
  if(system=="PtZn") return COMPOUND; // Pauling
  if(system=="PtZr") return COMPOUND; // Pauling
  if(system=="RbMg" || system=="MgRb") return NOMIX; // Pauling
  if(system=="RbPd" || system=="PdRb") return UNKNOWN; // Pauling
  if(system=="RbPt" || system=="PtRb") return UNKNOWN; // Pauling
  if(system=="ReMg" || system=="MgRe") return NOMIX; // Pauling
  if(system=="ReRh") return NOMIX; // Pauling
  if(system=="ReRu") return NOMIX; // Pauling
  if(system=="ReSc") return COMPOUND; // Pauling
  if(system=="ReTa") return COMPOUND; // Pauling
  if(system=="ReTc") return NOMIX; // Pauling
  if(system=="ReTi") return COMPOUND; // Pauling
  if(system=="ReV") return COMPOUND; // Pauling
  if(system=="ReW") return COMPOUND; // Pauling
  if(system=="ReY") return COMPOUND; // Pauling
  if(system=="ReZn") return NOTSTUDIED; // Massalsky
  if(system=="ReZr") return COMPOUND; // Pauling
  if(system=="RhMg" || system=="MgRh") return COMPOUND; // Pauling
  if(system=="RhRu") return NOMIX; // Pauling
  if(system=="RhSc") return COMPOUND; // Pauling
  if(system=="RhTa") return COMPOUND; // Pauling
  if(system=="RhTc") return NOMIX; // Pauling
  if(system=="RhTi") return COMPOUND; // Pauling
  if(system=="RhTl") return UNKNOWN; // Pauling
  if(system=="RhV") return COMPOUND; // Pauling
  if(system=="RhW") return COMPOUND; // Pauling
  if(system=="RhY") return COMPOUND; // Pauling
  if(system=="RhZn") return COMPOUND; // Pauling
  if(system=="RhZr") return COMPOUND; // Pauling
  if(system=="RuMg" || system=="MgRu") return COMPOUND; // Pauling
  if(system=="RuSc") return COMPOUND; // Pauling
  if(system=="RuTa") return COMPOUND; // Pauling
  if(system=="RuTc") return NOMIX; // Pauling
  if(system=="RuTi") return COMPOUND; // Pauling
  if(system=="RuV") return COMPOUND; // Pauling
  if(system=="RuW") return COMPOUND; // Pauling
  if(system=="RuY") return COMPOUND; // Pauling
  if(system=="RuZn") return COMPOUND; // Pauling
  if(system=="RuZr") return COMPOUND; // Pauling
  if(system=="ScMg" || system=="MgSc") return COMPOUND; // Pauling
  if(system=="ScTa") return NOMIX; // Pauling
  if(system=="ScTc") return COMPOUND; // Pauling
  if(system=="ScTi") return NOMIX; // Pauling
  if(system=="ScV") return NOMIX; // Pauling
  if(system=="ScW") return NOMIX; // Pauling
  if(system=="ScY") return NOMIX; // Pauling
  if(system=="ScZn") return COMPOUND; // Pauling
  if(system=="ScZr") return NOMIX; // Pauling
  if(system=="SiMg" || system=="MgSi") return COMPOUND; // Pauling
  if(system=="SiPd" || system=="PdSi") return COMPOUND; // Pauling
  if(system=="SiPt" || system=="PtSi") return COMPOUND; // Pauling
  if(system=="SnMg" || system=="MgSn") return COMPOUND; // Pauling
  if(system=="SnPd" || system=="PdSn") return COMPOUND; // Pauling
  if(system=="SnPt" || system=="PtSn") return COMPOUND; // Pauling
  if(system=="SrMg" || system=="MgSr") return COMPOUND; // Pauling
  if(system=="SrPd" || system=="PdSr") return COMPOUND; // Pauling
  if(system=="SrPt" || system=="PdSr") return COMPOUND; // Pauling
  if(system=="TaMg" || system=="MgTa") return NOMIX; // Pauling
  if(system=="TaTc") return COMPOUND; // Pauling
  if(system=="TaTi") return NOMIX; // Pauling
  if(system=="TaV") return COMPOUND; // Pauling
  if(system=="TaW") return NOMIX; // Pauling
  if(system=="TaY") return NOMIX; // Pauling
  if(system=="TaZn") return COMPOUND; // Pauling
  if(system=="TaZr") return NOMIX; // Pauling
  if(system=="TcTi") return COMPOUND; // Pauling
  if(system=="TcV") return COMPOUND; // Pauling
  if(system=="TcW") return COMPOUND; // Pauling
  if(system=="TcY") return COMPOUND; // Pauling
  if(system=="TcZn") return COMPOUND; // Pauling
  if(system=="TcZr") return COMPOUND; // Pauling
  if(system=="TiMg" || system=="MgTi") return NOMIX; // Pauling
  if(system=="TiV") return NOMIX; // Pauling
  if(system=="TiW") return NOMIX; // Pauling
  if(system=="TiY") return NOMIX; // Pauling
  if(system=="TiZn") return COMPOUND; // Pauling
  if(system=="TiZr") return NOMIX; // Pauling
  if(system=="VMg" ||system=="MgV") return NOMIX; // Pauling
  if(system=="VW") return NOMIX; // Pauling
  if(system=="VY") return NOMIX; // Pauling
  if(system=="VZn") return COMPOUND; // Pauling
  if(system=="VZr") return COMPOUND; // Pauling
  if(system=="WMg" || system=="MgW") return NOMIX; // Pauling
  if(system=="WY") return NOMIX; // Pauling
  if(system=="WZn") return NOMIX; // Pauling
  if(system=="WZr") return COMPOUND; // Pauling
  if(system=="YMg" || system=="MgY") return COMPOUND; // Pauling
  if(system=="YZn") return COMPOUND; // Pauling
  if(system=="YZr") return NOMIX; // Pauling
  if(system=="ZnMg" || system=="MgZn") return COMPOUND; // Pauling
  if(system=="ZnZr") return COMPOUND; // Pauling
  if(system=="ZrMg" || system=="MgZr") return NOMIX; // Pauling
  // If not found then UNKNOWN
  return MISCIBILITY_SYSTEM_UNKNOWN; // unknown
}
// ***************************************************************************
#endif

// ***************************************************************************
// *                                                                         *
// *           Aflow STEFANO CURTAROLO - Duke University 2003-2018           *
// *                                                                         *
// ***************************************************************************
