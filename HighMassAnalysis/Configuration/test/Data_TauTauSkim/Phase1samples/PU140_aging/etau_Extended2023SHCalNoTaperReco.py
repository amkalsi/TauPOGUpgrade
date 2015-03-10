import FWCore.ParameterSet.Config as cms
channel = "BLABLA"
process = cms.Process("PATTuple")

## MessageLogger
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1 



process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False) )
process.options.allowUnscheduled = cms.untracked.bool( False )


## Geometry and Detector Conditions (needed for a few patTuple production steps)

process.load('Configuration.Geometry.GeometryExtended2019_cff')
process.load('Configuration.Geometry.GeometryExtended2019Reco_cff')
process.load('Configuration.StandardSequences.Services_cff')
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = 'PH1_1K_FB_V3::All'
process.load("Configuration.StandardSequences.MagneticField_38T_PostLS1_cff")
process.source = cms.Source("PoolSource", 
                            fileNames = cms.untracked.vstring(

#'root://xrootd.unl.edu//store/mc/SHCAL2023Upg14DR/QCD_Pt-15to3000_Tune4C_14TeV_pythia8/GEN-SIM-RECO/Test_SHCAL_age1k_PU140bx25_PH2_1K_FB_V4-v1/20000/00880C4F-D42F-E411-8090-001E67ABE650.root'
'root://xrootd.unl.edu//store/mc/Upg2023SHCAL14DR/WHToTauTau_M-125_TuneZ2star_14TeV-pythia6/GEN-SIM-RECO/PU140bx25_PH2_1K_FB_V4-v1/00000/00E4FE61-443B-E411-B191-00261894397D.root'
)
                            )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )

from HighMassAnalysis.Configuration.patTupleEventContentForHiMassTau_cff import *
process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('new_skimPat.root'),
                               # save only events passing the full path
                               SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                               outputCommands = cms.untracked.vstring('drop *', *patTupleEventContent ),
                               fastCloning = cms.untracked.bool(False)
                               )

process.scrapingVeto = cms.EDFilter("FilterOutScraping",
                                    applyfilter = cms.untracked.bool(True),
                                    debugOn = cms.untracked.bool(False),
                                    numtrack = cms.untracked.uint32(10),
                                    thresh = cms.untracked.double(0.2)
                                    )

#process.outpath = cms.EndPath(process.out)                                                                                                                        

process.demo = cms.EDAnalyzer('TreeMaker',
                              JetCorrectionService=cms.string('ak5PFL1FastL2L3'),
                              JetAlgorithm             =cms.string('ak5PFJets'),
                              UseCondDB                = cms.untracked.bool(False),
                               etacutmin                = cms.double(-9.0),  
                               etacut                   = cms.double(2.3),
                               isnewTau1                = cms.bool(False),
                               isnewTau2                = cms.bool(False),
                               isnewTau3                = cms.bool(False),
                               isTauID0                 = cms.bool(False),
                               isTauID1                 = cms.bool(False),
                               isTauID2                 = cms.bool(False),       
                               isTauID3                 = cms.bool(False),
                               isTauID4                 = cms.bool(False),
                               isTauID5                 = cms.bool(False),
                               isTauID6                 = cms.bool(False), 
                               isJetID1                 = cms.bool(False),                       
                               isJetID2                 = cms.bool(False),
                               isJetID3                 = cms.bool(False),
                               isJetID4                 = cms.bool(False),
                               isEleID1                 = cms.bool(True),
                               isEleID2                 = cms.bool(False),
                               isEleID3                 = cms.bool(False),  
                               isMuID1                  = cms.bool(False),
                               isMuID2                  = cms.bool(False),
                               isMuID3                  = cms.bool(False),
 
                              MatchLeptonToGen = cms.bool(False),
                              UseLeptonMotherId = cms.bool(False),           # if true, require the matched lepton to come from a certain
                              UseLeptonGrandMotherId = cms.bool(False),      # if true, require the matched lepton to come from a certain
                              LeptonMotherId = cms.int32(24),     # pdgId of the 'mother' particle
                              LeptonGrandMotherId = cms.int32(32),          # pdgId of the 'grandmother' particle
                              MatchTauToGen = cms.bool(True),                         # if true, match reco tau to a gen had tau
                              UseTauMotherId = cms.bool(True),                       # if true, require the matched tau to come from a certain
                              UseTauGrandMotherId = cms.bool(False),      # if true, require the matched tau to come from a certain
                              TauMotherId = cms.int32(23),                           # pdgId of the 'mother' particle
                              TauGrandMotherId = cms.int32(1),                          # pdgId of the 'grandmother' particle
                              TauToGenMatchingDeltaR = cms.double(0.5),         # matching dR:  dR(vis gen tau,reco tau)<X
                              TaumatchToGenJet = cms.bool(False),
                              TaumatchToMuon = cms.bool(False),
                              TaumatchToElectron = cms.bool(False),
                              TaumatchToGenTau = cms.bool(False)
                              
)

## Output Module Configuration (expects a path 'p')

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string("analysis.root")
                                   )


# save only events passing the full path

process.load('RecoJets.Configuration.RecoPFJets_cff')
process.load("PhysicsTools.PatAlgos.patSequences_cff")
  
  # --------------------Modifications for taus--------------------
process.load("PhysicsTools.JetMCAlgos.TauGenJets_cfi")
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
from PhysicsTools.PatAlgos.tools.tauTools import *
switchToPFTauHPS(process)
  
from RecoJets.JetProducers.kt4PFJets_cfi import kt4PFJets
process.kt6PFJetsForIsolation = kt4PFJets.clone( rParam = 0.6, doRhoFastjet = True )
process.kt6PFJetsForIsolation.Rho_EtaMax = cms.double(2.5)
  
#---------------------- gen jets -------------------------------

#from PhysicsTools.PatAlgos.tools.jetTools import *
## uncomment the following lines to add ak5PFJets to your PAT output
#switchJetCollection(
#  process,
#  jetSource = cms.InputTag('ak5PFJets'),
#  jetCorrections = ('AK5PF', cms.vstring(['L1FastJet', 'L2Relative', 'L3Absolute']), 'Type-2'),
#  btagDiscriminators = [
#  'combinedSecondaryVertexBJetTags',
#  #   'combinedSecondaryVertexMVABJetTags',
  #   'jetBProbabilityBJetTags',
  #   'jetProbabilityBJetTags',
  #   'simpleSecondaryVertexHighEffBJetTags',
  #   'simpleSecondaryVertexHighPurBJetTags',
#  ],
#  )
#process.selectedPatJets.cut = cms.string("pt > 0 && abs(eta) < 5")



# --------------------Modifications for MET--------------------
#process.load("JetMETCorrections.Type1MET.pfMETCorrections_cff")
#process.load("JetMETCorrections.Type1MET.pfMETCorrectionType0_cfi")
#process.pfType1CorrectedMet.applyType0Corrections = cms.bool(False)
#process.pfType1CorrectedMet.srcType1Corrections = cms.VInputTag(
#    cms.InputTag('pfMETcorrType0'),
#    cms.InputTag('pfJetMETcorr', 'type1')        
#    )


# Let it run
process.p = cms.Path(
 # process.type0PFMEtCorrection +
  #     process.ak5PFJets +
 # process.producePFMETCorrections + 
  process.tauGenJets *
  process.PFTau * 
  #  process.recoTauClassicHPSSequence +
 # process.patDefaultSequence + 
 # process.kt6PFJetsForIsolation +
#  process.kt6PFJetsForIsolation * 
  process.demo
  )
