# https://root.cern.ch/download/doc/RooFit_Users_Manual_2.91-33.pdf

import ROOT

c1 = ROOT.TCanvas("c1")

twoFiles = False
#file_ = ROOT.TFile.Open("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/signal_bias_test/higgsCombineqq_300_lumi-35.900_r-1.000_CaloTrijet2016_fiveparam_fiveparam.MaxLikelihoodFit.mH120.123456.root")

fileFit = ROOT.TFile.Open("bias_nom5_nom5/dijet_combine_qq_500_lumi-1.992_CaloTrijet2016.root")
#fileToys = ROOT.TFile.Open("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq/bias_nom5_nom5/higgsCombineqq_500_lumi-1.001_r-1.006_CaloTrijet2016_alt5_alt5.GenerateOnly.mH120.123456.root")
fileToys = ROOT.TFile.Open("bias_nom5_nom5/higgsCombineqq_500_lumi-1.992_r-0.001_CaloTrijet2016_nom5_nom5.GenerateOnly.mH120.123456.root")
toys = fileToys.Get("toys")
toy1 = toys.Get("toy_4")
toy2 = toys.Get("toy_2")

if twoFiles: 
    fileToys2 = ROOT.TFile.Open("bias_nom5_nom5/higgsCombineqq_600_lumi-1.992_r-0.213_CaloTrijet2016_alt5_alt5.GenerateOnly.mH120.123456.root")
    toys2 = fileToys2.Get("toys")
    toy2 = toys2.Get("toy_1")

w = fileFit.Get("wCaloTrijet2016")
extDijetPdf = w.pdf("extDijetPdf")
pdf_index = w.arg("pdf_index")

print("\nWorkSpace:")
w.Print()
print()

print("\toy1:")
toy1.Print()
print()


mjj = w.var("mjj")
th1x = w.var("th1x")

frame = th1x.frame()


#data.plotOn(frame)
#toy1.plotOn(frame)
#toy2.plotOn(frame,ROOT.RooFit.LineColor(ROOT.kRed))
#extDijetPdf.fitTo(toy1, ROOT.RooFit.Range(270,1000))
pdf_index.setIndex(9)
pdf_index.Print()
extDijetPdf.plotOn(frame)

frame.Draw("")


'''
    pdfIndexMap = {#'fourparam': 0,
                   'modexp': 0,
                   'fiveparam': 1,
                   'atlas': 2,
                   'atlas6': 3,
                   'silvio4': 4,
                   'silvio5': 5,
                   'silvio6': 6,
                   'nom3': 7,
                   'nom4': 8,
                   'nom5': 9,
                   'nom6': 10,
                   'nom7': 11,
                   'alt3': 12,
                   'alt4': 13,
                   'alt5': 14,
                   'alt6': 15,
                   'alt7': 16,
                   }
'''

result = extDijetPdf.fitTo((toy1),ROOT.RooFit.PrintLevel(-1),ROOT.RooFit.Save(),ROOT.RooFit.Verbose(ROOT.kFALSE), ROOT.RooFit.Range(0,17)) #ROOT.RooFit.Range(270,1000),
