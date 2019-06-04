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

colors = colors * 20

#bins = range(200,800,50)
#bins = range(-3,3)
#bins = [i*1./10. for i in range(-25,26)]
bins = [i*1./10. for i in range(-25,26,5)]
#bins = [60,70,80,90]


ROOT.gStyle.SetOptStat(0)

fileName = "../0683324A-6D0D-8443-A441-7FDF9D0CF9EC.root"
#fileName = "../data_trig_eff_eta2.5.root"
#fileName = "../data_trig_eff_eta2.5_skim_40.root"

denTrigger = "abs(Jet_eta[1])<2.5 && abs(Jet_eta[0])<2.5"
#denTrigger = "isr_pt>40"
#denTrigger = "isr_pt>=70 && HLT_CaloScoutingHT250"

preselect = denTrigger + "&& 1" #
title = "Jet2 eta"

varX = "Jet_eta[1]"

varX_nbins,   varX_min,  varX_max = 30,-2.5,2.5

varX_title = "m_{jj}"

fit_min = 320

#######################################################

N = 4
dijet_eta_max = 3
#canv.SetTitle(title)
preselect += "&& (%s < %d)"%(varX,varX_max)

file_ = ROOT.TFile(fileName)
tree = file_.Get("Events")
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
    preselect = denTrigger + "&& (Jet_eta[0])>%f && (Jet_eta[0])<%f"%(bins[i],bins[i+1]) #
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
    histo.Scale(1./histo.Integral(-1,varX_nbins))
    leg.AddEntry(histo,histo.GetName(),"l") 
    histo.SetLineColor(colors[i])
    histo.SetLineWidth(2)
    histo.SetMinimum(0)
    histo.SetMaximum(2.*histo.GetMaximum())
#    fit = ROOT.TF1("fit"+str(i),"gaus(0)+gaus(3)", varX_min,  varX_max)
#    fit.SetParameters(0.082, 2.7, -1, 0.03, 0.5, -2.0)
    fit = ROOT.TF1("fit"+str(i),"gaus(0)", varX_min,  varX_max)
    fit.SetParameters(0.05, 0.01, 1.7)
    fit.SetLineColor(colors[i])
    fitr = histo.Fit(fit,"","",varX_min,  varX_max)
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
c2.SaveAs("eta2plotcheck.png")
c2.SaveAs("eta2plotcheck.pdf")
#g.Draw("LEGO")c2.SaveAs("plotDetacheck.png")

means  = ROOT.TGraphErrors()
sigmas = ROOT.TGraphErrors()
for graph in [means,sigmas]:
    npar = 2
    if graph==means:
        npar = 1
    for i,fit in enumerate(fits):
        val = (bins[i]+bins[i+1])/2
        err = (float(bins[i+1])-bins[i])/2
        graph.SetPoint(i,val,fit.GetParameter(npar))
        graph.SetPointError(i,err,fit.GetParError(npar))

c3 = ROOT.TCanvas("c3")
means.Draw("APL")
means_fit = ROOT.TF1("means_fit","pol1")
means.Fit(means_fit)
c3.SaveAs("means.png")

c4 = ROOT.TCanvas("c4")
sigmas.Draw("APL")
sigmas_fit = ROOT.TF1("sigmas_fit","pol2")
sigmas_fit.SetParameters(2,0,-0.001)
sigmas.Fit(sigmas_fit)
c4.SaveAs("sigmas.png")

