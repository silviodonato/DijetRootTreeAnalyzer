from optparse import OptionParser
import os
import BinnedFitMod
import ROOT
signal_mjj_binning = [1, 3, 6, 10, 16, 23, 31, 40, 50, 61, 74, 88, 103, 119, 137, 156, 176, 197, 220, 244, 270, 296, 325, 354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000, 1058, 1118, 1181, 1246, 1313, 1383, 1455, 1530, 1607, 1687, 1770, 1856, 1945, 2037, 2132, 2231, 2332, 2438, 2546, 2659, 2775, 2895, 3019, 3147, 3279, 3416, 3558, 3704, 3854, 4010, 4171, 4337, 4509, 4686, 4869, 5058, 5253, 5455, 5663, 5877, 6099, 6328, 6564, 6808, 7060, 7320, 7589, 7866, 8152, 8447, 8752, 9067, 9391, 9726, 10072, 10430, 10798, 11179, 11571, 11977, 12395, 12827, 13272, 13732, 14000]
isrPtCutBinning = [40,50,60,70,80,90,100,150,200,300]

def findLines(lines, findString, box):

    output = ""
    startIndex = lines.index("["+box+"]"+'\n')
    br_match = 0

    for line in lines[startIndex:]:
        if findString in line and '#' not in line[0:5]:
            br_match=line.count("[")
            br_match-=line.count("]")
            output = line
            break
        startIndex+=1

    if br_match is not 0:
        for line in lines[(startIndex+1):]:
            if '#' not in line[0:5]:
                br_match+=line.count("[")
                br_match-=line.count("]")
                output+=line
            # print br_match
            if br_match == 0:
                break
    return output

def signal_mjj_function(minBin, maxBin):
    signal_mjj = []
    for mjj in signal_mjj_binning[signal_mjj_binning.index(minBin):signal_mjj_binning.index(maxBin)+1]:
        signal_mjj.append(mjj)

    return signal_mjj


def writeConfigFile(configFileTemplateName,box,isrPtCut,fitRanges,variables_range):
    output_string = {}
    keys = []
    keys.append('box')
    output_string['box'] = "["+box+"]" # '[CaloTrijet2016]'

    minDrawRange,minFitRange,maxFitRange=fitRanges
    mjjLowLeft,mjjLowRight,mjjBlindLeft,mjjBlindRight,mjjHighLeft,mjjHighRight = variables_range

    keys.append('variables')
    output_string['variables'] = "variables = ['mjj[%s.,%s.,%s.]','th1x[0,0,1000]']"%(minDrawRange,minFitRange,maxFitRange)

    keys.append('histoName')
    # output_string['histoName'] ='histoName = "dijetMassHisto_isrptcut_%s"'%(int(isrPtCut))
    output_string['histoName'] ='histoName = ['
    if isrPtCut < 300:
        output_string['histoName'] += "'DijetFilter/dijetMassHisto/dijetMassHisto_isrptcut_%s_%s'"%(int(isrPtCut), isrPtCutBinning[isrPtCutBinning.index(isrPtCut)+1])
        for isrBinLeftEdge in isrPtCutBinning[isrPtCutBinning.index(isrPtCut)+1:-1]:
            output_string['histoName'] += ", 'DijetFilter/dijetMassHisto/dijetMassHisto_isrptcut_%s_%s'"%(isrBinLeftEdge, isrPtCutBinning[isrPtCutBinning.index(isrBinLeftEdge)+1])
        output_string['histoName'] += ", "
    output_string['histoName'] += "'DijetFilter/dijetMassHisto/dijetMassHisto_isrptcut_300'"
    output_string['histoName'] += "]"

    keys.append('variables_range')
    output_string['variables_range'] = "variables_range = ['mjj_Low[%s.,%s.]', 'mjj_Blind[%s.,%s.]', 'mjj_High[%s.,%s.]']"%(mjjLowLeft,mjjLowRight,mjjBlindLeft,mjjBlindRight,mjjHighLeft,mjjHighRight)

    configFileTemplate = open(configFileTemplateName,'r')
    lines = configFileTemplate.readlines()
    # print lines

    keys.append('combine_pdfs')
    output_string['combine_pdfs'] = findLines(lines, 'combine_pdfs', box)

    keys.append('combine_parameters')
    output_string['combine_parameters'] = findLines(lines, 'combine_parameters', box)

    signal_mjj = signal_mjj_function(minDrawRange, maxFitRange)
    keys.append('signal_mjj')
    output_string['signal_mjj'] = "signal_mjj = "+str(signal_mjj)
    configText = ""
    for k in keys:
        configText += output_string[k] + "\n"
    return configText

def createConfigFile(configPath, configFileName, text):
    configFile = open(configPath+configFileName,'w')
    configFile.write(text)
    print "Config file %s/%s was created!"%(configPath, configFileName)

def writeLaTeXTable(outputFileName, chiSquare_dict, isrPtCutArray, minBinArr, maxBin):
    outFile = open(outputFileName,"w")
    output = "\\begin{table}[h]\n \\begin{tabular}{|l||"+"c|"*(len(isrPtCutArray)+1)+"}\n"
    output+="\\textbf{Fit range / isr pT cut}"
    for i,isrPtCut in enumerate(isrPtCutArray):
        output+= " & $p_{T,ISR} > %s $"%(isrPtCut)
    output+=" \\\\\n"
    output+="\\hline\n \\hline\n"
    for j,minBin in enumerate(minBinArr):
        output+=" $%s < m_{jj} < %s$"%(minBin, maxBin)
        for i,isrPtCut in enumerate(isrPtCutArray):
            output+=" & %s"%(chiSquare_dict[int(isrPtCut)][int(minBin)])
        output+=" \\\\\n \\hline\n"

    output+= " \\end{tabular}"
    output+="\n\\end{table}"
    outFile.write(output)
    return output

def main(options,args):
    configFileTemplateName = options.config
    box = options.box
    isrPtCutArray   = [50.,60.,70.,80.,90.,100.]
    minBinArr = [244., 270., 296., 325.]

    # isrPtCutArray   = [70.]
    # minBinArr = [296.]
    chiSquareHisto = ROOT.TH2F("chi2_profile", "Chi2 profile", len(isrPtCutArray), isrPtCutArray[0], isrPtCutArray[-1]+10., len(minBinArr), minBinArr[0], signal_mjj_binning[signal_mjj_binning.index(minBinArr[-1])+1])
    chiSquareHisto.GetXaxis().SetTitle("ISR pT cut")
    chiSquareHisto.GetYaxis().SetTitle("Fit Range")
    c1 = ROOT.TCanvas("chi2_profile","#Chi^{2}/ndof", 0,0,1600,1600)
    chiSquare_dict = {}
    for i,isrPtCut in enumerate(isrPtCutArray):
        chiSquare_dict[int(isrPtCut)] = {}
        chiSquareHisto.GetXaxis().SetBinLabel(i+1, "p_{T,ISR} > " + str(isrPtCut))
        for j,minBin in enumerate(minBinArr):
            isrPtCut = isrPtCut
            fitRanges = minBin,minBin,1000.
            variables_range = minBin,1000,minBin,1000,minBin,1000
            configText = writeConfigFile(configFileTemplateName,box,isrPtCut,fitRanges,variables_range)
            configPath = "/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/config/"
            configFileName = "dijet_isr_DijetFisherAlt4_isrpt_%s_minBin_%s.config"%(int(isrPtCut),int(minBin))
            createConfigFile(configPath, configFileName, configText)
            chiSquare = BinnedFitMod.BinnedFitMod(options, args, configPath+configFileName,str(int(isrPtCut)), str(int(minBin)))
            chiSquare_dict[int(isrPtCut)][int(minBin)] = chiSquare
            chiSquareHisto.GetYaxis().SetBinLabel(j+1, str(minBin) + " < m_{jj} < " + str(fitRanges[2]))
            chiSquareHisto.Fill(isrPtCut,minBin,chiSquare)

    latexText = writeLaTeXTable("chi2_table.tex", chiSquare_dict, isrPtCutArray, minBinArr, 1000)
    # print latexText
    # exit()
    outputFile = ROOT.TFile.Open("chi2_profile.root","RECREATE")

    chiSquareHisto.Draw("COLZ")
    c1.Write()
    # print chiSquare_dict
    raw_input("Press enter...")



if __name__ == '__main__':

    parser = OptionParser()
    parser.add_option('-c','--config',dest="config",type="string",default="config/run2.config",
                  help="Name of the config file to use")
    parser.add_option('-d','--dir',dest="outDir",default="./",type="string",
                  help="Output directory to store cards")
    parser.add_option('-l','--lumi',dest="lumi", default=1.,type="float",
                  help="integrated luminosity in pb^-1")
    parser.add_option('--run-min',dest="runMin", default=0,type="int",
                  help="minimum run to consider for trigger efficiency")
    parser.add_option('--run-max',dest="runMax", default=999999,type="int",
                  help="maximum run to consider for trigger efficiency")
    parser.add_option('-b','--box',dest="box", default="CaloDijet",type="string",
                  help="box name")
    parser.add_option('--no-fit',dest="noFit",default=False,action='store_true',
                  help="Turn off fit (useful for visualizing initial parameters)")
    parser.add_option('--fit-region',dest="fitRegion",default="Full",type="string",
                  help="Fit region")
    parser.add_option('--plot-region',dest="plotRegion",default="Full",type="string",
                  help="Plot region")
    parser.add_option('-i','--input-fit-file',dest="inputFitFile", default=None,type="string",
                  help="input fit file")
    parser.add_option('-w','--weight',dest="useWeight",default=False,action='store_true',
                  help="use weight")
    parser.add_option('-s','--signal',dest="signalFileName", default=None,type="string",
                  help="input dataset file for signal pdf")
    parser.add_option('-m','--model',dest="model", default="gg",type="string",
                  help="signal model")
    parser.add_option('--mass',dest="mass", default="750",type="string",
                  help="mgluino")
    parser.add_option('--xsec',dest="xsec", default="1",type="string",
                  help="cross section in pb")
    parser.add_option('-t','--trigger',dest="triggerDataFile", default=None,type="string",
                  help="trigger data file")
    parser.add_option('--l1',dest="l1Trigger", default=False,action='store_true',
                  help="level-1 trigger")
    parser.add_option('--fit-trigger',dest="doTriggerFit", default=False,action='store_true',
                  help="fit trigger")
    parser.add_option('--fit-spectrum',dest="doSpectrumFit", default=False,action='store_true',
                  help="fit spectrum")
    parser.add_option('--sim',dest="doSimultaneousFit", default=False,action='store_true',
                  help="do simultaneous trigger fit")
    parser.add_option('--multi',dest="multi", default=True,action='store_true',
                  help="multiple background pdfs")
    parser.add_option('--linearX',dest="linearX", default=False,action='store_true',
                  help="linear X axis")


    (options,args) = parser.parse_args()


    main(options,args)
