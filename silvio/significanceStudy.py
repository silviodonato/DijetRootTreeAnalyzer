import ROOT
import copy

ROOT.gROOT.SetBatch(1)

#mass = 600

wj = 1.1

#wjs = [round(x/10.,1) for x in range(4,19,1)]

'''
varName = "isrPtCut"
varTex = "third jet p_{T} [GeV]"
values = [round(x/1.,1) for x in range(40,100,5)]
#values = [round(x/1.,1) for x in range(40,160,5)]
selection = "isr_pt>%f && HLT_CaloScoutingHT250 && abs(dijet_deta)<1.1 && abs(jet1_eta)<2.5 && abs(jet2_eta)<2.5 && abs(isr_eta)<2.5 && HLT_CaloScoutingHT250" #&& 

'''

varName = "deta"
varTex = "Delta#eta (jj)"
values = [round(x/10.,1) for x in range(4,28,1)]
selection = "isr_pt>70 && HLT_CaloScoutingHT250 && abs(dijet_deta)<%f  && abs(jet1_eta)<2.5 && abs(jet2_eta)<2.5 && abs(isr_eta)<2.5 && HLT_CaloScoutingHT250 "
#'''

varPlot = "dijet_mass"

varTexNoUnits = varTex.replace("[GeV]","")
 
masses = [
    300, 400, 500, 600
]

#masses = [
#    mass
#]

binning = "(200,0,1000)"

dataFileName = "/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/data_wj_studies/data_wj_studies_%sdata.root"
signalFileName = "/mnt/t3nfs01/data01/shome/sdonato/scoutingNew/copy/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/wideJetMC/signal_%s_wj%s.root"

###################################

ROOT.gStyle.SetOptStat(0)

c1 = ROOT.TCanvas("c1","",1280,720)
c1.SetLogy()
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
    tree = file_.Get("rootTupleTree/tree")
    tree.Draw(varPlot + ">> histo"+binning, sel%value)
    print(sel%value)
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
for value in values:
    data[value] = getHisto(dataFileName%wj)
    for mass in masses:
        signal[(value,mass)] = getHisto(signalFileName%(mass,wj))
        signalGoodMatch[(value,mass)] = getHisto(signalFileName%(mass,wj), selection + " && (sqrt(TVector2::Phi_mpi_pi(jet1_phi-jet1MC_phi)**2 + (jet1_eta-jet1MC_eta)**2)<0.4 && sqrt(TVector2::Phi_mpi_pi(jet2_phi-jet2MC_phi)**2 + (jet2_eta-jet2MC_eta)**2)<0.4) ")
    print(data[value])

print(data)
print(signal)

## rescale to show plots nicer
for mass in masses:
    bin_ = data[value].FindBin(mass)
    scale = 10. * data[value].GetBinContent(bin_) / signal[(values[0],mass)].GetBinContent(bin_)
    for value in values:
        signal[(value,mass)].Scale(scale)
        signalGoodMatch[(value,mass)].Scale(scale)


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
        for i,value in enumerate(values):
            data[value].SetLineColor(colors[i])
            signals[(value,mass)].SetLineColor(colors[i])
            if i==0:
                signals[(value,mass)].SetTitle("M(X) = %s GeV"%mass)
                signals[(value,mass)].GetYaxis().SetTitle("Events")
                signals[(value,mass)].GetXaxis().SetTitle("m_{jj} [GeV]")
                signals[(value,mass)].GetYaxis().SetRangeUser(1E1,1E4)
                signals[(value,mass)].Draw("")
            else:
                signals[(value,mass)].Draw("same")
                
            data[value].Draw("same")
            leg.AddEntry(data[value],"%s = %s"%(varTexNoUnits, value))
        #    SsqrtB,minBin,maxBin = getBestSsqrtB(data[wj],signalGoodMatch[(wj,mass)])
        #    print("wide jet R=%s, S/sqrt(B)=%s, in mjj=[%s,%s]"%(wj,SsqrtB,minBin,maxBin))
            SsqrtB,minBin,maxBin = getSsqrtB(data[value],signals[(value,mass)],mass)
            print("wide jet R=%s, S/sqrt(B)=%s, in mjj=[%s,%s]"%(value,SsqrtB,minBin,maxBin))
            signif[(value,mass,matching)] = SsqrtB
            signif_max[(mass,matching)] = max(signif_max[(mass,matching)], SsqrtB)
        leg.Draw()

        c1.Update()
        c1.Modified()
        if matching:
            c1.SaveAs("plots_%s_%s_matching.png"%(varName,mass))
        else:
            c1.SaveAs("plots_%s_%s.png"%(varName,mass))

#data[wj].Scale(1./data[wj].Integral())
#signal[(wj,mass)].Scale(1./signal[(wj,mass)].Integral())
#signalGoodMatch[(wj,mass)].Scale(1./signalGoodMatch[(wj,mass)].Integral())

#data[wj].Draw()
#signal[(wj,mass)].Draw("same")
#signalGoodMatch[(wj,mass)].Draw("same")


#sig = signalGoodMatch[(value,mass)]
#dat = data[value]

c1.SetLogy(0)

grs = {}
for matching in [True,False]:
    for mass in sorted(masses):
        grs[(mass,matching)] = ROOT.TGraphErrors()
        grs[(mass,matching)].SetLineWidth(2)
        grs[(mass,matching)].SetLineColor(colors[masses.index(mass)])
        grs[(mass,matching)].SetMarkerColor(colors[masses.index(mass)])
        grs[(mass,matching)].SetMarkerSize(0)
        grs[(mass,matching)].SetMarkerStyle(21)
        grs[(mass,matching)].SetMinimum(0)
        grs[(mass,matching)].SetMaximum(1.1)
        for i,value in enumerate(values):
            grs[(mass,matching)].SetPoint(i,value, signif[(value,mass,matching)]/ signif_max[(mass,matching)])
            grs[(mass,matching)].SetPointError(i,0,0)


for matching in [True,False]:
    leg = ROOT.TLegend(0.78,0.58,0.98,0.98)
    for mass in sorted(masses):
        grs[(mass,matching)].GetXaxis().SetTitle(" %s"%varTex)
        grs[(mass,matching)].GetYaxis().SetTitle("Normalized S/sqrt(B)")
        grs[(mass,matching)].SetTitle("Significance vs %s cut"%varTexNoUnits)
        ax = grs[(mass,matching)].GetXaxis()
        ax.SetLimits(ax.GetXmin(),ax.GetXmin() + (ax.GetXmax()-ax.GetXmin())*1.2 )
        leg.AddEntry(grs[(mass,matching)],"M = %s GeV"%mass,"lep")
        if masses.index(mass)==0:
            grs[(mass,matching)].Draw("ALP")
        else:
            grs[(mass,matching)].Draw("LP")
    leg.Draw()
    c1.Update()
    c1.Modified()
    if matching:
        c1.SaveAs("plots_%s_sig_matching.png"%varName)
        c1.SaveAs("plots_%s_sig_matching.pdf"%varName)
    else:
        c1.SaveAs("plots_%s_sig.png"%varName)
        c1.SaveAs("plots_%s_sig.pdf"%varName)
