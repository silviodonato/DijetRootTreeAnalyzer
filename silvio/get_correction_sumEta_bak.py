import ROOT
import array

ROOT.gROOT.SetBatch(0)

xbins, xmin, xmax = 200,0, 500
xtitle = ""

ROOT.gStyle.SetOptStat(0)
canv = ROOT.TCanvas("canv","",720,480)
canv.SetGridx()
canv.SetGridy()
canv.SetLogy(0)

file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim_40.root")
#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim.root")
#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5.root")
#file_ = ROOT.TFile.Open("../data_ntuple_CR_studies.root")
#file_ = ROOT.TFile.Open("../data_ntuple_CR_nocut.root")
#file_ = ROOT.TFile.Open("../data_ntuple_full_study_10perc.root")
#file_ = ROOT.TFile.Open("../data_ntuple_full_study.root")
#file_ = ROOT.TFile.Open("mc_signal_300.root")

sigMass = 300
#sigFile_ = ROOT.TFile.Open("mc_signal_%d.root"%sigMass)

tree = file_.Get("tree")
if not type(tree)==ROOT.TTree:
    tree = file_.Get("rootTupleTree/tree")

ROOT.gInterpreter.ProcessLine(".L function.C+")

#preselection = "isr_pt>=70 &&  deltaR(jet1_eta,jet1_phi,jet2_eta,jet2_phi)>1.1 && deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1"

preselection = "isr_pt>=70 "


'''

print("Draw1")
tree.Draw("abs(jet1_eta+jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> sumEta2D(%d,%d,%d,2,-0.5,1.5)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1","")
sumEta = ROOT.gDirectory.Get("sumEta2D").ProfileX().Clone("sumEta")


print("Draw2")
tree.Draw("abs(jet1_eta-jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> deltaEta2D(%d,%d,%d,2,-0.5,1.5)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,jet2_eta,jet2_phi)>1.1","")

print("Done")

deltaEta = ROOT.gDirectory.Get("deltaEta2D").ProfileX().Clone("deltaEta")
'''

print("Draw1")
tree.Draw("abs(jet1_eta+jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> sumEta(%d,%d,%d)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1","prof")
sumEta = ROOT.gDirectory.Get("sumEta").Clone("sumEta")

print("Draw2")
tree.Draw("abs(jet1_eta-jet2_eta)<1.1:sqrt(jet1_pt*jet2_pt) >> deltaEta(%d,%d,%d)"%(xbins, xmin, xmax),preselection + "&& deltaR(jet1_eta,jet1_phi,jet2_eta,jet2_phi)>1.1","prof")

print("Done")

deltaEta = ROOT.gDirectory.Get("deltaEta").Clone("deltaEta")

sumEta.SetLineColor(ROOT.kRed)
sumEta.SetMarkerColor(ROOT.kRed)

print(sumEta.GetBinContent(30))
print(sumEta.GetBinError(30))
print(deltaEta.GetBinContent(30))
print(deltaEta.GetBinError(30))

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

fit = ROOT.TF1("fit","[0]*(TMath::Erf((x-[1])/[2]) +[3] + [4]*x + [5]*x*x)",xmin,xmax)
fit.SetParameter(0, 4.30101e-01)
fit.SetParameter(1, 4.35588e+01)
fit.SetParameter(2, 3.17064e+01)
fit.SetParameter(3, 1.40279e+00)
fit.SetParameter(4, 3.39522e-04)
fit.SetParameter(5, -9.52332e-07)


ratio.Fit(fit)
fit.Draw("same")

canv2.SaveAs("tmp/Sum_Delta_Eta_ratio.png")
canv2.SaveAs("tmp/Sum_Delta_Eta_ratio.root")
canv2.SaveAs("tmp/Sum_Delta_Eta_ratio.C")
canv2.SaveAs("tmp/Sum_Delta_Eta_ratio.pdf")

print(fit.GetExpFormula("P"))
print(fit.GetMaximum())

