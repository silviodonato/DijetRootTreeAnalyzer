from optparse import OptionParser
import os
import BinnedFitMod
from ROOT import *

isrPtCutBinning = [40,50,60,70,80,90,100,150,200,300]

def main(inputFile, outputFile, isrPtCutArray):
    th1fDict = {}
    tfileOutput = TFile.Open(outputFile,"RECREATE")
    for isrPtCut in isrPtCutArray:
        th1fDict[str(int(isrPtCut))] = TH1F("dijetMassHisto_isrptcut_%s"%(int(isrPtCut)),"Dijet Mass", 5000, 0., 5000.)
    tfileInput = TFile.Open(inputFile)
    for isrPtCut in isrPtCutArray:
        if isrPtCut < 300:
            th1fDict[str(int(isrPtCut))].Add(tfileInput.Get("DijetFilter/dijetMassHisto/dijetMassHisto_isrptcut_%s_%s"%(int(isrPtCut), isrPtCutBinning[isrPtCutBinning.index(isrPtCut)+1])))
            for isrBinLeftEdge in isrPtCutBinning[isrPtCutBinning.index(isrPtCut)+1:-1]:
                th1fDict[str(int(isrPtCut))].Add(tfileInput.Get("DijetFilter/dijetMassHisto/dijetMassHisto_isrptcut_%s_%s"%(isrBinLeftEdge, isrPtCutBinning[isrPtCutBinning.index(isrBinLeftEdge)+1])))
        th1fDict[str(int(isrPtCut))].Add(tfileInput.Get('DijetFilter/dijetMassHisto/dijetMassHisto_isrptcut_300'))
    tfileOutput.Write()






if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option('-i','--input',dest="input",type="string",default="",
                  help="Name of the input file")
    parser.add_option('-o','--output',dest="output",type="string",default="",
                  help="Name of the output file")

    (options,args) = parser.parse_args()
    inputFile = options.input
    outputFile = options.output
    isrPtCutArray = [50,60,70,80,90,100]

    main(inputFile, outputFile, isrPtCutArray)
