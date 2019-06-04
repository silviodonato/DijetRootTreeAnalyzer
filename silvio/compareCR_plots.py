import ROOT
import array

ROOT.gROOT.SetBatch(0)

ROOT.gROOT.LoadMacro("tdrstyleTrigger.C")
ROOT.setTDRStyle()
ROOT.gROOT.LoadMacro("CMS_lumi.C")
ROOT.gROOT.ProcessLine('lumi_7TeV="1.8 fb^{-1} (13 TeV)"')
#ROOT.gROOT.ProcessLine('lumi_7TeV="t#bar{t}, PU=35"')
#ROOT.gROOT.ProcessLine('extraText   = "Simulation Preliminary"')
#ROOT.gROOT.ProcessLine('extraText   = "Simulation"')
ROOT.gROOT.ProcessLine('extraText   = ""')


title = "Di-jet mass plot"
histoName = "dijetMassHisto_isrptcut_70"

#massBoundaries = [i*10 for i in range(1000)]
#massBoundaries = [i for i in range(1000)]
#massBoundaries = [i*5 for i in range(1000)]
#massBoundaries = [i*10 for i in range(1000)]
massBoundaries = [1, 3, 6, 10, 16, 23, 31, 40, 50, 61, 74, 88, 103, 119, 137, 156, 176, 197, 220, 244, 270, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838,  890, 944, 1000, 1058, 1118, 1181, 1246, 1313, 1383, 1455, 1530, 1607, 1687, 1770, 1856, 1945, 2037, 2132, 2231, 2332, 2438, 2546, 2659, 2775, 2895, 3019, 3147, 3279, 3416, 3558, 3704, 3854, 4010, 4171, 4337, 4509, 4686, 4869, 5058, 5253, 5455, 5663, 5877, 6099, 6328, 6564, 6808,  7060, 7320, 7589, 7866, 8152, 8447, 8752, 9067, 9391, 9726, 10072, 10430, 10798, 11179, 11571, 11977, 12395, 12827, 13272, 13732, 14000]


normalize_min = 255
varX_min,  varX_max = 255,1000

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
def getRatio(data, histo2, padSizeRatio):
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
#            fx_cen = max(0.001,funct.Eval(bin_cen))
#            fx = max(0.001,funct.Integral(bin_low,bin_high) / (bin_high-bin_low) )
            fx = histo2.GetBinContent(i)
            
#            val = (data.GetBinContent(i) - fx)/(data.GetBinError(i)+1E-9)

            val = (data.GetBinContent(i) - fx)/(fx+1E-9) * 100
            err = (data.GetBinError(i)**2 + histo2.GetBinError(i)**2)**0.5/(fx+1E-9) * 100
            ratio.SetBinContent(i,val)
            ratio.SetBinError(i,err)
            maxPull = max(maxPull,abs(val))
        else:
            ratio.SetBinContent(i,100)
    
#    ratio.SetMaximum(+1.49)
#    ratio.SetMinimum(-1.49)
    ratio.SetMaximum(+0.45)
    ratio.SetMinimum(-0.45)
    print("maxPull=",maxPull)
    return ratio


canv = ROOT.TCanvas("canv","",1280,1024)
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

#file_orig = ROOT.TFile.Open("../data_th1f_newcr_test_deta_0p0_1p1.root")
#file_flip = ROOT.TFile.Open("../data_th1f_newcr_test_deta_0p0_1p1_cr.root")

#file_orig = ROOT.TFile.Open("../data_th3f_cr2_deta1p1_sr.root")
#file_flip = ROOT.TFile.Open("../data_th3f_cr2_deta1p1_cr.root")

#file_orig = ROOT.TFile.Open("../data_th1f_newcr_test_deta_1p1_1p5.root")
#file_flip = ROOT.TFile.Open("../data_th1f_newcr_test_deta_1p1_1p5_cr.root")

#file_orig = ROOT.TFile.Open("../data_test_Apr_plot_sr.root")
#file_flip = ROOT.TFile.Open("../data_test_Apr_plot_cr.root")

#file_orig = ROOT.TFile.Open("../data_test_Apr_plot_deta_1p1_sr.root")
#file_flip = ROOT.TFile.Open("../data_test_Apr_plot_deta_1p1_cr.root")

#file_orig = ROOT.TFile.Open("../data_test_Apr_plot_deta_1p1_1p5_sr.root")
#file_flip = ROOT.TFile.Open("../data_test_Apr_plot_deta_1p1_1p5_cr.root")

#file_orig = ROOT.TFile.Open("../data_th1f_full_newmethod_sr_100percent.root")
#file_flip = ROOT.TFile.Open("../data_th1f_full_newmethod_cr_100percent.root")

#file_orig = ROOT.TFile.Open("../data_th1f_full_newmethod_10percent_sr.root")
#file_flip = ROOT.TFile.Open("../data_th1f_full_newmethod_10percent_cr.root")

#file_orig = ROOT.TFile.Open("data_test_Apr_plot_deta_1p1_sr_sig0.root")
#file_flip = ROOT.TFile.Open("data_test_Apr_plot_deta_1p1_cr_sig0.root")

#file_orig = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_new_method_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_new_method_cr.root")


#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_th1f_full_newmethod_0_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/data_th1f_full_newmethod_0_cr.root")


#file_orig = ROOT.TFile.Open("../inputs_Danyyl/test0_cr.root")
#file_flip = ROOT.TFile.Open("../inputs_Danyyl/test0_sr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/output_data_th3f_fulldata_newmethod_20190406_215315_Run2016BCDEFG_0_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/output_data_th3f_fulldata_newmethod_20190406_215315_Run2016BCDEFG_0_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/hist3D_filtered_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/hist3D_filtered_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_runH_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/data_runH_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_th3f_runH_newmethod_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/data_th3f_runH_newmethod_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_th3f_full_newmethod_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/data_th3f_full_newmethod_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/test_addRunH_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/test_addRunH_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_th1f_full_newmethod_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/data_th1f_full_newmethod_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/output_data_th3f_fulldata_newmethod_20190406_215315_Run2016BCDEFGH_0_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/output_data_th3f_fulldata_newmethod_20190406_215315_Run2016BCDEFGH_0_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_runH_oldCorr_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/data_runH_oldCorr_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_runBCDEFGH_new_0_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/data_runBCDEFGH_new_0_cr.root")

file_orig = ROOT.TFile.Open("../inputs_Silvio/output_data_th3f_fulldata_newmethod_20190406_215315_Run2016BCDEFG_0_sr.root")
file_flip = ROOT.TFile.Open("../inputs_Silvio/output_data_th3f_fulldata_newmethod_20190406_215315_Run2016BCDEFG_0_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/output_data_th3f_fulldata_newmethod_20190406_215315_Run2016H_0_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/output_data_th3f_fulldata_newmethod_20190406_215315_Run2016H_0_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_new_method_sr.root")
#file_flip = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_new_method_cr.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_th1f_full_sr_newmethod_10percent.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/data_th1f_full_cr_newmethod_10percent.root")

#file_orig = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_full_newmethod_sr_9.root")
#file_flip = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_full_newmethod_cr_9.root")

#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_th1f_full_newmethod_10percent_cr_0.root")
#file_flip = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_full_newmethod_cr_0.root")
#file_orig = ROOT.TFile.Open("../inputs_Silvio/data_th1f_full_newmethod_10percent_sr_0.root")
#file_flip = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_full_newmethod_sr_0.root")
#file_flip = ROOT.TFile.Open("../inputs_Silvio/data_th1f_full_newmethod_10percent_cr_0.root")

#file_orig = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_full_newmethod_cr_0.root")
#file_flip = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_full_newmethod_cr_00.root")
#file_flip = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_full_newmethod_cr_0.root")

#file_orig = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_full_newmethod_sr_0.root")
#file_flip = ROOT.TFile.Open("../inputs_Danyyl/data_th1f_full_newmethod_cr_0.root")



fileSig_orig = ROOT.TFile.Open("histograms_isrPt_signal_400.root")
fileSig_flip = ROOT.TFile.Open("histograms_isrPt_signal_flipped_400.root")

histo_orig = file_orig.Get(histoName).Clone("histo_orig")
histo_flip = file_flip.Get(histoName).Clone("histo_flip")
histoSig_orig = fileSig_orig.Get(histoName).Clone("histoSig_orig")
histoSig_flip = fileSig_flip.Get(histoName).Clone("histoSig_flip")

histo_flip.SetLineColor(ROOT.kRed)


canv.SetTitle(title)

histo_orig.GetXaxis().SetTitle(varX_title)


canv.Draw()
yPadSeparation = 0.25
padPlot = ROOT.TPad("padPlot","",0.,yPadSeparation,1.,1.)
padPlot.SetBottomMargin(.0)
padRatio = ROOT.TPad("padRatio","",0.,0.,1.,yPadSeparation)
padRatio.SetTopMargin(0)
padRatio.SetBottomMargin(.11/yPadSeparation)
padRatio.Draw()
padPlot.Draw()
canv.SetGridx(0)
canv.SetGridy(0)
padRatio.SetGridx(0)
padRatio.SetGridy(0)
padPlot.SetGridx(0)
padPlot.SetGridy(0)
padPlot.SetLogy(1)
padPlot.cd()
histo_orig.Sumw2()
histo_flip.Sumw2()
histo_orig = rebin(histo_orig)
histo_flip = rebin(histo_flip)
histoSig_orig = rebin(histoSig_orig)
histoSig_flip = rebin(histoSig_flip)
bin_low = histo_orig.FindBin(normalize_min)
bin_high = histo_orig.FindBin(varX_max)
#scale = 1.0480142708827895
scale = histo_orig.Integral(bin_low,bin_high)/(histo_flip.Integral(bin_low,bin_high))
histo_flip.Scale(scale)

histoSig_orig.Scale(scale)
histoSig_flip.Scale(scale)

histo_flip.GetXaxis().SetRangeUser(varX_min+1E-6, varX_max-1E-6)
histo_orig.GetXaxis().SetRangeUser(varX_min+1E-6, varX_max-1E-6)
#histo_orig.GetYaxis().SetTitle("Events")
histo_orig.GetYaxis().SetTitle("d#sigma/dm_{jj} [pb/TeV]")
histo_orig.SetLineColor(ROOT.kBlue)
histo_flip.SetLineColor(ROOT.kRed)
histoSig_orig.SetLineColor(ROOT.kBlue)
histoSig_flip.SetLineColor(ROOT.kRed)

histoSig_orig.SetLineStyle(2)
histoSig_flip.SetLineStyle(2)
histoSig_orig.SetLineWidth(2)
histoSig_flip.SetLineWidth(2)

histo_orig.SetLineWidth(2)
histo_flip.SetLineWidth(2)


histo_orig.Draw("HIST,ERR")
histo_flip.Draw("HIST,ERR,same")

histoSig_orig.Scale(300)
histoSig_flip.Scale(300)

histoSig_orig.Draw("HIST,same")
histoSig_flip.Draw("HIST,same")

leg = ROOT.TLegend(0.6,0.62,0.97,0.92)
#leg = TLegend(0.18,0.72,0.45,0.82)

leg.AddEntry(histo_orig,"signal region (data)","pel")
leg.AddEntry(histo_flip,"modified signal region (data)","pel")
leg.AddEntry(histoSig_orig,"signal region (400-GeV signal)","pel")
leg.AddEntry(histoSig_flip,"modified signal region (400-GeV signal)","pel")

leg.Draw("same")

padPlot.SetTitle(title)
padRatio.SetTitle("")

ROOT.CMS_lumi(padPlot,30,33)

padPlot.Draw()
padRatio.cd()

padSizeRatio = (padPlot.GetWh()*padPlot.GetAbsHNDC())/(padRatio.GetWh()*padRatio.GetAbsHNDC())
ratio = getRatio(histo_flip,histo_orig,padSizeRatio)
line = ROOT.TLine(varX_min, 0, varX_max, 0)
line.SetLineStyle(2)
ratio.Draw("E,HIST")
ratio.GetXaxis().SetTitle("m_{jj} [GeV]")
line.Draw()

padRatio.Draw()





canv.SaveAs(histo_orig.GetName()+"_ratio.png")
canv.SaveAs(histo_orig.GetName()+"_ratio.pdf")
canv.SaveAs(histo_orig.GetName()+"_ratio.root")
canv.SaveAs(histo_orig.GetName()+"_ratio.C")

#print(funct.GetExpFormula("P"))
