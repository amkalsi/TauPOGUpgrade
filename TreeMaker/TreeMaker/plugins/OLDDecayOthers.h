#ifndef __DECAYMODE_OLD_OTHERS_H_                                                                                                                                          
#define __DECAYMODE_OLD_OTHERS_H_ 


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

class OLDDecayOthers {
    public:
        OLDDecayOthers(std::string prefix,edm::Service<TFileService> fs, const edm::ParameterSet& cfg);
      ~OLDDecayOthers();
        void Fill(const edm::Event& iEvent);
        void Clear();
 //      FakeRate* fakerateObj;

    private:
     OLDDecayOthers() {};


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
  double  etacut , etacutmin;
  double PUInfo_true, PUInfo, PUInfo_Bunch0; 
  std::vector<bool> muVetoContainer,EVetoContainer,IsoVetoContainer;
  std::vector<reco::GenParticleRef> associatedGenParticles;
  
  Handle< reco::GenParticleCollection > _genParticles;
  Handle<reco::GenJetCollection> _genJets;
  Handle<reco::PFTauCollection> _hpsTaucoll;
  Handle<reco::PFTauDiscriminator> _dmf,_mv1,_mv2,_mv3,_mv31,_mv32,_ev1,_ev2,_ev3,_iso1,_iso2,_iso3,_iso4,_iso5,_iso6, _hpsTau,_hpsTau1,_hpsTau2,_hpsTau3,_chargedIsoPtSum,_neutralIsoPtSum,_pucorrPtSum,_rawCharged, _rawpu, _rawn , _rawc,_nw1,_nw2,_nw1nq,_nw2nq,_hw1,_hw2,_hw1nq,_hw2nq, _h1 ,rho1,rho2,rho3 , _enew , _Newdmf;
  
  bool OverlapWithGenTau(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc, int &index ) ;

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
 TH1F  *Nvtx_Den1Prong;
 TH1F  *Nvtx_NDM1Prong;

 TH1F  *Nvtx_DenBothPi0;
 TH1F  *Nvtx_NDMBothPi0;

 
 TH1F  *Nvtx_Den1Prong1pi0;
 TH1F  *Nvtx_NDM1Prong1pi0;

 TH1F  *Nvtx_Den1Prong2pi0;
 TH1F  *Nvtx_NDM1Prong2pi0;

 TH1F  *Nvtx_Den3Prong;
 TH1F  *Nvtx_NDM3Prong;


 TH1F  *Nvtx_Den3Prong1pi0;
 TH1F  *Nvtx_NDM3Prong1pi0;
 

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

  TH1F *TauPtResponse_DenDMF;
  TH1F  *RecoTauDecayMode_DenDMF;
  TH1F  *GenTauDecayMode_DenDMF;
  TH2F  *reco_dm_vs_gen_DenDMF;

  TH1F  *TauPtResponse_LIso;
  TH1F  *TauPtResponse_MIso;
  TH1F  *TauPtResponse_TIso;

  TH1F  *TauPtResponse_VLChar;
  TH1F  *TauPtResponse_LChar;
  TH1F  *TauPtResponse_MChar;
  TH1F  *TauPtResponse_TChar;

  TH1I*  npuVertices_;
  TH1I*  ootnpuVertices_;

  TH1F  *RecoTauDecayMode_DM;
  TH1F  *GenTauDecayMode_DM;
  TH2F  *reco_dm_vs_gen_dm;



  TH1F  *GenTauPtWithDMF_0;
  TH1F  *GenTauEtaWithDMF_0;
  TH1F  *GenTauPhiWithDMF_0;
  TH1F  *GenTauPtWithDMF_1;
  TH1F  *GenTauEtaWithDMF_1;
  TH1F  *GenTauPhiWithDMF_1;
 
  TH1F  *GenTauPtWithDMF_2;
  TH1F  *GenTauEtaWithDMF_2;
  TH1F  *GenTauPhiWithDMF_2;



  TH1F  *GenTauPtWithDMF_DenDMF;
  TH1F  *GenTauEtaWithDMF_DenDMF;
  TH1F  *GenTauPhiWithDMF_DenDMF;

      
  TH1F  *GenTauPtWithDMF_10;
  TH1F  *GenTauEtaWithDMF_10;
  TH1F  *GenTauPhiWithDMF_10;
 
  TH1F  *GenTauPtWithDMF_11;
  TH1F  *GenTauEtaWithDMF_11;
  TH1F  *GenTauPhiWithDMF_11;

  TH1F  *GenTauPt_Den1Prong;
  TH1F  *GenTauEta_Den1Prong;
 TH1F  *GenTauPhi_Den1Prong;

  TH1F  *GenTauPt_DM1Prong;
  TH1F  *GenTauEta_DM1Prong;
 TH1F  *GenTauPhi_DM1Prong;

  TH1F  *GenTauPt_NDM1Prong;
  TH1F  *GenTauEta_NDM1Prong;
 TH1F  *GenTauPhi_NDM1Prong;

  TH1F *TauPtResponse_DM1Prong;
  TH1F *TauPtResponse_NDM1Prong;

 TH1F *TauPtResponse_DM1ProngLChar;
  TH1F *TauPtResponse_NDM1ProngLChar;

  TH1F  *GenTauPt_DenBothPi0;
  TH1F  *GenTauEta_DenBothPi0;
    TH1F  *GenTauPhi_DenBothPi0;

                                                                                                                                                                              
  TH1F  *GenTauPt_Den1Prong1pi0;
  TH1F  *GenTauEta_Den1Prong1pi0;
 TH1F  *GenTauPhi_Den1Prong1pi0;

  TH1F  *GenTauPt_DM1Prong1pi0;
  TH1F  *GenTauEta_DM1Prong1pi0;
 TH1F  *GenTauPhi_DM1Prong1pi0;

  TH1F  *GenTauPt_NDM1Prong1pi0;
  TH1F  *GenTauEta_NDM1Prong1pi0;
 TH1F  *GenTauPhi_NDM1Prong1pi0;

  TH1F *TauPtResponse_DM1Prong1pi0;
  TH1F *TauPtResponse_NDM1Prong1pi0;

 TH1F *TauPtResponse_DM1Prong1pi0LChar;
  TH1F *TauPtResponse_NDM1Prong1pi0LChar;

TH1F  *GenTauPt_Den1Prong2pi0;
  TH1F  *GenTauEta_Den1Prong2pi0;
 TH1F  *GenTauPhi_Den1Prong2pi0;


 TH1F  *GenTauPt_DM1Prong2pi0;
  TH1F  *GenTauEta_DM1Prong2pi0;
 TH1F  *GenTauPhi_DM1Prong2pi0;

  TH1F  *GenTauPt_NDM1Prong2pi0;
  TH1F  *GenTauEta_NDM1Prong2pi0;
 TH1F  *GenTauPhi_NDM1Prong2pi0;

  TH1F *TauPtResponse_DM1Prong2pi0;
  TH1F *TauPtResponse_NDM1Prong2pi0;
 TH1F *TauPtResponse_DM1Prong2pi0LChar;
  TH1F *TauPtResponse_NDM1Prong2pi0LChar;


  TH1F  *GenTauPt_Den3Prong1pi0;
  TH1F  *GenTauEta_Den3Prong1pi0;
 TH1F  *GenTauPhi_Den3Prong1pi0;

  TH1F  *GenTauPt_DM3Prong1pi0;
  TH1F  *GenTauEta_DM3Prong1pi0;
 TH1F  *GenTauPhi_DM3Prong1pi0;

 TH1F  *GenTauPt_NDMBothPi0;
 TH1F  *GenTauEta_NDMBothPi0;
 TH1F  *GenTauPhi_NDMBothPi0;


  TH1F  *GenTauPt_NDM3Prong1pi0;
  TH1F  *GenTauEta_NDM3Prong1pi0;
 TH1F  *GenTauPhi_NDM3Prong1pi0;

  TH1F *TauPtResponse_DM3Prong1pi0;
  TH1F *TauPtResponse_NDM3Prong1pi0;
  TH1F *TauPtResponse_DM3Prong1pi0LChar;
  TH1F *TauPtResponse_NDM3Prong1pi0LChar;

  TH1F *TauPtResponse_NDMBothPi0;

  TH1F  *GenTauPt_Den3Prong;
  TH1F  *GenTauEta_Den3Prong;
  TH1F  *GenTauPhi_Den3Prong;


   TH1F  *GenTauPt_DM3Prong;
  TH1F  *GenTauEta_DM3Prong;
 TH1F  *GenTauPhi_DM3Prong;

  TH1F  *GenTauPt_NDM3Prong;
  TH1F  *GenTauEta_NDM3Prong;
 TH1F  *GenTauPhi_NDM3Prong;

  TH1F *TauPtResponse_DM3Prong;
  TH1F *TauPtResponse_NDM3Prong;
    TH1F *TauPtResponse_DM3ProngLChar;

  TH1F *TauPtResponse_NDM3ProngLChar;


 TH1F *TauPtResponse_DM_LooseIso_3Prong1Pi0;
  TH1F *TauPtResponse_DM_LooseIso_3Prong;
  TH1F *TauPtResponse_DM_LooseIso_1Prong;
   TH1F *TauPtResponse_DM_LooseIso_1Prong1Pi0;

  TH1F *TauPtResponse_DM_LooseIso_1Prong2Pi0;


  TH1F *hFillTauHcal3x3OverPLead;
  TH1F *FillHOverP;
  TH1F *FillEOverP;
  TH1F *FillGammaFraction;

  TH1F *hFillTauHcal3x3OverPLead_before;
  TH1F *FillHOverP_before;
  TH1F *FillEOverP_before;
  TH1F *FillGammaFraction_before;

  TH1F *hFillTauHcal3x3OverPLead_DMF;
  TH1F *FillHOverP_DMF;
  TH1F *FillEOverP_DMF;
  TH1F *FillGammaFraction_DMF;


  TH1F *h_RunNumber_NDM1Prong;
  TH1F *h_EventNumber_NDM1Prong;
  TH1F *h_LumiNumber_NDM1Prong;
  TH1F *h_BXNumber_NDM1Prong;
 

  TH1F *h_RunNumber_NDM1Prong1pi0;
  TH1F *h_EventNumber_NDM1Prong1pi0;
  TH1F *h_LumiNumber_NDM1Prong1pi0;
  TH1F *h_BXNumber_NDM1Prong1pi0;


  TH1F *h_RunNumber_NDM1Prong2pi0;
  TH1F *h_EventNumber_NDM1Prong2pi0;
  TH1F *h_LumiNumber_NDM1Prong2pi0;
  TH1F *h_BXNumber_NDM1Prong2pi0;

  TH1F *h_RunNumber_NDM3Prong;
  TH1F *h_EventNumber_NDM3Prong;
  TH1F *h_LumiNumber_NDM3Prong;
  TH1F *h_BXNumber_NDM3Prong;
 
  TH1F *h_RunNumber_NDM3Prong1pi0 ;
  TH1F *h_EventNumber_NDM3Prong1pi0 ;
  TH1F *h_LumiNumber_NDM3Prong1pi0 ;
  TH1F *h_BXNumber_NDM3Prong1pi0 ;

  TProfile *TES_NDM1Prong;
  TProfile *TES_NDM1Prong1pi0;
  TProfile *TES_NDM1Prong2pi0;
  TProfile *TES_NDM3Prong;
  TProfile *TES_NDM3Prong1pi0;
  TProfile *TES_NDMBothPi0;

  TH1F *TauPtResponse_NDM3Prong1pi00;
  TH1F *TauPtResponse_NDM3Prong1pi00a;
  TH1F *TauPtResponse_NDM3Prong1pi012;
  TH1F *TauPtResponse_NDM3Prong1pi012a;
  TH1F *TauPtResponse_NDM3Prong1pi010;
  TH1F *TauPtResponse_NDM3Prong1pi010a;

  TH1F *TauPtResponse_NDM3Prong0;
  TH1F *TauPtResponse_NDM3Prong0a;
  TH1F *TauPtResponse_NDM3Prong12;
  TH1F *TauPtResponse_NDM3Prong12a;
  TH1F *TauPtResponse_NDM3Prong10;
  TH1F *TauPtResponse_NDM3Prong10a;


  TH1F *TauPtResponse_NDM1Prong0;
  TH1F *TauPtResponse_NDM1Prong0a;
  TH1F *TauPtResponse_NDM1Prong12;
  TH1F *TauPtResponse_NDM1Prong12a;
  TH1F *TauPtResponse_NDM1Prong10;
  TH1F *TauPtResponse_NDM1Prong10a;


  TH1F *TauPtResponse_NDM1Prong1pi00;
  TH1F *TauPtResponse_NDM1Prong1pi00a;
  TH1F *TauPtResponse_NDM1Prong1pi012;
  TH1F *TauPtResponse_NDM1Prong1pi012a;
  TH1F *TauPtResponse_NDM1Prong1pi010;
  TH1F *TauPtResponse_NDM1Prong1pi010a;

  TH1F *TauPtResponse_NDMBothPi0LChar;
  TH1F *TauPtResponse_NDM1Prong2pi00;
  TH1F *TauPtResponse_NDM1Prong2pi00a;
  TH1F *TauPtResponse_NDM1Prong2pi012;
  TH1F *TauPtResponse_NDM1Prong2pi012a;
  TH1F *TauPtResponse_NDM1Prong2pi010;
  TH1F *TauPtResponse_NDM1Prong2pi010a;

  TH1F *TauPtResponse_NDMBothPi00;
  TH1F *TauPtResponse_NDMBothPi00a;
  TH1F *TauPtResponse_NDMBothPi012;
  TH1F *TauPtResponse_NDMBothPi012a;
  TH1F *TauPtResponse_NDMBothPi010;
  TH1F *TauPtResponse_NDMBothPi010a;

};
#endif
