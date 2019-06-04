#include"TString.h"
#include"TChain.h"
#include"TTree.h"
#include"TFile.h"
#include"TH1F.h"
#include"TTreeFormula.h"
#include <iostream>

void skimAndMergeFile(TString inputFiles, TString outputFile){
    cout << "I'm doing "<< outputFile << endl;
    TFile* fileout = new TFile(outputFile,"recreate");
    TChain* tree = new TChain("rootTupleTree/tree");
    tree->Add(inputFiles);

    fileout->cd();
    int entries = tree->GetEntries();
    if(entries<=0) {
        cout<<"No entries in file "<<inputFiles<<endl;
        throw 1;
    }
    TTree* newTree = tree->CloneTree(0);

    TTreeFormula* cut = new TTreeFormula("cut","isr_pt>40 && abs(jet1_eta)<2.4 && abs(jet2_eta)<2.4 && abs(isr_eta)<2.4",tree);
    
   for(int i=0; i<tree->GetEntries(); i++){
        tree->GetEntry(i);
        cut->UpdateFormulaLeaves();
        if(cut->EvalInstance()){
            newTree->Fill();
        }
    }
    newTree->Write();

    /// Add histogram with Count ///
    TH1F* Count = new TH1F("Count","Count",1,0,1);
    Count->SetBinContent(1,entries);
    Count->Write();
    fileout->Close();
}

void skim(){
    skimAndMergeFile("../data_trig_eff_eta2.5.root", "../data_trig_eff_eta2.5_skim_40.root");
}