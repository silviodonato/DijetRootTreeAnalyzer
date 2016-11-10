
mkdir -p fits_2016_11_09/PFDijet2016_Full/
python python/BinnedFit.py -c config/dijet.config -l 20057 -s inputs/ResonanceShapes_gaus10_13TeV_Spring16.root inputs/20fb_btag.root -b PFDijet2016 -d fits_2016_11_09/PFDijet2016_Full/ --fit-spectrum

mkdir -p fits_2016_11_09/PFDijetbb20160mt_Full/
python python/BinnedFit.py -c config/dijet.config -l 20057 -s inputs/ResonanceShapes_gaus10_13TeV_Spring16.root inputs/20fb_btag.root -b PFDijetbb20160mt -d fits_2016_11_09/PFDijetbb20160mt_Full/ --fit-spectrum

mkdir -p fits_2016_11_09/PFDijetbb20161mt_Full/
python python/BinnedFit.py -c config/dijet.config -l 20057 -s inputs/ResonanceShapes_gaus10_13TeV_Spring16.root inputs/20fb_btag.root -b PFDijetbb20161mt -d fits_2016_11_09/PFDijetbb20161mt_Full/ --fit-spectrum

mkdir -p fits_2016_11_09/PFDijetbb20162mt_Full/
python python/BinnedFit.py -c config/dijet.config -l 20057 -s inputs/ResonanceShapes_gaus10_13TeV_Spring16.root inputs/20fb_btag.root -b PFDijetbb20162mt -d fits_2016_11_09/PFDijetbb20162mt_Full/ --fit-spectrum


#root fits_2016_11_09/PFDijetbb20160mt_Full//fit_mjj_Full_PFDijetbb20160mt.C fits_2016_11_09/PFDijetbb20161mt_Full//fit_mjj_Full_PFDijetbb20161mt.C fits_2016_11_09/PFDijetbb20162mt_Full//fit_mjj_Full_PFDijetbb20162mt.C
