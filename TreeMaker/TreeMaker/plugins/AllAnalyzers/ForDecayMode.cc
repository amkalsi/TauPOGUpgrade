#include "./ForDecayMode.h"                                                                                                                                        
#include "DataFormats/TrackReco/interface/HitPattern.h"
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"

ForDecayMode::ForDecayMode(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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

  hFill_Num_pT_VertexMatch_highest  = fs->make<TH1F>(("hFill_Num_pT_VertexMatch_highest"+prefix).c_str() ,"hFill_Num_pT_VertexMatch_highest", 100,0,700);

 hFill_Num_pT_VertexMatch = fs->make<TH1F>(("hFill_Num_pT_VertexMatch"+prefix).c_str() ,"hFill_Num_pT_VertexMatch", 100,0,700);
 hFill_Den_pT_VertexMatch  = fs->make<TH1F>(("hFill_Den_pT_VertexMatch"+prefix).c_str() ,"hFill_Den_pT_VertexMatch", 100,0,700);

 hFill_postion_highestVertexMatch  = fs->make<TH1F>(("hFill_postion_highestVertexMatch"+prefix).c_str() ,"hFill_postion_highestVertexMatch",20,-0.5,19.5);

h_genpt_vis_Step4 =  fs->make<TH1F>(("h_genpt_vis_Step4"+prefix).c_str() ,"h_genpt_vis_Step4", 100,0,700);
h_genpt_vis_Step3 =  fs->make<TH1F>(("h_genpt_vis_Step3"+prefix).c_str() ,"h_genpt_vis_Step3", 100,0,700);
h_genpt_vis_Step2 =  fs->make<TH1F>(("h_genpt_vis_Step2"+prefix).c_str() ,"h_genpt_vis_Step2", 100,0,700);   
h_genpt_vis_Step1 =  fs->make<TH1F>(("h_genpt_vis_Step1"+prefix).c_str() ,"h_genpt_vis_Step1", 100,0,700);
h_genpt_vis =  fs->make<TH1F>(("h_genpt_vis"+prefix).c_str() ,"h_genpt_vis", 100,0,700);
}



ForDecayMode::~ForDecayMode()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called for each event  ------------
void ForDecayMode::Fill(const edm::Event& iEvent , const edm::EventSetup& iSetup) {
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
  
  edm::Handle<reco::VertexCollection> vC;
  iEvent.getByLabel("offlinePrimaryVertices",vC);
  //  vector<pat::Muon>                    "patMuons"                  ""           "PATTuple"  
 
// edm::HepMCProduct                  "generator"                 ""           "SIM"        
   edm::Handle<edm::HepMCProduct> hepMC;
   iEvent.getByLabel("generator",hepMC);

  iEvent.getByLabel("ak5GenJets", _genJets);
  
  
  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  //decay Mode
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFindingOldDMs",_dmf);
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFindingNewDMs",_dmf_new);
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
   
   // Get Event
   
   const HepMC::GenEvent* Evt = hepMC->GetEvent();
   
   //    HepMC::GenVertex* highestpT = 0;
   
   
   reco::VertexCollection::const_iterator leadVTX;
   
  double sumpTMAX = -9999;
  for(reco::VertexCollection::const_iterator vtx=vC->begin(); vtx!= vC->end(); ++vtx) {
    
    double sumpT = 0;
    for(reco::Vertex::trackRef_iterator itk = vtx->tracks_begin();itk != vtx->tracks_end(); ++itk) {
      sumpT = sumpT + ((*itk)->pt())*((*itk)->pt());
    }
    if(sumpT > sumpTMAX) {
      sumpTMAX = sumpT;
      leadVTX = vtx;
    }
  }
  
  double pT_TauMax = -999; 
  double genVertex_end_z = -999;
  double genVertex_prod_z = -999;
  
  HepMC::GenEvent::particle_const_iterator highestPtGenTau;

  for(HepMC::GenEvent::particle_const_iterator p=Evt->particles_begin(); p!=Evt->particles_end();p++) {
    if((fabs((*p)->pdg_id()) == 15))  {
      // if this is tau
      cout<<"this is tau"<<endl;
      // Now if this is last tau in chain // 
      if(isLastTauinChain(*p)){
	cout<<"this is Last CHain"<<endl;
	int found ;
	found= findMother(*p);
	cout << "found=mother "<<found<<endl;
	if(found == _TauMotherId){
	  TLorentzVector visibletauP4 = TauP4(*p);
	  // obtained subtracted pT
	  
	  double pT_tau = sqrt((visibletauP4.Px()*visibletauP4.Px()) +(visibletauP4.Py()*visibletauP4.Py())) ;
	  if(pT_tau > pT_TauMax) {
	    pT_TauMax = pT_tau;
	    genVertex_end_z = (*p)->end_vertex()->position().z();
	    genVertex_prod_z = (*p)->production_vertex()->position().z(); 
	    //cout<<"genVertex_end_z"<<genVertex_end_z<<endl;
	    //cout<<"genVertex_prod_z"<<genVertex_prod_z<<endl;
	    highestPtGenTau=p;
	  }
	}
      }
    }
  }
  cout<<"genVertex_end_z"<<genVertex_end_z<<endl;
  cout<<"genVertex_prod_z"<<genVertex_prod_z<<endl;
  
  bool foundWithinDzLt2mm = false;
  for(reco::VertexCollection::const_iterator vtx=vC->begin(); vtx!= vC->end(); ++vtx) {
    
    cout<<"max"<<(*highestPtGenTau)->end_vertex()->position().z()<<endl; 
    if(fabs((vtx->z()) - ((*highestPtGenTau)->production_vertex()->position().z())) < 0.2) {
      foundWithinDzLt2mm = true;
  
    };   

  }


  if(foundWithinDzLt2mm) hFill_Num_pT_VertexMatch->Fill(pT_TauMax);
  hFill_Den_pT_VertexMatch->Fill(pT_TauMax);

  // Matching highest SUmpT vertex

  bool  foundWithinDzLt2mm_highest = false;

  if(fabs((leadVTX->z()) - ((*highestPtGenTau)->production_vertex()->position().z())) < 0.2) {foundWithinDzLt2mm_highest= true;}

  if(foundWithinDzLt2mm_highest) {
   
    hFill_Num_pT_VertexMatch_highest->Fill(pT_TauMax);

   // Fill other histos
  }

if(foundWithinDzLt2mm_highest) {

 if(leadVTX->position().z() <= 15) {
 hFill_postion_highestVertexMatch->Fill(leadVTX->position().z());
} else if(leadVTX->position().z() > 15){
hFill_postion_highestVertexMatch->Fill(17);
}

}else{
hFill_postion_highestVertexMatch->Fill(19);
}

/////////////////////////// Second Part /////////////////////////////////////////////////

for(HepMC::GenEvent::particle_const_iterator gen=Evt->particles_begin(); gen!=Evt->particles_end();gen++) {
    if((fabs((*gen)->pdg_id()) == 15))  {
      // if this is tau
    if(isLastTauinChain(*gen)){
     int found1 ;
     found1= findMother(*gen);
   if(found1 == _TauMotherId){
    TLorentzVector visibletauP4_1 = TauP4(*gen);
 // obtained subtracted pT
 
   double pT_tau_1 = sqrt((visibletauP4_1.Px()*visibletauP4_1.Px()) +(visibletauP4_1.Py()*visibletauP4_1.Py())) ;

   h_genpt_vis->Fill(pT_tau_1);

     cout<<"pT_tau_1"<<pT_tau_1<<endl;

   for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
        reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);                                                
        if(reco::deltaR((*gen)->momentum().eta(), (*gen)->momentum().phi(), tauCandidate->eta(), tauCandidate->phi()) < _TauToGenMatchingDeltaR){ 

        if((*_dmf_new)[tauCandidate] > 0.5) {
 
    //Tau ID new Mode Discriminator
           h_genpt_vis_Step1->Fill(pT_tau_1);

         if(tauCandidate->leadPFChargedHadrCand()->trackRef().isNonnull() && tauCandidate->leadPFChargedHadrCand()->gsfTrackRef().isNonnull() ) { 
         if((fabs((tauCandidate->leadPFChargedHadrCand()->trackRef()->innerPosition().z()-((*gen)->production_vertex()->position().z())) < 0.2 ) || fabs((tauCandidate->leadPFChargedHadrCand()->gsfTrackRef()->innerPosition().z())-((*gen)->production_vertex()->position().z())) < 0.2 )) {
          h_genpt_vis_Step2->Fill(pT_tau_1);

       if((tauCandidate->pt() > 20 ) && (fabs(tauCandidate->eta()) < 2.3)) {

          h_genpt_vis_Step3->Fill(pT_tau_1);

       if(((*_dmf)[tauCandidate] > 0.5)) {

          h_genpt_vis_Step4->Fill(pT_tau_1);
}
}
}
}
}
}
}
    }
 }
}
}






} // Fill Event finishes here

bool ForDecayMode::isLastTauinChain(const HepMC::GenParticle* tau){
  if ( tau->end_vertex() ) {
    HepMC::GenVertex::particle_iterator dau;
    for (dau = tau->end_vertex()->particles_begin(HepMC::children); dau!= tau->end_vertex()->particles_end(HepMC::children); dau++ ) {
      int dau_pid = (*dau)->pdg_id();
      if(dau_pid == tau->pdg_id()) return false;
    }
  }
  return true;
}


int ForDecayMode::findMother(const HepMC::GenParticle* tau){
  int mother_pid = 0;
  if ( tau->production_vertex() ) {
    HepMC::GenVertex::particle_iterator mother;
    int i = 0;
    for (mother = tau->production_vertex()->particles_begin(HepMC::parents); mother!= tau->production_vertex()->particles_end(HepMC::parents); mother++ ) {
      i++;
      mother_pid = (*mother)->pdg_id();
      if(mother_pid == tau->pdg_id() ) return findMother(*mother);
    }
  }
  return mother_pid;
}



TLorentzVector ForDecayMode::TauP4(const HepMC::GenParticle* tau){
  
  TLorentzVector p4(tau->momentum().px(),tau->momentum().py(),tau->momentum().pz(),tau->momentum().e());
  TLorentzVector MCHad_Tau(0,0,0,0);
  if ( tau->end_vertex() ) {
    HepMC::GenVertex::particle_iterator des;
    int neutrinos = 0;
    for(des = tau->end_vertex()->particles_begin(HepMC::descendants);des!= tau->end_vertex()->particles_end(HepMC::descendants);++des ) {
      int pid = (*des)->pdg_id();
      
      //              if(abs(pid) == 15) return visibleTauEnergy(*des);
      if (abs(pid) == 13 || abs(pid) == 11) continue; 
      // restricting tau decay products
      if(abs(pid) == 12 || abs(pid) == 14 || abs(pid) == 16) {
	    TLorentzVector daughter_N((*des)->momentum().px(),(*des)->momentum().py(),(*des)->momentum().pz(),(*des)->momentum().e());  
//p4 -= TLorentzVector((*des)->momentum().px(),(*des)->momentum().py(),(*des)->momentum().pz(),(*des)->momentum().e());
       MCHad_Tau = p4 - daughter_N;  
        neutrinos++;
      }

    }
   if(neutrinos == 1 ) return MCHad_Tau;
   
  } 
 return MCHad_Tau;
}
