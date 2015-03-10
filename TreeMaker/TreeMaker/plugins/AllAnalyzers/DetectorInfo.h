

#ifndef __DETECTOR_CHECK_H_                                                                                                                                          
#define __DETECTOR_CHECK_H_ 


#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"                                                             

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/ParticleFlowReco/interface/PFRecHit.h"
#include "DataFormats/ParticleFlowReco/interface/PFRecHitFwd.h"
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
#include "DataFormats/CaloRecHit/interface/CaloCluster.h"
#include "DataFormats/CaloRecHit/interface/CaloClusterFwd.h"
#include "DataFormats/CaloRecHit/interface/CaloID.h"
#include "DataFormats/CaloRecHit/interface/CaloRecHit.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "boost/regex.hpp"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "PhysicsTools/JetMCUtils/interface/JetMCTag.h"
#include "DataFormats/EgammaReco/interface/BasicCluster.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/HFEMClusterShapeAssociation.h"
#include "DataFormats/EgammaReco/interface/HFEMClusterShape.h"
#include "DataFormats/EgammaReco/interface/HFEMClusterShapeFwd.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "DataFormats/HcalDetId/interface/HcalSubdetector.h"
#include "DataFormats/HcalDetId/interface/HcalDetId.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
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

class DetectorInfo {
    public:
        DetectorInfo(std::string prefix,edm::Service<TFileService> fs, const edm::ParameterSet& cfg);
      ~DetectorInfo();
        void Fill(const edm::Event& iEvent);
        void Clear();
 //      FakeRate* fakerateObj;

    private:
     DetectorInfo() {};


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
  Handle<reco::PFTauDiscriminator> _dmf,_mv1,_mv2,_mv3,_mv31,_mv32,_ev1,_ev2,_ev3,_iso1,_iso2,_iso3,_iso4,_iso5,_iso6, _hpsTau,_hpsTau1,_hpsTau2,_hpsTau3,_chargedIsoPtSum,_neutralIsoPtSum,_pucorrPtSum,_rawCharged, _rawpu, _rawn , _rawc,_nw1,_nw2,_nw1nq,_nw2nq,_hw1,_hw2,_hw1nq,_hw2nq, _h1 ,rho1,rho2,rho3;
  
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
 

 TH1F *h_gen_pt_pure;
 TH1F *h_gen_eta_pure;
 TH1F *h_gen_phi_pure;
 TH1F *h_pfjet_pt_pure;
 TH1F *h_pfjet_eta_pure;
 TH1F *h_pfjet_phi_pure ;
 TH1F *Fill_gentauEta;
 TH1F *Fill_RecotauEta;

 TH1F *h_EcalBEt, *h_EcalBEta, *h_EcalBPhi, *h_EcalBEnergy, *h_EcalEEt, *h_EcalEEta, *h_EcalEPhi, *h_EcalEEnergy, *h_HcalEt , *h_HcalEta, *h_HcalPhi, *h_HOEt , *h_HOEta, *h_HOPhi ,*h_PSEt , *h_PSEta, *h_PSPhi, *h_HcalEnergy, *h_HOEnergy, *h_PSEnergy;
 TProfile *h_EcalEEtaVsEt,*h_EcalEEtaVsEnergy, *h_EcalBEtaVsEt,*h_EcalBEtaVsEnergy, *h_HcalEtaVsEt, *h_HOEtaVsEt , *h_HcalEtaVsEnergy, *h_HOEtaVsEnergy , *h_EcalBPhiVsEt, *h_EcalBPhiVsEnergy , *h_EcalEPhiVsEt, *h_EcalEPhiVsEnergy , *h_HcalPhiVsEt, *h_HOPhiVsEt , *h_PSPhiVsEt , *h_PSEtaVsEt, *h_HcalPhiVsEnergy, *h_HOPhiVsEnergy , *h_PSPhiVsEnergy , *h_PSEtaVsEnergy ;
 TH2D *h_EcalBEtaVsEt2D, *h_EcalBEtaVsEnergy2D, *h_EcalEEtaVsEt2D, *h_EcalEEtaVsEnergy2D, *h_HcalEtaVsEt2D, *h_HOEtaVsEt2D, *h_HcalEtaVsEnergy2D, *h_HOEtaVsEnergy2D,*h_EcalBPhiVsEt2D, *h_EcalBPhiVsEnergy2D, *h_EcalEPhiVsEt2D, *h_EcalEPhiVsEnergy2D, *h_HcalPhiVsEt2D, *h_HOPhiVsEt2D, *h_PSEtaVsEt2D, *h_PSPhiVsEt2D, *h_HcalPhiVsEnergy2D, *h_HOPhiVsEnergy2D, *h_PSEtaVsEnergy2D, *h_PSPhiVsEnergy2D;

 TH1F *h_TrackPt, *h_TrackEta ,*h_TrackPhi, *h_StandAloneMuonPt, *h_StandAloneMuonEta, *h_StandAloneMuonPhi, *h_CaloMuonPt, *h_CaloMuonEta, *h_CaloMuonPhi;
 TProfile *h_TrackEtaVsPt, *h_TrackPhiVsPt, *h_StandAloneMuonEtaVsPt, *h_StandAloneMuonPhiVsPt , *h_CaloMuonEtaVsPt, *h_CaloMuonPhiVsPt;
 TH2D *h_TrackEtaVsPt2D, *h_TrackPhiVsPt2D, *h_StandAloneMuonEtaVsPt2D, *h_StandAloneMuonPhiVsPt2D , *h_CaloMuonEtaVsPt2D ,*h_CaloMuonPhiVsPt2D ;
//

TH1F *h_EcalPSEt, *h_EcalPSEta, *h_EcalPSPhi, *h_EcalPSEnergy, *h_hfEMEt, *h_hfEMEnergy, *h_hfEMEta, *h_hfEMPhi;

TProfile *h_EcalPSEtaVsEt , *h_EcalPSEtaVsEnergy, *h_EcalPSPhiVsEt , *h_EcalPSPhiVsEnergy, *h_hfEMEtaVsEt, *h_hfEMEtaVsEnergy, *h_hfEMPhiVsEt, *h_hfEMPhiVsEnergy;

TH2D *h_EcalPSEtaVsEt2D , *h_EcalPSEtaVsEnergy2D, *h_EcalPSPhiVsEt2D , *h_EcalPSPhiVsEnergy2D, *h_hfEMEtaVsEt2D,*h_hfEMEtaVsEnergy2D, *h_hfEMPhiVsEt2D, *h_hfEMPhiVsEnergy2D;
//
// static data member definitions
//

//
// constructors and destructor
};
#endif
