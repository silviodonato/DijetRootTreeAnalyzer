import ROOT, array

ROOT.gROOT.SetBatch(1)

ROOT.gStyle.SetPaintTextFormat(".1f")

massBins_list = [1, 3, 6, 10, 16, 23, 31, 40, 50, 61, 74, 88, 103, 119, 137, 156, 176, 197, 220, 244, 270, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000, 1058, 1118, 1181, 1246, 1313, 1383, 1455, 1530, 1607, 1687, 1770, 1856, 1945, 2037, 2132, 2231, 2332, 2438, 2546, 2659, 2775, 2895, 3019, 3147, 3279, 3416, 3558, 3704, 3854, 4010, 4171, 4337, 4509, 4686, 4869, 5058, 5253, 5455, 5663, 5877, 6099, 6328, 6564, 6808, 7060, 7320, 7589, 7866, 8152, 8447, 8752, 9067, 9391, 9726, 10072, 10430, 10798, 11179, 11571, 11977, 12395, 12827, 13272, 13732, 14000]

ROOT.gStyle.SetOptStat(0)

c1 = ROOT.TCanvas("c1","")
c1.SetLeftMargin(0.13)
c1.SetBottomMargin(0.13)

chi2_maxRange = 4000

rang_min,  rang_max  = 220, 315
isrPt_min, isrPt_max = 40,  92

#rang_min,  rang_max  = 230, 285
#isrPt_min, isrPt_max = 50,  82

#rang_min,  rang_max  = 280, 290
#isrPt_min, isrPt_max = 60,  70




isrPt_bin = 2
rang_bin  = 5


def chi2Probability(folder,isrPt,rang):
#    fileName = folder+"/fit_results_CaloTrijet2016_isrpt_%d_minrange_%d/Plots_CaloTrijet2016.root"%(isrPt,rang)
    try:
        fileName = (folder+"/fit_results_CaloTrijet2016_isrpt_%d_minrange_%d/Plots_CaloTrijet2016.root")%(isrPt,rang,isrPt,rang)
        file_ = ROOT.TFile.Open(fileName)
#        print("Open %s"%fileName)
    except:
        fileName = (folder+"/fit_results_CaloTrijet2016_isrpt_%d_minrange_%d/Plots_CaloTrijet2016.root")%(isrPt,rang)
        file_ = ROOT.TFile.Open(fileName)
    canv = file_.Get("fit_results_CaloTrijet2016_isrpt_%d_minrange_%d/c"%(isrPt,rang))
    rat = canv.GetListOfPrimitives()[1].GetListOfPrimitives()[1]
    data = canv.GetListOfPrimitives()[0].GetListOfPrimitives()[1]
    funct = canv.GetListOfPrimitives()[0].GetListOfPrimitives()[2]
    graph = canv.GetListOfPrimitives()[0].FindObject("Graph_from_data_obs_rebin").Clone("graph")
    funct_histo = data.Clone("funct_histo")
    funct_histo.Reset()
    for i in range(1,graph.GetN()):
        bin_ = data.FindBin(graph.GetX()[ (i-1)])
        data.SetBinContent(bin_, graph.GetY()[i-1])
        data.SetBinError(bin_, graph.GetErrorY(i-1))
        xmin = 1.*data.GetBinLowEdge(bin_)
        xmax = 1.*data.GetBinLowEdge(bin_+1)
        integ = funct.Integral(xmin,xmax) / (xmax-xmin) 
        funct_histo.SetBinContent(bin_, integ )
        funct_histo.SetBinError(bin_, 0 )
#        print(xmin,xmax,data.GetBinContent(i), integ, (integ-data.GetBinContent(i))/integ)

#    print(data.GetXaxis().GetXmax())
#    print(data.GetXaxis().GetXmin())
#    print(data.GetXaxis().GetNbins())
#    print(funct_histo.GetXaxis().GetXmax())
#    print(funct_histo.GetXaxis().GetXmin())
#    print(funct_histo.GetXaxis().GetNbins())
    ks = data.KolmogorovTest(funct_histo)
 #   print(ks)
    chi2 = 0
    nbins = 0
    for i in range(1,rat.GetNbinsX()+1):
        if rat.GetBinLowEdge(i+1)<chi2_maxRange:
            val = rat.GetBinContent(i)
            chi2 += val*val
            nbins += 1

    fuction_ndof = 0
    for word in reversed(folder.split("/")[-1].lower().split("_")):
        if "alt" in word or "nom" in word:
            fuction_ndof = int(word[-1])
            break
    
    if fuction_ndof == 0:
        for word in reversed(folder.split("/")[-2].lower().split("_")):
            if "alt" in word or "nom" in word:
                fuction_ndof = int(word[-1])
                break

#        print(nbins)
#        print(word)
#        print(fuction_ndof)
#        print(fileName)
#        print(chi2)
    prob = ROOT.TMath.Prob(chi2, nbins - fuction_ndof)
#    print(isrPt,rang, ROOT.TMath.Prob(chi2, nbins - fuction_ndof), ks)
    file_.Close()
    return ks
#    return min(ks,prob)


def print_chi2_profile(folder):  
#    if "5GeV" in folder: massBins_list = range(100,3000,5)
#    elif "10GeV" in folder: massBins_list = range(100,3000,10)

    global rang_bin
    if "10GeV" in folder: rang_bin = 10
    elif "5GeV" in folder: rang_bin = 5

    isrPts = range(isrPt_min,isrPt_max+1, isrPt_bin)
    rangs  = range(rang_min,rang_max+1, rang_bin)

#    print(isrPts)
#    print(rangs)
    chi2_profile = ROOT.TH2F("chi2_profile","", len(isrPts)-1 ,array.array('f',isrPts) , len(rangs)-1 , array.array('f',rangs))

    for i, isrPt in enumerate(isrPts[:-1]):
        chi2_profile.GetXaxis().SetBinLabel(i+1, "p_{T,ISR} > %d"%isrPt)

    for i, rang in enumerate(rangs[:-1]):
        chi2_profile.GetYaxis().SetBinLabel(i+1, "%d < m_{jj} < 1000"%rang)

#    print(isrPts)
#    print(rangs)
    max_isr = [0]*len(isrPts)
    
    for i in range(chi2_profile.GetNbinsX()):
        for j in range(chi2_profile.GetNbinsY()):
            try:
                val = chi2Probability(folder, isrPts[i], rangs[j])
#                print("chi2Probability(%s, %d, %d) = %f"%(folder, isrPts[i], rangs[j],val))
            except:
                print("ERROR: chi2Probability(%s, %d, %d)"%(folder, isrPts[i], rangs[j]))
                val = 999999
            chi2_profile.SetBinContent(i+1,j+1,val*100)
            max_isr[i] = max(max_isr[i], val*100)

#    for i in range(chi2_profile.GetNbinsX()):
#        for j in range(chi2_profile.GetNbinsY()):
#            if max_isr[i]>0.05:
#                    chi2_profile.SetBinContent(i+1,j+1,chi2_profile.GetBinContent(i+1,j+1)/max_isr[i] * 100 )

    chi2_profile.SetMinimum(-1E-9)
    chi2_profile.SetMaximum(10)
    chi2_profile.SetMaximum(50)
#    chi2_profile.SetMaximum(100)
    chi2_profile.GetXaxis().SetTitleOffset(1.4)
    chi2_profile.GetYaxis().SetTitleOffset(1.6)
    chi2_profile.GetXaxis().LabelsOption("u")
    chi2_profile.GetXaxis().SetLabelOffset(0.007)
#    if "isrPt" in fileIn: chi2_profile.SetMaximum(0.5)
    c1.cd()
    chi2_profile.Draw("COLZ,TEXT")
    #chi2_profile
    c1.Modified()
    c1.Update()
    nameF = folder.split("/")[-2]+folder.split("/")[-1].replace("_isrpt%d_minBin%d","")
    chi2_profile.Draw("COLZ,TEXT")
    nameF = nameF.replace(".","p")
    c1.SaveAs(nameF+".C")
    c1.SaveAs(nameF+".png")
    c1.SaveAs(nameF+".pdf")
    c1.SaveAs(nameF+".root")
    return chi2_profile



#chi2_profile = print_chi2_profile("chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percents_newmethod_cr_0")
#chi2_profile = print_chi2_profile("chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percents_newmethod_sr_0")
#chi2_profile = print_chi2_profile("chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percents_newmethod_cr_2")
#chi2_profile = print_chi2_profile("chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percents_newmethod_sr_2")

#chi2_profile = print_chi2_profile("chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percents_newmethod_sr_1")
#chi2_profile = print_chi2_profile("chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percents_newmethod_sr_8")

#chi2_profile = print_chi2_profile("chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percents_newmethod_cr_5")
#chi2_profile = print_chi2_profile("chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percents_newmethod_cr_6")
#chi2_profile = print_chi2_profile("chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percents_newmethod_cr_7")

'''
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_0_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_1_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_2_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_3_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_4_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_5_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_6_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_7_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_8_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_sr/Alt5_mjjBinning5_isrpt%d_minBin%d_9_batch")

chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_0_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_1_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_2_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_3_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_4_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_5_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_6_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_7_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_8_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_10pers_newmethod_cr/Alt5_mjjBinning5_isrpt%d_minBin%d_9_batch")

chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_0_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_1_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_2_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_3_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_4_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_5_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_6_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_7_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_8_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_9_batch")

chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_0_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_1_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_2_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_3_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_4_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_5_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_6_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_7_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_8_batch")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_cr2/Alt5_mjjBinning5_isrpt%d_minBin%d_9_batch")
'''

#chi2_profile = print_chi2_profile("/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/chi2_studies_test_sig_cr_inj_0/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/chi2_studies_test_sig_cr_inj_300/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/chi2_studies_test_sig_cr_inj_400/Nom4_mjjBinning5_isrpt%d_minBin%d")

#chi2_profile = print_chi2_profile("/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/chi2_studies_test_sig_inj_0/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/chi2_studies_test_sig_inj_300/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/chi2_studies_test_sig_inj_400/Nom4_mjjBinning5_isrpt%d_minBin%d")

#chi2_profile = print_chi2_profile("/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/chi2_studies_test_cr_sig_inj_0/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/chi2_studies_test_cr_sig_inj_300/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/chi2_studies_test_cr_sig_inj_400/Nom4_mjjBinning5_isrpt%d_minBin%d")



#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta/Nom5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta/Nom6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta/Nom7_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta/Alt4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta/Alt5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta/Alt6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta/Alt7_mjjBinning5_isrpt%d_minBin%d")


#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_alt3_isrPt_5GeVBinning10percent_newmethod_sr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_alt4_isrPt_5GeVBinning10percent_newmethod_sr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percent_newmethod_sr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_alt6_isrPt_5GeVBinning10percent_newmethod_sr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_nom3_isrPt_5GeVBinning10percent_newmethod_sr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_nom4_isrPt_5GeVBinning10percent_newmethod_sr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_nom5_isrPt_5GeVBinning10percent_newmethod_sr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_nom6_isrPt_5GeVBinning10percent_newmethod_sr_060419")

#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_alt3_isrPt_5GeVBinning10percent_newmethod_cr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_alt4_isrPt_5GeVBinning10percent_newmethod_cr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_alt5_isrPt_5GeVBinning10percent_newmethod_cr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_alt6_isrPt_5GeVBinning10percent_newmethod_cr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_nom3_isrPt_5GeVBinning10percent_newmethod_cr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_nom4_isrPt_5GeVBinning10percent_newmethod_cr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_nom5_isrPt_5GeVBinning10percent_newmethod_cr_060419")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/chi2_studies_deta1.1_nom6_isrPt_5GeVBinning10percent_newmethod_cr_060419/")

#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta_4thpart_10percent/Nom5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta_4thpart_10percent/Nom6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta_4thpart_10percent/Nom7_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta_4thpart_10percent/Alt4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta_4thpart_10percent/Alt5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta_4thpart_10percent/Alt6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_flippedEta_4thpart_10percent/Alt7_mjjBinning5_isrpt%d_minBin%d")


#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_SR_4thpart_10percent/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_SR_4thpart_10percent/Nom5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_SR_4thpart_10percent/Nom6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_SR_4thpart_10percent/Nom7_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_SR_4thpart_10percent/Alt4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_SR_4thpart_10percent/Alt5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_SR_4thpart_10percent/Alt6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fitOutput_deta1.1_SR_4thpart_10percent/Alt7_mjjBinning5_isrpt%d_minBin%d")


#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0part_woH/Nom6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0part_woH/Nom5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0part_woH/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0part_woH/Alt6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0part_woH/Alt5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0part_woH/Alt4_mjjBinning5_isrpt%d_minBin%d")

#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0part_woH/Nom6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0part_woH/Nom5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0part_woH/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0part_woH/Alt6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0part_woH/Alt5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0part_woH/Alt4_mjjBinning5_isrpt%d_minBin%d")

#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0thpart/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0thpart/Nom5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0thpart/Nom6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0thpart/Alt4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0thpart/Alt5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_SR_10percent_0thpart/Alt6_mjjBinning5_isrpt%d_minBin%d")

#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0thpart/Nom4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0thpart/Nom5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0thpart/Nom6_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0thpart/Alt4_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0thpart/Alt5_mjjBinning5_isrpt%d_minBin%d")
#chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_10percent_0thpart/Alt6_mjjBinning5_isrpt%d_minBin%d")


chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_fullData/Nom4_mjjBinning5_isrpt%d_minBin%d")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_fullData/Nom5_mjjBinning5_isrpt%d_minBin%d")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_fullData/Nom6_mjjBinning5_isrpt%d_minBin%d")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_fullData/Alt4_mjjBinning5_isrpt%d_minBin%d")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_fullData/Alt5_mjjBinning5_isrpt%d_minBin%d")
chi2_profile = print_chi2_profile("/work/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer_silvio/scan_fits_flippedEta_fullData/Alt6_mjjBinning5_isrpt%d_minBin%d")

chi2_profile.Draw("COLZ,TEXT")
