


#include "./DetectorInfo.h"                                                                                                                                        
  

DetectorInfo::DetectorInfo(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
 {

   //now do what ever initialization is needed
  _MatchLeptonToGen = iConfig.getParameter<bool>("MatchLeptonToGen");                                                                                        
  _UseLeptonMotherId = iConfig.getParameter<bool>("UseLeptonMotherId");
  _UseLeptonGrandMotherId = iConfig.getParameter<bool>("UseLeptonGrandMotherId");
  _LeptonMotherId = iConfig.getParameter<int>("LeptonMotherId");
  _LeptonGrandMotherId = iConfig.getParameter<int>("LeptonGrandMotherId");
  _MatchTauToGen = iConfig.getParameter<bool>("MatchTauToGen");
  _UseTauMotherId = iConfig.getParameter<bool>("UseTauMotherId");
  _UseTauGrandMotherId = iConfig.getParameter<bool>("UseTauGrandMotherId");
  _TauMotherId = iConfig.getParameter<int>("TauMotherId");
  _TauGrandMotherId = iConfig.getParameter<int>("TauGrandMotherId");
  _TauToGenMatchingDeltaR = iConfig.getParameter<double>("TauToGenMatchingDeltaR");



  h_gen_pt_pure= fs->make<TH1F>(("h_gen_pt_pure"+prefix).c_str() ,"h_gen_pt_pure",200,0,1400);
  h_gen_eta_pure = fs->make<TH1F>(("h_gen_eta_pure"+prefix).c_str() ,"h_gen_eta_pure",100,-5,5);
  h_gen_phi_pure = fs->make<TH1F>(("h_gen_phi_pure"+prefix).c_str() ,"h_gen_phi_pure",100,-5,5);
  
  
  h_pfjet_pt_pure = fs->make<TH1F>(("h_pfjet_pt_pure"+prefix).c_str() ,"h_pfjet_pt_pure",200,0,1400);
  h_pfjet_eta_pure = fs->make<TH1F>(("h_pfjet_eta_pure"+prefix).c_str() ,"h_pfjet_eta_pure",100,-5,5);
  h_pfjet_phi_pure = fs->make<TH1F>(("h_pfjet_phi_pure"+prefix).c_str() ,"h_pfjet_phi_pure",100,-5,5);
  
  Fill_gentauEta = fs->make<TH1F>(("Fill_gentauEta"+prefix).c_str() ,"Fill_gentauEta",100,-5,5);
  Fill_RecotauEta = fs->make<TH1F>(("Fill_RecotauEta"+prefix).c_str() ,"Fill_RecotauEta",100,-5,5);

 h_EcalBEt = fs->make<TH1F>(("h_EcalBEt"+prefix).c_str() ,"h_EcalBEt",1000,0,1000); 
 h_EcalBEnergy  = fs->make<TH1F>(("h_EcalBEnergy"+prefix).c_str() ,"h_EcalBEnergy",1000,0,1000); 
 h_EcalBEta = fs->make<TH1F>(("h_EcalBEta"+prefix).c_str() ,"h_EcalBEta",100,-5,5);

 h_EcalBPhi = fs->make<TH1F>(("h_EcalBPhi"+prefix).c_str() ,"h_EcalBPhi",100,-5,5);
 h_EcalBEtaVsEt = fs->make<TProfile>(("h_EcalBEtaVsEt"+prefix).c_str() ,"h_EcalBEtaVsEt",100,-5,5,0,1000);
  h_EcalBEtaVsEnergy = fs->make<TProfile>(("h_EcalBEtaVsEnergy"+prefix).c_str() ,"h_EcalBEtaVsEnergy",100,-5,5,0,1000);
 h_EcalBEtaVsEt2D = fs->make<TH2D>(("h_EcalBEtaVsEt2D"+prefix).c_str() ,"h_EcalBEtaVsEt2D",100,-5,5,1000,0,1000);
h_EcalBEtaVsEnergy2D = fs->make<TH2D>(("h_EcalBEtaVsEnergy2D"+prefix).c_str() ,"h_EcalBEtaVsEnergy2D",100,-5,5,1000,0,1000);
 h_EcalBPhiVsEt = fs->make<TProfile>(("h_EcalBPhiVsEt"+prefix).c_str() ,"h_EcalBPhiVsEt",100,-5,5,0,1000);
 h_EcalBPhiVsEnergy = fs->make<TProfile>(("h_EcalBPhiVsEnergy"+prefix).c_str() ,"h_EcalBPhiVsEnergy",100,-5,5,0,1000);

 h_EcalBPhiVsEt2D = fs->make<TH2D>(("h_EcalBPhiVsEt2D"+prefix).c_str() ,"h_EcalBPhiVsEt2D",100,-5,5,1000,0,1000);
 
h_EcalBPhiVsEnergy2D = fs->make<TH2D>(("h_EcalBPhiVsEnergy2D"+prefix).c_str() ,"h_EcalBPhiVsEnergy2D",100,-5,5,1000,0,1000);


 h_EcalPSEt = fs->make<TH1F>(("h_EcalPSEt"+prefix).c_str() ,"h_EcalPSEt",1000,0.000001,100); 
 h_EcalPSEnergy  = fs->make<TH1F>(("h_EcalPSEnergy"+prefix).c_str() ,"h_EcalPSEnergy",1000,0.000001,100); 
 h_EcalPSEta = fs->make<TH1F>(("h_EcalPSEta"+prefix).c_str() ,"h_EcalPSEta",100,-5,5);

 h_EcalPSPhi = fs->make<TH1F>(("h_EcalPSPhi"+prefix).c_str() ,"h_EcalPSPhi",100,-5,5);
 h_EcalPSEtaVsEt = fs->make<TProfile>(("h_EcalPSEtaVsEt"+prefix).c_str() ,"h_EcalPSEtaVsEt",100,-5,5,0,1000);
  h_EcalPSEtaVsEnergy = fs->make<TProfile>(("h_EcalPSEtaVsEnergy"+prefix).c_str() ,"h_EcalPSEtaVsEnergy",100,-5,5,0,1000);
 h_EcalPSEtaVsEt2D = fs->make<TH2D>(("h_EcalPSEtaVsEt2D"+prefix).c_str() ,"h_EcalPSEtaVsEt2D",100,-5,5,1000,0.000001,100);
h_EcalPSEtaVsEnergy2D = fs->make<TH2D>(("h_EcalPSEtaVsEnergy2D"+prefix).c_str() ,"h_EcalPSEtaVsEnergy2D",100,-5,5,1000,0.000001,100);
 h_EcalPSPhiVsEt = fs->make<TProfile>(("h_EcalPSPhiVsEt"+prefix).c_str() ,"h_EcalPSPhiVsEt",100,-5,5,0,1000);
 h_EcalPSPhiVsEnergy = fs->make<TProfile>(("h_EcalPSPhiVsEnergy"+prefix).c_str() ,"h_EcalPSPhiVsEnergy",100,-5,5,0,1000);

 h_EcalPSPhiVsEt2D = fs->make<TH2D>(("h_EcalPSPhiVsEt2D"+prefix).c_str() ,"h_EcalPSPhiVsEt2D",100,-5,5,1000,0,1000);
 
h_EcalPSPhiVsEnergy2D = fs->make<TH2D>(("h_EcalPSPhiVsEnergy2D"+prefix).c_str() ,"h_EcalPSPhiVsEnergy2D",100,-5,5,1000,0,1000);

 h_EcalEEt = fs->make<TH1F>(("h_EcalEEt"+prefix).c_str() ,"h_EcalEEt",1000,0,1000); 
 h_EcalEEnergy  = fs->make<TH1F>(("h_EcalEEnergy"+prefix).c_str() ,"h_EcalEEnergy",1000,0,1000); 
 h_EcalEEta = fs->make<TH1F>(("h_EcalEEta"+prefix).c_str() ,"h_EcalEEta",100,-5,5);

 h_EcalEPhi = fs->make<TH1F>(("h_EcalEPhi"+prefix).c_str() ,"h_EcalEPhi",100,-5,5);
 h_EcalEEtaVsEt = fs->make<TProfile>(("h_EcalEEtaVsEt"+prefix).c_str() ,"h_EcalEEtaVsEt",100,-5,5,0,1000);
  h_EcalEEtaVsEnergy = fs->make<TProfile>(("h_EcalEEtaVsEnergy"+prefix).c_str() ,"h_EcalEEtaVsEnergy",100,-5,5,0,1000);
 h_EcalEEtaVsEt2D = fs->make<TH2D>(("h_EcalEEtaVsEt2D"+prefix).c_str() ,"h_EcalEEtaVsEt2D",100,-5,5,1000,0,1000);
h_EcalEEtaVsEnergy2D = fs->make<TH2D>(("h_EcalEEtaVsEnergy2D"+prefix).c_str() ,"h_EcalEEtaVsEnergy2D",100,-5,5,1000,0,1000);
 h_EcalEPhiVsEt = fs->make<TProfile>(("h_EcalEPhiVsEt"+prefix).c_str() ,"h_EcalEPhiVsEt",100,-5,5,0,1000);
 h_EcalEPhiVsEnergy = fs->make<TProfile>(("h_EcalEPhiVsEnergy"+prefix).c_str() ,"h_EcalEPhiVsEnergy",100,-5,5,0,1000);

 h_EcalEPhiVsEt2D = fs->make<TH2D>(("h_EcalEPhiVsEt2D"+prefix).c_str() ,"h_EcalEPhiVsEt2D",100,-5,5,1000,0,1000);
 
h_EcalEPhiVsEnergy2D = fs->make<TH2D>(("h_EcalEPhiVsEnergy2D"+prefix).c_str() ,"h_EcalEPhiVsEnergy2D",100,-5,5,1000,0,1000);


h_HcalEt = fs->make<TH1F>(("h_HcalEt"+prefix).c_str() ,"h_HcalEt",1000,0,1000);
h_HcalEnergy = fs->make<TH1F>(("h_HcalEnergy"+prefix).c_str() ,"h_HcalEnergy",1000,0,1000);
h_HcalEta = fs->make<TH1F>(("h_HcalEta"+prefix).c_str() ,"h_HcalEta",100,-5,5);
h_HcalPhi = fs->make<TH1F>(("h_HcalPhi"+prefix).c_str() ,"h_HcalPhi",100,-5,5);
h_HcalEtaVsEt = fs->make<TProfile>(("h_HcalEtaVsEt"+prefix).c_str() ,"h_HcalEtaVsEt",100,-5,5,0,1000);
h_HcalEtaVsEnergy = fs->make<TProfile>(("h_HcalEtaVsEnergy"+prefix).c_str() ,"h_HcalEtaVsEnergy",100,-5,5,0,1000);

h_HcalEtaVsEt2D= fs->make<TH2D>(("h_HcalEtaVsEt2D"+prefix).c_str() ,"h_HcalEtaVsEt2D",100,-5,5,1000,0,1000);
h_HcalEtaVsEnergy2D= fs->make<TH2D>(("h_HcalEtaVsEnergy2D"+prefix).c_str() ,"h_HcalEtaVsEnergy2D",100,-5,5,1000,0,1000);

 h_HcalPhiVsEt = fs->make<TProfile>(("h_HcalPhiVsEt"+prefix).c_str() ,"h_HcalPhiVsEt",100,-5,5,0,1000);
h_HcalPhiVsEnergy = fs->make<TProfile>(("h_HcalPhiVsEnergy"+prefix).c_str() ,"h_HcalPhiVsEnergy",100,-5,5,0,1000);
 h_HcalPhiVsEt2D= fs->make<TH2D>(("h_HcalPhiVsEt2D"+prefix).c_str() ,"h_HcalPhiVsEt2D",100,-5,5,1000,0,1000);
 h_HcalPhiVsEnergy2D= fs->make<TH2D>(("h_HcalPhiVsEnergy2D"+prefix).c_str() ,"h_HcalPhiVsEnergy2D",100,-5,5,1000,0,1000);


h_HOEnergy = fs->make<TH1F>(("h_HOEnergy"+prefix).c_str() ,"h_HOEnergy",1000,0,1000);
h_HOEta = fs->make<TH1F>(("h_HOEta"+prefix).c_str() ,"h_HOEta",100,-5,5);
h_HOPhi = fs->make<TH1F>(("h_HOPhi"+prefix).c_str() ,"h_HOPhi",100,-5,5);
h_HOEtaVsEt = fs->make<TProfile>(("h_HOEtaVsEt"+prefix).c_str() ,"h_HOEtaVsEt",100,-5,5,0,1000);
h_HOEtaVsEt2D= fs->make<TH2D>(("h_HOEtaVsEt2D"+prefix).c_str() ,"h_HOEtaVsEt2D",100,-5,5,1000,0,1000);
 h_HOPhiVsEt = fs->make<TProfile>(("h_HOPhiVsEt"+prefix).c_str() ,"h_EcalPhiVsEt",100,-5,5,0,1000);
 h_HOPhiVsEt2D= fs->make<TH2D>(("h_HOPhiVsEt2D"+prefix).c_str() ,"h_HOPhiVsEt2D",100,-5,5,1000,0,1000);
h_HOEt = fs->make<TH1F>(("h_HOEt"+prefix).c_str() ,"h_HOEt",1000,0,1000);
h_HOEtaVsEnergy = fs->make<TProfile>(("h_HOEtaVsEnergy"+prefix).c_str() ,"h_HOEtaVsEnergy",100,-5,5,0,1000);
h_HOEtaVsEnergy2D= fs->make<TH2D>(("h_HOEtaVsEnergy2D"+prefix).c_str() ,"h_HOEtaVsEnergy2D",100,-5,5,1000,0,1000);
 h_HOPhiVsEnergy = fs->make<TProfile>(("h_HOPhiVsEnergy"+prefix).c_str() ,"h_EcalPhiVsEnergy",100,-5,5,0,1000);
h_HOPhiVsEnergy2D= fs->make<TH2D>(("h_HOPhiVsEnergy2D"+prefix).c_str() ,"h_HOPhiVsEnergy2D",100,-5,5,1000,0,1000);


h_hfEMEt = fs->make<TH1F>(("h_hfEMEt"+prefix).c_str() ,"h_hfEMEt",1000,0,1000);
h_hfEMEta = fs->make<TH1F>(("h_hfEMEta"+prefix).c_str() ,"h_hfEMEta",100,-5,5);
h_hfEMPhi = fs->make<TH1F>(("h_hfEMPhi"+prefix).c_str() ,"h_hfEMPhi",100,-5,5);
h_hfEMEtaVsEt = fs->make<TProfile>(("h_hfEMEtaVsEt"+prefix).c_str() ,"h_hfEMEtaVsEt",100,-5,5,0,1000);
h_hfEMEtaVsEt2D= fs->make<TH2D>(("h_hfEMEtaVsEt2D"+prefix).c_str() ,"h_hfEMEtaVsEt2D",100,-5,5,1000,0,1000);
 h_hfEMPhiVsEt = fs->make<TProfile>(("h_hfEMPhiVsEt"+prefix).c_str() ,"h_EcalPhiVsEt",100,-5,5,0,1000);
 h_hfEMPhiVsEt2D= fs->make<TH2D>(("h_hfEMPhiVsEt2D"+prefix).c_str() ,"h_hfEMPhiVsEt2D",100,-5,5,1000,0,1000);

h_hfEMEnergy = fs->make<TH1F>(("h_hfEMEnergy"+prefix).c_str() ,"h_hfEMEnergy",1000,0,1000);
h_hfEMEtaVsEnergy = fs->make<TProfile>(("h_hfEMEtaVsEnergy"+prefix).c_str() ,"h_hfEMEtaVsEnergy",100,-5,5,0,1000);
h_hfEMEtaVsEnergy2D= fs->make<TH2D>(("h_hfEMEtaVsEnergy2D"+prefix).c_str() ,"h_hfEMEtaVsEnergy2D",100,-5,5,1000,0,1000);
 h_hfEMPhiVsEnergy = fs->make<TProfile>(("h_hfEMPhiVsEnergy"+prefix).c_str() ,"h_EcalPhiVsEnergy",100,-5,5,0,1000);
 h_hfEMPhiVsEnergy2D= fs->make<TH2D>(("h_hfEMPhiVsEnergy2D"+prefix).c_str() ,"h_hfEMPhiVsEnergy2D",100,-5,5,1000,0,1000);


h_PSEt = fs->make<TH1F>(("h_PSEt"+prefix).c_str() ,"h_PSEt",1000,0,1000);
h_PSEta = fs->make<TH1F>(("h_PSEta"+prefix).c_str() ,"h_PSEta",100,-5,5);
h_PSPhi = fs->make<TH1F>(("h_PSPhi"+prefix).c_str() ,"h_PSPhi",100,-5,5);
h_PSEtaVsEt = fs->make<TProfile>(("h_PSEtaVsEt"+prefix).c_str() ,"h_PSEtaVsEt",100,-5,5,0,1000);
h_PSEtaVsEt2D= fs->make<TH2D>(("h_PSEtaVsEt2D"+prefix).c_str() ,"h_PSEtaVsEt2D",100,-5,5,1000,0,1000);
 h_PSPhiVsEt = fs->make<TProfile>(("h_PSPhiVsEt"+prefix).c_str() ,"h_EcalPhiVsEt",100,-5,5,0,1000);
 h_PSPhiVsEt2D= fs->make<TH2D>(("h_PSPhiVsEt2D"+prefix).c_str() ,"h_PSPhiVsEt2D",100,-5,5,1000,0,1000);

h_PSEnergy = fs->make<TH1F>(("h_PSEnergy"+prefix).c_str() ,"h_PSEnergy",1000,0,1000);
h_PSEtaVsEnergy = fs->make<TProfile>(("h_PSEtaVsEnergy"+prefix).c_str() ,"h_PSEtaVsEnergy",100,-5,5,0,1000);
h_PSEtaVsEnergy2D= fs->make<TH2D>(("h_PSEtaVsEnergy2D"+prefix).c_str() ,"h_PSEtaVsEnergy2D",100,-5,5,1000,0,1000);
 h_PSPhiVsEnergy = fs->make<TProfile>(("h_PSPhiVsEnergy"+prefix).c_str() ,"h_EcalPhiVsEnergy",100,-5,5,0,1000);
 h_PSPhiVsEnergy2D= fs->make<TH2D>(("h_PSPhiVsEnergy2D"+prefix).c_str() ,"h_PSPhiVsEnergy2D",100,-5,5,1000,0,1000);


 h_TrackPt = fs->make<TH1F>(("h_TrackPt"+prefix).c_str() ,"h_TrackPt",1000,0,1000);
 h_TrackEta = fs->make<TH1F>(("h_TrackEta"+prefix).c_str() ,"h_TrackEta",100,-5,5);
 h_TrackPhi = fs->make<TH1F>(("h_TrackPhi"+prefix).c_str() ,"h_TrackPhi",100,-5,5);
 h_TrackEtaVsPt =  fs->make<TProfile>(("h_TrackEtaVsPt"+prefix).c_str() ,"h_TrackEtaVsPt",100,-5,5,0,1000);
 h_TrackEtaVsPt2D = fs->make<TH2D>(("h_TrackEtaVsPt2D"+prefix).c_str() ,"h_TrackEtaVsPt2D",100,-5,5,1000,0,1000);
 h_TrackPhiVsPt=  fs->make<TProfile>(("h_TrackPhiVsPt"+prefix).c_str() ,"h_TrackPhiVsPt",100,-5,5,0,1000);
 h_TrackPhiVsPt2D =  fs->make<TH2D>(("h_TrackPhiVsPt2D"+prefix).c_str() ,"h_TrackPhiVsPt2D",100,-5,5,1000,0,1000);

h_StandAloneMuonPt  = fs->make<TH1F>(("h_StandAloneMuonPt"+prefix).c_str() ,"h_StandAloneMuonPt",1000,0,1000);
h_StandAloneMuonEta = fs->make<TH1F>(("h_StandAloneMuonEta"+prefix).c_str() ,"h_StandAloneMuonEta",100,-5,5);
h_StandAloneMuonPhi = fs->make<TH1F>(("h_StandAloneMuonPhi"+prefix).c_str() ,"h_StandAloneMuonPhi",100,-5,5);
h_StandAloneMuonEtaVsPt  =  fs->make<TProfile>(("h_StandAloneMuonEtaVsPt"+prefix).c_str() ,"h_StandAloneMuonEtaVsPt",100,-5,5,0,1000);
h_StandAloneMuonEtaVsPt2D = fs->make<TH2D>(("h_StandAloneMuonEtaVsPt2D"+prefix).c_str() ,"h_StandAloneMuonEtaVsPt2D",100,-5,5,1000,0,1000);
h_StandAloneMuonPhiVsPt  =  fs->make<TProfile>(("h_StandAloneMuonPhiVsPt"+prefix).c_str() ,"h_StandAloneMuonPhiVsPt",100,-5,5,0,1000);
h_StandAloneMuonPhiVsPt2D = fs->make<TH2D>(("h_StandAloneMuonPhiVsPt2D"+prefix).c_str() ,"h_StandAloneMuonPhiVsPt2D",100,-5,5,1000,0,1000);


h_CaloMuonPt  = fs->make<TH1F>(("h_CaloMuonPt"+prefix).c_str() ,"h_CaloMuonPt",1000,0,1000);
h_CaloMuonEta = fs->make<TH1F>(("h_CaloMuonEta"+prefix).c_str() ,"h_CaloMuonEta",100,-5,5);
h_CaloMuonPhi = fs->make<TH1F>(("h_CaloMuonPhi"+prefix).c_str() ,"h_CaloMuonPhi",100,-5,5);
h_CaloMuonEtaVsPt  =  fs->make<TProfile>(("h_CaloMuonEtaVsPt"+prefix).c_str() ,"h_CaloMuonEtaVsPt",100,-5,5,0,1000);
h_CaloMuonEtaVsPt2D = fs->make<TH2D>(("h_CaloMuonEtaVsPt2D"+prefix).c_str() ,"h_CaloMuonEtaVsPt2D",100,-5,5,1000,0,1000);
h_CaloMuonPhiVsPt  =  fs->make<TProfile>(("h_CaloMuonPhiVsPt"+prefix).c_str() ,"h_CaloMuonPhiVsPt",100,-5,5,0,1000);
h_CaloMuonPhiVsPt2D = fs->make<TH2D>(("h_CaloMuonPhiVsPt2D"+prefix).c_str() ,"h_CaloMuonPhiVsPt2D",100,-5,5,1000,0,1000);

 

}


DetectorInfo::~DetectorInfo()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void DetectorInfo::Fill(const edm::Event& iEvent) {
   using namespace edm;
   using namespace std;
   using namespace reco;
   using namespace pat;

  iEvent.getByLabel("genParticles", _genParticles); 
   
  
  Handle< reco::TrackCollection > track;
  iEvent.getByLabel("generalTracks", track);

  Handle< reco::GenJetCollection > genTauJets;
  iEvent.getByLabel("tauGenJets",genTauJets);


  edm::Handle<std::vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel(std::string("addPileupInfo"), PupInfo);

    edm::Handle<reco::MuonCollection> rmuons;
    iEvent.getByLabel("muons",rmuons);

    edm::Handle<reco::VertexCollection> vtx;
   iEvent.getByLabel("offlinePrimaryVertices",vtx);
  
 
//  vector<pat::Muon>                    "patMuons"                  ""           "PATTuple"  
 std::vector<PileupSummaryInfo>::const_iterator PVI;


      edm::Handle<reco::PFJetCollection>  pfjets;
   iEvent.getByLabel("ak5PFJets", pfjets);

  iEvent.getByLabel("ak5GenJets", _genJets);
  

  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  //decay Mode
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFinding",_dmf);
  //Muon Veto

//  Handle<CaloTowerCollection> caloTowers;
//   iEvent.getByLabel( "towerMaker", caloTowers );
 

   Handle<PFRecHitCollection> hcal,ho,ps;
    iEvent.getByLabel("particleFlowRecHitHCAL","Cleaned",hcal);
    iEvent.getByLabel("particleFlowRecHitHO","Cleaned",ho);
    iEvent.getByLabel("particleFlowRecHitPS","Cleaned",ps);

    Handle<reco::CaloClusterCollection> EcalB, EcalE, EcalPS;//, hfEM;
  //  Handle<reco::CaloClusterCollection> hfEM;
     iEvent.getByLabel("particleFlowSuperClusterECAL","particleFlowBasicClusterECALBarrel",EcalB);
     iEvent.getByLabel("particleFlowSuperClusterECAL","particleFlowBasicClusterECALEndcap",EcalE);
     iEvent.getByLabel("particleFlowSuperClusterECAL","particleFlowBasicClusterECALPreshower",EcalPS);

//     iEvent.getByLabel("hfEMClusters",hfEM);

 
  //Muon 2 working pint
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection2",_mv1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumMuonRejection2",_mv2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection2",_mv3);
   
   // Muon 3 working points

   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection3",_mv31);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection3",_mv32);

   //Electron Veto

   iEvent.getByLabel("hpsPFTauDiscriminationByMVA5LooseElectronRejection",_ev1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMVA5MediumElectronRejection",_ev2);
   iEvent.getByLabel("hpsPFTauDiscriminationByMVA5TightElectronRejection",_ev3);
   
   // Isolation Working points
   
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseCombinedIsolationDBSumPtCorr",_iso1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumCombinedIsolationDBSumPtCorr",_iso2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightCombinedIsolationDBSumPtCorr",_iso3);
   
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseCombinedIsolationDBSumPtCorr3Hits",_iso4);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumCombinedIsolationDBSumPtCorr3Hits",_iso5);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightCombinedIsolationDBSumPtCorr3Hits",_iso6);
   
   iEvent.getByLabel("hpsPFTauDiscriminationByVLooseChargedIsolation",_hpsTau);
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseChargedIsolation",_hpsTau1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumChargedIsolation",_hpsTau2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightChargedIsolation",_hpsTau3);
   iEvent.getByLabel("hpsPFTauDiscriminationByRawChargedIsolationDBSumPtCorr",_rawCharged);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSumWeight1",_nw1);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSumWeight2",_nw2);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSumWeight1NQ",_nw1nq);

   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSumWeight2NQ",_nw2nq);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSum",_h1);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSumWeight1",_hw1);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSumWeight2",_hw2);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSumWeight1NQ",_hw1nq);
   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralHadronIsoPtSumWeight2NQ",_hw2nq);
   
   iEvent.getByLabel("hpsPFTauMVA3IsolationChargedIsoPtSum",_rawc);

   iEvent.getByLabel("hpsPFTauMVA3IsolationNeutralIsoPtSum",_rawn);

   iEvent.getByLabel("hpsPFTauMVA3IsolationPUcorrPtSum",_rawpu);

   iEvent.getByLabel("hpsPFTauDiscriminationByLooseCombinedIsolationRhoSumPtCorr3Hits",rho1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumCombinedIsolationRhoSumPtCorr3Hits",rho2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightCombinedIsolationRhoSumPtCorr3Hits",rho3);   
   


   
   int  nGoodVtx = 0;
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){
     
     if((vtxIt->isValid()) && !(vtxIt->isFake())) {
       
       nGoodVtx++;
     }
   }
   
     for (reco::GenJetCollection::const_iterator jet1 = _genJets->begin(); jet1 != _genJets->end(); ++jet1) {

      h_gen_pt_pure->Fill(jet1->pt());
      h_gen_eta_pure->Fill(jet1->eta());
     h_gen_phi_pure->Fill(jet1->phi());

}


for (reco::PFJetCollection::const_iterator jet2 = pfjets->begin(); jet2 != pfjets->end(); ++jet2) {

      h_pfjet_pt_pure->Fill(jet2->pt());
      h_pfjet_eta_pure->Fill(jet2->eta());
      h_pfjet_phi_pure->Fill(jet2->phi());

}

//energy for ECAL from CaloTriggers

for(PFRecHitCollection::const_iterator hcalRec = hcal->begin(); hcalRec != hcal->end(); ++hcalRec) {
      
      double etb = ((hcalRec->energy()) * sin(2*atan(exp((-1)*(hcalRec->position().eta())))));

      h_HcalEt->Fill(etb);
      h_HcalEnergy->Fill(hcalRec->energy());
      h_HcalEta->Fill(hcalRec->position().eta());
      h_HcalPhi->Fill(hcalRec->position().phi());
      h_HcalEtaVsEnergy->Fill(hcalRec->position().eta(), hcalRec->energy());

      h_HcalEtaVsEt->Fill(hcalRec->position().eta(), etb);
       h_HcalEtaVsEnergy2D->Fill(hcalRec->position().eta(), hcalRec->energy());
      h_HcalEtaVsEt2D->Fill(hcalRec->position().eta(), etb);
      h_HcalPhiVsEnergy->Fill(hcalRec->position().phi(), hcalRec->energy());
      h_HcalPhiVsEt->Fill(hcalRec->position().phi(), etb);
      h_HcalPhiVsEnergy2D->Fill(hcalRec->position().phi(), hcalRec->energy());
      h_HcalPhiVsEt2D->Fill(hcalRec->position().phi(), etb);

}

for(PFRecHitCollection::const_iterator hoRec = ho->begin(); hoRec != ho->end(); ++hoRec) {

      double etb1 = ((hoRec->energy()) * sin(2*atan(exp((-1)*(hoRec->position().eta())))));
      h_HOEnergy->Fill(hoRec->energy());
      h_HOEt->Fill(etb1);
      h_HOEta->Fill(hoRec->position().eta());
      h_HOPhi->Fill(hoRec->position().phi());
      h_HOEtaVsEnergy->Fill(hoRec->position().eta(), hoRec->energy());
      h_HOEtaVsEt->Fill(hoRec->position().eta(), etb1);
      h_HOEtaVsEnergy2D->Fill(hoRec->position().eta(), hoRec->energy()); 
      h_HOEtaVsEt2D->Fill(hoRec->position().eta(), etb1);
      h_HOPhiVsEnergy->Fill(hoRec->position().phi(), hoRec->energy());
      h_HOPhiVsEt->Fill(hoRec->position().phi(), etb1);
      h_HOPhiVsEnergy2D->Fill(hoRec->position().phi(), hoRec->energy()); 
      h_HOPhiVsEt2D->Fill(hoRec->position().phi(), etb1);

}

for(PFRecHitCollection::const_iterator psRec = ps->begin(); psRec != ps->end(); ++psRec) {

      double etb2 = ((psRec->energy()) * sin(2*atan(exp((-1)*(psRec->position().eta())))));
      h_PSEt->Fill(etb2);
      h_PSEta->Fill(psRec->position().eta());
      h_PSPhi->Fill(psRec->position().phi());
      h_PSEtaVsEt->Fill(psRec->position().eta(), etb2);
      h_PSEtaVsEt2D->Fill(psRec->position().eta(), etb2);
      h_PSPhiVsEt->Fill(psRec->position().phi(), etb2);
      h_PSPhiVsEt2D->Fill(psRec->position().phi(), etb2);

      h_PSEnergy->Fill(psRec->energy());
      h_PSEtaVsEnergy->Fill(psRec->position().eta(), psRec->energy());
      h_PSEtaVsEnergy2D->Fill(psRec->position().eta(), psRec->energy());
      h_PSPhiVsEnergy->Fill(psRec->position().phi(), psRec->energy());
      h_PSPhiVsEnergy2D->Fill(psRec->position().phi(), psRec->energy());

}

for(CaloClusterCollection::const_iterator calE = EcalE->begin(); calE != EcalE->end(); ++calE) {
   
      double etb3 = ((calE->energy()) * sin(2*atan(exp((-1)*(calE->eta()))))); 
      h_EcalEEt->Fill(etb3);
      h_EcalEEta->Fill(calE->eta());
      h_EcalEPhi->Fill(calE->phi());
      h_EcalEEtaVsEt->Fill(calE->eta(), etb3);
      h_EcalEEtaVsEt2D->Fill(calE->eta(), etb3);
      h_EcalEPhiVsEt->Fill(calE->phi(),etb3);
      h_EcalEPhiVsEt2D->Fill(calE->phi(), etb3);

      h_EcalEEnergy->Fill(calE->energy());
      h_EcalEEtaVsEnergy->Fill(calE->eta(), calE->energy());
      h_EcalEEtaVsEnergy2D->Fill(calE->eta(), calE->energy());
      h_EcalEPhiVsEnergy->Fill(calE->phi(), calE->energy());
      h_EcalEPhiVsEnergy2D->Fill(calE->phi(), calE->energy());
 

}

for(CaloClusterCollection::const_iterator calB = EcalB->begin(); calB != EcalB->end(); ++calB) {
   
            double etb4 = ((calB->energy()) * sin(2*atan(exp((-1)*(calB->eta()))))); 
      h_EcalBEt->Fill(etb4);
      h_EcalBEta->Fill(calB->eta());
      h_EcalBPhi->Fill(calB->phi());
      h_EcalBEtaVsEt->Fill(calB->eta(), etb4);
      h_EcalBEtaVsEt2D->Fill(calB->eta(), etb4);
      h_EcalBPhiVsEt->Fill(calB->phi(), etb4);
      h_EcalBPhiVsEt2D->Fill(calB->phi(), etb4);
 
   h_EcalBEnergy->Fill(calB->energy());
   h_EcalBEtaVsEnergy->Fill(calB->eta(), calB->energy());
      h_EcalBEtaVsEnergy2D->Fill(calB->eta(), calB->energy());
      h_EcalBPhiVsEnergy->Fill(calB->phi(), calB->energy());
      h_EcalBPhiVsEnergy2D->Fill(calB->phi(), calB->energy());
 


}


for(CaloClusterCollection::const_iterator calPS = EcalPS->begin(); calPS!= EcalPS->end(); ++calPS) {
    
      double etb5= ((calPS->energy()) * sin(2*atan(exp((-1)*(calPS->eta())))));
      h_EcalPSEt->Fill(etb5);
      h_EcalPSEta->Fill(calPS->eta());
      h_EcalPSPhi->Fill(calPS->phi());
      h_EcalPSEtaVsEt->Fill(calPS->eta(), etb5);
      h_EcalPSEtaVsEt2D->Fill(calPS->eta(), etb5);
      h_EcalPSPhiVsEt->Fill(calPS->phi(), etb5);
      h_EcalPSPhiVsEt2D->Fill(calPS->phi(), etb5);
 
      h_EcalPSEnergy->Fill(calPS->energy());
      h_EcalPSEtaVsEnergy->Fill(calPS->eta(), calPS->energy());
      h_EcalPSEtaVsEnergy2D->Fill(calPS->eta(), calPS->energy());
      h_EcalPSPhiVsEnergy->Fill(calPS->phi(), calPS->energy());
      h_EcalPSPhiVsEnergy2D->Fill(calPS->phi(), calPS->energy());

}

for(reco::TrackCollection::const_iterator trk = track->begin(); trk !=  track->end() ; ++trk) {

    h_TrackPt->Fill(trk->pt());
    h_TrackEta->Fill(trk->eta());
    h_TrackPhi->Fill(trk->phi());
    h_TrackEtaVsPt->Fill(trk->eta() , trk->pt());
    h_TrackEtaVsPt2D->Fill(trk->eta() , trk->pt());
    h_TrackPhiVsPt->Fill(trk->phi() , trk->pt());
    h_TrackPhiVsPt2D->Fill(trk->phi() , trk->pt());
}


for(reco::MuonCollection::const_iterator mu = rmuons->begin(); mu != rmuons->end() ; ++mu){

   if(mu->isStandAloneMuon()) {
 
   h_StandAloneMuonPt->Fill(mu->pt());
   h_StandAloneMuonEta->Fill(mu->eta());
   h_StandAloneMuonPhi->Fill(mu->phi());

   h_StandAloneMuonEtaVsPt->Fill(mu->eta(),mu->pt());
   h_StandAloneMuonEtaVsPt2D->Fill(mu->eta(),mu->pt());

   h_StandAloneMuonPhiVsPt->Fill(mu->phi(),mu->pt());
   h_StandAloneMuonPhiVsPt2D->Fill(mu->phi(),mu->pt());

   }

   if(mu->isCaloMuon()) {

    h_CaloMuonPt->Fill(mu->pt());
    h_CaloMuonEta->Fill(mu->eta());
    h_CaloMuonPhi->Fill(mu->phi());
 
    h_CaloMuonEtaVsPt->Fill(mu->eta(),mu->pt());
    h_CaloMuonEtaVsPt2D->Fill(mu->eta(),mu->pt());
 
    h_CaloMuonPhiVsPt->Fill(mu->phi(),mu->pt());
    h_CaloMuonPhiVsPt2D->Fill(mu->phi(),mu->pt());


   }

}

// end of event Loop   
}


