#include "TF1.h"
#include "TH1D.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TH2F.h"
#include "TTree.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TPaveText.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TStyle.h"
#include "TChain.h"
#include <iostream>
#include <fstream>
#include "TSystem.h"
#include "TROOT.h"
#include "TH1.h"

 void MakePrediction(){

   TFile *fMC = TFile::Open("root://eosuser-internal.cern.ch//eos/user/w/woodson/dijet/histos_MC_pythia_1530.root","READ");
  
   TFile *fdata = TFile::Open("root://eosuser-internal.cern.ch//eos/user/w/woodson/dijet/small_tree_2017.root","READ");

  TH1D *h_ratio_MC = (TH1D*)(fMC->Get("h_ratio_MC"));
  TF1 *fun = h_ratio_MC->GetFunction("fun");

  TH1D *h_mjj,*h_mjj_high,*h_mjj_prediction,*h_ratio_Data,*h_mjj_prediction_1GeVbin,*h_mjj_prediction_1GeVbin_plus_sigma, *h_mjj_prediction_1GeVbin_minus_sigma,*h_mjj_1GeVbin,*h_mjj_high_1GeVbin,*h_Double_ratio ;

   const int nMassBins = 103;   
   double massBoundaries[nMassBins+1] = {1, 3, 6, 10, 16, 23, 31, 40, 50, 61, 74, 88, 103, 119, 137, 156, 176, 197, 220, 244, 270, 296, 325,
     354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000, 1058, 1118, 1181, 1246, 1313, 1383, 1455, 1530, 1607,
     1687,1770, 1856, 1945, 2037, 2132, 2231, 2332, 2438, 2546, 2659, 2775, 2895, 3019, 3147, 3279, 3416, 3558, 3704, 3854, 4010, 4171, 4337, 
     4509,
     4686, 4869, 5058, 5253, 5455, 5663, 5877, 6099, 6328, 6564, 6808, 7060, 7320, 7589, 7866, 8152, 8447, 8752, 9067, 9391, 9726, 10072,
     10430,
     10798, 11179, 11571, 11977, 12395, 12827, 13272, 13732, 14000};

    Char_t name[1024];

    sprintf(name,"h_mjj");
    h_mjj= new TH1D(name,"",103,massBoundaries);
    h_mjj->Sumw2();
     
    sprintf(name,"h_mjj_high");
    h_mjj_high= new TH1D(name,"",103,massBoundaries);
    h_mjj_high->Sumw2();

    sprintf(name,"h_mjj_prediction");
    h_mjj_prediction= new TH1D(name,"",103,massBoundaries);
    h_mjj_prediction->Sumw2();

    sprintf(name,"h_mjj_prediction_1GeVbin");
    h_mjj_prediction_1GeVbin= new TH1D(name,"",14000,0,14000);
    h_mjj_prediction_1GeVbin->Sumw2();
    
    sprintf(name,"h_mjj_prediction_1GeVbin_plus_sigma");
    h_mjj_prediction_1GeVbin_plus_sigma= new TH1D(name,"",14000,0,14000);
    h_mjj_prediction_1GeVbin_plus_sigma->Sumw2();
 
    sprintf(name,"h_mjj_prediction_1GeVbin_minus_sigma");
    h_mjj_prediction_1GeVbin_minus_sigma= new TH1D(name,"",14000,0,14000);
    h_mjj_prediction_1GeVbin_minus_sigma->Sumw2();
   
    sprintf(name,"h_mjj_1GeVbin");
    h_mjj_1GeVbin= new TH1D(name,"",14000,0,14000);
    h_mjj_1GeVbin->Sumw2();

    sprintf(name,"h_mjj_high_1GeVbin");
    h_mjj_high_1GeVbin= new TH1D(name,"",14000,0,14000);
    h_mjj_high_1GeVbin->Sumw2();

    sprintf(name,"h_ratio_Data");
    h_ratio_Data= new TH1D(name,"",103,massBoundaries);
    h_ratio_Data->Sumw2();

    sprintf(name,"h_Double_ratio");
    h_Double_ratio= new TH1D(name,"",103,massBoundaries);
    h_Double_ratio->Sumw2();

   double met_ov_sumet,MET, chf, nhf, cemf, nemf, muf, cm,pm, nm ,chf_j2,nhf_j2,cemf_j2,nemf_j2,muf_j2;
   double etaAK4_j1, etaAK4_j2, ptAK4_j1,ptAK4_j2, phiAK4_j1, phiAK4_j2,etaWJ_j1, etaWJ_j2, ptWJ_j1,ptWJ_j2, phiWJ_j1,phiWJ_j2, mjj, Dijet_MassAK4, deltaETAjj, deltaPHIjj,cm_j2,pm_j2,nm_j2,nVtx,CosThetaStarWJ;
   double PassJSON,run,lumin,event;
   double mcut_low = 2037;		//cut filling predictions
   double mcut_low_data = 1455;     //cut filling data histograms
   


TTree *tree = (TTree*)(fdata->Get("t1"));


  
    tree->SetBranchAddress("metSig",&met_ov_sumet);
    tree->SetBranchAddress("MET",&MET); 
    tree->SetBranchAddress("chargedHadEnFrac_j1",&chf);
    tree->SetBranchAddress("neutrHadEnFrac_j1",&nhf);
    tree->SetBranchAddress("chargedElectromFrac_j1",&cemf);
    tree->SetBranchAddress("neutrElectromFrac_j1",&nemf);
    tree->SetBranchAddress("muEnFract_j1",&muf);
    tree->SetBranchAddress("chargedHadEnFrac_j2",&chf_j2);
    tree->SetBranchAddress("neutrHadEnFrac_j2",&nhf_j2);
    tree->SetBranchAddress("chargedElectromFrac_j2",&cemf_j2);
    tree->SetBranchAddress("neutrElectromFrac_j2",&nemf_j2);
    tree->SetBranchAddress("muEnFract_j2",&muf_j2);
    tree->SetBranchAddress("etaAK4_j1",&etaAK4_j1);
    tree->SetBranchAddress("etaAK4_j2",&etaAK4_j2);
    tree->SetBranchAddress("pTAK4_j1",&ptAK4_j1);
    tree->SetBranchAddress("pTAK4_j2",&ptAK4_j2);
    tree->SetBranchAddress("phiAK4_j1",&phiAK4_j1);
    tree->SetBranchAddress("phiAK4_j2",&phiAK4_j2);
    tree->SetBranchAddress("etaWJ_j1",&etaWJ_j1);
    tree->SetBranchAddress("etaWJ_j2",&etaWJ_j2);
    tree->SetBranchAddress("ptWJ_j1",&ptWJ_j1);
    tree->SetBranchAddress("ptWJ_j2",&ptWJ_j2);
    tree->SetBranchAddress("phiWJ_j1",&phiWJ_j1);
    tree->SetBranchAddress("phiWJ_j2",&phiWJ_j2);
    tree->SetBranchAddress("mjj", &mjj);
    tree->SetBranchAddress("Dijet_MassAK4", &Dijet_MassAK4);
    tree->SetBranchAddress("deltaETAjj", &deltaETAjj);
    tree->SetBranchAddress("deltaPHIjj", &deltaPHIjj);
    tree->SetBranchAddress("chargedMult_j1",&cm);
    tree->SetBranchAddress("neutrMult_j1",&nm);
    tree->SetBranchAddress("photonMult_j1",&pm);
    tree->SetBranchAddress("chargedMult_j2",&cm_j2);
    tree->SetBranchAddress("neutrMult_j2",&nm_j2);
    tree->SetBranchAddress("photonMult_j2",&pm_j2);
    tree->SetBranchAddress("nVtx",&nVtx);	
    tree->SetBranchAddress("CosThetaStarWJ",&CosThetaStarWJ);
    tree->SetBranchAddress("PassJSON",&PassJSON);   	
    tree->SetBranchAddress("run",&run);
    tree->SetBranchAddress("event",&event);
    tree->SetBranchAddress("lumi",&lumin);



	//first event loop to create the Dratio of Data vs MC and get the correction
    int nentries=(Int_t)tree->GetEntries(); 
    std::cout<<"Number of entries =  "<<nentries<<std::endl;
    for (int i=0; i<nentries; i++){    //event loop
      tree->GetEntry(i);
     if (i%1000000==0) cout << " exw ftasei sto "<< i<<"\n";
      if(chf!=0 || nhf!=0 || cemf!=0 || nemf!=0 || muf!=0 || chf_j2!=0 || nhf_j2!=0 || cemf_j2!=0 || nemf_j2!=0 || muf_j2!=0){  
       //this is necessary becasue the analyzer, when an event doesn't pass the cuts, fills all the variables with 0
       

        if(met_ov_sumet<0.5 && fabs(etaWJ_j1-etaWJ_j2)<1.3 && mjj>mcut_low_data && mjj<14000 && ptWJ_j2<6500 && ptWJ_j1<6500 && PassJSON==1){
            h_mjj->Fill(mjj);
            h_mjj_1GeVbin->Fill(mjj);
        } //end of Delta phi cut

       if(met_ov_sumet<0.5 && fabs(etaWJ_j1-etaWJ_j2)>=1.3 && fabs(etaWJ_j1-etaWJ_j2)<=2.6 && mjj>mcut_low_data && mjj<14000 && ptWJ_j2<6500 && ptWJ_j1<6500 && PassJSON==1){
            //double weight = fun->Eval(mjj);
            
             
             //weight = weight * correction; // SHMEIWSH
            h_mjj_high->Fill(mjj);
            h_mjj_high_1GeVbin->Fill(mjj);           
            } //end of Delta phi cut
      }//end of if, necessary from analyzer   
    }// end of event loop

	 // h_ratio_Data->Divide(h_mjj,h_mjj_high);


		//creating Data ratio with correct errors
		for (i=0; i<h_mjj_high->GetNbinsX(); i++){ 

			
	   if(h_mjj_high->GetBinContent(i)>0){
		double sr = h_mjj->GetBinContent(i);
		double esr = h_mjj->GetBinError(i);
		double cr =h_mjj_high->GetBinContent(i);
		double ecr =h_mjj_high->GetBinError(i);
		if(cr>0){
			h_ratio_Data->SetBinContent(i,sr/cr);
			h_ratio_Data->SetBinError(i, sqrt( pow(esr/cr,2) + pow(sr*ecr/(cr*cr),2) ) );
					}
					      }
						}	

	 // h_Double_ratio->Divide(h_ratio_Data,h_ratio_MC);         


		    //creating Double Ratio : "Data" Ratio / MC Ratio with correct errors

		for (i=0; i<h_ratio_Data->GetNbinsX(); i++){ 			
		   if(h_ratio_MC->GetBinContent(i)>0){
			double sr = h_ratio_Data->GetBinContent(i);
			double esr = h_ratio_Data->GetBinError(i);
			double cr =h_ratio_MC->GetBinContent(i);
			double ecr =h_ratio_MC->GetBinError(i);

			h_Double_ratio->SetBinContent(i,sr/cr);
			h_Double_ratio->SetBinError(i, sqrt( pow(esr/cr,2) + pow(sr*ecr/(cr*cr),2) ) );

					      }
						}	


	TF1 *pol = new TF1("pol","[0]*x+[1]",2037,7060);
	TF1 *polup = new TF1("polup","2.*[0]*x+[1]",2037,7060);
	TF1 *poldown = new TF1("poldown","[0]",2037,7060);

  
 
	  TCanvas *c5 = new TCanvas("c5","Double Ratio Fit",600,300);
	   h_Double_ratio->GetXaxis()->SetRangeUser(2037.,7060.);
	   h_Double_ratio->GetYaxis()->SetRangeUser(0.,3.);
	   //h_Double_ratio->Draw();
	   h_Double_ratio->Fit("pol","","",2037,7060);
	   //c5->Close();

	  double slope = pol->GetParameter(0);
	  double eslope = pol->GetParError(0);
	  double beta  = pol->GetParameter(1);
	  poldown->SetParameter(0,beta);
	  polup->SetParameter(0,slope);
	  polup->SetParameter(1,beta);
	  polup->SetLineColor(kGreen);
	  poldown->SetLineColor(kGreen);
	  polup->Draw("same");
	  poldown->Draw("same");
	  double correction,correctionUp,correctionDown;
	  c5->SaveAs("double_ratio_fit.pdf");
	  c5->SaveAs("double_ratio_fit.C");

	//second event loop to create the prediction
	for (int i=0; i<nentries; i++){    //event loop
	      tree->GetEntry(i);
	     if (i%1000000==0) cout << " exw ftasei sto "<< i<<"\n";
	      if(chf!=0 || nhf!=0 || cemf!=0 || nemf!=0 || muf!=0 || chf_j2!=0 || nhf_j2!=0 || cemf_j2!=0 || nemf_j2!=0 || muf_j2!=0){  
	       //this is necessary becasue the analyzer, when an event doesn't pass the cuts, fills all the variables with 0
	       

	       if(met_ov_sumet<0.5 && fabs(etaWJ_j1-etaWJ_j2)>=1.3 && fabs(etaWJ_j1-etaWJ_j2)<=2.6 && mjj>mcut_low && mjj<14000 && ptWJ_j2<6500 && ptWJ_j1<6500 && PassJSON==1){
		    //double weight = fun->Eval(mjj);
		     double weight =h_ratio_MC->Interpolate(mjj);
		     correction = beta+slope*mjj;
		     correctionUp = beta+(slope+slope)*mjj;
		     correctionDown = beta+(slope-slope)*mjj;		     
		    h_mjj_prediction->Fill(mjj,weight*correction);
		    h_mjj_prediction_1GeVbin->Fill(mjj,weight*correction);
		
		    h_mjj_prediction_1GeVbin_minus_sigma->Fill(mjj,weight*correctionUp); 
		    h_mjj_prediction_1GeVbin_plus_sigma->Fill(mjj,weight*correctionDown);
		    } //end of Delta phi cut
	       //}//|eta|<1 test cut
	      }//end of if, necessary from analyzer   
	    }// end of event loop






	TFile *fout = TFile::Open("inputs/Ratio_Method_Prediction_2017.root","RECREATE");
	

	 fout->cd();
	 h_mjj->Write();
	 h_mjj_1GeVbin->Write();
	 h_mjj_high->Write();
	 h_mjj_high_1GeVbin->Write();
	 h_mjj_prediction->Write();
	 h_ratio_Data->Write();
	 h_ratio_MC->Write();
	 h_mjj_prediction_1GeVbin->Write();
	 h_mjj_prediction_1GeVbin_plus_sigma->Write();
	 h_mjj_prediction_1GeVbin_minus_sigma->Write();
	 h_Double_ratio->Write();


	fout->Close();


}
