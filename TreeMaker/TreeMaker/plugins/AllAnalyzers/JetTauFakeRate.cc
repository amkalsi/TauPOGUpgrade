#include "./JetTauFakeRate.h"                                                                                                                                        
#include "DataFormats/TrackReco/interface/HitPattern.h"

JetTauFakeRate::JetTauFakeRate(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
{
  
  //now do what ever initialization is needed
 JetCorrectionService = iConfig.getParameter<std::string> ("JetCorrectionService"); 
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

  //h_RPC_FourthStation_etag1p2 = fs->make<TH1F>(("h_RPC_FourthStation_etag1p2"+prefix).c_str() ,"h_RPC_FourthStation_etag1p2",15,0,15);
  DR_After_Matching = fs->make<TH1F>(("DR_After_Matching"+prefix).c_str() ,"DR_After_Matching",500,0,8);
  h_Den_JetPt = fs->make<TH1F>(("h_Den_JetPt"+prefix).c_str() ,"h_Den_JetPt",100,0,700);
  h_DMF_JetPt = fs->make<TH1F>(("h_DMF_JetPt"+prefix).c_str() ,"h_DMF_JetPt",100,0,700);

  h_Loose3_JetPt = fs->make<TH1F>(("h_Loose3_JetPt"+prefix).c_str() ,"h_Loose3_JetPt",100,0,700);
  h_Medium3_JetPt = fs->make<TH1F>(("h_Medium3_JetPt"+prefix).c_str() ,"h_Medium3_JetPt",100,0,700);
  h_Tight3_JetPt = fs->make<TH1F>(("h_Tight3_JetPt"+prefix).c_str() ,"h_Tight3_JetPt",100,0,700);
  h_VLooseChar_JetPt = fs->make<TH1F>(("h_VLooseChar_JetPt"+prefix).c_str() ,"h_VLooseChar_JetPt",100,0,700);
  h_LooseChar_JetPt = fs->make<TH1F>(("h_LooseChar_JetPt"+prefix).c_str() ,"h_LooseChar_JetPt",100,0,700);
  h_MediumChar_JetPt = fs->make<TH1F>(("h_MediumChar_JetPt"+prefix).c_str() ,"h_MediumChar_JetPt",100,0,700);
  h_TightChar_JetPt = fs->make<TH1F>(("h_TightChar_JetPt"+prefix).c_str() ,"h_TightChar_JetPt",100,0,700);

  h_Den_TauPt = fs->make<TH1F>(("h_Den_TauPt"+prefix).c_str() ,"h_Den_TauPt",100,0,700);
  h_DMF_TauPt = fs->make<TH1F>(("h_DMF_TauPt"+prefix).c_str() ,"h_DMF_TauPt",100,0,700);

  h_Loose3_TauPt = fs->make<TH1F>(("h_Loose3_TauPt"+prefix).c_str() ,"h_Loose3_TauPt",100,0,700);
  h_Medium3_TauPt = fs->make<TH1F>(("h_Medium3_TauPt"+prefix).c_str() ,"h_Medium3_TauPt",100,0,700);
  h_Tight3_TauPt = fs->make<TH1F>(("h_Tight3_TauPt"+prefix).c_str() ,"h_Tight3_TauPt",100,0,700);
  h_VLooseChar_TauPt = fs->make<TH1F>(("h_VLooseChar_TauPt"+prefix).c_str() ,"h_VLooseChar_TauPt",100,0,700);
  h_LooseChar_TauPt = fs->make<TH1F>(("h_LooseChar_TauPt"+prefix).c_str() ,"h_LooseChar_TauPt",100,0,700);
  h_MediumChar_TauPt = fs->make<TH1F>(("h_MediumChar_TauPt"+prefix).c_str() ,"h_MediumChar_TauPt",100,0,700);
  h_TightChar_TauPt = fs->make<TH1F>(("h_TightChar_TauPt"+prefix).c_str() ,"h_TightChar_TauPt",100,0,700);


  h_Den_JetEta = fs->make<TH1F>(("h_Den_JetEta"+prefix).c_str() ,"h_Den_JetEta",100,-5,5);
  h_DMF_JetEta = fs->make<TH1F>(("h_DMF_JetEta"+prefix).c_str() ,"h_DMF_JetEta",100,-5,5);

  h_Loose3_JetEta = fs->make<TH1F>(("h_Loose3_JetEta"+prefix).c_str() ,"h_Loose3_JetEta",100,-5,5);
  h_Medium3_JetEta = fs->make<TH1F>(("h_Medium3_JetEta"+prefix).c_str() ,"h_Medium3_JetEta",100,-5,5);
  h_Tight3_JetEta = fs->make<TH1F>(("h_Tight3_JetEta"+prefix).c_str() ,"h_Tight3_JetEta",100,-5,5);
  h_VLooseChar_JetEta = fs->make<TH1F>(("h_VLooseChar_JetEta"+prefix).c_str() ,"h_VLooseChar_JetEta",100,-5,5);
  h_LooseChar_JetEta = fs->make<TH1F>(("h_LooseChar_JetEta"+prefix).c_str() ,"h_LooseChar_JetEta",100,-5,5);
  h_MediumChar_JetEta = fs->make<TH1F>(("h_MediumChar_JetEta"+prefix).c_str() ,"h_MediumChar_JetEta",100,-5,5);
  h_TightChar_JetEta = fs->make<TH1F>(("h_TightChar_JetEta"+prefix).c_str() ,"h_TightChar_JetEta",100,-5,5);


  h_Den_TauEta = fs->make<TH1F>(("h_Den_TauEta"+prefix).c_str() ,"h_Den_TauEta",100,-5,5);
   h_DMF_TauEta = fs->make<TH1F>(("h_DMF_TauEta"+prefix).c_str() ,"h_DMF_TauEta",100,-5,5);
  h_Loose3_TauEta = fs->make<TH1F>(("h_Loose3_TauEta"+prefix).c_str() ,"h_Loose3_TauEta",100,-5,5);
  h_Medium3_TauEta = fs->make<TH1F>(("h_Medium3_TauEta"+prefix).c_str() ,"h_Medium3_TauEta",100,-5,5);
  h_Tight3_TauEta = fs->make<TH1F>(("h_Tight3_TauEta"+prefix).c_str() ,"h_Tight3_TauEta",100,-5,5);
  h_VLooseChar_TauEta = fs->make<TH1F>(("h_VLooseChar_TauEta"+prefix).c_str() ,"h_VLooseChar_TauEta",100,-5,5);
  h_LooseChar_TauEta = fs->make<TH1F>(("h_LooseChar_TauEta"+prefix).c_str() ,"h_LooseChar_TauEta",100,-5,5);
  h_MediumChar_TauEta = fs->make<TH1F>(("h_MediumChar_TauEta"+prefix).c_str() ,"h_MediumChar_TauEta",100,-5,5);
  h_TightChar_TauEta = fs->make<TH1F>(("h_TightChar_TauEta"+prefix).c_str() ,"h_TightChar_TauEta",100,-5,5);


  h_Den_JetPhi = fs->make<TH1F>(("h_Den_JetPhi"+prefix).c_str() ,"h_Den_JetPhi",100,-5,5);
  h_DMF_JetPhi = fs->make<TH1F>(("h_DMF_JetPhi"+prefix).c_str() ,"h_DMF_JetPhi",100,-5,5);
  h_Loose3_JetPhi = fs->make<TH1F>(("h_Loose3_JetPhi"+prefix).c_str() ,"h_Loose3_JetPhi",100,-5,5);
  h_Medium3_JetPhi = fs->make<TH1F>(("h_Medium3_JetPhi"+prefix).c_str() ,"h_Medium3_JetPhi",100,-5,5);
  h_Tight3_JetPhi = fs->make<TH1F>(("h_Tight3_JetPhi"+prefix).c_str() ,"h_Tight3_JetPhi",100,-5,5);
  h_VLooseChar_JetPhi = fs->make<TH1F>(("h_VLooseChar_JetPhi"+prefix).c_str() ,"h_VLooseChar_JetPhi",100,-5,5);
  h_LooseChar_JetPhi = fs->make<TH1F>(("h_LooseChar_JetPhi"+prefix).c_str() ,"h_LooseChar_JetPhi",100,-5,5);
  h_MediumChar_JetPhi = fs->make<TH1F>(("h_MediumChar_JetPhi"+prefix).c_str() ,"h_MediumChar_JetPhi",100,-5,5);
  h_TightChar_JetPhi = fs->make<TH1F>(("h_TightChar_JetPhi"+prefix).c_str() ,"h_TightChar_JetPhi",100,-5,5);


  h_Den_TauPhi = fs->make<TH1F>(("h_Den_TauPhi"+prefix).c_str() ,"h_Den_TauPhi",100,-5,5);
  h_DMF_TauPhi = fs->make<TH1F>(("h_DMF_TauPhi"+prefix).c_str() ,"h_DMF_TauPhi",100,-5,5);
  h_Loose3_TauPhi = fs->make<TH1F>(("h_Loose3_TauPhi"+prefix).c_str() ,"h_Loose3_TauPhi",100,-5,5);
  h_Medium3_TauPhi = fs->make<TH1F>(("h_Medium3_TauPhi"+prefix).c_str() ,"h_Medium3_TauPhi",100,-5,5);
  h_Tight3_TauPhi = fs->make<TH1F>(("h_Tight3_TauPhi"+prefix).c_str() ,"h_Tight3_TauPhi",100,-5,5);
  h_VLooseChar_TauPhi = fs->make<TH1F>(("h_VLooseChar_TauPhi"+prefix).c_str() ,"h_VLooseChar_TauPhi",100,-5,5);
  h_LooseChar_TauPhi = fs->make<TH1F>(("h_LooseChar_TauPhi"+prefix).c_str() ,"h_LooseChar_TauPhi",100,-5,5);
  h_MediumChar_TauPhi = fs->make<TH1F>(("h_MediumChar_TauPhi"+prefix).c_str() ,"h_MediumChar_TauPhi",100,-5,5);
  h_TightChar_TauPhi = fs->make<TH1F>(("h_TightChar_TauPhi"+prefix).c_str() ,"h_TightChar_TauPhi",100,-5,5);

  h_Den_JetToTauPt = fs->make<TH1F>(("h_Den_JetToTauPt"+prefix).c_str() ,"h_Den_JetToTauPt",100,-2,2);
  h_DMF_JetToTauPt = fs->make<TH1F>(("h_DMF_JetToTauPt"+prefix).c_str() ,"h_DMF_JetToTauPt",100,-2,2); 
  h_Loose3_JetToTauPt = fs->make<TH1F>(("h_Loose3_JetToTauPt"+prefix).c_str() ,"h_Loose3_JetToTauPt",100,-2,2);
  h_Medium3_JetToTauPt = fs->make<TH1F>(("h_Medium3_JetToTauPt"+prefix).c_str() ,"h_Medium3_JetToTauPt",100,-2,2);
  h_Tight3_JetToTauPt = fs->make<TH1F>(("h_Tight3_JetToTauPt"+prefix).c_str() ,"h_Tight3_JetToTauPt",100,-2,2);
  h_VLooseChar_JetToTauPt = fs->make<TH1F>(("h_VLooseChar_JetToTauPt"+prefix).c_str() ,"h_VLooseChar_JetToTauPt",100,-2,2);
  h_LooseChar_JetToTauPt = fs->make<TH1F>(("h_LooseChar_JetToTauPt"+prefix).c_str() ,"h_LooseChar_JetToTauPt",100,-2,2);
  h_MediumChar_JetToTauPt = fs->make<TH1F>(("h_MediumChar_JetToTauPt"+prefix).c_str() ,"h_MediumChar_JetToTauPt",100,-2,2);
  h_TightChar_JetToTauPt = fs->make<TH1F>(("h_TightChar_JetToTauPt"+prefix).c_str() ,"h_TightChar_JetToTauPt",100,-2,2);

  h_Den_NVtx  = fs->make<TH1F>(("h_Den_NVtx"+prefix).c_str() ,"h_Den_NVtx",400,0,400);
  h_Den_NGood  = fs->make<TH1F>(("h_Den_NGood"+prefix).c_str() ,"h_Den_NGood",400,0,400);
  h_Den_NBest  = fs->make<TH1F>(("h_Den_NBest"+prefix).c_str() ,"h_Den_NBest",400,0,400);

  h_Loose3_NVtx  = fs->make<TH1F>(("h_Loose3_NVtx"+prefix).c_str() ,"h_Loose3_NVtx",400,0,400);
  h_Loose3_NGood  = fs->make<TH1F>(("h_Loose3_NGood"+prefix).c_str() ,"h_Loose3_NGood",400,0,400);
  h_Loose3_NBest  = fs->make<TH1F>(("h_Loose3_NBest"+prefix).c_str() ,"h_Loose3_NBest",400,0,400);

  h_DMF_NVtx  = fs->make<TH1F>(("h_DMF_NVtx"+prefix).c_str() ,"h_DMF_NVtx",400,0,400);
  h_DMF_NGood  = fs->make<TH1F>(("h_DMF_NGood"+prefix).c_str() ,"h_DMF_NGood",400,0,400);
  h_DMF_NBest  = fs->make<TH1F>(("h_DMF_NBest"+prefix).c_str() ,"h_DMF_NBest",400,0,400);

  h_Medium3_NVtx  = fs->make<TH1F>(("h_Medium3_NVtx"+prefix).c_str() ,"h_Medium3_NVtx",400,0,400);
  h_Medium3_NGood  = fs->make<TH1F>(("h_Medium3_NGood"+prefix).c_str() ,"h_Medium3_NGood",400,0,400);
  h_Medium3_NBest  = fs->make<TH1F>(("h_Medium3_NBest"+prefix).c_str() ,"h_Medium3_NBest",400,0,400);

  h_Tight3_NVtx  = fs->make<TH1F>(("h_Tight3_NVtx"+prefix).c_str() ,"h_Tight3_NVtx",400,0,400);
  h_Tight3_NGood  = fs->make<TH1F>(("h_Tight3_NGood"+prefix).c_str() ,"h_Tight3_NGood",400,0,400);
  h_Tight3_NBest  = fs->make<TH1F>(("h_Tight3_NBest"+prefix).c_str() ,"h_Tight3_NBest",400,0,400);

  h_VLooseChar_NVtx  = fs->make<TH1F>(("h_VLooseChar_NVtx"+prefix).c_str() ,"h_VLooseChar_NVtx",400,0,400);
  h_VLooseChar_NGood  = fs->make<TH1F>(("h_VLooseChar_NGood"+prefix).c_str() ,"h_VLooseChar_NGood",400,0,400);
  h_VLooseChar_NBest  = fs->make<TH1F>(("h_VLooseChar_NBest"+prefix).c_str() ,"h_VLooseChar_NBest",400,0,400);


  h_LooseChar_NVtx  = fs->make<TH1F>(("h_LooseChar_NVtx"+prefix).c_str() ,"h_LooseChar_NVtx",400,0,400);
  h_LooseChar_NGood  = fs->make<TH1F>(("h_LooseChar_NGood"+prefix).c_str() ,"h_LooseChar_NGood",400,0,400);
  h_LooseChar_NBest  = fs->make<TH1F>(("h_LooseChar_NBest"+prefix).c_str() ,"h_LooseChar_NBest",400,0,400);

  h_MediumChar_NVtx  = fs->make<TH1F>(("h_MediumChar_NVtx"+prefix).c_str() ,"h_MediumChar_NVtx",400,0,400);
  h_MediumChar_NGood  = fs->make<TH1F>(("h_MediumChar_NGood"+prefix).c_str() ,"h_MediumChar_NGood",400,0,400);
  h_MediumChar_NBest  = fs->make<TH1F>(("h_MediumChar_NBest"+prefix).c_str() ,"h_MediumChar_NBest",400,0,400);

  h_TightChar_NVtx  = fs->make<TH1F>(("h_TightChar_NVtx"+prefix).c_str() ,"h_TightChar_NVtx",400,0,400);
  h_TightChar_NGood  = fs->make<TH1F>(("h_TightChar_NGood"+prefix).c_str() ,"h_TightChar_NGood",400,0,400);
  h_TightChar_NBest  = fs->make<TH1F>(("h_TightChar_NBest"+prefix).c_str() ,"h_TightChar_NBest",400,0,400);

 h_gen_pt_pure  = fs->make<TH1F>(("h_gen_pt_pure"+prefix).c_str() ,"h_gen_pt_pure",200,0,1400);                                                                      
  h_gen_eta_pure = fs->make<TH1F>(("h_gen_eta_pure"+prefix).c_str() ,"h_gen_eta_pure",100,-5,5);
  h_gen_phi_pure = fs->make<TH1F>(("h_gen_phi_pure"+prefix).c_str() ,"h_gen_phi_pure",100,-5,5);

  h_pfjet_pt_pure  = fs->make<TH1F>(("h_pfjet_pt_pure"+prefix).c_str() ,"h_pfjet_pt_pure",200,0,1400);
  h_pfjet_eta_pure = fs->make<TH1F>(("h_pfjet_eta_pure"+prefix).c_str() ,"h_pfjet_eta_pure",100,-5,5);
  h_pfjet_phi_pure = fs->make<TH1F>(("h_pfjet_phi_pure"+prefix).c_str() ,"h_pfjet_phi_pure",100,-5,5);




}


JetTauFakeRate::~JetTauFakeRate()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called for each event  ------------
void JetTauFakeRate::Fill(const edm::Event& iEvent,const edm::EventSetup& iSetup) {
  using namespace edm;
  using namespace std;
  using namespace reco;
  using namespace pat;
  
  iEvent.getByLabel("genParticles", _genParticles); 
  
  Handle< reco::TrackCollection > track;
  iEvent.getByLabel("generalTracks", track);
  
  Handle< reco::GenJetCollection > genTauJets;
  iEvent.getByLabel("tauGenJets",genTauJets);
  
  edm::Handle<pat::JetCollection> pfjet;
  iEvent.getByLabel("selectedPatJets", pfjet);
  
  edm::Handle<std::vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel(std::string("addPileupInfo"), PupInfo);
  
  edm::Handle<reco::MuonCollection> rmuons;
  iEvent.getByLabel("muons",rmuons);
  
  edm::Handle<reco::VertexCollection> vtx;
  iEvent.getByLabel("offlinePrimaryVertices",vtx);

  //  vector<pat::Muon>                    "patMuons"                  ""           "PATTuple"  
 
  
  iEvent.getByLabel("ak5GenJets", _genJets);
  
  
  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  //decay Mode
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFinding",_dmf);
  //Muon Veto

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


  // vertices

  int  nGoodVtx = 0; 
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){ 

      if((vtxIt->isValid()) && !(vtxIt->isFake())) {
     
         nGoodVtx++;
    }
   }


   int  nBestVtx = 0;
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){

      if((vtxIt->isValid()) && !(vtxIt->isFake())) {

       if(vtxIt->ndof() < 4.) continue; 
       if(abs(vtxIt->z()) > 24.) continue;
     // if(passRecoVertexCuts(*vtxIt))
      double vtxdxy = sqrt((vtxIt->x()*vtxIt->x()) + (vtxIt->y()*vtxIt->y()));
      if(vtxdxy >= 2.0) continue; 
     nBestVtx++;
    }
  }

  edm::Handle<reco::PFJetCollection>  pfjets;
  iEvent.getByLabel("ak5PFJets", pfjets);


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
  
  const JetCorrector* corrector = JetCorrector::getJetCorrector(JetCorrectionService,iSetup);
  
  
  
  for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
    reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
    
    bool TauEtaCuts = false;
    bool RecoptCut = false;
    bool DecayModeFinding = false;
    bool IsoDiscL = false;    
    bool IsoDiscM = false;  
    bool IsoDiscT = false;  
    
    bool IsoDiscVLC = false;
    bool IsoDiscLC   = false;
    bool IsoDiscMC = false;
    bool IsoDiscTC = false;
    

      
    if(abs(tauCandidate->eta()) < 2.3) TauEtaCuts = true;
    
    if((tauCandidate->pt()) > 20) RecoptCut = true;
    
    if((*_dmf)[tauCandidate] > 0.5) DecayModeFinding = true; 
    
    
    if((*_iso4)[tauCandidate] > 0.5) IsoDiscL = true;
    if((*_iso5)[tauCandidate] > 0.5) IsoDiscM = true;
    if((*_iso6)[tauCandidate] > 0.5) IsoDiscT = true; 
    
    
    if((*_hpsTau)[tauCandidate] > 0.5) IsoDiscVLC = true; 
    
    if((*_hpsTau1)[tauCandidate] > 0.5) IsoDiscLC = true; 

    if((*_hpsTau2)[tauCandidate] > 0.5) IsoDiscMC = true; 

    if((*_hpsTau3)[tauCandidate] > 0.5) IsoDiscTC = true; 
    
    reco::Candidate::LorentzVector rawJetP4 = tauCandidate->jetRef()->p4();
    reco::Candidate::LorentzVector corrJetP4 = rawJetP4;
    
    double jec = corrector->correction(*(tauCandidate->jetRef()),iEvent,iSetup);
    
    corrJetP4 *= jec;
    
    ////  denominator Tau Pt > 20 and eta < 2.3
    
    //denominator Jet Pt 20 and Eta < 2.3

    if((corrJetP4.pt() > 20) && (fabs(corrJetP4.eta()) < 2.3) ){

 if ( vtx->size() >= 1 ) {
        const reco::Vertex::Point& vertexPos = vtx->at(0).position();


        std::vector<reco::PFCandidatePtr> pfCands = tauCandidate->jetRef()->getPFConstituents();
         double temppt = -999;
        for ( std::vector<reco::PFCandidatePtr>::const_iterator jetConstituent = pfCands.begin(); jetConstituent != pfCands.end(); ++jetConstituent ) {
         if((*jetConstituent)->trackRef().isNonnull()) {

           if(((*jetConstituent)->trackRef()->pt()) > temppt ) {
           temppt = ((*jetConstituent)->trackRef()->pt());
           zof = ((*jetConstituent)->trackRef()->dz(vertexPos));
      }
   }

  }
}
      
      if(abs(zof) >= 0.2 ) continue;
 
      h_Den_JetPt->Fill(rawJetP4.pt());
      h_Den_JetEta->Fill(rawJetP4.eta());
      h_Den_JetPhi->Fill(rawJetP4.phi());
      h_Den_NVtx->Fill(vtx->size());
      h_Den_NGood->Fill(nGoodVtx);
      h_Den_NBest->Fill(nBestVtx);
      h_Den_TauPt->Fill(corrJetP4.pt());
      h_Den_TauEta->Fill(corrJetP4.eta());
      h_Den_TauPhi->Fill(corrJetP4.phi());
 
    if(RecoptCut && TauEtaCuts && DecayModeFinding) { 
    
h_DMF_JetPt->Fill(rawJetP4.pt());
h_DMF_JetEta->Fill(rawJetP4.eta());   
h_DMF_JetPhi->Fill(rawJetP4.phi());
h_DMF_NVtx->Fill(vtx->size());
h_DMF_NGood->Fill(nGoodVtx);
h_DMF_NBest->Fill(nBestVtx);
h_DMF_TauPt->Fill(corrJetP4.pt());
h_DMF_TauEta->Fill(corrJetP4.eta());
h_DMF_TauPhi->Fill(corrJetP4.phi());
  
     
      
      if(IsoDiscL) {
	
	h_Loose3_JetPt->Fill(rawJetP4.pt());
	h_Loose3_JetEta->Fill(rawJetP4.eta());
	h_Loose3_JetPhi->Fill(rawJetP4.phi());   
	h_Loose3_NVtx->Fill(vtx->size());
	h_Loose3_NGood->Fill(nGoodVtx);
	h_Loose3_NBest->Fill(nBestVtx);
	
	h_Loose3_TauPt->Fill(corrJetP4.pt());
	h_Loose3_TauEta->Fill(corrJetP4.eta());
	h_Loose3_TauPhi->Fill(corrJetP4.phi());
	
      }


      if(IsoDiscM) {
	
	h_Medium3_JetPt->Fill(rawJetP4.pt());
	h_Medium3_JetEta->Fill(rawJetP4.eta());
	h_Medium3_JetPhi->Fill(rawJetP4.phi());  
	h_Medium3_NVtx->Fill(vtx->size());
	h_Medium3_NGood->Fill(nGoodVtx);
	h_Medium3_NBest->Fill(nBestVtx);
	
	h_Medium3_TauPt->Fill(corrJetP4.pt());
	h_Medium3_TauEta->Fill(corrJetP4.eta());
	
	h_Medium3_TauPhi->Fill(corrJetP4.phi());
	
      }
      
      
      if(IsoDiscT) {
	
	h_Tight3_JetPt->Fill(rawJetP4.pt());
	h_Tight3_JetEta->Fill(rawJetP4.eta());
	h_Tight3_JetPhi->Fill(rawJetP4.phi()); 
	h_Tight3_NVtx->Fill(vtx->size());
	h_Tight3_NGood->Fill(nGoodVtx);
	h_Tight3_NBest->Fill(nBestVtx);
	
	h_Tight3_TauPt->Fill(corrJetP4.pt());
	h_Tight3_TauEta->Fill(corrJetP4.eta());
	h_Tight3_TauPhi->Fill(corrJetP4.phi());
	
      }
      
      if(IsoDiscVLC) {
	
	h_VLooseChar_JetPt->Fill(rawJetP4.pt());
	h_VLooseChar_JetEta->Fill(rawJetP4.eta());
	h_VLooseChar_JetPhi->Fill(rawJetP4.phi());

	
	h_VLooseChar_NVtx->Fill(vtx->size());
	h_VLooseChar_NGood->Fill(nGoodVtx);
	h_VLooseChar_NBest->Fill(nBestVtx);
	
	h_VLooseChar_TauPt->Fill(corrJetP4.pt());
	h_VLooseChar_TauEta->Fill(corrJetP4.eta());
	h_VLooseChar_TauPhi->Fill(corrJetP4.phi());
	
      }
      
      if(IsoDiscLC) {
	
	
	
	h_LooseChar_NVtx->Fill(vtx->size());
	h_LooseChar_NGood->Fill(nGoodVtx);
	h_LooseChar_NBest->Fill(nBestVtx);
	
	
	h_LooseChar_JetPt->Fill(rawJetP4.pt());
	h_LooseChar_JetEta->Fill(rawJetP4.eta());
	h_LooseChar_JetPhi->Fill(rawJetP4.phi());
	
        h_LooseChar_TauPt->Fill(corrJetP4.pt());
	h_LooseChar_TauEta->Fill(corrJetP4.eta());
	h_LooseChar_TauPhi->Fill(corrJetP4.phi());

	
      }
      
      if(IsoDiscMC) {

	
	h_MediumChar_NVtx->Fill(vtx->size());
	h_MediumChar_NGood->Fill(nGoodVtx);
	h_MediumChar_NBest->Fill(nBestVtx);
	
	
	h_MediumChar_JetPt->Fill(rawJetP4.pt());
	h_MediumChar_JetEta->Fill(rawJetP4.eta());
	h_MediumChar_JetPhi->Fill(rawJetP4.phi());
	
        h_MediumChar_TauPt->Fill(corrJetP4.pt());
	h_MediumChar_TauEta->Fill(corrJetP4.eta());
	h_MediumChar_TauPhi->Fill(corrJetP4.phi());

	    }

	    if(IsoDiscTC) {



	      h_TightChar_NVtx->Fill(vtx->size());
	      h_TightChar_NGood->Fill(nGoodVtx);
	      h_TightChar_NBest->Fill(nBestVtx);

	      h_TightChar_JetPt->Fill(rawJetP4.pt());
	      h_TightChar_JetEta->Fill(rawJetP4.eta());
	      h_TightChar_JetPhi->Fill(rawJetP4.phi());

	      h_TightChar_TauPt->Fill(corrJetP4.pt());
	      h_TightChar_TauEta->Fill(corrJetP4.eta());
	      h_TightChar_TauPhi->Fill(corrJetP4.phi());

	      

	    }



	  }
      }	  
    }
}


// ------------ method called once each job just before starting event loop  ------------

/*
  for (reco::PFJetCollection::const_iterator jet1 = pfjets->begin(); jet1 != pfjets->end(); ++jet1) {
       
       scale = corrector->correction(*jet1,iEvent,iSetup);
       
       double jetcorrpt = scale*(jet1->pt());

*/
bool JetTauFakeRate::OverlapWithJet(double Taueta , double Tauphi ,edm::Handle<reco::PFJetCollection> jets ,int  &index,const edm::Event& iEvent,const edm::EventSetup& iSetup ) {
  double drtmp =0.5; 
  int tmpindex =0 ;
  bool jetfound = false;

for (reco::PFJetCollection::const_iterator jet1 = jets->begin(); jet1 != jets->end(); ++jet1) {

    double dr =reco::deltaR(Taueta, Tauphi,jet1->eta(),jet1->phi());
//    cout<<"dr"<<dr<<endl;
    if(dr < drtmp){
     cout<<"dr"<<dr<<endl;
      drtmp = dr;
      index = tmpindex;
      jetfound= true;
    } 
    tmpindex++;
	 }
    return jetfound;
  }
  

