#! /usr/bin/env python
from ROOT import *
import os, multiprocessing
import copy
import math
from array import array
import optparse
import re

gROOT.SetBatch(1)
gStyle.SetOptStat(0)
default_dir = "output_20180418_163054"
default_mass = "300,400,500,600,800,1000"
usage = "usage: %prog [options]"
parser = optparse.OptionParser(usage)

parser.add_option("-d", "--directory", action="store", type="string", dest="dir", default="")
parser.add_option("-m", "--mass", action="store", type="string", dest="mass", default=default_mass)
# parser.add_option("-o", "--output", action="store", type="string", dest="output", default="histos.root")
parser.add_option("", "--out-acc-dir", action="store", type="string", dest="outputAccPath", default="./")
parser.add_option("-v", "--var", action="store", type="string", dest="var", default="dijet_mass")
parser.add_option("-s", "--step", action="store", type="string", dest="step", default="50")
parser.add_option("-b", "--batch", action="store", type="string", dest="batch", default="True")
parser.add_option("", "--matching", action="store", type="string", dest="matching", default="")
(options, args) = parser.parse_args()
selection    = "isr_pt > 70 && jet2_pt>70 && jet1_pt>70 && abs(jet1_eta)<2.5 && abs(jet2_eta)<2.5 && abs(isr_eta)<2.5 && abs(dijet_deta) < 1.1 && dijet_mass > 270 && dijet_mass < 1000"
#selection    = "jet2_pt>70 && jet1_pt>70 && abs(jet1_eta)<2.5 && abs(jet2_eta)<2.5 && abs(isr_eta)<2.5 && abs(dijet_deta) < 1.1 && dijet_mass > 270 && dijet_mass < 1000"
preselection = "abs(jet1MC_eta)<2.5 && abs(jet2MC_eta)<2.5 && abs(dijetMC_deta) < 1.1"
#selection    += " && "+preselection
#if options.matching == "jets01":
#    selection += " && abs(dijetMC_deta) < 1.1"
#elif options.matching == "jets02":
#    selection += " && abs(jet1MC_eta-isrMC_eta) < 1.1"
#elif options.matching == "jets12":
#    selection += " && abs(jet2MC_eta-isrMC_eta) < 1.1"
step = 10.
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
getHistoNBins = {"mjj": 10000, "mjj_ratio": 75  }
getHistoMin   = {"mjj": 0,     "mjj_ratio": 0   }
getHistoMax   = {"mjj": 10000, "mjj_ratio": 1.5 }
# outputFileName=options.output
def prob_mass(rootTree, var, val_key, isPrintAcc=False):
    mass_array = []
    for m,t in rootTree.iteritems():
        mass_array.append(float(m))
    mass_array.sort()
    acc = array('f')
    acc_reco = array('f')
    acc_gen = array('f')
    acc_errs = array('f')
    for i,m in enumerate(mass_array):
        mass = m
        tree = rootTree[str(int(m))]
        reco = float(tree.Draw(var, selection))
        gen = float(tree.Draw(var,preselection))
        den = float(tree.Draw(var,""))
        accptnc = reco/gen
        print "M = %s: %s/%s"%(m, tree.Draw(var, selection),tree.Draw(var,preselection))
        accptnc_err = math.sqrt(accptnc/gen*(1+accptnc))
        acc.append(accptnc)
        acc_reco.append(reco/den)
        acc_gen.append(gen/den)
        acc_errs.append(accptnc_err)
        if(isPrintAcc): print "acceptance(%s) = %s +- %s"%(mass, accptnc, accptnc_err)
        #for entry in tree:
        #    isr_pt      = tree.isr_pt
        #    jet2_pt     = tree.jet2_pt
        #    dijet_deta  = tree.dijet_deta
        #    jet1_pt     = tree.jet1_pt
        #    dijet_mass  = tree.dijet_mass
        #    mjj         = dijet_mass

           # if isr_pt > 50 and jet2_pt>45  and abs(dijet_deta)<1.2 and jet1_pt>90:
    return {"acceptance": acc,
            "errors": acc_errs,
            "acceptance_reco": acc_reco,
            "acceptance_gen": acc_gen,
            }[val_key]

errs = lambda Ni, N: sqrt(Ni)/N*sqrt(1+Ni/N)

def interpol(massArr, step, acc, acc_errs, matching):
    acc_dict={}
    minMass = massArr[0]
    maxMass = massArr[-1]
    massArrIM = array('f')
    accIM = array('f')
    acc_errsIM = array('f')
    acc_count = 0
    for m in range(int(minMass),int(maxMass+1),int(step)):
        if m not in massArr:
            massArrIM.append(m)
            m2 = min([i for i in massArr if i > m])
            m1 = max([i for i in massArr if i < m])
            acc2 = acc[massArr.index(min([i for i in massArr if i > m]))]
            acc1 = acc[massArr.index(max([i for i in massArr if i < m]))]
            acc_err2 = acc_errs[massArr.index(min([i for i in massArr if i > m]))]
            acc_err1 = acc_errs[massArr.index(max([i for i in massArr if i < m]))]
            accIM.append((m-m1)/(m2-m1)*(acc2-acc1)+acc1)
            acc_dict[m] = accIM[-1]
            acc_errsIM.append(math.sqrt((m-m1)/(m2-m1)*(m-m1)/(m2-m1)*acc_err2*acc_err2+(m2-m)/(m2-m1)*(m2-m)/(m2-m1)*acc_err1*acc_err1))
            #print max([i for i in massArr if i < m]), " | ", min([i for i in massArr if i > m])
        else:
            massArrIM.append(m)
            accIM.append(acc[acc_count])
            acc_dict[m] = accIM[-1]
            acc_errsIM.append(acc_errs[acc_count])
            acc_count+=1
    gr_imp=TGraphErrors(len(massArrIM),massArrIM,accIM,array('f',[0]*len(accIM)),acc_errsIM)
    print accIM
    return gr_imp, acc_dict

def mass_shapes(directory, mass, var, outputFileName, matching):
    rootTree = {}
    pathlist = os.listdir(directory)
    print "Directory: %s"%(directory)
    # print data
    mass = re.split(",|, ", mass)
    massArr = array('f')
    step = float(options.step)
    for m in mass:
        massArr.append(float(m))
        rootTree[m] = TChain("rootTupleTree/tree")
        for file in pathlist:
            if ('rootfile_list_VectorDiJet1Jet_'+m) in file and 'reduced_skim.root' in file:
                rootTree[m].Add(directory+"/"+file)
                fileName = file
    acc = prob_mass(rootTree, var, "acceptance")
    acc_gen = prob_mass(rootTree, var, "acceptance_gen")
    acc_reco = prob_mass(rootTree, var, "acceptance_reco")
    acc_errs = prob_mass(rootTree, var, "errors", True)
    outFile=TFile(outputFileName, "RECREATE")
    c1=TCanvas("c","c",0,0,800,800)
    #gr=TGraphErrors(len(mass),massArr,acc,array('f',[0]*len(acc)),acc_errs)
    gr_imp, acc_dict=interpol(massArr, step, acc, acc_errs, matching)
    #gr.Draw("AP")
    gr_imp.Draw("AP")
    gr_imp.SetMarkerColor(kRed)
    gr_imp.SetMarkerStyle(8)
    #gr.SetTitle("Acceptance vs. m_{jj}")
    #gr.GetXaxis().SetTitle("m_{jj}, GeV")
    #gr.GetYaxis().SetTitle("acceptance")
    #gr.SetMarkerStyle(8)
    c1.SaveAs(outputFileName.split(".")[0]+".pdf")
    c1.SaveAs(outputFileName.split(".")[0]+".png")
    # raw_input("press enter...")
    #gr.Write()
    gr_imp.Write()

    gr_imp, acc_dict_reco = interpol(massArr, step, acc_reco, array('f',[0.0]*len(acc_reco)), matching)
    gr_imp.SetMarkerColor(kRed)
    gr_imp.SetMarkerStyle(8)
    gr_imp.Draw("AP")
    c1.SaveAs(outputFileName.split(".")[0]+"_reco.png")
    c1.SaveAs(outputFileName.split(".")[0]+"_reco.pdf")

    gr_imp, acc_dict_gen  = interpol(massArr, step, acc_gen, array('f',[0.0]*len(acc_gen)), matching)
    gr_imp.SetMarkerColor(kRed)
    gr_imp.SetMarkerStyle(8)
    gr_imp.Draw("AP")
    c1.SaveAs(outputFileName.split(".")[0]+"_gen.png")
    c1.SaveAs(outputFileName.split(".")[0]+"_gen.pdf")
    return acc_dict

if options.matching == "all":
    matching_array = ["jets01", "jets02", "jets12", "jetsij"]
elif options.matching is not "":
    matching_array = options.matching.split(",")
else:
    matching_array = ["jets01", "jets02", "jets12", "jetsij"]
# dir_array = options.dir.split(",")

if not options.dir:
    dir_array = ["/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_jets01_mc_eta2.5_acc_20181114_151035",
                 "/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_jets02_mc_eta2.5_acc_20181114_152551",
                 "/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_8_0_30/src/DijetRootTreeAnalyzer/output_jets12_mc_eta2.5_acc_20181114_155058",]

acc_dict = {}
iter_dir = 0
print dir_array
print matching_array
for matching in matching_array:
    if matching == "jetsij":
        continue
    acc_dict[matching] = mass_shapes(dir_array[iter_dir], options.mass, options.var, "acceptance_"+matching+".root", matching)
    iter_dir += 1

if "jetsij" in matching_array:
    acc_dict["jetsij"] = {}
    for m in acc_dict[matching_array[0]].keys():
        acc_dict["jetsij"][m] = (acc_dict["jets01"][m]+acc_dict["jets02"][m]+acc_dict["jets12"][m])/3.

input_acc = open(options.outputAccPath+'/inputAcceptance.py','w')
input_acc.write("acc_dict = "+str(acc_dict))

print "File "+options.outputAccPath+"/inputAcceptance.py with acceptance was created!"
