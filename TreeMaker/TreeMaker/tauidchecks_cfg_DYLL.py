import FWCore.ParameterSet.Config as cms
import copy
process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.autoCond import autoCond
process.GlobalTag.globaltag = cms.string( autoCond[ 'startup'])
process.load('JetMETCorrections.Configuration.JetCorrectionServices_cff')
process.load('CommonTools/RecoAlgos/HBHENoiseFilter_cfi')

process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.options.SkipEvent = cms.untracked.vstring('ProductNotFound')
process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
           'file:/uscms_data/d3/aman30/TauPOG/2014/CMSSW_6_2_5/src/HighMassAnalysis/Configuration/test/Data_TauTauSkim/skimPat_14_2_cz9.root'
    )
)

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
process.demo.TauMotherId = cms.int32(23)                           # pdgId of the 'mother' particle
process.demo.TauGrandMotherId = cms.int32(1)                          # pdgId of the 'grandmother' particle
process.demo.TauToGenMatchingDeltaR = cms.double(0.3)         # matching dR:  dR(vis gen tau,reco tau)<X
process.demo.TaumatchToGenJet = cms.bool(False)
process.demo.TaumatchToMuon = cms.bool(False)
process.demo.TaumatchToElectron = cms.bool(False)
process.demo.TaumatchToGenTau = cms.bool(True)


process.p = cms.Path(process.demo)
