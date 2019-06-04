import ROOT
import array

ROOT.gROOT.SetBatch(1)

title = "Di-jet mass plot"
histoName = "dijetMassHisto_isrptcut_70"

#massBoundaries = [i*10 for i in range(1000)]
#massBoundaries = [i for i in range(1000)]
massBoundaries = [i*3 for i in range(1000)]
#massBoundaries = [1, 3, 6, 10, 16, 23, 31, 40, 50, 61, 74, 88, 103, 119, 137, 156, 176, 197, 220, 244, 270, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838,  890, 944, 1000, 1058, 1118, 1181, 1246, 1313, 1383, 1455, 1530, 1607, 1687, 1770, 1856, 1945, 2037, 2132, 2231, 2332, 2438, 2546, 2659, 2775, 2895, 3019, 3147, 3279, 3416, 3558, 3704, 3854, 4010, 4171, 4337, 4509, 4686, 4869, 5058, 5253, 5455, 5663, 5877, 6099, 6328, 6564, 6808,  7060, 7320, 7589, 7866, 8152, 8447, 8752, 9067, 9391, 9726, 10072, 10430, 10798, 11179, 11571, 11977, 12395, 12827, 13272, 13732, 14000]


normalize_min = 220
varX_min,  varX_max = 220,500

varX = "dijet_mass"
varX_nbins = 50
varX_title = "m_{jj}"

def rebin(histo):
    oldWidth = 1.* histo.GetBinWidth(1)
    newHisto = ROOT.TH1F("histo", "", len(massBoundaries)-1, array.array('f',massBoundaries))
    for i in range(histo.GetNbinsX()):
        newHisto.Fill(histo.GetBinCenter(i), histo.GetBinContent(i))
    for i in range(newHisto.GetNbinsX()):
        newHisto.SetBinError(i, newHisto.GetBinContent(i)**0.5)
        newHisto.SetBinContent(i, newHisto.GetBinContent(i) * oldWidth / newHisto.GetBinWidth(i)  )
        newHisto.SetBinError(i, newHisto.GetBinError(i) * oldWidth / newHisto.GetBinWidth(i)  )
    return newHisto
    
## evaluate the ratio
'''
def getRatio(data, funct, padSizeRatio):
    ratio = data.Clone("ratio")
    ratio.Reset()
    
    ratio.GetYaxis().SetLabelSize(padSizeRatio*data.GetYaxis().GetLabelSize())
    ratio.GetXaxis().SetLabelSize(padSizeRatio*data.GetXaxis().GetLabelSize())
    ratio.GetYaxis().SetTitleSize(padSizeRatio*data.GetYaxis().GetTitleSize())
    ratio.GetXaxis().SetTitleSize(padSizeRatio*data.GetXaxis().GetTitleSize())
    ratio.GetYaxis().SetTitleOffset(1./padSizeRatio*data.GetYaxis().GetTitleOffset())
    ratio.GetXaxis().SetTitleOffset(1./data.GetXaxis().GetTitleOffset())
#    ratio.GetYaxis().SetTitle("Pull")    
    ratio.GetYaxis().SetTitle("Diff (%)")    
    ratio.GetXaxis().SetTitle(data.GetXaxis().GetTitle())    
    ratio.GetYaxis().SetNdivisions(805)
    
    maxPull = -1 
    for i in range(data.GetNbinsX()):
        bin_low = ratio.GetBinLowEdge(i)
        bin_high = ratio.GetBinLowEdge(i+1)
        bin_cen = ratio.GetBinCenter(i)
#        if(funct.GetXmin()<=bin_low and funct.GetXmax()>=bin_high ) or (fullRatioPlot and True):
        if True:
            fx_cen = max(0.001,funct.Eval(bin_cen))
#            fx = max(0.001,funct.Integral(bin_low,bin_high) / (bin_high-bin_low) )
            fx = max(0.001,funct.Integral(bin_low,bin_high) / (bin_high-bin_low) )
#            fx = histo2.GetBinContent(i)
            
#            val = (data.GetBinContent(i) - fx)/(data.GetBinError(i)+1E-9)

            val = (data.GetBinContent(i) - fx)/(fx+1E-9) * 100
            err = (data.GetBinError(i)**2 )**0.5/(fx+1E-9) * 100
            ratio.SetBinContent(i,val)
            ratio.SetBinError(i,err)
            maxPull = max(maxPull,abs(val))
        else:
            ratio.SetBinContent(i,100)
    
    ratio.SetMaximum(3)
    ratio.SetMinimum(-3)
    print("maxPull=",maxPull)
    return ratio
'''


canv = ROOT.TCanvas("canv","",1280,1024)
canv.SetGridx()
canv.SetGridy()
canv.SetLogy(1)

ROOT.gStyle.SetOptStat(0)

#file_orig = ROOT.TFile.Open("../data_th1f_newcr_test_central.root")
#file_flip = ROOT.TFile.Open("../data_th1f_newcr_test_central_cr.root")

#file_orig = ROOT.TFile.Open("../data_th1f_newcr_test_external.root")
#file_flip = ROOT.TFile.Open("../data_th1f_newcr_test_external_cr.root")

#file_orig = ROOT.TFile.Open("../data_10percent_th3f_test.root")
#file_flip = ROOT.TFile.Open("../data_10percent_th3f_test_cr.root")

#file_flip = ROOT.TFile.Open("../data_10percent_th3f_test_detaReg.root")
#file_orig = ROOT.TFile.Open("../data_10percent_th3f_test_detaReg.root")
#file_flip = ROOT.TFile.Open("../data_10percent_th3f_test_detaReg_cr.root")

file_orig = ROOT.TFile.Open("../data_th1f_newcr_test_deta_0p0_1p1.root")
file_flip = ROOT.TFile.Open("../data_th1f_newcr_test_deta_0p0_1p1_cr.root")

file_orig_cr = ROOT.TFile.Open("../data_th1f_newcr_test_deta_1p1_1p5.root")
file_flip_cr = ROOT.TFile.Open("../data_th1f_newcr_test_deta_1p1_1p5_cr.root")

#file_orig = ROOT.TFile.Open("../data_th3f_cr2_deta1p1_sr.root")
#file_flip = ROOT.TFile.Open("../data_th3f_cr2_deta1p1_cr.root")

#file_orig = ROOT.TFile.Open("../data_th1f_newcr_test_deta_1p1_1p5.root")
#file_flip = ROOT.TFile.Open("../data_th1f_newcr_test_deta_1p1_1p5_cr.root")


histo_orig = file_orig.Get(histoName).Clone("histo_orig")
histo_flip = file_flip.Get(histoName).Clone("histo_flip")
histo_orig_cr = file_orig_cr.Get(histoName).Clone("histo_orig_cr")
histo_flip_cr = file_flip_cr.Get(histoName).Clone("histo_flip_cr")



histo_orig = rebin(histo_orig)
histo_flip = rebin(histo_flip)
histo_orig_cr = rebin(histo_orig_cr)
histo_flip_cr = rebin(histo_flip_cr)


canv.SetLogy(0)

ratio_to_eta = histo_flip.Clone("ratio_to_eta")
ratio_to_eta.Reset()
ratio_to_eta.Divide(histo_flip_cr,histo_flip)
ratio_to_eta.GetXaxis().SetRangeUser(varX_min,  varX_max)
f1 = ROOT.TF1("f1","[0]*(TMath::Erf( (x-[1])/[2] + [5]*x*x  ) + [3] + [4]*x   )")
#f1.SetParameters(1,150,150)
f1.SetParameter(0,3.94451e-01)
f1.SetParameter(1,1.48337e+02)
f1.SetParameter(2,4.33323e+01)
f1.SetParameter(3,-1.94233e-01)
f1.SetParameter(4,1.07839e-03)
f1.SetParameter(5,-2.72527e-05)


canv.SetLogy(0)
ratio_to_eta.Draw("")
ratio_to_eta.Fit(f1)
canv.SetLogy(0)
canv.SaveAs("Ratio.png")
canv.SaveAs("Ratio.root")
canv.SaveAs("Ratio.C")

histo_flip.Draw()
histo_flip.GetXaxis().SetRangeUser(varX_min,  varX_max)
histo_flip_cr.SetLineColor(ROOT.kRed)
histo_flip_cr.SetMarkerColor(ROOT.kRed)
histo_flip_cr.Draw("same")

canv.SetLogy(1)
canv.SaveAs("TwoPlots.png")


new_histo = histo_orig_cr.Clone("new_histo")
new_histo.Divide(new_histo,ratio_to_eta)
new_histo.SetLineColor(ROOT.kRed)
new_histo.SetMarkerColor(ROOT.kRed)
new_histo.GetXaxis().SetRangeUser(varX_min,  varX_max)
new_histo.Draw("")
histo_orig.Draw("same")

canv.SetLogy(1)
canv.SaveAs("NewHisto.png")


canv.SetLogy(0)
ratio_histo = histo_flip.Clone("ratio_histo")
ratio_histo.Reset()
ratio_histo.Divide(new_histo,histo_orig)
ratio_histo.GetXaxis().SetRangeUser(varX_min,  varX_max)
ratio_histo.Draw()
ratio_histo.GetYaxis().SetRangeUser(1.0, 1.1)

canv.SaveAs("RatioHisto.png")

new_histo = histo_orig_cr.Clone("new_histo")
#new_histo.Divide(new_histo,ratio_to_eta)

data = histo_orig_cr
funct = f1
for i in range(data.GetNbinsX()):
    bin_low = new_histo.GetBinLowEdge(i)
    bin_high = new_histo.GetBinLowEdge(i+1)
    bin_cen = new_histo.GetBinCenter(i)
#        if(funct.GetXmin()<=bin_low and funct.GetXmax()>=bin_high ) or (fullRatioPlot and True):
    if True:
        fx_cen = max(0.001,funct.Eval(bin_cen))
        fx = max(0.000001,funct.Integral(bin_low,bin_high))  / (bin_high-bin_low)
        val = (data.GetBinContent(i) /  fx)
        err = data.GetBinError(i) / fx
        new_histo.SetBinContent(i,val)
        new_histo.SetBinError(i,err)
    else:
        new_histo.SetBinContent(i,100)


new_histo.SetLineColor(ROOT.kRed)
new_histo.SetMarkerColor(ROOT.kRed)
new_histo.GetXaxis().SetRangeUser(varX_min,  varX_max)
new_histo.GetXaxis().SetRangeUser(varX_min,  varX_max)
new_histo.Draw("")
histo_orig.Draw("same")
canv.SetLogy(1)
canv.SaveAs("NewHisto2.png")

canv.SetLogy(0)
ratio_histo = histo_flip.Clone("ratio_histo")
ratio_histo.Reset()
ratio_histo.Divide(new_histo,histo_orig)
ratio_histo.GetXaxis().SetRangeUser(varX_min,  varX_max)
ratio_histo.Draw()
ratio_histo.GetYaxis().SetRangeUser(1.0, 1.1)

canv.SaveAs("RatioHisto2.png")

'''
1/0

histo_flip.SetLineColor(ROOT.kRed)


canv.SetTitle(title)

histo_orig.GetXaxis().SetTitle(varX_title)

canv.Draw()
yPadSeparation = 0.25
padPlot = ROOT.TPad("padPlot","",0.,yPadSeparation,1.,1.)
padPlot.SetBottomMargin(.02)
padRatio = ROOT.TPad("padRatio","",0.,0.,1.,yPadSeparation)
padRatio.SetTopMargin(0)
padRatio.SetBottomMargin(.09/yPadSeparation)
padRatio.Draw()
padPlot.Draw()
padRatio.SetGridx()
padRatio.SetGridy()
padPlot.SetGridx()
padPlot.SetGridy()
padPlot.SetLogy(1)
padPlot.cd()
histo_orig.Sumw2()
histo_flip.Sumw2()
histo_orig = rebin(histo_orig)
histo_flip = rebin(histo_flip)
bin_low = histo_orig.FindBin(normalize_min)
bin_high = histo_orig.FindBin(varX_max)
histo_flip.Scale(histo_orig.Integral(bin_low,bin_high)/(histo_flip.Integral(bin_low,bin_high)))
histo_flip.GetXaxis().SetRangeUser(varX_min+1E-6, varX_max-1E-6)
histo_orig.GetXaxis().SetRangeUser(varX_min+1E-6, varX_max-1E-6)
histo_orig.GetYaxis().SetTitle("Events")
histo_orig.SetLineColor(ROOT.kBlue)
histo_flip.SetLineColor(ROOT.kRed)
histo_orig.Draw("ERR")
histo_flip.Draw("ERR,same")



padPlot.SetTitle(title)
padRatio.SetTitle("")


padPlot.Draw()
padRatio.cd()

padSizeRatio = (padPlot.GetWh()*padPlot.GetAbsHNDC())/(padRatio.GetWh()*padRatio.GetAbsHNDC())
ratio = getRatio(histo_flip,histo_orig,padSizeRatio)
ratio.Draw("E,HIST")
ratio.GetXaxis().SetTitle("m_{jj} [GeV]")
padRatio.Draw()


canv.SaveAs(histo_orig.GetName()+"_ratio.png")
canv.SaveAs(histo_orig.GetName()+"_ratio.root")
canv.SaveAs(histo_orig.GetName()+"_ratio.C")

#print(funct.GetExpFormula("P"))
'''
