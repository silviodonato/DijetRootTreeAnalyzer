
import ROOT
import array

ROOT.gROOT.SetBatch(1)
normalize_min = 255


#massBoundaries = [i*10 for i in range(1000)]
#massBoundaries = [i for i in range(1000)]
massBoundaries = [255, 270, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838,  890, 944, 1000, 1058, 1118, 1181, 1246, 1313, 1383, 1455, 1530, 1607, 1687, 1770, 1856, 1945, 2037, 2132, 2231, 2332, 2438, 2546, 2659, 2775, 2895, 3019, 3147, 3279, 3416, 3558, 3704, 3854, 4010, 4171, 4337, 4509, 4686, 4869, 5058, 5253, 5455, 5663, 5877, 6099, 6328, 6564, 6808,  7060, 7320, 7589, 7866, 8152, 8447, 8752, 9067, 9391, 9726, 10072, 10430, 10798, 11179, 11571, 11977, 12395, 12827, 13272, 13732, 14000]


xvar, xbins, xmin, xmax, xtitle = "min(isr_pt,jet2_pt)", 1000,255, 1000, ""


def rebin(histo):
    global max_
    oldWidth = 1.* histo.GetBinWidth(1)
    newHisto = ROOT.TH1F("histo", "", len(massBoundaries)-1, array.array('f',massBoundaries))
    for i in range(histo.GetNbinsX()):
        if histo.GetBinCenter(i)>=xmin and histo.GetBinCenter(i)<=xmax:
            newHisto.Fill(histo.GetBinCenter(i), histo.GetBinContent(i))
    for i in range(newHisto.GetNbinsX()):
        newHisto.SetBinError(i, newHisto.GetBinContent(i)**0.5)
        newHisto.SetBinContent(i, newHisto.GetBinContent(i) * oldWidth / newHisto.GetBinWidth(i)  )
        newHisto.SetBinError(i, newHisto.GetBinError(i) * oldWidth / newHisto.GetBinWidth(i)  )
        if i>2 and i<newHisto.GetNbinsX()-3: max_ = max(newHisto.GetBinContent(i),max_)
    return newHisto
    
max_ = 0

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
    
    ratio.SetMaximum(3)
    ratio.SetMinimum(-3)
    print("maxPull=",maxPull)
    return ratio


ROOT.gInterpreter.ProcessLine(".L function.C+")

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


#c1 = ROOT.TCanvas("c1","")


#xvar, xbins, xmin, xmax, xtitle = "min(isr_pt,jet2_pt)", 100,0, 1000, "p^{T}_{3} (GeV)"
ROOT.gStyle.SetOptStat(0)
#ROOT.gROOT.SetBatch(1)
#canv = ROOT.TCanvas("canv","",1280,720)
canv = ROOT.TCanvas("canv","",720,480)
canv.SetGridx()
canv.SetGridy()
canv.SetLogy(1)

#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5.root")
#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim_40.root")
#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim.root")

#file_ = ROOT.TFile.Open("output_jets01_mc_eta2.5_20181120_160649/rootfile_list_VectorDiJet1Jet_600_13TeV_SIGNAL_20181120_160649_0_reduced_skim.root")
#file_ = ROOT.TFile.Open("mc_signal_600.root")
#file_ = ROOT.TFile.Open("mc_signal_300.root")

#file_ = ROOT.TFile.Open("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/data_files/data_strat_unblind.root")

#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim_40.root")
#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5_skim.root")
#file_ = ROOT.TFile.Open("../data_trig_eff_eta2.5.root")
#file_ = ROOT.TFile.Open("../data_ntuple_CR_studies.root")
#file_ = ROOT.TFile.Open("../data_ntuple_CR_nocut.root")
#file_ = ROOT.TFile.Open("../data_ntuple_full_study_10perc.root")
#file_ = ROOT.TFile.Open("../data_ntuple_full_study.root")
#file_ = ROOT.TFile.Open("/work/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/data_runH_ntuple.root")
#file_ = ROOT.TFile.Open("../inputs_Silvio/data_ntuple_filtered.root")
file_ = ROOT.TFile.Open("../inputs_Silvio/data_RunH_ntuple_long.root")


tree = file_.Get("tree")
if not type(tree)==ROOT.TTree:
    tree = file_.Get("rootTupleTree/tree")

#tree = file_.Get("rootTupleTree/tree")

j1  = ROOT.TLorentzVector()
j2  = ROOT.TLorentzVector()
j2m = ROOT.TLorentzVector()
j2m2 = ROOT.TLorentzVector()
j2m3 = ROOT.TLorentzVector()

histo = ROOT.TH1F("histo",xtitle,xbins,xmin,xmax)
histomod = ROOT.TH1F("histomod",xtitle,xbins,xmin,xmax)
histomod2 = ROOT.TH1F("histomod2",xtitle,xbins,xmin,xmax)
histomod3 = ROOT.TH1F("histomod3",xtitle,xbins,xmin,xmax)


rnd = ROOT.TRandom3()

'''
tree.SetBranchStatus("*",0)
tree.SetBranchStatus("isr_pt",1)
tree.SetBranchStatus("isr_eta",1)
tree.SetBranchStatus("jet1_pt",1)
tree.SetBranchStatus("jet1_eta",1)
tree.SetBranchStatus("jet1_phi",1)
tree.SetBranchStatus("jet1_mass",1)
tree.SetBranchStatus("jet2_pt",1)
tree.SetBranchStatus("jet2_eta",1)
tree.SetBranchStatus("jet2_phi",1)
tree.SetBranchStatus("jet2_mass",1)

for i,ev in enumerate(tree):
    if ev.isr_pt>=0:
#    if ev.isr_pt>=0 and not(abs(ev.jet1_eta-ev.jet2_eta)<2.5 and abs(ev.jet1_eta+ev.jet2_eta)<2.5):
#    if ev.isr_pt>=0 and abs(ev.jet1_eta-ev.jet2_eta)<2.5 and abs(ev.jet1_eta+ev.jet2_eta)<2.5:
        j1.SetPtEtaPhiM(ev.jet1_pt, ev.jet1_eta, ev.jet1_phi, ev.jet1_mass)
        j2.SetPtEtaPhiM(ev.jet2_pt, ev.jet2_eta, ev.jet2_phi, ev.jet2_mass)
        j2m.SetPtEtaPhiM(ev.jet2_pt, -ev.jet2_eta, ev.jet2_phi, ev.jet2_mass)
        j2m2.SetPtEtaPhiM(ev.jet2_pt, rnd.Rndm()*5 - 2.5, ev.jet2_phi, ev.jet2_mass)
        mass = (j1+j2).M()
        massm = (j1+j2m).M()      
        massm2 = (j1+j2m2).M()      
        if abs(j1.Eta()-j2.Eta())<1.1  and j1.DeltaR(j2 )>1.1    and abs(j2.Eta())<2.5:
            histo.Fill(mass)
        if abs(j1.Eta()-j2m.Eta())<1.1 and j1.DeltaR(j2m)>1.1    and abs(j2m.Eta())<2.5:
            histomod.Fill(massm)
        if abs(j1.Eta()-j2m2.Eta())<1.1 and j1.DeltaR(j2m2)>1.1  and abs(j2m2.Eta())<2.5:
            histomod2.Fill(massm2)
            for j in range(1):
                j2m3.SetPtEtaPhiM(ev.jet2_pt, rnd.Gaus()*1.75 + 0.35*ev.jet1_eta, ev.jet2_phi, ev.jet2_mass)
                massm3 = (j1+j2m3).M()      
                if abs(j1.Eta()-j2m3.Eta())<1.1 and j1.DeltaR(j2m3)>1.1  and abs(j2m3.Eta())<2.5:
                    histomod3.Fill(massm3)
    if i%100000==0:
        print(i)
    if i>5000: break
'''

print("tree.Draw(...)")

#preselection = "abs(jet1_eta-jet2_eta)<1.4 && abs(jet1_eta+jet2_eta)<1.4 && isr_pt>=40"
#preselection = "isr_pt>=50 &&  deltaR(jet1_eta,jet1_phi,jet2_eta,jet2_phi)>1.1 && deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1 "
#preselection = "isr_pt>=50 && (jet1_pt*jet2_pt)>20000  "
#preselection = "isr_pt>=50 && deltaR(jet1_eta,jet1_phi,jet2_eta,jet2_phi)>1.1 && deltaR(jet1_eta,jet1_phi,-jet2_eta,jet2_phi)>1.1 && (jet1_pt+jet2_pt)>0 "
#preselection = "isr_pt>=70 && abs(TVector2::Phi_mpi_pi(jet1_phi-jet2_phi))>1.57 " # && TVector2::Phi_mpi_pi(phi1-phi2)
#preselection = "isr_pt>=50  && (jet1_pt*TMath::CosH(jet1_eta)+jet2_pt*TMath::CosH(jet2_eta))>350" # && TVector2::Phi_mpi_pi(phi1-phi2)
preselection = "isr_pt>=70 && L1_HTT270 && HLT_CaloScoutingHT250" # && TVector2::Phi_mpi_pi(phi1-phi2) &&  abs(TVector2::Phi_mpi_pi(jet1_phi-jet2_phi))>1.57
#&& sqrt(jet1_pt*jet2_pt)>110 && sqrt(jet1_pt*jet2_pt)<160
#preselection = "isr_pt>=50" # && TVector2::Phi_mpi_pi(phi1-phi2)
#&& abs(TVector2::Phi_mpi_pi(jet1_phi-jet2_phi))>1.57
#&& (jet1_pt*jet2_pt)>265*265/4
#preselection = "isr_pt>=50 && abs(TVector2::Phi_mpi_pi(jet1_phi-jet2_phi))>2.35"
#&& jet1_pt*jet2_pt>9000
#preselection = "abs(jet1_eta-jet2_eta)<1.4  && isr_pt>70"

#tree.Draw("dijet_mass >> histo", preselection + "&&abs(jet1_eta-jet2_eta)<1.1")
#tree.Draw("TMath::Sqrt(2.068*jet1_pt*jet2_pt*(TMath::CosH(jet1_eta+jet2_eta)       - TMath::Cos(TVector2::Phi_mpi_pi(jet1_phi-jet2_phi)))) >> histomod" , preselection + "&&abs(jet1_eta+jet2_eta)<1.1 && deltaR(jet1_eta,jet1_phi, -jet2_eta,jet2_phi)>1.1")
#tree.Draw("sqrt(2.068*jet1_pt*jet2_pt*(TMath::CosH(jet1_eta+jet2_eta)       - cos(TVector2::Phi_mpi_pi(jet1_phi-jet2_phi)))) >> histomod2", preselection + "&&abs(jet1_eta+jet2_eta)<1.1 && deltaR(jet1_eta,jet1_phi, -jet2_eta,jet2_phi)>1.1" )
#tree.Draw("sqrt(2.068*jet1_pt*jet2_pt*(TMath::CosH(jet1_eta-jet2_eta)       - cos(TVector2::Phi_mpi_pi(jet1_phi-jet2_phi)))) >> histomod3", preselection + "&&abs(jet1_eta-jet2_eta)<1.1 && deltaR(jet1_eta,jet1_phi, jet2_eta,jet2_phi)>1.1  && deltaR(jet1_eta,jet1_phi, -jet2_eta,jet2_phi)>1.1" )
#tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt, jet2_eta, jet2_phi, jet2_mass) >> histo", preselection )
#tree.Draw("MyMass(jet1_pt, -jet1_eta, jet1_phi, jet1_mass, jet2_pt, jet2_eta, jet2_phi, jet2_mass) >> histomod", preselection )
tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt, jet2_eta, jet2_phi, jet2_mass) >> histo", preselection )
tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt,-jet2_eta, jet2_phi, jet2_mass)*weightRunHOld_rnd(jet1_pt*jet2_pt) >> histomod", preselection )
tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt,-jet2_eta, jet2_phi, jet2_mass)*weightRunH_rnd(jet1_pt*jet2_pt) >> histomod2", preselection )
#tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt,-jet2_eta, jet2_phi, jet2_mass)*weightRunH_rnd(jet1_pt*jet2_pt)  >> histomod2", preselection )
#tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt,-jet2_eta, jet2_phi, jet2_mass)*weightRunHOld_rnd(jet1_pt*jet2_pt) >> histomod3", preselection )
#tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt, jet1_eta + dijet_deta/abs(dijet_deta)*(abs(dijet_deta)-1.1)/(3-1.1)*1.1, jet2_phi, jet2_mass) >> histomod2", preselection + " && abs(dijet_deta)>1.1 && abs(dijet_deta)<1.3" )
#tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt, jet1_eta + dijet_deta/abs(dijet_deta)* abs(DijetEta(jet1_pt*jet2_pt)), jet2_phi, jet2_mass) >> histomod3", preselection + " && abs(dijet_deta)>1.1 && abs(dijet_deta)<1.3" )

#for i in range(0,5):
#    tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt, jet1_eta - jet1_eta/abs(jet1_eta)* abs(DijetEta(jet1_pt*jet2_pt)), jet2_phi, jet2_mass) >>+ histomod3", preselection + " && abs(dijet_deta)>1.1 && abs(dijet_deta)<1.3" )


#tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt, Eta2(jet1_eta, jet1_pt*jet2_pt), jet2_phi, jet2_mass) >> histomod2", "("+preselection+") " ) ##* weight(jet1_pt*jet2_pt)
#tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt, Eta2(jet1_eta, jet1_pt*jet2_pt), jet2_phi, jet2_mass) >> histomod2", preselection )
#tree.Draw("MyMass(jet1_pt,  jet1_eta, jet1_phi, jet1_mass, jet2_pt, Eta1(), jet2_phi, jet2_mass) >> histomod3", preselection )
#tree.Draw("MyMassTest(jet1_pt, jet1_eta,jet1_phi,jet1_mass,jet2_pt, jet2_eta, jet2_phi, isr_eta, isr_phi) >> histo", preselection )
#tree.Draw("MyMassTest(jet1_pt, -jet1_eta,jet1_phi,jet1_mass,jet2_pt, jet2_eta, jet2_phi, isr_eta, isr_phi) >> histomod", preselection )
#tree.Draw("MyMassTest(jet1_pt, jet1_eta,jet1_phi,jet1_mass,jet2_pt, jet2_eta, jet2_phi, isr_eta, isr_phi) >> histo", preselection )
#tree.Draw("MyMassTest(jet1_pt, jet1_eta,jet1_phi,jet1_mass,jet2_pt, -jet2_eta, jet2_phi, isr_eta, isr_phi) >> histomod", preselection )
#tree.Draw("MyMass(jet1_pt, jet1_eta,jet1_phi,jet1_mass,jet2_pt, -jet2_eta, jet2_phi, isr_eta, isr_phi) >> histomod2", preselection )
#tree.Draw("MyMassTest(jet1_pt, jet1_eta,jet1_phi,jet1_mass,jet2_pt, Eta1(), jet2_phi, isr_eta, isr_phi) >> histomod2", preselection )
#tree.Draw("MyMass(jet1_pt, jet1_eta,jet1_phi,jet1_mass,jet2_pt, Eta2(jet1_eta, 20000)  , jet2_phi, isr_eta, isr_phi) >> histomod2", preselection  )
#tree.Draw("MyMassTest(jet1_pt, jet1_eta,jet1_phi,jet1_mass,jet2_pt, Eta2(jet1_eta, jet1_pt*jet2_pt)  , jet2_phi, isr_eta, isr_phi) >> histomod3", preselection  )

#max_ = histo.GetMaximum()
histo = rebin(histo)
histomod = rebin(histomod)
histomod2 = rebin(histomod2)
histomod3 = rebin(histomod3)

max_ = max_*1.2
#max_ = max_/5/3
#max_ = 40

bin_low = histo.FindBin(normalize_min)
bin_high = histo.FindBin(xmax)

print("Integrals:")
print("Histo: %f",histo.Integral(bin_low,bin_high))
print("HistoMod  (red):     %f, ratio: %f", histomod.Integral(bin_low,bin_high), histomod.Integral(bin_low,bin_high)/histo.Integral(bin_low,bin_high))
print("HistoMod2 (blue):    %f, ratio: %f",histomod2.Integral(bin_low,bin_high),histomod2.Integral(bin_low,bin_high)/histo.Integral(bin_low,bin_high))
print("HistoMod3 (magenta): %f, ratio: %f",histomod3.Integral(bin_low,bin_high),histomod3.Integral(bin_low,bin_high)/histo.Integral(bin_low,bin_high))


histomod.Sumw2()
histomod.SetLineColor(ROOT.kRed)

histomod2.Sumw2()
histomod2.SetLineColor(ROOT.kBlue)

histomod3.Sumw2()
histomod3.SetLineColor(ROOT.kMagenta)

#histomod.Scale(1.04799646743)

if "data" in file_.GetName():
    histomod.Scale(histo.Integral(bin_low,bin_high)/(1E-9+histomod.Integral(bin_low,bin_high)))
    histomod2.Scale(histo.Integral(bin_low,bin_high)/(1E-9+histomod2.Integral(bin_low,bin_high)))
    histomod3.Scale(histo.Integral(bin_low,bin_high)/(1E-9+histomod3.Integral(bin_low,bin_high)))



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
padPlot.cd()
if "data" in file_.GetName():
    padPlot.SetLogy(1)


histo.GetXaxis().SetRangeUser(xmin+1E-6, xmax-1E-6)

histo.SetMaximum(max_)
histo.Draw("HIST,ERR")
histomod.Draw("HIST,ERR,same")
histomod2.Draw("HIST,ERR,same")
histomod3.Draw("HIST,ERR,same")


padRatio.cd()

padSizeRatio = (padPlot.GetWh()*padPlot.GetAbsHNDC())/(padRatio.GetWh()*padRatio.GetAbsHNDC())
ratio1 = getRatio(histomod,histo,padSizeRatio)
ratio2 = getRatio(histomod2,histo,padSizeRatio)
ratio3 = getRatio(histomod3,histo,padSizeRatio)
ratio1.GetXaxis().SetTitle("m_{jj} [GeV]")
ratio1.GetXaxis().SetRangeUser(xmin+1E-6, xmax-1E-6)
ratio1.GetYaxis().SetRangeUser(-8, 8)
ratio1.Draw("HISTO,ERR")
ratio1.Draw("HISTO,ERR")
ratio2.Draw("HISTO,ERR,same")
ratio3.Draw("HISTO,ERR,same")
padRatio.Draw()


canv.SaveAs("control_region_study.png")
canv.SaveAs("control_region_study.C")
canv.SaveAs("control_region_study.root")
