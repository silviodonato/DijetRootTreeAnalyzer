import ROOT
import array

ROOT.gROOT.SetBatch(1)

xbins, xmin, xmax = 200,0, 1000
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
file_ = ROOT.TFile.Open("../data_ntuple_full_study_10perc.root")
#file_ = ROOT.TFile.Open("../data_ntuple_full_study.root")


tree = file_.Get("tree")
if not type(tree)==ROOT.TTree:
    tree = file_.Get("rootTupleTree/tree")

ROOT.gInterpreter.ProcessLine(".L function.C+")

#preselection = "isr_pt>=70 &&  deltaR(jet1_eta,jet1_phi,jet2_eta,jet2_phi)>1.1 && deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1"

preselection = "isr_pt>=70 "

tree.Draw("abs(jet1_eta-jet2_eta)<1.1:MyMassNoCut(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt, jet2_eta, jet2_phi, jet2_mass) >> dijetMass(%d,%d,%d)"%(xbins, xmin, xmax),preselection,"prof")
dijetMass = ROOT.gDirectory.Get("dijetMass").Clone("dijetMass")

tree.Draw("abs(jet1_eta+jet2_eta)<1.1:MyMassNoCut(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt,-jet2_eta, jet2_phi, jet2_mass) >> dijetMass2(%d,%d,%d)"%(xbins, xmin, xmax),preselection,"prof")

dijetMass2 = ROOT.gDirectory.Get("dijetMass2").Clone("dijetMass2")

dijetMass.SetLineColor(ROOT.kRed)
dijetMass.SetMarkerColor(ROOT.kRed)


dijetMass.Draw("HIST,ERR")
dijetMass2.Draw("HIST,ERR,same")

canv.SaveAs("tmp/Sum_Delta_Eta.png")
canv.SaveAs("tmp/Sum_Delta_Eta.pdf")
canv.SaveAs("tmp/Sum_Delta_Eta.root")
canv.SaveAs("tmp/Sum_Delta_Eta.C")

canv2 = ROOT.TCanvas("canv2","",720,480)
canv2.SetGridx()
canv2.SetGridy()
canv2.SetLogy(0)

ratio = dijetMass.ProjectionX().Clone("ratio")
ratio.Divide(dijetMass2.ProjectionX(),dijetMass.ProjectionX())
ratio.Draw("HIST,ERR")

fit = ROOT.TF1("fit","[0]*(TMath::Erf((x-[1])/[2]) +[3] + [4]*x + [5]*x*x)",xmin,xmax)
fit.SetParameter(0, 4.30101e-01)
fit.SetParameter(1, 4.35588e+01)
fit.SetParameter(2, 3.17064e+01)
fit.SetParameter(3, 1.40279e+00)
fit.SetParameter(4, 3.39522e-04)
fit.SetParameter(5, -9.52332e-07)

print(fit.GetExpFormula("P"))
print(fit.GetMaximum())

ratio.Fit(fit)
fit.Draw("same")

canv2.SaveAs("tmp/DijetMass_correction_ratio.png")
canv2.SaveAs("tmp/DijetMass_correction_ratio.root")
canv2.SaveAs("tmp/DijetMass_correction_ratio.C")
canv2.SaveAs("tmp/DijetMass_correction_ratio.pdf")

