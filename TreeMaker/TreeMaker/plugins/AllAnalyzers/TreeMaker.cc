// -*- C++ -*-
//
// Package:    TreeMaker
// Class:      TreeMaker
// 
/**\class TreeMaker TreeMaker.cc TauIDChecks/TreeMaker/plugins/TreeMaker.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  kaur amandeepkalsi
//         Created:  Fri, 25 Oct 2013 15:07:16 GMT
// $Id$
//
//


// system include files
#include "./TreeMaker.h"
//
// class declaration
//

class TreeMaker : public edm::EDAnalyzer {
   public:
      explicit TreeMaker(const edm::ParameterSet&);
      ~TreeMaker();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

      DetectorInfo *detector;      
    
      NEWDecayMode *NewDMF;
      NEWDecayOthers *newdefothers;

      OLDDecayMode *OldDMF;
      OLDDecayOthers *olddefothers;

      NEWDecayMode1Prong *newdmf1prong;
      OLDDecayMode1Prong *olddmf1prong;



      JetTauFakeRateFullSimon *fakerateold;
   JetTauFakeRateFullSimonNew *fakeratenew;
 
      JetTauFakeRateFullSimonEtaG23 *etag2p3;
      JetTauFakeRateFullSimonEta40 *etal4p0;

      MuTauFakeRate  *muFake;
      MuTauFakeRateNew  *muFakeNew;

      ETauFakeRate *etaufr;
      ETauFakeRateNew *etaufrNew;

  private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) ;
      virtual void endJob() ;

      //virtual void beginRun(edm::Run const&, edm::EventSetup const&) ;
      //virtual void endRun(edm::Run const&, edm::EventSetup const&) ;
      //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) ;
      //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) ;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
TreeMaker::TreeMaker(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
 isnewTau1 = iConfig.getParameter<bool>("isnewTau1");
 isnewTau2 = iConfig.getParameter<bool>("isnewTau2");
 isTauID0 = iConfig.getParameter<bool>("isTauID0");
 isTauID1 = iConfig.getParameter<bool>("isTauID1");
 isJetID1 = iConfig.getParameter<bool>("isJetID1");
 isJetID2 = iConfig.getParameter<bool>("isJetID2");
 isJetID3 = iConfig.getParameter<bool>("isJetID3");
 isJetID4 = iConfig.getParameter<bool>("isJetID4");
 isEleID1 = iConfig.getParameter<bool>("isEleID1");
 isEleID2 = iConfig.getParameter<bool>("isEleID2");

 isTauID2 = iConfig.getParameter<bool>("isTauID2");
 isTauID3 = iConfig.getParameter<bool>("isTauID3");
/* isTauID4 = iConfig.getParameter<bool>("isTauID4");
 isTauID5 = iConfig.getParameter<bool>("isTauID5");
 isTauID6 = iConfig.getParameter<bool>("isTauID6");
 isEleID1 = iConfig.getParameter<bool>("isEleID1");
 
 isEleID2 = iConfig.getParameter<bool>("isEleID2");
 isEleID3 = iConfig.getParameter<bool>("isEleID3");
*/
 isMuID1 = iConfig.getParameter<bool>("isMuID1");
 isMuID2  = iConfig.getParameter<bool>("isMuID2");
// isMuID3  = iConfig.getParameter<bool>("isMuID3");


edm::Service<TFileService> fs;
//std::cout<<"before detector"<<std::endl;
if(true) detector = new DetectorInfo("det",fs,iConfig);    
//std::cout<<"after detector"<<std::endl;
//std::cout<<"inside1"<<std::endl; 
if(isnewTau1) NewDMF = new NEWDecayMode ("NewDMFs",fs,iConfig); 
//std::cout<<"inside2"<<std::endl; 
if(isnewTau2) OldDMF = new OLDDecayMode ("OldDMFs",fs,iConfig); 

//std::cout<<"inside3"<<std::endl; 
if(isTauID0) newdefothers  = new NEWDecayOthers ("NewDMFothers",fs,iConfig);
//std::cout<<"inside4"<<std::endl; 
if(isTauID1) olddefothers = new OLDDecayOthers ("OldDMFothers",fs,iConfig);
//std::cout<<"inside5"<<std::endl; 

if(isTauID2) newdmf1prong  = new NEWDecayMode1Prong  ("NewDMF1prong",fs,iConfig);
if(isTauID3) olddmf1prong  = new OLDDecayMode1Prong  ("OldDMF1prong",fs,iConfig);

if(isJetID1) fakerateold = new JetTauFakeRateFullSimon("fakerateoldDM",fs,iConfig);
if(isJetID2) fakeratenew = new JetTauFakeRateFullSimonNew("fakeratenewDM",fs,iConfig);
if(isJetID3) etag2p3  = new JetTauFakeRateFullSimonEtaG23("fakerateoldDMetag2p3",fs,iConfig);
if(isJetID4) etal4p0  = new JetTauFakeRateFullSimonEta40("fakerateoldDMetal4p0",fs,iConfig);



//if(isJetID2) fakeratenew = new JetTauFakeRateFullNDM("fakeratenewDM",fs,iConfig);

if(isMuID1)  muFake = new MuTauFakeRate("MuTauFR",fs,iConfig);
if(isMuID2)  muFakeNew = new MuTauFakeRateNew("MuTauFRNew",fs,iConfig);
//if(isMuID3)  muFakeU4p0 = new MuTauFakeRateU4p0("MuTauFRU4p0",fs,iConfig);


if(isEleID1)  etaufr = new ETauFakeRate("ETauFR",fs,iConfig); 

if(isEleID2)  etaufrNew = new ETauFakeRateNew("ETauFRNew",fs,iConfig);
//if(isEleID3)  eFakeU4p0 = new ETauFakeRateU4p0("ETauFRU4p0",fs,iConfig);


}


TreeMaker::~TreeMaker()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
TreeMaker::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

if(isTauID0) {fillefficiency = true;}
if(isTauID1) { fillefficiencyG2p3 =  true;}
if(isnewTau1) {fillnewtauid = true;}
if(isnewTau2) {filloldtauid = true;}
if(isJetID1) {fillfakerate=true; }
if(isJetID2) {fillfakerate2=true; }
if(isJetID3) {fillfakerate3=true; }
if(isJetID4) {fillfakerate4=true; }

/*
if(isTauID3) {fillefficiencyU4p0 =  true;} 

if(isTauID4) { fillefficiency_newDM = true;}
if(isTauID5) { fillefficiency_newDMG2p3 =  true;}
if(isTauID6) { fillefficiency_newDMU4p0 =  true;}


if(isJetID1) {fillfakerate=true; }
if(isJetID2) { fillfakerateG2p3 =  true; }
if(isJetID3) { fillfakerateU4p0 =  true; }


if(isJetID1) {fillfakerateold=true; }
if(isJetID2) {fillfakeratenew=true; }
*/
 if(isMuID1) {fillmuTaufr = true; }
 if(isMuID2) {fillmuTaufrG2p3 = true; }



 if(isEleID1) {filleTaufr=true; }
 if(isEleID2) {filleTaufrG2p3=true; }


filldetectorinfo = true;
//std::cout<<"problem here"<<std::endl;
if(filldetectorinfo) detector->Fill(iEvent);
//std::cout<<"problem here1"<<std::endl;
 if(isEleID1) { if(filleTaufr) etaufr->Fill(iEvent); }
 if(isEleID2) { if(filleTaufrG2p3) etaufrNew->Fill(iEvent); }

if(isTauID0) { if(fillefficiency) newdefothers->Fill(iEvent); }
//std::cout<<"problem here2"<<std::endl;

 if(isTauID1) { if(fillefficiencyG2p3) olddefothers->Fill(iEvent); }
//std::cout<<"problem here3"<<std::endl;

 if(isnewTau1) { if(fillnewtauid) NewDMF->Fill(iEvent);}
//std::cout<<"problem here4"<<std::endl;

 if(isnewTau2) { if(filloldtauid) OldDMF->Fill(iEvent);}
if(isJetID1) { if(fillfakerate) fakerateold->Fill(iEvent, iSetup);}
if(isJetID2) { if(fillfakerate2) fakeratenew->Fill(iEvent, iSetup);}
if(isJetID3) { if(fillfakerate3) etag2p3->Fill(iEvent, iSetup);}
if(isJetID4) { if(fillfakerate4) etal4p0->Fill(iEvent, iSetup);}
if(isMuID1) { if(fillmuTaufr) muFake->Fill(iEvent); }
 if(isMuID2) { if(fillmuTaufrG2p3) muFakeNew->Fill(iEvent); }  

#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
TreeMaker::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TreeMaker::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
TreeMaker::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
TreeMaker::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
TreeMaker::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
TreeMaker::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
TreeMaker::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(TreeMaker);
