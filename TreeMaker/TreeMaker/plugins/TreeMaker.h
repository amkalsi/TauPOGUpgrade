
// system include files
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
/*
#include "TauIDChecks.h"
#include "TauIDChecks_newDM.h"
#include "TauIDChecks_newDMG2p3.h"
#include "TauIDChecks_newDMU4p0.h"
#include "MuonVeto.h"

#include "FakeRate.h"
#include "MuTauFakeRate.h"
#include "MuTauFakeRateG2p3.h"
#include "MuTauFakeRateU4p0.h"

#include "JetTauFakeRate.h"
#include "JetTauFakeRateG2p3.h"
#include "JetTauFakeRateU4p0.h"

#include "RhoVariables.h"
#include "ETauFakeRate.h"
#include "JetTauFakeRateFull.h"
#include "JetTauFakeRateFullNDM.h"
#include "JETTauFakeRateFull.h"
#include "JETTauFakeRateFullNDM.h"

#include "JetTauFakeRateFullSimon.h"
#include "JetTauFakeRateFullSimonNew.h"

 #include "JetTauFakeRateFullSimonEtaG23.h"
#include "JetTauFakeRateFullSimonEta40.h"
#include "TauIDChecksU4p0.h"
#include "ETauFakeRateU4p0.h"
#include "ETauFakeRateG2p3.h"
#include "LessInfo.h"
#include "DetectorInfo.h"
#include "NewDefinitions.h"
#include "NewDefinitionU3p0.h"
#include "NewDefinitionG2p3.h"
#include "NewDefinitions_newdmf.h"
#include "NewDecayMode.h"
#include "OldDecayMode.h"
#include "ETauFakeRateNew.h"
#include "MuTauFakeRateNew.h"
#include "NEWDecayMode.h"
#include "NEWDecayOthers.h"

#include "OLDDecayMode.h"
#include "OLDDecayOthers.h"
#include "NEWDecayMode1Prong.h"
#include "OLDDecayMode1Prong.h"
*/
 #include "MuTauFakeRate.h" 
 #include "MuTauFakeRate2to3.h"
 #include "MuTauFakeRateUpto3.h"
#include "TauIDUpto2to3.h"
#include "TauIDUpto23.h"
#include "TauIDUpto3.h"

#include "TauIDUpto2to3New.h"
#include "TauIDUpto23New.h"
#include "TauIDUpto3New.h"
#include "ETauFakeRate.h"
#include "JetTauFakeRateFullSimon.h"
#include "NEWDecayMode.h"
#include "OLDDecayMode.h"
#include "OLDDecayOthers.h"
#include "NEWDecayOthers.h"
//#include "ForDecayMode.h"
// class declaration                                                                                                                           
//                                                                                                                                             
using namespace std;
using namespace edm;
bool fillinfo;
bool fillefficiency;
bool fillefficiencyG2p3;
bool fillefficiencyU4p0; 

bool fillnew1, fillnew2, fillnew3, fillold1, fillold2,fillold3 ; 
bool fillefficiency_newDM;
bool fillefficiency_newDMG2p3;
bool fillefficiency_newDMU4p0;

bool fillfakerate;
bool fillfakerate2;
bool fillfakerate3;
bool fillfakerate4;

bool fillfakerateold;
bool fillfakeratenew;
bool fillfakerateG2p3;
bool fillfakerateU4p0;

bool fillmuTaufr;
bool fillmuTaufrG2p3;
bool fillmuTaufrU4p0; 
bool filleTaufr;
bool filleTaufrG2p3;
bool filleTaufrU4p0;
bool fillnewtauid; 
bool filloldtauid; 

bool isnewTau1;
bool isnewTau2;
bool isnewTau3;


bool isTauID1,isTauID2,isTauID3,isTauID4,isTauID5,isTauID6,isTauID0;
bool isJetID1,isJetID2,isJetID3, isJetID4;
bool isMuID1,isMuID2,isMuID3;
bool isEleID1,isEleID2,isEleID3;
bool filldetectorinfo;
//
// class declaration
//
