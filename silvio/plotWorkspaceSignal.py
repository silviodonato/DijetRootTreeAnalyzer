import ROOT

_file = ROOT.TFile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/dijet_combine_qq_850_lumi-1.001_CaloTrijet2016.root")
wCaloTrijet2016 = _file.Get("wCaloTrijet2016")

mjj = wCaloTrijet2016.var("mjj")
th1x = wCaloTrijet2016.var("th1x")

CaloTrijet2016_bkg = wCaloTrijet2016.pdf("CaloTrijet2016_bkg")
extDijetPdf = wCaloTrijet2016.pdf("extDijetPdf")
data_obs = wCaloTrijet2016.data("data_obs")


frame = th1x.frame()
data_obs.plotOn(frame)
extDijetPdf.plotOn(frame)

frame.Draw()
