import ROOT
import os

lumiIn     = 1.777
lumiOut    = 21.190

fileIn   = "input_jets01/full.root"
fileOut  = "input_jets01_fakeFullLumi/full.root"

#fileIn   = "data_wRunH_deta1p1_full_ten_percent.root"
#fileOut  = "data_wRunH_deta1p1_ext.root"

print("scale(%s,%s)"%(fileIn,fileOut))
f1 = ROOT.TFile.Open(fileIn)
fo = ROOT.TFile.Open(fileOut,"RECREATE")

dataFolder = "DijetFilter/dijetMassHisto"
if type(f1.Get(dataFolder))==ROOT.TDirectory:
    fo.mkdir(dataFolder)
    for a in f1.Get(dataFolder).GetListOfKeys():
        obj1 = f1.Get(dataFolder).Get(a.GetName())
        obj1.Scale(lumiOut/lumiIn)
        fo.cd(dataFolder)
        out = obj1.Clone(obj1.GetName())
        out.Sumw2()
        out.Write()
else:
    for a in f1.GetListOfKeys():
        obj1 = f1.Get(a.GetName())
        obj1.Scale(lumiOut/lumiIn)
        out = obj1.Clone(obj1.GetName())
        out.Sumw2()
        out.Write()

fo.Close()



