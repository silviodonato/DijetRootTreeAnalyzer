#! /usr/bin/env python
from ROOT import *
import os, multiprocessing
import copy
import math
from array import array
import optparse
import re

rnd = TRandom3()

gStyle.SetOptStat(0)
default_dir = "output_20180418_163054"
default_mass = "150,200,300,400,500,600,800,1000"
#default_mass = "1000"
usage = "usage: %prog [options]"
parser = optparse.OptionParser(usage)

parser.add_option("-d", "--directory", action="store", type="string", dest="dir", default=default_dir)
parser.add_option("-m", "--mass", action="store", type="string", dest="mass", default=default_mass)
# parser.add_option("-o", "--output", action="store", type="string", dest="output", default="histos.root")
parser.add_option("-v", "--var", action="store", type="string", dest="var", default="dijet_mass")
parser.add_option("-b", "--batch", action="store", type="string", dest="batch", default="True")
(options, args) = parser.parse_args()
step = 50.
numberOfBins = 14000
leftEdge = 0
rightEdge = 14000
massBoundaries = array('f',[  1, 3, 6, 10, 16, 23, 31, 40, 50, 61, 74, 88, 103, 119, 137, 156, 176,
                    197, 220, 244, 270, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606,
                    649, 693, 740, 788, 838, 890, 944, 1000, 1058, 1118, 1181, 1246,
                    1313, 1383, 1455, 1530, 1607, 1687, 1770, 1856, 1945, 2037, 2132,
                    2231, 2332, 2438, 2546, 2659, 2775, 2895, 3019, 3147, 3279, 3416,
                    3558, 3704, 3854, 4010, 4171, 4337, 4509, 4686, 4869, 5058, 5253,
                    5455, 5663, 5877, 6099, 6328, 6564, 6808, 7060, 7320, 7589, 7866,
                    8152, 8447, 8752, 9067, 9391, 9726, 10072, 10430, 10798, 11179,
                    11571, 11977, 12395, 12827, 13272, 13732, 14000])
getHistoNBins = {"mjj": 10000, "mjj_ratio": 200  }
getHistoMin   = {"mjj": 0,     "mjj_ratio": 0   }
getHistoMax   = {"mjj": 10000, "mjj_ratio": 5.0 }

# h_mjj_fullSel_varBin = TH1F("h_mjj_fullSel_varBin", "",
#                                       103, massBoundaries)
# h_mjj_nom_fullSel_varBin = TH1F("h_mjj_nom_fullSel_varBin", "",
#                                       103, massBoundaries)
# h_mjj_jesUp_fullSel_varBin = TH1F("h_mjj_jesUp_fullSel_varBin", "",
#                                       103, massBoundaries)
# h_mjj_jesDown_fullSel_varBin = TH1F("h_mjj_jesDown_fullSel_varBin", "",
#                                       103, massBoundaries)
# h_mjj_jerUp_fullSel_varBin = TH1F("h_mjj_jerUp_fullSel_varBin", "",
#                                       103, massBoundaries)
# h_mjj_jerDown_fullSel_varBin = TH1F("h_mjj_jerDown_fullSel_varBin", "",
#                                       103, massBoundaries)
# h_mjj_fullSel_fixBin = TH1F("h_mjj_fullSel_fixBin", "",
#                                       getHistoNBins["mjj"],
#                                       getHistoMin["mjj"], getHistoMax["mjj"])
# h_mjj_nom_fullSel_fixBin = TH1F("h_mjj_nom_fullSel_fixBin", "",
#                                       getHistoNBins["mjj"],
#                                       getHistoMin["mjj"], getHistoMax["mjj"])
# h_mjj_jesUp_fullSel_fixBin = TH1F("h_mjj_jesUp_fullSel_fixBin", "",
#                                       getHistoNBins["mjj"],
#                                       getHistoMin["mjj"], getHistoMax["mjj"])
# h_mjj_jesDown_fullSel_fixBin = TH1F("h_mjj_jesDown_fullSel_fixBin", "",
#                                       getHistoNBins["mjj"],
#                                       getHistoMin["mjj"], getHistoMax["mjj"])
# h_mjj_jerUp_fullSel_fixBin = TH1F("h_mjj_jerUp_fullSel_fixBin", "",
#                                       getHistoNBins["mjj"],
#                                       getHistoMin["mjj"], getHistoMax["mjj"])
# h_mjj_jerDown_fullSel_fixBin = TH1F("h_mjj_jerDown_fullSel_fixBin", "",
#                                       getHistoNBins["mjj"],
# 				  getHistoMin["mjj"], getHistoMax["mjj"])

h_mjj_ratio = TH1F("h_mjj_ratio", "", getHistoNBins["mjj_ratio"],
                             getHistoMin["mjj_ratio"], getHistoMax["mjj_ratio"])
h_mjj_ratio_nom = TH1F("h_mjj_ratio_nom", "", getHistoNBins["mjj_ratio"],
                             getHistoMin["mjj_ratio"], getHistoMax["mjj_ratio"])
h_mjj_ratio_jerUp = TH1F("h_mjj_ratio_jerUp", "", getHistoNBins["mjj_ratio"],
                             getHistoMin["mjj_ratio"], getHistoMax["mjj_ratio"])
h_mjj_ratio_jerDown = TH1F("h_mjj_ratio_jerDown", "", getHistoNBins["mjj_ratio"],
                             getHistoMin["mjj_ratio"], getHistoMax["mjj_ratio"])
h_mjj_ratio_jesUp = TH1F("h_mjj_ratio_jesUp", "", getHistoNBins["mjj_ratio"],
                             getHistoMin["mjj_ratio"], getHistoMax["mjj_ratio"])
h_mjj_ratio_jesDown = TH1F("h_mjj_ratio_jesDown", "", getHistoNBins["mjj_ratio"],
                                 getHistoMin["mjj_ratio"], getHistoMax["mjj_ratio"])
h_mjj_ratio_flat = TH1F("h_mjj_ratio_flat", "", getHistoNBins["mjj_ratio"],
                                 getHistoMin["mjj_ratio"], getHistoMax["mjj_ratio"])


r = TRandom3(1988);

hltP0  = 2.441
hltP1  = 0.0
recoP0 = 2.077
recoP1 = 0.0
jerUp   = 0.10
jerDown = -0.10
jes     = 0.
jesUp   = 0.02
jesDown = -0.02
hltFunc = TF1("hltFunc","sqrt([0]*[0]/x+[1]*[1])",0,14000)
hltFunc.SetParameter(0,hltP0)
hltFunc.SetParameter(1,hltP1)
recoFunc = TF1("recoFunc","sqrt([0]*[0]/x+[1]*[1])",0,14000)
recoFunc.SetParameter(0,recoP0)
recoFunc.SetParameter(1,recoP1)

smearFunc  = TF1("smearFunc","sqrt(([2]*[2]-[0]*[0])/x+([3]*[3]-[1]*[1]))",0,14000) # smearFunc*smearFunc = hltFunc*hltFunc - recoFunc*recoFunc
smearFunc.SetParameter(0,recoP0)
smearFunc.SetParameter(1,recoP1)
smearFunc.SetParameter(2,hltP0)
smearFunc.SetParameter(3,hltP1)

smearJerUpFunc    = TF1("smearJerUpFunc","sqrt((sqrt([2]*[2]/x+[3]*[3])+[4]*sqrt([0]*[0]/x+[1]*[1]))*(sqrt([2]*[2]/x+[3]*[3])+[4]*sqrt([0]*[0]/x+[1]*[1]))-[0]*[0]/x+[1]*[1])",0,14000) # smearJerUpFunc*smearJerUpFunc = (hltFunc+jerUp*recoFunc)*(hltFunc+p*recoFunc) - recoFunc*recoFunc
smearJerUpFunc.SetParameter(0,recoP0)
smearJerUpFunc.SetParameter(1,recoP1)
smearJerUpFunc.SetParameter(2,hltP0)
smearJerUpFunc.SetParameter(3,hltP1)
smearJerUpFunc.SetParameter(4,jerUp)

smearJerDownFunc  = TF1("smearJerDownFunc","sqrt((sqrt([2]*[2]/x+[3]*[3])+[4]*sqrt([0]*[0]/x+[1]*[1]))*(sqrt([2]*[2]/x+[3]*[3])+[4]*sqrt([0]*[0]/x+[1]*[1]))-[0]*[0]/x+[1]*[1])",0,14000) # smearJerDownFunc*smearJerDownFunc = (hltFunc+jerDown*recoFunc)*(hltFunc+p*recoFunc) - recoFunc*recoFunc
smearJerDownFunc.SetParameter(0,recoP0)
smearJerDownFunc.SetParameter(1,recoP1)
smearJerDownFunc.SetParameter(2,hltP0)
smearJerDownFunc.SetParameter(3,hltP1)
smearJerDownFunc.SetParameter(4,jerDown)

outputFileName = [  "rootfile_list_VectorDiJet1JetNoCorrection.root",
                    "rootfile_list_VectorDiJet1Jet.root",
                    "rootfile_list_VectorDiJet1Jet_JERUP.root",
                    "rootfile_list_VectorDiJet1Jet_JERDOWN.root",
                    "rootfile_list_VectorDiJet1Jet_JESUP.root",
                    "rootfile_list_VectorDiJet1Jet_JESDOWN.root",
                    "rootfile_list_VectorDiJet1Jet_flat.root",
                    ]
h_mjj_ratio_array = {}
h_mjj_ratio_nom_array = {}
h_mjj_ratio_jerUp_array = {}
h_mjj_ratio_jerDown_array = {}
h_mjj_ratio_jesUp_array = {}
h_mjj_ratio_jesDown_array = {}
h_mjj_ratio_flat_array = {}
def prob_mass(rootTree, var, outputFileName, acceptances):
    print("acceptances = ",acceptances)
    mass_array = []
    f = {}
    for m,t in rootTree.iteritems():
        mass_array.append(float(m))
    mass_array.sort()
    for i,m in enumerate(mass_array):
        mass = m
        tree = rootTree[str(int(m))]
        nentries    = tree.Draw("","")
        acceptance  = acceptances[str(int(m))]
        print("m = "  + str(int(m)))
        print("acceptance"  + str(acceptance))
    
        h_mjj_ratio.Reset()
        h_mjj_ratio_nom.Reset()
        h_mjj_ratio_jerUp.Reset()
        h_mjj_ratio_jerDown.Reset()
        h_mjj_ratio_jesUp.Reset()
        h_mjj_ratio_jesDown.Reset()
        h_mjj_ratio_flat.Reset()

        h_mjj_ratio.SetBinContent(0,1.*nentries*(1.-acceptance))
        h_mjj_ratio_nom.SetBinContent(0,1.*nentries*(1.-acceptance))
        h_mjj_ratio_jerUp.SetBinContent(0,1.*nentries*(1.-acceptance))
        h_mjj_ratio_jerDown.SetBinContent(0,1.*nentries*(1.-acceptance))
        h_mjj_ratio_jesUp.SetBinContent(0,1.*nentries*(1.-acceptance))
        h_mjj_ratio_jesDown.SetBinContent(0,1.*nentries*(1.-acceptance))
        h_mjj_ratio_flat.SetBinContent(0,1.*nentries*(1.-acceptance))
        
        for entry in tree:
            isr_pt      = tree.isr_pt
            jet2_pt     = tree.jet2_pt
            jet1_pt     = tree.jet1_pt
            isr_eta      = tree.isr_eta
            jet2_eta     = tree.jet2_eta
            jet1_eta     = tree.jet1_eta
            dijet_deta  = tree.dijet_deta
            dijet_mass  = tree.dijet_mass
            mjj         = dijet_mass
           
            
            if isr_pt >68 jet2_pt>68 and jet1_pt>68  and abs(dijet_deta)<1.1 and abs(isr_eta)<2.5 and abs(jet1_eta)<2.5 and abs(jet2_eta)<2.5:
                x1 = r.Gaus()
                x2 = r.Gaus()
                x3 = r.Gaus()

                flat = rnd.Rndm()*10000 
                mjj_flat = flat*(1.+jes)*(1.+smearFunc.Eval(flat)*x1)
                mjj_nom = dijet_mass*(1.+jes)*(1.+smearFunc.Eval(dijet_mass)*x1)
                mjj_jerUp = dijet_mass*(1.+jes)*(1.+smearJerUpFunc.Eval(dijet_mass)*x1) ## it was x2
                mjj_jerDown = dijet_mass*(1.+jes)*(1.+smearJerDownFunc.Eval(dijet_mass)*x1) ## it was x3
                mjj_jesUp = dijet_mass*(1.+jesUp)*(1.+smearFunc.Eval(dijet_mass)*x1)
                mjj_jesDown = dijet_mass*(1.+jesDown)*(1.+smearFunc.Eval(dijet_mass)*x1)
                # ORIGINAL
                mjj_ratio_flat = mjj_flat/mass
                mjj_ratio = dijet_mass/mass
                mjj_ratio_nom = mjj_nom/mass
                mjj_ratio_jerUp = mjj_jerUp/mass
                mjj_ratio_jerDown = mjj_jerDown/mass
                mjj_ratio_jesUp = mjj_jesUp/mass
                mjj_ratio_jesDown = mjj_jesDown/mass

                # SILVIO TEST
                #mjj_ratio_flat    = (mjj_flat  - mass)/((mass)**0.5) /40. + 1.
                #mjj_ratio         = (dijet_mass  - mass)/((mass)**0.5) /40. + 1.
                #mjj_ratio_nom     = (mjj_nom     - mass)/((mass)**0.5) /40. + 1.
                #mjj_ratio_jerUp   = (mjj_jerUp   - mass)/((mass)**0.5) /40. + 1.
                #mjj_ratio_jerDown = (mjj_jerDown - mass)/((mass)**0.5) /40. + 1.
                #mjj_ratio_jesUp   = (mjj_jesUp   - mass)/((mass)**0.5) /40. + 1.
                #mjj_ratio_jesDown = (mjj_jesDown - mass)/((mass)**0.5) /40. + 1. 
                
                # h_mjj_fullSel_varBin.Fill(mjj)
                # h_mjj_nom_fullSel_varBin.Fill(mjj_nom)
                # h_mjj_jerUp_fullSel_varBin.Fill(mjj_jerUp)
                # h_mjj_jerDown_fullSel_varBin.Fill(mjj_jerDown)
                # h_mjj_jesUp_fullSel_varBin.Fill(mjj_jesUp)
                # h_mjj_jesDown_fullSel_varBin.Fill(mjj_jesDown)
                # h_mjj_fullSel_fixBin.Fill(mjj)
                # h_mjj_nom_fullSel_fixBin.Fill(mjj_nom)
                # h_mjj_jerUp_fullSel_fixBin.Fill(mjj_jerUp)
                # h_mjj_jerDown_fullSel_fixBin.Fill(mjj_jerDown)
                # h_mjj_jesUp_fullSel_fixBin.Fill(mjj_jesUp)
                # h_mjj_jesDown_fullSel_fixBin.Fill(mjj_jesDown)

                h_mjj_ratio.Fill(mjj_ratio)
                h_mjj_ratio_nom.Fill(mjj_ratio_nom)
                h_mjj_ratio_jerUp.Fill(mjj_ratio_jerUp)
                h_mjj_ratio_jerDown.Fill(mjj_ratio_jerDown)
                h_mjj_ratio_jesUp.Fill(mjj_ratio_jesUp)
                h_mjj_ratio_jesDown.Fill(mjj_ratio_jesDown)
                h_mjj_ratio_flat.Fill(mjj_ratio_flat)

                # h_mjj_ratio_nom.SetBinError(mjj_ratio_nom)
                # h_mjj_ratio_jerUp.SetBinError(mjj_ratio_jerUp)
                # h_mjj_ratio_jerDown.SetBinError(mjj_ratio_jerDown)
                # h_mjj_ratio_jesUp.Fill(mjj_ratio_jesUp)
                # h_mjj_ratio_jesDown.Fill(mjj_ratio_jesDown)
            else:
                h_mjj_ratio_flat.Fill(-1)
                h_mjj_ratio.Fill(-1)
                h_mjj_ratio_nom.Fill(-1)
                h_mjj_ratio_jerUp.Fill(-1)
                h_mjj_ratio_jerDown.Fill(-1)
                h_mjj_ratio_jesUp.Fill(-1)
                h_mjj_ratio_jesDown.Fill(-1)
        print("total acceptance"  + str((h_mjj_ratio.Integral()/h_mjj_ratio.Integral(0,100000))))
        

        h_mjj_ratio_array[str(int(mass))] = h_mjj_ratio.Clone()
        h_mjj_ratio_array[str(int(mass))].SetName("h_qq_"+'CaloScoutingNotTheRightOne_'+str(int(mass))+'_WJ')

        h_mjj_ratio_nom_array[str(int(mass))] = h_mjj_ratio_nom.Clone()
        h_mjj_ratio_nom_array[str(int(mass))].SetName("h_qq_"+'CaloScouting_'+str(int(mass))+'_WJ')

        h_mjj_ratio_jerUp_array[str(int(mass))] = h_mjj_ratio_jerUp.Clone()
        h_mjj_ratio_jerUp_array[str(int(mass))].SetName("h_qq_"+'CaloScoutingJERUP_'+str(int(mass))+'_WJ')

        h_mjj_ratio_jerDown_array[str(int(mass))] = h_mjj_ratio_jerDown.Clone()
        h_mjj_ratio_jerDown_array[str(int(mass))].SetName("h_qq_"+'CaloScoutingJERDOWN_'+str(int(mass))+'_WJ')

        h_mjj_ratio_jesUp_array[str(int(mass))] = h_mjj_ratio_jesUp.Clone()
        h_mjj_ratio_jesUp_array[str(int(mass))].SetName("h_qq_"+'CaloScoutingJESUP_'+str(int(mass))+'_WJ')

        h_mjj_ratio_jesDown_array[str(int(mass))] = h_mjj_ratio_jesDown.Clone()
        h_mjj_ratio_jesDown_array[str(int(mass))].SetName("h_qq_"+'CaloScoutingJESDOWN_'+str(int(mass))+'_WJ')

        h_mjj_ratio_flat_array[str(int(mass))] = h_mjj_ratio_flat.Clone()
        h_mjj_ratio_flat_array[str(int(mass))].SetName("h_qq_"+'CaloScoutingFlat_'+str(int(mass))+'_WJ')

        
        # h_mjj_fullSel_varBin.Write()
        # h_mjj_nom_fullSel_varBin.Write()
        # h_mjj_jerUp_fullSel_varBin.Write()
        # h_mjj_jerDown_fullSel_varBin.Write()
        # h_mjj_jesUp_fullSel_varBin.Write()
        # h_mjj_jesDown_fullSel_varBin.Write()
        # h_mjj_fullSel_fixBin.Write()
        # h_mjj_nom_fullSel_fixBin.Write()
        # h_mjj_jerUp_fullSel_fixBin.Write()
        # h_mjj_jerDown_fullSel_fixBin.Write()
        # h_mjj_jesUp_fullSel_fixBin.Write()
        # h_mjj_jesDown_fullSel_fixBin.Write()
        #
        # h_mjj_ratio.Write()
        # h_mjj_ratio_nom.Write()
        # h_mjj_ratio_jerUp.Write()
        # h_mjj_ratio_jerDown.Write()
        # h_mjj_ratio_jesUp.Write()
        # h_mjj_ratio_jesDown.Write()
    f = []
    histos = [h_mjj_ratio_array, h_mjj_ratio_nom_array, h_mjj_ratio_jerUp_array, h_mjj_ratio_jerDown_array, h_mjj_ratio_jesUp_array, h_mjj_ratio_jesDown_array,h_mjj_ratio_flat_array]
    for i in range(0,7):
        f.append(TFile(outputFileName[i], "recreate"))
        # print histos
        for m in mass_array:
            histos[i][str(int(m))].Write()
            # print h.GetName()
        f[-1].Close()

def mass_shapes(directory, mass, var, outputFileName):
    rootTree = {}
    eventCounter = {}
    acceptances = {}
    pathlist = os.listdir(directory)
    # print data
    mass = re.split(",|, ", mass)
    for m in mass:
        rootTree[m] = TChain("rootTupleTree/tree")
        pass_ = 0
        total_ = 0
        for file in pathlist:
            if ('rootfile_list_VectorDiJet1Jet_'+m) in file and 'reduced_skim.root' in file:
                rootTree[m].Add(directory+"/"+file)
                fileName = file
                file_ = TFile.Open(directory+"/"+file)
                histoCount = file_.Get("DijetFilter/EventCount/EventCounter")
                print(directory+"/"+file)
                total_ += histoCount.GetBinContent(1)
                pass_ += histoCount.GetBinContent(3)
        print(pass_ , total_)
        if total_>0:
                acceptances[m] = 1.* pass_ / total_
                print("acceptances " + str(m) + " " + str(acceptances[m]))
        else:
                acceptances[m] = 0
                print("total = 0")
    prob_mass(rootTree, var, outputFileName, acceptances)


mass_shapes(options.dir, options.mass, options.var, outputFileName)
