import FWCore.ParameterSet.Config as cms

from HighMassAnalysis.Skimming.tauSelector_cfi import *

selectedTausInclusive = cms.EDFilter("CandViewCountFilter",
  src = cms.InputTag('selectedLooseHPSPatTau'),
  minNumber = cms.uint32(1)                      
)

TauSkimSequence = cms.Sequence(
    selectedLooseHPSPatTau
  * selectedTausInclusive
)
