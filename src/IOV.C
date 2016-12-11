#include "IOV.h"

namespace jec{

void IOV::add(string id, int runmin, int runmax, bool isdata) {

    // sanity checks to avoid IOV overlaps
    assert(runmax>=runmin);
    assert(jecs.find(runmin)==jecs.end());
    for (IOVmap::const_iterator it = jecs.begin(); it != jecs.end(); ++it) {
      if (it->first < runmin) assert(it->second.first < runmin);
      if (it->first > runmin) assert(it->first > runmax);
    }
    
    const char *s;
    const char *dir = "data/Spring16_23Sep2016V1_DATA/";
    const char *tag = "Spring16_23Sep2016";
    const char *dtype = "V1_DATA";
    const char *a = _algo.c_str();

    // L1FastJet for AK*PF, L1Offset for others
    s = Form("%s%s%s%s_L1FastJet_%s.txt",dir,tag,id.c_str(),dtype,a); cout<<s<<endl<<flush;
    JetCorrectorParameters *par_l1 = new JetCorrectorParameters(s);
      //(_algo=="AK5PF" || _algo=="AK7PF" ?
      //new JetCorrectorParameters(Form("CondFormats/JetMETObjects/data/GR_R_42_V23_L1FastJet_%s.txt",a)) :
      //new JetCorrectorParameters(Form("CondFormats/JetMETObjects/data/GR_R_42_V23_L1Offset_%s.txt",a)));
      //
    s = Form("%s%s%s%s_L2Relative_%s.txt",dir,tag,id.c_str(),dtype,a); cout<<s<<endl<<flush;
    JetCorrectorParameters *par_l2 = new JetCorrectorParameters(s);
    s = Form("%s%s%s%s_L3Absolute_%s.txt",dir,tag,id.c_str(),dtype,a); cout<<s<<endl<<flush;
    JetCorrectorParameters *par_l3 = new JetCorrectorParameters(s);
    //JetCorrectorParameters *par_l2l3res = new JetCorrectorParameters(Form("CondFormats/JetMETObjects/data/GR_R_42_V23_L2L3Residual_%s.txt",a));
    s = Form("%s%s%s%s_L2L3Residual_%s.txt",dir,tag,id.c_str(),dtype,a); cout<<s<<endl<<flush;
    // Switched off IOV handling for now (or not. Juska.)
      //Form("CondFormats/JetMETObjects/data/Jec_V14_%s_L2L3Residual_%s.txt",id.c_str(),a));
    JetCorrectorParameters *par_l2l3res = new JetCorrectorParameters(s);
    vector<JetCorrectorParameters> vpar;
    vpar.push_back(*par_l1);
    vpar.push_back(*par_l2);
    vpar.push_back(*par_l3);
    if (isdata) vpar.push_back(*par_l2l3res);
    FactorizedJetCorrector *jec = new FactorizedJetCorrector(vpar);
    
    jecs[runmin] = pair<int, FactorizedJetCorrector*>(runmax, jec);
  } // add
  
  FactorizedJetCorrector *IOV::get(int run) {
    assert(jecs.size()!=0);
    for (IOVmap::const_iterator it = jecs.begin(); it != jecs.end(); ++it) {
      if (it->first <= run && run <= it->second.first)
        return it->second.second;
    }
    cout << "IOV for run " << run << " not found!!" << endl << flush;
    assert(false);
    return 0;
  } // get

} //namespace jec
