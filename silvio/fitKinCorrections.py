import ROOT
ROOT.gStyle.SetOptStat(0)
#### Comment me! ###
#ROOT.gROOT.SetBatch()
#####################

#ROOT.gROOT.LoadMacro("function.C+")
#ROOT.gROOT.LoadMacro("functions_C.so")


rnd = ROOT.TRandom3()

def getRatioPt(histoHighCSV,histoLowCSV):
    histoHighCSV_pt = histoHighCSV.ProjectionY()
    histoLowCSV_pt = histoLowCSV.ProjectionY()
    ratio_pt = histoHighCSV_pt.Clone("ratio_pt")
    ratio_pt.Divide(histoHighCSV_pt,histoLowCSV_pt)
    return ratio_pt

def getRatioEta(histoHighCSV,histoLowCSV):
    histoHighCSV_eta = histoHighCSV.ProjectionX()
    histoLowCSV_eta = histoLowCSV.ProjectionX()
    ratio_eta = histoHighCSV_eta.Clone("ratio_eta")
    ratio_eta.Divide(histoHighCSV_eta,histoLowCSV_eta)
    return ratio_eta

useTT = False

fileData = ROOT.TFile.Open("/home/sdonato/CMS/tth/withCSVsortedV25_systematics_nBCSVM_CR_v1/JetHT.root")
#fileData = ROOT.TFile.Open("/home/sdonato/CMS/tth/V25_systematics_nBCSVM_CR_v1/JetHT.root")
if useTT: 
    fileTT = ROOT.TFile.Open("/home/sdonato/CMS/tth/V25_systematics_nBCSVM_CR_v1/TT_TuneCUETP8M2T4_13TeV-powheg-pythia8.root")
#fileData = ROOT.TFile.Open("/home/sdonato/CMS/tth/V25_systematics_nBCSVM_CR_v1/QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8.root")

treeData = fileData.Get("tree")
if useTT: 
    treeTT = fileTT.Get("tree")
    #countTT = fileTT.Get("CountWeighted").GetBinContent(1)
    countTT = fileTT.Get("Count").GetBinContent(1)
    cross_TT = 831.*2
    #cross_TT = 1000
    #cross_TT = 0.
    luminosity = 36000.
    cross_TT = 0

######### vars definition ######
scale = 2

pt_nbins = 75
pt_min  = 30.
pt_max  = 280.

eta_nbins = 48*2
eta_min  = -2.4
eta_max  = +2.4

btag_low = 0.5426
btag_high = 0.8484

funct_pt = ROOT.TF1("funct_pt","([2]+[5]*x)*erf((x-[0])*[1])+[3]",pt_min,pt_max)
funct_pt.SetParameters(-1.82290e+02,9.38371e-03,8.74875e+01,-8.63769e+01)

#funct_eta = ROOT.TF1("funct_eta","pol16",eta_min,eta_max)
funct_eta = ROOT.TF1("funct_eta","pol17",eta_min,eta_max)
funct_eta.SetParameters(1.37043e+00,-3.50750e-01,5.89835e-01,-1.29868e+00,8.24484e-01,-1.62533e-01)

########### get 2D histos ########

sel = "jets_btagCSVsorted>=2"
#sel = "1"

treeData.Draw("jets_pt:jets_eta >> histo(%d,%f,%f,%d,%f,%f)"%(eta_nbins,eta_min,eta_max,pt_nbins,pt_min,pt_max),"(%s)&&(jets_btagCSV>%f)"%(sel,btag_high),"GOFF")
histoHighCSV = ROOT.gDirectory.Get("histo").Clone("histoHighCSV")
if useTT: 
    treeTT.Draw("jets_pt:jets_eta >> histo(%d,%f,%f,%d,%f,%f)"%(eta_nbins,eta_min,eta_max,pt_nbins,pt_min,pt_max),"((%s)&&(jets_btagCSV>%f))*puWeight*btagWeightCSV*((genWeight>0)-(genWeight<0))"%(sel,btag_high),"GOFF")
    histoHighCSVTT = ROOT.gDirectory.Get("histo").Clone("histoHighCSVTT")
    histoHighCSVTT.Scale(-cross_TT*luminosity/countTT)
    histoHighCSV.Add(histoHighCSVTT)
print "histoHighCSV.Integral():",histoHighCSV.Integral()
histoHighCSV.Scale(1./histoHighCSV.Integral())


treeData.Draw("jets_pt:jets_eta >> histo(%d,%f,%f,%d,%f,%f)"%(eta_nbins,eta_min,eta_max,pt_nbins,pt_min,pt_max),"(%s)&&(jets_btagCSV>%f) && jets_btagCSV<%f"%(sel,btag_low,btag_high),"GOFF")
histoLowCSV = ROOT.gDirectory.Get("histo").Clone("histoLowCSV")
if useTT: 
    treeTT.Draw("jets_pt:jets_eta >> histo(%d,%f,%f,%d,%f,%f)"%(eta_nbins,eta_min,eta_max,pt_nbins,pt_min,pt_max),"((%s)&&(jets_btagCSV>%f) && jets_btagCSV<%f)*puWeight*btagWeightCSV*((genWeight>0)-(genWeight<0))"%(sel,btag_low,btag_high),"GOFF")
    histoLowCSVTT = ROOT.gDirectory.Get("histo").Clone("histoLowCSVTT")
    histoLowCSVTT.Scale(-cross_TT*luminosity/countTT)
    histoLowCSV.Add(histoLowCSVTT)
print "histoLowCSV.Integral():",histoLowCSV.Integral()
histoLowCSV.Scale(1./histoLowCSV.Integral())


########### get pt ratio and fit pt corrections ########

ratio_pt = getRatioPt(histoHighCSV,histoLowCSV)
ratio_eta = getRatioEta(histoHighCSV,histoLowCSV)
ratio_pt.Fit(funct_pt)

########### apply pt corrections to LowCSV ########

funct2D_pt_str = str(funct_pt.GetExpFormula("P")).replace("x","y") + " + 0*x"
funct2D_pt = ROOT.TF2("funct2D_pt", funct2D_pt_str, eta_min, eta_max, pt_min, pt_max)
histoLowCSV_ptCorr = histoLowCSV.Clone("histoLowCSV_ptCorr")
histoLowCSV_ptCorr.Multiply(funct2D_pt,1)

########### get eta ratio and fit eta corrections ########

ratio_pt_corr1 = getRatioPt(histoHighCSV,histoLowCSV_ptCorr)
ratio_eta_corr1 = getRatioEta(histoHighCSV,histoLowCSV_ptCorr)
ratio_eta.Fit(funct_eta)

########### apply pt-eta corrections to LowCSV ########

funct2D_full_str = "("+str(funct_eta.GetExpFormula("P")) + " )*( " + str(funct_pt.GetExpFormula("P")).replace("x","y")+")"
funct2D_full = ROOT.TF2("funct2D_full", funct2D_full_str, eta_min, eta_max, pt_min, pt_max)

histoLowCSV_full = histoLowCSV.Clone("histoLowCSV_full")
histoLowCSV_full.Multiply(funct2D_full,1)

ratio_pt_corr2 = getRatioPt(histoHighCSV,histoLowCSV_full)
ratio_eta_corr2 = getRatioEta(histoHighCSV,histoLowCSV_full)

################### Draw  checks ##############

ratio_2D_before = histoLowCSV_full.Clone("ratio_2D_before")
ratio_2D_before.Divide(histoHighCSV,histoLowCSV)
ratio_2D_before.SetMaximum(1.5)
ratio_2D_before.SetMinimum(0.5)
ratio_2D_before.Draw("COLZ")

etaFunct = str(funct_eta.GetExpFormula())
ptFunct  = str(funct_pt.GetExpFormula()).replace("x","y")
etaNPar = funct_eta.GetNpar()
ptNPar = funct_pt.GetNpar()
ptFunct = ptFunct.replace("p0]","p"+str(0+etaNPar)+"]")
ptFunct = ptFunct.replace("p1]","p"+str(1+etaNPar)+"]")
ptFunct = ptFunct.replace("p2]","p"+str(2+etaNPar)+"]")
ptFunct = ptFunct.replace("p3]","p"+str(3+etaNPar)+"]")
ptFunct = ptFunct.replace("p4]","p"+str(4+etaNPar)+"]")

funct2D_full_refit_str = "("+ etaFunct + " )*( " + ptFunct +")"
funct2D_full_refit = ROOT.TF2("funct2D_full_refit", funct2D_full_refit_str, eta_min, eta_max, pt_min, pt_max)

for i in range(etaNPar):
    funct2D_full_refit.SetParameter(i,funct_eta.GetParameter(i))
for i in range(ptNPar):
    funct2D_full_refit.SetParameter(i+etaNPar,funct_pt.GetParameter(i))

fitResults = ratio_2D_before.Fit(funct2D_full_refit)

histoLowCSV_full_refit = histoLowCSV.Clone("histoLowCSV_full_refit")
histoLowCSV_full_refit.Multiply(funct2D_full_refit,1)

ratio_2D_after = histoLowCSV_full.Clone("ratio_2D_after")
ratio_2D_after.Divide(histoHighCSV,histoLowCSV_full)
ratio_2D_after.SetMaximum(1.5)
ratio_2D_after.SetMinimum(0.5)

ratio_2D_after_refit = histoLowCSV_full_refit.Clone("ratio_2D_after_refit")
ratio_2D_after_refit.Divide(histoHighCSV,histoLowCSV_full_refit)
ratio_2D_after_refit.SetMaximum(1.5)
ratio_2D_after_refit.SetMinimum(0.5)


ratio_pt.SetLineColor(ROOT.kBlack)
ratio_pt_corr1.SetLineColor(ROOT.kBlue)
ratio_pt_corr2.SetLineColor(ROOT.kRed)

ratio_eta.SetLineColor(ROOT.kBlack)
ratio_eta_corr1.SetLineColor(ROOT.kBlue)
ratio_eta_corr2.SetLineColor(ROOT.kRed)

c1 = ROOT.TCanvas("c1")

ratio_pt.Draw()
ratio_pt_corr1.Draw("same")
ratio_pt_corr2.Draw("same")
funct_pt.Draw("same")

c1.SaveAs("ratio_pt.png")

c2 = ROOT.TCanvas("c2")

funct_eta.Draw("same")

ratio_eta.Draw()
ratio_eta_corr1.Draw("same")
ratio_eta_corr2.Draw("same")
funct_eta.Draw("same")

c2.SaveAs("ratio_eta.png")

c3 = ROOT.TCanvas("c3")

ratio_2D_before.Draw("COLZ")

c3.SaveAs("ratio_2D_before.png")

c4 = ROOT.TCanvas("c4")

ratio_2D_after.Draw("COLZ")

c4.SaveAs("ratio_2D_after.png")

c5 = ROOT.TCanvas("c5")

ratio_2D_after_refit.Draw("COLZ")

c5.SaveAs("ratio_2D_after_refit.png")

print
print funct2D_pt_str
print 
print funct2D_full_str
print 

################### make .h file with weights ##############

funct2D_full_str = str(funct2D_full_refit.GetExpFormula("P"))
funct2D_full_str = funct2D_full_str.replace("--","+")
funct2D_full_str = funct2D_full_str.replace("++","+")
funct2D_full_str = funct2D_full_str.replace("-+","-")
funct2D_full_str = funct2D_full_str.replace("+-","-")
funct2D_full_str = funct2D_full_str.replace("x","eta")
funct2D_full_str = funct2D_full_str.replace("y","pt")
funct2D_full_str = funct2D_full_str.replace("abs(eta)","eta")

txt = '''
#include<algorithm>

float btagCorrection(float pt, float eta, float csv){
    if(csv<%f || csv>%f) return 1;
    else return %s;
}
'''%(btag_low,btag_high,funct2D_full_str)
#    eta = std::abs(eta);

outputFile = file("btagCorrection_ddQCD.h","w")
outputFile.write(txt)
outputFile.close()


#######################################################



c6 = ROOT.TCanvas("c6")

rnd = ROOT.TRandom3()



############ stupid way ###########

#funct_pt_err = []
#for j in range(10):
#    funct_pt_err.append(funct_pt.Clone("funct_pt_err"+str(j)))
#    for i in range(funct_pt.GetNpar()):
#        delta = funct_pt.GetParError(i) * rnd.Gaus()
#        funct_pt_err[j].SetParameter(i,funct_pt.GetParameter(i) + delta)
#    funct_pt_err[j].Draw("same")

############ correct way ###########

ratio_pt.Draw()
fitResults = ratio_pt.Fit(funct_pt,"ESV0")
res = fitResults.Get()
matr = res.GetCovarianceMatrix()
matr.Print()
funct_pt.Draw("same")

funct_pt_err = []
eigenvalues = getattr(ROOT,"TVectorT<double>")()
eigenvectors = matr.EigenVectors(eigenvalues)

for i in range(funct_pt.GetNpar()):
    funct_pt_err.append(funct_pt.Clone("funct_pt_err"+str(i)))
    gaus = rnd.Gaus()
    delta=[0.]*funct_pt.GetNpar()
    for j in range(funct_pt.GetNpar()):
        centralValue = funct_pt.GetParameter(j)
        delta = eigenvectors[j][i] * (eigenvalues[i])**0.5 
        funct_pt_err[i].SetParameter(j, centralValue + delta*2)
        print eigenvectors[j][i],"\t",eigenvalues[i],"\t",delta,"\t",centralValue,"\t",centralValue+delta
    funct_pt_err[i].SetLineColor(1+i)
    funct_pt_err[i].Draw("same")

c6.SaveAs("pt_errors.png")


#################################

ratio_eta.Draw()
fitResults = ratio_eta.Fit(funct_eta,"ES")
res = fitResults.Get()
matr = res.GetCovarianceMatrix()
matr.Print()

ratio_eta.Draw()
funct_eta.Draw("same")

funct_eta_err = []
eigenvalues = getattr(ROOT,"TVectorT<double>")()
eigenvectors = matr.EigenVectors(eigenvalues)

for i in range(funct_eta.GetNpar()):
    funct_eta_err.append(funct_eta.Clone("funct_eta_err"+str(i)))
    gaus = rnd.Gaus()*20
    delta=[0.]*funct_eta.GetNpar()
    for j in range(funct_eta.GetNpar()):
        centralValue = funct_eta.GetParameter(j)
        delta = eigenvectors[j][i] * (eigenvalues[i])**0.5
        funct_eta_err[i].SetParameter(j, centralValue + delta*2)
        print eigenvectors[j][i],"\t",eigenvalues[i],"\t",delta,"\t",centralValue,"\t",centralValue+delta
    funct_eta_err[i].SetLineColor(1+i)
    funct_eta_err[i].Draw("same")

c6.SaveAs("pt_errors.png")




