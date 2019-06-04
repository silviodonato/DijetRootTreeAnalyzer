##################### Background Only #################################

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_alt5_alt5 -l 1992 --xsec 10  --gen-pdf alt5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_nom5_alt5 -l 1992 --xsec 10  --gen-pdf nom5     --fit-pdf alt5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0

python python/PlotBias.py -c config/dijet_silvio_bias.config -m qq -d biasBkgOnly_nom5_nom5 -l 1992 --xsec 10  --gen-pdf nom5     --fit-pdf nom5  -b CaloTrijet2016  --mass range\(300,601,50\) -r 0
