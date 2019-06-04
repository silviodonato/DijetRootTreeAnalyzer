##################### Background Only #################################

mkdir -p biasBkgOnly_alt5_alt5

python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_alt5_alt5 -l 1.992 --xsec 10 --gen-pdf alt5     --fit-pdf alt5 -t 100 -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass range\(300,601,50\) -r 0 --step generator --queue none

source submit_bias_study/lauch_300_alt5_alt5.sh &
source submit_bias_study/lauch_350_alt5_alt5.sh &
source submit_bias_study/lauch_400_alt5_alt5.sh &
source submit_bias_study/lauch_450_alt5_alt5.sh &
source submit_bias_study/lauch_500_alt5_alt5.sh &
source submit_bias_study/lauch_550_alt5_alt5.sh &
source submit_bias_study/lauch_600_alt5_alt5.sh && \
python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_alt5_alt5 -l 1.992 --xsec 10 --gen-pdf alt5     --fit-pdf alt5 -t 100 -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass range\(300,601,50\) -r 0 --step fit --queue short &

## nom5 vs alt5


mkdir -p biasBkgOnly_nom5_alt5

python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_nom5_alt5 -l 1.992 --xsec 10 --gen-pdf nom5     --fit-pdf alt5 -t 100 -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,601,50\) -r 0 --step generator --queue none

source submit_bias_study/lauch_300_nom5_alt5.sh &
source submit_bias_study/lauch_350_nom5_alt5.sh &
source submit_bias_study/lauch_400_nom5_alt5.sh &
source submit_bias_study/lauch_450_nom5_alt5.sh &
source submit_bias_study/lauch_500_nom5_alt5.sh &
source submit_bias_study/lauch_550_nom5_alt5.sh &
source submit_bias_study/lauch_600_nom5_alt5.sh && \
python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_nom5_alt5 -l 1.992 --xsec 10 --gen-pdf nom5     --fit-pdf alt5 -t 100 -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,601,50\) -r 0 --step fit --queue short &

## nom5 vs nom5


mkdir -p biasBkgOnly_nom5_nom5


python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_nom5_nom5 -l 1.992 --xsec 10 --gen-pdf nom5     --fit-pdf nom5 -t 100 -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,601,50\) -r 0 --step generator --queue none

source submit_bias_study/lauch_300_nom5_nom5.sh &
source submit_bias_study/lauch_350_nom5_nom5.sh &
source submit_bias_study/lauch_400_nom5_nom5.sh &
source submit_bias_study/lauch_450_nom5_nom5.sh &
source submit_bias_study/lauch_500_nom5_nom5.sh &
source submit_bias_study/lauch_550_nom5_nom5.sh &
source submit_bias_study/lauch_600_nom5_nom5.sh && \
python python/RunBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_nom5_nom5 -l 1.992 --xsec 10 --gen-pdf nom5     --fit-pdf nom5 -t 100 -i cards_qq_freq/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100  --mass range\(300,601,50\) -r 0 --step fit --queue short &
