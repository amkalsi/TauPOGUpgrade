#include "./ETauFakeRateG2p3.h"                                                                                                                                        
#include "DataFormats/TrackReco/interface/HitPattern.h"

ETauFakeRateG2p3::ETauFakeRateG2p3(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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

  //h_RPC_FourthStation_etag1p2 = fs->make<TH1F>(("h_RPC_FourthStation_etag1p2"+prefix).c_str() ,"h_RPC_FourthStation_etag1p2",15,0,15);

  h_PfTau_pT_den = fs->make<TH1F>(("h_PfTau_pT_den"+prefix).c_str() ,"h_PfTau_pT_den",100,0,700);
  h_PfTau_Eta_den = fs->make<TH1F>(("h_PfTau_Eta_den"+prefix).c_str() ,"h_PfTau_Eta_den",100,-5,5);
  h_PfTau_Phi_den = fs->make<TH1F>(("h_PfTau_Phi_den"+prefix).c_str() ,"h_PfTau_Phi_den",100,-5,5);
  h_genElectron_pT_den = fs->make<TH1F>(("h_genElectron_pT_den"+prefix).c_str() ,"h_genElectron_pT_den",100,0,700);
  h_genElectron_Eta_den = fs->make<TH1F>(("h_genElectron_Eta_den"+prefix).c_str() ,"h_genElectron_Eta_den",100,-5,5);
  h_genElectron_Phi_den = fs->make<TH1F>(("h_genElectron_Phi_den"+prefix).c_str() ,"h_genElectron_Phi_den",100,-5,5); 

  h_PfTau_pT_num = fs->make<TH1F>(("h_PfTau_pT_num"+prefix).c_str() ,"h_PfTau_pT_num",100,0,700);
  h_PfTau_Eta_num = fs->make<TH1F>(("h_PfTau_Eta_num"+prefix).c_str() ,"h_PfTau_Eta_num",100,-5,5);
  h_PfTau_Phi_num = fs->make<TH1F>(("h_PfTau_Phi_num"+prefix).c_str() ,"h_PfTau_Phi_num",100,-5,5);
  h_genElectron_pT_num = fs->make<TH1F>(("h_genElectron_pT_num"+prefix).c_str() ,"h_genElectron_pT_num",100,0,700);
  h_genElectron_Eta_num = fs->make<TH1F>(("h_genElectron_Eta_num"+prefix).c_str() ,"h_genElectron_Eta_num",100,-5,5); 
  h_genElectron_Phi_num = fs->make<TH1F>(("h_genElectron_Phi_num"+prefix).c_str() ,"h_genElectron_Phi_num",100,-5,5); 
 

  h_PfTau_pT_num_tight = fs->make<TH1F>(("h_PfTau_pT_num_tight"+prefix).c_str() ,"h_PfTau_pT_num_tight",100,0,700);
  h_PfTau_Eta_num_tight = fs->make<TH1F>(("h_PfTau_Eta_num_tight"+prefix).c_str() ,"h_PfTau_Eta_num_tight",100,-5,5);
  h_PfTau_Phi_num_tight = fs->make<TH1F>(("h_PfTau_Phi_num_tight"+prefix).c_str() ,"h_PfTau_Phi_num_tight",100,-5,5);
  h_genElectron_pT_num_tight = fs->make<TH1F>(("h_genElectron_pT_num_tight"+prefix).c_str() ,"h_genElectron_pT_num_tight",100,0,700);
  h_genElectron_Eta_num_tight = fs->make<TH1F>(("h_genElectron_Eta_num_tight"+prefix).c_str() ,"h_genElectron_Eta_num_tight",100,-5,5); 
  h_genElectron_Phi_num_tight = fs->make<TH1F>(("h_genElectron_Phi_num_tight"+prefix).c_str() ,"h_genElectron_Phi_num_tight",100,-5,5); 



   h_PfTau_pT_num_medium = fs->make<TH1F>(("h_PfTau_pT_num_medium"+prefix).c_str() ,"h_PfTau_pT_num_medium",100,0,700);
  h_PfTau_Eta_num_medium = fs->make<TH1F>(("h_PfTau_Eta_num_medium"+prefix).c_str() ,"h_PfTau_Eta_num_medium",100,-5,5);
 h_PfTau_Phi_num_medium = fs->make<TH1F>(("h_PfTau_Phi_num_medium"+prefix).c_str() ,"h_PfTau_Phi_num_medium",100,-5,5);
  h_genElectron_pT_num_medium = fs->make<TH1F>(("h_genElectron_pT_num_medium"+prefix).c_str() ,"h_genElectron_pT_num_medium",100,0,700);
  h_genElectron_Eta_num_medium = fs->make<TH1F>(("h_genElectron_Eta_num_medium"+prefix).c_str() ,"h_genElectron_Eta_num_medium",100,-5,5); 
  h_genElectron_Phi_num_medium = fs->make<TH1F>(("h_genElectron_Phi_num_medium"+prefix).c_str() ,"h_genElectron_Phi_num_medium",100,-5,5);   

  h_PfTau_pT_num_Cut = fs->make<TH1F>(("h_PfTau_pT_num_Cut"+prefix).c_str() ,"h_PfTau_pT_num_Cut",100,0,700);
 h_PfTau_Eta_num_Cut = fs->make<TH1F>(("h_PfTau_Eta_num_Cut"+prefix).c_str() ,"h_PfTau_Eta_num_Cut",100,-5,5);
  h_PfTau_Phi_num_Cut = fs->make<TH1F>(("h_PfTau_Phi_num_Cut"+prefix).c_str() ,"h_PfTau_Phi_num_Cut",100,-5,5);
  h_genElectron_pT_num_Cut = fs->make<TH1F>(("h_genElectron_pT_num_Cut"+prefix).c_str() ,"h_genElectron_pT_num_Cut",100,0,700);
  h_genElectron_Eta_num_Cut = fs->make<TH1F>(("h_genElectron_Eta_num_Cut"+prefix).c_str() ,"h_genElectron_Eta_num_Cut",100,-5,5);
 h_genElectron_Phi_num_Cut = fs->make<TH1F>(("h_genElectron_Phi_num_Cut"+prefix).c_str() ,"h_genElectron_Phi_num_Cut",100,-5,5);




}


ETauFakeRateG2p3::~ETauFakeRateG2p3()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called for each event  ------------
void ETauFakeRateG2p3::Fill(const edm::Event& iEvent) {
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
  

  //  vector<pat::Electron>                    "patElectrons"                  ""           "PATTuple"  
 
  
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


 //cut bases                                                                                                                                                        

   iEvent.getByLabel("hpsPFTauDiscriminationByMediumElectronRejection2",_enew);

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
  
  
  
  bool isZEE=false;
  isZEE = IsZEE(_genParticles) ;
  
  //isZtautau=true;
  
  if(isZEE) {
    
    /*    for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
      reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
      
      bool TauEtaCuts = false;
      bool RecoptCut = false;
      bool DecayModeFinding = false;
      bool MuonDisc = false;
      bool IsoDisc = false;    
      bool MuonDisc1 = false;
 
       if(abs(tauCandidate->eta()) < 2.3) TauEtaCuts = true;
       
       if((tauCandidate->pt()) > 20) RecoptCut = true;
       
       if((*_dmf)[tauCandidate] > 0.5) DecayModeFinding = true; 
   
       if((*_mv31)[tauCandidate] > 0.5) MuonDisc = true;

       if((*_mv32)[tauCandidate] > 0.5) MuonDisc1 = true;
     
       if((*_iso4)[tauCandidate] > 0.5) IsoDisc = true;
    */
      
    for(reco::GenParticleCollection::const_iterator genparticles = _genParticles->begin(); genparticles !=  _genParticles->end(); ++genparticles) {
      
      if(genparticles->pt() <= 20) continue;
      if(abs(genparticles->eta()) <= 2.3) continue;
      if(abs(genparticles->eta()) >= 3.0) continue;  
      if(((abs(genparticles->pdgId()) == 11) )) {
	if(abs(genparticles->mother(0)->pdgId()) == _TauMotherId) {
	  
	  h_PfTau_pT_den->Fill(0);//tauCandidate->pt());
	  h_PfTau_Eta_den->Fill(0);//tauCandidate->eta());
	  h_PfTau_Phi_den->Fill(0);//tauCandidate->phi());
      
          h_genElectron_pT_den->Fill(genparticles->pt());
          h_genElectron_Eta_den->Fill(genparticles->eta());
          h_genElectron_Phi_den->Fill(genparticles->phi());

	  for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
	    reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
	    
	    bool TauEtaCuts = false;
	    bool RecoptCut = false;
	    bool DecayModeFinding = false;
	    bool ElectronDisc = false;
	    bool IsoDisc = false;    
	    bool ElectronDisc1 = false;
       bool ElectronDisc2 = false;    
      bool CutBased = false;
	    if((abs(tauCandidate->eta()) > 2.3) && (abs(tauCandidate->eta()) < 3.0)) TauEtaCuts = true;
	    
	    if((tauCandidate->pt()) > 20) RecoptCut = true;
	    
	    if((*_dmf)[tauCandidate] > 0.5) DecayModeFinding = true; 
	    
	    if((*_ev1)[tauCandidate] > 0.5) ElectronDisc = true;
	    
	    if((*_ev2)[tauCandidate] > 0.5) ElectronDisc1 = true;
	    
      if((*_ev3)[tauCandidate] > 0.5) ElectronDisc2  = true;

	    if((*_iso4)[tauCandidate] > 0.5) IsoDisc = true;
	     if((*_enew)[tauCandidate] > 0.5) CutBased = true;
	    
	    if(reco::deltaR(genparticles->eta(), genparticles->phi(), tauCandidate->eta(), tauCandidate->phi()) < _TauToGenMatchingDeltaR) {
	      
	      if(DecayModeFinding  && TauEtaCuts && RecoptCut && IsoDisc ) {
		if (ElectronDisc) { 
		  h_PfTau_pT_num->Fill(tauCandidate->pt());
		  h_PfTau_Eta_num->Fill(tauCandidate->eta());
		  h_PfTau_Phi_num->Fill(tauCandidate->phi());
		  
		  h_genElectron_pT_num->Fill(genparticles->pt());
		  h_genElectron_Eta_num->Fill(genparticles->eta());
		  h_genElectron_Phi_num->Fill(genparticles->phi());    
		  //Fill Reco 
		}

		if (ElectronDisc1) {
		  h_PfTau_pT_num_medium->Fill(tauCandidate->pt());
		  h_PfTau_Eta_num_medium->Fill(tauCandidate->eta());
		  h_PfTau_Phi_num_medium->Fill(tauCandidate->phi());
		  
		  h_genElectron_pT_num_medium->Fill(genparticles->pt());
		  h_genElectron_Eta_num_medium->Fill(genparticles->eta());
		  h_genElectron_Phi_num_medium->Fill(genparticles->phi()); 
		}
     // Tight Veto
if (ElectronDisc2) {
 h_PfTau_pT_num_tight->Fill(tauCandidate->pt());
 h_PfTau_Eta_num_tight->Fill(tauCandidate->eta());
  h_PfTau_Phi_num_tight->Fill(tauCandidate->phi());
  
 h_genElectron_pT_num_tight->Fill(genparticles->pt());
 h_genElectron_Eta_num_tight->Fill(genparticles->eta());
 h_genElectron_Phi_num_tight->Fill(genparticles->phi()); 
}

if(CutBased) {

h_PfTau_pT_num_Cut->Fill(tauCandidate->pt());
h_PfTau_Eta_num_Cut->Fill(tauCandidate->eta());
 h_PfTau_Phi_num_Cut->Fill(tauCandidate->phi());
h_genElectron_pT_num_Cut->Fill(genparticles->pt());
h_genElectron_Eta_num_Cut->Fill(genparticles->eta());
h_genElectron_Phi_num_Cut->Fill(genparticles->phi());




}




	      }
	    }
	  }	  
	}
      }
      //	}
    }
  }
}

// ------------ method called once each job just before starting event loop  ------------


bool ETauFakeRateG2p3::IsZEE(edm::Handle<reco::GenParticleCollection> genParticles){
   bool isZEE = false;
  reco::GenParticleCollection::const_iterator particle;
  for (particle = genParticles->begin(); particle != genParticles->end();  particle++) {
    if ((abs(particle->pdgId()) == _TauMotherId)) {
//      std::cout<<" Z found with pdgid = "<<particle->numberOfDaughters()<<std::endl;
      int daughters  = particle->numberOfDaughters();
       for (int j = 0; j<daughters; ++j) {
        const reco::Candidate *daughter = particle->daughter(j);
         int pidg = std::abs(daughter->pdgId());
// int status = daughter->status();
         if (pidg == 11) {
           isZEE = true;
//           std::cout<<"working inside function"<<std::endl;
           break;
        }
      }
    }
  }
  return isZEE;  
}

bool ETauFakeRateG2p3::OverlapWithGenMu(double Taueta , double Tauphi ,edm::Handle<reco::GenParticleCollection> genParticles ,int  &index ) {
  double drtmp = _TauToGenMatchingDeltaR;
  int tmpindex =0 ;
  bool genTaufound = false;
  for(reco::GenParticleCollection::const_iterator genmuons=genParticles->begin(); genmuons!=genParticles->end(); ++genmuons) {
    if(((abs(genmuons->pdgId()) == 11) && (genmuons->status() ==3))) {
	 if(abs(genmuons->mother(0)->pdgId()) == _TauMotherId) {
    double dr =reco::deltaR(Taueta, Tauphi,genmuons->eta(),genmuons->phi());
    if(dr < drtmp){
      drtmp = dr;
      index = tmpindex;
      genTaufound= true;
    } 
    tmpindex++;
	 }
       }
       }
    return genTaufound;
  }
  

