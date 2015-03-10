#include "./MuTauFakeRate2to3.h"                                                                                                                                        
#include "DataFormats/TrackReco/interface/HitPattern.h"

MuTauFakeRate2to3::MuTauFakeRate2to3(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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

   Nvtx_DMF = fs->make<TH1F>(("Nvtx_DMF"+prefix).c_str() ,"Nvtx_DMF",200,0,200);            
  NGood_DMF = fs->make<TH1F>(("NGood_DMF"+prefix).c_str() ,"NGood_DMF",200,0,200);

   Nvtx_num_tight = fs->make<TH1F>(("Nvtx_num_tight"+prefix).c_str() ,"Nvtx_num_tight",200,0,200);            
  NGood_num_tight = fs->make<TH1F>(("NGood_num_tight"+prefix).c_str() ,"NGood_num_tight",200,0,200);

  Nvtx_num = fs->make<TH1F>(("Nvtx_num"+prefix).c_str() ,"Nvtx_num",200,0,200);            
  NGood_num = fs->make<TH1F>(("NGood_num"+prefix).c_str() ,"NGood_num",200,0,200);

 Nvtx_den = fs->make<TH1F>(("Nvtx_den"+prefix).c_str() ,"Nvtx_den",200,0,200);            
  NGood_den = fs->make<TH1F>(("NGood_den"+prefix).c_str() ,"NGood_den",200,0,200);

Nvtx_den = fs->make<TH1F>(("Nvtx_den"+prefix).c_str() ,"Nvtx_den",200,0,200);            
  NGood_den = fs->make<TH1F>(("NGood_den"+prefix).c_str() ,"NGood_den",200,0,200);


  h_PfTau_pT_DMF = fs->make<TH1F>(("h_PfTau_pT_DMF"+prefix).c_str() ,"h_PfTau_pT_DMF",100,0,700);
  h_PfTau_Eta_DMF = fs->make<TH1F>(("h_PfTau_Eta_DMF"+prefix).c_str() ,"h_PfTau_Eta_DMF",100,-5,5);
  h_PfTau_Phi_DMF = fs->make<TH1F>(("h_PfTau_Phi_DMF"+prefix).c_str() ,"h_PfTau_Phi_DMF",100,-5,5);
  h_genMuon_pT_DMF = fs->make<TH1F>(("h_genMuon_pT_DMF"+prefix).c_str() ,"h_genMuon_pT_DMF",100,0,700);
  h_genMuon_Eta_DMF = fs->make<TH1F>(("h_genMuon_Eta_DMF"+prefix).c_str() ,"h_genMuon_Eta_DMF",100,-5,5);
  h_genMuon_Phi_DMF = fs->make<TH1F>(("h_genMuon_Phi_DMF"+prefix).c_str() ,"h_genMuon_Phi_DMF",100,-5,5); 

  h_PfTau_pT_den = fs->make<TH1F>(("h_PfTau_pT_den"+prefix).c_str() ,"h_PfTau_pT_den",100,0,700);
  h_PfTau_Eta_den = fs->make<TH1F>(("h_PfTau_Eta_den"+prefix).c_str() ,"h_PfTau_Eta_den",100,-5,5);
  h_PfTau_Phi_den = fs->make<TH1F>(("h_PfTau_Phi_den"+prefix).c_str() ,"h_PfTau_Phi_den",100,-5,5);
  h_genMuon_pT_den = fs->make<TH1F>(("h_genMuon_pT_den"+prefix).c_str() ,"h_genMuon_pT_den",100,0,700);
  h_genMuon_Eta_den = fs->make<TH1F>(("h_genMuon_Eta_den"+prefix).c_str() ,"h_genMuon_Eta_den",100,-5,5);
  h_genMuon_Phi_den = fs->make<TH1F>(("h_genMuon_Phi_den"+prefix).c_str() ,"h_genMuon_Phi_den",100,-5,5); 

  h_PfTau_pT_num = fs->make<TH1F>(("h_PfTau_pT_num"+prefix).c_str() ,"h_PfTau_pT_num",100,0,700);
  h_PfTau_Eta_num = fs->make<TH1F>(("h_PfTau_Eta_num"+prefix).c_str() ,"h_PfTau_Eta_num",100,-5,5);
  h_PfTau_Phi_num = fs->make<TH1F>(("h_PfTau_Phi_num"+prefix).c_str() ,"h_PfTau_Phi_num",100,-5,5);
  h_genMuon_pT_num = fs->make<TH1F>(("h_genMuon_pT_num"+prefix).c_str() ,"h_genMuon_pT_num",100,0,700);
  h_genMuon_Eta_num = fs->make<TH1F>(("h_genMuon_Eta_num"+prefix).c_str() ,"h_genMuon_Eta_num",100,-5,5); 
  h_genMuon_Phi_num = fs->make<TH1F>(("h_genMuon_Phi_num"+prefix).c_str() ,"h_genMuon_Phi_num",100,-5,5); 
 

  h_PfTau_pT_num_tight = fs->make<TH1F>(("h_PfTau_pT_num_tight"+prefix).c_str() ,"h_PfTau_pT_num_tight",100,0,700);
  h_PfTau_Eta_num_tight = fs->make<TH1F>(("h_PfTau_Eta_num_tight"+prefix).c_str() ,"h_PfTau_Eta_num_tight",100,-5,5);
  h_PfTau_Phi_num_tight = fs->make<TH1F>(("h_PfTau_Phi_num_tight"+prefix).c_str() ,"h_PfTau_Phi_num_tight",100,-5,5);
  h_genMuon_pT_num_tight = fs->make<TH1F>(("h_genMuon_pT_num_tight"+prefix).c_str() ,"h_genMuon_pT_num_tight",100,0,700);
  h_genMuon_Eta_num_tight = fs->make<TH1F>(("h_genMuon_Eta_num_tight"+prefix).c_str() ,"h_genMuon_Eta_num_tight",100,-5,5); 
  h_genMuon_Phi_num_tight = fs->make<TH1F>(("h_genMuon_Phi_num_tight"+prefix).c_str() ,"h_genMuon_Phi_num_tight",100,-5,5); 
  
}


MuTauFakeRate2to3::~MuTauFakeRate2to3()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called for each event  ------------
void MuTauFakeRate2to3::Fill(const edm::Event& iEvent) {
  using namespace edm;
  using namespace std;
  using namespace reco;
  using namespace pat;

  edm::Handle<reco::VertexCollection> vtx;
  iEvent.getByLabel("offlinePrimaryVertices",vtx);
  
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
  

  //  vector<pat::Muon>                    "patMuons"                  ""           "PATTuple"  
 
  
  iEvent.getByLabel("ak5GenJets", _genJets);
  
  
  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  //decay Mode
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFindingOldDMs",_dmf);
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
 
 

  
  
  bool isZMuMu=false;
  isZMuMu = IsZMuMu (_genParticles) ;
 
 int  nGoodVtx = 0;
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){
     
     if((vtxIt->isValid()) && !(vtxIt->isFake())) {
       
       nGoodVtx++;
     }
   }
 
  //isZtautau=true;
  
  if(isZMuMu) {
    
      
    for(reco::GenParticleCollection::const_iterator genparticles = _genParticles->begin(); genparticles !=  _genParticles->end(); ++genparticles) {
      
      if(genparticles->pt() <= 20) continue;
       if(abs(genparticles->eta()) < 2.3) continue; 
      if(abs(genparticles->eta()) >= 3.0) continue;
      
      if(((abs(genparticles->pdgId()) == 13) && (genparticles->status() ==3))) {
	if(abs(genparticles->mother(0)->pdgId()) == _TauMotherId) {
 
      
          h_genMuon_pT_den->Fill(genparticles->pt());
          h_genMuon_Eta_den->Fill(genparticles->eta());
          h_genMuon_Phi_den->Fill(genparticles->phi());
          Nvtx_den->Fill(vtx->size());                                                                                         
          NGood_den->Fill(nGoodVtx);

	  
	   int index1= -1;
    if(OverlapWithGenTauForOther(genparticles->eta() , genparticles->phi() , _hpsTaucoll, _dmf ,index1 )) {   
       if(index1 != -1){
       reco::PFTauRef tauCandidate(_hpsTaucoll, index1);
      h_PfTau_pT_DMF->Fill(tauCandidate->pt());
      h_PfTau_Eta_DMF->Fill(tauCandidate->eta());
      h_PfTau_Phi_DMF->Fill(tauCandidate->phi());
  
      h_genMuon_pT_DMF->Fill(genparticles->pt());
      h_genMuon_Eta_DMF->Fill(genparticles->eta());
      h_genMuon_Phi_DMF->Fill(genparticles->phi());  
      Nvtx_DMF->Fill(vtx->size()); 
      NGood_DMF->Fill(nGoodVtx);

	 // if((*_hpsTau1)[tauCandidate] > 0.5) {

    if((*_rawc)[tauCandidate] < 4){
		if ((*_mv31)[tauCandidate] > 0.5) { 
		  h_PfTau_pT_num->Fill(tauCandidate->pt());
		  h_PfTau_Eta_num->Fill(tauCandidate->eta());
		  h_PfTau_Phi_num->Fill(tauCandidate->phi());
		  
		  h_genMuon_pT_num->Fill(genparticles->pt());
		  h_genMuon_Eta_num->Fill(genparticles->eta());
		  h_genMuon_Phi_num->Fill(genparticles->phi());    
      Nvtx_num->Fill(vtx->size());                                                                                         
      NGood_num->Fill(nGoodVtx);


		  //Fill Reco 
		}

		if ((*_mv32)[tauCandidate] > 0.5) {
		  h_PfTau_pT_num_tight->Fill(tauCandidate->pt());
		  h_PfTau_Eta_num_tight->Fill(tauCandidate->eta());
		  h_PfTau_Phi_num_tight->Fill(tauCandidate->phi());
		  
		  h_genMuon_pT_num_tight->Fill(genparticles->pt());
		  h_genMuon_Eta_num_tight->Fill(genparticles->eta());
		  h_genMuon_Phi_num_tight->Fill(genparticles->phi()); 
      Nvtx_num_tight->Fill(vtx->size());                                                                                         
      NGood_num_tight->Fill(nGoodVtx);

		}
     // Tight Veto
	      }
	    }
	  }	  
	}
      }
    }
  }
}
// ------------ method called once each job just before starting event loop  ------------

bool MuTauFakeRate2to3::OverlapWithGenTauForOther(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc ,int &index ) {
   double drtmp = _TauToGenMatchingDeltaR;
   bool genTaufound = false;
   index = -1;
   for ( unsigned iTau = 0; iTau < taujetcol->size(); ++iTau ) {
     reco::PFTauRef tauCandidate(taujetcol,iTau);
     if(tauCandidate->pt() <= 20) continue;
     if(fabs(tauCandidate->eta()) < 2.3)  continue;
     if(fabs(tauCandidate->eta()) >= 3.0) continue;
     if((*disc)[tauCandidate] > 0.5) {

       double dr =reco::deltaR(Taueta, Tauphi,tauCandidate->eta(),tauCandidate->phi());
       if(dr < drtmp){
 drtmp = dr;
 index = iTau;
 genTaufound= true;
     }
     }
   }
   return genTaufound;
 }

bool MuTauFakeRate2to3::IsZMuMu(edm::Handle<reco::GenParticleCollection> genParticles){
   bool isZMuMu = false;
  reco::GenParticleCollection::const_iterator particle;
  for (particle = genParticles->begin(); particle != genParticles->end();  particle++) {
    if ((abs(particle->pdgId()) == _TauMotherId)) {
//      std::cout<<" Z found with pdgid = "<<particle->numberOfDaughters()<<std::endl;
      int daughters  = particle->numberOfDaughters();
       for (int j = 0; j<daughters; ++j) {
        const reco::Candidate *daughter = particle->daughter(j);
         int pidg = std::abs(daughter->pdgId());
	 int status = daughter->status();
         if (pidg == 13 && status ==3) {
           isZMuMu = true;
//           std::cout<<"working inside function"<<std::endl;
           break;
        }
      }
    }
  }
  return isZMuMu;  
}

bool MuTauFakeRate2to3::OverlapWithGenMu(double Taueta , double Tauphi ,edm::Handle<reco::GenParticleCollection> genParticles ,int  &index ) {
  double drtmp = _TauToGenMatchingDeltaR;
  int tmpindex =0 ;
  bool genTaufound = false;
  for(reco::GenParticleCollection::const_iterator genmuons=genParticles->begin(); genmuons!=genParticles->end(); ++genmuons) {
    if(((abs(genmuons->pdgId()) == 13) && (genmuons->status() ==3))) {
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
  

