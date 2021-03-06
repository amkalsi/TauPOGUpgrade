#ifndef __JET_S_FAKERATE_FULL_H_              
#define __JET_S_FAKERATE_FULL_H_ 


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
#include "DataFormats/MuonReco/interface/MuonFwd.h"
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

class JetTauFakeRateFullSimon {
    public:
        JetTauFakeRateFullSimon(std::string prefix, edm::Service<TFileService> fs, const edm::ParameterSet& cfg);
      ~JetTauFakeRateFullSimon();
        void Fill(const edm::Event& iEvent,const edm::EventSetup& iSetup);
        void Clear();
 //      FakeRate* fakerateObj;

    private:
     JetTauFakeRateFullSimon() {};

 std::string JetCorrectionService; 
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
//  Handle<reco::PFTauDiscriminator> _hpsTau,_hpsTau1,_hpsTau2,_hpsTau3,_chargedIsoPtSum,_neutralIsoPtSum,_pucorrPtSum,_rawCharged;
  
 Handle<reco::PFTauDiscriminator> _dmf,_mv1,_mv2,_mv3,_mv31,_mv32,_ev1,_ev2,_ev3,_iso1,_iso2,_iso3,_iso4,_iso5,_iso6, _hpsTau,_hpsTau1,_hpsTau2,_hpsTau3,_chargedIsoPtSum,_neutralIsoPtSum,_pucorrPtSum,_rawCharged ,  _rawpu, _rawn , _rawc,_nw1,_nw2,_nw1nq,_nw2nq,_hw1,_hw2,_hw1nq,_hw2nq, _h1 ; 
  bool OverlapWithGenJet(double Taueta , double Tauphi ,edm::Handle<reco::GenJetCollection> jets ,int  &index ,const edm::Event& iEvent,const edm::EventSetup& iSetup);  
  pair<bool, reco::Candidate::LorentzVector> matchToGenJet(double jeteta , double jetphi  , edm::Handle<reco::GenJetCollection> ak5jets);
  reco::Candidate::LorentzVector MChadtau;
  const reco::Candidate * daughterCand;  
  const reco::Candidate * motherCand;
  const reco::Candidate * grandMotherCand;
  int igentau;
  bool  MuonDisc , IsoDisc ;
  //  double hpsLooseCombined3HitsFromPtSums1;

  // vector<string> muVeto, EVeto, IsoVeto;

  double ptofleadtrack, zof, PVz, temppt;
  TH1F *h_Den_JetToTauPt ;
  TH1F *h_DMF_JetToTauPt ;
  TH1F *h_Fill_DZ ;
  TH1F *h_Loose3_JetToTauPt ;
  TH1F *h_Medium3_JetToTauPt ;
  TH1F *h_Tight3_JetToTauPt ;
  TH1F *h_VLooseChar_JetToTauPt ;
  TH1F *h_LooseChar_JetToTauPt ;
  TH1F *h_MediumChar_JetToTauPt ;
  TH1F *h_TightChar_JetToTauPt ;
  TH1F *DR_After_Matching; 
  TH1F *h_Den_JetPt;
  TH1F *h_DMF_JetPt;
  TH1F *h_Loose3_JetPt;
  TH1F *h_Medium3_JetPt;
  TH1F *h_Tight3_JetPt;
  TH1F *h_VLooseChar_JetPt;
  TH1F *h_LooseChar_JetPt;
  TH1F *h_MediumChar_JetPt;
  TH1F *h_TightChar_JetPt;

  TH1F *h_Den_TauPt ;
  TH1F *h_DMF_TauPt;
  TH1F *h_Loose3_TauPt;
  TH1F *h_Medium3_TauPt;
  TH1F *h_Tight3_TauPt;
  TH1F *h_VLooseChar_TauPt;
  TH1F *h_LooseChar_TauPt;
  TH1F *h_MediumChar_TauPt;
  TH1F *h_TightChar_TauPt;


  TH1F *h_Den_JetEta ;
  TH1F *h_DMF_JetEta;
  TH1F *h_Loose3_JetEta;
  TH1F *h_Medium3_JetEta;
  TH1F *h_Tight3_JetEta;
  TH1F *h_VLooseChar_JetEta;
  TH1F *h_LooseChar_JetEta;
  TH1F *h_MediumChar_JetEta;
  TH1F *h_TightChar_JetEta;


  TH1F *h_Den_TauEta;
  TH1F *h_DMF_TauEta;
  TH1F *h_Loose3_TauEta;
  TH1F *h_Medium3_TauEta;
  TH1F *h_Tight3_TauEta;
  TH1F *h_VLooseChar_TauEta;
  TH1F *h_LooseChar_TauEta ;
  TH1F *h_MediumChar_TauEta ;
  TH1F *h_TightChar_TauEta ;



  TH1F *h_Den_JetPhi;
  TH1F *h_DMF_JetPhi;
  TH1F *h_Loose3_JetPhi;
  TH1F *h_Medium3_JetPhi;
  TH1F *h_Tight3_JetPhi ;
  TH1F *h_VLooseChar_JetPhi;
  TH1F *h_LooseChar_JetPhi;
  TH1F *h_MediumChar_JetPhi;
  TH1F *h_TightChar_JetPhi;

  TH1F *h_Iso1_JetPhi;
  TH1F *h_Iso2_JetPhi;
  TH1F *h_Iso4_JetPhi;
  TH1F *h_Iso1_TauPhi;
  TH1F *h_Iso2_TauPhi;
  TH1F *h_Iso4_TauPhi;


  TH1F *h_Iso1_JetEta;
  TH1F *h_Iso2_JetEta;
  TH1F *h_Iso4_JetEta;
  TH1F *h_Iso1_TauEta;
  TH1F *h_Iso2_TauEta;
  TH1F *h_Iso4_TauEta;

  TH1F *h_Iso1_JetPt;
  TH1F *h_Iso2_JetPt;
  TH1F *h_Iso4_JetPt;
  TH1F *h_Iso1_TauPt;
  TH1F *h_Iso2_TauPt;
  TH1F *h_Iso4_TauPt;



  TH1F *h_Den_TauPhi;
  TH1F *h_DMF_TauPhi;
  TH1F *h_Loose3_TauPhi;
  TH1F *h_Medium3_TauPhi;
  TH1F *h_Tight3_TauPhi;
  TH1F *h_VLooseChar_TauPhi;
  TH1F *h_LooseChar_TauPhi ;
  TH1F *h_MediumChar_TauPhi;
  TH1F *h_TightChar_TauPhi;

  TH1F *h_VLooseChar_NVtx;
  TH1F *h_VLooseChar_NGood;
  TH1F *h_VLooseChar_NBest;

  TH1F *h_LooseChar_NVtx;
  TH1F *h_LooseChar_NGood;
  TH1F *h_LooseChar_NBest;

  TH1F *h_MediumChar_NVtx;
  TH1F *h_MediumChar_NGood;
  TH1F *h_MediumChar_NBest;

  TH1F *h_TightChar_NVtx;
  TH1F *h_TightChar_NGood;
  TH1F *h_TightChar_NBest;

  TH1F *h_Loose3_NVtx;
  TH1F *h_Loose3_NGood;
  TH1F *h_Loose3_NBest;

  TH1F *h_DMF_NVtx;
  TH1F *h_DMF_NGood;
  TH1F *h_DMF_NBest;

  TH1F *h_Medium3_NVtx;
  TH1F *h_Medium3_NGood;
  TH1F *h_Medium3_NBest;

  TH1F *h_Iso1_NVtx;
  TH1F *h_Iso1_NGood;
  TH1F *h_Iso1_NBest;

  TH1F *h_Iso2_NVtx;
  TH1F *h_Iso2_NGood;
  TH1F *h_Iso2_NBest;

  TH1F *h_Iso4_NVtx;
  TH1F *h_Iso4_NGood;
  TH1F *h_Iso4_NBest;

  TH1F *h_Tight3_NVtx;
  TH1F *h_Tight3_NGood;
  TH1F *h_Tight3_NBest;

  TH1F *h_Den_NVtx;
  TH1F *h_Den_NGood;
  TH1F *h_Den_NBest;

  TH1F *h_gen_pt_pure;
  TH1F *h_gen_eta_pure;
  TH1F *h_gen_phi_pure;

  TH1F *h_pfjet_pt_pure;
  TH1F *h_pfjet_eta_pure;
  TH1F *h_pfjet_phi_pure ;

  TH1F *h_VLooseChar_GenJetPt;
  TH1F *h_VLooseChar_GenJetEta;
  TH1F *h_VLooseChar_GenJetPhi ;
  TH1F *h_VLooseChar_DR;


  TH1F *h_LooseChar_GenJetPt;
  TH1F *h_LooseChar_GenJetEta;
  TH1F *h_LooseChar_GenJetPhi;
  TH1F *h_LooseChar_DR;


  TH1F *h_MediumChar_GenJetPt;
  TH1F *h_MediumChar_GenJetEta;
  TH1F *h_MediumChar_GenJetPhi;
  TH1F *h_MediumChar_DR;


  TH1F *h_TightChar_GenJetPt;
  TH1F *h_TightChar_GenJetEta;
  TH1F *h_TightChar_GenJetPhi;
  TH1F *h_TightChar_DR;

  TH1F *h_Iso1_GenJetPt ;
  TH1F *h_Iso1_GenJetEta;
  TH1F *h_Iso1_GenJetPhi ;
  TH1F *h_Iso1_DR;

  TH1F *h_Iso2_GenJetPt ;
  TH1F *h_Iso2_GenJetEta;
  TH1F *h_Iso2_GenJetPhi ;
  TH1F *h_Iso2_DR;

  TH1F *h_Iso4_GenJetPt ;
  TH1F *h_Iso4_GenJetEta;
  TH1F *h_Iso4_GenJetPhi ;
  TH1F *h_Iso4_DR;

  TH1F *h_Loose3_GenJetPt ;
  TH1F *h_Loose3_GenJetEta;
  TH1F *h_Loose3_GenJetPhi ;
  TH1F *h_Loose3_DR;


  TH1F *h_Medium3_GenJetPt;
  TH1F *h_Medium3_GenJetEta;
  TH1F *h_Medium3_GenJetPhi;
  TH1F *h_Medium3_DR ;


  TH1F *h_Tight3_GenJetPt ;
  TH1F *h_Tight3_GenJetEta;
  TH1F *h_Tight3_GenJetPhi ;
  TH1F *h_Tight3_DR;

  TH1F *h_DMF_GenJetPt;
  TH1F *h_DMF_GenJetEta;
  TH1F *h_DMF_GenJetPhi;
  TH1F *h_DMF_DR ;


  TH1F *h_Den_GenJetPt;
  TH1F *h_Den_GenJetEta;
  TH1F *h_Den_GenJetPhi;
  TH1F *h_Den_DR;
  TH1F *h_VLooseChar_Response ;
  TH1F *h_LooseChar_Response ;
  TH1F *h_MediumChar_Response;
  TH1F *h_TightChar_Response;

  TH1F *h_Loose3_Response ;
  TH1F *h_Medium3_Response;
  TH1F *h_Tight3_Response;


  TH1F *h_Den_Response ;
  TH1F *h_DMF_Response;

  TH1F *h_Iso1_Response;
  TH1F *h_Iso2_Response;
  TH1F *h_Iso4_Response;


  TH1F *h_MIsoPtSum_Response;
  TH1F *h_MIsoPtSum_TauPt;
  TH1F *h_MIsoPtSum_TauEta;
  TH1F *h_MIsoPtSum_TauPhi;

  TH1F *h_MIsoPtSum_JetPt;
  TH1F *h_MIsoPtSum_JetEta;
  TH1F *h_MIsoPtSum_JetPhi;

  TH1F *h_MIsoPtSum_GenJetPt;
  TH1F *h_MIsoPtSum_GenJetEta;
  TH1F *h_MIsoPtSum_GenJetPhi;

  TH1F *h_MIsoPtSum_NVtx;
  TH1F *h_MIsoPtSum_NGood;
  TH1F *h_MIsoPtSum_NBest;



  TH1F *h_TIsoPtSum_Response;
  TH1F *h_TIsoPtSum_TauPt;
  TH1F *h_TIsoPtSum_TauEta;
  TH1F *h_TIsoPtSum_TauPhi;

  TH1F *h_TIsoPtSum_JetPt;
  TH1F *h_TIsoPtSum_JetEta;
  TH1F *h_TIsoPtSum_JetPhi;

  TH1F *h_TIsoPtSum_GenJetPt;
  TH1F *h_TIsoPtSum_GenJetEta;
  TH1F *h_TIsoPtSum_GenJetPhi;

  TH1F *h_TIsoPtSum_NVtx;
  TH1F *h_TIsoPtSum_NGood;
  TH1F *h_TIsoPtSum_NBest;



  TH1F *h_LIsoPtSum_Response;
  TH1F *h_LIsoPtSum_TauPt;
  TH1F *h_LIsoPtSum_TauEta;
  TH1F *h_LIsoPtSum_TauPhi;

  TH1F *h_LIsoPtSum_JetPt;
  TH1F *h_LIsoPtSum_JetEta;
  TH1F *h_LIsoPtSum_JetPhi;

  TH1F *h_LIsoPtSum_GenJetPt;
  TH1F *h_LIsoPtSum_GenJetEta;
  TH1F *h_LIsoPtSum_GenJetPhi;

  TH1F *h_LIsoPtSum_NVtx;
  TH1F *h_LIsoPtSum_NGood;
  TH1F *h_LIsoPtSum_NBest;

  TH1F *h_LIsoPtSum_DR;
  TH1F *h_MIsoPtSum_DR;
  TH1F *h_TIsoPtSum_DR;


// constructors and destructor
};
#endif
