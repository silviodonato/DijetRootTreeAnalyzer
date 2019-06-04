##################### Fit #################################

mkdir -p biasTest

python python/BinnedFit.py -c config/dijet_isr_DijetFisherAlt5.config -l 1777  -b CaloTrijet2016 -d biasTest/ --fit-spectrum inputs/full.root 

##################### Background Only #################################

python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasTest -l 1.777 --xsec 10 --gen-pdf alt5     --fit-pdf alt5 -t 100 -i biasTest/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass 450 -r 0 

####################### plot #############################3

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d biasTest -l 1777 --xsec 10  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass 450 -r 0


##################### Signal+Background Only #################################

python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasTest -l 1.777 --xsec 10 --gen-pdf alt5     --fit-pdf alt5 -t 100 -i biasTest/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass 450 --asymptotic-file  cards_qq_freq/xsecUL_Asymptotic_qq_CaloTrijet2016.root

####################### plot #############################3

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d biasTest -l 1777 --xsec 10  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass 450 --asymptotic-file  cards_qq_freq/xsecUL_Asymptotic_qq_CaloTrijet2016.root


###########################################3


python python/WriteDataCard.py -m qq --mass 450 -i biasTest/DijetFitResults_CaloTrijet2016.root -l 1777.000000 -c config/dijet_silvio_bias.config -b CaloTrijet2016 -d . inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root inputs/full.root --xsec 10.000000  --jesUp inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016_JESUP.root --jesDown inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016_JESDOWN.root --jerUp inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016_JERUP.root --jerDown inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016_JERDOWN.root --multi

mv dijet_combine_qq_450_lumi-1.777_CaloTrijet2016.* biasTest_810

cd biasTest_810 && combine -M GenerateOnly dijet_combine_qq_450_lumi-1.777_CaloTrijet2016.txt -n qq_450_lumi-1.777_r-5.518_CaloTrijet2016_alt5_alt5 --rMin -100 --rMax 100 --setParameters pdf_index=14 --freezeParameters pdf_index --toysFrequentist --saveToys --expectSignal 5.518 -t 100

cd biasTest_810 && combine -M FitDiagnostics --robustFit=1 dijet_combine_qq_450_lumi-1.777_CaloTrijet2016.txt -n qq_450_lumi-1.777_r-5.518_CaloTrijet2016_alt5_alt5 --toysFile higgsCombineqq_450_lumi-1.777_r-5.518_CaloTrijet2016_alt5_alt5.GenerateOnly.mH120.123456.root -t 100 --rMin -100 --rMax 100 --setParameters pdf_index=14 --freezeParameters pdf_index,p51_CaloTrijet2016,p52_CaloTrijet2016,p53_CaloTrijet2016,p54_CaloTrijet2016,pm1_CaloTrijet2016,pm2_CaloTrijet2016,pm3_CaloTrijet2016,pm4_CaloTrijet2016,pa1_CaloTrijet2016,pa2_CaloTrijet2016,pa3_CaloTrijet2016,pa4_CaloTrijet2016,pa61_CaloTrijet2016,pa62_CaloTrijet2016,pa63_CaloTrijet2016,pa64_CaloTrijet2016,pa65_CaloTrijet2016,p1s4_CaloTrijet2016,p2s4_CaloTrijet2016,p3s4_CaloTrijet2016,p1s5_CaloTrijet2016,p2s5_CaloTrijet2016,p3s5_CaloTrijet2016,p4s5_CaloTrijet2016,p1s6_CaloTrijet2016,p2s6_CaloTrijet2016,p3s6_CaloTrijet2016,p4s6_CaloTrijet2016,p5s6_CaloTrijet2016,p7nom1_CaloTrijet2016,p7nom2_CaloTrijet2016,p7nom3_CaloTrijet2016,p7nom4_CaloTrijet2016,p7nom5_CaloTrijet2016,p7nom6_CaloTrijet2016,p6nom1_CaloTrijet2016,p6nom2_CaloTrijet2016,p6nom3_CaloTrijet2016,p6nom4_CaloTrijet2016,p6nom5_CaloTrijet2016,p5nom1_CaloTrijet2016,p5nom2_CaloTrijet2016,p5nom3_CaloTrijet2016,p5nom4_CaloTrijet2016,p4nom1_CaloTrijet2016,p4nom2_CaloTrijet2016,p4nom3_CaloTrijet2016,p3nom1_CaloTrijet2016,p3nom2_CaloTrijet2016,p7alt1_CaloTrijet2016,p7alt2_CaloTrijet2016,p7alt3_CaloTrijet2016,p7alt4_CaloTrijet2016,p7alt5_CaloTrijet2016,p7alt6_CaloTrijet2016,p6alt1_CaloTrijet2016,p6alt2_CaloTrijet2016,p6alt3_CaloTrijet2016,p6alt4_CaloTrijet2016,p6alt5_CaloTrijet2016,p4alt1_CaloTrijet2016,p4alt2_CaloTrijet2016,p4alt3_CaloTrijet2016,p3alt1_CaloTrijet2016,p3alt2_CaloTrijet2016 --cminDefaultMinimizerTolerance 9.99999975e-02 --cminDefaultMinimizerStrategy 0 --minos poi --saveWorkspace

cd /work/sdonato/scoutingAnalysis/combine/CMSSW_8_1_0/src/CMSDIJET





