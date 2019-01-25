mkdir -p trigger_Nom4_studies_deta1p1_full_ten_percent_blind

python python/chisquareTable.py \
-c config/dijet_isr_DijetFisherNom4.config \
-l 1536  -b CaloTrijet2016 \
-d trigger_Nom4_studies_deta1p1_full_ten_percent_blind/ \
--fit-spectrum data_deta1p1_full_ten_percent_blind.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root \
 --model qq --mass 400 --xsec 20 \
 --chi2table-create True \
 --root-out trigger_Nom4_studies_deta1p1_full_ten_percent_blind.root \
 --config-create True \
 --latex-out trigger_Nom4_studies_deta1p1_full_ten_percent_blind.tex \
 --cut-type trigger >& log_trigger_Nom4_studies_deta1p1_full_ten_percent_blind &

############################################

mkdir -p isrPt_Nom4_studies_deta1p1_full_ten_percent_blind

python python/chisquareTable.py \
-c config/dijet_isr_DijetFisherNom4.config \
-l 1536  -b CaloTrijet2016 \
-d isrPt_Nom4_studies_deta1p1_full_ten_percent_blind/ \
--fit-spectrum data_deta1p1_full_ten_percent_blind.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root \
 --model qq --mass 400 --xsec 20 \
 --chi2table-create True \
 --root-out isrPt_Nom4_studies_deta1p1_full_ten_percent_blind.root \
 --config-create True \
 --latex-out isrPt_Nom4_studies_deta1p1_full_ten_percent_blind.tex \
 --cut-type isrPtCut >& log_isrPt_Nom4_studies_deta1p1_full_ten_percent_blind &

############################################


mkdir -p trigger_Nom4_studies_deta1p1_full_ten_percent

python python/chisquareTable.py \
-c config/dijet_isr_DijetFisherNom4.config \
-l 1536  -b CaloTrijet2016 \
-d trigger_Nom4_studies_deta1p1_full_ten_percent/ \
--fit-spectrum data_deta1p1_full_ten_percent.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root \
 --model qq --mass 400 --xsec 20 \
 --chi2table-create True \
 --root-out trigger_Nom4_studies_deta1p1_full_ten_percent.root \
 --config-create True \
 --latex-out trigger_Nom4_studies_deta1p1_full_ten_percent.tex \
 --cut-type trigger >& log_trigger_Nom4_studies_deta1p1_full_ten_percent &

############################################

mkdir -p isrPt_Nom4_studies_deta1p1_full_ten_percent

python python/chisquareTable.py \
-c config/dijet_isr_DijetFisherNom4.config \
-l 1536  -b CaloTrijet2016 \
-d isrPt_Nom4_studies_deta1p1_full_ten_percent/ \
--fit-spectrum data_deta1p1_full_ten_percent.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root \
 --model qq --mass 400 --xsec 20 \
 --chi2table-create True \
 --root-out isrPt_Nom4_studies_deta1p1_full_ten_percent.root \
 --config-create True \
 --latex-out isrPt_Nom4_studies_deta1p1_full_ten_percent.tex \
 --cut-type isrPtCut >& log_isrPt_Nom4_studies_deta1p1_full_ten_percent &

################################################

mkdir -p trigger_Nom4_studies_deta1p1_full_blind

python python/chisquareTable.py \
-c config/dijet_isr_DijetFisherNom4.config \
-l 1536  -b CaloTrijet2016 \
-d trigger_Nom4_studies_deta1p1_full_blind/ \
--fit-spectrum data_deta1p1_full_blind.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root \
 --model qq --mass 400 --xsec 20 \
 --chi2table-create True \
 --root-out trigger_Nom4_studies_deta1p1_full_blind.root \
 --config-create True \
 --latex-out trigger_Nom4_studies_deta1p1_full_blind.tex \
 --cut-type trigger >& log_trigger_Nom4_studies_deta1p1_full_blind &

############################################

mkdir -p isrPt_Nom4_studies_deta1p1_full_blind

python python/chisquareTable.py \
-c config/dijet_isr_DijetFisherNom4.config \
-l 1536  -b CaloTrijet2016 \
-d isrPt_Nom4_studies_deta1p1_full_blind/ \
--fit-spectrum data_deta1p1_full_blind.root \
--signal inputs/ResonanceShapes_qq_13TeV_CaloScouting_2016.root \
 --model qq --mass 400 --xsec 20 \
 --chi2table-create True \
 --root-out isrPt_Nom4_studies_deta1p1_full_blind.root \
 --config-create True \
 --latex-out isrPt_Nom4_studies_deta1p1_full_blind.tex \
 --cut-type isrPtCut >& log_isrPt_Nom4_studies_deta1p1_full_blind &

