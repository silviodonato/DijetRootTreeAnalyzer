from optparse import OptionParser
import ROOT as rt
import rootTools
from framework import Config
from array import *
import os
import sys
from RunCombine import massIterable


def exec_me(command,dryRun=True):
    print command
    if not dryRun: os.system(command)

if __name__ == '__main__':

    parser = OptionParser()
    parser.add_option('-c','--config',dest="config",type="string",default="config/dijet_bias.config",
                  help="Name of the config file to use")
    parser.add_option('-b','--box',dest="box", default="CaloTrijet2016",type="string",
                  help="box name")
    parser.add_option('-m','--model',dest="model", default="qq",type="string",
                  help="signal model name")
    parser.add_option('--mass',dest="mass", default='300',type="string",
                  help="mass of resonance")
    parser.add_option('-l','--lumi',dest="lumi", default="35.9",type="string",
                  help="lumi in fb^-1, e.g.: 12.910")
    parser.add_option('--dry-run',dest="dryRun",default=False,action='store_true',
                  help="Just print out commands to run")
    parser.add_option('--rMax',dest="rMax",default=20,type="float",
                  help="maximum r value (for better precision)")
    parser.add_option('-r',dest="r",default=1,type="float",
                  help="expect signal r value")
    parser.add_option('--rMin',dest="rMin",default=-20,type="float",
                  help="minimum r value (for better precision)")
    parser.add_option('--xsec',dest="xsec",default=10,type="float",
                  help="xsec for signal in pb (r = 1)")
    parser.add_option('-i','--input-fit-file',dest="inputFitFile", default="fits_trijet_2018/DijetFitResults_CaloTrijet2016.root",type="string",
                  help="input fit file")
    parser.add_option('-d','--dir',dest="outDir",default="./",type="string",
                  help="Output directory to store everything")
    parser.add_option('-t','--toys',dest="toys",default=1000,type="int",
                  help="number of toys")
    parser.add_option('--gen-pdf',dest="genPdf", default="fiveparam", choices=['modexp','fiveparam','atlas','atlas6','silvio5','silvio6'],
                  help="pdf for generating")
    parser.add_option('--fit-pdf',dest="fitPdf", default="fiveparam", choices=['modexp','fiveparam','atlas','atlas6','silvio5','silvio6'],
                  help="pdf for fitting")
    parser.add_option('--asymptotic-file',dest="asymptoticFile",default=None,type="string",
                  help="load asymptotic cross section results file")

    (options,args) = parser.parse_args()

    pdfIndexMap = {#'fourparam': 0,
                   'modexp': 0,
                   'fiveparam': 1,
                   'atlas': 2,
                   'atlas6': 3,
                   'silvio5': 4,
                   'silvio6': 5
                   }

    box = options.box
    lumi = float(options.lumi)
    model = options.model

    backgroundDsName = {'CaloDijet2015':'inputs/data_CaloScoutingHT_Run2015D_BiasCorrected_CaloDijet2015.root',
                        #'CaloDijet2016':'inputs/data_CaloScoutingHT_Run2016BCD_NewBiasCorrectedFlat_Golden12910pb_CaloDijet2016.root',
                        'CaloDijet2016':'inputs/data_CaloScoutingHT_Run2016BCDEFG_BiasCorrected_Mjj300_Golden27637pb_CaloDijet2016.root',
                        'CaloTrijet2016':'inputs/data_2016_part_unblind_dijetisr.root',
                        'PFDijet2016':'inputs/data_PFRECOHT_Run2016BCD_Golden12910pb_PFDijet2016.root',
                        'CaloDijet20152016':'inputs/data_CaloScoutingHT_Run2015D2016B_CaloDijet20152016.root'
                        }

    signalDsName = ''
    if box=='CaloDijet2016':
        signalDsName = 'inputs/ResonanceShapes_%s_13TeV_CaloScouting_Spring16.root'%model
    elif box=='PFDijet2016':
        signalDsName = 'inputs/ResonanceShapes_%s_13TeV_Spring16.root'%model
    elif box=='CaloTrijet2016':
        signalDsName = 'inputs/ResonanceShapes_%s_13TeV_CaloScouting_2016.root'%model


    signalSys = ''
    if box=='CaloDijet2016':
        signalSys  = '--jesUp inputs/ResonanceShapes_%s_13TeV_CaloScouting_Spring16_JESUP.root --jesDown inputs/ResonanceShapes_%s_13TeV_CaloScouting_Spring16_JESDOWN.root'%(model,model)
        signalSys += ' --jerUp inputs/ResonanceShapes_%s_13TeV_CaloScouting_Spring16_JERUP.root --jerDown inputs/ResonanceShapes_%s_13TeV_CaloScouting_Spring16_JERDOWN.root'%(model,model)
    elif box=='PFDijet2016':
        signalSys  =   '--jesUp inputs/ResonanceShapes_%s_13TeV_Spring16_JESUP.root --jesDown inputs/ResonanceShapes_%s_13TeV_Spring16_JESDOWN.root'%(model,model)
        signalSys += ' --jerUp inputs/ResonanceShapes_%s_13TeV_Spring16_JERUP.root'%(model)
    elif box=='CaloTrijet2016':
        signalSys  = ' --jesUp inputs/ResonanceShapes_%s_13TeV_CaloScouting_2016_JESUP.root --jesDown inputs/ResonanceShapes_%s_13TeV_CaloScouting_2016_JESDOWN.root'%(model,model)
        signalSys += ' --jerUp inputs/ResonanceShapes_%s_13TeV_CaloScouting_2016_JERUP.root --jerDown inputs/ResonanceShapes_%s_13TeV_CaloScouting_2016_JERDOWN.root'%(model,model)


    xsecTree = None
    rDict = {}
    if options.asymptoticFile is not None:
        print "INFO: Input ref xsec file!"
        asymptoticRootFile = rt.TFile.Open(options.asymptoticFile,"READ")
        xsecTree = asymptoticRootFile.Get("xsecTree")
        xsecTree.Draw('>>elist','','entrylist')
        elist = rt.gDirectory.Get('elist')
        entry = -1
        while True:
            entry = elist.Next()
            if entry == -1: break
            xsecTree.GetEntry(entry)
            rDict[int(eval('xsecTree.mass'))] = eval('xsecTree.xsecULExp_%s'%box)/options.xsec
    else:
        for massPoint in massIterable(options.mass):
            rDict[int(massPoint)] = options.r
    print rDict

    xsecString = '--xsec %f'%options.xsec
    rRangeString =  '--setPhysicsModelParameterRanges r=%.3f,%.3f'%(options.rMin,options.rMax)

    fixStringGen = '--setPhysicsModelParameters pdf_index=%i'%(pdfIndexMap[options.genPdf])
    freezeStringGen = '--freezeNuisances pdf_index'
    if options.genPdf != 'fiveparam':
        freezeStringGen += ',p51_CaloTrijet2016,p52_CaloTrijet2016,p53_CaloTrijet2016,p54_CaloTrijet2016'
    if options.genPdf != 'modexp':
        freezeStringGen += ',pm1_CaloTrijet2016,pm2_CaloTrijet2016,pm3_CaloTrijet2016,pm4_CaloTrijet2016'
    if options.genPdf != 'atlas':
        freezeStringGen += ',pa1_CaloTrijet2016,pa2_CaloTrijet2016,pa3_CaloTrijet2016,pa4_CaloTrijet2016'
    if options.genPdf != 'atlas6':
        freezeStringGen += ',pa61_CaloTrijet2016,pa62_CaloTrijet2016,pa63_CaloTrijet2016,pa64_CaloTrijet2016,pa65_CaloTrijet2016'
    if options.genPdf != 'fourparam':
        freezeStringGen += ',p1_CaloTrijet2016,p2_CaloTrijet2016,p3_CaloTrijet2016'
    if options.fitPdf != 'silvio5':
        freezeStringGen += ',p1s5_CaloTrijet2016,p2s5_CaloTrijet2016,p3s5_CaloTrijet2016,p4s5_CaloTrijet2016'
    if options.fitPdf != 'silvio6':
        freezeStringGen += ',p1s6_CaloTrijet2016,p2s6_CaloTrijet2016,p3s6_CaloTrijet2016,p4s6_CaloTrijet2016,p5s6_CaloTrijet2016'



    fixStringFit = '--setPhysicsModelParameters pdf_index=%i'%(pdfIndexMap[options.fitPdf])
    freezeStringFit = '--freezeNuisances pdf_index'
    if options.fitPdf != 'fiveparam':
        freezeStringFit += ',p51_CaloTrijet2016,p52_CaloTrijet2016,p53_CaloTrijet2016,p54_CaloTrijet2016'
    if options.fitPdf != 'modexp':
        freezeStringFit += ',pm1_CaloTrijet2016,pm2_CaloTrijet2016,pm3_CaloTrijet2016,pm4_CaloTrijet2016'
    if options.fitPdf != 'atlas':
        freezeStringFit += ',pa1_CaloTrijet2016,pa2_CaloTrijet2016,pa3_CaloTrijet2016,pa4_CaloTrijet2016'
    if options.fitPdf != 'atlas6':
        freezeStringFit += ',pa61_CaloTrijet2016,pa62_CaloTrijet2016,pa63_CaloTrijet2016,pa64_CaloTrijet2016,pa65_CaloTrijet2016'
    if options.fitPdf != 'fourparam':
        freezeStringFit += ',p1_CaloTrijet2016,p2_CaloTrijet2016,p3_CaloTrijet2016'
    if options.fitPdf != 'silvio5':
        freezeStringFit += ',p1s5_CaloTrijet2016,p2s5_CaloTrijet2016,p3s5_CaloTrijet2016,p4s5_CaloTrijet2016'
    if options.fitPdf != 'silvio6':
        freezeStringFit += ',p1s6_CaloTrijet2016,p2s6_CaloTrijet2016,p3s6_CaloTrijet2016,p4s6_CaloTrijet2016,p5s6_CaloTrijet2016'


    for massPoint in massIterable(options.mass):
        exec_me('python python/WriteDataCard.py -m %s --mass %s -i %s -l %f -c %s -b %s -d %s %s %s %s %s --multi'%(model, massPoint, options.inputFitFile,1000*lumi,options.config,box,options.outDir,signalDsName,backgroundDsName[box],xsecString,signalSys),options.dryRun)
        exec_me('combine -M GenerateOnly %s/dijet_combine_%s_%s_lumi-%.3f_%s.txt -n %s_%s_lumi-%.3f_r-%.3f_%s_%s_%s %s %s %s --toysFrequentist --saveToys --expectSignal %.3f -t %i'%(options.outDir,model,massPoint,lumi,box,model,massPoint,lumi,rDict[int(massPoint)],box,options.genPdf,options.fitPdf,rRangeString,fixStringGen,freezeStringGen,rDict[int(massPoint)],options.toys),options.dryRun)
        exec_me('combine -M MaxLikelihoodFit --robustFit=1  %s/dijet_combine_%s_%s_lumi-%.3f_%s.txt -n %s_%s_lumi-%.3f_r-%.3f_%s_%s_%s --toysFile higgsCombine%s_%s_lumi-%.3f_r-%.3f_%s_%s_%s.GenerateOnly.mH120.123456.root -t %i %s %s %s --minimizerTolerance 0.01 --minimizerStrategy 2 --minos poi --saveWorkspace'%(options.outDir,model,massPoint,lumi,box,model,massPoint,lumi,rDict[int(massPoint)],box,options.genPdf,options.fitPdf,model,massPoint,lumi,rDict[int(massPoint)],box,options.genPdf,options.fitPdf,options.toys,rRangeString,fixStringFit,freezeStringFit),options.dryRun)
        exec_me('mv higgsCombine%s_%s_lumi-%.3f_r-%.3f_%s_%s_%s.GenerateOnly.mH120.123456.root %s/'%(model,massPoint,lumi,rDict[int(massPoint)],box,options.genPdf,options.fitPdf,options.outDir),options.dryRun)
        exec_me('mv higgsCombine%s_%s_lumi-%.3f_r-%.3f_%s_%s_%s.MaxLikelihoodFit.mH120.123456.root %s/'%(model,massPoint,lumi,rDict[int(massPoint)],box,options.genPdf,options.fitPdf,options.outDir),options.dryRun)
        exec_me('mv mlfit%s_%s_lumi-%.3f_r-%.3f_%s_%s_%s.root %s/'%(model,massPoint,lumi,rDict[int(massPoint)],box,options.genPdf,options.fitPdf,options.outDir),options.dryRun)
