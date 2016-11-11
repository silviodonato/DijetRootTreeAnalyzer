python python/GetCombine.py -d cards_gaus10_freq/ -m gaus10 --mass range\(1650,7550,100\) -b PFDijet2016 --xsec 1e-1 -l 20.057
python python/Plot1DLimit.py -d cards_gaus10_freq/ -m gaus10 -b PFDijet2016 -l 20.057 --massMin 1650 --massMax 7500 --xsecMin 1e-5 --xsecMax 1e4

python python/GetCombine.py -d cards_gaus10_freq/ -m gaus10 --mass range\(1650,7550,100\) -b PFDijetbb20160mt --xsec 1e-1 -l 20.057
python python/Plot1DLimit.py -d cards_gaus10_freq/ -m gaus10 -b PFDijetbb20160mt -l 20.057 --massMin 1650 --massMax 7500 --xsecMin 1e-5 --xsecMax 1e4

python python/GetCombine.py -d cards_gaus10_freq/ -m gaus10 --mass range\(1650,7550,100\) -b PFDijetbb20161mt --xsec 1e-1 -l 20.057
python python/Plot1DLimit.py -d cards_gaus10_freq/ -m gaus10 -b PFDijetbb20161mt -l 20.057 --massMin 1650 --massMax 7500 --xsecMin 1e-5 --xsecMax 1e4

python python/GetCombine.py -d cards_gaus10_freq/ -m gaus10 --mass range\(1650,7550,100\) -b PFDijetbb20162mt --xsec 1e-1 -l 20.057
python python/Plot1DLimit.py -d cards_gaus10_freq/ -m gaus10 -b PFDijetbb20162mt -l 20.057 --massMin 1650 --massMax 7500 --xsecMin 1e-5 --xsecMax 1e4
