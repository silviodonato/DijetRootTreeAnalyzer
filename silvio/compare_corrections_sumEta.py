import ROOT

#file1 = ROOT.TFile.Open("tmp/withHLTriggerSig300/Sum_Delta_Eta_ratio.root")
#file2 = ROOT.TFile.Open("tmp/withHLTriggerSig0/Sum_Delta_Eta_ratio.root")

file1 = ROOT.TFile.Open("tmp/withTriggerSig400/Sum_Delta_Eta_ratio.root")
file2 = ROOT.TFile.Open("tmp/withTrigger/Sum_Delta_Eta_ratio.root")

ratio1 = file1.Get("canv2").GetListOfPrimitives().At(1)
fit1 = file1.Get("canv2").GetListOfPrimitives().At(2)
fit1.SetLineColor(ROOT.kBlue)
ratio1.SetLineColor(ROOT.kBlue)
ratio1.SetMarkerColor(ROOT.kBlue)

ratio2 = file2.Get("canv2").GetListOfPrimitives().At(1)
fit2 = file2.Get("canv2").GetListOfPrimitives().At(2)
fit2.SetLineColor(ROOT.kRed)
ratio2.SetLineColor(ROOT.kRed)
ratio2.SetMarkerColor(ROOT.kRed)

canv = ROOT.TCanvas("canv")
ratio1.Draw("HIST,ERR")
ratio2.Draw("HIST,ERR,same")
fit1.Draw("same")
fit2.Draw("same")

canv.SaveAs("")

c2 = ROOT.TCanvas("c2")


ratioNew = ratio1.Clone("ratioNew")
ratioNew.Divide(ratio1,ratio2)
ratioNew.GetXaxis().SetRangeUser(70,500)
ratioNew.GetYaxis().SetRangeUser(0.9975,1.0025)
ratioNew.Draw("HIST,ERR")

c2.SaveAs("correction_modiefiers.png")
c2.SaveAs("correction_modiefiers.pdf")
c2.SaveAs("correction_modiefiers.root")

c3 = ROOT.TCanvas("c3")

fitNew = ratio2.Clone("fitNew")
fitNew.Reset()

fit1H = fitNew.Clone("fit1H")
fit2H = fitNew.Clone("fit2H")

fit1H.Add(fit1)
fit2H.Add(fit2)

fitNew.Divide(fit1H,fit2H)
fitNew.GetXaxis().SetRangeUser(70,500)
fitNew.GetYaxis().SetRangeUser(0.9975,1.0025)
fitNew.Draw("HIST")

c3.SaveAs("correction_modiefiers_fit.png")
c3.SaveAs("correction_modiefiers_fit.pdf")
c3.SaveAs("correction_modiefiers_fit.root")

