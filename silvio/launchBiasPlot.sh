export TOYS=100
export XSECT=10

##################### 5 sigma Signal + background #################################

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d bias_t$TOYS_xs$XSECT_alt5_alt5 -l 1777 --xsec $XSECT  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) --asymptotic-file  cards_qq_freq/xsecUL_Asymptotic_qq_CaloTrijet2016.root

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d bias_t$TOYS_xs$XSECT_nom5_alt5 -l 1777 --xsec $XSECT  --gen-pdf nom5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) --asymptotic-file  cards_qq_freq/xsecUL_Asymptotic_qq_CaloTrijet2016.root

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d bias_t$TOYS_xs$XSECT_nom5_nom5 -l 1777 --xsec $XSECT  --gen-pdf nom5     --fit-pdf nom5  -b CaloTrijet2016  --mass range\(300,601,50\) --asymptotic-file  cards_qq_freq/xsecUL_Asymptotic_qq_CaloTrijet2016.root

##################### Background Only #################################

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_alt5_alt5 -l 1777 --xsec $XSECT  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_nom5_alt5 -l 1777 --xsec $XSECT  --gen-pdf nom5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_nom5_nom5 -l 1777 --xsec $XSECT  --gen-pdf nom5     --fit-pdf nom5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0
