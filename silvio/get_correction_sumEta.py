import ROOT
import array

sigMass = 0

from inputAcceptance import acc_dict
lumi = 0.520984 #fb-1
lumi = lumi * 1000 #pb-1

#asymptoticFile = "/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak/xsecUL_Asymptotic_qq_CaloTrijet2016.root"
asymptoticFile = "/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_fullFakeLumi/xsecUL_Asymptotic_qq_CaloTrijet2016.root"
asymptoticRootFile = ROOT.TFile.Open(asymptoticFile,"READ")
xsecTree = asymptoticRootFile.Get("xsecTree")
limits = {}
for entry in xsecTree:
    limits[entry.mass] = entry.xsecULExp_CaloTrijet2016 / acc_dict["jets01"][entry.mass] #sigma(pb)*A / A


ROOT.gROOT.SetBatch(0)

xbins, xmin, xmax = 272, 70, 750
#xbins, xmin, xmax = 212, 70, 600
#xbins, xmin, xmax = 240,0, 600
#xbins, xmin, xmax = 168,80, 500
#xbins, xmin, xmax = 168,80, 500
#xbins, xmin, xmax = 172,70, 500
#xbins, xmin, xmax = 200,0, 500
xtitle = ""

ROOT.gStyle.SetOptStat(0)
canv = ROOT.TCanvas("canv","",720,480)
canv.SetGridx()
canv.SetGridy()
canv.SetLogy(0)


#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim_40.root")
#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim.root")
#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5.root")
#file_ = ROOT.TFile.Open("../data_ntuple_CR_studies.root")
#file_ = ROOT.TFile.Open("../data_ntuple_CR_nocut.root")
#file_ = ROOT.TFile.Open("../data_ntuple_full_study_10perc.root") ##0.055286
#file_ = ROOT.TFile.Open("../data_ntuple_full_study.root") ##0.520984
#file_ = ROOT.TFile.Open("/work/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/hadd_runH/data_th3f_full_newmethod_runH.root")
#file_ = ROOT.TFile.Open("/work/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/data_runH_ntuple.root")
file_ = ROOT.TFile.Open("../inputs_Silvio/data_RunH_ntuple_long.root")


tree = file_.Get("tree")
if not type(tree)==ROOT.TTree:
    tree = file_.Get("rootTupleTree/tree")

sigTree = 0
sigentries = 0
if sigMass>0:
    sigFile_ = ROOT.TFile.Open("mc_signal_%d.root"%sigMass)
    sigTree = file_.Get("tree")
    if not type(sigTree)==ROOT.TTree:
        sigTree = file_.Get("rootTupleTree/tree")
    sigentries = sigTree.GetEntries()


ROOT.gInterpreter.ProcessLine(".L function.C+")

#preselection = "isr_pt>=70 &&  deltaR(jet1_eta,jet1_phi,jet2_eta,jet2_phi)>1.1 && deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1"

preselection = "isr_pt>=70 && HLT_CaloScoutingHT250 && L1_HTT270"



print("Draw1")
tree.Draw("abs(jet1_eta+jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> sumEta2D(%d,%d,%d,2,-0.5,1.5)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1","")
sumEta2D = ROOT.gDirectory.Get("sumEta2D").Clone("sumEta2D")

if sigMass>0:
    sigTree.Draw("abs(jet1_eta+jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> sumEta2D_sig(%d,%d,%d,2,-0.5,1.5)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1","")
    sumEta2D_sig = ROOT.gDirectory.Get("sumEta2D_sig").Clone("sumEta2D_sig")
    sumEta2D.Add(sumEta2D_sig, lumi*limits[sigMass]/sigentries)

sumEta = sumEta2D.ProfileX().Clone("sumEta")

##############################################

print("Draw2")
tree.Draw("abs(jet1_eta-jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> deltaEta2D(%d,%d,%d,2,-0.5,1.5)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,jet2_eta,jet2_phi)>1.1","")

deltaEta2D = ROOT.gDirectory.Get("deltaEta2D").Clone("deltaEta2D")

if sigMass>0:
    sigTree.Draw("abs(jet1_eta+jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> deltaEta2D_sig(%d,%d,%d,2,-0.5,1.5)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1","")
    deltaEta2D_sig = ROOT.gDirectory.Get("deltaEta2D_sig").Clone("deltaEta2D_sig")
    deltaEta2D.Add(deltaEta2D_sig, lumi*limits[sigMass]/sigentries)
    
deltaEta = deltaEta2D.ProfileX().Clone("deltaEta")


######################################################

print("Done")

'''

print("Draw1")
tree.Draw("abs(jet1_eta+jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> sumEta(%d,%d,%d)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1","prof")
sumEta = ROOT.gDirectory.Get("sumEta").Clone("sumEta")

print("Draw2")
tree.Draw("abs(jet1_eta-jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> deltaEta(%d,%d,%d)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,jet2_eta,jet2_phi)>1.1","prof")

print("Done")

deltaEta = ROOT.gDirectory.Get("deltaEta").Clone("deltaEta")
'''

sumEta.SetLineColor(ROOT.kRed)
sumEta.SetMarkerColor(ROOT.kRed)

print(sumEta.GetBinContent(30))
print(sumEta.GetBinError(30))
print(deltaEta.GetBinContent(30))
print(deltaEta.GetBinError(30))

sumEta.SetTitle("")
sumEta.GetYaxis().SetTitle("Ratio")
sumEta.GetXaxis().SetTitle("#sqrt{p^{T}_1p^{T}_2}")

sumEta.Draw("HIST,ERR")
deltaEta.Draw("HIST,ERR,same")

canv.SaveAs("tmp/Sum_Delta_Eta.png")
canv.SaveAs("tmp/Sum_Delta_Eta.C")
canv.SaveAs("tmp/Sum_Delta_Eta.root")
canv.SaveAs("tmp/Sum_Delta_Eta.pdf")

canv2 = ROOT.TCanvas("canv2","",720,480)
canv2.SetGridx()
canv2.SetGridy()
canv2.SetLogy(0)

ratio = sumEta.ProjectionX().Clone("ratio")
ratio.Divide(deltaEta.ProjectionX(),sumEta.ProjectionX())
ratio.Draw("HIST,ERR")

'''
fit = ROOT.TF1("fit","[0]*(TMath::Erf((x-[1])/[2]) +[3] + [4]*x + [5]*x*x)",xmin,xmax)
fit.SetParameter(0, 4.30101e-01)
fit.SetParameter(1, 4.35588e+01)
fit.SetParameter(2, 3.17064e+01)
fit.SetParameter(3, 1.40279e+00)
fit.SetParameter(4, 3.39522e-04)
fit.SetParameter(5, -9.52332e-07)


ratio.Fit(fit)
fit.Draw("same")
'''


ratio.Draw()

fit = ROOT.TF1("fit","[0]*(TMath::Erf((x-[1])/[2]) +[3] + [4]*x + [5]*x*x)/(1+[6] + [7]*x+ [8]*x*x)",xmin,xmax)
fit.SetParameter(0, 3.85055e-01)
fit.SetParameter(1, 3.72598e+01)
fit.SetParameter(2, 3.95537e+01)
fit.SetParameter(3, 1.47707e+00)
fit.SetParameter(4, -8.40785e-03)
fit.SetParameter(5, 9.86701e-06)
fit.SetParameter(6, -4.62415e-02)
fit.SetParameter(7, -3.51607e-03)
fit.SetParameter(8, 4.69648e-06)

for i in range(0,10):
    ratio.Fit(fit)

fit.Draw("same")


canv2.SaveAs("tmp/Sum_Delta_Eta_ratio.png")
canv2.SaveAs("tmp/Sum_Delta_Eta_ratio.root")
canv2.SaveAs("tmp/Sum_Delta_Eta_ratio.C")
canv2.SaveAs("tmp/Sum_Delta_Eta_ratio.pdf")

print(fit.GetExpFormula("P"))
print(fit.GetMaximum())


histo2 = deltaEta2D.ProjectionX().Clone("histo2")
histo3 = sumEta2D.ProjectionX().Clone("histo3")


histo2.SetTitle("")
histo2.GetYaxis().SetTitle("Events")
histo2.GetXaxis().SetTitle("#sqrt{p^{T}_1p^{T}_2}")


histo2.Draw()
#histo3.Draw("same")

canv2.SaveAs("tmp/histo.png")
canv2.SaveAs("tmp/histo.root")
canv2.SaveAs("tmp/histo.C")
canv2.SaveAs("tmp/histo.pdf")

