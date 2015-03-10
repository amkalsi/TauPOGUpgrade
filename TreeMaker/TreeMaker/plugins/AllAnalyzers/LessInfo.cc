


#include "./LessInfo.h"                                                                                                                                        
  

LessInfo::LessInfo(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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



}


LessInfo::~LessInfo()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void LessInfo::Fill(const edm::Event& iEvent) {
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
   


   bool isZtautau=false;
   isZtautau = IsZTauTau (_genParticles) ;
   
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

   //isZtautau=true;
   
   if(isZtautau) {
     
     for(reco::GenJetCollection::const_iterator gentaujet = genTauJets->begin(); gentaujet !=  genTauJets->end(); ++gentaujet) {
       std::string tauGenJetDecayMode = JetMCTagUtils::genTauDecayMode(*gentaujet);
       
       
       if(tauGenJetDecayMode=="muon") continue;
       if(tauGenJetDecayMode=="electron") continue;
       if(gentaujet->pt() > 20 ) {
	 
	 Fill_gentauEta->Fill(gentaujet->eta());
	 
       }}



     
       
   

     for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
       reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);

       if(((*_dmf)[tauCandidate] > 0.5) && ((tauCandidate->pt()) > 20)) {

	 Fill_RecotauEta->Fill(tauCandidate->eta());
       }
     }
     
   }
}


// ------------ method called once each job just before starting event loop  ------------
bool LessInfo::OverlapWithGenTau(double Taueta , double Tauphi ,edm::Handle<std::vector< reco::GenJet > > genTauJets ,int  &index     ) {
   double drtmp = _TauToGenMatchingDeltaR;
   int tmpindex =0 ;
   bool genTaufound = false;
   for(std::vector<reco::GenJet>::const_iterator genJetItr=genTauJets->begin(); genJetItr!=genTauJets->end(); ++genJetItr) {
 
     double dr =reco::deltaR(Taueta, Tauphi,genJetItr->eta(),genJetItr->phi());
     if(dr < drtmp){
       drtmp = dr;
       index = tmpindex;
       genTaufound= true;
     }
     tmpindex++;
   }
   return genTaufound;
 }

bool LessInfo::IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles){
   bool isZTauTau = false;
  reco::GenParticleCollection::const_iterator particle;
  for (particle = genParticles->begin(); particle != genParticles->end();  particle++) {
    if ((abs(particle->pdgId()) == _TauMotherId)) {
//      std::cout<<" Z found with pdgid = "<<particle->numberOfDaughters()<<std::endl;
      int daughters  = particle->numberOfDaughters();
       for (int j = 0; j<daughters; ++j) {
        const reco::Candidate *daughter = particle->daughter(j);
         int pidg = std::abs(daughter->pdgId());
         if (pidg == 15) {
           isZTauTau = true;
//           std::cout<<"working inside function"<<std::endl;
           break;
        }
      }
    }
  }
  return isZTauTau;  
}

