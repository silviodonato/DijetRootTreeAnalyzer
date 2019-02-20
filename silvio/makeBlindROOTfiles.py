import ROOT
import os


map = {
"dijetMassHisto_40_50_dijet_deta_cut":"dijetMassHisto_isrptcut_40_50",
"dijetMassHisto_50_60_dijet_deta_cut":"dijetMassHisto_isrptcut_50_60",
"dijetMassHisto_60_70_dijet_deta_cut":"dijetMassHisto_isrptcut_60_70",
"dijetMassHisto_70_80_dijet_deta_cut":"dijetMassHisto_isrptcut_70_80",
"dijetMassHisto_80_90_dijet_deta_cut":"dijetMassHisto_isrptcut_80_90",
"dijetMassHisto_90_100_dijet_deta_cut":"dijetMassHisto_isrptcut_90_100",
"dijetMassHisto_100_150_dijet_deta_cut":"dijetMassHisto_isrptcut_100_150",
"dijetMassHisto_150_200_dijet_deta_cut":"dijetMassHisto_isrptcut_150_200",
"dijetMassHisto_200_300_dijet_deta_cut":"dijetMassHisto_isrptcut_200_300",
"dijetMassHisto_300_dijet_deta_cut":"dijetMassHisto_isrptcut_300",
"dijetMassHisto_70_dijet_deta_cut":"dijetMassHisto_isrptcut_70",
"dijetMassHisto_70_HT_270_dijet_deta_cut":"dijetMassHisto_isrptcut_70_HT_270",
"dijetMassHisto_70_L1_HTT240_L1_HTT270_dijet_deta_cut":"dijetMassHisto_isrptcut_70_L1_HTT240_L1_HTT270",
"dijetMassHisto_L1_HTT_240_270_or_dijet_deta_cut":"dijetMassHisto_L1_HTT_240_270_or",
"dijetMassHisto_L1_HTT_240_270_280_or_dijet_deta_cut":"dijetMassHisto_L1_HTT_240_270_280_or",
"dijetMassHisto_L1_HTT_240_270_280_300_or_dijet_deta_cut":"dijetMassHisto_L1_HTT_240_270_280_300_or",
"dijetMassHisto_L1_HTT_240_270_280_300_320_or_dijet_deta_cut":"dijetMassHisto_L1_HTT_240_270_280_300_320_or",
"dijetMassHisto_70_L1_HTT240_L1_HTT320_dijet_deta_cut":"dijetMassHisto_70_L1_HTT240_L1_HTT320",
}

def makeBlindFile(fileIn):
    print("#CALLING makeBlindFile(%s)"%(fileIn))
    fileOut = fileIn.replace(".root","_blind.root")
    print("Creating %s"%(fileOut))
    f1 = ROOT.TFile.Open(fileIn)
    fo = ROOT.TFile.Open(fileOut,"RECREATE")

    dataFolderOld = "DijetFilter/dijetMassHisto_dijetCut"
    dataFolderNew = "DijetFilter/dijetMassHisto"
    fo.mkdir(dataFolderNew)
    for a in f1.Get(dataFolderOld).GetListOfKeys():
        obj1 = f1.Get(dataFolderOld).Get(a.GetName())
        fo.cd(dataFolderNew)
        out = obj1.Clone(map[obj1.GetName()])
        out.Write()
    fo.Close()

#makeBlindFile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/data_deta1p1_full.root")
#makeBlindFile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/data_deta1p3_full.root")
#makeBlindFile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/data_deta1p1_full_ten_percent.root")
#makeBlindFile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/data_deta1p3_full_ten_percent.root")

makeBlindFile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/data_wRunH_deta1p1_full.root")
makeBlindFile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/data_wRunH_deta1p1_full_ten_percent.root")

