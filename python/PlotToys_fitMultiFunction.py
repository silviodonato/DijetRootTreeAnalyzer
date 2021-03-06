# https://root.cern.ch/download/doc/RooFit_Users_Manual_2.91-33.pdf

import ROOT

c1 = ROOT.TCanvas("c1")


#-rw-r--r-- 1 sdonato uniz-higgs  828 Aug  3 15:36 higgsCombineqq_475_lumi-27.637_r-1.000_CaloTrijet2016_silvio6_atlas6.GenerateOnly.mH120.123456.root
#-rw-r--r-- 1 sdonato uniz-higgs 6.1K Aug  3 15:37 higgsCombineqq_425_lumi-27.637_r-1.000_CaloTrijet2016_silvio6_atlas6.MaxLikelihoodFit.mH120.123456.root


#file_ = ROOT.TFile.Open("/mnt/t3nfs01/data01/shome/dbrzhech/DijetScouting/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/signal_bias_test/higgsCombineqq_300_lumi-35.900_r-1.000_CaloTrijet2016_fiveparam_fiveparam.MaxLikelihoodFit.mH120.123456.root")

#fileFit = ROOT.TFile.Open("fits_trijet_silvio_2018/DijetFitResults_CaloTrijet2016.root")
#fileFit = ROOT.TFile.Open("signal_bias_silvio/qq/modexp_silvio6/dijet_combine_qq_600_lumi-27.637_CaloTrijet2016.root")



#fileFit = ROOT.TFile.Open("signal_bias_silvio/qq/atlas6_silvio4/dijet_combine_qq_460_lumi-27.637_CaloTrijet2016.root")
#fileFit = ROOT.TFile.Open("signal_bias_silvio/qq/silvio4_silvio4/dijet_combine_qq_500_lumi-0.971_CaloTrijet2016.root")
##made with text2workspace.py
#fileFit = ROOT.TFile.Open("signal_bias_silvio/qq/silvio4_silvio4/higgsCombineqq_500_lumi-0.971_r-0.498_CaloTrijet2016_silvio4_silvio4.MaxLikelihoodFit.mH120.123456.root")
#fileToys = ROOT.TFile.Open("signal_bias_silvio/qq/silvio4_silvio4/higgsCombineqq_500_lumi-0.971_r-0.498_CaloTrijet2016_silvio4_silvio4.GenerateOnly.mH120.123456.root")

fileFit = ROOT.TFile.Open("signal_bias_silvio_test/higgsCombineqq_850_lumi-0.971_r-0.145_CaloTrijet2016_silvio5_silvio4.MaxLikelihoodFit.mH120.root")
fileToys = ROOT.TFile.Open("signal_bias_silvio_test/higgsCombineqq_850_lumi-0.971_r-0.145_CaloTrijet2016_silvio5_silvio4.GenerateOnly.mH120.123456.root")


#fileFit = ROOT.TFile.Open("signal_bias_silvio/qq/atlas6_silvio5/higgsCombineqq_400_lumi-27.637_r-1.641_CaloTrijet2016_atlas6_silvio5.MaxLikelihoodFit.mH120.123456.root")
#fileToys = ROOT.TFile.Open("signal_bias_silvio/qq/atlas6_silvio5/higgsCombineqq_400_lumi-27.637_r-1.641_CaloTrijet2016_atlas6_silvio5.GenerateOnly.mH120.123456.root")

#fileFit = ROOT.TFile.Open("signal_bias_silvio/qq/silvio6_silvio5/higgsCombineqq_500_lumi-27.637_r-1.211_CaloTrijet2016_silvio6_silvio5.GenerateOnly.mH120.123456.root")
#fileToys = ROOT.TFile.Open("signal_bias_silvio/qq/silvio6_silvio5/higgsCombineqq_500_lumi-27.637_r-1.211_CaloTrijet2016_silvio6_silvio5.MaxLikelihoodFit.mH120.123456.root")



toys = fileToys.Get("toys")
try:
    toy1 = toys.Get("toy_1")
    toy1.Print()
except:
    toy1 = toys.Get("toy_asimov")
    toy1.Print()

try:
    w = fileFit.Get("w")
    if w == None:
        w = fileFit.Get("wCaloTrijet2016")
    print("\nWorkSpace:")
    w.Print()
    print()
except:
    print("CANNOT OPEN WORKSPACE!!!")

print("\toy5:")
toy1.Print()
print()

try:
    pdf_index = w.cat("pdf_index")
    pdf_index.setIndex(4)
    print("#"*20)
    print("#"*5 + "I'm selecting" +  pdf_index.getLabel() + "#"*5 )
    print("#"*20)
except:
    pass

#try:
    #shapeBkg_CaloTrijet2016_multi_CaloTrijet2016__norm = w.var("shapeBkg_CaloTrijet2016_multi_CaloTrijet2016__norm")
    #shapeBkg_CaloTrijet2016_multi_CaloTrijet2016__norm.setVal(1)
    #shapeBkg_CaloTrijet2016_multi_CaloTrijet2016__norm.setConstant(ROOT.kTrue)
#except:
    #pass

#try:
    #r = w.var("r")
    #r.setVal(1)
    #r.setConstant(ROOT.kTrue)
#except:
    #pass


#mjj = w.var("mjj")
th1x = w.var("th1x")

frame = th1x.frame()


#data.plotOn(frame)
toy1.plotOn(frame)


#w.pdf("pdf_binCaloTrijet2016").printCompactTree()

#function = w.pdf("pdf_binCaloTrijet2016")
#function = w.pdf("pdf_binCaloTrijet2016__model_bonly_")

#pdf_binCaloTrijet2016__model_bonly_


#function = w.pdf("_model_bonly_")
#function = w.pdf("model_s")
#function = w.function("pdf_binCaloTrijet2016_nuis")
#function = w.function("pdf_binCaloTrijet2016")
#function = w.function("model_s")
#function = w.function("pdf_binCaloTrijet2016")
#function = w.function("shapeBkg_CaloTrijet2016_multi_CaloTrijet2016")
#function = w.function("CaloTrijet2016_multi")
#function = w.function("pdf_binCaloTrijet2016_nuis")

function = w.function("pdf_binCaloTrijet2016_nuis")

#, ROOT.Constrain(shapeBkg_CaloTrijet2016_multi_CaloTrijet2016__norm=1


par_fiveparams=[
    'p51_CaloTrijet2016',
    'p52_CaloTrijet2016',
    'p53_CaloTrijet2016',
    'p54_CaloTrijet2016',
]

par_modexp=[
    'pm1_CaloTrijet2016',
    'pm2_CaloTrijet2016',
    'pm3_CaloTrijet2016',
    'pm4_CaloTrijet2016',
]

par_atlas=[
    'pa1_CaloTrijet2016', 
    'pa2_CaloTrijet2016',
    'pa3_CaloTrijet2016',
    'pa4_CaloTrijet2016',
]

par_atlas6=[
    'pa61_CaloTrijet2016', 
    'pa62_CaloTrijet2016',
    'pa63_CaloTrijet2016',
    'pa64_CaloTrijet2016',
    'pa65_CaloTrijet2016',
]

par_silvio6=[
    'p1s6_CaloTrijet2016', 
    'p2s6_CaloTrijet2016',
    'p3s6_CaloTrijet2016',
    'p4s6_CaloTrijet2016',
    'p5s6_CaloTrijet2016',
]

par_silvio5=[
    'p1s5_CaloTrijet2016', 
    'p2s5_CaloTrijet2016',
    'p3s5_CaloTrijet2016',
    'p4s5_CaloTrijet2016',
]

par_silvio4=[
    'p1s4_CaloTrijet2016', 
    'p2s4_CaloTrijet2016',
    'p3s4_CaloTrijet2016',
]

pdf_index_value = pdf_index.getIndex()

if pdf_index_value==0:
    funct_param = par_modexp
elif pdf_index_value==1:
    funct_param = par_fiveparams
elif pdf_index_value==2:
    funct_param = par_atlas
elif pdf_index_value==3:
    funct_param = par_atlas6
elif pdf_index_value==4:
    funct_param = par_silvio4
elif pdf_index_value==5:
    funct_param = par_silvio5
elif pdf_index_value==6:
    funct_param = par_silvio6



pdf_index_value = pdf_index.getIndex()
for par in (par_silvio4+par_silvio5+par_silvio6+par_atlas+par_atlas6+par_fiveparams+par_modexp):
    if "CaloTrijet2016" in par:
        if par in funct_param:
            print("par: "+par)
            var = w.var(par)
            print("was "+str(var.isConstant())+". Now I set it to FALSE")
            var.setConstant(ROOT.kFALSE)
        else:
            print("par: "+par)
            var = w.var(par)
            print("was "+str(var.isConstant())+". Now I set it to TRUE")
            var.setConstant(ROOT.kTRUE)

#function.fitTo(toy1,ROOT.RooFit.Range("Full"),ROOT.RooFit.Extended(True),ROOT.RooFit.Offset(True),ROOT.RooFit.Strategy(2),ROOT.RooFit.PrintLevel(0)) 


w.var("jer").setConstant(ROOT.kTRUE)
w.var("jes").setConstant(ROOT.kTRUE)
#w.var("lumi").setConstant(ROOT.kTRUE)
#w.var("jer_In").setConstant(ROOT.kTRUE)
#w.var("jes_In").setConstant(ROOT.kTRUE)
#w.var("pm1_CaloTrijet2016").setVal(-620)
#w.var("pm1_CaloTrijet2016").setVal(-530)

r = w.var("r")
r.setRange(-20,20)

nll = function.createNLL(toy1,ROOT.RooFit.Range("Full"),ROOT.RooFit.Extended(True),ROOT.RooFit.Offset(True))
m2 = ROOT.RooMinimizer(nll)
m2.setPrintLevel(2)
m2.setPrintEvalErrors(2)
m2.setStrategy(0)
m2.setMaxFunctionCalls(100000 * 10000)
m2.setMaxIterations(100000 * 10000)
migrad_status = m2.minimize('Minuit2','migrad')


shapeSig_CaloTrijet2016_CaloTrijet2016_qq_morph = w.pdf("shapeSig_CaloTrijet2016_CaloTrijet2016_qq_morph")
shapeBkg_CaloTrijet2016_multi_CaloTrijet2016 = w.pdf("shapeBkg_CaloTrijet2016_multi_CaloTrijet2016")

n_exp_final_binCaloTrijet2016_proc_CaloTrijet2016_multi = w.function("n_exp_final_binCaloTrijet2016_proc_CaloTrijet2016_multi")
n_exp_binCaloTrijet2016_proc_CaloTrijet2016_qq = w.function("n_exp_final_binCaloTrijet2016_proc_CaloTrijet2016_multi")


#c1.SetLogy()
function.plotOn(frame)
function.plotOn(frame,ROOT.RooFit.Components("shapeBkg_CaloTrijet2016_multi_CaloTrijet2016"),ROOT.RooFit.LineStyle(ROOT.kDashed), ROOT.RooFit.Normalization(1,ROOT.RooAbsReal.RelativeExpected) )
function.plotOn(frame,ROOT.RooFit.Components("shapeSig_CaloTrijet2016_CaloTrijet2016_qq_morph"),ROOT.RooFit.LineStyle(ROOT.kDashed), ROOT.RooFit.Normalization(1,ROOT.RooAbsReal.RelativeExpected) )
frame.Draw("")


#par.isConstant()
#par.setConstant(ROOT.kTRUE)


#r.Print()
#shapeBkg_CaloTrijet2016_multi_CaloTrijet2016__norm.Print()


print("pdf index: ", pdf_index.getIndex() )
pdf_index.Print()

c1.Update()
c1.Modify()
