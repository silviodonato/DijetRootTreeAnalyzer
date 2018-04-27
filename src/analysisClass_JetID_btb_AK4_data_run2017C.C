#define analysisClass_cxx
#include "analysisClass.h"
#include <TH2.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <TVector3.h>
#include "TRandom.h"

analysisClass::analysisClass(string * inputList, string * cutFile, string * treeName, string * outputFileName, string * cutEfficFile)
  :baseClass(inputList, cutFile, treeName, outputFileName, cutEfficFile)
{
  std::cout << "analysisClass::analysisClass(): begins " << std::endl;

  // For JECs
  if( int(getPreCutValue1("useJECs"))==1 ) //it's not implemented
  {
    
    std::string L1Path = "data/Spring16_25nsV2_MC/Spring16_25nsV2_MC_L1FastJet_AK4PFchs.txt";
    std::string L2Path = "data/Spring16_25nsV2_MC/Spring16_25nsV2_MC_L2Relative_AK4PFchs.txt"; 
    std::string L3Path = "data/Spring16_25nsV2_MC/Spring16_25nsV2_MC_L3Absolute_AK4PFchs.txt";
    std::string L1DATAPath = "data/Spring16_25nsV2_DATA/Spring16_25nsV2_DATA_L1FastJet_AK4PFchs.txt";
    std::string L2DATAPath = "data/Spring16_25nsV2_DATA/Spring16_25nsV2_DATA_L2Relative_AK4PFchs.txt"; 
    std::string L3DATAPath = "data/Spring16_25nsV2_DATA/Spring16_25nsV2_DATA_L3Absolute_AK4PFchs.txt";
    std::string L2L3ResidualPath = "data/Spring16_25nsV2_DATA/Spring16_25nsV2_DATA_L2Residual_AK4PFchs.txt";

    L1Par = new JetCorrectorParameters(L1Path);
    L2Par = new JetCorrectorParameters(L2Path);
    L3Par = new JetCorrectorParameters(L3Path);
    L1DATAPar = new JetCorrectorParameters(L1DATAPath);
    L2DATAPar = new JetCorrectorParameters(L2DATAPath);
    L3DATAPar = new JetCorrectorParameters(L3DATAPath);
    L2L3Residual = new JetCorrectorParameters(L2L3ResidualPath);

    std::vector<JetCorrectorParameters> vPar;
    std::vector<JetCorrectorParameters> vPar_data;
    vPar.push_back(*L1Par);
    vPar.push_back(*L2Par);
    vPar.push_back(*L3Par);
   
    //residuals are applied only to data
    vPar_data.push_back(*L1DATAPar);
    vPar_data.push_back(*L2DATAPar);
    vPar_data.push_back(*L3DATAPar);
    vPar_data.push_back(*L2L3Residual);

    JetCorrector = new FactorizedJetCorrector(vPar); assert(JetCorrector);
    JetCorrector_data = new FactorizedJetCorrector(vPar_data); assert(JetCorrector_data);

    //uncertainty
    unc = new JetCorrectionUncertainty("data/Spring16_25nsV2_DATA/Spring16_25nsV2_DATA_Uncertainty_AK4PFchs.txt");

  }
  
  std::cout << "analysisClass::analysisClass(): ends " << std::endl;
}

analysisClass::~analysisClass()
{
  std::cout << "analysisClass::~analysisClass(): begins " << std::endl;

  std::cout << "analysisClass::~analysisClass(): ends " << std::endl;
}

void analysisClass::Loop()
{
   std::cout << "analysisClass::Loop() begins" <<std::endl;   
    
   if (fChain == 0) return;
   
   //////////book histos here

   /////////initialize variables

   Long64_t nentries = fChain->GetEntriesFast();
   std::cout << "analysisClass::Loop(): nentries = " << nentries << std::endl;   

   ////// The following ~7 lines have been taken from rootNtupleClass->Loop() /////
   ////// If the root version is updated and rootNtupleClass regenerated,     /////
   ////// these lines may need to be updated.                                 /////    
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<nentries;jentry=jentry+10) {   //takes every 10th entry
   //for (Long64_t jentry=0; jentry<1000;jentry++) {   
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     if(jentry < 10 || jentry%1000000 == 0) std::cout << "analysisClass::Loop(): jentry = " << jentry << std::endl;   
     // if (Cut(ientry) < 0) continue;

     ////////////////////// User's code starts here ///////////////////////

     ///Stuff to be done for every event
     size_t no_jets_AK4=jetPtAK4->size();

     resetCuts();     
    
     //== Fill Variables for AK4 ==
     if(no_jets_AK4 >=2){

 	bool cut1 = (jetPtAK4->at(0) > getPreCutValue1("pt0Cut"));
        bool cut2 = (jetPtAK4->at(1) > getPreCutValue1("pt1Cut"));
            
        if(cut1 && cut2){

           if(dPhijjAK4 > getPreCutValue1("deltaPhijj")){  //back-to-back

	    bool tight_1 = true; bool tight_2=true; bool extracut_27_3_1=true; bool extracut_27_3_2 =true; bool extracut_3_5_1 =true; bool extracut_3_5_2 =true; bool allJetIDs=true;
	    if(getPreCutValue1("tightJetID")==1){  // all JetIDs

	      tight_1 = (abs(jetEtaAK4->at(0))<=2.7 && idTAK4->at(0) >= getPreCutValue1("tightJetID") && jetCemfAK4->at(0)<0.8);
	      extracut_27_3_1 = (abs(jetEtaAK4->at(0))> 2.7 && abs(jetEtaAK4->at(0))<=3.0 && neMultAK4->at(0)>2 && jetNemfAK4->at(0)<0.99);
	      extracut_3_5_1 = (abs(jetEtaAK4->at(0))> 3.0 && abs(jetEtaAK4->at(0))<=5.0 && jetNemfAK4->at(0)< 0.9 && neMultAK4->at(0)>10 && jetNhfAK4->at(0)>0.02);
	      tight_2 = (abs(jetEtaAK4->at(1))<=2.7 && idTAK4->at(1) >= getPreCutValue1("tightJetID") && jetCemfAK4->at(1)<0.8);
	      extracut_27_3_2 = (abs(jetEtaAK4->at(1))> 2.7 && abs(jetEtaAK4->at(1))<=3.0 && neMultAK4->at(1)>2 && jetNemfAK4->at(1)<0.99);
	      extracut_3_5_2 = (abs(jetEtaAK4->at(1))> 3.0 && abs(jetEtaAK4->at(1))<=5.0 && jetNemfAK4->at(1)< 0.9 && neMultAK4->at(1)>10 && jetNhfAK4->at(1)>0.02);
 	      allJetIDs = (tight_1 && tight_2) || (tight_1 && extracut_27_3_2) || (tight_1 && extracut_3_5_2) || (extracut_27_3_1 && tight_2) || (extracut_27_3_1 && extracut_27_3_2) || (extracut_27_3_1 && extracut_3_5_2) || (extracut_3_5_1 && tight_2) || (extracut_3_5_1 && extracut_27_3_2) || (extracut_3_5_1 && extracut_3_5_2);
	    }

	    if(allJetIDs){

	        fillVariableWithValue("run",runNo);     
	        fillVariableWithValue("event",evtNo);     
	        fillVariableWithValue("lumi",lumi);     
	        fillVariableWithValue("nVtx",nvtx); 
                if( int(getPreCutValue1("IsData"))==1) fillVariableWithValue ( "PassJSON", passJSON (runNo, lumi, int(getPreCutValue1("IsData"))==1 ));  //if JSON file in the cutfile is used, then uncommand it!!!  

	        // Trigger
	        //int NtriggerBits = triggerResult->size();
	        //if( NtriggerBits > 0) fillVariableWithValue("passHLT",triggerResult->at(0));// HLT_PFHT900_v*  

		 fillVariableWithValue("nJet", no_jets_AK4);
                 fillVariableWithValue("met",met);
                 fillVariableWithValue("metSig",metSig);
    		 fillVariableWithValue("passFilterGoodVtx",passFilterGoodVtx);
                 //fillVariableWithValue("HT",htAK4);
                 fillVariableWithValue("DijetMassAK4",mjjAK4);
		 fillVariableWithValue( "deltaPhi", dPhijjAK4);
		 //fillVariableWithValue( "IdTight_j1", idTAK4->at(0));
		 fillVariableWithValue( "pT_j1", jetPtAK4->at(0));
		 fillVariableWithValue( "eta_j1", jetEtaAK4->at(0));
		 fillVariableWithValue( "phi_j1", jetPhiAK4->at(0));
		 fillVariableWithValue( "neutrHadEnFrac_j1", jetNhfAK4->at(0));
		 fillVariableWithValue( "chargedHadEnFrac_j1", jetChfAK4->at(0));
		 fillVariableWithValue( "photonEnFrac_j1", jetPhfAK4->at(0));
		 fillVariableWithValue( "eleEnFract_j1", jetElfAK4->at(0));
		 fillVariableWithValue( "muEnFract_j1", jetMufAK4->at(0));
                 fillVariableWithValue( "neutrElectromFrac_j1", jetNemfAK4->at(0));
                 fillVariableWithValue( "chargedElectromFrac_j1", jetCemfAK4->at(0));
		 fillVariableWithValue( "chargedMult_j1", chMultAK4->at(0));
           	 fillVariableWithValue( "neutrMult_j1", neMultAK4->at(0));
        	 fillVariableWithValue( "photonMult_j1", phoMultAK4->at(0));
			
		 //fillVariableWithValue( "IdTight_j2", idTAK4->at(1));
		 fillVariableWithValue( "pT_j2", jetPtAK4->at(1));
		 fillVariableWithValue( "eta_j2", jetEtaAK4->at(1));
	         fillVariableWithValue( "phi_j2", jetPhiAK4->at(1));	
		 fillVariableWithValue( "neutrHadEnFrac_j2", jetNhfAK4->at(1));
		 fillVariableWithValue( "chargedHadEnFrac_j2", jetChfAK4->at(1));
		 fillVariableWithValue( "photonEnFrac_j2", jetPhfAK4->at(1));
		 fillVariableWithValue( "eleEnFract_j2", jetElfAK4->at(1));
		 fillVariableWithValue( "muEnFract_j2", jetMufAK4->at(1));
                 fillVariableWithValue( "neutrElectromFrac_j2", jetNemfAK4->at(1));
                 fillVariableWithValue( "chargedElectromFrac_j2", jetCemfAK4->at(1));
		 fillVariableWithValue( "chargedMult_j2", chMultAK4->at(1));
       		 fillVariableWithValue( "neutrMult_j2", neMultAK4->at(1));
         	 fillVariableWithValue( "photonMult_j2", phoMultAK4->at(1));

		 //Trigger
    		 int NtriggerBits = triggerResult->size();
    		 if( NtriggerBits > 0){
		   if( int(getPreCutValue1("IsData"))==1){//data, this is the order for re-reco
     		     fillVariableWithValue("passHLT",triggerResult->at(0));// HLT_PFHT780_v* 
     		     fillVariableWithValue("passHLT1",triggerResult->at(1));// HLT_PFHT890_v* 
     		     fillVariableWithValue("passHLT2",triggerResult->at(2));// HLT_PFHT1050_v* 
     		     fillVariableWithValue("passHLT3",triggerResult->at(3));// HLT_PFJet400_v* 
     		     fillVariableWithValue("passHLT4",triggerResult->at(4));// HLT_PFJet455_v* 
     		     fillVariableWithValue("passHLT5",triggerResult->at(5));// HLT_PFJet500_v* 
     		     fillVariableWithValue("passHLT6",triggerResult->at(6));// HLT_PFJet550_v* 
		   }
		   if( int(getPreCutValue1("IsData"))==0){//MC	
		     fillVariableWithValue("passHLT",triggerResult->at(0));// HLT_PFHT900_v* 
     		     fillVariableWithValue("passHLT1",triggerResult->at(1));// HLT_PFHT650_v* 
     		     fillVariableWithValue("passHLT2",triggerResult->at(2));// HLT_PFHT600_v* 
     		     fillVariableWithValue("passHLT3",triggerResult->at(3));// HLT_PFHT350_v* 
     		     fillVariableWithValue("passHLT4",triggerResult->at(4));// HT650_WideJetMassXX  
     		     fillVariableWithValue("passHLT5",triggerResult->at(5));// HT650_WideJetMassXX 
		   }
		 }//end of trigger   
	
 		}//end of JetID cut   

	     //========================== Tag and Probe method ============================
          if(passJSON (runNo, lumi, int(getPreCutValue1("IsData"))==1 )==1   ||  int(getPreCutValue1("IsData"))==0 ){ //if it's golden data or MC

	     bool trigger_fired=true;
	     if(getPreCutValue1("IsData")==1){
 		if(triggerResult->at(2)==1){trigger_fired=true;}
 		else trigger_fired=false;
	     }
	     
               if(getPreCutValue1("tightJetID")==1){  // Go througth it only if it's "all JetIDs" (tight=1), no need if it's noJetID.
		if(trigger_fired){ //HT1050 for data or MC without trigger selection

	         int irand = (gRandom->Uniform()>0.5) ? 0 : 1;   //tag jet
	         int irand2 = (irand+1)%2;   //probe jet

	         bool tight_tag = (abs(jetEtaAK4->at(irand))<=2.7 && idTAK4->at(irand) >= getPreCutValue1("tightJetID") && jetCemfAK4->at(irand)<0.8);
	         bool extracut_27_3_tag = (abs(jetEtaAK4->at(irand))> 2.7 && abs(jetEtaAK4->at(irand))<=3.0 && neMultAK4->at(irand)>2 && jetNemfAK4->at(irand)<0.99);
	         bool extracut_3_5_tag = (abs(jetEtaAK4->at(irand))> 3.0 && abs(jetEtaAK4->at(irand))<=5.0 && jetNemfAK4->at(irand)< 0.9 && neMultAK4->at(irand)>10 && jetNhfAK4->at(irand)>0.02);

                 if(tight_tag || extracut_27_3_tag || extracut_3_5_tag){ 

		    //bool lepton_cut =  abs(jetEtaAK4->at(irand2))>2.7 || (jetMufAK4->at(irand2)<0.8) && ( (abs(jetEtaAK4->at(irand2))<2.4 && jetCemfAK4->at(irand2)<0.8) || (abs(jetEtaAK4->at(irand2))>2.4) && (abs(jetEtaAK4->at(irand2))<2.7) );
 		    bool lepton_cut =  abs(jetEtaAK4->at(irand2))>2.7 || (jetMufAK4->at(irand2)<0.8 && jetCemfAK4->at(irand2)<0.8 && abs(jetEtaAK4->at(irand2))<2.7);
  
		    if(lepton_cut){

	          	fillVariableWithValue( "pT_probe_all", jetPtAK4->at(irand2));
	          	fillVariableWithValue( "eta_probe", jetEtaAK4->at(irand2));
	          	fillVariableWithValue( "phi_probe", jetPhiAK4->at(irand2));
	         	fillVariableWithValue( "pT_tag", jetPtAK4->at(irand));
	         	fillVariableWithValue( "eta_tag", jetEtaAK4->at(irand));
	         	fillVariableWithValue( "phi_tag", jetPhiAK4->at(irand));
		 	fillVariableWithValue( "mjj_tagANDprobe", mjjAK4);

	         	bool tight_probe = (abs(jetEtaAK4->at(irand2))<=2.7 && idTAK4->at(irand2) >= getPreCutValue1("tightJetID") && jetCemfAK4->at(irand2)<0.8);
	         	bool extracut_27_3_probe = (abs(jetEtaAK4->at(irand2))> 2.7 && abs(jetEtaAK4->at(irand2))<=3.0 && neMultAK4->at(irand2)>2 && jetNemfAK4->at(irand2)<0.99);
	         	bool extracut_3_5_probe = (abs(jetEtaAK4->at(irand2))> 3.0 && abs(jetEtaAK4->at(irand2))<=5.0 && jetNemfAK4->at(irand2)< 0.9 && neMultAK4->at(irand2)>10 && jetNhfAK4->at(irand2)>0.02);

	                if(tight_probe || extracut_27_3_probe || extracut_3_5_probe){
		  	    fillVariableWithValue( "pT_probe_JetID", jetPtAK4->at(irand2)); 
	                }//end of probe JetID cut 
  		    }// end of lepton cut
                 }  //end of tag JetID cut
               }//end of trigger_fired HLT_PFHT1050_v*

 	       if(getPreCutValue1("IsData")==1 && triggerResult->at(3)==1){   // HLT_PFJet400_v*

	         int irand = (gRandom->Uniform()>0.5) ? 0 : 1;   //tag jet
	         int irand2 = (irand+1)%2;   //probe jet

	         bool tight_tag = (abs(jetEtaAK4->at(irand))<=2.7 && idTAK4->at(irand) >= getPreCutValue1("tightJetID") && jetCemfAK4->at(irand)<0.8);
	         bool extracut_27_3_tag = (abs(jetEtaAK4->at(irand))> 2.7 && abs(jetEtaAK4->at(irand))<=3.0 && neMultAK4->at(irand)>2 && jetNemfAK4->at(irand)<0.99);
	         bool extracut_3_5_tag = (abs(jetEtaAK4->at(irand))> 3.0 && abs(jetEtaAK4->at(irand))<=5.0 && jetNemfAK4->at(irand)< 0.9 && neMultAK4->at(irand)>10 && jetNhfAK4->at(irand)>0.02);

                 if(tight_tag || extracut_27_3_tag || extracut_3_5_tag){ 

 		    //bool lepton_cut =  abs(jetEtaAK4->at(irand2))>2.7 || (jetMufAK4->at(irand2)<0.8) && ( (abs(jetEtaAK4->at(irand2))<2.4 && jetCemfAK4->at(irand2)<0.8) || (abs(jetEtaAK4->at(irand2))>2.4) && (abs(jetEtaAK4->at(irand2))<2.7) );
 		    bool lepton_cut =  abs(jetEtaAK4->at(irand2))>2.7 || (jetMufAK4->at(irand2)<0.8 && jetCemfAK4->at(irand2)<0.8 && abs(jetEtaAK4->at(irand2))<2.7);
 
		    if(lepton_cut){	

                  	fillVariableWithValue( "pT_probe_all_HLT_PFJet400", jetPtAK4->at(irand2));
	          	fillVariableWithValue( "eta_probe_HLT_PFJet400", jetEtaAK4->at(irand2));
	          	fillVariableWithValue( "phi_probe_HLT_PFJet400", jetPhiAK4->at(irand2));
		  	fillVariableWithValue( "mjj_tagANDprobe_HLT_PFJet400", mjjAK4);

	          	bool tight_probe = (abs(jetEtaAK4->at(irand2))<=2.7 && idTAK4->at(irand2) >= getPreCutValue1("tightJetID") && jetCemfAK4->at(irand2)<0.8);
	          	bool extracut_27_3_probe = (abs(jetEtaAK4->at(irand2))> 2.7 && abs(jetEtaAK4->at(irand2))<=3.0 && neMultAK4->at(irand2)>2  && jetNemfAK4->at(irand2)<0.99);
	          	bool extracut_3_5_probe = (abs(jetEtaAK4->at(irand2))> 3.0 && abs(jetEtaAK4->at(irand2))<=5.0 && jetNemfAK4->at(irand2)< 0.9 && neMultAK4->at(irand2)>10 && jetNhfAK4->at(irand2)>0.02);

	          	if(tight_probe || extracut_27_3_probe || extracut_3_5_probe){
		   	   fillVariableWithValue( "pT_probe_JetID_HLT_PFJet400", jetPtAK4->at(irand2)); 
                  	}//end of probe JetID cut 
		    }//end of lepton cut
                 }  //end of tag JetID cut
               }//end of if tight=1
             } //end of trigger HLT_PFHT350_v*
           }//end of PassJSON
	     //========================== End of Tag and Probe method ======================

           } //end of deltPhi cut  
        } //end of pt cut
     } //end of dijets 

     // Evaluate cuts (but do not apply them)
     evaluateCuts();
     
     // optional call to fill a skim with the full content of the input roottuple
     //if( passedCut("nJetFinal") ) fillSkimTree();
     
     // optional call to fill a skim with a subset of the variables defined in the cutFile (use flag SAVE)
//     if( passedAllPreviousCuts("nJet") && passedCut("nJet") ) 
//       {
	 fillReducedSkimTree();
//       }
  

     ////////////////////// User's code ends here ///////////////////////

   } // End loop over events

  
  
   std::cout << "analysisClass::Loop() ends" <<std::endl;   
}
