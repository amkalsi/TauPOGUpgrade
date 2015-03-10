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
  

  MuTauFakeRate *mufake;
  ETauFakeRate *etaufake;
  NEWDecayMode *NewDMF;
  OLDDecayMode *OLDDMF; 
  NEWDecayOthers *newothers;
  OLDDecayOthers *oldothers; 
  JetTauFakeRateFullSimon *jetfake;
 
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
 isnewTau3 = iConfig.getParameter<bool>("isnewTau3"); 
 isTauID0 = iConfig.getParameter<bool>("isTauID0");
 isTauID1 = iConfig.getParameter<bool>("isTauID1");
 isTauID2 = iConfig.getParameter<bool>("isTauID2");
 isJetID1 = iConfig.getParameter<bool>("isJetID1");
 isJetID2 = iConfig.getParameter<bool>("isJetID2");
 isJetID3 = iConfig.getParameter<bool>("isJetID3");
 isJetID4 = iConfig.getParameter<bool>("isJetID4");
 isEleID1 = iConfig.getParameter<bool>("isEleID1");
 isEleID2 = iConfig.getParameter<bool>("isEleID2");

 isTauID3 = iConfig.getParameter<bool>("isTauID3");
/* isTauID4 = iConfig.getParameter<bool>("isTauID4");
 isTauID5 = iConfig.getParameter<bool>("isTauID5");
 isTauID6 = iConfig.getParameter<bool>("isTauID6");
 isEleID1 = iConfig.getParameter<bool>("isEleID1");
*/ 
 isEleID2 = iConfig.getParameter<bool>("isEleID2");
 isEleID3 = iConfig.getParameter<bool>("isEleID3");

 isMuID1 = iConfig.getParameter<bool>("isMuID1");
 isMuID2  = iConfig.getParameter<bool>("isMuID2");
 isMuID3  = iConfig.getParameter<bool>("isMuID3");


edm::Service<TFileService> fs;

if(isnewTau1)  NewDMF = new NEWDecayMode("NewDMFs",fs,iConfig); 
if(isnewTau2)  OLDDMF = new OLDDecayMode("OldDMFs",fs,iConfig); 
if(isTauID0)  newothers = new NEWDecayOthers("newothers",fs,iConfig);
if(isTauID1)  oldothers = new OLDDecayOthers("oldothers",fs,iConfig); 
if(isMuID1)  mufake = new MuTauFakeRate("mufake",fs,iConfig);
if(isEleID1) etaufake = new ETauFakeRate("efake",fs,iConfig);
if(isJetID1) jetfake  = new JetTauFakeRateFullSimon("jetfake",fs,iConfig);
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

if(isTauID0) {fillold1 = true;}
if(isTauID1) { fillold2 =  true;}
if(isTauID2) { fillold3 =  true;}
if(isnewTau1) {fillnew1 = true;}
if(isnewTau2) {fillnew2 = true;}
if(isEleID1) {fillnew3 = true;}
if(isJetID1) {fillfakerate=true; }
if(isJetID2) {fillfakerate2=true; }
if(isJetID3) {fillfakerate3=true; }
if(isJetID4) {fillfakerate4=true; }

if(isMuID1) { fillefficiency_newDM = true;}
if(isMuID2) { fillefficiency_newDMG2p3 =  true;}
if(isMuID3) { fillefficiency_newDMU4p0 =  true;}

/*
if(isTauID3) {fillefficiencyU4p0 =  true;} 

if(isTauID4) { fillefficiency_newDM = true;}
if(isTauID5) { fillefficiency_newDMG2p3 =  true;}
if(isTauID6) { fillefficiency_newDMU4p0 =  true;}
*/

if(isJetID1) {fillfakerate=true; }
if(isJetID2) { fillfakerateG2p3 =  true; }

// if(isnewTau1) { if(fillnewtauid) NewDMF->Fill(iEvent);}
if(isTauID0) { if(fillold1) newothers->Fill(iEvent);}
if(isTauID1) { if(fillold2) oldothers->Fill(iEvent);}
if(isnewTau1) { if(fillnew1) NewDMF->Fill(iEvent);}
if(isnewTau2) { if(fillnew2) OLDDMF->Fill(iEvent);}
 
if(isMuID1) { if(fillefficiency_newDM)  mufake->Fill(iEvent);}

if(isEleID1)  { if(fillnew3) etaufake->Fill(iEvent);}
if(isJetID1) { if(fillfakerate) jetfake->Fill(iEvent, iSetup);}

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
