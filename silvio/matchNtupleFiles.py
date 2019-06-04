import os

splittedNtuple = "/work/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/config/list_RunH_test/splitted__20190514_111013/list_ScoutingCaloHT_Run2016H-v2_SIGNAL_20190514_111013_%d.txt"

splittedHisto = "/work/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/config/list_silvio_files_ScoutingCaloHT_Run2016H/splitted__20190520_175355/list_ScoutingCaloHT_Run2016H-v2_CaloHT_20190520_175355_%d.txt"



def getMap(splitted, inverted=False):
    map_ = {}
    num = 0
    while(os.path.isfile(splitted%num)):
        if inverted:
            map_[num] = open(splitted%num).readlines()[0]
        else:
            map_[open(splitted%num).readlines()[0]] = num
        num = num +1
    return map_

mapNtuple = getMap(splittedNtuple, True)
mapHisto = getMap(splittedHisto, False)

rootHisto = "/work/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_20190520_175355/rootfile_list_ScoutingCaloHT_Run2016H-v2_CaloHT_20190520_175355_%d_reduced_skim.root"

print ("hadd -f test.root \\")
for num in mapNtuple:
    histoNum = mapHisto[mapNtuple[num]]
    print(" %s \\"%(rootHisto%histoNum))

print ("")    
print ("")    
    
    
