import ROOT
import copy

ROOT.gROOT.SetBatch(0)

mass = 600

wj = 1.1

#wjs = [round(x/10.,1) for x in range(4,19,1)]

#detas = [round(x/10.,1) for x in range(4,28,1)]
detas = [1.1]

masses = [
    300, 400, 500, 600
]

#masses = [
#    mass
#]

selection = "isr_pt>50 && HLT_CaloScoutingHT250 && abs(dijet_deta)<%f "
variable = "abs(TVector2::Phi_mpi_pi(jet1_phi-jet2_phi))"
binning = "(64,0,3.1415)"

dataFileName = "../data_ntuple_CR_studies.root"
signalFileName = "mc_signal_%s.root"
#dataFileName = "/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/data_wj_studies/data_wj_studies_%sdata.root"
#signalFileName = "/mnt/t3nfs01/data01/shome/sdonato/scoutingNew/copy/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/wideJetMC/signal_%s_wj%s.root"

###################################

ROOT.gStyle.SetOptStat(0)

c1 = ROOT.TCanvas("c1","",1280,720)
c1.SetLogy(0)
c1.SetGridx()
c1.SetGridy()

colors = [
ROOT.kRed +3,
ROOT.kRed +1,
ROOT.kRed -4,
ROOT.kRed -7,
ROOT.kRed -9,
ROOT.kGreen +3,
ROOT.kGreen +1,
ROOT.kGreen -4,
ROOT.kGreen -7,
ROOT.kGreen -9,
ROOT.kBlue +3,
ROOT.kBlue +1,
ROOT.kBlue -4,
ROOT.kBlue -7,
ROOT.kBlue -9,
ROOT.kRed +3,
ROOT.kRed +1,
ROOT.kRed -4,
ROOT.kRed -7,
ROOT.kRed -9,
ROOT.kGreen +3,
ROOT.kGreen +1,
ROOT.kGreen -4,
ROOT.kGreen -7,
ROOT.kGreen -9,
ROOT.kBlue +3,
ROOT.kBlue +1,
ROOT.kBlue -4,
ROOT.kBlue -7,
ROOT.kBlue -9,
]


def getHisto(fileName, sel = selection):
    file_ = ROOT.TFile.Open(fileName)
    tree = file_.Get("tree")
    if not type(tree)==ROOT.TTree:
        tree = file_.Get("rootTupleTree/tree")
    tree.Draw(variable + ">> histo"+binning, sel%deta)
    print(sel%deta)
    histo = file_.Get("histo").Clone(fileName.replace("/",""))
    histo.SetLineWidth(2)
    return copy.copy(histo)

def getBestSsqrtB(dat,sig):
    s_sqrtB_max = 0
    for i in range(mass-100,mass,10):
        bin_min = sig.FindBin(i)
        for j in range(mass,mass+300,10):
            bin_max = sig.FindBin(j)
            s = 1.*sig.Integral(bin_min, bin_max)
            b = 1.*dat.Integral(bin_min, bin_max)
            s_sqrtB = s/(b**0.5)
            if s_sqrtB>s_sqrtB_max:
                s_sqrtB_max = s_sqrtB
                minBin = dat.GetBinLowEdge(bin_min)
                maxBin = dat.GetBinLowEdge(bin_max+1)
    #            print(i,j,s,b,s_sqrtB_max)
    return s_sqrtB_max,minBin,maxBin

def getSsqrtB(dat,sig, mass):
    bin_min = sig.FindBin(mass*0.98)
    bin_max = sig.FindBin(mass*1.02)
    s = 1.*sig.Integral(bin_min, bin_max)
    b = 1.*dat.Integral(bin_min, bin_max)
    s_sqrtB_max = s/(b**0.5)
    minBin = dat.GetBinLowEdge(bin_min)
    maxBin = dat.GetBinLowEdge(bin_max+1)
    return s_sqrtB_max,minBin,maxBin


data = {}
signal = {}
signalGoodMatch = {}
for deta in detas:
    data[deta] = getHisto(dataFileName)
    for mass in masses:
        signal[(deta,mass)] = getHisto(signalFileName%(mass))
        signalGoodMatch[(deta,mass)] = getHisto(signalFileName%(mass), selection + " && (sqrt(TVector2::Phi_mpi_pi(jet1_phi-jet1MC_phi)**2 + (jet1_eta-jet1MC_eta)**2)<0.4 && sqrt(TVector2::Phi_mpi_pi(jet2_phi-jet2MC_phi)**2 + (jet2_eta-jet2MC_eta)**2)<0.4) ")
    print(data[deta])

print(data)
print(signal)

## rescale to show plots nicer
for mass in masses:
    scale = data[detas[0]].Integral() / signalGoodMatch[(detas[0],mass)].Integral()
#    scale = 10. * data[deta].GetBinContent(bin_) / signal.values()[0].GetBinContent(bin_)
    for deta in detas:
        signal[(deta,mass)].Scale(scale)
        signalGoodMatch[(deta,mass)].Scale(scale)

signif = {}
signif_max = {}

for matching in [True,False]:
    if matching:
        signals = signal
    else:
        signals = signalGoodMatch
    for mass in masses:
        leg = ROOT.TLegend(0.78,0.58,0.98,0.98)
        leg.SetHeader("")
        print("M(jj) = %s GeV. Matching %s"%(mass,matching))
        signif_max[(mass,matching)] = 0
        for i,deta in enumerate(detas):
            data[deta].SetLineColor(ROOT.kBlack)
            signals[(deta,mass)].SetLineColor(ROOT.kRed)
            if i==0:
                signals[(deta,mass)].SetTitle("M(X) = %s GeV"%mass)
                signals[(deta,mass)].GetYaxis().SetTitle("Events")
                signals[(deta,mass)].GetXaxis().SetTitle("m_{jj} [GeV]")
#                signals[(deta,mass)].GetYaxis().SetRangeUser(1E1,1E7)
                signals[(deta,mass)].Draw("")
            else:
                signals[(deta,mass)].Draw("same")
                
            data[deta].Draw("same")
            leg.AddEntry(data[deta],"#Delta #eta (jj) = %s"%deta)
        #    SsqrtB,minBin,maxBin = getBestSsqrtB(data[wj],signalGoodMatch[(wj,mass)])
        #    print("wide jet R=%s, S/sqrt(B)=%s, in mjj=[%s,%s]"%(wj,SsqrtB,minBin,maxBin))
            SsqrtB,minBin,maxBin = getSsqrtB(data[deta],signals[(deta,mass)],mass)
            print("wide jet R=%s, S/sqrt(B)=%s, in mjj=[%s,%s]"%(deta,SsqrtB,minBin,maxBin))
            signif[(deta,mass,matching)] = SsqrtB
            signif_max[(mass,matching)] = max(signif_max[(mass,matching)], SsqrtB)
#        leg.Draw()

        c1.Update()
        c1.Modified()
        if matching:
            c1.SaveAs("plots_dphi_%s_matching.png"%mass)
        else:
            c1.SaveAs("plots_dphi_%s.png"%mass)

#data[wj].Scale(1./data[wj].Integral())
#signal[(wj,mass)].Scale(1./signal[(wj,mass)].Integral())
#signalGoodMatch[(wj,mass)].Scale(1./signalGoodMatch[(wj,mass)].Integral())

#data[wj].Draw()
#signal[(wj,mass)].Draw("same")
#signalGoodMatch[(wj,mass)].Draw("same")


#sig = signalGoodMatch[(deta,mass)]
#dat = data[deta]

c1.SetLogy(0)

'''
grs = {}
for matching in [True,False]:
    for mass in sorted(masses):
        grs[mass] = ROOT.TGraphErrors()
        grs[mass].SetLineWidth(2)
        grs[mass].SetLineColor(colors[masses.index(mass)])
        grs[mass].SetMarkerColor(colors[masses.index(mass)])
        grs[mass].SetMarkerSize(0)
        grs[mass].SetMarkerStyle(21)
        for i,deta in enumerate(detas):
            grs[mass].SetPoint(i,deta, signif[(deta,mass,matching)]/ signif_max[(mass,matching)])
            grs[mass].SetPointError(i,0,0)


for matching in [True,False]:
    leg = ROOT.TLegend(0.78,0.58,0.98,0.98)
    for mass in sorted(masses):
        grs[mass].GetXaxis().SetTitle(" #Delta#phi (jj)")
        grs[mass].GetYaxis().SetTitle("Normalized S/sqrt(B)")
        grs[mass].SetTitle("Significance vs #Delta #phi (jj) cut")
        ax = grs[mass].GetXaxis()
        ax.SetLimits(ax.GetXmin(),ax.GetXmin() + (ax.GetXmax()-ax.GetXmin())*1.2 )
        leg.AddEntry(grs[mass],"%s GeV"%mass,"lep")
        if masses.index(mass)==0:
            grs[mass].Draw("ALP")
        else:
            grs[mass].Draw("LP")
    leg.Draw()
    c1.Update()
    c1.Modified()
    if matching:
        c1.SaveAs("plots_dphi_sig_matching.png")
    else:
        c1.SaveAs("plots_dphi_sig.png")
'''