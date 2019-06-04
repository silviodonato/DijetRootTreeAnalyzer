import ROOT
import array



lumi = 21.190

ROOT.gROOT.SetBatch(0)

xbins, xmin, xmax = 5000,0, 5000
xtitle = ""

ROOT.gStyle.SetOptStat(0)
canv = ROOT.TCanvas("canv","",720,480)
canv.SetGridx()
canv.SetGridy()
canv.SetLogy(0)

isrPtCut = 40

preselection = "isr_pt>%d && abs(dijet_deta)<1.1 && abs(jet1_eta)<2.5 && abs(jet2_eta)<2.5 && abs(isr_eta)<2.5 && L1_HTT240"%isrPtCut

fileHisto_ = ROOT.TFile.Open("../data_th1f_full_newmethod_signal.root")

#fileTree_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim_40.root")
#fileTree_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim.root")
#fileTree_ = ROOT.TFile.Open("../data_trig_eff_eta2.5.root")
#fileTree_ = ROOT.TFile.Open("../data_ntuple_CR_studies.root")
#fileTree_ = ROOT.TFile.Open("../data_ntuple_CR_nocut.root")
#fileTree_ = ROOT.TFile.Open("../data_ntuple_full_study_10perc.root")
fileTree_ = ROOT.TFile.Open("../data_ntuple_full_study.root")


dijetHisto = fileHisto_.Get("dijetMassHisto_isrptcut_%d"%isrPtCut).Clone("dijetHisto")


tree = fileTree_.Get("tree")
if not type(tree)==ROOT.TTree:
    tree = fileTree_.Get("rootTupleTree/tree")





print("Draw1")
tree.Draw("dijet_mass >> histo(%d,%d,%d)"%(xbins, xmin, xmax), preselection,"")
histo = ROOT.gDirectory.Get("histo").Clone("histo")

fileNorm = dijetHisto.Integral()
treeNorm = histo.Integral()

histo.Scale(fileNorm/treeNorm)
histo.SetLineColor(ROOT.kRed)

print("Lumi file %f"%lumi)
print("Lumi tree %f"%(lumi*treeNorm/fileNorm))

histo.Draw()
dijetHisto.Draw("same")
