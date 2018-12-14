#! /usr/bin/env python
from ROOT import *
import os, multiprocessing
import copy
import math
from array import array
import optparse
import re

colors = [kRed +3,kRed +1,kRed -4,kRed -7,kRed -9,kGreen +3,kGreen +1,kGreen -4,kGreen -7,kGreen -9,kBlue +3,kBlue +1,kBlue -4,kBlue -7,kBlue -9,]

massMin, massMax = 296., 1000.

def interpol(massArr, step, acc, acc_errs, matching):
    print("Run interpol. masmassArr=%s, step=%s, acc=%s, acc_errs=%s, matchings=%s"%(massArr, step, acc, acc_errs, matching))
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

gROOT.SetBatch(1)
gStyle.SetOptStat(0)
masses = [300,400,500,600,800,1000]
usage = "usage: %prog [options]"
default_mass = 500

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

def getAcceptances(fileIn, outputFileName, matchings):
    print("Opening %s, writing, %s, matching %s"%(fileIn, outputFileName, matchings))
    _file = TFile(fileIn)
    acc = []
    acc_errs = []
    for mass in masses:
#        histo = _file.Get("h_qq_CaloScouting_%s_WJ"%(int(mass)))
        if "NoCorrection" in fileIn:
            histo = _file.Get("h_qq_CaloScoutingNotTheRightOne_%s_WJ"%(int(mass)))
        elif "JERUP" in fileIn:
            histo = _file.Get("h_qq_CaloScoutingJERUP_%s_WJ"%(int(mass)))
        elif "JERDOWN" in fileIn:
            histo = _file.Get("h_qq_CaloScoutingJERDOWN_%s_WJ"%(int(mass)))
        elif "JESUP" in fileIn:
            histo = _file.Get("h_qq_CaloScoutingJESUP_%s_WJ"%(int(mass)))
        elif "JESDOWN" in fileIn:
            histo = _file.Get("h_qq_CaloScoutingJESDOWN_%s_WJ"%(int(mass)))
        else:
            histo = _file.Get("h_qq_CaloScouting_%s_WJ"%(int(mass)))
        nbins = histo.GetNbinsX()
        acc.append(histo.Integral(histo.FindBin(1.*massMin/mass),histo.FindBin(1.*massMax/mass-1e-9))/histo.Integral(-1,nbins+2))
#        acc.append(histo.Integral(histo.FindBin(1.*massMin/mass)-1,histo.FindBin(1.*massMax/mass+1e-9))/histo.Integral(-1,nbins+2))
        acc_errs.append(0.0001)

    outFile=TFile(outputFileName, "RECREATE")
    c1=TCanvas("c","c",0,0,800,800)
    #gr=TGraphErrors(len(mass),massArr,acc,array('f',[0]*len(acc)),acc_errs)
    massArr = array('f',masses)
    gr_imp, acc_dict=interpol(massArr, options.step, acc, acc_errs, matching)
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
    return gr_imp, acc_dict

if options.matching == "all":
    matching_array = ["jets01", "jets02", "jets12", "jetsij"]
elif options.matching is not "":
    matching_array = options.matching.split(",")
else:
    matching_array = ["jets01", "jets02", "jets12", "jetsij"]
# dir_array = options.dir.split(",")

dir_array = [
                "input_jets01/rootfile_list_VectorDiJet1Jet%s.root",
                "input_jets02/rootfile_list_VectorDiJet1Jet%s.root",
                "input_jets12/rootfile_list_VectorDiJet1Jet%s.root",
                "input_jetsij/rootfile_list_VectorDiJet1Jet%s.root",
                ]

acc_dict = {}
grs = {}
for typ in ["","NoCorrection","_JERDOWN","_JERUP","_JESDOWN","_JESUP"]:
    acc_dict[typ] = {}
    grs[typ] = {}
    print dir_array
    print matching_array
    for i,matching in enumerate(matching_array):
        if matching == "jetsij":
            continue
        grs[typ][matching], acc_dict[typ][matching] = getAcceptances(dir_array[i]%typ, "acceptance_"+matching+typ+".root", matching)

    if "jetsij" in matching_array:
        acc_dict[typ]["jetsij"] = {}
        for m in acc_dict[typ][matching_array[0]].keys():
            acc_dict[typ]["jetsij"][m] = (acc_dict[typ]["jets01"][m]+acc_dict[typ]["jets02"][m]+acc_dict[typ]["jets12"][m])/3.



for i,matching in enumerate(matching_array):
    if matching=="jetsij": continue
    first = True
    c2 = TCanvas("c1","")
    leg = TLegend(0.1,0.7,0.48,0.9)
    for j,typ in enumerate(["","NoCorrection","_JERDOWN","_JERUP","_JESDOWN","_JESUP"]):
        grs[typ][matching].SetMarkerColor(colors[j])
        if first:
            grs[typ][matching].Draw("AP")
            first = False
        else:
            grs[typ][matching].Draw("P")
        leg.AddEntry(grs[typ][matching],typ.replace("_",""),"p")
    leg.Draw()
    c2.SaveAs("acceptance_syst_%s.png"%matching)
    c2.SaveAs("acceptance_syst_%s.root"%matching)
    c2.SaveAs("acceptance_syst_%s.pdf"%matching)

    


    #input_acc = open(options.outputAccPath+'/inputAcceptance.py','w')
    #input_acc.write("acc_dict = "+str(acc_dict))

    #print "File "+options.outputAccPath+"/inputAcceptance.py with acceptance was created!"
