import FWCore.ParameterSet.Config as cms
import copy
process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.autoCond import autoCond
process.GlobalTag.globaltag = cms.string( autoCond[ 'startup'])
process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')
process.load("PhysicsTools.JetMCAlgos.TauGenJets_cfi")
process.load("RecoTauTag.Configuration.RecoPFTauTag_cff")
process.load('CommonTools/RecoAlgos/HBHENoiseFilter_cfi')

process.MessageLogger.cerr.FwkReport.reportEvery = 10

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
#         'file:/uscmst1b_scratch/lpc1/3DayLifetime/aman30/skimPat_171_1_qpP.root'
#         'file:/uscms_data/d3/aman30/TauPOG/Try/CMSSW_6_2_0/src/HighMassAnalysis/Configuration/test/Data_TauTauSkim/skimPat.root'
#          'root://xrootd.unl.edu//store/user/nitish/VBF_HToTauTau_M-125_14TeV-powheg-pythia6/VBF_HToTauTau_M-125_Summer12-PU35_POSTLS161_07082013_skimPAT/a10cf3eab9b6a641842e6222dac97fdd/skimPat_127_1_1dB.root'
#           'file:/uscmst1b_scratch/lpc1/3DayLifetime/aman30/612_vbfHiggs_PU35.root'
#           'file:/uscmst1b_scratch/lpc1/3DayLifetime/aman30/skimPat_31_1_yQt.root'
#            'file:/uscms_data/d3/aman30/TauPOG/Try/CMSSW_6_2_0/src/HighMassAnalysis/Configuration/test/Data_TauTauSkim/skimPat.root'
            'file:/uscms_data/d3/aman30/TauPOG/tauPog/CMSSW_5_3_12/src/HighMassAnalysis/Configuration/test/Data_TauTauSkim/skimPat.root' 
   )
)

#process.options = cms.untracked.PSet(
#   SkipEvent = cms.untracked.vstring('ProductNotFound'),
#   wantSummary = cms.untracked.bool(True) 
#)
process.TFileService = cms.Service("TFileService",
    fileName = cms.string("analysis.root")
)

process.demo = cms.EDAnalyzer('TreeMaker')
process.demo.MatchLeptonToGen = cms.bool(False)                                 # if true, match reco lepton to a gen lepton
process.demo.UseLeptonMotherId = cms.bool(False)           # if true, require the matched lepton to come from a certain
                                                                                        # 'mother' particle
process.demo.UseLeptonGrandMotherId = cms.bool(False)      # if true, require the matched lepton to come from a certain
                                                                                        # 'grandmother' particle
process.demo.LeptonMotherId = cms.int32(24)     # pdgId of the 'mother' particle
process.demo.LeptonGrandMotherId = cms.int32(32)          # pdgId of the 'grandmother' particle
process.demo.MatchTauToGen = cms.bool(True)                         # if true, match reco tau to a gen had tau
process.demo.UseTauMotherId = cms.bool(True)                       # if true, require the matched tau to come from a certain
                                                              # 'mother' particle ('mother' here is NOT 15!!!!! Matching
                                 # for the had tau leg already requires the vis had tau to come from a tau lepton)
process.demo.UseTauGrandMotherId = cms.bool(False)      # if true, require the matched tau to come from a certain
process.demo.TauMotherId = cms.int32(25)                           # pdgId of the 'mother' particle
process.demo.TauGrandMotherId = cms.int32(1)                          # pdgId of the 'grandmother' particle
process.demo.TauToGenMatchingDeltaR = cms.double(0.25)         # matching dR:  dR(vis gen tau,reco tau)<X
process.demo.TaumatchToGenJet = cms.bool(False)
process.demo.TaumatchToMuon = cms.bool(False)
process.demo.TaumatchToElectron = cms.bool(False)
process.demo.TaumatchToGenTau = cms.bool(True)


process.p = cms.Path(process.demo)
