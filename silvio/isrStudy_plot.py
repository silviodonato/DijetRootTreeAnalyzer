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

bins = range(50,101,5)

ROOT.gStyle.SetOptStat(0)

#fileName = "../inputs_Silvio/data_RunH_ntuple_long.root"
#fileName = "../inputs_Silvio/test_ntuple.root"
#fileName = "../data_ntuple_full_study_10perc.root"
fileName = "../data_ntuple_full_study.root"


#fileName = "../ntupleSignal/VectorDiJet1Jet_150_13TeV.root"
denTrigger = "abs(dijet_deta)<=1.1 && HLT_CaloScoutingHT250 && L1_HTT240"

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
varX_nbins,   varX_min,  varX_max = 160,100,500
#varX_nbins,   varX_min,  varX_max = 1000,60,1050
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
tree.Draw("dijet_eta >> isrpt(100,0,%f)"%dijet_eta_max,"%s && dijet_mass>300"%(preselect) ,"")
isrpt = ROOT.gDirectory.Get("isrpt")
isrpt.Draw("HIST")

x = array.array('d',[i*1./N for i in range(N)])
y = array.array('d',[0 for i in range(N)])
isrpt.GetQuantiles(N,y,x)
#bins = list(y)
#funct = ROOT.TF1("funct","pol4",0,3)
#isrpt.Fit(funct)
#funct.Draw("same")

#canv.SaveAs("histoMjj.root")

c2 = ROOT.TCanvas("c2","")
#c2.SetLogz()

g = ROOT.TGraph2D()
chi2 = {}
max_ = 0
histos=[]
for i in range(len(bins)-1):
    preselect = denTrigger + "&& isr_pt>%f && isr_pt<%f"%(bins[i],bins[i+1]) #
    tree.Draw("%s >> histo(%f,%f,%f)"%(varX,varX_nbins,varX_min,varX_max),"%s"%(preselect) ,"")
    histo = ROOT.gDirectory.Get("histo")
    histos.append(histo.Clone("%s < p_{T,3} < %s"%((round(bins[i],2)),round(bins[i+1],2))))
    max_ = max(max_, histo.GetMaximum())


leg = ROOT.TLegend(0.52,0.4,0.9,0.9)
#leg.SetHeader("")

for i,histo in enumerate(histos):
    histo.SetTitle("")
    histo.GetXaxis().SetTitle("m(jj)")
    histo.GetYaxis().SetTitle("AU")
    histo.Sumw2()
    histo.Scale(1./histo.Integral(histo.FindBin(300),varX_nbins))
    leg.AddEntry(histo,histo.GetName(),"l") 
    histo.SetLineColor(colors[i])
    histo.SetLineWidth(2)
    histo.SetMinimum(0)
    histo.SetMaximum(0.1)
    if i==0:
        histo.Draw("ERR")
        histo.Draw("HIST,C,same")
    else:
        histo.Draw("ERR,same")
        histo.Draw("HIST,C,same")



c2.SetGridx(1)
c2.SetGridy(1)
c2.SetLogy(0)
leg.Draw()
c2.SaveAs("isrptplot.png")
c2.SaveAs("isrptplot.pdf")
#g.Draw("LEGO")c2.SaveAs("plotisrpt.png")
