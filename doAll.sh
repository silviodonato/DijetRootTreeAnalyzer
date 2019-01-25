mkdir -p cards_qq_freq_jets01_ten_percent_Nom4
rm -rf cards_qq_freq
ln -s cards_qq_freq_jets01_ten_percent_Nom4 cards_qq_freq

python python/BinnedFit.py -c config/dijet_isr_DijetFisherNom4.config -l 1654  -b CaloTrijet2016 -d cards_qq_freq/ --fit-spectrum inputs/full.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 500 --xsec 20

python python/RunCombine.py -m qq -d cards_qq_freq/ \
-c config/dijet_isr_DijetFisherNom4.config \
-i cards_qq_freq/DijetFitResults_CaloTrijet2016.root \
-b CaloTrijet2016 \
--rMax 100 --xsec 1 -l 1.654 \
--min-strat 0 \
--mass range\(300,1001,50\) \
--min-tol 9.99999975e-02 \
--queue short.q

i="1"
while [ $i -gt 0 ]
do
echo $i
sleep 1
i=`qstat -u sdonato | wc  -l`
done

######################################

python python/GetCombine.py -d cards_qq_freq/ -m qq --mass range\(300,1001,50\) -b CaloTrijet2016 --xsec 1 -l 1.654 && \
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 1 --xsecMax 10000 &&
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 0.0 --xsecMax 0.45 --coupling jets01



mkdir -p cards_qq_freq_jets01_ten_percent_Nom5
rm -rf cards_qq_freq
ln -fs cards_qq_freq_jets01_ten_percent_Nom5 cards_qq_freq

python python/BinnedFit.py -c config/dijet_isr_DijetFisherNom5.config -l 1654  -b CaloTrijet2016 -d cards_qq_freq/ --fit-spectrum inputs/full.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 500 --xsec 20

python python/RunCombine.py -m qq -d cards_qq_freq/ \
-c config/dijet_isr_DijetFisherNom5.config \
-i cards_qq_freq/DijetFitResults_CaloTrijet2016.root \
-b CaloTrijet2016 \
--rMax 100 --xsec 1 -l 1.654 \
--min-strat 0 \
--mass range\(300,1001,50\) \
--min-tol 9.99999975e-02 \
--queue short.q


i="1"
while [ $i -gt 0 ]
do
echo $i
sleep 1
i=`qstat -u sdonato | wc  -l`
done

######################################

python python/GetCombine.py -d cards_qq_freq/ -m qq --mass range\(300,1001,50\) -b CaloTrijet2016 --xsec 1 -l 1.654 && \
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 1 --xsecMax 10000 &&
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 0.0 --xsecMax 0.45 --coupling jets01

rm -rf cards_qq_freq_jets01_ten_percent_Nom5 && mv cards_qq_freq cards_qq_freq_jets01_ten_percent_Nom5 && ln -s cards_qq_freq_jets01_ten_percent_Nom5 cards_qq_freq

mkdir -p cards_qq_freq_jets01_ten_percent_Alt5
rm -rf cards_qq_freq
ln -s cards_qq_freq_jets01_ten_percent_Alt5 cards_qq_freq

python python/BinnedFit.py -c config/dijet_isr_DijetFisherAlt5.config -l 1654  -b CaloTrijet2016 -d cards_qq_freq/ --fit-spectrum inputs/full.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 500 --xsec 20

python python/RunCombine.py -m qq -d cards_qq_freq/ \
-c config/dijet_isr_DijetFisherAlt5.config \
-i cards_qq_freq/DijetFitResults_CaloTrijet2016.root \
-b CaloTrijet2016 \
--rMax 100 --xsec 1 -l 1.654 \
--min-strat 0 \
--mass range\(300,1001,50\) \
--min-tol 9.99999975e-02 \
--queue short.q

i="1"
while [ $i -gt 0 ]
do
echo $i
sleep 1
i=`qstat -u sdonato | wc  -l`
done

######################################

python python/GetCombine.py -d cards_qq_freq/ -m qq --mass range\(300,1001,50\) -b CaloTrijet2016 --xsec 1 -l 1.654 && \
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 1 --xsecMax 10000 &&
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 0.0 --xsecMax 0.45 --coupling jets01

rm -rf cards_qq_freq_jets01_ten_percent_Alt5 && mv cards_qq_freq cards_qq_freq_jets01_ten_percent_Alt5 && ln -s cards_qq_freq_jets01_ten_percent_Alt5 cards_qq_freq

mkdir -p cards_qq_freq_jets01_ten_percent_Alt4
rm -rf cards_qq_freq
ln -s cards_qq_freq_jets01_ten_percent_Alt4 cards_qq_freq

python python/BinnedFit.py -c config/dijet_isr_DijetFisherAlt4.config -l 1654  -b CaloTrijet2016 -d cards_qq_freq/ --fit-spectrum inputs/full.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 500 --xsec 20

python python/RunCombine.py -m qq -d cards_qq_freq/ \
-c config/dijet_isr_DijetFisherAlt4.config \
-i cards_qq_freq/DijetFitResults_CaloTrijet2016.root \
-b CaloTrijet2016 \
--rMax 100 --xsec 1 -l 1.654 \
--min-strat 0 \
--mass range\(300,1001,50\) \
--min-tol 9.99999975e-02 \
--queue short.q

i="1"
while [ $i -gt 0 ]
do
echo $i
sleep 1
i=`qstat -u sdonato | wc  -l`
done

######################################

python python/GetCombine.py -d cards_qq_freq/ -m qq --mass range\(300,1001,50\) -b CaloTrijet2016 --xsec 1 -l 1.654 && \
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 1 --xsecMax 10000 &&
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 0.0 --xsecMax 0.45 --coupling jets01

rm -rf cards_qq_freq_jets01_ten_percent_Alt4 && mv cards_qq_freq cards_qq_freq_jets01_ten_percent_Alt4 && ln -s cards_qq_freq_jets01_ten_percent_Alt4 cards_qq_freq

mkdir -p cards_qq_freq_jets01_ten_percent_Alt3
rm -rf cards_qq_freq
ln -s cards_qq_freq_jets01_ten_percent_Alt3 cards_qq_freq

python python/BinnedFit.py -c config/dijet_isr_DijetFisherAlt3.config -l 1654  -b CaloTrijet2016 -d cards_qq_freq/ --fit-spectrum inputs/full.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root  --model qq --mass 500 --xsec 20

python python/RunCombine.py -m qq -d cards_qq_freq/ \
-c config/dijet_isr_DijetFisherAlt3.config \
-i cards_qq_freq/DijetFitResults_CaloTrijet2016.root \
-b CaloTrijet2016 \
--rMax 100 --xsec 1 -l 1.654 \
--min-strat 0 \
--mass range\(300,1001,50\) \
--min-tol 9.99999975e-02 \
--queue short.q

i="1"
while [ $i -gt 0 ]
do
echo $i
sleep 1
i=`qstat -u sdonato | wc  -l`
done

######################################

python python/GetCombine.py -d cards_qq_freq/ -m qq --mass range\(300,1001,50\) -b CaloTrijet2016 --xsec 1 -l 1.654 && \
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 1 --xsecMax 10000 &&
python python/Plot1DLimit_silvio.py -d cards_qq_freq/ -m qq -b CaloTrijet2016 -l 1.654 --massMin 100 --massMax 1200  --xsecMin 0.0 --xsecMax 0.45 --coupling jets01

rm -rf cards_qq_freq_jets01_ten_percent_Alt3 && mv cards_qq_freq cards_qq_freq_jets01_ten_percent_Alt3 && ln -s cards_qq_freq_jets01_ten_percent_Alt3 cards_qq_freq


