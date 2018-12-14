import ROOT
import os

folder1   = "input_jets01"
folder2   = "input_jets02"
folder3   = "input_jets12"
folderOut = "input_jetsij"

#folder1   = "input_jets01"
#folder2   = "input_jets01"
#folder3   = "input_jets01"
#folderOut = "input_jetsij_test3"

fileList = [
    "ResonanceShapes_qq_13TeV_CaloScouting_2016.root",
    "ResonanceShapes_qq_13TeV_CaloScouting_2016_JERDOWN.root",
    "ResonanceShapes_qq_13TeV_CaloScouting_2016_JERUP.root",
    "ResonanceShapes_qq_13TeV_CaloScouting_2016_JESDOWN.root",
    "ResonanceShapes_qq_13TeV_CaloScouting_2016_JESUP.root",
    "full.root"
]

def merge(fileName1,fileName2,fileName3,fileNameOut):
    print("#CALLING merge(%s,%s,%s,%s)"%(fileName1,fileName2,fileName3,fileNameOut))
    f1 = ROOT.TFile.Open(fileName1)
    f2 = ROOT.TFile.Open(fileName2)
    f3 = ROOT.TFile.Open(fileName3)
    fo = ROOT.TFile.Open(fileNameOut,"RECREATE")

    if "ResonanceShapes" in fileName1:
        data = False
    else:
        data = True
    dataFolder = "DijetFilter/dijetMassHisto"
    if data:
        fo.mkdir(dataFolder)
        for a in f1.Get(dataFolder).GetListOfKeys():
            obj1 = f1.Get(dataFolder).Get(a.GetName())
            obj2 = f2.Get(dataFolder).Get(a.GetName())
            obj3 = f3.Get(dataFolder).Get(a.GetName())
#            for obj in [obj1,obj2,obj3]: 
#                obj.Sumw2()
#                obj.Scale(1./3)
            fo.cd(dataFolder)
            out = obj1.Clone(obj1.GetName())
            out.Add(obj2)
            out.Add(obj3)
            out.Write()
    else:
        for a in f1.GetListOfKeys():
            obj1 = f1.Get(a.GetName())
            obj2 = f2.Get(a.GetName())
            obj3 = f3.Get(a.GetName())
            for obj in [obj1,obj2,obj3]: 
                obj.Sumw2()
                obj.Scale(1./3)
            fo.cd()
            out = obj1.Clone(obj1.GetName())
            out.Add(obj2)
            out.Add(obj3)
            out.Write()
    fo.Close()

for fil in fileList:
    fileName1   = folder1 + "/" + fil
    fileName2   = folder2 + "/" + fil
    fileName3   = folder3 + "/" + fil
    fileNameOut = folderOut + "/" + fil
    merge(fileName1,fileName2,fileName3,fileNameOut)


