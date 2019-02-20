hadd -f data_deta1p1_full.root /mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_full_data_woH_jets01_deta1.1_20181214_135859/rootfile_list_ScoutingCaloHT_Run2016*_*_reduced_skim.root &

hadd -f data_deta1p1_full_ten_percent.root /mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_full_data_woH_jets01_deta1.1_20181214_135859/rootfile_list_ScoutingCaloHT_Run2016*_*9_reduced_skim.root &

hadd -f data_deta1p3_full.root /mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_full_data_woH_jets01_deta1.3_20181214_135941/rootfile_list_ScoutingCaloHT_Run2016*_*_reduced_skim.root &

hadd -f data_deta1p3_full_ten_percent.root /mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_full_data_woH_jets01_deta1.3_20181214_135941/rootfile_list_ScoutingCaloHT_Run2016*_*9_reduced_skim.root &

################################

hadd -f data_RunH_deta1p1_full.root /mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_data_full_RunH_jets01_deta1.1_20190121_154640/rootfile_list_ScoutingCaloHT_Run2016*_*_reduced_skim.root &

hadd -f data_RunH_deta1p1_full_ten_percent.root /mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_data_full_RunH_jets01_deta1.1_20190121_154640/rootfile_list_ScoutingCaloHT_Run2016*_*9_reduced_skim.root &

hadd -f data_wRunH_deta1p1_full.root data_deta1p1_full.root data_RunH_deta1p1_full.root

hadd -f data_wRunH_deta1p1_full_ten_percent.root data_deta1p1_full_ten_percent.root data_RunH_deta1p1_full_ten_percent.root


# run silvio/MakeBlindFiles.sh
