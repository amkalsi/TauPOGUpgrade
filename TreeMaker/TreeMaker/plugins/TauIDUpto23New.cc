
#include "./TauIDUpto23New.h"                                                                                                                                        


TauIDUpto23New::TauIDUpto23New(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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
  
  
  hFillTauHcal3x3OverPLead  = fs->make<TH1F>(("hFillTauHcal3x3OverPLead"+prefix).c_str() ,"hFillTauHcal3x3OverPLead",1000,0,50);
  FillHOverP  = fs->make<TH1F>(("FillHOverP"+prefix).c_str() ,"FillHOverP",1000,0,50);
  FillEOverP  = fs->make<TH1F>(("FillEOverP"+prefix).c_str() ,"FillEOverP",1000,0,30); 
  FillGammaFraction = fs->make<TH1F>(("FillGammaFraction"+prefix).c_str() ,"FillGammaFraction",1000,0,5);
  
  hFillTauHcal3x3OverPLead_before  = fs->make<TH1F>(("hFillTauHcal3x3OverPLead_before"+prefix).c_str() ,"hFillTauHcal3x3OverPLead_befor",1000,0,50);
  FillHOverP_before  = fs->make<TH1F>(("FillHOverP_before"+prefix).c_str() ,"FillHOverP_before",1000,0,50);
  FillEOverP_before  = fs->make<TH1F>(("FillEOverP_before"+prefix).c_str() ,"FillEOverP_brfore",1000,0,30); 
  FillGammaFraction_before = fs->make<TH1F>(("FillGammaFraction_before"+prefix).c_str() ,"FillGammaFraction_before",1000,0,5);
  
  hFillTauHcal3x3OverPLead_DMF  = fs->make<TH1F>(("hFillTauHcal3x3OverPLead_DMF"+prefix).c_str() ,"hFillTauHcal3x3OverPLead_DMF",1000,0,50);
  FillHOverP_DMF  = fs->make<TH1F>(("FillHOverP_DMF"+prefix).c_str() ,"FillHOverP_DMF",1000,0,50);
  FillEOverP_DMF  = fs->make<TH1F>(("FillEOverP_DMF"+prefix).c_str() ,"FillEOverP_DMF",1000,0,30); 
  FillGammaFraction_DMF = fs->make<TH1F>(("FillGammaFraction_DMF"+prefix).c_str() ,"FillGammaFraction_DMF",1000,0,5);
  
  
  GenTauPt_Den  = fs->make<TH1F>(("GenTauPt_Den"+prefix).c_str() ,"GenTauPt_Den" ,500,0,2000);
  GenTauEta_Den  = fs->make<TH1F>(("GenTauEta_Den"+prefix).c_str() ,"GenTauEta_Den" ,100,-5,5);
  GenTauPhi_Den   = fs->make<TH1F>(("GenTauPhi_Den"+prefix).c_str() ,"GenTauPhi_Den" ,100,-5,5);
 
 
  GenTauPtWithDMF = fs->make<TH1F>(("GenTauPtWithDMF"+prefix).c_str() ,"GenTauPtWithDMF",500,0,2000);
  GenTauEtaWithDMF = fs->make<TH1F>(("GenTauEtaWithDMF"+prefix).c_str() ,"GenTauEtaWithDMF",100,-5,5);
  GenTauPhiWithDMF = fs->make<TH1F>(("GenTauPhiWithDMF"+prefix).c_str() ,"GenTauPhiWithDMF",100,-5,5);

  GenTauPiZeroCandidatesDMF = fs->make<TH1F>(("GenTauPiZeroCandidatesDMF"+prefix).c_str() ,"GenTauPiZeroCandidatesDMF",15,0,15); 
  GenTauHadronCandidatesDMF  = fs->make<TH1F>(("GenTauHadronCandidatesDMF"+prefix).c_str() ,"GenTauHadronCandidatesDMF",15,0,15);
  
  hFillDecayMode  = fs->make<TH1F>(("hFillDecayMode"+prefix).c_str() ,"hFillDecayMode",15,0,15);
  

 hNeutralIsoPtSumWeight1_dmf = fs->make<TH1F>(("hNeutralIsoPtSumWeight1_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_dmf",800,0,400);
 hNeutralIsoPtSumWeight2_dmf = fs->make<TH1F>(("hNeutralIsoPtSumWeight2_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_dmf",800,0,400);
 hNeutralIsoPtSumWeight1NQ_dmf = fs->make<TH1F>(("hNeutralIsoPtSumWeight1NQ_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_dmf",800,0,400);
 hNeutralIsoPtSumWeight2NQ_dmf = fs->make<TH1F>(("hNeutralIsoPtSumWeight2NQ_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_dmf",800,0,400);
 hNeutralHadronIsoPtSum_dmf  = fs->make<TH1F>(("hNeutralHadronIsoPtSum_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_dmf",800,0,400);
 hNeutralHadronIsoPtSumWeight1_dmf = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight1_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_dmf",800,0,400);
 hNeutralHadronIsoPtSumWeight2_dmf = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight2_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_dmf",800,0,400);
 hNeutralHadronIsoPtSumWeight1NQ_dmf = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight1NQ_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_dmf",800,0,400);
 hNeutralHadronIsoPtSumWeight2NQ_dmf = fs->make<TH1F>(("hNeutralHadronIsoPtSumWeight2NQ_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_dmf",800,0,400);
 hChargedIsoPtSum_dmf  = fs->make<TH1F>(("hChargedIsoPtSum_dmf"+prefix).c_str(),"hChargedIsoPtSum_dmf",800,0,400); 
 hNeutralIsoPtSum_dmf = fs->make<TH1F>(("hNeutralIsoPtSum_dmf"+prefix).c_str(),"hNeutralIsoPtSum_dmf",800,0,400);
 hPUcorrPtSum_dmf = fs->make<TH1F>(("hPUcorrPtSum_dmf"+prefix).c_str(),"hPUcorrPtSum_dmf",800,0,400);

  hNeutralIsoPtSumWeight1_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_pt_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_pt_dmf",400,0,700,0,400); 
  hNeutralIsoPtSumWeight2_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_pt_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_pt_dmf",400,0,700,0,400); 
  hNeutralIsoPtSumWeight1NQ_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_pt_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_pt_dmf",400,0,700,0,400); 
  hNeutralIsoPtSumWeight2NQ_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_pt_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_pt_dmf",400,0,700,0,400); 
  hNeutralHadronIsoPtSum_pt_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_pt_dmf",400,0,700,0,400);
  hNeutralHadronIsoPtSumWeight1_pt_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_pt_dmf",400,0,700,0,400);
  hNeutralHadronIsoPtSumWeight2_pt_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_pt_dmf",400,0,700,0,400);
  hNeutralHadronIsoPtSumWeight1NQ_pt_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_pt_dmf",400,0,700,0,400);
  hNeutralHadronIsoPtSumWeight2NQ_pt_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_pt_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_pt_dmf",400,0,700,0,400);
  hChargedIsoPtSum_pt_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_pt_dmf"+prefix).c_str(),"hChargedIsoPtSum_pt_dmf",400,0,700,0,400); 
  hNeutralIsoPtSum_pt_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_pt_dmf"+prefix).c_str(),"hNeutralIsoPtSum_pt_dmf",400,0,700,0,400);
  hPUcorrPtSum_pt_dmf = fs->make<TProfile>(("hPUcorrPtSum_pt_dmf"+prefix).c_str(),"hPUcorrPtSum_pt_dmf",400,0,700,0,400);

  hNeutralIsoPtSumWeight1_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_eta_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_eta_dmf",200,-5,5,0,400); 
  hNeutralIsoPtSumWeight2_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_eta_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_eta_dmf",200,-5,5,0,400); 
  hNeutralIsoPtSumWeight1NQ_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_eta_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_eta_dmf",200,-5,5,0,400); 
  hNeutralIsoPtSumWeight2NQ_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_eta_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_eta_dmf",200,-5,5,0,400); 
  hNeutralHadronIsoPtSum_eta_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_eta_dmf",200,-5,5,0,400);
  hNeutralHadronIsoPtSumWeight1_eta_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_eta_dmf",200,-5,5,0,400);
  hNeutralHadronIsoPtSumWeight2_eta_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_eta_dmf",200,-5,5,0,400);
  hNeutralHadronIsoPtSumWeight1NQ_eta_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_eta_dmf",200,-5,5,0,400);
  hNeutralHadronIsoPtSumWeight2NQ_eta_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_eta_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_eta_dmf",200,-5,5,0,400);
  hChargedIsoPtSum_eta_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_eta_dmf"+prefix).c_str(),"hChargedIsoPtSum_eta_dmf",200,-5,5,0,400); 
  hNeutralIsoPtSum_eta_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_eta_dmf"+prefix).c_str(),"hNeutralIsoPtSum_eta_dmf",200,-5,5,0,400);
  hPUcorrPtSum_eta_dmf = fs->make<TProfile>(("hPUcorrPtSum_eta_dmf"+prefix).c_str(),"hPUcorrPtSum_eta_dmf",200,-5,5,0,400);

 hNeutralIsoPtSumWeight1_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_phi_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_phi_dmf",200,-5,5,0,400); 
  hNeutralIsoPtSumWeight2_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_phi_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_phi_dmf",200,-5,5,0,400); 
  hNeutralIsoPtSumWeight1NQ_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_phi_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_phi_dmf",200,-5,5,0,400); 
  hNeutralIsoPtSumWeight2NQ_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_phi_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_phi_dmf",200,-5,5,0,400); 
  hNeutralHadronIsoPtSum_phi_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_phi_dmf",200,-5,5,0,400);
  hNeutralHadronIsoPtSumWeight1_phi_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_phi_dmf",200,-5,5,0,400);
  hNeutralHadronIsoPtSumWeight2_phi_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_phi_dmf",200,-5,5,0,400);
  hNeutralHadronIsoPtSumWeight1NQ_phi_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_phi_dmf",200,-5,5,0,400);
  hNeutralHadronIsoPtSumWeight2NQ_phi_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_phi_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_phi_dmf",200,-5,5,0,400);
  hChargedIsoPtSum_phi_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_phi_dmf"+prefix).c_str(),"hChargedIsoPtSum_phi_dmf",200,-5,5,0,400); 
  hNeutralIsoPtSum_phi_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_phi_dmf"+prefix).c_str(),"hNeutralIsoPtSum_phi_dmf",200,-5,5,0,400);
  hPUcorrPtSum_phi_dmf = fs->make<TProfile>(("hPUcorrPtSum_phi_dmf"+prefix).c_str(),"hPUcorrPtSum_phi_dmf",200,-5,5,0,400);


  hNeutralIsoPtSumWeight1_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_vtx_dmf",200,0,200,0,400); 
  hNeutralIsoPtSumWeight2_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_vtx_dmf",200,0,200,0,400); 
  hNeutralIsoPtSumWeight1NQ_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_vtx_dmf",200,0,200,0,400); 
  hNeutralIsoPtSumWeight2NQ_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_vtx_dmf",200,0,200,0,400); 
  hNeutralHadronIsoPtSum_vtx_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_vtx_dmf",200,0,200,0,400);
  hNeutralHadronIsoPtSumWeight1_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_vtx_dmf",200,0,200,0,400);
  hNeutralHadronIsoPtSumWeight2_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_vtx_dmf",200,0,200,0,400);
  hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf",200,0,200,0,400);
  hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf",200,0,200,0,400);
  hChargedIsoPtSum_vtx_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_vtx_dmf"+prefix).c_str(),"hChargedIsoPtSum_vtx_dmf",200,0,200,0,400); 
  hNeutralIsoPtSum_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_vtx_dmf"+prefix).c_str(),"hNeutralIsoPtSum_vtx_dmf",200,0,200,0,400);
  hPUcorrPtSum_vtx_dmf = fs->make<TProfile>(("hPUcorrPtSum_vtx_dmf"+prefix).c_str(),"hPUcorrPtSum_vtx_dmf",200,0,200,0,400);

hNeutralIsoPtSumWeight1_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_nGoodVtx_dmf",200,0,200,0,400); 
  hNeutralIsoPtSumWeight2_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_nGoodVtx_dmf",200,0,200,0,400); 
  hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf",200,0,200,0,400); 
  hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf",200,0,200,0,400); 
  hNeutralHadronIsoPtSum_nGoodVtx_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_nGoodVtx_dmf",200,0,200,0,400);
  hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf",200,0,200,0,400);
  hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf",200,0,200,0,400);
  hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf",200,0,200,0,400);
  hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf",200,0,200,0,400);
  hChargedIsoPtSum_nGoodVtx_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_nGoodVtx_dmf"+prefix).c_str(),"hChargedIsoPtSum_nGoodVtx_dmf",200,0,200,0,400); 
  hNeutralIsoPtSum_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_nGoodVtx_dmf"+prefix).c_str(),"hNeutralIsoPtSum_nGoodVtx_dmf",200,0,200,0,400);
  hPUcorrPtSum_nGoodVtx_dmf = fs->make<TProfile>(("hPUcorrPtSum_nGoodVtx_dmf"+prefix).c_str(),"hPUcorrPtSum_nGoodVtx_dmf",200,0,200,0,400);


  Nvtx_Den = fs->make<TH1F>(("Nvtx_Den"+prefix).c_str() ,"Nvtx_Den",200,0,200);
  NGood_Den = fs->make<TH1F>(("NGood_Den"+prefix).c_str() ,"NGood_Den",200,0,200);
  
  TES_DM = fs->make<TProfile>(("TES_DM"+prefix).c_str(),"TES_DM",500,0,2000,0,50);
  Nvtx_DM = fs->make<TH1F>(("Nvtx_DM"+prefix).c_str() ,"Nvtx_DM",200,0,200);
  NGood_DM = fs->make<TH1F>(("NGood_DM"+prefix).c_str() ,"NGood_DM",200,0,200);

  TES_ML2 = fs->make<TProfile>(("TES_ML2"+prefix).c_str(),"TES_ML2",500,0,2000,0,50);
  Nvtx_ML2 = fs->make<TH1F>(("Nvtx_ML2"+prefix).c_str() ,"Nvtx_ML2",200,0,200);
  NGood_ML2 = fs->make<TH1F>(("NGood_ML2"+prefix).c_str() ,"NGood_ML2",200,0,200);

  TES_MM2 = fs->make<TProfile>(("TES_MM2"+prefix).c_str(),"TES_MM2",500,0,2000,0,50);
  Nvtx_MM2 = fs->make<TH1F>(("Nvtx_MM2"+prefix).c_str() ,"Nvtx_MM2",200,0,200);
  NGood_MM2 = fs->make<TH1F>(("NGood_MM2"+prefix).c_str() ,"NGood_MM2",200,0,200);

  TES_MT2 = fs->make<TProfile>(("TES_MT2"+prefix).c_str(),"TES_MT2",500,0,2000,0,50);
  Nvtx_MT2 = fs->make<TH1F>(("Nvtx_MT2"+prefix).c_str() ,"Nvtx_MT2",200,0,200);
  NGood_MT2 = fs->make<TH1F>(("NGood_MT2"+prefix).c_str() ,"NGood_MT2",200,0,200);

  TES_ML3 = fs->make<TProfile>(("TES_ML3"+prefix).c_str(),"TES_ML3",500,0,2000,0,50);
  Nvtx_ML3 = fs->make<TH1F>(("Nvtx_ML3"+prefix).c_str() ,"Nvtx_ML3",200,0,200);
  NGood_ML3 = fs->make<TH1F>(("NGood_ML3"+prefix).c_str() ,"NGood_ML3",200,0,200);

  TES_MT3 = fs->make<TProfile>(("TES_MT3"+prefix).c_str(),"TES_MT3",500,0,2000,0,50);
  Nvtx_MT3 = fs->make<TH1F>(("Nvtx_MT3"+prefix).c_str() ,"Nvtx_MT3",200,0,200);
  NGood_MT3 = fs->make<TH1F>(("NGood_MT3"+prefix).c_str() ,"NGood_MT3",200,0,200);


  TES_Iso1 = fs->make<TProfile>(("TES_Iso1"+prefix).c_str(),"TES_Iso1",500,0,2000,0,50);
  Nvtx_Iso1 = fs->make<TH1F>(("Nvtx_Iso1"+prefix).c_str() ,"Nvtx_Iso1",200,0,200);
  NGood_Iso1 = fs->make<TH1F>(("NGood_Iso1"+prefix).c_str() ,"NGood_Iso1",200,0,200);

  TES_Iso2 = fs->make<TProfile>(("TES_Iso2"+prefix).c_str(),"TES_Iso2",500,0,2000,0,50);
  Nvtx_Iso2 = fs->make<TH1F>(("Nvtx_Iso2"+prefix).c_str() ,"Nvtx_Iso2",200,0,200);
  NGood_Iso2 = fs->make<TH1F>(("NGood_Iso2"+prefix).c_str() ,"NGood_Iso2",200,0,200);

  TES_Iso4 = fs->make<TProfile>(("TES_Iso4"+prefix).c_str(),"TES_Iso4",500,0,2000,0,50);
  Nvtx_Iso4 = fs->make<TH1F>(("Nvtx_Iso4"+prefix).c_str() ,"Nvtx_Iso4",200,0,200);
  NGood_Iso4 = fs->make<TH1F>(("NGood_Iso4"+prefix).c_str() ,"NGood_Iso4",200,0,200);

  TES_Cut = fs->make<TProfile>(("TES_Cut"+prefix).c_str(),"TES_Cut",500,0,2000,0,50);
  Nvtx_Cut = fs->make<TH1F>(("Nvtx_Cut"+prefix).c_str() ,"Nvtx_Cut",200,0,200);
  NGood_Cut = fs->make<TH1F>(("NGood_Cut"+prefix).c_str() ,"NGood_Cut",200,0,200);
  //seee
  TES_EL3 = fs->make<TProfile>(("TES_EL3"+prefix).c_str(),"TES_EL3",500,0,2000,0,50);
  Nvtx_EL3 = fs->make<TH1F>(("Nvtx_EL3"+prefix).c_str() ,"Nvtx_EL3",200,0,200);
  NGood_EL3 = fs->make<TH1F>(("NGood_EL3"+prefix).c_str() ,"NGood_EL3",200,0,200);

  TES_EM3 = fs->make<TProfile>(("TES_EM3"+prefix).c_str(),"TES_EM3",500,0,2000,0,50);
  Nvtx_EM3 = fs->make<TH1F>(("Nvtx_EM3"+prefix).c_str() ,"Nvtx_EM3",200,0,200);
  NGood_EM3 = fs->make<TH1F>(("NGood_EM3"+prefix).c_str() ,"NGood_EM3",200,0,200);

  TES_ET3 = fs->make<TProfile>(("TES_ET3"+prefix).c_str(),"TES_ET3",500,0,2000,0,50);
  Nvtx_ET3 = fs->make<TH1F>(("Nvtx_ET3"+prefix).c_str() ,"Nvtx_ET3",200,0,200);
  NGood_ET3 = fs->make<TH1F>(("NGood_ET3"+prefix).c_str() ,"NGood_ET3",200,0,200);


  TES_VLChar = fs->make<TProfile>(("TES_VLChar"+prefix).c_str(),"TES_VLChar",500,0,2000,0,50);
  Nvtx_VLChar = fs->make<TH1F>(("Nvtx_VLChar"+prefix).c_str() ,"Nvtx_VLChar",200,0,200);
  NGood_VLChar = fs->make<TH1F>(("NGood_VLChar"+prefix).c_str() ,"NGood_VLChar",200,0,200);

  TES_LChar = fs->make<TProfile>(("TES_LChar"+prefix).c_str(),"TES_LChar",500,0,2000,0,50);
  Nvtx_LChar = fs->make<TH1F>(("Nvtx_LChar"+prefix).c_str() ,"Nvtx_LChar",200,0,200);
  NGood_LChar = fs->make<TH1F>(("NGood_LChar"+prefix).c_str() ,"NGood_LChar",200,0,200);

  TES_MChar = fs->make<TProfile>(("TES_MChar"+prefix).c_str(),"TES_MChar",500,0,2000,0,50);
  Nvtx_MChar = fs->make<TH1F>(("Nvtx_MChar"+prefix).c_str() ,"Nvtx_MChar",200,0,200);
  NGood_MChar = fs->make<TH1F>(("NGood_MChar"+prefix).c_str() ,"NGood_MChar",200,0,200);

  TES_TChar = fs->make<TProfile>(("TES_TChar"+prefix).c_str(),"TES_TChar",500,0,2000,0,50);
  Nvtx_TChar = fs->make<TH1F>(("Nvtx_TChar"+prefix).c_str() ,"Nvtx_TChar",200,0,200);
  NGood_TChar = fs->make<TH1F>(("NGood_TChar"+prefix).c_str() ,"NGood_TChar",200,0,200);

  TES_LIso = fs->make<TProfile>(("TES_LIso"+prefix).c_str(),"TES_LIso",500,0,2000,0,50);
  Nvtx_LIso = fs->make<TH1F>(("Nvtx_LIso"+prefix).c_str() ,"Nvtx_LIso",200,0,200);
  NGood_LIso = fs->make<TH1F>(("NGood_LIso"+prefix).c_str() ,"NGood_LIso",200,0,200);


  TES_MIso = fs->make<TProfile>(("TES_MIso"+prefix).c_str(),"TES_MIso",500,0,2000,0,50);
  Nvtx_MIso = fs->make<TH1F>(("Nvtx_MIso"+prefix).c_str() ,"Nvtx_MIso",200,0,200);
  NGood_MIso = fs->make<TH1F>(("NGood_MIso"+prefix).c_str() ,"NGood_MIso",200,0,200);

  TES_TIso = fs->make<TProfile>(("TES_TIso"+prefix).c_str(),"TES_TIso",500,0,2000,0,50);
  Nvtx_TIso = fs->make<TH1F>(("Nvtx_TIso"+prefix).c_str() ,"Nvtx_TIso",200,0,200);
  NGood_TIso = fs->make<TH1F>(("NGood_TIso"+prefix).c_str() ,"NGood_TIso",200,0,200);


  TES_LIso3Hits = fs->make<TProfile>(("TES_LIso3Hits"+prefix).c_str(),"TES_LIso3Hits",500,0,2000,0,50);
  Nvtx_LIso3Hits = fs->make<TH1F>(("Nvtx_LIso3Hits"+prefix).c_str() ,"Nvtx_LIso3Hits",200,0,200);
  NGood_LIso3Hits = fs->make<TH1F>(("NGood_LIso3Hits"+prefix).c_str() ,"NGood_LIso3Hits",200,0,200);


  TES_MIso3Hits = fs->make<TProfile>(("TES_MIso3Hits"+prefix).c_str(),"TES_MIso3Hits",500,0,2000,0,50);
  Nvtx_MIso3Hits = fs->make<TH1F>(("Nvtx_MIso3Hits"+prefix).c_str() ,"Nvtx_MIso3Hits",200,0,200);
  NGood_MIso3Hits = fs->make<TH1F>(("NGood_MIso3Hits"+prefix).c_str() ,"NGood_MIso3Hits",200,0,200);

  TES_TIso3Hits = fs->make<TProfile>(("TES_TIso3Hits"+prefix).c_str(),"TES_TIso3Hits",500,0,2000,0,50);
  Nvtx_TIso3Hits = fs->make<TH1F>(("Nvtx_TIso3Hits"+prefix).c_str() ,"Nvtx_TIso3Hits",200,0,200);
  NGood_TIso3Hits = fs->make<TH1F>(("NGood_TIso3Hits"+prefix).c_str() ,"NGood_TIso3Hits",200,0,200);


  TES_LooseRho = fs->make<TProfile>(("TES_LooseRho"+prefix).c_str(),"TES_LooseRho",500,0,2000,0,50);
  Nvtx_LooseRho = fs->make<TH1F>(("Nvtx_LooseRho"+prefix).c_str() ,"Nvtx_LooseRho",200,0,200);
  NGood_LooseRho = fs->make<TH1F>(("NGood_LooseRho"+prefix).c_str() ,"NGood_LooseRho",200,0,200);

  TES_MediumRho = fs->make<TProfile>(("TES_MediumRho"+prefix).c_str(),"TES_MediumRho",500,0,2000,0,50);
  Nvtx_MediumRho = fs->make<TH1F>(("Nvtx_MediumRho"+prefix).c_str() ,"Nvtx_MediumRho",200,0,200);
  NGood_MediumRho = fs->make<TH1F>(("NGood_MediumRho"+prefix).c_str() ,"NGood_MediumRho",200,0,200);

  
  TES_TightRho = fs->make<TProfile>(("TES_TightRho"+prefix).c_str(),"TES_TightRho",500,0,2000,0,50);
  Nvtx_TightRho = fs->make<TH1F>(("Nvtx_TightRho"+prefix).c_str() ,"Nvtx_TightRho",200,0,200);
  NGood_TightRho = fs->make<TH1F>(("NGood_TightRho"+prefix).c_str() ,"NGood_TightRho",200,0,200);

  TES_Combined = fs->make<TProfile>(("TES_Combined"+prefix).c_str(),"TES_Combined",500,0,2000,0,50);
  Nvtx_Combined = fs->make<TH1F>(("Nvtx_Combined"+prefix).c_str() ,"Nvtx_Combined",200,0,200);
  NGood_Combined = fs->make<TH1F>(("NGood_Combined"+prefix).c_str() ,"NGood_Combined",200,0,200);

  RecoTauDecayMode_Combined = fs->make<TH1F>(("RecoTauDecayMode_Combined"+prefix).c_str() ,"RecoTauDecayMode_Combined",15,0,15);
  GenTauDecayMode_Combined  = fs->make<TH1F>(("GenTauDecayMode_Combined"+prefix).c_str() ,"GenTauDecayMode_Combined",15,0,15);
  reco_dm_vs_gen_Combined  = fs->make<TH2F>(("reco_dm_vs_gen_Combined"+prefix).c_str() ,"reco_dm_vs_gen_Combined",15,0,15,15,0,15);
  GenTauPtWithDMF_Combined = fs->make<TH1F>(("GenTauPtWithDMF_Combined"+prefix).c_str() ,"GenTauPtWithDMF_Combined",500,0,2000);
  GenTauEtaWithDMF_Combined = fs->make<TH1F>(("GenTauEtaWithDMF_Combined"+prefix).c_str() ,"GenTauEtaWithDMF_Combined",100,-5,5);
  GenTauPhiWithDMF_Combined = fs->make<TH1F>(("GenTauPhiWithDMF_Combined"+prefix).c_str() ,"GenTauPhiWithDMF_Combined",100,-5,5);
 
 //

  TES_MIsoPtSum = fs->make<TProfile>(("TES_MIsoPtSum"+prefix).c_str(),"TES_MIsoPtSum",500,0,2000,0,50);
  Nvtx_MIsoPtSum = fs->make<TH1F>(("Nvtx_MIsoPtSum"+prefix).c_str() ,"Nvtx_MIsoPtSum",200,0,200);
  NGood_MIsoPtSum = fs->make<TH1F>(("NGood_MIsoPtSum"+prefix).c_str() ,"NGood_MIsoPtSum",200,0,200);

  RecoTauDecayMode_MIsoPtSum = fs->make<TH1F>(("RecoTauDecayMode_MIsoPtSum"+prefix).c_str() ,"RecoTauDecayMode_MIsoPtSum",15,0,15);
  GenTauDecayMode_MIsoPtSum  = fs->make<TH1F>(("GenTauDecayMode_MIsoPtSum"+prefix).c_str() ,"GenTauDecayMode_MIsoPtSum",15,0,15);
  reco_dm_vs_gen_MIsoPtSum  = fs->make<TH2F>(("reco_dm_vs_gen_MIsoPtSum"+prefix).c_str() ,"reco_dm_vs_gen_MIsoPtSum",15,0,15,15,0,15);
  GenTauPtWithDMF_MIsoPtSum = fs->make<TH1F>(("GenTauPtWithDMF_MIsoPtSum"+prefix).c_str() ,"GenTauPtWithDMF_MIsoPtSum",500,0,2000);
  GenTauEtaWithDMF_MIsoPtSum = fs->make<TH1F>(("GenTauEtaWithDMF_MIsoPtSum"+prefix).c_str() ,"GenTauEtaWithDMF_MIsoPtSum",100,-5,5);
  GenTauPhiWithDMF_MIsoPtSum = fs->make<TH1F>(("GenTauPhiWithDMF_MIsoPtSum"+prefix).c_str() ,"GenTauPhiWithDMF_MIsoPtSum",100,-5,5);
  TauPtResponse_MIsoPtSum  = fs->make<TH1F>(("TauPtResponse_MIsoPtSum"+prefix).c_str() ,"TauPtResponse_MIsoPtSum",100,0.1,2.0);         

TauPtResponse_Combined  = fs->make<TH1F>(("TauPtResponse_Combined"+prefix).c_str() ,"TauPtResponse_Combined",100,0.1,2.0);

  TES_TIsoPtSum = fs->make<TProfile>(("TES_TIsoPtSum"+prefix).c_str(),"TES_TIsoPtSum",500,0,2000,0,50);
  Nvtx_TIsoPtSum = fs->make<TH1F>(("Nvtx_TIsoPtSum"+prefix).c_str() ,"Nvtx_TIsoPtSum",200,0,200);
  NGood_TIsoPtSum = fs->make<TH1F>(("NGood_TIsoPtSum"+prefix).c_str() ,"NGood_TIsoPtSum",200,0,200);

  RecoTauDecayMode_TIsoPtSum = fs->make<TH1F>(("RecoTauDecayMode_TIsoPtSum"+prefix).c_str() ,"RecoTauDecayMode_TIsoPtSum",15,0,15);
  GenTauDecayMode_TIsoPtSum  = fs->make<TH1F>(("GenTauDecayMode_TIsoPtSum"+prefix).c_str() ,"GenTauDecayMode_TIsoPtSum",15,0,15);
  reco_dm_vs_gen_TIsoPtSum  = fs->make<TH2F>(("reco_dm_vs_gen_TIsoPtSum"+prefix).c_str() ,"reco_dm_vs_gen_TIsoPtSum",15,0,15,15,0,15);
  GenTauPtWithDMF_TIsoPtSum = fs->make<TH1F>(("GenTauPtWithDMF_TIsoPtSum"+prefix).c_str() ,"GenTauPtWithDMF_TIsoPtSum",500,0,2000);
  GenTauEtaWithDMF_TIsoPtSum = fs->make<TH1F>(("GenTauEtaWithDMF_TIsoPtSum"+prefix).c_str() ,"GenTauEtaWithDMF_TIsoPtSum",100,-5,5);
  GenTauPhiWithDMF_TIsoPtSum = fs->make<TH1F>(("GenTauPhiWithDMF_TIsoPtSum"+prefix).c_str() ,"GenTauPhiWithDMF_TIsoPtSum",100,-5,5);
  TauPtResponse_TIsoPtSum  = fs->make<TH1F>(("TauPtResponse_TIsoPtSum"+prefix).c_str() ,"TauPtResponse_TIsoPtSum",100,0.1,2.0);         


  TES_LIsoPtSum = fs->make<TProfile>(("TES_LIsoPtSum"+prefix).c_str(),"TES_LIsoPtSum",500,0,2000,0,50);
  Nvtx_LIsoPtSum = fs->make<TH1F>(("Nvtx_LIsoPtSum"+prefix).c_str() ,"Nvtx_LIsoPtSum",200,0,200);
  NGood_LIsoPtSum = fs->make<TH1F>(("NGood_LIsoPtSum"+prefix).c_str() ,"NGood_LIsoPtSum",200,0,200);

  RecoTauDecayMode_LIsoPtSum = fs->make<TH1F>(("RecoTauDecayMode_LIsoPtSum"+prefix).c_str() ,"RecoTauDecayMode_LIsoPtSum",15,0,15);
  GenTauDecayMode_LIsoPtSum  = fs->make<TH1F>(("GenTauDecayMode_LIsoPtSum"+prefix).c_str() ,"GenTauDecayMode_LIsoPtSum",15,0,15);
  reco_dm_vs_gen_LIsoPtSum  = fs->make<TH2F>(("reco_dm_vs_gen_LIsoPtSum"+prefix).c_str() ,"reco_dm_vs_gen_LIsoPtSum",15,0,15,15,0,15);
  GenTauPtWithDMF_LIsoPtSum = fs->make<TH1F>(("GenTauPtWithDMF_LIsoPtSum"+prefix).c_str() ,"GenTauPtWithDMF_LIsoPtSum",500,0,2000);
  GenTauEtaWithDMF_LIsoPtSum = fs->make<TH1F>(("GenTauEtaWithDMF_LIsoPtSum"+prefix).c_str() ,"GenTauEtaWithDMF_LIsoPtSum",100,-5,5);
  GenTauPhiWithDMF_LIsoPtSum = fs->make<TH1F>(("GenTauPhiWithDMF_LIsoPtSum"+prefix).c_str() ,"GenTauPhiWithDMF_LIsoPtSum",100,-5,5);
  TauPtResponse_LIsoPtSum  = fs->make<TH1F>(("TauPtResponse_LIsoPtSum"+prefix).c_str() ,"TauPtResponse_LIsoPtSum",100,0.1,2.0);         



 RecoTauDecayMode_DenDMF = fs->make<TH1F>(("RecoTauDecayMode_DenDMF"+prefix).c_str() ,"RecoTauDecayMode_DenDMF",15,0,15);
  GenTauDecayMode_DenDMF  = fs->make<TH1F>(("GenTauDecayMode_DenDMF"+prefix).c_str() ,"GenTauDecayMode_DenDMF",15,0,15);
  reco_dm_vs_gen_DenDMF  = fs->make<TH2F>(("reco_dm_vs_gen_DenDMF"+prefix).c_str() ,"reco_dm_vs_gen_DenDMF",15,0,15,15,0,15);
  GenTauPtWithDMF_DenDMF = fs->make<TH1F>(("GenTauPtWithDMF_DenDMF"+prefix).c_str() ,"GenTauPtWithDMF_DenDMF",500,0,2000);
  GenTauEtaWithDMF_DenDMF = fs->make<TH1F>(("GenTauEtaWithDMF_DenDMF"+prefix).c_str() ,"GenTauEtaWithDMF_DenDMF",100,-5,5);
  GenTauPhiWithDMF_DenDMF = fs->make<TH1F>(("GenTauPhiWithDMF_DenDMF"+prefix).c_str() ,"GenTauPhiWithDMF_DenDMF",100,-5,5);
TauPtResponse_DenDMF  = fs->make<TH1F>(("TauPtResponse_DenDMF"+prefix).c_str() ,"TauPtResponse_DenDMF",100,0.1,2.0);         

  //
  RecoTauDecayMode_DM = fs->make<TH1F>(("RecoTauDecayMode_DM"+prefix).c_str() ,"RecoTauDecayMode_DM",15,0,15);
  GenTauDecayMode_DM = fs->make<TH1F>(("GenTauDecayMode_DM"+prefix).c_str() ,"GenTauDecayMode_DM",15,0,15);
  reco_dm_vs_gen_dm = fs->make<TH2F>(("reco_dm_vs_gen_dm"+prefix).c_str() ,"reco_dm_vs_gen_dm",15,0,15,15,0,15);
  GenTauPtWithDMF_Iso1 = fs->make<TH1F>(("GenTauPtWithDMF_Iso1"+prefix).c_str() ,"GenTauPtWithDMF_Iso1" ,500,0,2000);                                         
  GenTauEtaWithDMF_Iso1 = fs->make<TH1F>(("GenTauEtaWithDMF_Iso1"+prefix).c_str() ,"GenTauEtaWithDMF_Iso1" ,100,-5,5);
  GenTauPhiWithDMF_Iso1 = fs->make<TH1F>(("GenTauPhiWithDMF_Iso1"+prefix).c_str() ,"GenTauPhiWithDMF_Iso1" ,100,-5,5);

  GenTauPtWithDMF_Iso2 = fs->make<TH1F>(("GenTauPtWithDMF_Iso2"+prefix).c_str() ,"GenTauPtWithDMF_Iso2" ,500,0,2000);
  GenTauEtaWithDMF_Iso2 = fs->make<TH1F>(("GenTauEtaWithDMF_Iso2"+prefix).c_str() ,"GenTauEtaWithDMF_Iso2" ,100,-5,5);
  GenTauPhiWithDMF_Iso2 = fs->make<TH1F>(("GenTauPhiWithDMF_Iso2"+prefix).c_str() ,"GenTauPhiWithDMF_Iso2" ,100,-5,5);


  GenTauPtWithDMF_Iso4 = fs->make<TH1F>(("GenTauPtWithDMF_Iso4"+prefix).c_str() ,"GenTauPtWithDMF_Iso4" ,500,0,2000);
  GenTauEtaWithDMF_Iso4 = fs->make<TH1F>(("GenTauEtaWithDMF_Iso4"+prefix).c_str() ,"GenTauEtaWithDMF_Iso4" ,100,-5,5);
  GenTauPhiWithDMF_Iso4 = fs->make<TH1F>(("GenTauPhiWithDMF_Iso4"+prefix).c_str() ,"GenTauPhiWithDMF_Iso4" ,100,-5,5);
  TauPtResponse_Iso1 = fs->make<TH1F>(("TauPtResponse_Iso1"+prefix).c_str() ,"TauPtResponse_Iso1",100,0.1,2.0);
  TauPtResponse_Iso2 = fs->make<TH1F>(("TauPtResponse_Iso2"+prefix).c_str() ,"TauPtResponse_Iso2",100,0.1,2.0);
  TauPtResponse_Iso4 = fs->make<TH1F>(("TauPtResponse_Iso4"+prefix).c_str() ,"TauPtResponse_Iso4",100,0.1,2.0);
  
  RecoTauDecayMode_Iso1 = fs->make<TH1F>(("RecoTauDecayMode_Iso1"+prefix).c_str() ,"RecoTauDecayMode_Iso1",15,0,15);
  GenTauDecayMode_Iso1 = fs->make<TH1F>(("GenTauDecayMode_Iso1"+prefix).c_str() ,"GenTauDecayMode_Iso1",15,0,15);
  reco_dm_vs_gen_Iso1 = fs->make<TH2F>(("reco_dm_vs_gen_Iso1"+prefix).c_str() ,"reco_dm_vs_gen_Iso1",15,0,15,15,0,15);
  
  RecoTauDecayMode_Iso2 = fs->make<TH1F>(("RecoTauDecayMode_Iso2"+prefix).c_str() ,"RecoTauDecayMode_Iso2",15,0,15);
  GenTauDecayMode_Iso2 = fs->make<TH1F>(("GenTauDecayMode_Iso2"+prefix).c_str() ,"GenTauDecayMode_Iso2",15,0,15);
  reco_dm_vs_gen_Iso2 = fs->make<TH2F>(("reco_dm_vs_gen_Iso2"+prefix).c_str() ,"reco_dm_vs_gen_Iso2",15,0,15,15,0,15);
  
  RecoTauDecayMode_Iso4 = fs->make<TH1F>(("RecoTauDecayMode_Iso4"+prefix).c_str() ,"RecoTauDecayMode_Iso4",15,0,15);
  GenTauDecayMode_Iso4 = fs->make<TH1F>(("GenTauDecayMode_Iso4"+prefix).c_str() ,"GenTauDecayMode_Iso4",15,0,15);
  reco_dm_vs_gen_Iso4 = fs->make<TH2F>(("reco_dm_vs_gen_Iso4"+prefix).c_str() ,"reco_dm_vs_gen_Iso4",15,0,15,15,0,15);
 
  TauPtResponse_ML2 = fs->make<TH1F>(("TauPtResponse_ML2"+prefix).c_str() ,"TauPtResponse_ML2",100,0.1,2.0);
  
  RecoTauDecayMode_ML2 = fs->make<TH1F>(("RecoTauDecayMode_ML2"+prefix).c_str() ,"RecoTauDecayMode_ML2",15,0,15);
  GenTauDecayMode_ML2 = fs->make<TH1F>(("GenTauDecayMode_ML2"+prefix).c_str() ,"GenTauDecayMode_ML2",15,0,15);
  reco_dm_vs_gen_ML2 = fs->make<TH2F>(("reco_dm_vs_gen_ML2"+prefix).c_str() ,"reco_dm_vs_gen_ML2",15,0,15,15,0,15);
  GenTauPtWithDMF_ML2 = fs->make<TH1F>(("GenTauPtWithDMF_ML2"+prefix).c_str() ,"GenTauPtWithDMF_ML2" ,500,0,2000);
  GenTauEtaWithDMF_ML2 = fs->make<TH1F>(("GenTauEtaWithDMF_ML2"+prefix).c_str() ,"GenTauEtaWithDMF_ML2" ,100,-5,5);
  GenTauPhiWithDMF_ML2 = fs->make<TH1F>(("GenTauPhiWithDMF_ML2"+prefix).c_str() ,"GenTauPhiWithDMF_ML2" ,100,-5,5);



  TauPtResponse_DM = fs->make<TH1F>(("TauPtResponse_DM"+prefix).c_str() ,"TauPtResponse_DM",100,0.1,2.0);
  TauPtResponse_MM2 = fs->make<TH1F>(("TauPtResponse_MM2"+prefix).c_str() ,"TauPtResponse_MM2",100,0.1,2.0);
  RecoTauDecayMode_MM2 = fs->make<TH1F>(("RecoTauDecayMode_MM2"+prefix).c_str() ,"RecoTauDecayMode_MM2",15,0,15);
  GenTauDecayMode_MM2 = fs->make<TH1F>(("GenTauDecayMode_MM2"+prefix).c_str() ,"GenTauDecayMode_MM2",15,0,15);
  reco_dm_vs_gen_MM2 = fs->make<TH2F>(("reco_dm_vs_gen_MM2"+prefix).c_str() ,"reco_dm_vs_gen_MM2",15,0,15,15,0,15);
  GenTauPtWithDMF_MM2 = fs->make<TH1F>(("GenTauPtWithDMF_MM2"+prefix).c_str() ,"GenTauPtWithDMF_MM2" ,500,0,2000);
  GenTauEtaWithDMF_MM2 = fs->make<TH1F>(("GenTauEtaWithDMF_MM2"+prefix).c_str() ,"GenTauEtaWithDMF_MM2" ,100,-5,5);
  GenTauPhiWithDMF_MM2 = fs->make<TH1F>(("GenTauPhiWithDMF_MM2"+prefix).c_str() ,"GenTauPhiWithDMF_MM2" ,100,-5,5);

  TauPtResponse_MT2= fs->make<TH1F>(("TauPtResponse_MT2"+prefix).c_str() ,"TauPtResponse_MT2",100,0.1,2.0);
  RecoTauDecayMode_MT2 = fs->make<TH1F>(("RecoTauDecayMode_MT2"+prefix).c_str() ,"RecoTauDecayMode_MT2",15,0,15);
  GenTauDecayMode_MT2 = fs->make<TH1F>(("GenTauDecayMode_MT2"+prefix).c_str() ,"GenTauDecayMode_MT2",15,0,15);
  reco_dm_vs_gen_MT2 = fs->make<TH2F>(("reco_dm_vs_gen_MT2"+prefix).c_str() ,"reco_dm_vs_gen_MT2",15,0,15,15,0,15);
  GenTauPtWithDMF_MT2 = fs->make<TH1F>(("GenTauPtWithDMF_MT2"+prefix).c_str() ,"GenTauPtWithDMF_MT2" ,500,0,2000);
  GenTauEtaWithDMF_MT2 = fs->make<TH1F>(("GenTauEtaWithDMF_MT2"+prefix).c_str() ,"GenTauEtaWithDMF_MT2" ,100,-5,5);
  GenTauPhiWithDMF_MT2 = fs->make<TH1F>(("GenTauPhiWithDMF_MT2"+prefix).c_str() ,"GenTauPhiWithDMF_MT2" ,100,-5,5);


  TauPtResponse_ML3 = fs->make<TH1F>(("TauPtResponse_ML3"+prefix).c_str() ,"TauPtResponse_ML3",100,0.1,2.0);
  RecoTauDecayMode_ML3 = fs->make<TH1F>(("RecoTauDecayMode_ML3"+prefix).c_str() ,"RecoTauDecayMode_ML3",15,0,15);
  GenTauDecayMode_ML3 = fs->make<TH1F>(("GenTauDecayMode_ML3"+prefix).c_str() ,"GenTauDecayMode_ML3",15,0,15);
  reco_dm_vs_gen_ML3 = fs->make<TH2F>(("reco_dm_vs_gen_ML3"+prefix).c_str() ,"reco_dm_vs_gen_ML3",15,0,15,15,0,15);
  GenTauPtWithDMF_ML3 = fs->make<TH1F>(("GenTauPtWithDMF_ML3"+prefix).c_str() ,"GenTauPtWithDMF_ML3" ,500,0,2000);
  GenTauEtaWithDMF_ML3 = fs->make<TH1F>(("GenTauEtaWithDMF_ML3"+prefix).c_str() ,"GenTauEtaWithDMF_ML3" ,100,-5,5);
  GenTauPhiWithDMF_ML3 = fs->make<TH1F>(("GenTauPhiWithDMF_ML3"+prefix).c_str() ,"GenTauPhiWithDMF_ML3" ,100,-5,5);



  TauPtResponse_MT3= fs->make<TH1F>(("TauPtResponse_MT3"+prefix).c_str() ,"TauPtResponse_MT3",100,0.1,2.0);
  RecoTauDecayMode_MT3 = fs->make<TH1F>(("RecoTauDecayMode_MT3"+prefix).c_str() ,"RecoTauDecayMode_MT3",15,0,15);
  GenTauDecayMode_MT3 = fs->make<TH1F>(("GenTauDecayMode_MT3"+prefix).c_str() ,"GenTauDecayMode_MT3",15,0,15);
  reco_dm_vs_gen_MT3 = fs->make<TH2F>(("reco_dm_vs_gen_MT3"+prefix).c_str() ,"reco_dm_vs_gen_MT3",15,0,15,15,0,15);
  GenTauPtWithDMF_MT3 = fs->make<TH1F>(("GenTauPtWithDMF_MT3"+prefix).c_str() ,"GenTauPtWithDMF_MT3" ,500,0,2000);
  GenTauEtaWithDMF_MT3 = fs->make<TH1F>(("GenTauEtaWithDMF_MT3"+prefix).c_str() ,"GenTauEtaWithDMF_MT3" ,100,-5,5);
  GenTauPhiWithDMF_MT3 = fs->make<TH1F>(("GenTauPhiWithDMF_MT3"+prefix).c_str() ,"GenTauPhiWithDMF_MT3" ,100,-5,5);



  TauPtResponse_EL3 = fs->make<TH1F>(("TauPtResponse_EL3"+prefix).c_str() ,"TauPtResponse_EL3",100,0.1,2.0);
  RecoTauDecayMode_EL3 = fs->make<TH1F>(("RecoTauDecayMode_EL3"+prefix).c_str() ,"RecoTauDecayMode_EL3",15,0,15);
  GenTauDecayMode_EL3 = fs->make<TH1F>(("GenTauDecayMode_EL3"+prefix).c_str() ,"GenTauDecayMode_EL3",15,0,15);
  reco_dm_vs_gen_EL3 = fs->make<TH2F>(("reco_dm_vs_gen_EL3"+prefix).c_str() ,"reco_dm_vs_gen_EL3",15,0,15,15,0,15);
  GenTauPtWithDMF_EL3 = fs->make<TH1F>(("GenTauPtWithDMF_EL3"+prefix).c_str() ,"GenTauPtWithDMF_EL3" ,500,0,2000);
  GenTauEtaWithDMF_EL3 = fs->make<TH1F>(("GenTauEtaWithDMF_EL3"+prefix).c_str() ,"GenTauEtaWithDMF_EL3" ,100,-5,5);
  GenTauPhiWithDMF_EL3 = fs->make<TH1F>(("GenTauPhiWithDMF_EL3"+prefix).c_str() ,"GenTauPhiWithDMF_EL3" ,100,-5,5);

  TauPtResponse_EM3 = fs->make<TH1F>(("TauPtResponse_EM3"+prefix).c_str() ,"TauPtResponse_EM3",100,0.1,2.0);
  RecoTauDecayMode_EM3 = fs->make<TH1F>(("RecoTauDecayMode_EM3"+prefix).c_str() ,"RecoTauDecayMode_EM3",15,0,15);
  GenTauDecayMode_EM3 = fs->make<TH1F>(("GenTauDecayMode_EM3"+prefix).c_str() ,"GenTauDecayMode_EM3",15,0,15);
  reco_dm_vs_gen_EM3 = fs->make<TH2F>(("reco_dm_vs_gen_EM3"+prefix).c_str() ,"reco_dm_vs_gen_EM3",15,0,15,15,0,15);
  GenTauPtWithDMF_EM3 = fs->make<TH1F>(("GenTauPtWithDMF_EM3"+prefix).c_str() ,"GenTauPtWithDMF_EM3" ,500,0,2000);
  GenTauEtaWithDMF_EM3 = fs->make<TH1F>(("GenTauEtaWithDMF_EM3"+prefix).c_str() ,"GenTauEtaWithDMF_EM3" ,100,-5,5);
  GenTauPhiWithDMF_EM3 = fs->make<TH1F>(("GenTauPhiWithDMF_EM3"+prefix).c_str() ,"GenTauPhiWithDMF_EM3" ,100,-5,5);

  TauPtResponse_ET3 = fs->make<TH1F>(("TauPtResponse_ET3"+prefix).c_str() ,"TauPtResponse_ET3",100,0.1,2.0);
  RecoTauDecayMode_ET3 = fs->make<TH1F>(("RecoTauDecayMode_ET3"+prefix).c_str() ,"RecoTauDecayMode_ET3",15,0,15);
  GenTauDecayMode_ET3 = fs->make<TH1F>(("GenTauDecayMode_ET3"+prefix).c_str() ,"GenTauDecayMode_ET3",15,0,15);
  reco_dm_vs_gen_ET3 = fs->make<TH2F>(("reco_dm_vs_gen_ET3"+prefix).c_str() ,"reco_dm_vs_gen_ET3",15,0,15,15,0,15);
  GenTauPtWithDMF_ET3 = fs->make<TH1F>(("GenTauPtWithDMF_ET3"+prefix).c_str() ,"GenTauPtWithDMF_ET3" ,500,0,2000);
  GenTauEtaWithDMF_ET3 = fs->make<TH1F>(("GenTauEtaWithDMF_ET3"+prefix).c_str() ,"GenTauEtaWithDMF_ET3" ,100,-5,5);
  GenTauPhiWithDMF_ET3 = fs->make<TH1F>(("GenTauPhiWithDMF_ET3"+prefix).c_str() ,"GenTauPhiWithDMF_ET3" ,100,-5,5);

  TauPtResponse_Cut  = fs->make<TH1F>(("TauPtResponse_Cut"+prefix).c_str() ,"TauPtResponse_Cut",100,0.1,2.0);
  RecoTauDecayMode_Cut  = fs->make<TH1F>(("RecoTauDecayMode_Cut"+prefix).c_str() ,"RecoTauDecayMode_Cut",15,0,15);
  GenTauDecayMode_Cut   = fs->make<TH1F>(("GenTauDecayMode_Cut"+prefix).c_str() ,"GenTauDecayMode_Cut",15,0,15);
  reco_dm_vs_gen_Cut = fs->make<TH2F>(("reco_dm_vs_gen_Cut"+prefix).c_str() ,"reco_dm_vs_gen_Cut",15,0,15,15,0,15);
  GenTauPtWithDMF_Cut = fs->make<TH1F>(("GenTauPtWithDMF_Cut"+prefix).c_str() ,"GenTauPtWithDMF_Cut" ,500,0,2000);
  GenTauEtaWithDMF_Cut = fs->make<TH1F>(("GenTauEtaWithDMF_Cut"+prefix).c_str() ,"GenTauEtaWithDMF_Cut"  ,100,-5,5);
  GenTauPhiWithDMF_Cut = fs->make<TH1F>(("GenTauPhiWithDMF_Cut"+prefix).c_str() ,"GenTauPhiWithDMF_Cut"  ,100,-5,5);

  TauPtResponse_LIso3Hits = fs->make<TH1F>(("TauPtResponse_LIso3Hits"+prefix).c_str() ,"TauPtResponse_LIso3Hits",100,0.1,2.0);
  RecoTauDecayMode_LIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_LIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_LIso3Hits",15,0,15);
  GenTauDecayMode_LIso3Hits = fs->make<TH1F>(("GenTauDecayMode_LIso3Hits"+prefix).c_str() ,"GenTauDecayMode_LIso3Hits",15,0,15);
  reco_dm_vs_gen_LIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_LIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_LIso3Hits",15,0,15,15,0,15);
  GenTauPtWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_LIso3Hits" ,500,0,2000);
  GenTauEtaWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_LIso3Hits"  ,100,-5,5);
  GenTauPhiWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_LIso3Hits"  ,100,-5,5);
  

  TauPtResponse_MIso3Hits = fs->make<TH1F>(("TauPtResponse_MIso3Hits"+prefix).c_str() ,"TauPtResponse_MIso3Hits",100,0.1,2.0);
  RecoTauDecayMode_MIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_MIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_MIso3Hits",15,0,15);
  GenTauDecayMode_MIso3Hits = fs->make<TH1F>(("GenTauDecayMode_MIso3Hits"+prefix).c_str() ,"GenTauDecayMode_MIso3Hits",15,0,15);
  reco_dm_vs_gen_MIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_MIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_MIso3Hits",15,0,15,15,0,15);
  GenTauPtWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_MIso3Hits" ,500,0,2000);
  GenTauEtaWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_MIso3Hits"  ,100,-5,5);
  GenTauPhiWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_MIso3Hits"  ,100,-5,5);
  
  TauPtResponse_TIso3Hits = fs->make<TH1F>(("TauPtResponse_TIso3Hits"+prefix).c_str() ,"TauPtResponse_TIso3Hits",100,0.1,2.0);
  RecoTauDecayMode_TIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_TIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_TIso3Hits",15,0,15);
  GenTauDecayMode_TIso3Hits = fs->make<TH1F>(("GenTauDecayMode_TIso3Hits"+prefix).c_str() ,"GenTauDecayMode_TIso3Hits",15,0,15);
  reco_dm_vs_gen_TIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_TIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_TIso3Hits",15,0,15,15,0,15);
  GenTauPtWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_TIso3Hits" ,500,0,2000);
  GenTauEtaWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_TIso3Hits"  ,100,-5,5);
  GenTauPhiWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_TIso3Hits"  ,100,-5,5);
  

  TauPtResponse_LIso = fs->make<TH1F>(("TauPtResponse_LIso"+prefix).c_str() ,"TauPtResponse_LIso",100,0.1,2.0);
  RecoTauDecayMode_LIso = fs->make<TH1F>(("RecoTauDecayMode_LIso"+prefix).c_str() ,"RecoTauDecayMode_LIso",15,0,15);
  GenTauDecayMode_LIso = fs->make<TH1F>(("GenTauDecayMode_LIso"+prefix).c_str() ,"GenTauDecayMode_LIso",15,0,15);
  reco_dm_vs_gen_LIso = fs->make<TH2F>(("reco_dm_vs_gen_LIso"+prefix).c_str() ,"reco_dm_vs_gen_LIso",15,0,15,15,0,15);
  GenTauPtWithDMF_LIso = fs->make<TH1F>(("GenTauPtWithDMF_LIso"+prefix).c_str() ,"GenTauPtWithDMF_LIso" ,500,0,2000);
  GenTauEtaWithDMF_LIso = fs->make<TH1F>(("GenTauEtaWithDMF_LIso"+prefix).c_str() ,"GenTauEtaWithDMF_LIso"  ,100,-5,5);
  GenTauPhiWithDMF_LIso = fs->make<TH1F>(("GenTauPhiWithDMF_LIso"+prefix).c_str() ,"GenTauPhiWithDMF_LIso"  ,100,-5,5);

  TauPtResponse_MIso = fs->make<TH1F>(("TauPtResponse_MIso"+prefix).c_str() ,"TauPtResponse_MIso",100,0.1,2.0);
  RecoTauDecayMode_MIso = fs->make<TH1F>(("RecoTauDecayMode_MIso"+prefix).c_str() ,"RecoTauDecayMode_MIso",15,0,15);
  GenTauDecayMode_MIso = fs->make<TH1F>(("GenTauDecayMode_MIso"+prefix).c_str() ,"GenTauDecayMode_MIso",15,0,15);
  reco_dm_vs_gen_MIso = fs->make<TH2F>(("reco_dm_vs_gen_MIso"+prefix).c_str() ,"reco_dm_vs_gen_MIso",15,0,15,15,0,15);
  GenTauPtWithDMF_MIso = fs->make<TH1F>(("GenTauPtWithDMF_MIso"+prefix).c_str() ,"GenTauPtWithDMF_MIso" ,500,0,2000);
  GenTauEtaWithDMF_MIso = fs->make<TH1F>(("GenTauEtaWithDMF_MIso"+prefix).c_str() ,"GenTauEtaWithDMF_MIso"  ,100,-5,5);
  GenTauPhiWithDMF_MIso = fs->make<TH1F>(("GenTauPhiWithDMF_MIso"+prefix).c_str() ,"GenTauPhiWithDMF_MIso"  ,100,-5,5);

  TauPtResponse_TIso = fs->make<TH1F>(("TauPtResponse_TIso"+prefix).c_str() ,"TauPtResponse_TIso",100,0.1,2.0);
  RecoTauDecayMode_TIso = fs->make<TH1F>(("RecoTauDecayMode_TIso"+prefix).c_str() ,"RecoTauDecayMode_TIso",15,0,15);
  GenTauDecayMode_TIso = fs->make<TH1F>(("GenTauDecayMode_TIso"+prefix).c_str() ,"GenTauDecayMode_TIso",15,0,15);
  reco_dm_vs_gen_TIso = fs->make<TH2F>(("reco_dm_vs_gen_TIso"+prefix).c_str() ,"reco_dm_vs_gen_TIso",15,0,15,15,0,15);
  GenTauPtWithDMF_TIso = fs->make<TH1F>(("GenTauPtWithDMF_TIso"+prefix).c_str() ,"GenTauPtWithDMF_TIso" ,500,0,2000);
  GenTauEtaWithDMF_TIso = fs->make<TH1F>(("GenTauEtaWithDMF_TIso"+prefix).c_str() ,"GenTauEtaWithDMF_TIso"  ,100,-5,5);
  GenTauPhiWithDMF_TIso = fs->make<TH1F>(("GenTauPhiWithDMF_TIso"+prefix).c_str() ,"GenTauPhiWithDMF_TIso"  ,100,-5,5);

  TauPtResponse_VLChar = fs->make<TH1F>(("TauPtResponse_VLChar"+prefix).c_str() ,"TauPtResponse_VLChar",100,0.1,2.0);
  RecoTauDecayMode_VLChar = fs->make<TH1F>(("RecoTauDecayMode_VLChar"+prefix).c_str() ,"RecoTauDecayMode_VLChar",15,0,15);
  GenTauDecayMode_VLChar = fs->make<TH1F>(("GenTauDecayMode_VLChar"+prefix).c_str() ,"GenTauDecayMode_VLChar",15,0,15);
  reco_dm_vs_gen_VLChar = fs->make<TH2F>(("reco_dm_vs_gen_VLChar"+prefix).c_str() ,"reco_dm_vs_gen_VLChar",15,0,15,15,0,15);
  GenTauPtWithDMF_VLChar = fs->make<TH1F>(("GenTauPtWithDMF_VLChar"+prefix).c_str() ,"GenTauPtWithDMF_VLChar" ,500,0,2000);
  GenTauEtaWithDMF_VLChar = fs->make<TH1F>(("GenTauEtaWithDMF_VLChar"+prefix).c_str() ,"GenTauEtaWithDMF_VLChar"  ,100,-5,5);
  GenTauPhiWithDMF_VLChar = fs->make<TH1F>(("GenTauPhiWithDMF_VLChar"+prefix).c_str() ,"GenTauPhiWithDMF_VLChar"  ,100,-5,5);

  TauPtResponse_LChar = fs->make<TH1F>(("TauPtResponse_LChar"+prefix).c_str() ,"TauPtResponse_LChar",100,0.1,2.0);
  RecoTauDecayMode_LChar = fs->make<TH1F>(("RecoTauDecayMode_LChar"+prefix).c_str() ,"RecoTauDecayMode_LChar",15,0,15);
  GenTauDecayMode_LChar = fs->make<TH1F>(("GenTauDecayMode_LChar"+prefix).c_str() ,"GenTauDecayMode_LChar",15,0,15);
  reco_dm_vs_gen_LChar = fs->make<TH2F>(("reco_dm_vs_gen_LChar"+prefix).c_str() ,"reco_dm_vs_gen_LChar",15,0,15,15,0,15);
  GenTauPtWithDMF_LChar = fs->make<TH1F>(("GenTauPtWithDMF_LChar"+prefix).c_str() ,"GenTauPtWithDMF_LChar" ,500,0,2000);
  GenTauEtaWithDMF_LChar = fs->make<TH1F>(("GenTauEtaWithDMF_LChar"+prefix).c_str() ,"GenTauEtaWithDMF_LChar"  ,100,-5,5);
  GenTauPhiWithDMF_LChar = fs->make<TH1F>(("GenTauPhiWithDMF_LChar"+prefix).c_str() ,"GenTauPhiWithDMF_LChar"  ,100,-5,5);

  TauPtResponse_MChar = fs->make<TH1F>(("TauPtResponse_MChar"+prefix).c_str() ,"TauPtResponse_MChar",100,0.1,2.0);
  RecoTauDecayMode_MChar = fs->make<TH1F>(("RecoTauDecayMode_MChar"+prefix).c_str() ,"RecoTauDecayMode_MChar",15,0,15);
  GenTauDecayMode_MChar = fs->make<TH1F>(("GenTauDecayMode_MChar"+prefix).c_str() ,"GenTauDecayMode_MChar",15,0,15);
  reco_dm_vs_gen_MChar = fs->make<TH2F>(("reco_dm_vs_gen_MChar"+prefix).c_str() ,"reco_dm_vs_gen_MChar",15,0,15,15,0,15);
  GenTauPtWithDMF_MChar = fs->make<TH1F>(("GenTauPtWithDMF_MChar"+prefix).c_str() ,"GenTauPtWithDMF_MChar" ,500,0,2000);
  GenTauEtaWithDMF_MChar = fs->make<TH1F>(("GenTauEtaWithDMF_MChar"+prefix).c_str() ,"GenTauEtaWithDMF_MChar"  ,100,-5,5);
  GenTauPhiWithDMF_MChar = fs->make<TH1F>(("GenTauPhiWithDMF_MChar"+prefix).c_str() ,"GenTauPhiWithDMF_MChar"  ,100,-5,5);

  TauPtResponse_TChar = fs->make<TH1F>(("TauPtResponse_TChar"+prefix).c_str() ,"TauPtResponse_TChar",100,0.1,2.0);
  RecoTauDecayMode_TChar = fs->make<TH1F>(("RecoTauDecayMode_TChar"+prefix).c_str() ,"RecoTauDecayMode_TChar",15,0,15);
  GenTauDecayMode_TChar = fs->make<TH1F>(("GenTauDecayMode_TChar"+prefix).c_str() ,"GenTauDecayMode_TChar",15,0,15);
  reco_dm_vs_gen_TChar = fs->make<TH2F>(("reco_dm_vs_gen_TChar"+prefix).c_str() ,"reco_dm_vs_gen_TChar",15,0,15,15,0,15);
  GenTauPtWithDMF_TChar = fs->make<TH1F>(("GenTauPtWithDMF_TChar"+prefix).c_str() ,"GenTauPtWithDMF_TChar" ,500,0,2000);
  GenTauEtaWithDMF_TChar = fs->make<TH1F>(("GenTauEtaWithDMF_TChar"+prefix).c_str() ,"GenTauEtaWithDMF_TChar"  ,100,-5,5);
  GenTauPhiWithDMF_TChar = fs->make<TH1F>(("GenTauPhiWithDMF_TChar"+prefix).c_str() ,"GenTauPhiWithDMF_TChar"  ,100,-5,5);

  GenTauPtWithoutDMF = fs->make<TH1F>(("GenTauPtWithoutDMF"+prefix).c_str(), "GenTauPtWithoutDMF",500,0,2000); 
  GenTauEtaWithoutDMF = fs->make<TH1F>(("GenTauEtaWithoutDMF"+prefix).c_str() ,"GenTauEtaWithoutDMF",100,-5,5);
  GenTauPhiWithoutDMF = fs->make<TH1F>(("GenTauPhiWithoutDMF"+prefix).c_str() ,"GenTauPhiWithoutDMF",100,-5,5);
  
  //
  TauPtResponse_LooseRho = fs->make<TH1F>(("TauPtResponse_LooseRho"+prefix).c_str() ,"TauPtResponse_LooseRho",100,0.1,2.0);
  RecoTauDecayMode_LooseRho = fs->make<TH1F>(("RecoTauDecayMode_LooseRho"+prefix).c_str() ,"RecoTauDecayMode_LooseRho",15,0,15);
  GenTauDecayMode_LooseRho = fs->make<TH1F>(("GenTauDecayMode_LooseRho"+prefix).c_str() ,"GenTauDecayMode_LooseRho",15,0,15);
  reco_dm_vs_gen_LooseRho = fs->make<TH2F>(("reco_dm_vs_gen_LooseRho"+prefix).c_str() ,"reco_dm_vs_gen_LooseRho",15,0,15,15,0,15);
  
  GenTauPtWithDMF_LooseRho = fs->make<TH1F>(("GenTauPtWithDMF_LooseRho"+prefix).c_str(), "GenTauPtWithDMF_LooseRho",500,0,2000);
  GenTauEtaWithDMF_LooseRho = fs->make<TH1F>(("GenTauEtaWithDMF_LooseRho"+prefix).c_str() ,"GenTauEtaWithDMF_LooseRho",100,-5,5);
  GenTauPhiWithDMF_LooseRho = fs->make<TH1F>(("GenTauPhiWithDMF_LooseRho"+prefix).c_str() ,"GenTauPhiWithDMF_LooseRho",100,-5,5);
  
  TauPtResponse_MediumRho = fs->make<TH1F>(("TauPtResponse_MediumRho"+prefix).c_str() ,"TauPtResponse_MediumRho",100,0.1,2.0);
  RecoTauDecayMode_MediumRho = fs->make<TH1F>(("RecoTauDecayMode_MediumRho"+prefix).c_str() ,"RecoTauDecayMode_MediumRho",15,0,15);
  GenTauDecayMode_MediumRho = fs->make<TH1F>(("GenTauDecayMode_MediumRho"+prefix).c_str() ,"GenTauDecayMode_MediumRho",15,0,15);
  reco_dm_vs_gen_MediumRho = fs->make<TH2F>(("reco_dm_vs_gen_MediumRho"+prefix).c_str() ,"reco_dm_vs_gen_MediumRho",15,0,15,15,0,15);
  GenTauPtWithDMF_MediumRho = fs->make<TH1F>(("GenTauPtWithDMF_MediumRho"+prefix).c_str(), "GenTauPtWithDMF_MediumRho",500,0,2000);
  GenTauEtaWithDMF_MediumRho = fs->make<TH1F>(("GenTauEtaWithDMF_MediumRho"+prefix).c_str() ,"GenTauEtaWithDMF_MediumRho",100,-5,5);
  GenTauPhiWithDMF_MediumRho = fs->make<TH1F>(("GenTauPhiWithDMF_MediumRho"+prefix).c_str() ,"GenTauPhiWithDMF_MediumRho",100,-5,5);
  
  TauPtResponse_TightRho = fs->make<TH1F>(("TauPtResponse_TightRho"+prefix).c_str() ,"TauPtResponse_TightRho",100,0.1,2.0);
  RecoTauDecayMode_TightRho = fs->make<TH1F>(("RecoTauDecayMode_TightRho"+prefix).c_str() ,"RecoTauDecayMode_TightRho",15,0,15);
  GenTauDecayMode_TightRho = fs->make<TH1F>(("GenTauDecayMode_TightRho"+prefix).c_str() ,"GenTauDecayMode_TightRho",15,0,15);
  reco_dm_vs_gen_TightRho = fs->make<TH2F>(("reco_dm_vs_gen_TightRho"+prefix).c_str() ,"reco_dm_vs_gen_TightRho",15,0,15,15,0,15);
  
  GenTauPtWithDMF_TightRho = fs->make<TH1F>(("GenTauPtWithDMF_TightRho"+prefix).c_str(), "GenTauPtWithDMF_TightRho",500,0,2000);
  GenTauEtaWithDMF_TightRho = fs->make<TH1F>(("GenTauEtaWithDMF_TightRho"+prefix).c_str() ,"GenTauEtaWithDMF_TightRho",100,-5,5);
  GenTauPhiWithDMF_TightRho = fs->make<TH1F>(("GenTauPhiWithDMF_TightRho"+prefix).c_str() ,"GenTauPhiWithDMF_TightRho",100,-5,5);

  h_RunNumber = fs->make<TH1F>(("h_RunNumber"+prefix).c_str() ,"h_RunNumber",100000,0,100000);
  h_EventNumber = fs->make<TH1F>(("h_EventNumber"+prefix).c_str() ,"h_EventNumber",100000,0,100000);
  h_LumiNumber = fs->make<TH1F>(("h_LumiNumber"+prefix).c_str() ,"h_LumiNumber",100000,0,100000);
  h_BXNumber = fs->make<TH1F>(("h_BXNumber"+prefix).c_str() ,"h_BXNumber",100,0,100);


  /// new plots


  TauPtResponse_wLTloose = fs->make<TH1F>(("TauPtResponse_wLTloose"+prefix).c_str() ,"TauPtResponse_wLTloose",100,0.1,2.0);
  RecoTauDecayMode_wLTloose = fs->make<TH1F>(("RecoTauDecayMode_wLTloose"+prefix).c_str() ,"RecoTauDecayMode_wLTloose",15,0,15);
  GenTauDecayMode_wLTloose = fs->make<TH1F>(("GenTauDecayMode_wLTloose"+prefix).c_str() ,"GenTauDecayMode_wLTloose",15,0,15);
  reco_dm_vs_gen_wLTloose = fs->make<TH2F>(("reco_dm_vs_gen_wLTloose"+prefix).c_str() ,"reco_dm_vs_gen_wLTloose",15,0,15,15,0,15);
  GenTauPtWithDMF_wLTloose = fs->make<TH1F>(("GenTauPtWithDMF_wLTloose"+prefix).c_str() ,"GenTauPtWithDMF_wLTloose" ,500,0,2000);
  GenTauEtaWithDMF_wLTloose = fs->make<TH1F>(("GenTauEtaWithDMF_wLTloose"+prefix).c_str() ,"GenTauEtaWithDMF_wLTloose"  ,100,-5,5);
  GenTauPhiWithDMF_wLTloose = fs->make<TH1F>(("GenTauPhiWithDMF_wLTloose"+prefix).c_str() ,"GenTauPhiWithDMF_wLTloose"  ,100,-5,5);

  TES_wLTloose = fs->make<TProfile>(("TES_wLTloose"+prefix).c_str(),"TES_wLTloose",500,0,2000,0,50);
  Nvtx_wLTloose = fs->make<TH1F>(("Nvtx_wLTloose"+prefix).c_str() ,"Nvtx_wLTloose",200,0,200);
  NGood_wLTloose = fs->make<TH1F>(("NGood_wLTloose"+prefix).c_str() ,"NGood_wLTloose",200,0,200);

 
  TauPtResponse_wLTvloose = fs->make<TH1F>(("TauPtResponse_wLTvloose"+prefix).c_str() ,"TauPtResponse_wLTvloose",100,0.1,2.0);
  RecoTauDecayMode_wLTvloose = fs->make<TH1F>(("RecoTauDecayMode_wLTvloose"+prefix).c_str() ,"RecoTauDecayMode_wLTvloose",15,0,15);
  GenTauDecayMode_wLTvloose = fs->make<TH1F>(("GenTauDecayMode_wLTvloose"+prefix).c_str() ,"GenTauDecayMode_wLTvloose",15,0,15);
  reco_dm_vs_gen_wLTvloose = fs->make<TH2F>(("reco_dm_vs_gen_wLTvloose"+prefix).c_str() ,"reco_dm_vs_gen_wLTvloose",15,0,15,15,0,15);
  GenTauPtWithDMF_wLTvloose = fs->make<TH1F>(("GenTauPtWithDMF_wLTvloose"+prefix).c_str() ,"GenTauPtWithDMF_wLTvloose" ,500,0,2000);
  GenTauEtaWithDMF_wLTvloose = fs->make<TH1F>(("GenTauEtaWithDMF_wLTvloose"+prefix).c_str() ,"GenTauEtaWithDMF_wLTvloose"  ,100,-5,5);
  GenTauPhiWithDMF_wLTvloose = fs->make<TH1F>(("GenTauPhiWithDMF_wLTvloose"+prefix).c_str() ,"GenTauPhiWithDMF_wLTvloose"  ,100,-5,5);

  TES_wLTvloose = fs->make<TProfile>(("TES_wLTvloose"+prefix).c_str(),"TES_wLTvloose",500,0,2000,0,50);
  Nvtx_wLTvloose = fs->make<TH1F>(("Nvtx_wLTvloose"+prefix).c_str() ,"Nvtx_wLTvloose",200,0,200);
  NGood_wLTvloose = fs->make<TH1F>(("NGood_wLTvloose"+prefix).c_str() ,"NGood_wLTvloose",200,0,200);

  TauPtResponse_wLTmedium = fs->make<TH1F>(("TauPtResponse_wLTmedium"+prefix).c_str() ,"TauPtResponse_wLTmedium",100,0.1,2.0);
  RecoTauDecayMode_wLTmedium = fs->make<TH1F>(("RecoTauDecayMode_wLTmedium"+prefix).c_str() ,"RecoTauDecayMode_wLTmedium",15,0,15);
  GenTauDecayMode_wLTmedium = fs->make<TH1F>(("GenTauDecayMode_wLTmedium"+prefix).c_str() ,"GenTauDecayMode_wLTmedium",15,0,15);
  reco_dm_vs_gen_wLTmedium = fs->make<TH2F>(("reco_dm_vs_gen_wLTmedium"+prefix).c_str() ,"reco_dm_vs_gen_wLTmedium",15,0,15,15,0,15);
  GenTauPtWithDMF_wLTmedium = fs->make<TH1F>(("GenTauPtWithDMF_wLTmedium"+prefix).c_str() ,"GenTauPtWithDMF_wLTmedium" ,500,0,2000);
  GenTauEtaWithDMF_wLTmedium = fs->make<TH1F>(("GenTauEtaWithDMF_wLTmedium"+prefix).c_str() ,"GenTauEtaWithDMF_wLTmedium"  ,100,-5,5);
  GenTauPhiWithDMF_wLTmedium = fs->make<TH1F>(("GenTauPhiWithDMF_wLTmedium"+prefix).c_str() ,"GenTauPhiWithDMF_wLTmedium"  ,100,-5,5);

  TES_wLTmedium = fs->make<TProfile>(("TES_wLTmedium"+prefix).c_str(),"TES_wLTmedium",500,0,2000,0,50);
  Nvtx_wLTmedium = fs->make<TH1F>(("Nvtx_wLTmedium"+prefix).c_str() ,"Nvtx_wLTmedium",200,0,200);
  NGood_wLTmedium = fs->make<TH1F>(("NGood_wLTmedium"+prefix).c_str() ,"NGood_wLTmedium",200,0,200);



  TauPtResponse_wLTtight = fs->make<TH1F>(("TauPtResponse_wLTtight"+prefix).c_str() ,"TauPtResponse_wLTtight",100,0.1,2.0);
  RecoTauDecayMode_wLTtight = fs->make<TH1F>(("RecoTauDecayMode_wLTtight"+prefix).c_str() ,"RecoTauDecayMode_wLTtight",15,0,15);
  GenTauDecayMode_wLTtight = fs->make<TH1F>(("GenTauDecayMode_wLTtight"+prefix).c_str() ,"GenTauDecayMode_wLTtight",15,0,15);
  reco_dm_vs_gen_wLTtight = fs->make<TH2F>(("reco_dm_vs_gen_wLTtight"+prefix).c_str() ,"reco_dm_vs_gen_wLTtight",15,0,15,15,0,15);
  GenTauPtWithDMF_wLTtight = fs->make<TH1F>(("GenTauPtWithDMF_wLTtight"+prefix).c_str() ,"GenTauPtWithDMF_wLTtight" ,500,0,2000);
  GenTauEtaWithDMF_wLTtight = fs->make<TH1F>(("GenTauEtaWithDMF_wLTtight"+prefix).c_str() ,"GenTauEtaWithDMF_wLTtight"  ,100,-5,5);
  GenTauPhiWithDMF_wLTtight = fs->make<TH1F>(("GenTauPhiWithDMF_wLTtight"+prefix).c_str() ,"GenTauPhiWithDMF_wLTtight"  ,100,-5,5);

  TES_wLTtight = fs->make<TProfile>(("TES_wLTtight"+prefix).c_str(),"TES_wLTtight",500,0,2000,0,50);
  Nvtx_wLTtight = fs->make<TH1F>(("Nvtx_wLTtight"+prefix).c_str() ,"Nvtx_wLTtight",200,0,200);
  NGood_wLTtight = fs->make<TH1F>(("NGood_wLTtight"+prefix).c_str() ,"NGood_wLTtight",200,0,200);

  TauPtResponse_wLTvtight = fs->make<TH1F>(("TauPtResponse_wLTvtight"+prefix).c_str() ,"TauPtResponse_wLTvtight",100,0.1,2.0);
  RecoTauDecayMode_wLTvtight = fs->make<TH1F>(("RecoTauDecayMode_wLTvtight"+prefix).c_str() ,"RecoTauDecayMode_wLTvtight",15,0,15);
  GenTauDecayMode_wLTvtight = fs->make<TH1F>(("GenTauDecayMode_wLTvtight"+prefix).c_str() ,"GenTauDecayMode_wLTvtight",15,0,15);
  reco_dm_vs_gen_wLTvtight = fs->make<TH2F>(("reco_dm_vs_gen_wLTvtight"+prefix).c_str() ,"reco_dm_vs_gen_wLTvtight",15,0,15,15,0,15);
  GenTauPtWithDMF_wLTvtight = fs->make<TH1F>(("GenTauPtWithDMF_wLTvtight"+prefix).c_str() ,"GenTauPtWithDMF_wLTvtight" ,500,0,2000);
  GenTauEtaWithDMF_wLTvtight = fs->make<TH1F>(("GenTauEtaWithDMF_wLTvtight"+prefix).c_str() ,"GenTauEtaWithDMF_wLTvtight"  ,100,-5,5);
  GenTauPhiWithDMF_wLTvtight = fs->make<TH1F>(("GenTauPhiWithDMF_wLTvtight"+prefix).c_str() ,"GenTauPhiWithDMF_wLTvtight"  ,100,-5,5);

  TES_wLTvtight = fs->make<TProfile>(("TES_wLTvtight"+prefix).c_str(),"TES_wLTvtight",500,0,2000,0,50);
  Nvtx_wLTvtight = fs->make<TH1F>(("Nvtx_wLTvtight"+prefix).c_str() ,"Nvtx_wLTvtight",200,0,200);
  NGood_wLTvtight = fs->make<TH1F>(("NGood_wLTvtight"+prefix).c_str() ,"NGood_wLTvtight",200,0,200);

 
  TauPtResponse_wLTvvtight = fs->make<TH1F>(("TauPtResponse_wLTvvtight"+prefix).c_str() ,"TauPtResponse_wLTvvtight",100,0.1,2.0);
  RecoTauDecayMode_wLTvvtight = fs->make<TH1F>(("RecoTauDecayMode_wLTvvtight"+prefix).c_str() ,"RecoTauDecayMode_wLTvvtight",15,0,15);
  GenTauDecayMode_wLTvvtight = fs->make<TH1F>(("GenTauDecayMode_wLTvvtight"+prefix).c_str() ,"GenTauDecayMode_wLTvvtight",15,0,15);
  reco_dm_vs_gen_wLTvvtight = fs->make<TH2F>(("reco_dm_vs_gen_wLTvvtight"+prefix).c_str() ,"reco_dm_vs_gen_wLTvvtight",15,0,15,15,0,15);
  GenTauPtWithDMF_wLTvvtight = fs->make<TH1F>(("GenTauPtWithDMF_wLTvvtight"+prefix).c_str() ,"GenTauPtWithDMF_wLTvvtight" ,500,0,2000);
  GenTauEtaWithDMF_wLTvvtight = fs->make<TH1F>(("GenTauEtaWithDMF_wLTvvtight"+prefix).c_str() ,"GenTauEtaWithDMF_wLTvvtight"  ,100,-5,5);
  GenTauPhiWithDMF_wLTvvtight = fs->make<TH1F>(("GenTauPhiWithDMF_wLTvvtight"+prefix).c_str() ,"GenTauPhiWithDMF_wLTvvtight"  ,100,-5,5);

  TES_wLTvvtight = fs->make<TProfile>(("TES_wLTvvtight"+prefix).c_str(),"TES_wLTvvtight",500,0,2000,0,50);
  Nvtx_wLTvvtight = fs->make<TH1F>(("Nvtx_wLTvvtight"+prefix).c_str() ,"Nvtx_wLTvvtight",200,0,200);
  NGood_wLTvvtight = fs->make<TH1F>(("NGood_wLTvvtight"+prefix).c_str() ,"NGood_wLTvvtight",200,0,200);



  //



  TauPtResponse_woLTloose = fs->make<TH1F>(("TauPtResponse_woLTloose"+prefix).c_str() ,"TauPtResponse_woLTloose",100,0.1,2.0);
  RecoTauDecayMode_woLTloose = fs->make<TH1F>(("RecoTauDecayMode_woLTloose"+prefix).c_str() ,"RecoTauDecayMode_woLTloose",15,0,15);
  GenTauDecayMode_woLTloose = fs->make<TH1F>(("GenTauDecayMode_woLTloose"+prefix).c_str() ,"GenTauDecayMode_woLTloose",15,0,15);
  reco_dm_vs_gen_woLTloose = fs->make<TH2F>(("reco_dm_vs_gen_woLTloose"+prefix).c_str() ,"reco_dm_vs_gen_woLTloose",15,0,15,15,0,15);
  GenTauPtWithDMF_woLTloose = fs->make<TH1F>(("GenTauPtWithDMF_woLTloose"+prefix).c_str() ,"GenTauPtWithDMF_woLTloose" ,500,0,2000);
  GenTauEtaWithDMF_woLTloose = fs->make<TH1F>(("GenTauEtaWithDMF_woLTloose"+prefix).c_str() ,"GenTauEtaWithDMF_woLTloose"  ,100,-5,5);
  GenTauPhiWithDMF_woLTloose = fs->make<TH1F>(("GenTauPhiWithDMF_woLTloose"+prefix).c_str() ,"GenTauPhiWithDMF_woLTloose"  ,100,-5,5);

  TES_woLTloose = fs->make<TProfile>(("TES_woLTloose"+prefix).c_str(),"TES_woLTloose",500,0,2000,0,50);
  Nvtx_woLTloose = fs->make<TH1F>(("Nvtx_woLTloose"+prefix).c_str() ,"Nvtx_woLTloose",200,0,200);
  NGood_woLTloose = fs->make<TH1F>(("NGood_woLTloose"+prefix).c_str() ,"NGood_woLTloose",200,0,200);

 
  TauPtResponse_woLTvloose = fs->make<TH1F>(("TauPtResponse_woLTvloose"+prefix).c_str() ,"TauPtResponse_woLTvloose",100,0.1,2.0);
  RecoTauDecayMode_woLTvloose = fs->make<TH1F>(("RecoTauDecayMode_woLTvloose"+prefix).c_str() ,"RecoTauDecayMode_woLTvloose",15,0,15);
  GenTauDecayMode_woLTvloose = fs->make<TH1F>(("GenTauDecayMode_woLTvloose"+prefix).c_str() ,"GenTauDecayMode_woLTvloose",15,0,15);
  reco_dm_vs_gen_woLTvloose = fs->make<TH2F>(("reco_dm_vs_gen_woLTvloose"+prefix).c_str() ,"reco_dm_vs_gen_woLTvloose",15,0,15,15,0,15);
  GenTauPtWithDMF_woLTvloose = fs->make<TH1F>(("GenTauPtWithDMF_woLTvloose"+prefix).c_str() ,"GenTauPtWithDMF_woLTvloose" ,500,0,2000);
  GenTauEtaWithDMF_woLTvloose = fs->make<TH1F>(("GenTauEtaWithDMF_woLTvloose"+prefix).c_str() ,"GenTauEtaWithDMF_woLTvloose"  ,100,-5,5);
  GenTauPhiWithDMF_woLTvloose = fs->make<TH1F>(("GenTauPhiWithDMF_woLTvloose"+prefix).c_str() ,"GenTauPhiWithDMF_woLTvloose"  ,100,-5,5);

  TES_woLTvloose = fs->make<TProfile>(("TES_woLTvloose"+prefix).c_str(),"TES_woLTvloose",500,0,2000,0,50);
  Nvtx_woLTvloose = fs->make<TH1F>(("Nvtx_woLTvloose"+prefix).c_str() ,"Nvtx_woLTvloose",200,0,200);
  NGood_woLTvloose = fs->make<TH1F>(("NGood_woLTvloose"+prefix).c_str() ,"NGood_woLTvloose",200,0,200);

  TauPtResponse_woLTmedium = fs->make<TH1F>(("TauPtResponse_woLTmedium"+prefix).c_str() ,"TauPtResponse_woLTmedium",100,0.1,2.0);
  RecoTauDecayMode_woLTmedium = fs->make<TH1F>(("RecoTauDecayMode_woLTmedium"+prefix).c_str() ,"RecoTauDecayMode_woLTmedium",15,0,15);
  GenTauDecayMode_woLTmedium = fs->make<TH1F>(("GenTauDecayMode_woLTmedium"+prefix).c_str() ,"GenTauDecayMode_woLTmedium",15,0,15);
  reco_dm_vs_gen_woLTmedium = fs->make<TH2F>(("reco_dm_vs_gen_woLTmedium"+prefix).c_str() ,"reco_dm_vs_gen_woLTmedium",15,0,15,15,0,15);
  GenTauPtWithDMF_woLTmedium = fs->make<TH1F>(("GenTauPtWithDMF_woLTmedium"+prefix).c_str() ,"GenTauPtWithDMF_woLTmedium" ,500,0,2000);
  GenTauEtaWithDMF_woLTmedium = fs->make<TH1F>(("GenTauEtaWithDMF_woLTmedium"+prefix).c_str() ,"GenTauEtaWithDMF_woLTmedium"  ,100,-5,5);
  GenTauPhiWithDMF_woLTmedium = fs->make<TH1F>(("GenTauPhiWithDMF_woLTmedium"+prefix).c_str() ,"GenTauPhiWithDMF_woLTmedium"  ,100,-5,5);

  TES_woLTmedium = fs->make<TProfile>(("TES_woLTmedium"+prefix).c_str(),"TES_woLTmedium",500,0,2000,0,50);
  Nvtx_woLTmedium = fs->make<TH1F>(("Nvtx_woLTmedium"+prefix).c_str() ,"Nvtx_woLTmedium",200,0,200);
  NGood_woLTmedium = fs->make<TH1F>(("NGood_woLTmedium"+prefix).c_str() ,"NGood_woLTmedium",200,0,200);



  TauPtResponse_woLTtight = fs->make<TH1F>(("TauPtResponse_woLTtight"+prefix).c_str() ,"TauPtResponse_woLTtight",100,0.1,2.0);
  RecoTauDecayMode_woLTtight = fs->make<TH1F>(("RecoTauDecayMode_woLTtight"+prefix).c_str() ,"RecoTauDecayMode_woLTtight",15,0,15);
  GenTauDecayMode_woLTtight = fs->make<TH1F>(("GenTauDecayMode_woLTtight"+prefix).c_str() ,"GenTauDecayMode_woLTtight",15,0,15);
  reco_dm_vs_gen_woLTtight = fs->make<TH2F>(("reco_dm_vs_gen_woLTtight"+prefix).c_str() ,"reco_dm_vs_gen_woLTtight",15,0,15,15,0,15);
  GenTauPtWithDMF_woLTtight = fs->make<TH1F>(("GenTauPtWithDMF_woLTtight"+prefix).c_str() ,"GenTauPtWithDMF_woLTtight" ,500,0,2000);
  GenTauEtaWithDMF_woLTtight = fs->make<TH1F>(("GenTauEtaWithDMF_woLTtight"+prefix).c_str() ,"GenTauEtaWithDMF_woLTtight"  ,100,-5,5);
  GenTauPhiWithDMF_woLTtight = fs->make<TH1F>(("GenTauPhiWithDMF_woLTtight"+prefix).c_str() ,"GenTauPhiWithDMF_woLTtight"  ,100,-5,5);

  TES_woLTtight = fs->make<TProfile>(("TES_woLTtight"+prefix).c_str(),"TES_woLTtight",500,0,2000,0,50);
  Nvtx_woLTtight = fs->make<TH1F>(("Nvtx_woLTtight"+prefix).c_str() ,"Nvtx_woLTtight",200,0,200);
  NGood_woLTtight = fs->make<TH1F>(("NGood_woLTtight"+prefix).c_str() ,"NGood_woLTtight",200,0,200);

  TauPtResponse_woLTvtight = fs->make<TH1F>(("TauPtResponse_woLTvtight"+prefix).c_str() ,"TauPtResponse_woLTvtight",100,0.1,2.0);
  RecoTauDecayMode_woLTvtight = fs->make<TH1F>(("RecoTauDecayMode_woLTvtight"+prefix).c_str() ,"RecoTauDecayMode_woLTvtight",15,0,15);
  GenTauDecayMode_woLTvtight = fs->make<TH1F>(("GenTauDecayMode_woLTvtight"+prefix).c_str() ,"GenTauDecayMode_woLTvtight",15,0,15);
  reco_dm_vs_gen_woLTvtight = fs->make<TH2F>(("reco_dm_vs_gen_woLTvtight"+prefix).c_str() ,"reco_dm_vs_gen_woLTvtight",15,0,15,15,0,15);
  GenTauPtWithDMF_woLTvtight = fs->make<TH1F>(("GenTauPtWithDMF_woLTvtight"+prefix).c_str() ,"GenTauPtWithDMF_woLTvtight" ,500,0,2000);
  GenTauEtaWithDMF_woLTvtight = fs->make<TH1F>(("GenTauEtaWithDMF_woLTvtight"+prefix).c_str() ,"GenTauEtaWithDMF_woLTvtight"  ,100,-5,5);
  GenTauPhiWithDMF_woLTvtight = fs->make<TH1F>(("GenTauPhiWithDMF_woLTvtight"+prefix).c_str() ,"GenTauPhiWithDMF_woLTvtight"  ,100,-5,5);

  TES_woLTvtight = fs->make<TProfile>(("TES_woLTvtight"+prefix).c_str(),"TES_woLTvtight",500,0,2000,0,50);
  Nvtx_woLTvtight = fs->make<TH1F>(("Nvtx_woLTvtight"+prefix).c_str() ,"Nvtx_woLTvtight",200,0,200);
  NGood_woLTvtight = fs->make<TH1F>(("NGood_woLTvtight"+prefix).c_str() ,"NGood_woLTvtight",200,0,200);

 
  TauPtResponse_woLTvvtight = fs->make<TH1F>(("TauPtResponse_woLTvvtight"+prefix).c_str() ,"TauPtResponse_woLTvvtight",100,0.1,2.0);
  RecoTauDecayMode_woLTvvtight = fs->make<TH1F>(("RecoTauDecayMode_woLTvvtight"+prefix).c_str() ,"RecoTauDecayMode_woLTvvtight",15,0,15);
  GenTauDecayMode_woLTvvtight = fs->make<TH1F>(("GenTauDecayMode_woLTvvtight"+prefix).c_str() ,"GenTauDecayMode_woLTvvtight",15,0,15);
  reco_dm_vs_gen_woLTvvtight = fs->make<TH2F>(("reco_dm_vs_gen_woLTvvtight"+prefix).c_str() ,"reco_dm_vs_gen_woLTvvtight",15,0,15,15,0,15);
  GenTauPtWithDMF_woLTvvtight = fs->make<TH1F>(("GenTauPtWithDMF_woLTvvtight"+prefix).c_str() ,"GenTauPtWithDMF_woLTvvtight" ,500,0,2000);
  GenTauEtaWithDMF_woLTvvtight = fs->make<TH1F>(("GenTauEtaWithDMF_woLTvvtight"+prefix).c_str() ,"GenTauEtaWithDMF_woLTvvtight"  ,100,-5,5);
  GenTauPhiWithDMF_woLTvvtight = fs->make<TH1F>(("GenTauPhiWithDMF_woLTvvtight"+prefix).c_str() ,"GenTauPhiWithDMF_woLTvvtight"  ,100,-5,5);

  TES_woLTvvtight = fs->make<TProfile>(("TES_woLTvvtight"+prefix).c_str(),"TES_woLTvvtight",500,0,2000,0,50);
  Nvtx_woLTvvtight = fs->make<TH1F>(("Nvtx_woLTvvtight"+prefix).c_str() ,"Nvtx_woLTvvtight",200,0,200);
  NGood_woLTvvtight = fs->make<TH1F>(("NGood_woLTvvtight"+prefix).c_str() ,"NGood_woLTvvtight",200,0,200);


  //
}


TauIDUpto23New::~TauIDUpto23New()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void TauIDUpto23New::Fill(const edm::Event& iEvent) {
   using namespace edm;
   using namespace std;
   using namespace reco;
   using namespace pat;

  iEvent.getByLabel("genParticles", _genParticles); 
   
  
  Handle< reco::TrackCollection > track;
  iEvent.getByLabel("generalTracks", track);

  Handle< reco::GenJetCollection > genTauJets;
  iEvent.getByLabel("tauGenJets",genTauJets);
  
  
  edm::Handle<std::vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel(std::string("addPileupInfo"), PupInfo);
  
  edm::Handle<reco::MuonCollection> rmuons;
  iEvent.getByLabel("muons",rmuons);
  
  edm::Handle<reco::VertexCollection> vtx;
  iEvent.getByLabel("offlinePrimaryVertices",vtx);
  
  //  vector<pat::Muon>                    "patMuons"                  ""           "PATTuple"  
  std::vector<PileupSummaryInfo>::const_iterator PVI;
  int ootnpuVertices =0;
  int npuVertices    =0;
  for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
    if(PVI->getBunchCrossing()== 0)  {
      npuVertices += PVI->getPU_NumInteractions();
    }
    else{   ootnpuVertices += PVI->getPU_NumInteractions();
    }
  }//loop over pileup infor
 

  iEvent.getByLabel("ak5GenJets", _genJets);
  
  
  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  //decay Mode
  
  //Muon Veto
 
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFindingNewDMs",_Newdmf);  

   //Muon 2 working pint
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection2",_mv1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumMuonRejection2",_mv2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection2",_mv3);
   
   // Muon 3 working points

   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection3",_mv31);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection3",_mv32);

   //Electron Veto
// new cut based

   iEvent.getByLabel("hpsPFTauDiscriminationByMediumElectronRejection2",_enew);

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
   
// new discriminators

    iEvent.getByLabel("hpsPFTauDiscriminationByIsolationMVA3newDMwLTraw", _isowLTraw);
    iEvent.getByLabel("hpsPFTauDiscriminationByIsolationMVA3newDMwoLTraw", _isowoLTraw);
    iEvent.getByLabel("hpsPFTauDiscriminationByVLooseIsolationMVA3newDMwLT",_isowLTvloose);
    iEvent.getByLabel("hpsPFTauDiscriminationByLooseIsolationMVA3newDMwLT", _isowLTloose);
    iEvent.getByLabel("hpsPFTauDiscriminationByMediumIsolationMVA3newDMwLT", _isowLTmedium);
    iEvent.getByLabel("hpsPFTauDiscriminationByTightIsolationMVA3newDMwLT", _isowLTtight);
    iEvent.getByLabel("hpsPFTauDiscriminationByVTightIsolationMVA3newDMwLT", _isowLTvtight);
    iEvent.getByLabel("hpsPFTauDiscriminationByVVTightIsolationMVA3newDMwLT", _isowLTvvtight);

     iEvent.getByLabel("hpsPFTauDiscriminationByVLooseIsolationMVA3newDMwoLT", _isowoLTvloose);
     iEvent.getByLabel("hpsPFTauDiscriminationByLooseIsolationMVA3newDMwoLT", _isowoLTloose);
     iEvent.getByLabel("hpsPFTauDiscriminationByMediumIsolationMVA3newDMwoLT", _isowoLTmedium);
     iEvent.getByLabel("hpsPFTauDiscriminationByTightIsolationMVA3newDMwoLT", _isowoLTtight);
     iEvent.getByLabel("hpsPFTauDiscriminationByVTightIsolationMVA3newDMwoLT", _isowoLTvtight);
     iEvent.getByLabel("hpsPFTauDiscriminationByVVTightIsolationMVA3newDMwoLT", _isowoLTvvtight);


   bool isZtautau=false;
   isZtautau = IsZTauTau (_genParticles) ;
   
   int  nGoodVtx = 0;
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){
     
     if((vtxIt->isValid()) && !(vtxIt->isFake())) {
       
       nGoodVtx++;
     }
   }
   

   //isZtautau=true;
   
   if(isZtautau) {

     
     // input variables to Electron Discriminator
     for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
       reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
       
       if((tauCandidate->leadPFChargedHadrCand().isNonnull()) && (tauCandidate->leadPFChargedHadrCand()->p() > 0)) { 
	 FillHOverP->Fill(tauCandidate->leadPFChargedHadrCand()->hcalEnergy()/tauCandidate->leadPFChargedHadrCand()->p());
	 FillEOverP->Fill(tauCandidate->leadPFChargedHadrCand()->ecalEnergy()/tauCandidate->leadPFChargedHadrCand()->p());
	 
       }
       
       hFillTauHcal3x3OverPLead->Fill(tauCandidate->hcal3x3OverPLead());
       
       // photon fraction
       
       int sumPt = 0;
       for ( std::vector<PFCandidatePtr>::const_iterator signalTrack =  tauCandidate->signalPFGammaCands().begin() ;signalTrack != tauCandidate->signalPFGammaCands().end(); ++signalTrack ) {
	 sumPt += (*signalTrack)->pt();
	 
       }
       
       if(tauCandidate->pt() > 0 ){ FillGammaFraction->Fill(sumPt/tauCandidate->pt()); }
       
     }   // tau collection ends here 
     //////////////////////////////////////////////////////////////////////////////////////////////////////////
     

     for(reco::GenJetCollection::const_iterator gentaujet = genTauJets->begin(); gentaujet !=  genTauJets->end(); ++gentaujet) { 
       
       if(gentaujet->pt() <= 20 ) continue;
       if(fabs(gentaujet->eta()) >= 2.3) continue;
       tauGenJetDecayModeInt = -999;
       std::string tauGenJetDecayMode = JetMCTagUtils::genTauDecayMode(*gentaujet);
       
       if(tauGenJetDecayMode=="muon") continue;
       if(tauGenJetDecayMode=="electron") continue;
       
       GenTauPt_Den->Fill(gentaujet->pt());
       GenTauEta_Den->Fill(gentaujet->eta());
       GenTauPhi_Den->Fill(gentaujet->phi());
  
       Nvtx_Den->Fill(vtx->size());
       NGood_Den->Fill(nGoodVtx);

       int index1= -1;
       if(OverlapWithGenTau(gentaujet->eta() ,gentaujet->phi() , _hpsTaucoll , _Newdmf, index1 )){
       if(index1 != -1){
       reco::PFTauRef tauCandidate(_hpsTaucoll, index1);

      if((tauCandidate->leadPFChargedHadrCand().isNonnull()) && (tauCandidate->leadPFChargedHadrCand()->p() > 0)) {
 FillHOverP_DMF->Fill(tauCandidate->leadPFChargedHadrCand()->hcalEnergy()/tauCandidate->leadPFChargedHadrCand()->p());
 FillEOverP_DMF->Fill(tauCandidate->leadPFChargedHadrCand()->ecalEnergy()/tauCandidate->leadPFChargedHadrCand()->p());

       }

       hFillTauHcal3x3OverPLead_DMF->Fill(tauCandidate->hcal3x3OverPLead());
       
       // photon fraction
       
       int sumPt = 0;
       for ( std::vector<PFCandidatePtr>::const_iterator signalTrack =  tauCandidate->signalPFGammaCands().begin() ;signalTrack != tauCandidate->signalPFGammaCands().end(); ++signalTrack ) {
 sumPt += (*signalTrack)->pt();
 
       }
       
       if(tauCandidate->pt() > 0 ){ FillGammaFraction_DMF->Fill(sumPt/tauCandidate->pt()); }
 
       //Fill Numerator histo
       GenTauPtWithDMF->Fill(gentaujet->pt());
       GenTauEtaWithDMF->Fill(gentaujet->eta());
       GenTauPhiWithDMF->Fill(gentaujet->phi());
       
       GenTauPiZeroCandidatesDMF->Fill(tauCandidate->signalPiZeroCandidates().size());
       GenTauHadronCandidatesDMF->Fill(tauCandidate->signalTauChargedHadronCandidates().size());

       int calculateDecayModeNew = -999;

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 1) && (tauCandidate->signalPiZeroCandidates().size() == 0))\
	 {calculateDecayModeNew =0 ;}
       if((tauCandidate->signalTauChargedHadronCandidates().size() == 1) && (tauCandidate->signalPiZeroCandidates().size() == 1))\
	 {calculateDecayModeNew =1 ;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 1) && (tauCandidate->signalPiZeroCandidates().size() == 2))\
	 {calculateDecayModeNew =2;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 2) && (tauCandidate->signalPiZeroCandidates().size() == 0))\
	 {calculateDecayModeNew =3;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 2) && (tauCandidate->signalPiZeroCandidates().size() == 1))\
	 {calculateDecayModeNew =4;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 2) && (tauCandidate->signalPiZeroCandidates().size() == 2))\
	 {calculateDecayModeNew =5;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 3) && (tauCandidate->signalPiZeroCandidates().size() == 0))\
	 {calculateDecayModeNew =6;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 3) && (tauCandidate->signalPiZeroCandidates().size() == 1))\
	 {calculateDecayModeNew =7;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 3) && (tauCandidate->signalPiZeroCandidates().size() == 2))\
	 {calculateDecayModeNew =8;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 4) && (tauCandidate->signalPiZeroCandidates().size() == 0))\
	 {calculateDecayModeNew =9;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 4) && (tauCandidate->signalPiZeroCandidates().size() == 1))\
	 {calculateDecayModeNew =10;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 4) && (tauCandidate->signalPiZeroCandidates().size() == 2))\
	 {calculateDecayModeNew =11;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 5) && (tauCandidate->signalPiZeroCandidates().size() == 0))\
	 {calculateDecayModeNew =12;}

       if((tauCandidate->signalTauChargedHadronCandidates().size() == 5) && (tauCandidate->signalPiZeroCandidates().size() == 1))\
	 {calculateDecayModeNew =13;}


       if( (tauCandidate->signalTauChargedHadronCandidates().size() == 5) && (tauCandidate->signalPiZeroCandidates().size() == 2)\
	   ) {calculateDecayModeNew =14;}

       if(tauCandidate->signalTauChargedHadronCandidates().size() >= 6) {calculateDecayModeNew =15;}

       hFillDecayMode->Fill(calculateDecayModeNew);
       hNeutralIsoPtSumWeight1_dmf->Fill((*_nw1)[tauCandidate] );
       hNeutralIsoPtSumWeight2_dmf->Fill((*_nw2)[tauCandidate] );
       hNeutralIsoPtSumWeight1NQ_dmf->Fill((*_nw1nq)[tauCandidate] );
       hNeutralIsoPtSumWeight2NQ_dmf->Fill((*_nw2nq)[tauCandidate] );
       hNeutralHadronIsoPtSum_dmf->Fill((*_h1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1_dmf->Fill((*_hw1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2_dmf->Fill((*_hw2)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1NQ_dmf->Fill((*_hw1nq)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2NQ_dmf->Fill((*_hw2nq)[tauCandidate] );
       hChargedIsoPtSum_dmf->Fill((*_rawc)[tauCandidate] );
       hNeutralIsoPtSum_dmf->Fill((*_rawn)[tauCandidate] );
       hPUcorrPtSum_dmf->Fill((*_rawpu)[tauCandidate] );

       hNeutralIsoPtSumWeight1_pt_dmf->Fill(gentaujet->pt(),(*_nw1)[tauCandidate] );
       hNeutralIsoPtSumWeight2_pt_dmf->Fill(gentaujet->pt(),(*_nw2)[tauCandidate] );
       hNeutralIsoPtSumWeight1NQ_pt_dmf->Fill(gentaujet->pt(),(*_nw1nq)[tauCandidate] );
       hNeutralIsoPtSumWeight2NQ_pt_dmf->Fill(gentaujet->pt(),(*_nw2nq)[tauCandidate] );
       hNeutralHadronIsoPtSum_pt_dmf->Fill(gentaujet->pt(),(*_h1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1_pt_dmf->Fill(gentaujet->pt(),(*_hw1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2_pt_dmf->Fill(gentaujet->pt(),(*_hw2)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1NQ_pt_dmf->Fill(gentaujet->pt(),(*_hw1nq)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2NQ_pt_dmf->Fill(gentaujet->pt(),(*_hw2nq)[tauCandidate] );
       hChargedIsoPtSum_pt_dmf->Fill(gentaujet->pt(),(*_rawc)[tauCandidate] );
       hNeutralIsoPtSum_pt_dmf->Fill(gentaujet->pt(),(*_rawn)[tauCandidate] );
       hPUcorrPtSum_pt_dmf->Fill(gentaujet->pt(),(*_rawpu)[tauCandidate] );


       hNeutralIsoPtSumWeight1_eta_dmf->Fill(gentaujet->eta(),(*_nw1)[tauCandidate] );
       hNeutralIsoPtSumWeight2_eta_dmf->Fill(gentaujet->eta(),(*_nw2)[tauCandidate] );
       hNeutralIsoPtSumWeight1NQ_eta_dmf->Fill(gentaujet->eta(),(*_nw1nq)[tauCandidate] );
       hNeutralIsoPtSumWeight2NQ_eta_dmf->Fill(gentaujet->eta(),(*_nw2nq)[tauCandidate] );
       hNeutralHadronIsoPtSum_eta_dmf->Fill(gentaujet->eta(),(*_h1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1_eta_dmf->Fill(gentaujet->eta(),(*_hw1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2_eta_dmf->Fill(gentaujet->eta(),(*_hw2)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1NQ_eta_dmf->Fill(gentaujet->eta(),(*_hw1nq)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2NQ_eta_dmf->Fill(gentaujet->eta(),(*_hw2nq)[tauCandidate] );
       hChargedIsoPtSum_eta_dmf->Fill(gentaujet->eta(),(*_rawc)[tauCandidate] );
       hNeutralIsoPtSum_eta_dmf->Fill(gentaujet->eta(),(*_rawn)[tauCandidate] );
       hPUcorrPtSum_eta_dmf->Fill(gentaujet->eta(),(*_rawpu)[tauCandidate] );

       hNeutralIsoPtSumWeight1_phi_dmf->Fill(gentaujet->phi(),(*_nw1)[tauCandidate] );
       hNeutralIsoPtSumWeight2_phi_dmf->Fill(gentaujet->phi(),(*_nw2)[tauCandidate] );
       hNeutralIsoPtSumWeight1NQ_phi_dmf->Fill(gentaujet->phi(),(*_nw1nq)[tauCandidate] );
       hNeutralIsoPtSumWeight2NQ_phi_dmf->Fill(gentaujet->phi(),(*_nw2nq)[tauCandidate] );
       hNeutralHadronIsoPtSum_phi_dmf->Fill(gentaujet->phi(),(*_h1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1_phi_dmf->Fill(gentaujet->phi(),(*_hw1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2_phi_dmf->Fill(gentaujet->phi(),(*_hw2)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1NQ_phi_dmf->Fill(gentaujet->phi(),(*_hw1nq)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2NQ_phi_dmf->Fill(gentaujet->phi(),(*_hw2nq)[tauCandidate] );
       hChargedIsoPtSum_phi_dmf->Fill(gentaujet->phi(),(*_rawc)[tauCandidate] );
       hNeutralIsoPtSum_phi_dmf->Fill(gentaujet->phi(),(*_rawn)[tauCandidate] );
       hPUcorrPtSum_phi_dmf->Fill(gentaujet->phi(),(*_rawpu)[tauCandidate] );

       hNeutralIsoPtSumWeight1_vtx_dmf->Fill(vtx->size(),(*_nw1)[tauCandidate] );
       hNeutralIsoPtSumWeight2_vtx_dmf->Fill(vtx->size(),(*_nw2)[tauCandidate] );
       hNeutralIsoPtSumWeight1NQ_vtx_dmf->Fill(vtx->size(),(*_nw1nq)[tauCandidate] );
       hNeutralIsoPtSumWeight2NQ_vtx_dmf->Fill(vtx->size(),(*_nw2nq)[tauCandidate] );
       hNeutralHadronIsoPtSum_vtx_dmf->Fill(vtx->size(),(*_h1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1_vtx_dmf->Fill(vtx->size(),(*_hw1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2_vtx_dmf->Fill(vtx->size(),(*_hw2)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf->Fill(vtx->size(),(*_hw1nq)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf->Fill(vtx->size(),(*_hw2nq)[tauCandidate] );
       hChargedIsoPtSum_vtx_dmf->Fill(vtx->size(),(*_rawc)[tauCandidate] );
       hNeutralIsoPtSum_vtx_dmf->Fill(vtx->size(),(*_rawn)[tauCandidate] );
       hPUcorrPtSum_vtx_dmf->Fill(vtx->size(),(*_rawpu)[tauCandidate] );

       hNeutralIsoPtSumWeight1_nGoodVtx_dmf->Fill(nGoodVtx,(*_nw1)[tauCandidate] );
       hNeutralIsoPtSumWeight2_nGoodVtx_dmf->Fill(nGoodVtx,(*_nw2)[tauCandidate] );
       hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf->Fill(nGoodVtx,(*_nw1nq)[tauCandidate] );
       hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf->Fill(nGoodVtx,(*_nw2nq)[tauCandidate] );
       hNeutralHadronIsoPtSum_nGoodVtx_dmf->Fill(nGoodVtx,(*_h1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf->Fill(nGoodVtx,(*_hw1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf->Fill(nGoodVtx,(*_hw2)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf->Fill(nGoodVtx,(*_hw1nq)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf->Fill(nGoodVtx,(*_hw2nq)[tauCandidate] );
       hChargedIsoPtSum_nGoodVtx_dmf->Fill(nGoodVtx,(*_rawc)[tauCandidate] );
       hNeutralIsoPtSum_nGoodVtx_dmf->Fill(nGoodVtx,(*_rawn)[tauCandidate] );
       hPUcorrPtSum_nGoodVtx_dmf->Fill(nGoodVtx,(*_rawpu)[tauCandidate] );



       if(tauGenJetDecayMode=="oneProng0Pi0") { tauGenJetDecayModeInt=0; }

       if(tauGenJetDecayMode=="oneProng1Pi0") { tauGenJetDecayModeInt=1; }

       if(tauGenJetDecayMode=="oneProng2Pi0") {  tauGenJetDecayModeInt=2; }

       if(tauGenJetDecayMode=="threeProng0Pi0") { tauGenJetDecayModeInt=10; }

       if(tauGenJetDecayMode=="threeProng1Pi0") { tauGenJetDecayModeInt=11;}

       if(gentaujet->pt() != 0) {
	 TauPtResponse_DM->Fill(tauCandidate->pt()/gentaujet->pt());
	 TES_DM->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
       }

       RecoTauDecayMode_DM->Fill(tauCandidate->decayMode());
       GenTauDecayMode_DM->Fill(tauGenJetDecayModeInt);
       reco_dm_vs_gen_dm->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
       Nvtx_DM->Fill(vtx->size());
       NGood_DM->Fill(nGoodVtx);
       
       /// other definitions


       double iso = (((*_rawc)[tauCandidate]) + ((*_nw2nq)[tauCandidate]));

       // isolation first option                                                                                                    


       if(iso < 1) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_Iso1->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_Iso1->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_Iso1->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_Iso1->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_Iso1->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 GenTauPtWithDMF_Iso1->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_Iso1->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_Iso1->Fill(gentaujet->phi());
	 Nvtx_Iso1->Fill(vtx->size());
	 NGood_Iso1->Fill(nGoodVtx);
      
       }


       if(iso < 2) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_Iso2->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_Iso2->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_Iso2->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_Iso2->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_Iso2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_Iso2->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_Iso2->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_Iso2->Fill(gentaujet->phi());
	 Nvtx_Iso2->Fill(vtx->size());
	 NGood_Iso2->Fill(nGoodVtx);
      
       }

       if(iso < 4) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_Iso4->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_Iso4->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_Iso4->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_Iso4->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_Iso4->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_Iso4->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_Iso4->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_Iso4->Fill(gentaujet->phi());
	 Nvtx_Iso4->Fill(vtx->size());
         NGood_Iso4->Fill(nGoodVtx);

       }


       if((*_rawc)[tauCandidate] < 4) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_LIsoPtSum->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_LIsoPtSum->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
 }
	 
	 RecoTauDecayMode_LIsoPtSum->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_LIsoPtSum->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_LIsoPtSum->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
 
	 GenTauPtWithDMF_LIsoPtSum->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_LIsoPtSum->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_LIsoPtSum->Fill(gentaujet->phi());
	 Nvtx_LIsoPtSum->Fill(vtx->size());
	 NGood_LIsoPtSum->Fill(nGoodVtx);
       }
       
       
       if((*_rawc)[tauCandidate] < 2) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MIsoPtSum->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_MIsoPtSum->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_MIsoPtSum->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MIsoPtSum->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_MIsoPtSum->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_MIsoPtSum->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MIsoPtSum->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MIsoPtSum->Fill(gentaujet->phi());
	 Nvtx_MIsoPtSum->Fill(vtx->size());
	 NGood_MIsoPtSum->Fill(nGoodVtx);
       }


       //

       if((*_isowLTloose)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_wLTloose->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_wLTloose->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_wLTloose->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_wLTloose->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_wLTloose->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_wLTloose->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_wLTloose->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_wLTloose->Fill(gentaujet->phi());
	 Nvtx_wLTloose->Fill(vtx->size());
	 NGood_wLTloose->Fill(nGoodVtx);
       }


       ///     


       if((*_isowLTvloose)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_wLTvloose->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_wLTvloose->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_wLTvloose->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_wLTvloose->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_wLTvloose->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_wLTvloose->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_wLTvloose->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_wLTvloose->Fill(gentaujet->phi());
	 Nvtx_wLTvloose->Fill(vtx->size());
	 NGood_wLTvloose->Fill(nGoodVtx);
       }


       ///     

       if((*_isowLTmedium)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_wLTmedium->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_wLTmedium->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_wLTmedium->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_wLTmedium->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_wLTmedium->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_wLTmedium->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_wLTmedium->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_wLTmedium->Fill(gentaujet->phi());
	 Nvtx_wLTmedium->Fill(vtx->size());
	 NGood_wLTmedium->Fill(nGoodVtx);
       }


       ///     
       if((*_isowLTtight)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_wLTtight->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_wLTtight->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_wLTtight->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_wLTtight->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_wLTtight->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_wLTtight->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_wLTtight->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_wLTtight->Fill(gentaujet->phi());
	 Nvtx_wLTtight->Fill(vtx->size());
	 NGood_wLTtight->Fill(nGoodVtx);
       }


       if((*_isowLTvtight)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_wLTvtight->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_wLTvtight->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_wLTvtight->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_wLTvtight->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_wLTvtight->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_wLTvtight->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_wLTvtight->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_wLTvtight->Fill(gentaujet->phi());
	 Nvtx_wLTvtight->Fill(vtx->size());
	 NGood_wLTvtight->Fill(nGoodVtx);
       }


       if((*_isowLTvvtight)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_wLTvvtight->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_wLTvvtight->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_wLTvvtight->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_wLTvvtight->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_wLTvvtight->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_wLTvvtight->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_wLTvvtight->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_wLTvvtight->Fill(gentaujet->phi());
	 Nvtx_wLTvvtight->Fill(vtx->size());
	 NGood_wLTvvtight->Fill(nGoodVtx);
       }


       ///     



       /// woLT


       if((*_isowoLTloose)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_woLTloose->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_woLTloose->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_woLTloose->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_woLTloose->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_woLTloose->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_woLTloose->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_woLTloose->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_woLTloose->Fill(gentaujet->phi());
	 Nvtx_woLTloose->Fill(vtx->size());
	 NGood_woLTloose->Fill(nGoodVtx);
       }


       ///     


       if((*_isowoLTvloose)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_woLTvloose->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_woLTvloose->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_woLTvloose->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_woLTvloose->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_woLTvloose->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_woLTvloose->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_woLTvloose->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_woLTvloose->Fill(gentaujet->phi());
	 Nvtx_woLTvloose->Fill(vtx->size());
	 NGood_woLTvloose->Fill(nGoodVtx);
       }


       ///     

       if((*_isowoLTmedium)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_woLTmedium->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_woLTmedium->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_woLTmedium->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_woLTmedium->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_woLTmedium->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_woLTmedium->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_woLTmedium->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_woLTmedium->Fill(gentaujet->phi());
	 Nvtx_woLTmedium->Fill(vtx->size());
	 NGood_woLTmedium->Fill(nGoodVtx);
       }


       ///     
       if((*_isowoLTtight)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_woLTtight->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_woLTtight->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_woLTtight->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_woLTtight->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_woLTtight->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_woLTtight->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_woLTtight->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_woLTtight->Fill(gentaujet->phi());
	 Nvtx_woLTtight->Fill(vtx->size());
	 NGood_woLTtight->Fill(nGoodVtx);
       }


       if((*_isowoLTvtight)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_woLTvtight->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_woLTvtight->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_woLTvtight->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_woLTvtight->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_woLTvtight->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_woLTvtight->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_woLTvtight->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_woLTvtight->Fill(gentaujet->phi());
	 Nvtx_woLTvtight->Fill(vtx->size());
	 NGood_woLTvtight->Fill(nGoodVtx);
       }


       if((*_isowoLTvvtight)[tauCandidate] > 0.5) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_woLTvvtight->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_woLTvvtight->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_woLTvvtight->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_woLTvvtight->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_woLTvvtight->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_woLTvvtight->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_woLTvvtight->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_woLTvvtight->Fill(gentaujet->phi());
	 Nvtx_woLTvvtight->Fill(vtx->size());
	 NGood_woLTvvtight->Fill(nGoodVtx);
       }


       ///     

       ///     

       ///     


if(((*_enew)[tauCandidate] > 0.5 ) && ((*_mv31)[tauCandidate] > 0.5 ) && (*_rawc)[tauCandidate] < 2) {

if(gentaujet->pt() != 0) {
 TauPtResponse_Combined->Fill(tauCandidate->pt()/gentaujet->pt());
 TES_Combined->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
}

RecoTauDecayMode_Combined->Fill(tauCandidate->decayMode());
GenTauDecayMode_Combined->Fill(tauGenJetDecayModeInt);
reco_dm_vs_gen_Combined->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
GenTauPtWithDMF_Combined->Fill(gentaujet->pt());
GenTauEtaWithDMF_Combined->Fill(gentaujet->eta());
GenTauPhiWithDMF_Combined->Fill(gentaujet->phi());
Nvtx_Combined->Fill(vtx->size());
 NGood_Combined->Fill(nGoodVtx);

}
       if((*_rawc)[tauCandidate] < 1) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_TIsoPtSum->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_TIsoPtSum->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_TIsoPtSum->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_TIsoPtSum->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_TIsoPtSum->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_TIsoPtSum->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_TIsoPtSum->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_TIsoPtSum->Fill(gentaujet->phi());
	 Nvtx_TIsoPtSum->Fill(vtx->size());
	 NGood_TIsoPtSum->Fill(nGoodVtx);
       }
       


       if((*_mv1)[tauCandidate] > 0.5) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_ML2->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_ML2->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_ML2->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_ML2->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_ML2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_ML2->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_ML2->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_ML2->Fill(gentaujet->phi());
	 Nvtx_ML2->Fill(vtx->size());
         NGood_ML2->Fill(nGoodVtx);

       }


       if((*_mv2)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MM2->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_MM2->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_MM2->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MM2->Fill(tauGenJetDecayModeInt);

	 reco_dm_vs_gen_MM2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_MM2->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MM2->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MM2->Fill(gentaujet->phi());

	 Nvtx_MM2->Fill(vtx->size());
         NGood_MM2->Fill(nGoodVtx);

       }


       if((*_mv3)[tauCandidate] > 0.5) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MT2->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_MT2->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }
	 //       std::cout<<"Debug6:"<<std::endl;                                                                                       


	 RecoTauDecayMode_MT2->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MT2->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_MT2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 GenTauPtWithDMF_MT2->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MT2->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MT2->Fill(gentaujet->phi());
	 Nvtx_MT2->Fill(vtx->size());
         NGood_MT2->Fill(nGoodVtx);

       }

       if((*_mv31)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_ML3->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_ML3->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_ML3->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_ML3->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_ML3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_ML3->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_ML3->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_ML3->Fill(gentaujet->phi());
	 Nvtx_ML3->Fill(vtx->size());
         NGood_ML3->Fill(nGoodVtx);


       }

       if((*_mv32)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MT3->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_MT3->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_MT3->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MT3->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_MT3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_MT3->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MT3->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MT3->Fill(gentaujet->phi());
	 Nvtx_MT3->Fill(vtx->size());
         NGood_MT3->Fill(nGoodVtx);

       }
       if((*_enew)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_Cut->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_Cut->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_Cut->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_Cut->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_Cut->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_Cut->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_Cut->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_Cut->Fill(gentaujet->phi());
	 Nvtx_Cut->Fill(vtx->size());
         NGood_Cut->Fill(nGoodVtx);

       }

       if((*_ev1)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_EL3->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_EL3->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_EL3->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_EL3->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_EL3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_EL3->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_EL3->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_EL3->Fill(gentaujet->phi());
	 Nvtx_EL3->Fill(vtx->size());
         NGood_EL3->Fill(nGoodVtx);

       }

       if((*_ev2)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_EM3->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_EM3->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_EM3->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_EM3->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_EM3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_EM3->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_EM3->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_EM3->Fill(gentaujet->phi());
	 Nvtx_EM3->Fill(vtx->size());
         NGood_EM3->Fill(nGoodVtx);

       }

       if((*_ev3)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_ET3->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_ET3->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_ET3->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_ET3->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_ET3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 GenTauPtWithDMF_ET3->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_ET3->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_ET3->Fill(gentaujet->phi());
	 Nvtx_ET3->Fill(vtx->size());
         NGood_ET3->Fill(nGoodVtx);

       }

       if((*_iso4)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_LIso3Hits->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_LIso3Hits->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_LIso3Hits->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_LIso3Hits->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_LIso3Hits->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_LIso3Hits->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_LIso3Hits->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_LIso3Hits->Fill(gentaujet->phi());
	 Nvtx_LIso3Hits->Fill(vtx->size());
         NGood_LIso3Hits->Fill(nGoodVtx);


       }

       if((*_iso5)[tauCandidate] > 0.5) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MIso3Hits->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_MIso3Hits->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_MIso3Hits->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MIso3Hits->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_MIso3Hits->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_MIso3Hits->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MIso3Hits->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MIso3Hits->Fill(gentaujet->phi());
	 Nvtx_MIso3Hits->Fill(vtx->size());
         NGood_MIso3Hits->Fill(nGoodVtx);

       }

       if((*_iso6)[tauCandidate] > 0.5) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_TIso3Hits->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_TIso3Hits->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_TIso3Hits->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_TIso3Hits->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_TIso3Hits->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_TIso3Hits->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_TIso3Hits->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_TIso3Hits->Fill(gentaujet->phi());
	 Nvtx_TIso3Hits->Fill(vtx->size());
         NGood_TIso3Hits->Fill(nGoodVtx);

       }

       if((*_iso1)[tauCandidate] > 0.5) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_LIso->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_LIso->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_LIso->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_LIso->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_LIso->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_LIso->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_LIso->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_LIso->Fill(gentaujet->phi());
	 Nvtx_LIso->Fill(vtx->size());
         NGood_LIso->Fill(nGoodVtx);

       }

       if((*_iso2)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MIso->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_MIso->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_MIso->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MIso->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_MIso->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_MIso->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MIso->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MIso->Fill(gentaujet->phi());
	 Nvtx_MIso->Fill(vtx->size());
         NGood_MIso->Fill(nGoodVtx);

       }

       if((*_iso3)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_TIso->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_TIso->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());


	 }

	 RecoTauDecayMode_TIso->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_TIso->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_TIso->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_TIso->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_TIso->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_TIso->Fill(gentaujet->phi());
	 Nvtx_TIso->Fill(vtx->size());
	 NGood_TIso->Fill(nGoodVtx);

       }

       if((*_hpsTau)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_VLChar->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_VLChar->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_VLChar->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_VLChar->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_VLChar->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_VLChar->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_VLChar->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_VLChar->Fill(gentaujet->phi());
	 Nvtx_VLChar->Fill(vtx->size());
         NGood_VLChar->Fill(nGoodVtx);


       }

       if((*_hpsTau1)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_LChar->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_LChar->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_LChar->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_LChar->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_LChar->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());


	 GenTauPtWithDMF_LChar->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_LChar->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_LChar->Fill(gentaujet->phi());
	 Nvtx_LChar->Fill(vtx->size());
         NGood_LChar->Fill(nGoodVtx);

       }

       if((*_hpsTau2)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MChar->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_MChar->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_MChar->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MChar->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_MChar->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());


	 GenTauPtWithDMF_MChar->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MChar->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MChar->Fill(gentaujet->phi());
	 Nvtx_MChar->Fill(vtx->size());
         NGood_MChar->Fill(nGoodVtx);
       }

       if((*rho1)[tauCandidate] > 0.5) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_LooseRho->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_LooseRho->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_LooseRho->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_LooseRho->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_LooseRho->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_LooseRho->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_LooseRho->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_LooseRho->Fill(gentaujet->phi());
	 Nvtx_LooseRho->Fill(vtx->size());
         NGood_LooseRho->Fill(nGoodVtx);
       }
       if((*rho2)[tauCandidate] > 0.5) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MediumRho->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_MediumRho->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_MediumRho->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MediumRho->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_MediumRho->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_MediumRho->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MediumRho->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MediumRho->Fill(gentaujet->phi());
	 Nvtx_MediumRho->Fill(vtx->size());
         NGood_MediumRho->Fill(nGoodVtx);

       }


       if((*rho3)[tauCandidate] > 0.5) {
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_TightRho->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_TightRho->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_TightRho->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_TightRho->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_TightRho->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_TightRho->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_TightRho->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_TightRho->Fill(gentaujet->phi());
	 Nvtx_TightRho->Fill(vtx->size());
         NGood_TightRho->Fill(nGoodVtx);

       }


       if((*_hpsTau3)[tauCandidate] > 0.5) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_TChar->Fill(tauCandidate->pt()/gentaujet->pt());
           TES_TChar->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());

	 }

	 RecoTauDecayMode_TChar->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_TChar->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_TChar->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());

	 GenTauPtWithDMF_TChar->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_TChar->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_TChar->Fill(gentaujet->phi());
	 Nvtx_TChar->Fill(vtx->size());
         NGood_TChar->Fill(nGoodVtx);

       }


       }
       }


       }
 
   }
   }


     
  



// ------------ method called once each job just before starting event loop  ------------
bool TauIDUpto23New::OverlapWithGenTau(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc, int &index ) {
   double drtmp = _TauToGenMatchingDeltaR;
   bool genTaufound = false;
   index = -1;
   for ( unsigned iTau = 0; iTau < taujetcol->size(); ++iTau ) {
     reco::PFTauRef tauCandidate(taujetcol,iTau);
     if(tauCandidate->pt() <= 20) continue;
     if(fabs(tauCandidate->eta()) >= 2.3) continue;
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


bool TauIDUpto23New::OverlapWithGenTauForOther(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc, edm::Handle<reco::PFTauDiscriminator>  disc1 ,int &index ) {
   double drtmp = _TauToGenMatchingDeltaR;
   bool genTaufound = false;
   index = -1;
   for ( unsigned iTau = 0; iTau < taujetcol->size(); ++iTau ) {
     reco::PFTauRef tauCandidate(taujetcol,iTau);
     if(tauCandidate->pt() <= 20) continue;
     if(fabs(tauCandidate->eta()) >= 2.3) continue;
     if((*disc)[tauCandidate] > 0.5) {
       if((*disc1)[tauCandidate] > 0.5) {

       double dr =reco::deltaR(Taueta, Tauphi,tauCandidate->eta(),tauCandidate->phi());
       if(dr < drtmp){
	 drtmp = dr;
	 index = iTau;
	 genTaufound= true;
       }
     }
     }
   }
   return genTaufound;
 }

bool TauIDUpto23New::IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles){
   bool isZTauTau = false;
  reco::GenParticleCollection::const_iterator particle;
  for (particle = genParticles->begin(); particle != genParticles->end();  particle++) {
    if ((abs(particle->pdgId()) == _TauMotherId)) {
//      std::cout<<" Z found with pdgid = "<<particle->numberOfDaughters()<<std::endl;
      int daughters  = particle->numberOfDaughters();
       for (int j = 0; j<daughters; ++j) {
        const reco::Candidate *daughter = particle->daughter(j);
         int pidg = std::abs(daughter->pdgId());
         if (pidg == 15) {
           isZTauTau = true;
//           std::cout<<"working inside function"<<std::endl;
           break;
        }
      }
    }
  }
  return isZTauTau;  
}

