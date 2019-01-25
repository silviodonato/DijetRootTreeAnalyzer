import ROOT
import array

redoPlot = True

'''
ROOT.gROOT.SetBatch(0)
canv2 = ROOT.TCanvas()
'''
colors = [
ROOT.kBlack,

ROOT.kRed,
ROOT.kCyan+1,
ROOT.kMagenta,
ROOT.kBlue,
ROOT.kYellow+1,
ROOT.kGreen+1,

ROOT.kOrange,
ROOT.kPink,
ROOT.kViolet,
ROOT.kAzure,
ROOT.kTeal,
ROOT.kSpring,

ROOT.kGray,
] 

bins = [
#    0,
    40,
    50,
    60,
    70,
    80,
    90,
    100,
]

#bins = [
#    0.0,
#    0.9,
#    1.1,
#]

ROOT.gStyle.SetOptStat(0)
#fileName = "/eos/cms/store/group/phys_exotica/dijet/Dijet13TeVScouting/rootTrees_reduced/ScoutingCaloCommissioning_2017-01-18/CommissioningG/rootfile_CaloScoutingCommissioning2016G_JEC_CaloHLT_plus_V10p2_20170119_001201_reduced_skim.root"
#fileName = "rootFile_reduced_skim.root"

#fileName = "ntupleTrigger/L1HTTSkim.root"
#fileName = "/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/rootfile_list_ScoutingCaloCommissioning_Run2016.root"
#fileName = "/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/data_trig_eff_wo_runH_eta2.5.root"
#fileName = "/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/data_strat_unblind.root"
#fileName = "/mnt/t3nfs01/data01/shome/sdonato/scoutingNew/copy/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/silvio/tmp.root"
fileName = "/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/data_wj_studies/data_wj_studies_1.1data.root"


#fileName = "../ntupleSignal/VectorDiJet1Jet_150_13TeV.root"
denTrigger = "abs(dijet_deta)<1.1 && HLT_CaloScoutingHT250 && L1_HTT240"

#fileName = "../CaloScoutingHT250.root"
#denTrigger = "HLT_CaloScoutingHT250"
#denTrigger = "1"

#fileName = "../ntupleTrigger/CaloJet40Skim.root"
#denTrigger = "1"


preselect = denTrigger + "&& 1" #
title = "Di-jet mass plot"

varX = "dijet_mass"
#varX_nbins,   varX_min,  varX_max = 200,100,1100
#varX_nbins,   varX_min,  varX_max = 50,0,1000
varX_nbins,   varX_min,  varX_max = 40,100,500
#varX_nbins,   varX_min,  varX_max = 1000,60,1050
varX_title = "m_{jj}"

fit_min = 320

#######################################################

N = 4
dijet_eta_max = 100
#canv.SetTitle(title)
preselect += "&& (%s < %d)"%(varX,varX_max)

file_ = ROOT.TFile(fileName)
tree = file_.Get("tree")
if not type(tree)==ROOT.TTree:
    tree = file_.Get("rootTupleTree/tree")

tree.Draw("isr_pt >> isrPt(100,0,%f)"%dijet_eta_max,"%s && dijet_mass>300"%(preselect) ,"")
isrPt = ROOT.gDirectory.Get("isrPt")
isrPt.Draw("HIST")


x = array.array('d',[i*1./N for i in range(N)])
y = array.array('d',[0 for i in range(N)])
isrPt.GetQuantiles(N,y,x)
#bins = list(y)
#funct = ROOT.TF1("funct","pol4",0,3)
#isrPt.Fit(funct)
#funct.Draw("same")

#canv.SaveAs("histoMjj.root")

c2 = ROOT.TCanvas("c2","")
#c2.SetLogz()

g = ROOT.TGraph2D()
chi2 = {}
histos=[]
for i in range(len(bins)-1):
    preselect = denTrigger + "&& abs(isr_pt)>%f && abs(isr_pt)<%f"%(bins[i],bins[i+1]) #
    tree.Draw("%s >> histo(%f,%f,%f)"%(varX,varX_nbins,varX_min,varX_max),"%s"%(preselect) ,"")
    print("%s >> histo(%f,%f,%f)"%(varX,varX_nbins,varX_min,varX_max)+",%s"%(preselect) ,"")
    histo = ROOT.gDirectory.Get("histo")
    histos.append(histo.Clone("%s < isr pt (GeV) < %s"%((round(bins[i],2)),round(bins[i+1],2))))


leg = ROOT.TLegend(0.52,0.7,0.9,0.9)
#leg.SetHeader("")

for i,histo in enumerate(histos):
    histo.SetTitle("")
    histo.GetXaxis().SetTitle("m(jj)")
    histo.GetYaxis().SetTitle("AU")
    histo.Sumw2()
    histo.Scale(1./histo.Integral(histo.FindBin(500),varX_nbins))
    leg.AddEntry(histo,histo.GetName(),"l") 
    histo.SetLineColor(colors[i])
    histo.SetLineWidth(2)
    histo.SetMinimum(1E-1)
    if i==0:
        histo.Draw("ERR")
        histo.Draw("HIST,C,same")
    else:
        histo.Draw("ERR,same")
        histo.Draw("HIST,C,same")


c2.SetLogy()
leg.Draw()
c2.SaveAs("isr_pt_plot.png")
c2.SaveAs("isr_pt_plot.pdf")
#g.Draw("LEGO")c2.SaveAs("plotDeta.png")
