import ROOT

ROOT.gStyle.SetPaintTextFormat(".3f")

massBins_list = [1, 3, 6, 10, 16, 23, 31, 40, 50, 61, 74, 88, 103, 119, 137, 156, 176, 197, 220, 244, 270, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000, 1058, 1118, 1181, 1246, 1313, 1383, 1455, 1530, 1607, 1687, 1770, 1856, 1945, 2037, 2132, 2231, 2332, 2438, 2546, 2659, 2775, 2895, 3019, 3147, 3279, 3416, 3558, 3704, 3854, 4010, 4171, 4337, 4509, 4686, 4869, 5058, 5253, 5455, 5663, 5877, 6099, 6328, 6564, 6808, 7060, 7320, 7589, 7866, 8152, 8447, 8752, 9067, 9391, 9726, 10072, 10430, 10798, 11179, 11571, 11977, 12395, 12827, 13272, 13732, 14000]

ROOT.gROOT.SetBatch(1)
ROOT.gStyle.SetOptStat(0)

c1 = ROOT.TCanvas("c1","")
c1.SetLeftMargin(0.13)
c1.SetBottomMargin(0.13)

def print_chi2_profile(fileIn):  
    if "5GeV" in fileIn: massBins_list = range(100,3000,5)
    elif "10GeV" in fileIn: massBins_list = range(100,3000,10)

    f1 = ROOT.TFile.Open(fileIn)
    chi2_profile = f1.Get("chi2_profile")
    chi2_profile.GetXaxis().LabelsOption("v")

    ndof = fileIn.split("/")[-1]
    ndof = ndof.split("_")[1]
    ndof = ndof.replace("Alt","")
    ndof = ndof.replace("Nom","")
    ndof = int(ndof)

    ax = chi2_profile.GetXaxis()
    ay = chi2_profile.GetYaxis()

    for i in range(chi2_profile.GetNbinsX()+2):
        for j in range(chi2_profile.GetNbinsY()+2):
            val = chi2_profile.GetBinContent(i,j)
#            val = min(val,100)
#            val = max(val,0.1)
            chi2_profile.SetBinContent(i,j,val)
            if True:
#            if "isrPt" in fileIn:
                lx = ax.GetBinLabel(i)
                lx = lx.replace(" ","")
                ly = ay.GetBinLabel(j)
                try:
                    ly_min, ly_max = int(ly.split("<")[0]), int(ly.split("<")[2])
                    nbins = massBins_list.index(ly_max) -  massBins_list.index(ly_min)
                    print(lx,ly_min,ly_max,nbins)
                    val = val * (nbins - 4)
                    val = ROOT.TMath.Prob(val, nbins - ndof)
                    val = max(val,1E-6)
                except:
                    pass
            print val
            chi2_profile.SetBinContent(i,j,val)

    chi2_profile.SetMinimum(-1E-9)
    chi2_profile.SetMaximum(10)
    chi2_profile.SetMaximum(0.5)
#    if "isrPt" in fileIn: chi2_profile.SetMaximum(0.5)
    chi2_profile.Draw("COLZ,TEXT")
    chi2_profile
    c1.SaveAs(fileIn.replace(".root",".pdf"))
    c1.SaveAs(fileIn.replace(".root",".png"))
    f1.Close()

'''
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Alt4_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Alt4_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Alt4_studies_deta1p1_full_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Alt4_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Alt4_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Alt4_studies_deta1p1_full_blind.root")

print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Alt3_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Alt3_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Alt3_studies_deta1p1_full_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Alt3_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Alt3_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Alt3_studies_deta1p1_full_blind.root")

print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Alt5_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Alt5_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Alt5_studies_deta1p1_full_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Alt5_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Alt5_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Alt5_studies_deta1p1_full_blind.root")

#############################################

print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Nom4_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Nom4_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Nom4_studies_deta1p1_full_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Nom4_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Nom4_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Nom4_studies_deta1p1_full_blind.root")

print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Nom3_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Nom3_studies_deta1p1_full_ten_percent.root")
#print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Nom3_studies_deta1p1_full_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Nom3_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Nom3_studies_deta1p1_full_ten_percent.root")
#print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Nom3_studies_deta1p1_full_blind.root")

print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Nom5_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Nom5_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/trigger_Nom5_studies_deta1p1_full_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Nom5_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Nom5_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPt_Nom5_studies_deta1p1_full_blind.root")

print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPtCheck_Alt6_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPtCheck_Alt6_studies_deta1p1_full_ten_percent_blind.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPtCheck_Nom6_studies_deta1p1_full_ten_percent.root")
print_chi2_profile("/mnt/t3nfs01/data01/shome/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/isrPtCheck_Nom6_studies_deta1p1_full_ten_percent_blind.root")
'''

print_chi2_profile("chi2th2fAllFunctions5GeVBinning/isrPt_Nom4_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning/isrPt_Alt5_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning/isrPt_Nom5_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning/isrPt_Alt4_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning/isrPt_Nom3_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning/isrPt_Alt6_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning/isrPt_Nom6_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning/isrPt_Alt3_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning10percent_detacut/isrPt_Nom3_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning10percent_detacut/isrPt_Nom6_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning10percent_detacut/isrPt_Nom5_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning10percent_detacut/isrPt_Nom4_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning10percent_detacut/isrPt_Alt3_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning10percent_detacut/isrPt_Alt5_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning10percent_detacut/isrPt_Alt4_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinning10percent_detacut/isrPt_Alt6_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinningfull_detacut/isrPt_Alt6_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinningfull_detacut/isrPt_Alt4_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinningfull_detacut/isrPt_Alt5_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinningfull_detacut/isrPt_Alt3_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinningfull_detacut/isrPt_Nom4_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinningfull_detacut/isrPt_Nom5_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinningfull_detacut/isrPt_Nom6_studies.root")
print_chi2_profile("chi2th2fAllFunctions5GeVBinningfull_detacut/isrPt_Nom3_studies.root")

print_chi2_profile("chi2th2fAllFunctions10GeVBinning/isrPt_Nom4_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning/isrPt_Alt5_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning/isrPt_Nom5_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning/isrPt_Alt4_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning/isrPt_Nom3_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning/isrPt_Alt6_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning/isrPt_Nom6_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning/isrPt_Alt3_studies_deta1p1_10percent_right_v1.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning10percent_detacut/isrPt_Nom3_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning10percent_detacut/isrPt_Nom6_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning10percent_detacut/isrPt_Nom5_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning10percent_detacut/isrPt_Nom4_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning10percent_detacut/isrPt_Alt3_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning10percent_detacut/isrPt_Alt5_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning10percent_detacut/isrPt_Alt4_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinning10percent_detacut/isrPt_Alt6_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinningfull_detacut/isrPt_Alt6_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinningfull_detacut/isrPt_Alt4_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinningfull_detacut/isrPt_Alt5_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinningfull_detacut/isrPt_Alt3_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinningfull_detacut/isrPt_Nom4_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinningfull_detacut/isrPt_Nom5_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinningfull_detacut/isrPt_Nom6_studies.root")
print_chi2_profile("chi2th2fAllFunctions10GeVBinningfull_detacut/isrPt_Nom3_studies.root")


