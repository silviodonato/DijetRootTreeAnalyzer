import ROOT

# ROOT.gROOT.SetBatch(0)
# canv2 = ROOT.TCanvas()

ROOT.gROOT.SetBatch(1)
canv = ROOT.TCanvas()
canv.SetGridx()
canv.SetGridy()

ROOT.gStyle.SetOptStat(0)

fileName = "Javier.root"
denTrigger = "passHLT_CaloJet40_CaloScouting_PFScouting"

preselect = denTrigger + " && abs(deltaETAjjAK4)<1.3 && abs(etaAK4_j1)<2.5 && abs(etaAK4_j2)<2.5 && pTAK4_j1>65 && pTAK4_j2>40 && PassJSON && passHLT_CaloJet40_CaloScouting_PFScouting && mjj>100 && run<=280385 && run>=277991"

file_ = ROOT.TFile.Open(fileName)

tree = file_.Get("tree")

trigger = "passHLT_CaloScoutingHT250"
title = "Trigger efficiency of HLT_CaloScoutingHT250"


varX = "mjj"
varX_nbins,   varX_min,  varX_max = 100,200,700
varX_title = "m_{jj}"

preselect += "&& (%s < %d)"%(varX,varX_max)

tree.Draw("%s >> den1D(%d,%d,%d)"%(varX,varX_nbins,varX_min,varX_max),"%s"%(preselect) ,"")
den = ROOT.gDirectory.Get("den1D")
tree.Draw("%s >> num1D(%d,%d,%d)"%(varX,varX_nbins,varX_min,varX_max),"%s && %s"%(preselect,trigger) ,"")
num = ROOT.gDirectory.Get("num1D")
num.Sumw2()
den.Sumw2()
eff = ROOT.TGraphAsymmErrors();
eff.SetName("eff1D")
eff.Divide(num,den)

eff.SetTitle(title)
eff.SetMaximum(1.0001)
eff.SetMinimum(0.)
num.SetTitle("numerator")
den.SetTitle("denominator")

for histo in [num, den]:
    histo.GetXaxis().SetTitle(varX_title)
    histo.Draw("E")
    canv.SaveAs(histo.GetName()+".png")
    canv.SaveAs(histo.GetName()+".root")
    canv.SaveAs(histo.GetName()+".C")
    

func = ROOT.TF1("func","erf((x-[0])/[1])*[2]+[3]",varX_min,varX_max)
func.SetParameters(200,40,0.5,0.5)
func = ROOT.TF1("func","[0]",varX_min,varX_max)
func.SetParameter(0,0.99)
eff.Fit(func)
#eff.Fit(func,"","",max(varX_min,func.GetParameter(0)),varX_max)
#eff.Fit(func,"","",max(varX_min,func.GetParameter(0)),varX_max)
#eff.Fit(func,"","",max(varX_min,func.GetParameter(0)),varX_max)
#eff.Fit(func,"","",max(varX_min,func.GetParameter(0)),varX_max)
#eff.Fit(func,"","",max(varX_min,func.GetParameter(0)),varX_max)
#eff.Fit(func,"","",max(varX_min,func.GetParameter(0)),varX_max)
eff.GetXaxis().SetTitle(varX_title)
eff.Draw("AP")
canv.SaveAs(eff.GetName()+"_Javier.png")
canv.SaveAs(eff.GetName()+"_Javier.root")
canv.SaveAs(eff.GetName()+"_Javier.C")
