import os

#os.system("rm ../jetPairingMC/*")
os.system("mkdir -p ../jetPairingMC")

masses = [
    200, 300, 400, 500, 600, 800
]

#for matching in ["jets01","jets02","jets12"]:
for matching in ["dijetp"]:
    for mass in masses:
        command = "hadd -f ../jetPairingMC/signal_%s_%s.root /mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_%s_*_mc_*/rootfile_list_VectorDiJet1Jet_%s_*_reduced_skim.root"%(matching,mass,matching,mass)
        print(command)
        pipe = os.system(command)
    command = "hadd -f ../jetPairingMC/data_%s.root /mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_%s_*_data_*/rootfile_*reduced_skim.root"%(matching,matching)
    print(command)
    pipe = os.system(command)


for mass in masses:
    command = "hadd -f ../jetPairingMC/signal_comb_%s.root ../jetPairingMC/signal_jet*_%s.root"%(mass,mass)
    print(command)
    pipe = os.system(command)

command = "hadd -f ../jetPairingMC/data_comb.root ../jetPairingMC/data_jet*.root"
print(command)

