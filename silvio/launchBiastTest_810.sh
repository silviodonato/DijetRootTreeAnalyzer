##################### Fit #################################

mkdir -p biasTest_810

python python/BinnedFit.py -c config/dijet_isr_DijetFisherAlt5.config -l 1777  -b CaloTrijet2016 -d biasTest_810/ --fit-spectrum inputs/full.root 

##################### Background Only #################################

python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d biasTest_810 -l 1.777 --xsec 10 --gen-pdf alt5     --fit-pdf alt5 -t 100 -i biasTest_810/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass 450 -r 0 

####################### plot #############################3

python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d biasTest_810 -l 1777 --xsec 10  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass 450 -r 0


##################### Signal+Background Only #################################

python python/RunBias810.py -c config/dijet_silvio_bias.config -m qq -d biasTest_810 -l 1.777 --xsec 10 --gen-pdf alt5     --fit-pdf alt5 -t 100 -i biasTest_810/DijetFitResults_CaloTrijet2016.root -b CaloTrijet2016 --rMin -100 --rMax 100 --mass 450 --asymptotic-file  cards_qq_freq/xsecUL_Asymptotic_qq_CaloTrijet2016.root

####################### plot #############################3

python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d biasTest_810 -l 1777 --xsec 10  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass 450 --asymptotic-file  cards_qq_freq/xsecUL_Asymptotic_qq_CaloTrijet2016.root


###########################################3


