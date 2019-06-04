export TOYS=1000
export XSECT=10

##################### 5 sigma Signal + background #################################

python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d bias1k_alt5_alt5 -l 1777 --xsec $XSECT  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root

python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d bias1k_nom5_alt5 -l 1777 --xsec $XSECT  --gen-pdf nom5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root

python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d bias1k_nom5_nom5 -l 1777 --xsec $XSECT  --gen-pdf nom5     --fit-pdf nom5  -b CaloTrijet2016  --mass range\(300,601,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root

python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d bias1k_alt5_nom5 -l 1777 --xsec $XSECT  --gen-pdf alt5     --fit-pdf nom5  -b CaloTrijet2016  --mass range\(300,601,50\) --asymptotic-file  /work/sdonato/scoutingAnalysis/CMSSW_7_4_14/src/CMSDIJET/DijetRootTreeAnalyzer/cards_qq_freq_bak//xsecUL_Asymptotic_qq_CaloTrijet2016.root

##################### Background Only #################################

python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d bias1kBkgOnly_alt5_alt5 -l 1777 --xsec $XSECT  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0

python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d bias1kBkgOnly_nom5_alt5 -l 1777 --xsec $XSECT  --gen-pdf nom5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0

python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d bias1kBkgOnly_nom5_nom5 -l 1777 --xsec $XSECT  --gen-pdf nom5     --fit-pdf nom5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0

#python python/PlotBias810.py -c config/dijet_silvio_bias.config -m qq -d bias1kBkgOnly_alt5_nom5 -l 1777 --xsec $XSECT  --gen-pdf alt5     --fit-pdf nom5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0


