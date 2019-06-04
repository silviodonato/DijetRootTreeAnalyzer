import ROOT

#file_ = ROOT.TFile.Open("../data_test_Apr_plot_sr.root")
file_ = ROOT.TFile.Open("../data_test_Apr_plot_cr.root")


isr_pts = range(45,70)

start_low = 200
start_high = 300

mean = (start_low+start_high)/2
sigma = (start_high-start_low)/2

gr = ROOT.TGraph()
for i, isr_pt in enumerate(isr_pts):
    histo = file_.Get("dijetMassHisto_isrptcut_%d"%isr_pt)
    max_ = histo.GetMaximumBin()
    fit = ROOT.TF1("fit","[2]*(1.-pow((x-[1])/[0],2))",0,1000)
#    max_ = histo.GetMaximum() 
    fit.SetParameters(sigma,mean,histo.GetMaximum())
    histo.Fit(fit,"N","",mean-sigma/2,mean+sigma/2)
    for n in range(5):
        mean = fit.GetParameter(1)
        sigma = fit.GetParameter(0)
        print(mean,sigma,mean-sigma/4,mean+sigma/4)
        histo.Fit(fit,"N","",mean-sigma/4,mean+sigma/4)
    gr.SetPoint(i, isr_pt, mean)
 
gr.SetMarkerStyle(21)
gr.Draw("APC")