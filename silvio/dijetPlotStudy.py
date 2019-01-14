import ROOT

title = "Dijet matching efficiency for M = XXX GeV "
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
ROOT.gROOT.SetBatch(1)
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
def getHisto(tree, sel):
    #print("%s >> histo(%d, %d, %d)"%(xvar,xbins,xmin,xmax), sel)
    tree.Draw("%s >> histo(%d, %d, %d)"%(xvar,xbins,xmin,xmax), sel)
    histo = ROOT.gDirectory.Get("histo")
    return histo

def getHistos(fileName):
    leg = ROOT.TLegend(0.9,0.1,0.999,0.9)
    leg.SetHeader("Matching")
    try:
        mass = fileName.replace(".root","").split("_")[-1]
    except:
        mass = "XXX"
        pass
    mass = mass.split("_")[0]
    name = fileName.replace(".root","")
    name = name.replace("test_reduced_skim_","")
    file_ = ROOT.TFile(fileName)
    tree = file_.Get("rootTupleTree/tree")
    if type(tree) != ROOT.TTree: 
        print("WARNING: skipping %s"%fileName)
        return
    den = getHisto(tree, preselection)
    den = den.Clone("den")
    denInt = den.Integral()
    for method in methods:
        var = "method_"+method
        var = "mcReco_matching && " + var
        if method == "mc":
                var = "mcReco_matching"
        num = getHisto(tree, preselection + "&&" + var)
        num = num.Clone(method)
        eff[method] = ROOT.TGraphAsymmErrors()
        eff[method].SetName("eff_"+method)
        eff[method].Divide(num,den)
        eff[method].SetLineWidth(2)
        eff[method].SetLineColor(colors[methods.index(method)])
        eff[method].SetMarkerColor(colors[methods.index(method)])
        print(method+": "+str(num.Integral()*1./denInt))
        leg.AddEntry(eff[method],"#splitline{%s}{(%.1f %s)}"%(method,100.*num.Integral()*1./denInt,"%"),"lep")
    den.Scale(0.9/den.GetMaximum())
    den.GetXaxis().SetTitle(xtitle)
    den.GetYaxis().SetTitle("Efficiency")
    den.SetTitle(title.replace("XXX",mass))
    den.SetLineColor(ROOT.kGray+1)
    den.SetFillColor(ROOT.kGray)
    den.SetMaximum(1)
    den.SetMinimum(0)
    den.Draw("HIST")
    for method in reversed(methods):
       if methods.index(method) == 0:
            eff[method].Draw("LP")
       else:
            eff[method].Draw("LP")
    leg.Draw();
    canv.SaveAs(fileName.replace(".root",".png"))
    canv.SaveAs(fileName.replace(".root",".pdf"))
    file_.Close()

for fileName in fileNames:
    getHistos(fileName)
