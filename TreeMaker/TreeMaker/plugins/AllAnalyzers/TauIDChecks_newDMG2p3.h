#ifndef __TAUID_NEW_CHECK_G2p3_H_                                                                                                                                          
#define __TAUID_NEW_CHECK_G2p3_H_ 


#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/CompositeCandidate.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/Math/interface/LorentzVectorFwd.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/PatCandidates/interface/Isolation.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Math/interface/normalizedPhi.h"
#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/TauReco/interface/PFTauDiscriminator.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/Common/interface/RefVector.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "CLHEP/Random/RandGauss.h"
#include "CommonTools/CandUtils/interface/Booster.h"
#include "DataFormats/METReco/interface/GenMET.h"
#include "DataFormats/METReco/interface/GenMETCollection.h"
#include <Math/VectorUtil.h>
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/HitPattern.h"
#include "TrackingTools/TransientTrack/interface/TrackTransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "CLHEP/Units/GlobalPhysicalConstants.h"
#include "CommonTools/Statistics/interface/ChiSquaredProbability.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "CommonTools/ParticleFlow/test/PFIsoReaderDemo.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "boost/regex.hpp"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "PhysicsTools/JetMCUtils/interface/JetMCTag.h"
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
#include <TProfile.h>
#include <TTree.h>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#include <TRandom3.h>
#include <TBranch.h>
// class declaration                                                                                                                           
//                                                                                                                                             
using namespace std;
using namespace edm;

//
// class declaration
//

class TauIDChecks_newDMG2p3 {
    public:
        TauIDChecks_newDMG2p3(std::string prefix,edm::Service<TFileService> fs, const edm::ParameterSet& cfg);
      ~TauIDChecks_newDMG2p3();
        void Fill(const edm::Event& iEvent);
        void Clear();
 //      FakeRate* fakerateObj;

    private:
     TauIDChecks_newDMG2p3() {};


  //-----do matching to gen?
  bool _MatchTauToGen;
  bool _UseTauMotherId;
  bool _UseTauGrandMotherId;
  bool _MatchLeptonToGen;
  bool _UseLeptonMotherId;
  bool _UseLeptonGrandMotherId;
  int _TauMotherId;
  int _TauGrandMotherId;
  int _LeptonMotherId;
  int _LeptonGrandMotherId;
  double _TauToGenMatchingDeltaR;                                                                                                                            
  std::vector<bool> muVetoContainer,EVetoContainer,IsoVetoContainer;
  std::vector<reco::GenParticleRef> associatedGenParticles;
  
  Handle< reco::GenParticleCollection > _genParticles;
  Handle<reco::GenJetCollection> _genJets;
  Handle<reco::PFTauCollection> _hpsTaucoll;
  Handle<reco::PFTauDiscriminator> _dmf,_mv1,_mv2,_mv3,_mv31,_mv32,_ev1,_ev2,_ev3,_iso1,_iso2,_iso3,_iso4,_iso5,_iso6, _hpsTau,_hpsTau1,_hpsTau2,_hpsTau3,_chargedIsoPtSum,_neutralIsoPtSum,_pucorrPtSum,_rawCharged,_losIsowLT,_losIsowoLT,_medIsowLT,_medIsowoLT,_TightIsowLT,_TightIsowoLT,_VTightIsowLT,_VTightIsowoLT,_VVTightIsowLT,_VVTightIsowoLT;                                                                          
  
bool OverlapWithGenTau(double Taueta , double Tauphi ,edm::Handle<std::vector< reco::GenJet > > genTauJets ,int  &index ) ; 
//  bool MatchingWithPFTau(const patTau& theObject);
  bool IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles);
  reco::Candidate::LorentzVector MChadtau;
  const reco::Candidate * daughterCand;  
  const reco::Candidate * motherCand;
  const reco::Candidate * grandMotherCand;

  //  double hpsLooseCombined3HitsFromPtSums1;
  double hpsLooseCombined3HitsFromPtSums;  
  // vector<string> muVeto, EVeto, IsoVeto;

 int tauGenJetDecayModeInt;
 TH1F  *TrackPt;
 TH1F  *TrackEta;
 TH1F  *TrackPhi;
 TH1F  *JetPt;
  TH1F  *TauPtResponse_DM;

  TH1F  *TauPtResponse_ML2;
  TH1F  *TauPtResponse_MM2;
  TH1F  *TauPtResponse_MT2;

  TH1F  *TauPtResponse_ML3;
  TH1F  *TauPtResponse_MT3;

  TH1F  *TauPtResponse_EL3;
  TH1F  *TauPtResponse_ET3;
  TH1F  *TauPtResponse_EM3;

  TH1F  *TauPtResponse_LIso3Hits;
  TH1F  *TauPtResponse_MIso3Hits;
  TH1F  *TauPtResponse_TIso3Hits;

  TH1F  *TauPtResponse_LIso;
  TH1F  *TauPtResponse_MIso;
  TH1F  *TauPtResponse_TIso;

  TH1F  *TauPtResponse_LooseIsowLT;
   TH1F  *TauPtResponse_LooseIsowoLT;

  TH1F  *TauPtResponse_MediumIsowLT;
  TH1F  *TauPtResponse_MediumIsowoLT;
  TH1F  *TauPtResponse_TightIsowLT;
  TH1F  *TauPtResponse_TightIsowoLT;

  TH1F  *TauPtResponse_VTightIsowLT;
  TH1F  *TauPtResponse_VTightIsowoLT;

  TH1F  *TauPtResponse_VVTightIsowLT;
  TH1F  *TauPtResponse_VVTightIsowoLT;


  TH1I*  npuVertices_;
  TH1I*  ootnpuVertices_;

  TH1F  *RecoTauDecayMode_DM;
  TH1F  *GenTauDecayMode_DM;
  TH2F  *reco_dm_vs_gen_dm;

  TH1F  *RecoTauDecayMode_ML2;
  TH1F  *GenTauDecayMode_ML2;
  TH2F  *reco_dm_vs_gen_ML2;

  TH1F  *RecoTauDecayMode_MM2;
  TH1F  *GenTauDecayMode_MM2;
  TH2F  *reco_dm_vs_gen_MM2;

  TH1F  *RecoTauDecayMode_MT2;
  TH1F  *GenTauDecayMode_MT2;
  TH2F  *reco_dm_vs_gen_MT2;

  TH1F  *RecoTauDecayMode_ML3;
  TH1F  *GenTauDecayMode_ML3;
  TH2F  *reco_dm_vs_gen_ML3;

  TH1F  *RecoTauDecayMode_MT3;
  TH1F  *GenTauDecayMode_MT3;
  TH2F  *reco_dm_vs_gen_MT3;

  TH1F  *RecoTauDecayMode_EL3;
  TH1F  *GenTauDecayMode_EL3;
  TH2F  *reco_dm_vs_gen_EL3;


  TH1F  *RecoTauDecayMode_EM3;
  TH1F  *GenTauDecayMode_EM3;
  TH2F  *reco_dm_vs_gen_EM3;


  TH1F  *RecoTauDecayMode_ET3;
  TH1F  *GenTauDecayMode_ET3;
  TH2F  *reco_dm_vs_gen_ET3;


  TH1F  *RecoTauDecayMode_LIso3Hits;
  TH1F  *GenTauDecayMode_LIso3Hits;
  TH2F  *reco_dm_vs_gen_LIso3Hits;

  TH1F  *RecoTauDecayMode_MIso3Hits;
  TH1F  *GenTauDecayMode_MIso3Hits;
  TH2F  *reco_dm_vs_gen_MIso3Hits;

  TH1F  *RecoTauDecayMode_TIso3Hits;
  TH1F  *GenTauDecayMode_TIso3Hits;
  TH2F  *reco_dm_vs_gen_TIso3Hits;


  TH1F  *RecoTauDecayMode_LIso;
  TH1F  *GenTauDecayMode_LIso;
  TH2F  *reco_dm_vs_gen_LIso;

  TH1F  *RecoTauDecayMode_MIso;
  TH1F  *GenTauDecayMode_MIso;
  TH2F  *reco_dm_vs_gen_MIso;

  TH1F  *RecoTauDecayMode_TIso;
  TH1F  *GenTauDecayMode_TIso;
  TH2F  *reco_dm_vs_gen_TIso;


  TH1F  *RecoTauDecayMode_LooseIsowLT;
  TH1F  *GenTauDecayMode_LooseIsowLT;
  TH2F  *reco_dm_vs_gen_LooseIsowLT;

  TH1F  *RecoTauDecayMode_LooseIsowoLT;
TH1F  *GenTauDecayMode_LooseIsowoLT;
 TH2F  *reco_dm_vs_gen_LooseIsowoLT;

  TH1F  *RecoTauDecayMode_MediumIsowLT;
  TH1F  *GenTauDecayMode_MediumIsowLT;
  TH2F  *reco_dm_vs_gen_MediumIsowLT;

   TH1F  *RecoTauDecayMode_MediumIsowoLT;
  TH1F  *GenTauDecayMode_MediumIsowoLT;
   TH2F  *reco_dm_vs_gen_MediumIsowoLT;

  TH1F  *RecoTauDecayMode_TightIsowLT;
  TH1F  *GenTauDecayMode_TightIsowLT;
  TH2F  *reco_dm_vs_gen_TightIsowLT;

  TH1F  *RecoTauDecayMode_TightIsowoLT;
  TH1F  *GenTauDecayMode_TightIsowoLT;
  TH2F  *reco_dm_vs_gen_TightIsowoLT;

  TH1F  *RecoTauDecayMode_VTightIsowLT;
  TH1F  *GenTauDecayMode_VTightIsowLT;
  TH2F  *reco_dm_vs_gen_VTightIsowLT;

  TH1F  *RecoTauDecayMode_VTightIsowoLT;
  TH1F  *GenTauDecayMode_VTightIsowoLT;
  TH2F  *reco_dm_vs_gen_VTightIsowoLT;

  TH1F  *RecoTauDecayMode_VVTightIsowLT;
  TH1F  *GenTauDecayMode_VVTightIsowLT;
  TH2F  *reco_dm_vs_gen_VVTightIsowLT;

  TH1F  *RecoTauDecayMode_VVTightIsowoLT;
  TH1F  *GenTauDecayMode_VVTightIsowoLT;
  TH2F  *reco_dm_vs_gen_VVTightIsowoLT;

  TH1F  *RecoTauDecayMode_TChar;
  TH1F  *GenTauDecayMode_TChar;
  TH2F  *reco_dm_vs_gen_TChar;


 TH1F  *GenTauPtWithoutDMF;
 TH1F  *GenTauEtaWithoutDMF;
 TH1F  *GenTauPhiWithoutDMF;

 TH1F  *GenTauPtWithoutDMF_eta1p47;
 TH1F  *GenTauEtaWithoutDMF_eta1p47;
 TH1F  *GenTauPhiWithoutDMF_eta1p47;

 TH1F  *GenTauPtWithoutDMF_etag1p47;
 TH1F  *GenTauEtaWithoutDMF_etag1p47;
 TH1F  *GenTauPhiWithoutDMF_etag1p47;



 TH1F  *GenTauPtWithDMF;
 TH1F  *GenTauEtaWithDMF;
 TH1F  *GenTauPhiWithDMF;

 TH1F  *GenTauPtWithDMF_ML2;
 TH1F  *GenTauEtaWithDMF_ML2;
 TH1F  *GenTauPhiWithDMF_ML2;

 TH1F  *GenTauPtWithDMF_MM2;
 TH1F  *GenTauEtaWithDMF_MM2;
 TH1F  *GenTauPhiWithDMF_MM2;

 TH1F  *GenTauPtWithDMF_MT2;
 TH1F  *GenTauEtaWithDMF_MT2;
 TH1F  *GenTauPhiWithDMF_MT2;

  TH1F  *GenTauPtWithDMF_ML3;
  TH1F  *GenTauEtaWithDMF_ML3;
  TH1F  *GenTauPhiWithDMF_ML3;

  TH1F  *GenTauPtWithDMF_MT3;
  TH1F  *GenTauEtaWithDMF_MT3;
  TH1F  *GenTauPhiWithDMF_MT3;

  TH1F  *GenTauPtWithDMF_EL3;
  TH1F  *GenTauEtaWithDMF_EL3;
  TH1F  *GenTauPhiWithDMF_EL3;
                     
  TH1F  *GenTauPtWithDMF_EM3;
  TH1F  *GenTauEtaWithDMF_EM3; 
  TH1F  *GenTauPhiWithDMF_EM3; 
                     
  TH1F  *GenTauPtWithDMF_ET3;
  TH1F  *GenTauEtaWithDMF_ET3;
  TH1F  *GenTauPhiWithDMF_ET3; // constants, enums and typedefs

  TH1F  *GenTauPtWithDMF_LIso3Hits; 
  TH1F  *GenTauEtaWithDMF_LIso3Hits;
  TH1F  *GenTauPhiWithDMF_LIso3Hits;
                           
  TH1F  *GenTauPtWithDMF_MIso3Hits; 
  TH1F  *GenTauEtaWithDMF_MIso3Hits;
  TH1F  *GenTauPhiWithDMF_MIso3Hits;
                           
  TH1F  *GenTauPtWithDMF_TIso3Hits; 
  TH1F  *GenTauEtaWithDMF_TIso3Hits;
  TH1F  *GenTauPhiWithDMF_TIso3Hits;

  TH1F  *GenTauPtWithDMF_LIso; 
  TH1F  *GenTauEtaWithDMF_LIso;
  TH1F  *GenTauPhiWithDMF_LIso;
                           
  TH1F  *GenTauPtWithDMF_MIso; 
  TH1F  *GenTauEtaWithDMF_MIso;
  TH1F  *GenTauPhiWithDMF_MIso;
                           
  TH1F  *GenTauPtWithDMF_TIso; 
  TH1F  *GenTauEtaWithDMF_TIso;
  TH1F  *GenTauPhiWithDMF_TIso;

  TH1F  *GenTauPtWithDMF_LooseIsowLT; 
  TH1F  *GenTauEtaWithDMF_LooseIsowLT;
  TH1F  *GenTauPhiWithDMF_LooseIsowLT;

  TH1F  *GenTauPtWithDMF_LooseIsowoLT; 
TH1F  *GenTauEtaWithDMF_LooseIsowoLT;
TH1F  *GenTauPhiWithDMF_LooseIsowoLT;
 
  TH1F  *GenTauPtWithDMF_MediumIsowLT; 
  TH1F  *GenTauEtaWithDMF_MediumIsowLT;
  TH1F  *GenTauPhiWithDMF_MediumIsowLT;
  
  TH1F  *GenTauPtWithDMF_MediumIsowoLT; 
  TH1F  *GenTauEtaWithDMF_MediumIsowoLT;
  TH1F  *GenTauPhiWithDMF_MediumIsowoLT;
                         
  TH1F  *GenTauPtWithDMF_TightIsowLT;
  TH1F  *GenTauEtaWithDMF_TightIsowLT;
  TH1F  *GenTauPhiWithDMF_TightIsowLT;
  
   TH1F  *GenTauPtWithDMF_TightIsowoLT;
   TH1F  *GenTauEtaWithDMF_TightIsowoLT;
  TH1F  *GenTauPhiWithDMF_TightIsowoLT;
                         
  TH1F  *GenTauPtWithDMF_VTightIsowLT;
  TH1F  *GenTauEtaWithDMF_VTightIsowLT;
  TH1F  *GenTauPhiWithDMF_VTightIsowLT;

  TH1F  *GenTauPtWithDMF_VTightIsowoLT;
  TH1F  *GenTauEtaWithDMF_VTightIsowoLT;
  TH1F  *GenTauPhiWithDMF_VTightIsowoLT;

  TH1F  *GenTauPtWithDMF_VVTightIsowLT;
  TH1F  *GenTauEtaWithDMF_VVTightIsowLT;
  TH1F  *GenTauPhiWithDMF_VVTightIsowLT;

  TH1F  *GenTauPtWithDMF_VVTightIsowoLT;
  TH1F  *GenTauEtaWithDMF_VVTightIsowoLT;
  TH1F  *GenTauPhiWithDMF_VVTightIsowoLT;





  TH1F  *GenTauPtWithDMF_eta1p47_0;
  TH1F  *GenTauEtaWithDMF_eta1p47_0;
  TH1F  *GenTauPhiWithDMF_eta1p47_0;
  TH1F  *GenTauPtWithDMF_eta1p47_1;
  TH1F  *GenTauEtaWithDMF_eta1p47_1;
  TH1F  *GenTauPhiWithDMF_eta1p47_1;
 
  TH1F  *GenTauPtWithDMF_eta1p47_2;
  TH1F  *GenTauEtaWithDMF_eta1p47_2;
  TH1F  *GenTauPhiWithDMF_eta1p47_2;
      
  TH1F  *GenTauPtWithDMF_eta1p47_10;
  TH1F  *GenTauEtaWithDMF_eta1p47_10;
  TH1F  *GenTauPhiWithDMF_eta1p47_10;
 
  TH1F  *GenTauPtWithDMF_eta1p47_11;
  TH1F  *GenTauEtaWithDMF_eta1p47_11;
  TH1F  *GenTauPhiWithDMF_eta1p47_11;



  TH1F  *GenTauPtWithDMF_etag1p47_0;
  TH1F  *GenTauEtaWithDMF_etag1p47_0;
  TH1F  *GenTauPhiWithDMF_etag1p47_0;
  TH1F  *GenTauPtWithDMF_etag1p47_1;
  TH1F  *GenTauEtaWithDMF_etag1p47_1;
  TH1F  *GenTauPhiWithDMF_etag1p47_1;
 
  TH1F  *GenTauPtWithDMF_etag1p47_2;
  TH1F  *GenTauEtaWithDMF_etag1p47_2;
  TH1F  *GenTauPhiWithDMF_etag1p47_2;
      
  TH1F  *GenTauPtWithDMF_etag1p47_10;
  TH1F  *GenTauEtaWithDMF_etag1p47_10;
  TH1F  *GenTauPhiWithDMF_etag1p47_10;
 
  TH1F  *GenTauPtWithDMF_etag1p47_11;
  TH1F  *GenTauEtaWithDMF_etag1p47_11;
  TH1F  *GenTauPhiWithDMF_etag1p47_11;

  TH1F  *GenTauPtWithDMF_0;
  TH1F  *GenTauEtaWithDMF_0;
  TH1F  *GenTauPhiWithDMF_0;
  TH1F  *GenTauPtWithDMF_1;
  TH1F  *GenTauEtaWithDMF_1;
  TH1F  *GenTauPhiWithDMF_1;
 
  TH1F  *GenTauPtWithDMF_2;
  TH1F  *GenTauEtaWithDMF_2;
  TH1F  *GenTauPhiWithDMF_2;
      
  TH1F  *GenTauPtWithDMF_10;
  TH1F  *GenTauEtaWithDMF_10;
  TH1F  *GenTauPhiWithDMF_10;
 
  TH1F  *GenTauPtWithDMF_11;
  TH1F  *GenTauEtaWithDMF_11;
  TH1F  *GenTauPhiWithDMF_11;
 
//

//
// static data member definitions
//

//
// constructors and destructor
};
#endif
