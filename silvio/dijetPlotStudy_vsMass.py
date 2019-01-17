import ROOT

title = "Dijet matching efficiency vs mass"
colors = [
ROOT.kBlack,

ROOT.kRed,
ROOT.kBlue,
ROOT.kMagenta,
ROOT.kCyan+1,
ROOT.kGreen+2,
ROOT.kYellow+1,

ROOT.kGray+2,

ROOT.kViolet,
ROOT.kAzure,
ROOT.kTeal,
ROOT.kSpring,

ROOT.kOrange,
ROOT.kPink,

ROOT.kRed+1,
ROOT.kBlue+1,
ROOT.kMagenta+1,
ROOT.kCyan+2,
ROOT.kGreen+3,
ROOT.kYellow+4,

ROOT.kGray+3,

ROOT.kViolet+2,
ROOT.kAzure+2,
ROOT.kTeal+2,
ROOT.kSpring+2,

ROOT.kOrange+2,
ROOT.kPink+2,

ROOT.kRed+2,
ROOT.kBlue+2,
ROOT.kMagenta+2,
ROOT.kCyan+3,
ROOT.kGreen+4,
ROOT.kYellow+5,

ROOT.kGray+4,

ROOT.kViolet+2,
ROOT.kAzure+2,
ROOT.kTeal+2,
ROOT.kSpring+2,

ROOT.kOrange+2,
ROOT.kPink+2,

ROOT.kRed+3,
ROOT.kBlue+3,
ROOT.kMagenta+3,
ROOT.kCyan+4,
ROOT.kGreen+5,
ROOT.kYellow+6,

ROOT.kGray+5,

ROOT.kViolet+3,
ROOT.kAzure+3,
ROOT.kTeal+3,
ROOT.kSpring+3,

ROOT.kOrange+3,
ROOT.kPink+3,

]


# ROOT.gROOT.SetBatch(0)
# canv2 = ROOT.TCanvas()

#preselection = "(HTgoodJets>300) && nJet>=3"
preselection = "HTgoodJets>0"
preselection =  " run<=280385 && abs(jet1_eta)<2.5 && abs(jet2_eta)<2.5 && abs(isr_eta)<2.5 && abs(dijetMC_deta)<1.1 && HLT_CaloScoutingHT250 && HTgoodJets>0 && isr_pt>=70 && jet1_pt>=70 && jet2_pt>=70" #&& 
mcReco_matching = "mcReco_matching"

#xvar, xbins, xmin, xmax, xtitle = "dijetMC_pt", 50,0, 500, "p^{T}_{jj,gen} (GeV)"
#xvar, xbins, xmin, xmax, xtitle = "HTgoodJets", 100,0, 1000, "HT [GeV]"
xvar, xbins, xmin, xmax, xtitle = "min(isr_pt,jet2_pt)", 50,0, 500, "p^{T}_{3} (GeV)"

ROOT.gStyle.SetOptStat(0)
#ROOT.gROOT.SetBatch(1)
#canv = ROOT.TCanvas("canv","",1280,720)
canv = ROOT.TCanvas("canv","",720,480)
canv.SetGridx()
canv.SetGridy()

folder = "../jetPairing3MC/"
fileNames = [
#    "../output/test_reduced_skim_new.root",
   folder + "signal_jets12_200.root",
   folder + "signal_jets12_300.root",
   folder + "signal_jets12_400.root",
   folder + "signal_jets12_500.root",
   folder + "signal_jets12_600.root",
   folder + "signal_jets12_800.root",
   folder + "signal_jets12_1000.root",
]


#fileNames = [
#    "../output/test_reduced_skim.root",
#    "../output_20171220_103246/rootfile_list_VectorDiJet1Jet_125_13TeV_TEST_20171220_093230_0_reduced_skim.root"
#]


methods = [
    "mc",

    "dijetP_CM",
    "jets01",
    "jets02",
    "jets12",
    "dijetDR",
]


eff = {}
eff_err = {}

masses = set()

def fillEfficiency(fileName):
    try:
        mass = fileName.replace(".root","").split("_")[-1]
    except:
        mass = "XXX"
        pass
    mass = float(mass.split("_")[0])
    masses.add(mass)
    name = fileName.replace(".root","")
    name = name.replace("test_reduced_skim_","")
    file_ = ROOT.TFile(fileName)
    tree = file_.Get("rootTupleTree/tree")
    if type(tree) != ROOT.TTree: 
        print("WARNING: skipping %s"%fileName)
        return
    denInt = tree.Draw("", preselection )
    for method in methods:
        var = "method_"+method
        var = "mcReco_matching && " + var
        if method == "mc":
                var = "mcReco_matching"
        numInt = tree.Draw("", preselection + "&&" + var)
        e = 1.*numInt / denInt
        eff[(method,mass)] = e
        eff_err[(method,mass)] = (e*(1.-e)/denInt)**0.5
        print((numInt, denInt, eff, eff_err))
        print("numInt = %f, denInt = %f, eff = %f, eff_err = %f"%(numInt, denInt, eff[(method,mass)], eff_err[(method,mass)]))
    file_.Close()

for fileName in fileNames:
    fillEfficiency(fileName)


masses  = sorted(masses)

grs = {}

leg = ROOT.TLegend(0.9,0.1,0.999,0.9)
leg.SetHeader("Matching")

for method in methods:
    grs[method] = ROOT.TGraphErrors()
    grs[method].SetLineWidth(2)
    grs[method].SetLineColor(colors[methods.index(method)])
    grs[method].SetMarkerColor(colors[methods.index(method)])
    grs[method].SetMarkerSize(0)
    grs[method].SetMarkerStyle(21)
    leg.AddEntry(grs[method],"%s"%method,"lep")
    for i,mass in enumerate(masses):
        grs[method].SetPoint(i,mass, eff[(method,mass)])
        grs[method].SetPointError(i,0,eff_err[(method,mass)])

for method in methods:
    grs[method].GetXaxis().SetTitle("Resonance mass [GeV]")
    grs[method].GetYaxis().SetTitle("Efficiency")
    grs[method].SetTitle("Matching efficiency vs resonance mass")
    grs[method].SetMaximum(1)
    grs[method].SetMinimum(0)
    if methods.index(method) == 0:
        grs[method].Draw("ALP")
    else:
        grs[method].Draw("LP")

leg.Draw();
canv.SaveAs("dijetPlotStudy_vsMass.png")
canv.SaveAs("dijetPlotStudy_vsMass.pdf")
