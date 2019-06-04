import ROOT
f = ROOT.TFile("data_3D_deta1p1_full_ten_percent.root")
#f = ROOT.TFile("data_3D_deta1p1_full.root")

histo3d = f.Get("DijetFilter/dijetMassHisto/dijet_mass")

xax = histo3d.GetXaxis()
yax = histo3d.GetYaxis()
zax = histo3d.GetZaxis()

xmin = 0
xmax = 5000

ymin = 40
ymax = 50

#zmin = -1.1
#zmax = 1.1

zmin = -9999999
zmax = 9999999
#zmax = 9999999

xmin += abs(xmin)*1E-4
ymin += abs(ymin)*1E-4
zmin += abs(zmin)*1E-4

xmax -= abs(xmin)*1E-4
ymax -= abs(ymax)*1E-4
zmax -= abs(zmax)*1E-4

dijet_mass_px = histo3d.ProjectionX("_px",yax.FindBin(ymin),yax.FindBin(ymax),zax.FindBin(zmin),zax.FindBin(zmax))
dijet_mass_px.SetLineWidth(3)
dijet_mass_px.Draw()

histo1d = f.Get("DijetFilter/dijetMassHisto/dijetMassHisto_isrptcut_40_50")
dijet_mass_px.SetLineColor(ROOT.kRed)
dijet_mass_px.SetLineWidth(2)
histo1d.Draw("same")