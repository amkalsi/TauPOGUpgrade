#include "./FakeRate.h"
//

FakeRate::FakeRate(edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)

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

  TrackPt = fs->make<TH1F>("TrackPt","TrackPt",100,0,700);
  TrackEta = fs->make<TH1F>("TrackEta","TrackEta",100,-5,5);
  TrackPhi = fs->make<TH1F>("TrackPhi","TrackPhi",100,-5,5);

  JetPt = fs->make<TH1F>("JetPt","JetPt",100,0,700);

  GenTauPtWithoutDMF = fs->make<TH1F>("GenTauPtWithoutDMF", "GenTauPtWithoutDMF",100,0,700);
  GenTauEtaWithoutDMF = fs->make<TH1F>("GenTauEtaWithoutDMF", "GenTauEtaWithoutDMF",100,-4,4);
  GenTauPhiWithoutDMF = fs->make<TH1F>("GenTauPhiWithoutDMF", "GenTauPhiWithoutDMF",100,-4,4);

  

  GenTauPtWithDMF = fs->make<TH1F>("GenTauPtWithDMF", "GenTauPtWithDMF",100,0,700);
  GenTauEtaWithDMF = fs->make<TH1F>("GenTauEtaWithDMF", "GenTauEtaWithDMF",100,-4,4);
  GenTauPhiWithDMF = fs->make<TH1F>("GenTauPhiWithDMF", "GenTauPhiWithDMF",100,-4,4);


  GenTauPtWithDMF_ML2 = fs->make<TH1F>("GenTauPtWithDMF_ML2", "GenTauPtWithDMF_ML2" ,100,0,700);
  GenTauEtaWithDMF_ML2 = fs->make<TH1F>("GenTauEtaWithDMF_ML2", "GenTauEtaWithDMF_ML2" ,100,-4,4);
  GenTauPhiWithDMF_ML2 = fs->make<TH1F>("GenTauPhiWithDMF_ML2", "GenTauPhiWithDMF_ML2" ,100,-4,4);

  GenTauPtWithDMF_MM2 = fs->make<TH1F>("GenTauPtWithDMF_MM2", "GenTauPtWithDMF_MM2" ,100,0,700);
  GenTauEtaWithDMF_MM2 = fs->make<TH1F>("GenTauEtaWithDMF_MM2", "GenTauEtaWithDMF_MM2" ,100,-4,4);
  GenTauPhiWithDMF_MM2 = fs->make<TH1F>("GenTauPhiWithDMF_MM2", "GenTauPhiWithDMF_MM2" ,100,-4,4);

  GenTauPtWithDMF_MT2 = fs->make<TH1F>("GenTauPtWithDMF_MT2", "GenTauPtWithDMF_MT2" ,100,0,700);
  GenTauEtaWithDMF_MT2 = fs->make<TH1F>("GenTauEtaWithDMF_MT2", "GenTauEtaWithDMF_MT2" ,100,-4,4);
  GenTauPhiWithDMF_MT2 = fs->make<TH1F>("GenTauPhiWithDMF_MT2", "GenTauPhiWithDMF_MT2" ,100,-4,4);

  GenTauPtWithDMF_ML3 = fs->make<TH1F>("GenTauPtWithDMF_ML3", "GenTauPtWithDMF_ML3" ,100,0,700);
  GenTauEtaWithDMF_ML3 = fs->make<TH1F>("GenTauEtaWithDMF_ML3", "GenTauEtaWithDMF_ML3" ,100,-4,4);
  GenTauPhiWithDMF_ML3 = fs->make<TH1F>("GenTauPhiWithDMF_ML3", "GenTauPhiWithDMF_ML3" ,100,-4,4);
	  
  GenTauPtWithDMF_MT3 = fs->make<TH1F>("GenTauPtWithDMF_MT3", "GenTauPtWithDMF_MT3" ,100,0,700);
  GenTauEtaWithDMF_MT3 = fs->make<TH1F>("GenTauEtaWithDMF_MT3", "GenTauEtaWithDMF_MT3" ,100,-4,4);
  GenTauPhiWithDMF_MT3 = fs->make<TH1F>("GenTauPhiWithDMF_MT3", "GenTauPhiWithDMF_MT3" ,100,-4,4);
    	  
  GenTauPtWithDMF_EL3 = fs->make<TH1F>("GenTauPtWithDMF_EL3", "GenTauPtWithDMF_EL3" ,100,0,700);
  GenTauEtaWithDMF_EL3 = fs->make<TH1F>("GenTauEtaWithDMF_EL3", "GenTauEtaWithDMF_EL3" ,100,-4,4);
  GenTauPhiWithDMF_EL3 = fs->make<TH1F>("GenTauPhiWithDMF_EL3", "GenTauPhiWithDMF_EL3" ,100,-4,4);

  GenTauPtWithDMF_EM3 = fs->make<TH1F>("GenTauPtWithDMF_EM3", "GenTauPtWithDMF_EM3" ,100,0,700);
  GenTauEtaWithDMF_EM3 = fs->make<TH1F>("GenTauEtaWithDMF_EM3", "GenTauEtaWithDMF_EM3" ,100,-4,4);
  GenTauPhiWithDMF_EM3 = fs->make<TH1F>("GenTauPhiWithDMF_EM3", "GenTauPhiWithDMF_EM3" ,100,-4,4);

  GenTauPtWithDMF_ET3 = fs->make<TH1F>("GenTauPtWithDMF_ET3", "GenTauPtWithDMF_ET3" ,100,0,700);
  GenTauEtaWithDMF_ET3 = fs->make<TH1F>("GenTauEtaWithDMF_ET3", "GenTauEtaWithDMF_ET3" ,100,-4,4);
  GenTauPhiWithDMF_ET3 = fs->make<TH1F>("GenTauPhiWithDMF_ET3", "GenTauPhiWithDMF_ET3" ,100,-4,4);


  GenTauPtWithDMF_LIso3Hits = fs->make<TH1F>("GenTauPtWithDMF_LIso3Hits", "GenTauPtWithDMF_LIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_LIso3Hits = fs->make<TH1F>("GenTauEtaWithDMF_LIso3Hits", "GenTauEtaWithDMF_LIso3Hits" ,100,-4,4);
  GenTauPhiWithDMF_LIso3Hits = fs->make<TH1F>("GenTauPhiWithDMF_LIso3Hits", "GenTauPhiWithDMF_LIso3Hits" ,100,-4,4);

  GenTauPtWithDMF_MIso3Hits = fs->make<TH1F>("GenTauPtWithDMF_MIso3Hits", "GenTauPtWithDMF_MIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_MIso3Hits = fs->make<TH1F>("GenTauEtaWithDMF_MIso3Hits", "GenTauEtaWithDMF_MIso3Hits" ,100,-4,4);
  GenTauPhiWithDMF_MIso3Hits = fs->make<TH1F>("GenTauPhiWithDMF_MIso3Hits", "GenTauPhiWithDMF_MIso3Hits" ,100,-4,4);

  GenTauPtWithDMF_TIso3Hits = fs->make<TH1F>("GenTauPtWithDMF_TIso3Hits", "GenTauPtWithDMF_TIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_TIso3Hits = fs->make<TH1F>("GenTauEtaWithDMF_TIso3Hits", "GenTauEtaWithDMF_TIso3Hits" ,100,-4,4);
  GenTauPhiWithDMF_TIso3Hits = fs->make<TH1F>("GenTauPhiWithDMF_TIso3Hits", "GenTauPhiWithDMF_TIso3Hits" ,100,-4,4);



  GenTauPtWithDMF_LIso = fs->make<TH1F>("GenTauPtWithDMF_LIso", "GenTauPtWithDMF_LIso" ,100,0,700);
  GenTauEtaWithDMF_LIso = fs->make<TH1F>("GenTauEtaWithDMF_LIso", "GenTauEtaWithDMF_LIso" ,100,-4,4);
  GenTauPhiWithDMF_LIso = fs->make<TH1F>("GenTauPhiWithDMF_LIso", "GenTauPhiWithDMF_LIso" ,100,-4,4);

  GenTauPtWithDMF_MIso = fs->make<TH1F>("GenTauPtWithDMF_MIso", "GenTauPtWithDMF_MIso" ,100,0,700);
  GenTauEtaWithDMF_MIso = fs->make<TH1F>("GenTauEtaWithDMF_MIso", "GenTauEtaWithDMF_MIso" ,100,-4,4);
  GenTauPhiWithDMF_MIso = fs->make<TH1F>("GenTauPhiWithDMF_MIso", "GenTauPhiWithDMF_MIso" ,100,-4,4);

  GenTauPtWithDMF_TIso = fs->make<TH1F>("GenTauPtWithDMF_TIso", "GenTauPtWithDMF_TIso" ,100,0,700);
  GenTauEtaWithDMF_TIso = fs->make<TH1F>("GenTauEtaWithDMF_TIso", "GenTauEtaWithDMF_TIso" ,100,-4,4);
  GenTauPhiWithDMF_TIso = fs->make<TH1F>("GenTauPhiWithDMF_TIso", "GenTauPhiWithDMF_TIso" ,100,-4,4);

  GenTauPtWithDMF_VLChar = fs->make<TH1F>("GenTauPtWithDMF_VLChar", "GenTauPtWithDMF_VLChar" ,100,0,700);
  GenTauEtaWithDMF_VLChar = fs->make<TH1F>("GenTauEtaWithDMF_VLChar", "GenTauEtaWithDMF_VLChar" ,100,-4,4);
  GenTauPhiWithDMF_VLChar = fs->make<TH1F>("GenTauPhiWithDMF_VLChar", "GenTauPhiWithDMF_VLChar" ,100,-4,4);

  GenTauPtWithDMF_LChar = fs->make<TH1F>("GenTauPtWithDMF_LChar", "GenTauPtWithDMF_LChar" ,100,0,700);
  GenTauEtaWithDMF_LChar = fs->make<TH1F>("GenTauEtaWithDMF_LChar", "GenTauEtaWithDMF_LChar" ,100,-4,4);
  GenTauPhiWithDMF_LChar = fs->make<TH1F>("GenTauPhiWithDMF_LChar", "GenTauPhiWithDMF_LChar" ,100,-4,4);

  GenTauPtWithDMF_MChar = fs->make<TH1F>("GenTauPtWithDMF_MChar", "GenTauPtWithDMF_MChar" ,100,0,700);
  GenTauEtaWithDMF_MChar = fs->make<TH1F>("GenTauEtaWithDMF_MChar", "GenTauEtaWithDMF_MChar" ,100,-4,4);
  GenTauPhiWithDMF_MChar = fs->make<TH1F>("GenTauPhiWithDMF_MChar", "GenTauPhiWithDMF_MChar" ,100,-4,4);

  GenTauPtWithDMF_TChar = fs->make<TH1F>("GenTauPtWithDMF_TChar", "GenTauPtWithDMF_TChar" ,100,0,700);
  GenTauEtaWithDMF_TChar = fs->make<TH1F>("GenTauEtaWithDMF_TChar", "GenTauEtaWithDMF_TChar" ,100,-4,4);
  GenTauPhiWithDMF_TChar = fs->make<TH1F>("GenTauPhiWithDMF_TChar", "GenTauPhiWithDMF_TChar" ,100,-4,4);

  ChargedIsoSumPtGenTauPtMuonElectron = fs->make<TProfile>("ChargedIsoSumPtGenTauPtMuonElectron","ChargedIsoSumPtGenTauPtMuonElectron",25,0,700,0,700);
  ChargedIsoSumPtGenTauEtaMuonElectron = fs->make<TProfile>("ChargedIsoSumPtGenTauEtaMuonElectron","ChargedIsoSumPtGenTauEtaMuonElectron",25,-4,4,0,700);
  ChargedIsoSumPtGenTauPhiMuonElectron = fs->make<TProfile>("ChargedIsoSumPtGenTauPhiMuonElectron","ChargedIsoSumPtGenTauPhiMuonElectron",25,-4,4,0,700);
  
  NeutralIsoSumPtGenTauPtMuonElectron = fs->make<TProfile>("NeutralIsoSumPtGenTauPtMuonElectron","NeutralIsoSumPtGenTauPtMuonElectron",25,0,700,0,700);
  NeutralIsoSumPtGenTauEtaMuonElectron = fs->make<TProfile>("NeutralIsoSumPtGenTauEtaMuonElectron","NeutralIsoSumPtGenTauEtaMuonElectron",25,-4,4,0,700);
  NeutralIsoSumPtGenTauPhiMuonElectron = fs->make<TProfile>("NeutralIsoSumPtGenTauPhiMuonElectron","NeutralIsoSumPtGenTauPhiMuonElectron",25,-4,4,0,700);
  
  PUcorrSumPtGenTauPtMuonElectron = fs->make<TProfile>("PUcorrIsoSumPtGenTauPtMuonElectron","PUcorrIsoSumPtGenTauPtMuonElectron",25,0,700,0,700);
  PUcorrSumPtGenTauEtaMuonElectron = fs->make<TProfile>("PUcorrIsoSumPtGenTauEtaMuonElectron","PUcorrIsoSumPtGenTauEtaMuonElectron",25,-4,4,0,700);
  PUcorrSumPtGenTauPhiMuonElectron = fs->make<TProfile>("PUcorrIsoSumPtGenTauPhiMuonElectron","PUcorrIsoSumPtGenTauPhiMuonElectron",25,-4,4,0,700);
  
  CorrelationPlots = fs->make<TH2F>("CorrelationPlots", "CorrelationPlots",3,0,2,3,0,2);

}


FakeRate::~FakeRate()
{
 
}


void FakeRate::Fill(const edm::Event& iEvent)
{
   using namespace edm;
   using namespace std;
   using namespace reco;
   using namespace pat;

  iEvent.getByLabel("genParticles", _genParticles); 
   
  Handle< pat::TauCollection > _patTaus;
  iEvent.getByLabel("patTaus", _patTaus);
  
  Handle< reco::TrackCollection > track;
  iEvent.getByLabel("generalTracks", track);

  edm::Handle<pat::JetCollection> pfjet;
  iEvent.getByLabel("selectedPatJets", pfjet);

  iEvent.getByLabel("ak5GenJets", _genJets);
  

  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  
 
  iEvent.getByLabel("hpsPFTauDiscriminationByVLooseChargedIsolation",_hpsTau);
  
  iEvent.getByLabel("hpsPFTauDiscriminationByLooseChargedIsolation",_hpsTau1);
  
  iEvent.getByLabel("hpsPFTauDiscriminationByMediumChargedIsolation",_hpsTau2);
  iEvent.getByLabel("hpsPFTauDiscriminationByTightChargedIsolation",_hpsTau3);
  
  
  iEvent.getByLabel("hpsPFTauIsolationChargedIsoPtSum", _chargedIsoPtSum);
  iEvent.getByLabel("hpsPFTauIsolationNeutralIsoPtSum", _neutralIsoPtSum);
  iEvent.getByLabel("hpsPFTauIsolationPUcorrPtSum", _pucorrPtSum);
  iEvent.getByLabel("hpsPFTauDiscriminationByRawChargedIsolationDBSumPtCorr",_rawCharged);

  for(reco::TrackCollection::const_iterator tp = track->begin(); tp != track->end(); ++tp){
   
   TrackPt->Fill(tp->pt());
   TrackEta->Fill(tp->eta());
   TrackPhi->Fill(tp->phi());
   }
 // int theNumberOfTaus1 =0;

 // Jet To Tau Fake Rate

/*   for(pat::TauCollection::const_iterator patTau2 = _patTaus->begin(); patTau2 != _patTaus->end(); ++patTau2) {

    if(patTau2->isPFTau()) {
    //if(patTau2->pfTauTagInfoRef()->pfJetRef().isNonnull()){
    double gg = patTau2->pfJetRef()->pt();
    cout<<"pt \t"<<gg<<endl; 
    std::cout<<"present"<<endl;
     } else

 cout<<"not present"<<std::endl;

    //}



   }
*/
  for(pat::TauCollection::const_iterator patTau1 = _patTaus->begin(); patTau1 != _patTaus->end(); ++patTau1) {
    

    bool matchingGen = false;
    bool TauEtaCuts = false;
    bool RecoptCut = false;

    bool DecayModeFinding = false;

    if(matchToGen(*patTau1).first) matchingGen = true;
    if(abs(patTau1->eta()) < 2.3) TauEtaCuts = true;
    
    if((patTau1->pt()) > 20) RecoptCut = true;
    
    if(patTau1->tauID("decayModeFinding") > 0.5) DecayModeFinding = true; 

    if(patTau1->pfJetRef().isNonnull()) { 
   //  reco::Candidate::LorentzVector p4Jet_ = patTau1->pfJetRef()->p4();
      JetPt->Fill(patTau1->pfJetRef()->pt());
     } 
    // Decay MOde Eff vs Pt ////////////////////////////////////////////////
    if((matchingGen) && (TauEtaCuts) && (RecoptCut)) {
      GenTauPtWithoutDMF->Fill(matchToGen(*patTau1).second.pt());	  
      GenTauEtaWithoutDMF->Fill(matchToGen(*patTau1).second.eta());
      GenTauPhiWithoutDMF->Fill(matchToGen(*patTau1).second.phi());
      
    }
    
    if((matchingGen) && (TauEtaCuts) && (RecoptCut)&& (DecayModeFinding)) {
      
      GenTauPtWithDMF->Fill(matchToGen(*patTau1).second.pt());	  
      GenTauEtaWithDMF->Fill(matchToGen(*patTau1).second.eta());
      GenTauPhiWithDMF->Fill(matchToGen(*patTau1).second.phi());
      

      /////////////////////////////////////////////////////////////////////////////////
      
      
    ////////// DMF v/s Eta Phi /////////////////////////

      if(patTau1->tauID("againstMuonLoose2") > 0.5) {
	
	GenTauPtWithDMF_ML2->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_ML2->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_ML2->Fill(matchToGen(*patTau1).second.phi());
      }
      
      
      

      if(patTau1->tauID("againstMuonMedium2") > 0.5) {
	
	GenTauPtWithDMF_MM2->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_MM2->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_MM2->Fill(matchToGen(*patTau1).second.phi());
      }
  

      if(patTau1->tauID("againstMuonTight2") > 0.5) {
	
	GenTauPtWithDMF_MT2->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_MT2->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_MT2->Fill(matchToGen(*patTau1).second.phi());
      }
  

      if(patTau1->tauID("againstMuonLoose3") > 0.5) {

	GenTauPtWithDMF_ML3->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_ML3->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_ML3->Fill(matchToGen(*patTau1).second.phi());
      }
    

      if(patTau1->tauID("againstMuonTight3") > 0.5) {
	
	GenTauPtWithDMF_MT3->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_MT3->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_MT3->Fill(matchToGen(*patTau1).second.phi());
      }
  

      if(patTau1->tauID("againstElectronLooseMVA3") > 0.5) {
	
	GenTauPtWithDMF_EL3->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_EL3->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_EL3->Fill(matchToGen(*patTau1).second.phi());
      }
      
   

      if(patTau1->tauID("againstElectronMediumMVA3") > 0.5) {
	
	GenTauPtWithDMF_EM3->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_EM3->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_EM3->Fill(matchToGen(*patTau1).second.phi());
      }
      
      if(patTau1->tauID("againstElectronTightMVA3") > 0.5) {
	
	GenTauPtWithDMF_ET3->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_ET3->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_ET3->Fill(matchToGen(*patTau1).second.phi());
      }
      
  

    if(patTau1->tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits") > 0.5) {
	
	GenTauPtWithDMF_LIso3Hits->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_LIso3Hits->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_LIso3Hits->Fill(matchToGen(*patTau1).second.phi());
      }
   
    if(patTau1->tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits") > 0.5) {
      
	GenTauPtWithDMF_MIso3Hits->Fill(matchToGen(*patTau1).second.pt());	  
	GenTauEtaWithDMF_MIso3Hits->Fill(matchToGen(*patTau1).second.eta());
	GenTauPhiWithDMF_MIso3Hits->Fill(matchToGen(*patTau1).second.phi());
      }
    
    if(patTau1->tauID("byTightCombinedIsolationDeltaBetaCorr3Hits") > 0.5) {
      
      GenTauPtWithDMF_TIso3Hits->Fill(matchToGen(*patTau1).second.pt());	  
      GenTauEtaWithDMF_TIso3Hits->Fill(matchToGen(*patTau1).second.eta());
      GenTauPhiWithDMF_TIso3Hits->Fill(matchToGen(*patTau1).second.phi());
    }
   
    
    if(patTau1->tauID("byLooseCombinedIsolationDeltaBetaCorr")> 0.5) {
      
      GenTauPtWithDMF_LIso->Fill(matchToGen(*patTau1).second.pt());	  
      GenTauEtaWithDMF_LIso->Fill(matchToGen(*patTau1).second.eta());
      GenTauPhiWithDMF_LIso->Fill(matchToGen(*patTau1).second.phi());
      
    }

  if(patTau1->tauID("byMediumCombinedIsolationDeltaBetaCorr")> 0.5) {
      
      GenTauPtWithDMF_MIso->Fill(matchToGen(*patTau1).second.pt());	  
      GenTauEtaWithDMF_MIso->Fill(matchToGen(*patTau1).second.eta());
      GenTauPhiWithDMF_MIso->Fill(matchToGen(*patTau1).second.phi());
      
    }


  if(patTau1->tauID("byTightCombinedIsolationDeltaBetaCorr")> 0.5) {
      
      GenTauPtWithDMF_TIso->Fill(matchToGen(*patTau1).second.pt());	  
      GenTauEtaWithDMF_TIso->Fill(matchToGen(*patTau1).second.eta());
      GenTauPhiWithDMF_TIso->Fill(matchToGen(*patTau1).second.phi());
      
    }

  // TProfile Plots for PFTau Isolations
  // These should be variation w.r.t eta for Denominator and  Numerator parts 
  
  
  for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
    reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
    if((fabs(patTau1->pt()  - tauCandidate->pt()) /patTau1->pt() < 0.0001) && (fabs(patTau1->eta() - tauCandidate->eta())/patTau1->eta() < 0.0001)&&(fabs(patTau1->phi() - tauCandidate->phi())/patTau1->phi() < 0.0001) )
      {
	
	if((*_hpsTau)[tauCandidate] > 0.5) {
	  GenTauPtWithDMF_VLChar->Fill(matchToGen(*patTau1).second.pt());	  
	  GenTauEtaWithDMF_VLChar->Fill(matchToGen(*patTau1).second.eta());
	  GenTauPhiWithDMF_VLChar->Fill(matchToGen(*patTau1).second.phi());
	
	}
        
	
	if((*_hpsTau1)[tauCandidate] > 0.5) {
	
	  GenTauPtWithDMF_LChar->Fill(matchToGen(*patTau1).second.pt());	  
	  GenTauEtaWithDMF_LChar->Fill(matchToGen(*patTau1).second.eta());
	  GenTauPhiWithDMF_LChar->Fill(matchToGen(*patTau1).second.phi());
	}
	
	if((*_hpsTau2)[tauCandidate] > 0.5) {
	  
	  GenTauPtWithDMF_MChar->Fill(matchToGen(*patTau1).second.pt());	  
	  GenTauEtaWithDMF_MChar->Fill(matchToGen(*patTau1).second.eta());
	  GenTauPhiWithDMF_MChar->Fill(matchToGen(*patTau1).second.phi());
	  
	}
		    
	if((*_hpsTau3)[tauCandidate] > 0.5) {
	  
	  GenTauPtWithDMF_TChar->Fill(matchToGen(*patTau1).second.pt());	  
	  GenTauEtaWithDMF_TChar->Fill(matchToGen(*patTau1).second.eta());
	  GenTauPhiWithDMF_TChar->Fill(matchToGen(*patTau1).second.phi());
		      
	}
		    
	
	
	
	ChargedIsoSumPtGenTauPtMuonElectron->Fill((matchToGen(*patTau1).second.pt()),((*_chargedIsoPtSum)[tauCandidate]));
	ChargedIsoSumPtGenTauEtaMuonElectron->Fill((matchToGen(*patTau1).second.eta()),((*_chargedIsoPtSum)[tauCandidate]));
	ChargedIsoSumPtGenTauPhiMuonElectron->Fill((matchToGen(*patTau1).second.phi()),((*_chargedIsoPtSum)[tauCandidate]));
	
	
	NeutralIsoSumPtGenTauPtMuonElectron->Fill((matchToGen(*patTau1).second.pt()),(*_neutralIsoPtSum)[tauCandidate]);
	NeutralIsoSumPtGenTauEtaMuonElectron->Fill((matchToGen(*patTau1).second.eta()),(*_neutralIsoPtSum)[tauCandidate]);
	NeutralIsoSumPtGenTauPhiMuonElectron->Fill((matchToGen(*patTau1).second.phi()),(*_neutralIsoPtSum)[tauCandidate]);
	
	
	PUcorrSumPtGenTauPtMuonElectron->Fill((matchToGen(*patTau1).second.pt()),(*_pucorrPtSum)[tauCandidate]);
	PUcorrSumPtGenTauEtaMuonElectron->Fill((matchToGen(*patTau1).second.eta()),(*_pucorrPtSum)[tauCandidate]);
	PUcorrSumPtGenTauPhiMuonElectron->Fill((matchToGen(*patTau1).second.phi()),(*_pucorrPtSum)[tauCandidate]);

	// Here it comes
	// cout<<"(*_chargedIsoPtSum)[tauCandidate]"<<(*_chargedIsoPtSum)[tauCandidate]<<std::endl;
	// cout<<"(*_neutralIsoPtSum)[tauCandidate]"<<(*_neutralIsoPtSum)[tauCandidate]<<std::endl;
	// cout<<"(*_pucorrPtSum)[tauCandidate]"<<(*_pucorrPtSum)[tauCandidate]<<std::endl; 
	// cout<<"hpsLooseCombined3HitsFromPtSums"<< "\t = \t " <<  ( (*_chargedIsoPtSum)[tauCandidate] + TMath::Max(0., (*_neutralIsoPtSum)[tauCandidate] - 0.4576*(*_pucorrPtSum)[tauCandidate])) <<std::endl;
	
       double hpsLooseCombined3HitsFromPtSums = ( ( (*_chargedIsoPtSum)[tauCandidate] + TMath::Max(0., (*_neutralIsoPtSum)[tauCandidate] - 0.4576*(*_pucorrPtSum)[tauCandidate])) < 2.0) ? 1.0 : 0.0;
		    
        bool OtherOne = (patTau1->tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits")) > 0.5;  
	CorrelationPlots->Fill(OtherOne,hpsLooseCombined3HitsFromPtSums);
      }
  
    
  }
    }
  }
		  

  
}

  

pair<bool, reco::Candidate::LorentzVector> FakeRate::matchToGen(const pat::Tau& theObject) {
   bool isGenMatched = false;
   reco::Candidate::LorentzVector theGenObject(0,0,0,0);
   for(reco::GenParticleCollection::const_iterator genParticle = _genParticles->begin();genParticle != _genParticles->end();++genParticle) {
     if((abs(genParticle->pdgId()) == 15) && (genParticle->status() != 3)) {
       int neutrinos = 0;
       MChadtau = genParticle->p4();
       motherCand = genParticle->mother(0);
       while(motherCand->pdgId() == genParticle->pdgId()) {motherCand = motherCand->mother(0);}
       grandMotherCand = motherCand->mother(0);
       while(grandMotherCand->pdgId() == motherCand->pdgId()) {grandMotherCand = grandMotherCand->mother(0);}
 
       for(int ii=0; ii<(int)(genParticle->numberOfDaughters()); ii++) {
         daughterCand = genParticle->daughter(ii);
         if( (abs(daughterCand->pdgId()) == 12) || (abs(daughterCand->pdgId()) == 14) || (abs(daughterCand->pdgId()) == 16) ) {
           neutrinos++;
           MChadtau = MChadtau - daughterCand->p4();
         }
       }
       if(neutrinos == 1) {
         if(reco::deltaR(MChadtau.eta(), MChadtau.phi(), theObject.eta(), theObject.phi()) < _TauToGenMatchingDeltaR) {
           if(_UseTauMotherId) {
             if(abs(motherCand->pdgId()) == _TauMotherId) {
               if(_UseTauGrandMotherId) {
                 if(abs(grandMotherCand->pdgId()) == _TauGrandMotherId) {isGenMatched = true;theGenObject = MChadtau;}
               } else {
                 isGenMatched = true;
                 theGenObject = MChadtau;
               }
             }
           } else {isGenMatched = true;theGenObject = MChadtau;}
         }
       }
    }
 }
   pair<bool, reco::Candidate::LorentzVector> GenMatchedInformation(isGenMatched,theGenObject);
   return GenMatchedInformation;
}


pair<bool, reco::Candidate::LorentzVector> FakeRate::matchTauToGenMuon(const pat::Tau& theObject) {
   bool isGenMuonMatched = false;
   reco::Candidate::LorentzVector theGenMuonObject(0,0,0,0);
   for(reco::GenParticleCollection::const_iterator genParticle = _genParticles->begin();genParticle != _genParticles->end();++genParticle) {
   if ((abs(genParticle->pdgId()) == 13) &&  (genParticle->status() == 1)) {
    //std::cout<<"DEBUG1"<<std::endl;
  if(reco::deltaR(genParticle->eta(), genParticle->phi(), theObject.eta(), theObject.phi()) >= _TauToGenMatchingDeltaR) continue;
   if(genParticle->mother(0)->pdgId() == genParticle->pdgId()) {
      motherCand = genParticle->mother(0)->mother(0);
      if(motherCand->mother(0)->pdgId() == motherCand->pdgId()) {grandMotherCand = motherCand->mother(0)->mother(0);}
      else {grandMotherCand = motherCand->mother(0);}
     } else {
        motherCand = genParticle->mother(0);
         if(motherCand->mother(0)->pdgId() == motherCand->pdgId()) {grandMotherCand = motherCand->mother(0)->mother(0);}
         else {grandMotherCand = motherCand->mother(0);}
        }
        if(_UseLeptonMotherId) {
       //     std::cout<<"DEBUG2"<<std::endl;
           if(abs(motherCand->pdgId()) == _LeptonMotherId) {
           if(_UseLeptonGrandMotherId) {
      if(abs(grandMotherCand->pdgId()) == _LeptonGrandMotherId) {isGenMuonMatched = true;theGenMuonObject = genParticle->p4();}
           } else {isGenMuonMatched = true;theGenMuonObject = genParticle->p4();}
        }
      } else {isGenMuonMatched = true;theGenMuonObject = genParticle->p4();}
    }
  ///electron part finished
 }
 pair<bool, reco::Candidate::LorentzVector> GenMuonMatchedInformation(isGenMuonMatched,theGenMuonObject);
 return GenMuonMatchedInformation;
}
 

pair<bool, reco::Candidate::LorentzVector> FakeRate::matchTauToGenElectron(const pat::Tau& theObject) {
  bool isGenElectronMatched = false;
  reco::Candidate::LorentzVector theGenElectronObject(0,0,0,0);
  for(reco::GenParticleCollection::const_iterator genParticle = _genParticles->begin();genParticle != _genParticles->end();++genParticle) {
    if ((abs(genParticle->pdgId()) == 11) && (genParticle->status() == 1)) {
      // std::cout<<"DEBUG1::"<<std::endl;
      if(reco::deltaR(genParticle->eta(), genParticle->phi(), theObject.eta(), theObject.phi()) >= _TauToGenMatchingDeltaR) continue;
      if(genParticle->mother(0)->pdgId() == genParticle->pdgId()) {
	motherCand = genParticle->mother(0)->mother(0);
	if(motherCand->mother(0)->pdgId() == motherCand->pdgId()) {grandMotherCand = motherCand->mother(0)->mother(0);} 
	else {grandMotherCand = motherCand->mother(0);}
      } else {
	motherCand = genParticle->mother(0);
	if(motherCand->mother(0)->pdgId() == motherCand->pdgId()) {grandMotherCand = motherCand->mother(0)->mother(0);} 
	else {grandMotherCand = motherCand->mother(0);}
      }
      if(_UseLeptonMotherId) {
	if(abs(motherCand->pdgId()) == _LeptonMotherId) {
	  if(_UseLeptonGrandMotherId) {
	    if(abs(grandMotherCand->pdgId()) == _LeptonGrandMotherId) {isGenElectronMatched = true;theGenElectronObject = genParticle->p4();}
	  } else {isGenElectronMatched = true;theGenElectronObject = genParticle->p4();}
	}
      } else {isGenElectronMatched = true;theGenElectronObject = genParticle->p4();}
    }                                                
    ///electron part finished
  }
  pair<bool, reco::Candidate::LorentzVector> GenElectronMatchedInformation(isGenElectronMatched,theGenElectronObject);
  return GenElectronMatchedInformation;
}

pair<bool, reco::Candidate::LorentzVector> FakeRate::matchTauToGenJet(const pat::Tau& theObject) {                                                                                                                                                   
  bool isGenJetMatched = false;
  reco::Candidate::LorentzVector theGenJetObject(0,0,0,0);
 for(reco::GenJetCollection::const_iterator genjet = _genJets->begin(); genjet != _genJets->end(); ++genjet) {
 

   if(reco::deltaR(genjet->eta(), genjet->phi(), theObject.eta(), theObject.phi()) < _TauToGenMatchingDeltaR) {
           isGenJetMatched = true; theGenJetObject = genjet->p4();
   }
 }


  pair<bool, reco::Candidate::LorentzVector> GenJetMatchedInformation(isGenJetMatched,theGenJetObject);
  return GenJetMatchedInformation;
}

