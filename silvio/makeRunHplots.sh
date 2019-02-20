python python/BinnedFit.py -c config/dijet_isr_DijetFisherNom5.config -l 18321  -b CaloTrijet2016 -d fits_trijet_2018/ --fit-spectrum data_deta1p1_full_blind.root --signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 400 --xsec 20
cp fits_trijet_2018//fit_mjj_Full_CaloTrijet2016.pdf fit_mjj_Full_CaloTrijet2016_woRunH_blind.pdf


python python/BinnedFit.py -c config/dijet_isr_DijetFisherNom5.config -l 21190  -b CaloTrijet2016 -d fits_trijet_2018/ --fit-spectrum data_wRunH_deta1p1_full_blind.root --signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 400 --xsec 20
cp fits_trijet_2018//fit_mjj_Full_CaloTrijet2016.pdf fit_mjj_Full_CaloTrijet2016_wRunH_blind.pdf


python python/BinnedFit.py -c config/dijet_isr_DijetFisherNom5.config -l 1654  -b CaloTrijet2016 -d fits_trijet_2018/ --fit-spectrum data_deta1p1_full_ten_percent.root --signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 400 --xsec 20
cp fits_trijet_2018//fit_mjj_Full_CaloTrijet2016.pdf fit_mjj_Full_CaloTrijet2016_woRunH_ten_percent.pdf


python python/BinnedFit.py -c config/dijet_isr_DijetFisherNom5.config -l 1992  -b CaloTrijet2016 -d fits_trijet_2018/ --fit-spectrum data_wRunH_deta1p1_full_ten_percent.root --signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 400 --xsec 20
cp fits_trijet_2018//fit_mjj_Full_CaloTrijet2016.pdf fit_mjj_Full_CaloTrijet2016_wRunH_ten_percent.pdf
