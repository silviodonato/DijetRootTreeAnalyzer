export TOYS=1000
export XSECT=10

ln -f -s /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/inputs_Silvio/output_data_th3f_fulldata_newmethod_20190406_215315_Run2016BCDEFG_0_sr.root inputs/full.root

##################### Fit #################################

mkdir -p biasTestLong_1kBkgOnly_alt5_alt5

python python/BinnedFit.py -c config/dijet_isr_DijetFisherAlt5.config -l 1777  -b CaloTrijet2016 -d biasTestLong_1kBkgOnly_alt5_alt5/ --fit-spectrum inputs/full.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 450 --xsec 20

##################### Background Only #################################


python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasTestLong_1kBkgOnly_alt5_alt5 -l 1.777 --xsec $XSECT --gen-pdf alt5     --fit-pdf alt5 -t $TOYS -i biasTestLong_1kBkgOnly_alt5_alt5/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass 450 -r 0 --step generator --no-signalSys

python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasTestLong_1kBkgOnly_alt5_alt5 -l 1.777 --xsec $XSECT --gen-pdf alt5     --fit-pdf alt5 -t $TOYS -i biasTestLong_1kBkgOnly_alt5_alt5/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass 450 -r 0 --step fit --no-signalSys

####################### plot #############################3

cd biasTestLong_1kBkgOnly_alt5_alt5 && combine -M MaxLikelihoodFit --robustFit=1 dijet_combine_qq_450_lumi-1.777_CaloTrijet2016.txt -n qq_450_lumi-1.777_r-0.000_CaloTrijet2016_alt5_alt5 --toysFile higgsCombineqq_450_lumi-1.777_r-0.000_CaloTrijet2016_alt5_alt5.GenerateOnly.mH120.123456.root -t 100 --setPhysicsModelParameterRanges r=-100,100 --setPhysicsModelParameters pdf_index=14 --freezeNuisances pdf_index,p51_CaloTrijet2016,p52_CaloTrijet2016,p53_CaloTrijet2016,p54_CaloTrijet2016,pm1_CaloTrijet2016,pm2_CaloTrijet2016,pm3_CaloTrijet2016,pm4_CaloTrijet2016,pa1_CaloTrijet2016,pa2_CaloTrijet2016,pa3_CaloTrijet2016,pa4_CaloTrijet2016,pa61_CaloTrijet2016,pa62_CaloTrijet2016,pa63_CaloTrijet2016,pa64_CaloTrijet2016,pa65_CaloTrijet2016,p1s4_CaloTrijet2016,p2s4_CaloTrijet2016,p3s4_CaloTrijet2016,p1s5_CaloTrijet2016,p2s5_CaloTrijet2016,p3s5_CaloTrijet2016,p4s5_CaloTrijet2016,p1s6_CaloTrijet2016,p2s6_CaloTrijet2016,p3s6_CaloTrijet2016,p4s6_CaloTrijet2016,p5s6_CaloTrijet2016,p7nom1_CaloTrijet2016,p7nom2_CaloTrijet2016,p7nom3_CaloTrijet2016,p7nom4_CaloTrijet2016,p7nom5_CaloTrijet2016,p7nom6_CaloTrijet2016,p6nom1_CaloTrijet2016,p6nom2_CaloTrijet2016,p6nom3_CaloTrijet2016,p6nom4_CaloTrijet2016,p6nom5_CaloTrijet2016,p5nom1_CaloTrijet2016,p5nom2_CaloTrijet2016,p5nom3_CaloTrijet2016,p5nom4_CaloTrijet2016,p4nom1_CaloTrijet2016,p4nom2_CaloTrijet2016,p4nom3_CaloTrijet2016,p3nom1_CaloTrijet2016,p3nom2_CaloTrijet2016,p7alt1_CaloTrijet2016,p7alt2_CaloTrijet2016,p7alt3_CaloTrijet2016,p7alt4_CaloTrijet2016,p7alt5_CaloTrijet2016,p7alt6_CaloTrijet2016,p6alt1_CaloTrijet2016,p6alt2_CaloTrijet2016,p6alt3_CaloTrijet2016,p6alt4_CaloTrijet2016,p6alt5_CaloTrijet2016,p4alt1_CaloTrijet2016,p4alt2_CaloTrijet2016,p4alt3_CaloTrijet2016,p3alt1_CaloTrijet2016,p3alt2_CaloTrijet2016 --minimizerTolerance 9.99999975e-02 --minimizerStrategy 0 --minos poi --saveWorkspace

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d biasTestLong_1kBkgOnly_alt5_alt5 -l 1777 --xsec $XSECT  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass 450 -r 0






