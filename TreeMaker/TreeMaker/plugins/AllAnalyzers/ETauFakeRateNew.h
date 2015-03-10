#ifndef __ELEC_FAKERATE_NEW_H_              
#define __ELEC_FAKERATE_NEW_H_ 


#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"                                                             

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

class ETauFakeRateNew {
    public:
        ETauFakeRateNew(std::string prefix, edm::Service<TFileService> fs, const edm::ParameterSet& cfg);
      ~ETauFakeRateNew();
        void Fill(const edm::Event& iEvent);
        void Clear();
 //      FakeRate* fakerateObj;

    private:
     ETauFakeRateNew() {};


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
 bool OverlapWithGenTauForOther(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc ,int &index ) ;
 
 Handle<reco::PFTauDiscriminator> _dmf,_mv1,_mv2,_mv3,_mv31,_mv32,_ev1,_ev2,_ev3,_iso1,_iso2,_iso3,_iso4,_iso5,_iso6, _hpsTau,_hpsTau1,_hpsTau2,_hpsTau3,_chargedIsoPtSum,_neutralIsoPtSum,_pucorrPtSum,_rawCharged, _enew, _rawpu, _rawn , _rawc,_nw1,_nw2,_nw1nq,_nw2nq,_hw1,_hw2,_hw1nq,_hw2nq, _h1 ,rho1,rho2,rho3 , _Newdmf;
 bool OverlapWithGenMu(double, double, edm::Handle<reco::GenParticleCollection> , int&) ;
  //  bool MatchingWithPFTau(const patTau& theObject);
  bool IsZEE(edm::Handle<reco::GenParticleCollection> genParticles);
  reco::Candidate::LorentzVector MChadtau;
  const reco::Candidate * daughterCand;  
  const reco::Candidate * motherCand;
  const reco::Candidate * grandMotherCand;
  int igentau;
  bool  ElectronDisc , IsoDisc ;
  //  double hpsLooseCombined3HitsFromPtSums1;

  // vector<string> muVeto, EVeto, IsoVeto;

  TH1F *h_PfTau_pT_num;
  TH1F *h_PfTau_Eta_num;
  TH1F *h_PfTau_Phi_num;
  
  TH1F *h_genElectron_pT_num;
  TH1F *h_genElectron_Eta_num;
  TH1F *h_genElectron_Phi_num;


  TH1F *h_PfTau_pT_num_tight;
  TH1F *h_PfTau_Eta_num_tight;
  TH1F *h_PfTau_Phi_num_tight;
  
  TH1F *h_genElectron_pT_num_tight;
  TH1F *h_genElectron_Eta_num_tight;
  TH1F *h_genElectron_Phi_num_tight;

  TH1F *h_PfTau_pT_num_Cut;
  TH1F *h_PfTau_Eta_num_Cut;
  TH1F *h_PfTau_Phi_num_Cut;
   
   TH1F *h_genElectron_pT_num_Cut;
   TH1F *h_genElectron_Eta_num_Cut;
   TH1F *h_genElectron_Phi_num_Cut;
 

   TH1F *h_PfTau_pT_num_medium;
  TH1F *h_PfTau_Eta_num_medium;
   TH1F *h_PfTau_Phi_num_medium;
 
   TH1F *h_genElectron_pT_num_medium;
   TH1F *h_genElectron_Eta_num_medium;
   TH1F *h_genElectron_Phi_num_medium;
 
   TH1F *h_PfTau_pT_DMF;
  TH1F *h_PfTau_Eta_DMF;
  TH1F *h_PfTau_Phi_DMF;

  TH1F *h_genElectron_pT_DMF;
  TH1F *h_genElectron_Eta_DMF;
  TH1F *h_genElectron_Phi_DMF;


 
  TH1F *h_PfTau_pT_den;
  TH1F *h_PfTau_Eta_den;
  TH1F *h_PfTau_Phi_den;
  
  TH1F *h_genElectron_pT_den;
  TH1F *h_genElectron_Eta_den;
  TH1F *h_genElectron_Phi_den;
   
 TH1F *hFillTauHcal3x3OverPLead_before;                                             
 TH1F *FillHOverP_before ;
 TH1F *FillEOverP_before;
 TH1F *FillGammaFraction_before;

 TH1F *hFillTauHcal3x3OverPLead_after;                                             
 TH1F *FillHOverP_after ;
 TH1F *FillEOverP_after;
 TH1F *FillGammaFraction_after;

TH1F *Nvtx_num_Cut;
TH1F *NGood_num_Cut;

TH1F *Nvtx_num_medium;
TH1F *NGood_num_medium;

TH1F *Nvtx_num_tight;
TH1F *NGood_num_tight;

TH1F *Nvtx_num;
TH1F *NGood_num;

TH1F *Nvtx_den;
TH1F *NGood_den;

TH1F *Nvtx_DMF;
TH1F *NGood_DMF;

// constructors and destructor
};
#endif
