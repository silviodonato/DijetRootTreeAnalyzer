#include"TLorentzVector.h"
#include"TRandom3.h"
#include"TVector2.h"
#include"TMath.h"
#include"TF1.h"

TLorentzVector a,b, genP;

float dRmatch(float j1_pt,float j1_eta,float j1_phi,float j2_pt,float j2_eta,float j2_phi,float gen_pt,float gen_eta,float gen_phi){
        a.SetPtEtaPhiM(j1_pt,j1_eta,j1_phi,0);
        b.SetPtEtaPhiM(j2_pt,j2_eta,j2_phi,0);
        genP.SetPtEtaPhiM(gen_pt,gen_eta,gen_phi,0);
        return genP.DeltaR(a+b);
}

bool match(float deltaR, float j1_pt,float j1_eta,float j1_phi,float j2_pt,float j2_eta,float j2_phi,float gen_pt,float gen_eta,float gen_phi){
        if(dRmatch(j1_pt,j1_eta,j1_phi,j2_pt,j2_eta,j2_phi,gen_pt,gen_eta,gen_phi) < deltaR) return true;
        else return false;
}


TRandom3 rnd;

float eta1,x, w;
float Eta1(){
//        return rnd.Rndm()*5-2.5;
//        do{
                eta1 = rnd.Gaus()*2.11;
//        } while(fabs(eta1)>2.5);
        return eta1;
}


float eta2, mean, sigma,deta, lpt1pt2, spt1pt2;

//TF1* gausss = new TF1("fit","[0]/[2]*((exp(-0.5*pow(x-[1],2)/pow([2],2))) + exp(-0.5*pow(-x-[1],2)/pow([2],2)))", -5,  +5);
//gausss->SetParameters(1,1.25,1.25);


/*

float Eta2(float eta1, float pt1pt2){
        lpt1pt2 = TMath::Log(pt1pt2);

// QCD isr 70
//        mean  = 1.05844;
 //       sigma = 4.12889e+00 + -2.92466e-01*pow(lpt1pt2,1);

// data
       mean  = 1.60694e+00 + -4.11391e-02*pow(lpt1pt2,1);
       sigma = -3.51829e-02 + 3.29584e-01*pow(lpt1pt2,1) + -1.94989e-02*pow(lpt1pt2,2);

//        mean  = 1.74434e+00 + -5.65917e-02*pow(lpt1pt2,1);
//        sigma = 1.36331e+00 + 5.76472e-02*pow(lpt1pt2,1) + -6.61440e-03*pow(lpt1pt2,2);
//        do{
                deta = fabs(rnd.Gaus()*sigma + mean);
//        }while(fabs(deta)>5);
        if(rnd.Rndm()>0.5) deta = - deta;
//        eta2 = rnd.Gaus()*1.75 + 0.35*eta1;
//        if(fabs(eta2)>2.5) {eta2 = 9999999;}
        eta2 = eta1 + deta;
        return eta2;
}

*/

float weight(float pt1pt2){
        spt1pt2 = 2*TMath::Sqrt(pt1pt2);
//        lpt1pt2 = TMath::Log(pt1pt2);
//        return -3.46897e-02 + 9.83977e-03*lpt1pt2 + -4.32322e-04 * lpt1pt2 * lpt1pt2;
//        return -4.01392e-01 + 1.17561e-01*lpt1pt2 + -1.09455e-02 * lpt1pt2 * lpt1pt2 + 3.40682e-04 * lpt1pt2 * lpt1pt2 * lpt1pt2;
//        return -8.56915e-01 + 2.40092e-01*pow(lpt1pt2,1) + -1.97845e-02*pow(lpt1pt2,2) + 5.78603e-04*pow(lpt1pt2,3) + -8.02108e-05*pow(lpt1pt2,4) + 1.03423e-05*pow(lpt1pt2,5) + -3.56032e-07*pow(lpt1pt2,6);
//        return 3.12465e-02 + -2.70984e-03*pow(lpt1pt2,1) + 1.62737e-04*pow(lpt1pt2,2);
//        return TMath::Erf((lpt1pt2-7.53651e+00)/1.25115e+00);
//        return 0.410736 + spt1pt2 * 8.62674e-05;
//        return 4.09797e-01*((TMath::Erf((spt1pt2-7.68477e+01)/7.11128e+01))+2.12367e-04*spt1pt2);
//        return 4.09797e-01*((TMath::Erf((spt1pt2-7.68477e+01)/7.11128e+01))+2.12367e-04*spt1pt2);
//        return 4.06380e-01*((TMath::Erf((spt1pt2-9.47632e+01)/5.79826e+01))+2.11201e-04*spt1pt2);
        return 4.06380e-01*(1+2.11201e-04*spt1pt2);
//        return 4.09797e-01*(1.+2.12367e-04*spt1pt2);
        
}

float weight2(float pt1pt2){
        x = TMath::Sqrt(pt1pt2);
//        return 0.430863*(TMath::Erf((x-42.5576)/31.0616)+1.40763+0.000235141*x+-7.33515e-07*x*x);
//        return 0.430101*(((TMath::Erf((x-43.5588)/31.7064)+1.40279)+(0.000339522*x))+(-9.52332e-07*(x*x)));

// ORIGINAL OK
//        return 0.339284*(((TMath::Erf((x-53.1535)/31.0223)+2.03013)+(0.000486256*x))+(-1.23389e-06*(x*x)));

// TEST with trigger
        return 0.430202*(((TMath::Erf((x-50.7327)/30.2791)+1.40395)+(0.000256341*x))+(-7.55566e-07*(x*x)));

}

float weight2_rnd(float pt1pt2){
//        w = weight2(pt1pt2)/1.04548;
//        w = weight2(pt1pt2)/1.04645779311;
        w = weight2(pt1pt2)/1.04433040227;
        if(rnd.Rndm()<w) return 1;
        else return -1;
}

float weightRunH(float pt1pt2){
        x = TMath::Sqrt(pt1pt2);
        return 0.385055*((((TMath::Erf((x-37.2598)/39.5537)+1.47707)+(-0.00840785*x))+(9.86701e-06*(x*x)))/(((1-0.0462415)+(-0.00351607*x))+(4.69648e-06*(x*x))));
}

float weightRunH_rnd(float pt1pt2){
        w = weightRunH(pt1pt2)/1.04536269803;
        if(rnd.Rndm()<w) return 1;
        else return -1;
}

float weightRunHOld(float pt1pt2){
        x = TMath::Sqrt(pt1pt2);
        return 0.417222*(((TMath::Erf((x-52.8224)/23.9418)+1.22716)+(0.00300497*x))+(-7.92978e-06*(x*x)));
}

float weightRunHOld_rnd(float pt1pt2){
        w = weightRunHOld(pt1pt2)/1.04799646743;
        if(rnd.Rndm()<w) return 1;
        else return -1;
}

float weightRunHL1HT320(float pt1pt2){
        x = TMath::Sqrt(pt1pt2);
        return 0.415292*(((TMath::Erf((x+30.4044)/84.7997)+1.13843)+(0.00379606*x))+(-9.18915e-06*(x*x)));
}

float weightRunHL1HT320_rnd(float pt1pt2){
        w = weightRunHL1HT320(pt1pt2)/1.05085030965;
        if(rnd.Rndm()<w) return 1;
        else return -1;
}

float Eta2(float eta1, float pt1pt2){
        lpt1pt2 = TMath::Log(pt1pt2);
        spt1pt2 = 2*TMath::Sqrt(pt1pt2);
//        return 4.06380e-01*((TMath::Erf((spt1pt2-9.47632e+01)/5.79826e+01))+2.11201e-04*spt1pt2);
        if(rnd.Rndm()> 4.06380e-01*((TMath::Erf((spt1pt2-9.47632e+01)/5.79826e+01))+2.11201e-04*spt1pt2)) return -1000;
//        if(rnd.Rndm()> 4.06380e-01*(1+2.11201e-04*spt1pt2)) return -1000;
//        if(rnd.Rndm()> 4.06380e-01*(1+2.11201e-04*spt1pt2)) return -1000;
//        if(rnd.Rndm()> 4.06380e-01*(1+2.11201e-04*spt1pt2)) return -1;
// QCD isr 70
//        mean  = 1.05844;
 //       sigma = 4.12889e+00 + -2.92466e-01*pow(lpt1pt2,1);

// data
       mean  = 0;
//       sigma = 2.03980e+01 + -3.08838e+00*pow(lpt1pt2,1) + 1.30583e-01*pow(lpt1pt2,2);
//       sigma = 3.11017e+00 + 1.44347e-01*pow(lpt1pt2,1) + -1.88566e-02*pow(lpt1pt2,2);
//       sigma = 2.11056e+01 + -3.36840e+00*pow(lpt1pt2,1) + 1.52905e-01*pow(lpt1pt2,2);
//       sigma = -1.30557e+01 + 2.93314e+00*pow(lpt1pt2,1) + -1.36117e-01*pow(lpt1pt2,2);
       sigma = 1.42248e+00 + 1.10765e-01*pow(lpt1pt2,1);
//       sigma = 2.5;

//        mean  = 1.74434e+00 + -5.65917e-02*pow(lpt1pt2,1);
//        sigma = 1.36331e+00 + 5.76472e-02*pow(lpt1pt2,1) + -6.61440e-03*pow(lpt1pt2,2);
        do{
//                deta = fabs(rnd.Gaus()*sigma + mean);
                deta = rnd.Gaus()*sigma + mean;
//                deta = rnd.Rndm()*2.2 - 1.1;
        }while(fabs(deta)>1.1);
//        if(rnd.Rndm()>0.5) deta = - deta;
//        eta2 = rnd.Gaus()*1.75 + 0.35*eta1;
//        if(fabs(eta2)>2.5) {eta2 = 9999999;}
        eta2 = eta1 - deta;
        return eta2;
}

float DijetEta(float pt1pt2){
        lpt1pt2 = TMath::Log(pt1pt2);
       mean  = 0;
       sigma = 1.42248e+00 + 1.10765e-01*pow(lpt1pt2,1);
        do{
                deta = rnd.Gaus()*sigma + mean;
        }while(fabs(deta)>1.1);
        return deta;
}




/*
float Eta2(float eta1){
        mean  = -3.04847e-02 + 4.45717e-02*pow(eta1,1) + 4.49069e-03*pow(eta1,2) + 2.42000e-02*pow(eta1,3);
        sigma = 2.40351e+00 -4.37918e-01*pow(eta1,2) +9.69738e-02*pow(eta1,4) +-7.48110e-03*pow(eta1,6);
        do{
                eta2 = rnd.Gaus()*sigma + mean;
        } while(fabs(eta2)>2.5);
//        eta2 = rnd.Gaus()*1.75 + 0.35*eta1;
//        if(fabs(eta2)>2.5) {eta2 = 9999999;}
        return eta2;
}
*/

float deltaR(float eta1,float phi1,float eta2,float phi2){
        return pow((pow(eta1-eta2,2)+pow(TVector2::Phi_mpi_pi(phi1-phi2),2)),0.5);
}

float MyMass(float pt1, float eta1, float phi1, float mass1, float pt2, float eta2, float phi2, float mass2){ //
        if(fabs(eta1-eta2)<1.1 &&  fabs(eta1)<2.5 && fabs(eta2)<2.5 && deltaR(eta1,phi1,eta2,phi2)>1.1  )
//        if(fabs(eta1-eta2)<1.1 && deltaR(eta1,phi1,eta2,phi2)>1.1) 
                return TMath::Sqrt(2*(pow(mass1,2)+pow(mass2,2)+pt1*pt2*(TMath::CosH(eta1-eta2)       - TMath::Cos(TVector2::Phi_mpi_pi(phi1-phi2)))));
        else return -1;
}

float MyMassNoCut(float pt1, float eta1, float phi1, float mass1, float pt2, float eta2, float phi2, float mass2){ //
        if(true  )
//        if(fabs(eta1)<2.5 && fabs(eta2)<2.5 && deltaR(eta1,phi1,eta2,phi2)>1.1  )
//        if(fabs(eta1-eta2)<1.1 && deltaR(eta1,phi1,eta2,phi2)>1.1) 
                return TMath::Sqrt(2*(pow(mass1,2)+pow(mass2,2)+pt1*pt2*(TMath::CosH(eta1-eta2)       - TMath::Cos(TVector2::Phi_mpi_pi(phi1-phi2)))));
        else return -1;
}


float MyMassTest(float pt1, float eta1, float phi1, float mass1, float pt2, float eta2, float phi2, float eta3, float phi3 ){ //
//        if(fabs(eta1-eta2)<1.1 && fabs(eta1)<2.5 && fabs(eta2)<2.5 && deltaR(eta1,phi1,eta2,phi2)>1.1  ) // && deltaR(eta1,phi1,eta3,phi3)>1.1 && deltaR(eta2,phi2,eta3,phi3)>1.1
//        if(fabs(eta1-eta2)<1.1 && fabs(eta1)<2.5 && fabs(eta2)<2.5 && deltaR(eta1,phi1,eta2,phi2)>1.1 && deltaR(eta1,phi1,eta3,phi3)>1.1 && deltaR(eta2,phi2,eta3,phi3)>1.1  ) // && deltaR(eta1,phi1,eta3,phi3)>1.1 && deltaR(eta2,phi2,eta3,phi3)>1.1
        if(fabs(eta1-eta2)<1.1  && fabs(eta1+eta2)<4  && fabs(eta1)<2.5 && fabs(eta2)<2.5 && deltaR(eta1,phi1,eta2,phi2)>1.1   ) 
//        if(fabs(eta1-eta2)<1.1 && deltaR(eta1,phi1,eta2,phi2)>1.1) 
                return TMath::Sqrt(2*(pow(mass1,2)+pow(0,2)+pt1*pt2*(TMath::CosH(eta1-eta2)       - TMath::Cos(TVector2::Phi_mpi_pi(phi1-phi2)))));
        else return -1;
}
