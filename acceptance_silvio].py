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
errs = lambda Ni, N: sqrt(Ni)/N*sqrt(1+Ni/N)

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
