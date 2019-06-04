import ROOT
from inputAcceptance import acc_dict
from Plot1DLimit_silvio import g_qsim, getThyXsecDict, q_qsim_withDM

def g_qsim(Mres):
    C_M = 0
    for mq in [2.2E-3, 4.7E-3, 95E-3, 1.275, 4.18, 173.0]:
        if Mres>2*mq:
            C_M += (1 - 4*(mq/Mres)**2 )**0.5 * (1 + 2*(mq/Mres)**2 )
    g_qsim = q_qsim_withDM * (1./(1.+1./(3*C_M*q_qsim_withDM**2)))**0.5
    return g_qsim


table_xsec = getThyXsecDict()



asymptoticFile = "/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_fullFakeLumi/xsecUL_Asymptotic_qq_CaloTrijet2016.root"
asymptoticRootFile = ROOT.TFile.Open(asymptoticFile,"READ")
xsecTree = asymptoticRootFile.Get("xsecTree")
limits_obs = {}
limits_exp = {}
for entry in xsecTree:
    limits_exp[entry.mass] = ROOT.TMath.Sqrt(entry.xsecULExp_CaloTrijet2016 /acc_dict["jets01"][int(entry.mass)]/table_xsec['DM1GeV'][int(entry.mass)])*g_qsim(int(entry.mass))
    limits_obs[entry.mass] = ROOT.TMath.Sqrt(entry.xsecULObs_CaloTrijet2016 /acc_dict["jets01"][int(entry.mass)]/table_xsec['DM1GeV'][int(entry.mass)])*g_qsim(int(entry.mass))

#####################################

datFile_exp = file("data/EXO19004_isr_exp.dat","w")

# mmed gq
datFile_exp.write("# mmed gq\n")
for mass in sorted(limits_exp.keys()):
    datFile_exp.write("%f\t%f\n"%(mass,limits_exp[mass]))

datFile_exp.close()

#####################################

datFile_obs = file("data/EXO19004_isr_obs.dat","w")

datFile_obs.write("# mmed gq\n")
for mass in sorted(limits_obs.keys()):
    datFile_obs.write("%f\t%f\n"%(mass,limits_obs[mass]))

datFile_obs.close()

#####################################

