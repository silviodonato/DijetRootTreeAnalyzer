import ROOT
import array

redoPlot = True

'''
ROOT.gROOT.SetBatch(0)
canv2 = ROOT.TCanvas()
'''
colors = [
ROOT.kBlack,

ROOT.kYellow+1,
ROOT.kRed,
ROOT.kMagenta,
ROOT.kBlue,
ROOT.kCyan+1,
ROOT.kGreen+1,

ROOT.kOrange,
ROOT.kPink,
ROOT.kViolet,
ROOT.kAzure,
ROOT.kTeal,
ROOT.kSpring,

ROOT.kGray,
] 


#bins = range(200,800,50)
bins = range(60,200,10)
#bins = [60,70,80,90]


ROOT.gStyle.SetOptStat(0)

fileName = "../data_trig_eff_eta2.5.root"
#fileName = "../data_trig_eff_eta2.5_skim_40.root"

denTrigger = "1"
#denTrigger = "isr_pt>40"
#denTrigger = "isr_pt>=70 && HLT_CaloScoutingHT250"

preselect = denTrigger + "&& 1" #
title = "Di-jet mass plot"

varX = "abs(dijet_eta)"

varX_nbins,   varX_min,  varX_max = 30,0,6

varX_title = "m_{jj}"

fit_min = 320

#######################################################

N = 4
dijet_eta_max = 3
#canv.SetTitle(title)
preselect += "&& (%s < %d)"%(varX,varX_max)

file_ = ROOT.TFile(fileName)
tree = file_.Get("tree")
if not type(tree)==ROOT.TTree:
    tree = file_.Get("rootTupleTree/tree")
#tree.Draw("dijet_eta >> deta(100,0,%f)"%dijet_eta_max,"%s && dijet_mass>300"%(preselect) ,"")
#deta = ROOT.gDirectory.Get("deta")
#deta.Draw("HIST")

#x = array.array('d',[i*1./N for i in range(N)])
#y = array.array('d',[0 for i in range(N)])
#deta.GetQuantiles(N,y,x)
#bins = list(y)
#funct = ROOT.TF1("funct","pol4",0,3)
#deta.Fit(funct)
#funct.Draw("same")

#canv.SaveAs("histoMjj.root")

c2 = ROOT.TCanvas("c2","")
#c2.SetLogz()

import copy

g = ROOT.TGraph2D()
chi2 = {}
histos=[]
fits = []
for i in range(len(bins)-1):
    preselect = denTrigger + "&& sqrt(2*jet1_pt*jet2_pt)>%f && sqrt(2*jet1_pt*jet2_pt)<%f"%(bins[i],bins[i+1]) #
    tree.Draw("%s >> histo(%f,%f,%f)"%(varX,varX_nbins,varX_min,varX_max),"%s"%(preselect) ,"")
    histo = ROOT.gDirectory.Get("histo")
    histos.append(histo.Clone("%s < DijetMass < %s"%((round(bins[i],2)),round(bins[i+1],2))))


leg = ROOT.TLegend(0.52,0.7,0.9,0.9)
#leg.SetHeader("")

for i,histo in enumerate(histos):
    histo.SetTitle("")
    histo.GetXaxis().SetTitle("m(jj)")
    histo.GetYaxis().SetTitle("AU")
    histo.Sumw2()
    histo.Scale(1./histo.Integral(histo.FindBin(2.),varX_nbins))
    leg.AddEntry(histo,histo.GetName(),"l") 
    histo.SetLineColor(colors[i])
    histo.SetLineWidth(2)
    histo.SetMinimum(3E-2)
    histo.SetMaximum(2.*histo.GetMaximum())
    fit = ROOT.TF1("fit"+str(i),"gaus(0)+gaus(3)", varX_min,  varX_max)
    fit.SetParameters(0.082, 2.7, -1, 0.03, 0.5, -2.0)
    fit.SetLineColor(colors[i])
    histo.Fit(fit,"","",varX_min,  varX_max)
    fits.append(copy.deepcopy(fit))
    print(fits[i].GetParameter(1))
#    histos[-1].Fit(fit,"","",varX_min,  varX_max)

for i,histo in enumerate(histos):
    if i==0:
        histo.Draw("ERR")
#        histo.Draw("HIST,same")
    else:
        histo.Draw("ERR,same")
#        histo.Draw("HIST,same")
    print(fits[i].GetParameter(1))
    fits[i].Draw("same")



#c2.SetLogy()
leg.Draw()
c2.SaveAs("detaplotcheck.png")
c2.SaveAs("detaplotcheck.pdf")
#g.Draw("LEGO")c2.SaveAs("plotDetacheck.png")
