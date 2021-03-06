#include <algorithm>
#include <cmath>

#include "GenParticle.h"
#include "Collection.h"
#include "IDTypes.h"

bool GenParticle::PassUserID (ID id, bool verbose){ 
  if      ( id == GEN_ELE_FROM_LQ         ) { return PassUserID_GenEleFromLQ     (verbose); }
  else if ( id == GEN_MUON_FROM_LQ        ) { return PassUserID_GenMuonFromLQ    (verbose); }
  else if ( id == GEN_TAU_FROM_LQ         ) { return PassUserID_GenTauFromLQ     (verbose); }
  else if ( id == GEN_ELE_HARD_SCATTER    ) { return PassUserID_GenEleHardScatter(verbose); }

  else if ( id == GEN_ZGAMMA_HARD_SCATTER ) { return PassUserID_GenZGammaHardScatter(verbose); }
  else if ( id == GEN_W_HARD_SCATTER      ) { return PassUserID_GenWHardScatter     (verbose); }
  else if ( id == GEN_NU_FROM_W  	  ) { return PassUserID_GenNuFromW          (verbose); }
  else if ( id == GEN_ELE_FROM_W  	  ) { return PassUserID_GenEleFromW         (verbose); }
  else if ( id == GEN_ELE_FROM_DY  	  ) { return PassUserID_GenEleFromDY        (verbose); }

  else if ( id == GEN_ELE_FIDUCIAL        ) { return PassUserID_ECALFiducial     (verbose); } 
  else if ( id == GEN_MUON_FIDUCIAL       ) { return PassUserID_MuonFiducial     (verbose); } 
  else return false;
}

bool GenParticle::PassUserID_GenEleHardScatter(bool verbose){ 
  if ( Status()      != 3   ) return false;  
  if ( abs(PdgId())  != 11  ) return false;
  return true;
}

bool GenParticle::PassUserID_FromLQ(bool verbose){
  if ( Status() != 3 ) return false;  
  int mother_pdg_id = m_collection -> GetData() -> GenParticlePdgId -> at ( MotherIndex() );
  if ( abs(mother_pdg_id) != 42 ) return false;
  return true;
}

bool GenParticle::PassUserID_FromDY(bool verbose){
  if ( Status() != 3 ) return false;  
  int mother_pdg_id = m_collection -> GetData() -> GenParticlePdgId -> at ( MotherIndex() );
  if ( abs(mother_pdg_id) != 22 && 
       abs(mother_pdg_id) != 23 ) return false;
  return true;
}

bool GenParticle::PassUserID_FromW(bool verbose){
  if ( Status() != 3 ) return false;  
  int mother_pdg_id = m_collection -> GetData() -> GenParticlePdgId -> at ( MotherIndex() );
  if ( abs(mother_pdg_id) != 24 ) return false;
  return true;
}

bool GenParticle::PassUserID_GenEleFromLQ (bool verbose){
  if ( abs(PdgId())  != 11         ) return false;
  if ( !PassUserID_FromLQ(verbose) ) return false;
  return true;
}

bool GenParticle::PassUserID_GenMuonFromLQ(bool verbose){
  if ( abs(PdgId())  != 13         ) return false;
  if ( !PassUserID_FromLQ(verbose) ) return false;
  return true;
}

bool GenParticle::PassUserID_GenTauFromLQ (bool verbose){
  if ( abs(PdgId())  != 15         ) return false;
  if ( !PassUserID_FromLQ(verbose) ) return false;
  return true;
}

bool GenParticle::PassUserID_GenZGammaHardScatter(bool verbose){
  if ( Status() != 3 ) return false;  
  if ( abs(PdgId()) != 22 && 
       abs(PdgId()) != 23 ) return false;
  return true;
}

 
bool GenParticle::PassUserID_GenWHardScatter     (bool verbose){
  if ( Status() != 3 ) return false;  
  if ( abs(PdgId()) != 24 ) return false;
  return true;
} 

bool GenParticle::PassUserID_GenNuFromW          (bool verbose){
  if ( abs(PdgId()) != 12         ) return false;
  if ( !PassUserID_FromW(verbose) ) return false;
  return true;
} 

bool GenParticle::PassUserID_GenEleFromW         (bool verbose){
  if ( abs(PdgId()) != 11         ) return false;
  if ( !PassUserID_FromW(verbose) ) return false;
  return true;
} 

bool GenParticle::PassUserID_GenEleFromDY        (bool verbose){
  if ( abs(PdgId())  != 11         ) return false;
  if ( !PassUserID_FromDY(verbose) ) return false;
  return true;
} 

bool GenParticle::PassUserID_ECALFiducial(bool verbose){
  if ( IsGenElectronFiducial() ) return true;
  else return false;
}

bool GenParticle::PassUserID_MuonFiducial(bool verbose){
  if ( IsMuonFiducial() ) return true;
  else return false;
}

