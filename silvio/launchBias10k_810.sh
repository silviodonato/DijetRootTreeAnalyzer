export TOYS=10000
export XSECT=10

##################### Fit #################################

mkdir -p cards_qq_freq

python python/BinnedFit.py -c config/dijet_isr_DijetFisherAlt5.config -l 1777  -b CaloTrijet2016 -d cards_qq_freq/ --fit-spectrum inputs/full.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 500 --xsec 20

##################### 5 sigma Signal + background #################################

mkdir -p bias10k_alt5_alt5

python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10k_alt5_alt5 -l 1.777 --xsec $XSECT --gen-pdf alt5     --fit-pdf alt5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass range\(300,701,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root --step generator --queue none

source submit_bias_study/lauch_300_alt5_alt5.sh &
source submit_bias_study/lauch_350_alt5_alt5.sh &
source submit_bias_study/lauch_400_alt5_alt5.sh &
source submit_bias_study/lauch_450_alt5_alt5.sh &
source submit_bias_study/lauch_500_alt5_alt5.sh &
source submit_bias_study/lauch_550_alt5_alt5.sh &
source submit_bias_study/lauch_600_alt5_alt5.sh && \
python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10k_alt5_alt5 -l 1.777 --xsec $XSECT --gen-pdf alt5     --fit-pdf alt5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass range\(300,701,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root --step fit --queue all &

## nom5 vs alt5


mkdir -p bias10k_nom5_alt5

python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10k_nom5_alt5 -l 1.777 --xsec $XSECT --gen-pdf nom5     --fit-pdf alt5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root --step generator --queue none

source submit_bias_study/lauch_300_nom5_alt5.sh &
source submit_bias_study/lauch_350_nom5_alt5.sh &
source submit_bias_study/lauch_400_nom5_alt5.sh &
source submit_bias_study/lauch_450_nom5_alt5.sh &
source submit_bias_study/lauch_500_nom5_alt5.sh &
source submit_bias_study/lauch_550_nom5_alt5.sh &
source submit_bias_study/lauch_600_nom5_alt5.sh && \
python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10k_nom5_alt5 -l 1.777 --xsec $XSECT --gen-pdf nom5     --fit-pdf alt5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root --step fit --queue all &

## nom5 vs nom5


mkdir -p bias10k_nom5_nom5


python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10k_nom5_nom5 -l 1.777 --xsec $XSECT --gen-pdf nom5     --fit-pdf nom5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root --step generator --queue none

source submit_bias_study/lauch_300_nom5_nom5.sh &
source submit_bias_study/lauch_350_nom5_nom5.sh &
source submit_bias_study/lauch_400_nom5_nom5.sh &
source submit_bias_study/lauch_450_nom5_nom5.sh &
source submit_bias_study/lauch_500_nom5_nom5.sh &
source submit_bias_study/lauch_550_nom5_nom5.sh &
source submit_bias_study/lauch_600_nom5_nom5.sh && \
python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10k_nom5_nom5 -l 1.777 --xsec $XSECT --gen-pdf nom5     --fit-pdf nom5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root --step fit --queue all &


##################### Background Only #################################

mkdir -p bias10kBkgOnly_alt5_alt5

python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10kBkgOnly_alt5_alt5 -l 1.777 --xsec $XSECT --gen-pdf alt5     --fit-pdf alt5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass range\(300,701,50\) -r 0 --step generator --queue none

source submit_bias_study/lauch_300_alt5_alt5.sh &
source submit_bias_study/lauch_350_alt5_alt5.sh &
source submit_bias_study/lauch_400_alt5_alt5.sh &
source submit_bias_study/lauch_450_alt5_alt5.sh &
source submit_bias_study/lauch_500_alt5_alt5.sh &
source submit_bias_study/lauch_550_alt5_alt5.sh &
source submit_bias_study/lauch_600_alt5_alt5.sh && \
python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10kBkgOnly_alt5_alt5 -l 1.777 --xsec $XSECT --gen-pdf alt5     --fit-pdf alt5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass range\(300,701,50\) -r 0 --step fit --queue all &

## nom5 vs alt5


mkdir -p bias10kBkgOnly_nom5_alt5

python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10kBkgOnly_nom5_alt5 -l 1.777 --xsec $XSECT --gen-pdf nom5     --fit-pdf alt5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) -r 0 --step generator --queue none

source submit_bias_study/lauch_300_nom5_alt5.sh &
source submit_bias_study/lauch_350_nom5_alt5.sh &
source submit_bias_study/lauch_400_nom5_alt5.sh &
source submit_bias_study/lauch_450_nom5_alt5.sh &
source submit_bias_study/lauch_500_nom5_alt5.sh &
source submit_bias_study/lauch_550_nom5_alt5.sh &
source submit_bias_study/lauch_600_nom5_alt5.sh && \
python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10kBkgOnly_nom5_alt5 -l 1.777 --xsec $XSECT --gen-pdf nom5     --fit-pdf alt5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) -r 0 --step fit --queue all &

## nom5 vs nom5


mkdir -p bias10kBkgOnly_nom5_nom5


python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10kBkgOnly_nom5_nom5 -l 1.777 --xsec $XSECT --gen-pdf nom5     --fit-pdf nom5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) -r 0 --step generator --queue none

source submit_bias_study/lauch_300_nom5_nom5.sh &
source submit_bias_study/lauch_350_nom5_nom5.sh &
source submit_bias_study/lauch_400_nom5_nom5.sh &
source submit_bias_study/lauch_450_nom5_nom5.sh &
source submit_bias_study/lauch_500_nom5_nom5.sh &
source submit_bias_study/lauch_550_nom5_nom5.sh &
source submit_bias_study/lauch_600_nom5_nom5.sh && \
python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10kBkgOnly_nom5_nom5 -l 1.777 --xsec $XSECT --gen-pdf nom5     --fit-pdf nom5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) -r 0 --step fit --queue all &

## alt5 vs nom5


mkdir -p bias10k_alt5_nom5

python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10k_alt5_nom5 -l 1.777 --xsec $XSECT --gen-pdf alt5     --fit-pdf nom5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root --step generator --queue none

source submit_bias_study/lauch_300_alt5_nom5.sh &
source submit_bias_study/lauch_350_alt5_nom5.sh &
source submit_bias_study/lauch_400_alt5_nom5.sh &
source submit_bias_study/lauch_450_alt5_nom5.sh &
source submit_bias_study/lauch_500_alt5_nom5.sh &
source submit_bias_study/lauch_550_alt5_nom5.sh &
source submit_bias_study/lauch_600_alt5_nom5.sh && \
python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d bias10k_alt5_nom5 -l 1.777 --xsec $XSECT --gen-pdf alt5     --fit-pdf nom5 -t $TOYS -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,701,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root --step fit --queue all &
