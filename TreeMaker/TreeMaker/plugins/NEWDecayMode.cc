
#include "./NEWDecayMode.h"                                                                                                                                        


NEWDecayMode::NEWDecayMode(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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
  
  etacut = iConfig.getParameter<double>("etacut"); 
  etacutmin = iConfig.getParameter<double>("etacutmin");  
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
  
  
  GenTauPt_Den  = fs->make<TH1F>(("GenTauPt_Den"+prefix).c_str() ,"GenTauPt_Den" ,100,0,700);
  GenTauEta_Den  = fs->make<TH1F>(("GenTauEta_Den"+prefix).c_str() ,"GenTauEta_Den" ,100,-5,5);
  GenTauPhi_Den   = fs->make<TH1F>(("GenTauPhi_Den"+prefix).c_str() ,"GenTauPhi_Den" ,100,-5,5);
 
 
  GenTauPtWithDMF = fs->make<TH1F>(("GenTauPtWithDMF"+prefix).c_str() ,"GenTauPtWithDMF",100,0,700);
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


  hNeutralIsoPtSumWeight1_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_vtx_dmf",700,0,700,0,400); 
  hNeutralIsoPtSumWeight2_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_vtx_dmf",700,0,700,0,400); 
  hNeutralIsoPtSumWeight1NQ_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_vtx_dmf",700,0,700,0,400); 
  hNeutralIsoPtSumWeight2NQ_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_vtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_vtx_dmf",700,0,700,0,400); 
  hNeutralHadronIsoPtSum_vtx_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_vtx_dmf",700,0,700,0,400);
  hNeutralHadronIsoPtSumWeight1_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_vtx_dmf",700,0,700,0,400);
  hNeutralHadronIsoPtSumWeight2_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_vtx_dmf",700,0,700,0,400);
  hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf",700,0,700,0,400);
  hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf",700,0,700,0,400);
  hChargedIsoPtSum_vtx_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_vtx_dmf"+prefix).c_str(),"hChargedIsoPtSum_vtx_dmf",700,0,700,0,400); 
  hNeutralIsoPtSum_vtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_vtx_dmf"+prefix).c_str(),"hNeutralIsoPtSum_vtx_dmf",700,0,700,0,400);
  hPUcorrPtSum_vtx_dmf = fs->make<TProfile>(("hPUcorrPtSum_vtx_dmf"+prefix).c_str(),"hPUcorrPtSum_vtx_dmf",700,0,700,0,400);

hNeutralIsoPtSumWeight1_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1_nGoodVtx_dmf",700,0,700,0,400); 
  hNeutralIsoPtSumWeight2_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2_nGoodVtx_dmf",700,0,700,0,400); 
  hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight1NQ_nGoodVtx_dmf",700,0,700,0,400); 
  hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralIsoPtSumWeight2NQ_nGoodVtx_dmf",700,0,700,0,400); 
  hNeutralHadronIsoPtSum_nGoodVtx_dmf  = fs->make<TProfile>(("hNeutralHadronIsoPtSum_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSum_nGoodVtx_dmf",700,0,700,0,400);
  hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1_nGoodVtx_dmf",700,0,700,0,400);
  hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2_nGoodVtx_dmf",700,0,700,0,400);
  hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight1NQ_nGoodVtx_dmf",700,0,700,0,400);
  hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf"+prefix).c_str() ,"hNeutralHadronIsoPtSumWeight2NQ_nGoodVtx_dmf",700,0,700,0,400);
  hChargedIsoPtSum_nGoodVtx_dmf  = fs->make<TProfile>(("hChargedIsoPtSum_nGoodVtx_dmf"+prefix).c_str(),"hChargedIsoPtSum_nGoodVtx_dmf",700,0,700,0,400); 
  hNeutralIsoPtSum_nGoodVtx_dmf = fs->make<TProfile>(("hNeutralIsoPtSum_nGoodVtx_dmf"+prefix).c_str(),"hNeutralIsoPtSum_nGoodVtx_dmf",700,0,700,0,400);
  hPUcorrPtSum_nGoodVtx_dmf = fs->make<TProfile>(("hPUcorrPtSum_nGoodVtx_dmf"+prefix).c_str(),"hPUcorrPtSum_nGoodVtx_dmf",700,0,700,0,400);


  Nvtx_Den = fs->make<TH1F>(("Nvtx_Den"+prefix).c_str() ,"Nvtx_Den",700,0,700);
  NGood_Den = fs->make<TH1F>(("NGood_Den"+prefix).c_str() ,"NGood_Den",700,0,700);
  
  TES_DM = fs->make<TProfile>(("TES_DM"+prefix).c_str(),"TES_DM",100,0,700,0,50);
  Nvtx_DM = fs->make<TH1F>(("Nvtx_DM"+prefix).c_str() ,"Nvtx_DM",700,0,700);
  NGood_DM = fs->make<TH1F>(("NGood_DM"+prefix).c_str() ,"NGood_DM",700,0,700);

  TES_ML2 = fs->make<TProfile>(("TES_ML2"+prefix).c_str(),"TES_ML2",100,0,700,0,50);
  Nvtx_ML2 = fs->make<TH1F>(("Nvtx_ML2"+prefix).c_str() ,"Nvtx_ML2",700,0,700);
  NGood_ML2 = fs->make<TH1F>(("NGood_ML2"+prefix).c_str() ,"NGood_ML2",700,0,700);

  TES_MM2 = fs->make<TProfile>(("TES_MM2"+prefix).c_str(),"TES_MM2",100,0,700,0,50);
  Nvtx_MM2 = fs->make<TH1F>(("Nvtx_MM2"+prefix).c_str() ,"Nvtx_MM2",700,0,700);
  NGood_MM2 = fs->make<TH1F>(("NGood_MM2"+prefix).c_str() ,"NGood_MM2",700,0,700);

  TES_MT2 = fs->make<TProfile>(("TES_MT2"+prefix).c_str(),"TES_MT2",100,0,700,0,50);
  Nvtx_MT2 = fs->make<TH1F>(("Nvtx_MT2"+prefix).c_str() ,"Nvtx_MT2",700,0,700);
  NGood_MT2 = fs->make<TH1F>(("NGood_MT2"+prefix).c_str() ,"NGood_MT2",700,0,700);

  TES_ML3 = fs->make<TProfile>(("TES_ML3"+prefix).c_str(),"TES_ML3",100,0,700,0,50);
  Nvtx_ML3 = fs->make<TH1F>(("Nvtx_ML3"+prefix).c_str() ,"Nvtx_ML3",700,0,700);
  NGood_ML3 = fs->make<TH1F>(("NGood_ML3"+prefix).c_str() ,"NGood_ML3",700,0,700);

  TES_MT3 = fs->make<TProfile>(("TES_MT3"+prefix).c_str(),"TES_MT3",100,0,700,0,50);
  Nvtx_MT3 = fs->make<TH1F>(("Nvtx_MT3"+prefix).c_str() ,"Nvtx_MT3",700,0,700);
  NGood_MT3 = fs->make<TH1F>(("NGood_MT3"+prefix).c_str() ,"NGood_MT3",700,0,700);


  TES_Iso1 = fs->make<TProfile>(("TES_Iso1"+prefix).c_str(),"TES_Iso1",100,0,700,0,50);
  Nvtx_Iso1 = fs->make<TH1F>(("Nvtx_Iso1"+prefix).c_str() ,"Nvtx_Iso1",700,0,700);
  NGood_Iso1 = fs->make<TH1F>(("NGood_Iso1"+prefix).c_str() ,"NGood_Iso1",700,0,700);

  TES_Iso2 = fs->make<TProfile>(("TES_Iso2"+prefix).c_str(),"TES_Iso2",100,0,700,0,50);
  Nvtx_Iso2 = fs->make<TH1F>(("Nvtx_Iso2"+prefix).c_str() ,"Nvtx_Iso2",700,0,700);
  NGood_Iso2 = fs->make<TH1F>(("NGood_Iso2"+prefix).c_str() ,"NGood_Iso2",700,0,700);

  TES_Iso4 = fs->make<TProfile>(("TES_Iso4"+prefix).c_str(),"TES_Iso4",100,0,700,0,50);
  Nvtx_Iso4 = fs->make<TH1F>(("Nvtx_Iso4"+prefix).c_str() ,"Nvtx_Iso4",700,0,700);
  NGood_Iso4 = fs->make<TH1F>(("NGood_Iso4"+prefix).c_str() ,"NGood_Iso4",700,0,700);

  TES_Cut = fs->make<TProfile>(("TES_Cut"+prefix).c_str(),"TES_Cut",100,0,700,0,50);
  Nvtx_Cut = fs->make<TH1F>(("Nvtx_Cut"+prefix).c_str() ,"Nvtx_Cut",700,0,700);
  NGood_Cut = fs->make<TH1F>(("NGood_Cut"+prefix).c_str() ,"NGood_Cut",700,0,700);
  //seee
  TES_EL3 = fs->make<TProfile>(("TES_EL3"+prefix).c_str(),"TES_EL3",100,0,700,0,50);
  Nvtx_EL3 = fs->make<TH1F>(("Nvtx_EL3"+prefix).c_str() ,"Nvtx_EL3",700,0,700);
  NGood_EL3 = fs->make<TH1F>(("NGood_EL3"+prefix).c_str() ,"NGood_EL3",700,0,700);

  TES_EM3 = fs->make<TProfile>(("TES_EM3"+prefix).c_str(),"TES_EM3",100,0,700,0,50);
  Nvtx_EM3 = fs->make<TH1F>(("Nvtx_EM3"+prefix).c_str() ,"Nvtx_EM3",700,0,700);
  NGood_EM3 = fs->make<TH1F>(("NGood_EM3"+prefix).c_str() ,"NGood_EM3",700,0,700);

  TES_ET3 = fs->make<TProfile>(("TES_ET3"+prefix).c_str(),"TES_ET3",100,0,700,0,50);
  Nvtx_ET3 = fs->make<TH1F>(("Nvtx_ET3"+prefix).c_str() ,"Nvtx_ET3",700,0,700);
  NGood_ET3 = fs->make<TH1F>(("NGood_ET3"+prefix).c_str() ,"NGood_ET3",700,0,700);


  TES_VLChar = fs->make<TProfile>(("TES_VLChar"+prefix).c_str(),"TES_VLChar",100,0,700,0,50);
  Nvtx_VLChar = fs->make<TH1F>(("Nvtx_VLChar"+prefix).c_str() ,"Nvtx_VLChar",700,0,700);
  NGood_VLChar = fs->make<TH1F>(("NGood_VLChar"+prefix).c_str() ,"NGood_VLChar",700,0,700);

  TES_LChar = fs->make<TProfile>(("TES_LChar"+prefix).c_str(),"TES_LChar",100,0,700,0,50);
  Nvtx_LChar = fs->make<TH1F>(("Nvtx_LChar"+prefix).c_str() ,"Nvtx_LChar",700,0,700);
  NGood_LChar = fs->make<TH1F>(("NGood_LChar"+prefix).c_str() ,"NGood_LChar",700,0,700);

  TES_MChar = fs->make<TProfile>(("TES_MChar"+prefix).c_str(),"TES_MChar",100,0,700,0,50);
  Nvtx_MChar = fs->make<TH1F>(("Nvtx_MChar"+prefix).c_str() ,"Nvtx_MChar",700,0,700);
  NGood_MChar = fs->make<TH1F>(("NGood_MChar"+prefix).c_str() ,"NGood_MChar",700,0,700);

  TES_TChar = fs->make<TProfile>(("TES_TChar"+prefix).c_str(),"TES_TChar",100,0,700,0,50);
  Nvtx_TChar = fs->make<TH1F>(("Nvtx_TChar"+prefix).c_str() ,"Nvtx_TChar",700,0,700);
  NGood_TChar = fs->make<TH1F>(("NGood_TChar"+prefix).c_str() ,"NGood_TChar",700,0,700);

  TES_LIso = fs->make<TProfile>(("TES_LIso"+prefix).c_str(),"TES_LIso",100,0,700,0,50);
  Nvtx_LIso = fs->make<TH1F>(("Nvtx_LIso"+prefix).c_str() ,"Nvtx_LIso",700,0,700);
  NGood_LIso = fs->make<TH1F>(("NGood_LIso"+prefix).c_str() ,"NGood_LIso",700,0,700);


  TES_MIso = fs->make<TProfile>(("TES_MIso"+prefix).c_str(),"TES_MIso",100,0,700,0,50);
  Nvtx_MIso = fs->make<TH1F>(("Nvtx_MIso"+prefix).c_str() ,"Nvtx_MIso",700,0,700);
  NGood_MIso = fs->make<TH1F>(("NGood_MIso"+prefix).c_str() ,"NGood_MIso",700,0,700);

  TES_TIso = fs->make<TProfile>(("TES_TIso"+prefix).c_str(),"TES_TIso",100,0,700,0,50);
  Nvtx_TIso = fs->make<TH1F>(("Nvtx_TIso"+prefix).c_str() ,"Nvtx_TIso",700,0,700);
  NGood_TIso = fs->make<TH1F>(("NGood_TIso"+prefix).c_str() ,"NGood_TIso",700,0,700);


  TES_LIso3Hits = fs->make<TProfile>(("TES_LIso3Hits"+prefix).c_str(),"TES_LIso3Hits",100,0,700,0,50);
  Nvtx_LIso3Hits = fs->make<TH1F>(("Nvtx_LIso3Hits"+prefix).c_str() ,"Nvtx_LIso3Hits",700,0,700);
  NGood_LIso3Hits = fs->make<TH1F>(("NGood_LIso3Hits"+prefix).c_str() ,"NGood_LIso3Hits",700,0,700);


  TES_MIso3Hits = fs->make<TProfile>(("TES_MIso3Hits"+prefix).c_str(),"TES_MIso3Hits",100,0,700,0,50);
  Nvtx_MIso3Hits = fs->make<TH1F>(("Nvtx_MIso3Hits"+prefix).c_str() ,"Nvtx_MIso3Hits",700,0,700);
  NGood_MIso3Hits = fs->make<TH1F>(("NGood_MIso3Hits"+prefix).c_str() ,"NGood_MIso3Hits",700,0,700);

  TES_TIso3Hits = fs->make<TProfile>(("TES_TIso3Hits"+prefix).c_str(),"TES_TIso3Hits",100,0,700,0,50);
  Nvtx_TIso3Hits = fs->make<TH1F>(("Nvtx_TIso3Hits"+prefix).c_str() ,"Nvtx_TIso3Hits",700,0,700);
  NGood_TIso3Hits = fs->make<TH1F>(("NGood_TIso3Hits"+prefix).c_str() ,"NGood_TIso3Hits",700,0,700);


  TES_LooseRho = fs->make<TProfile>(("TES_LooseRho"+prefix).c_str(),"TES_LooseRho",100,0,700,0,50);
  Nvtx_LooseRho = fs->make<TH1F>(("Nvtx_LooseRho"+prefix).c_str() ,"Nvtx_LooseRho",700,0,700);
  NGood_LooseRho = fs->make<TH1F>(("NGood_LooseRho"+prefix).c_str() ,"NGood_LooseRho",700,0,700);

  TES_MediumRho = fs->make<TProfile>(("TES_MediumRho"+prefix).c_str(),"TES_MediumRho",100,0,700,0,50);
  Nvtx_MediumRho = fs->make<TH1F>(("Nvtx_MediumRho"+prefix).c_str() ,"Nvtx_MediumRho",700,0,700);
  NGood_MediumRho = fs->make<TH1F>(("NGood_MediumRho"+prefix).c_str() ,"NGood_MediumRho",700,0,700);

  
  TES_TightRho = fs->make<TProfile>(("TES_TightRho"+prefix).c_str(),"TES_TightRho",100,0,700,0,50);
  Nvtx_TightRho = fs->make<TH1F>(("Nvtx_TightRho"+prefix).c_str() ,"Nvtx_TightRho",700,0,700);
  NGood_TightRho = fs->make<TH1F>(("NGood_TightRho"+prefix).c_str() ,"NGood_TightRho",700,0,700);

  TES_Combined = fs->make<TProfile>(("TES_Combined"+prefix).c_str(),"TES_Combined",100,0,700,0,50);
  Nvtx_Combined = fs->make<TH1F>(("Nvtx_Combined"+prefix).c_str() ,"Nvtx_Combined",700,0,700);
  NGood_Combined = fs->make<TH1F>(("NGood_Combined"+prefix).c_str() ,"NGood_Combined",700,0,700);

  RecoTauDecayMode_Combined = fs->make<TH1F>(("RecoTauDecayMode_Combined"+prefix).c_str() ,"RecoTauDecayMode_Combined",15,0,15);
  GenTauDecayMode_Combined  = fs->make<TH1F>(("GenTauDecayMode_Combined"+prefix).c_str() ,"GenTauDecayMode_Combined",15,0,15);
  reco_dm_vs_gen_Combined  = fs->make<TH2F>(("reco_dm_vs_gen_Combined"+prefix).c_str() ,"reco_dm_vs_gen_Combined",15,0,15,15,0,15);
  GenTauPtWithDMF_Combined = fs->make<TH1F>(("GenTauPtWithDMF_Combined"+prefix).c_str() ,"GenTauPtWithDMF_Combined",100,0,700);
  GenTauEtaWithDMF_Combined = fs->make<TH1F>(("GenTauEtaWithDMF_Combined"+prefix).c_str() ,"GenTauEtaWithDMF_Combined",100,-5,5);
  GenTauPhiWithDMF_Combined = fs->make<TH1F>(("GenTauPhiWithDMF_Combined"+prefix).c_str() ,"GenTauPhiWithDMF_Combined",100,-5,5);
 

  //

  TES_CombinedL = fs->make<TProfile>(("TES_CombinedL"+prefix).c_str(),"TES_CombinedL",100,0,700,0,50);
  Nvtx_CombinedL = fs->make<TH1F>(("Nvtx_CombinedL"+prefix).c_str() ,"Nvtx_CombinedL",700,0,700);
  NGood_CombinedL = fs->make<TH1F>(("NGood_CombinedL"+prefix).c_str() ,"NGood_CombinedL",700,0,700);

  RecoTauDecayMode_CombinedL = fs->make<TH1F>(("RecoTauDecayMode_CombinedL"+prefix).c_str() ,"RecoTauDecayMode_CombinedL",15,0,15);
  GenTauDecayMode_CombinedL  = fs->make<TH1F>(("GenTauDecayMode_CombinedL"+prefix).c_str() ,"GenTauDecayMode_CombinedL",15,0,15);
  reco_dm_vs_gen_CombinedL  = fs->make<TH2F>(("reco_dm_vs_gen_CombinedL"+prefix).c_str() ,"reco_dm_vs_gen_CombinedL",15,0,15,15,0,15);
  GenTauPtWithDMF_CombinedL = fs->make<TH1F>(("GenTauPtWithDMF_CombinedL"+prefix).c_str() ,"GenTauPtWithDMF_CombinedL",100,0,700);
  GenTauEtaWithDMF_CombinedL = fs->make<TH1F>(("GenTauEtaWithDMF_CombinedL"+prefix).c_str() ,"GenTauEtaWithDMF_CombinedL",100,-5,5);
  GenTauPhiWithDMF_CombinedL = fs->make<TH1F>(("GenTauPhiWithDMF_CombinedL"+prefix).c_str() ,"GenTauPhiWithDMF_CombinedL",100,-5,5);


  TES_CombinedT = fs->make<TProfile>(("TES_CombinedT"+prefix).c_str(),"TES_CombinedT",100,0,700,0,50);
  Nvtx_CombinedT = fs->make<TH1F>(("Nvtx_CombinedT"+prefix).c_str() ,"Nvtx_CombinedT",700,0,700);
  NGood_CombinedT = fs->make<TH1F>(("NGood_CombinedT"+prefix).c_str() ,"NGood_CombinedT",700,0,700);

  RecoTauDecayMode_CombinedT = fs->make<TH1F>(("RecoTauDecayMode_CombinedT"+prefix).c_str() ,"RecoTauDecayMode_CombinedT",15,0,15);
  GenTauDecayMode_CombinedT  = fs->make<TH1F>(("GenTauDecayMode_CombinedT"+prefix).c_str() ,"GenTauDecayMode_CombinedT",15,0,15);
  reco_dm_vs_gen_CombinedT  = fs->make<TH2F>(("reco_dm_vs_gen_CombinedT"+prefix).c_str() ,"reco_dm_vs_gen_CombinedT",15,0,15,15,0,15);
  GenTauPtWithDMF_CombinedT = fs->make<TH1F>(("GenTauPtWithDMF_CombinedT"+prefix).c_str() ,"GenTauPtWithDMF_CombinedT",100,0,700);
  GenTauEtaWithDMF_CombinedT = fs->make<TH1F>(("GenTauEtaWithDMF_CombinedT"+prefix).c_str() ,"GenTauEtaWithDMF_CombinedT",100,-5,5);
  GenTauPhiWithDMF_CombinedT = fs->make<TH1F>(("GenTauPhiWithDMF_CombinedT"+prefix).c_str() ,"GenTauPhiWithDMF_CombinedT",100,-5,5);
TauPtResponse_CombinedL  = fs->make<TH1F>(("TauPtResponse_CombinedL"+prefix).c_str() ,"TauPtResponse_CombinedL",100,0.1,2.0);


TauPtResponse_CombinedT  = fs->make<TH1F>(("TauPtResponse_CombinedT"+prefix).c_str() ,"TauPtResponse_CombinedT",100,0.1,2.0);
 //
////////////////////////////////////////////
  TES_MIsoPtSum = fs->make<TProfile>(("TES_MIsoPtSum"+prefix).c_str(),"TES_MIsoPtSum",100,0,700,0,50);
  Nvtx_MIsoPtSum = fs->make<TH1F>(("Nvtx_MIsoPtSum"+prefix).c_str() ,"Nvtx_MIsoPtSum",700,0,700);
  NGood_MIsoPtSum = fs->make<TH1F>(("NGood_MIsoPtSum"+prefix).c_str() ,"NGood_MIsoPtSum",700,0,700);

  RecoTauDecayMode_MIsoPtSum = fs->make<TH1F>(("RecoTauDecayMode_MIsoPtSum"+prefix).c_str() ,"RecoTauDecayMode_MIsoPtSum",15,0,15);
  GenTauDecayMode_MIsoPtSum  = fs->make<TH1F>(("GenTauDecayMode_MIsoPtSum"+prefix).c_str() ,"GenTauDecayMode_MIsoPtSum",15,0,15);
  reco_dm_vs_gen_MIsoPtSum  = fs->make<TH2F>(("reco_dm_vs_gen_MIsoPtSum"+prefix).c_str() ,"reco_dm_vs_gen_MIsoPtSum",15,0,15,15,0,15);
  GenTauPtWithDMF_MIsoPtSum = fs->make<TH1F>(("GenTauPtWithDMF_MIsoPtSum"+prefix).c_str() ,"GenTauPtWithDMF_MIsoPtSum",100,0,700);
  GenTauEtaWithDMF_MIsoPtSum = fs->make<TH1F>(("GenTauEtaWithDMF_MIsoPtSum"+prefix).c_str() ,"GenTauEtaWithDMF_MIsoPtSum",100,-5,5);
  GenTauPhiWithDMF_MIsoPtSum = fs->make<TH1F>(("GenTauPhiWithDMF_MIsoPtSum"+prefix).c_str() ,"GenTauPhiWithDMF_MIsoPtSum",100,-5,5);
  TauPtResponse_MIsoPtSum  = fs->make<TH1F>(("TauPtResponse_MIsoPtSum"+prefix).c_str() ,"TauPtResponse_MIsoPtSum",100,0.1,2.0);         
 TauPtResponse_Combined  = fs->make<TH1F>(("TauPtResponse_Combined"+prefix).c_str() ,"TauPtResponse_Combined",100,0.1,2.0);

  TES_TIsoPtSum = fs->make<TProfile>(("TES_TIsoPtSum"+prefix).c_str(),"TES_TIsoPtSum",100,0,700,0,50);
  Nvtx_TIsoPtSum = fs->make<TH1F>(("Nvtx_TIsoPtSum"+prefix).c_str() ,"Nvtx_TIsoPtSum",700,0,700);
  NGood_TIsoPtSum = fs->make<TH1F>(("NGood_TIsoPtSum"+prefix).c_str() ,"NGood_TIsoPtSum",700,0,700);

  RecoTauDecayMode_TIsoPtSum = fs->make<TH1F>(("RecoTauDecayMode_TIsoPtSum"+prefix).c_str() ,"RecoTauDecayMode_TIsoPtSum",15,0,15);
  GenTauDecayMode_TIsoPtSum  = fs->make<TH1F>(("GenTauDecayMode_TIsoPtSum"+prefix).c_str() ,"GenTauDecayMode_TIsoPtSum",15,0,15);
  reco_dm_vs_gen_TIsoPtSum  = fs->make<TH2F>(("reco_dm_vs_gen_TIsoPtSum"+prefix).c_str() ,"reco_dm_vs_gen_TIsoPtSum",15,0,15,15,0,15);
  GenTauPtWithDMF_TIsoPtSum = fs->make<TH1F>(("GenTauPtWithDMF_TIsoPtSum"+prefix).c_str() ,"GenTauPtWithDMF_TIsoPtSum",100,0,700);
  GenTauEtaWithDMF_TIsoPtSum = fs->make<TH1F>(("GenTauEtaWithDMF_TIsoPtSum"+prefix).c_str() ,"GenTauEtaWithDMF_TIsoPtSum",100,-5,5);
  GenTauPhiWithDMF_TIsoPtSum = fs->make<TH1F>(("GenTauPhiWithDMF_TIsoPtSum"+prefix).c_str() ,"GenTauPhiWithDMF_TIsoPtSum",100,-5,5);
  TauPtResponse_TIsoPtSum  = fs->make<TH1F>(("TauPtResponse_TIsoPtSum"+prefix).c_str() ,"TauPtResponse_TIsoPtSum",100,0.1,2.0);         


  TES_LIsoPtSum = fs->make<TProfile>(("TES_LIsoPtSum"+prefix).c_str(),"TES_LIsoPtSum",100,0,700,0,50);
  Nvtx_LIsoPtSum = fs->make<TH1F>(("Nvtx_LIsoPtSum"+prefix).c_str() ,"Nvtx_LIsoPtSum",700,0,700);
  NGood_LIsoPtSum = fs->make<TH1F>(("NGood_LIsoPtSum"+prefix).c_str() ,"NGood_LIsoPtSum",700,0,700);

  RecoTauDecayMode_LIsoPtSum = fs->make<TH1F>(("RecoTauDecayMode_LIsoPtSum"+prefix).c_str() ,"RecoTauDecayMode_LIsoPtSum",15,0,15);
  GenTauDecayMode_LIsoPtSum  = fs->make<TH1F>(("GenTauDecayMode_LIsoPtSum"+prefix).c_str() ,"GenTauDecayMode_LIsoPtSum",15,0,15);
  reco_dm_vs_gen_LIsoPtSum  = fs->make<TH2F>(("reco_dm_vs_gen_LIsoPtSum"+prefix).c_str() ,"reco_dm_vs_gen_LIsoPtSum",15,0,15,15,0,15);
  GenTauPtWithDMF_LIsoPtSum = fs->make<TH1F>(("GenTauPtWithDMF_LIsoPtSum"+prefix).c_str() ,"GenTauPtWithDMF_LIsoPtSum",100,0,700);
  GenTauEtaWithDMF_LIsoPtSum = fs->make<TH1F>(("GenTauEtaWithDMF_LIsoPtSum"+prefix).c_str() ,"GenTauEtaWithDMF_LIsoPtSum",100,-5,5);
  GenTauPhiWithDMF_LIsoPtSum = fs->make<TH1F>(("GenTauPhiWithDMF_LIsoPtSum"+prefix).c_str() ,"GenTauPhiWithDMF_LIsoPtSum",100,-5,5);
  TauPtResponse_LIsoPtSum  = fs->make<TH1F>(("TauPtResponse_LIsoPtSum"+prefix).c_str() ,"TauPtResponse_LIsoPtSum",100,0.1,2.0);         

  /////////////////////////////////////////////////////////


////////////////////////////////////////////
  TES_MIsoPtSumN = fs->make<TProfile>(("TES_MIsoPtSumN"+prefix).c_str(),"TES_MIsoPtSumN",100,0,700,0,50);
  Nvtx_MIsoPtSumN = fs->make<TH1F>(("Nvtx_MIsoPtSumN"+prefix).c_str() ,"Nvtx_MIsoPtSumN",700,0,700);
  NGood_MIsoPtSumN = fs->make<TH1F>(("NGood_MIsoPtSumN"+prefix).c_str() ,"NGood_MIsoPtSumN",700,0,700);

  RecoTauDecayMode_MIsoPtSumN = fs->make<TH1F>(("RecoTauDecayMode_MIsoPtSumN"+prefix).c_str() ,"RecoTauDecayMode_MIsoPtSumN",15,0,15);
  GenTauDecayMode_MIsoPtSumN  = fs->make<TH1F>(("GenTauDecayMode_MIsoPtSumN"+prefix).c_str() ,"GenTauDecayMode_MIsoPtSumN",15,0,15);
  reco_dm_vs_gen_MIsoPtSumN  = fs->make<TH2F>(("reco_dm_vs_gen_MIsoPtSumN"+prefix).c_str() ,"reco_dm_vs_gen_MIsoPtSumN",15,0,15,15,0,15);
  GenTauPtWithDMF_MIsoPtSumN = fs->make<TH1F>(("GenTauPtWithDMF_MIsoPtSumN"+prefix).c_str() ,"GenTauPtWithDMF_MIsoPtSumN",100,0,700);
  GenTauEtaWithDMF_MIsoPtSumN = fs->make<TH1F>(("GenTauEtaWithDMF_MIsoPtSumN"+prefix).c_str() ,"GenTauEtaWithDMF_MIsoPtSumN",100,-5,5);
  GenTauPhiWithDMF_MIsoPtSumN = fs->make<TH1F>(("GenTauPhiWithDMF_MIsoPtSumN"+prefix).c_str() ,"GenTauPhiWithDMF_MIsoPtSumN",100,-5,5);
  TauPtResponse_MIsoPtSumN  = fs->make<TH1F>(("TauPtResponse_MIsoPtSumN"+prefix).c_str() ,"TauPtResponse_MIsoPtSumN",100,0.1,2.0);         
 TauPtResponse_Combined  = fs->make<TH1F>(("TauPtResponse_Combined"+prefix).c_str() ,"TauPtResponse_Combined",100,0.1,2.0);

  TES_TIsoPtSumN = fs->make<TProfile>(("TES_TIsoPtSumN"+prefix).c_str(),"TES_TIsoPtSumN",100,0,700,0,50);
  Nvtx_TIsoPtSumN = fs->make<TH1F>(("Nvtx_TIsoPtSumN"+prefix).c_str() ,"Nvtx_TIsoPtSumN",700,0,700);
  NGood_TIsoPtSumN = fs->make<TH1F>(("NGood_TIsoPtSumN"+prefix).c_str() ,"NGood_TIsoPtSumN",700,0,700);

  RecoTauDecayMode_TIsoPtSumN = fs->make<TH1F>(("RecoTauDecayMode_TIsoPtSumN"+prefix).c_str() ,"RecoTauDecayMode_TIsoPtSumN",15,0,15);
  GenTauDecayMode_TIsoPtSumN  = fs->make<TH1F>(("GenTauDecayMode_TIsoPtSumN"+prefix).c_str() ,"GenTauDecayMode_TIsoPtSumN",15,0,15);
  reco_dm_vs_gen_TIsoPtSumN  = fs->make<TH2F>(("reco_dm_vs_gen_TIsoPtSumN"+prefix).c_str() ,"reco_dm_vs_gen_TIsoPtSumN",15,0,15,15,0,15);
  GenTauPtWithDMF_TIsoPtSumN = fs->make<TH1F>(("GenTauPtWithDMF_TIsoPtSumN"+prefix).c_str() ,"GenTauPtWithDMF_TIsoPtSumN",100,0,700);
  GenTauEtaWithDMF_TIsoPtSumN = fs->make<TH1F>(("GenTauEtaWithDMF_TIsoPtSumN"+prefix).c_str() ,"GenTauEtaWithDMF_TIsoPtSumN",100,-5,5);
  GenTauPhiWithDMF_TIsoPtSumN = fs->make<TH1F>(("GenTauPhiWithDMF_TIsoPtSumN"+prefix).c_str() ,"GenTauPhiWithDMF_TIsoPtSumN",100,-5,5);
  TauPtResponse_TIsoPtSumN  = fs->make<TH1F>(("TauPtResponse_TIsoPtSumN"+prefix).c_str() ,"TauPtResponse_TIsoPtSumN",100,0.1,2.0);         


  TES_LIsoPtSumN = fs->make<TProfile>(("TES_LIsoPtSumN"+prefix).c_str(),"TES_LIsoPtSumN",100,0,700,0,50);
  Nvtx_LIsoPtSumN = fs->make<TH1F>(("Nvtx_LIsoPtSumN"+prefix).c_str() ,"Nvtx_LIsoPtSumN",700,0,700);
  NGood_LIsoPtSumN = fs->make<TH1F>(("NGood_LIsoPtSumN"+prefix).c_str() ,"NGood_LIsoPtSumN",700,0,700);

  RecoTauDecayMode_LIsoPtSumN = fs->make<TH1F>(("RecoTauDecayMode_LIsoPtSumN"+prefix).c_str() ,"RecoTauDecayMode_LIsoPtSumN",15,0,15);
  GenTauDecayMode_LIsoPtSumN  = fs->make<TH1F>(("GenTauDecayMode_LIsoPtSumN"+prefix).c_str() ,"GenTauDecayMode_LIsoPtSumN",15,0,15);
  reco_dm_vs_gen_LIsoPtSumN  = fs->make<TH2F>(("reco_dm_vs_gen_LIsoPtSumN"+prefix).c_str() ,"reco_dm_vs_gen_LIsoPtSumN",15,0,15,15,0,15);
  GenTauPtWithDMF_LIsoPtSumN = fs->make<TH1F>(("GenTauPtWithDMF_LIsoPtSumN"+prefix).c_str() ,"GenTauPtWithDMF_LIsoPtSumN",100,0,700);
  GenTauEtaWithDMF_LIsoPtSumN = fs->make<TH1F>(("GenTauEtaWithDMF_LIsoPtSumN"+prefix).c_str() ,"GenTauEtaWithDMF_LIsoPtSumN",100,-5,5);
  GenTauPhiWithDMF_LIsoPtSumN = fs->make<TH1F>(("GenTauPhiWithDMF_LIsoPtSumN"+prefix).c_str() ,"GenTauPhiWithDMF_LIsoPtSumN",100,-5,5);
  TauPtResponse_LIsoPtSumN  = fs->make<TH1F>(("TauPtResponse_LIsoPtSumN"+prefix).c_str() ,"TauPtResponse_LIsoPtSumN",100,0.1,2.0);         

  /////////////////////////////////////////////////////////



////////////////////////////////////////////
  TES_MIsoPtSumN2 = fs->make<TProfile>(("TES_MIsoPtSumN2"+prefix).c_str(),"TES_MIsoPtSumN2",100,0,700,0,50);
  Nvtx_MIsoPtSumN2 = fs->make<TH1F>(("Nvtx_MIsoPtSumN2"+prefix).c_str() ,"Nvtx_MIsoPtSumN2",700,0,700);
  NGood_MIsoPtSumN2 = fs->make<TH1F>(("NGood_MIsoPtSumN2"+prefix).c_str() ,"NGood_MIsoPtSumN2",700,0,700);

  RecoTauDecayMode_MIsoPtSumN2 = fs->make<TH1F>(("RecoTauDecayMode_MIsoPtSumN2"+prefix).c_str() ,"RecoTauDecayMode_MIsoPtSumN2",15,0,15);
  GenTauDecayMode_MIsoPtSumN2  = fs->make<TH1F>(("GenTauDecayMode_MIsoPtSumN2"+prefix).c_str() ,"GenTauDecayMode_MIsoPtSumN2",15,0,15);
  reco_dm_vs_gen_MIsoPtSumN2  = fs->make<TH2F>(("reco_dm_vs_gen_MIsoPtSumN2"+prefix).c_str() ,"reco_dm_vs_gen_MIsoPtSumN2",15,0,15,15,0,15);
  GenTauPtWithDMF_MIsoPtSumN2 = fs->make<TH1F>(("GenTauPtWithDMF_MIsoPtSumN2"+prefix).c_str() ,"GenTauPtWithDMF_MIsoPtSumN2",100,0,700);
  GenTauEtaWithDMF_MIsoPtSumN2 = fs->make<TH1F>(("GenTauEtaWithDMF_MIsoPtSumN2"+prefix).c_str() ,"GenTauEtaWithDMF_MIsoPtSumN2",100,-5,5);
  GenTauPhiWithDMF_MIsoPtSumN2 = fs->make<TH1F>(("GenTauPhiWithDMF_MIsoPtSumN2"+prefix).c_str() ,"GenTauPhiWithDMF_MIsoPtSumN2",100,-5,5);
  TauPtResponse_MIsoPtSumN2  = fs->make<TH1F>(("TauPtResponse_MIsoPtSumN2"+prefix).c_str() ,"TauPtResponse_MIsoPtSumN2",100,0.1,2.0);         
 TauPtResponse_Combined  = fs->make<TH1F>(("TauPtResponse_Combined"+prefix).c_str() ,"TauPtResponse_Combined",100,0.1,2.0);

  TES_TIsoPtSumN2 = fs->make<TProfile>(("TES_TIsoPtSumN2"+prefix).c_str(),"TES_TIsoPtSumN2",100,0,700,0,50);
  Nvtx_TIsoPtSumN2 = fs->make<TH1F>(("Nvtx_TIsoPtSumN2"+prefix).c_str() ,"Nvtx_TIsoPtSumN2",700,0,700);
  NGood_TIsoPtSumN2 = fs->make<TH1F>(("NGood_TIsoPtSumN2"+prefix).c_str() ,"NGood_TIsoPtSumN2",700,0,700);

  RecoTauDecayMode_TIsoPtSumN2 = fs->make<TH1F>(("RecoTauDecayMode_TIsoPtSumN2"+prefix).c_str() ,"RecoTauDecayMode_TIsoPtSumN2",15,0,15);
  GenTauDecayMode_TIsoPtSumN2  = fs->make<TH1F>(("GenTauDecayMode_TIsoPtSumN2"+prefix).c_str() ,"GenTauDecayMode_TIsoPtSumN2",15,0,15);
  reco_dm_vs_gen_TIsoPtSumN2  = fs->make<TH2F>(("reco_dm_vs_gen_TIsoPtSumN2"+prefix).c_str() ,"reco_dm_vs_gen_TIsoPtSumN2",15,0,15,15,0,15);
  GenTauPtWithDMF_TIsoPtSumN2 = fs->make<TH1F>(("GenTauPtWithDMF_TIsoPtSumN2"+prefix).c_str() ,"GenTauPtWithDMF_TIsoPtSumN2",100,0,700);
  GenTauEtaWithDMF_TIsoPtSumN2 = fs->make<TH1F>(("GenTauEtaWithDMF_TIsoPtSumN2"+prefix).c_str() ,"GenTauEtaWithDMF_TIsoPtSumN2",100,-5,5);
  GenTauPhiWithDMF_TIsoPtSumN2 = fs->make<TH1F>(("GenTauPhiWithDMF_TIsoPtSumN2"+prefix).c_str() ,"GenTauPhiWithDMF_TIsoPtSumN2",100,-5,5);
  TauPtResponse_TIsoPtSumN2  = fs->make<TH1F>(("TauPtResponse_TIsoPtSumN2"+prefix).c_str() ,"TauPtResponse_TIsoPtSumN2",100,0.1,2.0);         


  TES_LIsoPtSumN2 = fs->make<TProfile>(("TES_LIsoPtSumN2"+prefix).c_str(),"TES_LIsoPtSumN2",100,0,700,0,50);
  Nvtx_LIsoPtSumN2 = fs->make<TH1F>(("Nvtx_LIsoPtSumN2"+prefix).c_str() ,"Nvtx_LIsoPtSumN2",700,0,700);
  NGood_LIsoPtSumN2 = fs->make<TH1F>(("NGood_LIsoPtSumN2"+prefix).c_str() ,"NGood_LIsoPtSumN2",700,0,700);

  RecoTauDecayMode_LIsoPtSumN2 = fs->make<TH1F>(("RecoTauDecayMode_LIsoPtSumN2"+prefix).c_str() ,"RecoTauDecayMode_LIsoPtSumN2",15,0,15);
  GenTauDecayMode_LIsoPtSumN2  = fs->make<TH1F>(("GenTauDecayMode_LIsoPtSumN2"+prefix).c_str() ,"GenTauDecayMode_LIsoPtSumN2",15,0,15);
  reco_dm_vs_gen_LIsoPtSumN2  = fs->make<TH2F>(("reco_dm_vs_gen_LIsoPtSumN2"+prefix).c_str() ,"reco_dm_vs_gen_LIsoPtSumN2",15,0,15,15,0,15);
  GenTauPtWithDMF_LIsoPtSumN2 = fs->make<TH1F>(("GenTauPtWithDMF_LIsoPtSumN2"+prefix).c_str() ,"GenTauPtWithDMF_LIsoPtSumN2",100,0,700);
  GenTauEtaWithDMF_LIsoPtSumN2 = fs->make<TH1F>(("GenTauEtaWithDMF_LIsoPtSumN2"+prefix).c_str() ,"GenTauEtaWithDMF_LIsoPtSumN2",100,-5,5);
  GenTauPhiWithDMF_LIsoPtSumN2 = fs->make<TH1F>(("GenTauPhiWithDMF_LIsoPtSumN2"+prefix).c_str() ,"GenTauPhiWithDMF_LIsoPtSumN2",100,-5,5);
  TauPtResponse_LIsoPtSumN2  = fs->make<TH1F>(("TauPtResponse_LIsoPtSumN2"+prefix).c_str() ,"TauPtResponse_LIsoPtSumN2",100,0.1,2.0);         

  /////////////////////////////////////////////////////////


 RecoTauDecayMode_DenDMF = fs->make<TH1F>(("RecoTauDecayMode_DenDMF"+prefix).c_str() ,"RecoTauDecayMode_DenDMF",15,0,15);
  GenTauDecayMode_DenDMF  = fs->make<TH1F>(("GenTauDecayMode_DenDMF"+prefix).c_str() ,"GenTauDecayMode_DenDMF",15,0,15);
  reco_dm_vs_gen_DenDMF  = fs->make<TH2F>(("reco_dm_vs_gen_DenDMF"+prefix).c_str() ,"reco_dm_vs_gen_DenDMF",15,0,15,15,0,15);
  GenTauPtWithDMF_DenDMF = fs->make<TH1F>(("GenTauPtWithDMF_DenDMF"+prefix).c_str() ,"GenTauPtWithDMF_DenDMF",100,0,700);
  GenTauEtaWithDMF_DenDMF = fs->make<TH1F>(("GenTauEtaWithDMF_DenDMF"+prefix).c_str() ,"GenTauEtaWithDMF_DenDMF",100,-5,5);
  GenTauPhiWithDMF_DenDMF = fs->make<TH1F>(("GenTauPhiWithDMF_DenDMF"+prefix).c_str() ,"GenTauPhiWithDMF_DenDMF",100,-5,5);
TauPtResponse_DenDMF  = fs->make<TH1F>(("TauPtResponse_DenDMF"+prefix).c_str() ,"TauPtResponse_DenDMF",100,0.1,2.0);         

  //
  RecoTauDecayMode_DM = fs->make<TH1F>(("RecoTauDecayMode_DM"+prefix).c_str() ,"RecoTauDecayMode_DM",15,0,15);
  GenTauDecayMode_DM = fs->make<TH1F>(("GenTauDecayMode_DM"+prefix).c_str() ,"GenTauDecayMode_DM",15,0,15);
  reco_dm_vs_gen_dm = fs->make<TH2F>(("reco_dm_vs_gen_dm"+prefix).c_str() ,"reco_dm_vs_gen_dm",15,0,15,15,0,15);
 reco_dm_vs_gen_dm1  = fs->make<TH2F>(("reco_dm_vs_gen_dm1"+prefix).c_str() ,"reco_dm_vs_gen_dm1",3,0,3,3,0,3);
  GenTauPtWithDMF_Iso1 = fs->make<TH1F>(("GenTauPtWithDMF_Iso1"+prefix).c_str() ,"GenTauPtWithDMF_Iso1" ,100,0,700);                                         
  GenTauEtaWithDMF_Iso1 = fs->make<TH1F>(("GenTauEtaWithDMF_Iso1"+prefix).c_str() ,"GenTauEtaWithDMF_Iso1" ,100,-5,5);
  GenTauPhiWithDMF_Iso1 = fs->make<TH1F>(("GenTauPhiWithDMF_Iso1"+prefix).c_str() ,"GenTauPhiWithDMF_Iso1" ,100,-5,5);

  GenTauPtWithDMF_Iso2 = fs->make<TH1F>(("GenTauPtWithDMF_Iso2"+prefix).c_str() ,"GenTauPtWithDMF_Iso2" ,100,0,700);
  GenTauEtaWithDMF_Iso2 = fs->make<TH1F>(("GenTauEtaWithDMF_Iso2"+prefix).c_str() ,"GenTauEtaWithDMF_Iso2" ,100,-5,5);
  GenTauPhiWithDMF_Iso2 = fs->make<TH1F>(("GenTauPhiWithDMF_Iso2"+prefix).c_str() ,"GenTauPhiWithDMF_Iso2" ,100,-5,5);


  GenTauPtWithDMF_Iso4 = fs->make<TH1F>(("GenTauPtWithDMF_Iso4"+prefix).c_str() ,"GenTauPtWithDMF_Iso4" ,100,0,700);
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
  GenTauPtWithDMF_ML2 = fs->make<TH1F>(("GenTauPtWithDMF_ML2"+prefix).c_str() ,"GenTauPtWithDMF_ML2" ,100,0,700);
  GenTauEtaWithDMF_ML2 = fs->make<TH1F>(("GenTauEtaWithDMF_ML2"+prefix).c_str() ,"GenTauEtaWithDMF_ML2" ,100,-5,5);
  GenTauPhiWithDMF_ML2 = fs->make<TH1F>(("GenTauPhiWithDMF_ML2"+prefix).c_str() ,"GenTauPhiWithDMF_ML2" ,100,-5,5);



  TauPtResponse_DM = fs->make<TH1F>(("TauPtResponse_DM"+prefix).c_str() ,"TauPtResponse_DM",100,0.1,2.0);
  TauPtResponse_MM2 = fs->make<TH1F>(("TauPtResponse_MM2"+prefix).c_str() ,"TauPtResponse_MM2",100,0.1,2.0);
  RecoTauDecayMode_MM2 = fs->make<TH1F>(("RecoTauDecayMode_MM2"+prefix).c_str() ,"RecoTauDecayMode_MM2",15,0,15);
  GenTauDecayMode_MM2 = fs->make<TH1F>(("GenTauDecayMode_MM2"+prefix).c_str() ,"GenTauDecayMode_MM2",15,0,15);
  reco_dm_vs_gen_MM2 = fs->make<TH2F>(("reco_dm_vs_gen_MM2"+prefix).c_str() ,"reco_dm_vs_gen_MM2",15,0,15,15,0,15);
  GenTauPtWithDMF_MM2 = fs->make<TH1F>(("GenTauPtWithDMF_MM2"+prefix).c_str() ,"GenTauPtWithDMF_MM2" ,100,0,700);
  GenTauEtaWithDMF_MM2 = fs->make<TH1F>(("GenTauEtaWithDMF_MM2"+prefix).c_str() ,"GenTauEtaWithDMF_MM2" ,100,-5,5);
  GenTauPhiWithDMF_MM2 = fs->make<TH1F>(("GenTauPhiWithDMF_MM2"+prefix).c_str() ,"GenTauPhiWithDMF_MM2" ,100,-5,5);

  TauPtResponse_MT2= fs->make<TH1F>(("TauPtResponse_MT2"+prefix).c_str() ,"TauPtResponse_MT2",100,0.1,2.0);
  RecoTauDecayMode_MT2 = fs->make<TH1F>(("RecoTauDecayMode_MT2"+prefix).c_str() ,"RecoTauDecayMode_MT2",15,0,15);
  GenTauDecayMode_MT2 = fs->make<TH1F>(("GenTauDecayMode_MT2"+prefix).c_str() ,"GenTauDecayMode_MT2",15,0,15);
  reco_dm_vs_gen_MT2 = fs->make<TH2F>(("reco_dm_vs_gen_MT2"+prefix).c_str() ,"reco_dm_vs_gen_MT2",15,0,15,15,0,15);
  GenTauPtWithDMF_MT2 = fs->make<TH1F>(("GenTauPtWithDMF_MT2"+prefix).c_str() ,"GenTauPtWithDMF_MT2" ,100,0,700);
  GenTauEtaWithDMF_MT2 = fs->make<TH1F>(("GenTauEtaWithDMF_MT2"+prefix).c_str() ,"GenTauEtaWithDMF_MT2" ,100,-5,5);
  GenTauPhiWithDMF_MT2 = fs->make<TH1F>(("GenTauPhiWithDMF_MT2"+prefix).c_str() ,"GenTauPhiWithDMF_MT2" ,100,-5,5);


  TauPtResponse_ML3 = fs->make<TH1F>(("TauPtResponse_ML3"+prefix).c_str() ,"TauPtResponse_ML3",100,0.1,2.0);
  RecoTauDecayMode_ML3 = fs->make<TH1F>(("RecoTauDecayMode_ML3"+prefix).c_str() ,"RecoTauDecayMode_ML3",15,0,15);
  GenTauDecayMode_ML3 = fs->make<TH1F>(("GenTauDecayMode_ML3"+prefix).c_str() ,"GenTauDecayMode_ML3",15,0,15);
  reco_dm_vs_gen_ML3 = fs->make<TH2F>(("reco_dm_vs_gen_ML3"+prefix).c_str() ,"reco_dm_vs_gen_ML3",15,0,15,15,0,15);
  GenTauPtWithDMF_ML3 = fs->make<TH1F>(("GenTauPtWithDMF_ML3"+prefix).c_str() ,"GenTauPtWithDMF_ML3" ,100,0,700);
  GenTauEtaWithDMF_ML3 = fs->make<TH1F>(("GenTauEtaWithDMF_ML3"+prefix).c_str() ,"GenTauEtaWithDMF_ML3" ,100,-5,5);
  GenTauPhiWithDMF_ML3 = fs->make<TH1F>(("GenTauPhiWithDMF_ML3"+prefix).c_str() ,"GenTauPhiWithDMF_ML3" ,100,-5,5);



  TauPtResponse_MT3= fs->make<TH1F>(("TauPtResponse_MT3"+prefix).c_str() ,"TauPtResponse_MT3",100,0.1,2.0);
  RecoTauDecayMode_MT3 = fs->make<TH1F>(("RecoTauDecayMode_MT3"+prefix).c_str() ,"RecoTauDecayMode_MT3",15,0,15);
  GenTauDecayMode_MT3 = fs->make<TH1F>(("GenTauDecayMode_MT3"+prefix).c_str() ,"GenTauDecayMode_MT3",15,0,15);
  reco_dm_vs_gen_MT3 = fs->make<TH2F>(("reco_dm_vs_gen_MT3"+prefix).c_str() ,"reco_dm_vs_gen_MT3",15,0,15,15,0,15);
  GenTauPtWithDMF_MT3 = fs->make<TH1F>(("GenTauPtWithDMF_MT3"+prefix).c_str() ,"GenTauPtWithDMF_MT3" ,100,0,700);
  GenTauEtaWithDMF_MT3 = fs->make<TH1F>(("GenTauEtaWithDMF_MT3"+prefix).c_str() ,"GenTauEtaWithDMF_MT3" ,100,-5,5);
  GenTauPhiWithDMF_MT3 = fs->make<TH1F>(("GenTauPhiWithDMF_MT3"+prefix).c_str() ,"GenTauPhiWithDMF_MT3" ,100,-5,5);



  TauPtResponse_EL3 = fs->make<TH1F>(("TauPtResponse_EL3"+prefix).c_str() ,"TauPtResponse_EL3",100,0.1,2.0);
  RecoTauDecayMode_EL3 = fs->make<TH1F>(("RecoTauDecayMode_EL3"+prefix).c_str() ,"RecoTauDecayMode_EL3",15,0,15);
  GenTauDecayMode_EL3 = fs->make<TH1F>(("GenTauDecayMode_EL3"+prefix).c_str() ,"GenTauDecayMode_EL3",15,0,15);
  reco_dm_vs_gen_EL3 = fs->make<TH2F>(("reco_dm_vs_gen_EL3"+prefix).c_str() ,"reco_dm_vs_gen_EL3",15,0,15,15,0,15);
  GenTauPtWithDMF_EL3 = fs->make<TH1F>(("GenTauPtWithDMF_EL3"+prefix).c_str() ,"GenTauPtWithDMF_EL3" ,100,0,700);
  GenTauEtaWithDMF_EL3 = fs->make<TH1F>(("GenTauEtaWithDMF_EL3"+prefix).c_str() ,"GenTauEtaWithDMF_EL3" ,100,-5,5);
  GenTauPhiWithDMF_EL3 = fs->make<TH1F>(("GenTauPhiWithDMF_EL3"+prefix).c_str() ,"GenTauPhiWithDMF_EL3" ,100,-5,5);

  TauPtResponse_EM3 = fs->make<TH1F>(("TauPtResponse_EM3"+prefix).c_str() ,"TauPtResponse_EM3",100,0.1,2.0);
  RecoTauDecayMode_EM3 = fs->make<TH1F>(("RecoTauDecayMode_EM3"+prefix).c_str() ,"RecoTauDecayMode_EM3",15,0,15);
  GenTauDecayMode_EM3 = fs->make<TH1F>(("GenTauDecayMode_EM3"+prefix).c_str() ,"GenTauDecayMode_EM3",15,0,15);
  reco_dm_vs_gen_EM3 = fs->make<TH2F>(("reco_dm_vs_gen_EM3"+prefix).c_str() ,"reco_dm_vs_gen_EM3",15,0,15,15,0,15);
  GenTauPtWithDMF_EM3 = fs->make<TH1F>(("GenTauPtWithDMF_EM3"+prefix).c_str() ,"GenTauPtWithDMF_EM3" ,100,0,700);
  GenTauEtaWithDMF_EM3 = fs->make<TH1F>(("GenTauEtaWithDMF_EM3"+prefix).c_str() ,"GenTauEtaWithDMF_EM3" ,100,-5,5);
  GenTauPhiWithDMF_EM3 = fs->make<TH1F>(("GenTauPhiWithDMF_EM3"+prefix).c_str() ,"GenTauPhiWithDMF_EM3" ,100,-5,5);

  TauPtResponse_ET3 = fs->make<TH1F>(("TauPtResponse_ET3"+prefix).c_str() ,"TauPtResponse_ET3",100,0.1,2.0);
  RecoTauDecayMode_ET3 = fs->make<TH1F>(("RecoTauDecayMode_ET3"+prefix).c_str() ,"RecoTauDecayMode_ET3",15,0,15);
  GenTauDecayMode_ET3 = fs->make<TH1F>(("GenTauDecayMode_ET3"+prefix).c_str() ,"GenTauDecayMode_ET3",15,0,15);
  reco_dm_vs_gen_ET3 = fs->make<TH2F>(("reco_dm_vs_gen_ET3"+prefix).c_str() ,"reco_dm_vs_gen_ET3",15,0,15,15,0,15);
  GenTauPtWithDMF_ET3 = fs->make<TH1F>(("GenTauPtWithDMF_ET3"+prefix).c_str() ,"GenTauPtWithDMF_ET3" ,100,0,700);
  GenTauEtaWithDMF_ET3 = fs->make<TH1F>(("GenTauEtaWithDMF_ET3"+prefix).c_str() ,"GenTauEtaWithDMF_ET3" ,100,-5,5);
  GenTauPhiWithDMF_ET3 = fs->make<TH1F>(("GenTauPhiWithDMF_ET3"+prefix).c_str() ,"GenTauPhiWithDMF_ET3" ,100,-5,5);

  TauPtResponse_Cut  = fs->make<TH1F>(("TauPtResponse_Cut"+prefix).c_str() ,"TauPtResponse_Cut",100,0.1,2.0);
  RecoTauDecayMode_Cut  = fs->make<TH1F>(("RecoTauDecayMode_Cut"+prefix).c_str() ,"RecoTauDecayMode_Cut",15,0,15);
  GenTauDecayMode_Cut   = fs->make<TH1F>(("GenTauDecayMode_Cut"+prefix).c_str() ,"GenTauDecayMode_Cut",15,0,15);
  reco_dm_vs_gen_Cut = fs->make<TH2F>(("reco_dm_vs_gen_Cut"+prefix).c_str() ,"reco_dm_vs_gen_Cut",15,0,15,15,0,15);
  GenTauPtWithDMF_Cut = fs->make<TH1F>(("GenTauPtWithDMF_Cut"+prefix).c_str() ,"GenTauPtWithDMF_Cut" ,100,0,700);
  GenTauEtaWithDMF_Cut = fs->make<TH1F>(("GenTauEtaWithDMF_Cut"+prefix).c_str() ,"GenTauEtaWithDMF_Cut"  ,100,-5,5);
  GenTauPhiWithDMF_Cut = fs->make<TH1F>(("GenTauPhiWithDMF_Cut"+prefix).c_str() ,"GenTauPhiWithDMF_Cut"  ,100,-5,5);

  TauPtResponse_LIso3Hits = fs->make<TH1F>(("TauPtResponse_LIso3Hits"+prefix).c_str() ,"TauPtResponse_LIso3Hits",100,0.1,2.0);
  RecoTauDecayMode_LIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_LIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_LIso3Hits",15,0,15);
  GenTauDecayMode_LIso3Hits = fs->make<TH1F>(("GenTauDecayMode_LIso3Hits"+prefix).c_str() ,"GenTauDecayMode_LIso3Hits",15,0,15);
  reco_dm_vs_gen_LIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_LIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_LIso3Hits",15,0,15,15,0,15);
  GenTauPtWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_LIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_LIso3Hits"  ,100,-5,5);
  GenTauPhiWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_LIso3Hits"  ,100,-5,5);
  

  TauPtResponse_MIso3Hits = fs->make<TH1F>(("TauPtResponse_MIso3Hits"+prefix).c_str() ,"TauPtResponse_MIso3Hits",100,0.1,2.0);
  RecoTauDecayMode_MIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_MIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_MIso3Hits",15,0,15);
  GenTauDecayMode_MIso3Hits = fs->make<TH1F>(("GenTauDecayMode_MIso3Hits"+prefix).c_str() ,"GenTauDecayMode_MIso3Hits",15,0,15);
  reco_dm_vs_gen_MIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_MIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_MIso3Hits",15,0,15,15,0,15);
  GenTauPtWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_MIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_MIso3Hits"  ,100,-5,5);
  GenTauPhiWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_MIso3Hits"  ,100,-5,5);
  
  TauPtResponse_TIso3Hits = fs->make<TH1F>(("TauPtResponse_TIso3Hits"+prefix).c_str() ,"TauPtResponse_TIso3Hits",100,0.1,2.0);
  RecoTauDecayMode_TIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_TIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_TIso3Hits",15,0,15);
  GenTauDecayMode_TIso3Hits = fs->make<TH1F>(("GenTauDecayMode_TIso3Hits"+prefix).c_str() ,"GenTauDecayMode_TIso3Hits",15,0,15);
  reco_dm_vs_gen_TIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_TIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_TIso3Hits",15,0,15,15,0,15);
  GenTauPtWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_TIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_TIso3Hits"  ,100,-5,5);
  GenTauPhiWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_TIso3Hits"  ,100,-5,5);
  

  TauPtResponse_LIso = fs->make<TH1F>(("TauPtResponse_LIso"+prefix).c_str() ,"TauPtResponse_LIso",100,0.1,2.0);
  RecoTauDecayMode_LIso = fs->make<TH1F>(("RecoTauDecayMode_LIso"+prefix).c_str() ,"RecoTauDecayMode_LIso",15,0,15);
  GenTauDecayMode_LIso = fs->make<TH1F>(("GenTauDecayMode_LIso"+prefix).c_str() ,"GenTauDecayMode_LIso",15,0,15);
  reco_dm_vs_gen_LIso = fs->make<TH2F>(("reco_dm_vs_gen_LIso"+prefix).c_str() ,"reco_dm_vs_gen_LIso",15,0,15,15,0,15);
  GenTauPtWithDMF_LIso = fs->make<TH1F>(("GenTauPtWithDMF_LIso"+prefix).c_str() ,"GenTauPtWithDMF_LIso" ,100,0,700);
  GenTauEtaWithDMF_LIso = fs->make<TH1F>(("GenTauEtaWithDMF_LIso"+prefix).c_str() ,"GenTauEtaWithDMF_LIso"  ,100,-5,5);
  GenTauPhiWithDMF_LIso = fs->make<TH1F>(("GenTauPhiWithDMF_LIso"+prefix).c_str() ,"GenTauPhiWithDMF_LIso"  ,100,-5,5);

  TauPtResponse_MIso = fs->make<TH1F>(("TauPtResponse_MIso"+prefix).c_str() ,"TauPtResponse_MIso",100,0.1,2.0);
  RecoTauDecayMode_MIso = fs->make<TH1F>(("RecoTauDecayMode_MIso"+prefix).c_str() ,"RecoTauDecayMode_MIso",15,0,15);
  GenTauDecayMode_MIso = fs->make<TH1F>(("GenTauDecayMode_MIso"+prefix).c_str() ,"GenTauDecayMode_MIso",15,0,15);
  reco_dm_vs_gen_MIso = fs->make<TH2F>(("reco_dm_vs_gen_MIso"+prefix).c_str() ,"reco_dm_vs_gen_MIso",15,0,15,15,0,15);
  GenTauPtWithDMF_MIso = fs->make<TH1F>(("GenTauPtWithDMF_MIso"+prefix).c_str() ,"GenTauPtWithDMF_MIso" ,100,0,700);
  GenTauEtaWithDMF_MIso = fs->make<TH1F>(("GenTauEtaWithDMF_MIso"+prefix).c_str() ,"GenTauEtaWithDMF_MIso"  ,100,-5,5);
  GenTauPhiWithDMF_MIso = fs->make<TH1F>(("GenTauPhiWithDMF_MIso"+prefix).c_str() ,"GenTauPhiWithDMF_MIso"  ,100,-5,5);

  TauPtResponse_TIso = fs->make<TH1F>(("TauPtResponse_TIso"+prefix).c_str() ,"TauPtResponse_TIso",100,0.1,2.0);
  RecoTauDecayMode_TIso = fs->make<TH1F>(("RecoTauDecayMode_TIso"+prefix).c_str() ,"RecoTauDecayMode_TIso",15,0,15);
  GenTauDecayMode_TIso = fs->make<TH1F>(("GenTauDecayMode_TIso"+prefix).c_str() ,"GenTauDecayMode_TIso",15,0,15);
  reco_dm_vs_gen_TIso = fs->make<TH2F>(("reco_dm_vs_gen_TIso"+prefix).c_str() ,"reco_dm_vs_gen_TIso",15,0,15,15,0,15);
  GenTauPtWithDMF_TIso = fs->make<TH1F>(("GenTauPtWithDMF_TIso"+prefix).c_str() ,"GenTauPtWithDMF_TIso" ,100,0,700);
  GenTauEtaWithDMF_TIso = fs->make<TH1F>(("GenTauEtaWithDMF_TIso"+prefix).c_str() ,"GenTauEtaWithDMF_TIso"  ,100,-5,5);
  GenTauPhiWithDMF_TIso = fs->make<TH1F>(("GenTauPhiWithDMF_TIso"+prefix).c_str() ,"GenTauPhiWithDMF_TIso"  ,100,-5,5);

  TauPtResponse_VLChar = fs->make<TH1F>(("TauPtResponse_VLChar"+prefix).c_str() ,"TauPtResponse_VLChar",100,0.1,2.0);
  RecoTauDecayMode_VLChar = fs->make<TH1F>(("RecoTauDecayMode_VLChar"+prefix).c_str() ,"RecoTauDecayMode_VLChar",15,0,15);
  GenTauDecayMode_VLChar = fs->make<TH1F>(("GenTauDecayMode_VLChar"+prefix).c_str() ,"GenTauDecayMode_VLChar",15,0,15);
  reco_dm_vs_gen_VLChar = fs->make<TH2F>(("reco_dm_vs_gen_VLChar"+prefix).c_str() ,"reco_dm_vs_gen_VLChar",15,0,15,15,0,15);
  GenTauPtWithDMF_VLChar = fs->make<TH1F>(("GenTauPtWithDMF_VLChar"+prefix).c_str() ,"GenTauPtWithDMF_VLChar" ,100,0,700);
  GenTauEtaWithDMF_VLChar = fs->make<TH1F>(("GenTauEtaWithDMF_VLChar"+prefix).c_str() ,"GenTauEtaWithDMF_VLChar"  ,100,-5,5);
  GenTauPhiWithDMF_VLChar = fs->make<TH1F>(("GenTauPhiWithDMF_VLChar"+prefix).c_str() ,"GenTauPhiWithDMF_VLChar"  ,100,-5,5);

  TauPtResponse_LChar = fs->make<TH1F>(("TauPtResponse_LChar"+prefix).c_str() ,"TauPtResponse_LChar",100,0.1,2.0);
  RecoTauDecayMode_LChar = fs->make<TH1F>(("RecoTauDecayMode_LChar"+prefix).c_str() ,"RecoTauDecayMode_LChar",15,0,15);
  GenTauDecayMode_LChar = fs->make<TH1F>(("GenTauDecayMode_LChar"+prefix).c_str() ,"GenTauDecayMode_LChar",15,0,15);
  reco_dm_vs_gen_LChar = fs->make<TH2F>(("reco_dm_vs_gen_LChar"+prefix).c_str() ,"reco_dm_vs_gen_LChar",15,0,15,15,0,15);
  GenTauPtWithDMF_LChar = fs->make<TH1F>(("GenTauPtWithDMF_LChar"+prefix).c_str() ,"GenTauPtWithDMF_LChar" ,100,0,700);
  GenTauEtaWithDMF_LChar = fs->make<TH1F>(("GenTauEtaWithDMF_LChar"+prefix).c_str() ,"GenTauEtaWithDMF_LChar"  ,100,-5,5);
  GenTauPhiWithDMF_LChar = fs->make<TH1F>(("GenTauPhiWithDMF_LChar"+prefix).c_str() ,"GenTauPhiWithDMF_LChar"  ,100,-5,5);

  TauPtResponse_MChar = fs->make<TH1F>(("TauPtResponse_MChar"+prefix).c_str() ,"TauPtResponse_MChar",100,0.1,2.0);
  RecoTauDecayMode_MChar = fs->make<TH1F>(("RecoTauDecayMode_MChar"+prefix).c_str() ,"RecoTauDecayMode_MChar",15,0,15);
  GenTauDecayMode_MChar = fs->make<TH1F>(("GenTauDecayMode_MChar"+prefix).c_str() ,"GenTauDecayMode_MChar",15,0,15);
  reco_dm_vs_gen_MChar = fs->make<TH2F>(("reco_dm_vs_gen_MChar"+prefix).c_str() ,"reco_dm_vs_gen_MChar",15,0,15,15,0,15);
  GenTauPtWithDMF_MChar = fs->make<TH1F>(("GenTauPtWithDMF_MChar"+prefix).c_str() ,"GenTauPtWithDMF_MChar" ,100,0,700);
  GenTauEtaWithDMF_MChar = fs->make<TH1F>(("GenTauEtaWithDMF_MChar"+prefix).c_str() ,"GenTauEtaWithDMF_MChar"  ,100,-5,5);
  GenTauPhiWithDMF_MChar = fs->make<TH1F>(("GenTauPhiWithDMF_MChar"+prefix).c_str() ,"GenTauPhiWithDMF_MChar"  ,100,-5,5);

  TauPtResponse_TChar = fs->make<TH1F>(("TauPtResponse_TChar"+prefix).c_str() ,"TauPtResponse_TChar",100,0.1,2.0);
  RecoTauDecayMode_TChar = fs->make<TH1F>(("RecoTauDecayMode_TChar"+prefix).c_str() ,"RecoTauDecayMode_TChar",15,0,15);
  GenTauDecayMode_TChar = fs->make<TH1F>(("GenTauDecayMode_TChar"+prefix).c_str() ,"GenTauDecayMode_TChar",15,0,15);
  reco_dm_vs_gen_TChar = fs->make<TH2F>(("reco_dm_vs_gen_TChar"+prefix).c_str() ,"reco_dm_vs_gen_TChar",15,0,15,15,0,15);
  GenTauPtWithDMF_TChar = fs->make<TH1F>(("GenTauPtWithDMF_TChar"+prefix).c_str() ,"GenTauPtWithDMF_TChar" ,100,0,700);
  GenTauEtaWithDMF_TChar = fs->make<TH1F>(("GenTauEtaWithDMF_TChar"+prefix).c_str() ,"GenTauEtaWithDMF_TChar"  ,100,-5,5);
  GenTauPhiWithDMF_TChar = fs->make<TH1F>(("GenTauPhiWithDMF_TChar"+prefix).c_str() ,"GenTauPhiWithDMF_TChar"  ,100,-5,5);

  GenTauPtWithoutDMF = fs->make<TH1F>(("GenTauPtWithoutDMF"+prefix).c_str(), "GenTauPtWithoutDMF",100,0,700); 
  GenTauEtaWithoutDMF = fs->make<TH1F>(("GenTauEtaWithoutDMF"+prefix).c_str() ,"GenTauEtaWithoutDMF",100,-5,5);
  GenTauPhiWithoutDMF = fs->make<TH1F>(("GenTauPhiWithoutDMF"+prefix).c_str() ,"GenTauPhiWithoutDMF",100,-5,5);
  
  //
  TauPtResponse_LooseRho = fs->make<TH1F>(("TauPtResponse_LooseRho"+prefix).c_str() ,"TauPtResponse_LooseRho",100,0.1,2.0);
  RecoTauDecayMode_LooseRho = fs->make<TH1F>(("RecoTauDecayMode_LooseRho"+prefix).c_str() ,"RecoTauDecayMode_LooseRho",15,0,15);
  GenTauDecayMode_LooseRho = fs->make<TH1F>(("GenTauDecayMode_LooseRho"+prefix).c_str() ,"GenTauDecayMode_LooseRho",15,0,15);
  reco_dm_vs_gen_LooseRho = fs->make<TH2F>(("reco_dm_vs_gen_LooseRho"+prefix).c_str() ,"reco_dm_vs_gen_LooseRho",15,0,15,15,0,15);
  
  GenTauPtWithDMF_LooseRho = fs->make<TH1F>(("GenTauPtWithDMF_LooseRho"+prefix).c_str(), "GenTauPtWithDMF_LooseRho",100,0,700);
  GenTauEtaWithDMF_LooseRho = fs->make<TH1F>(("GenTauEtaWithDMF_LooseRho"+prefix).c_str() ,"GenTauEtaWithDMF_LooseRho",100,-5,5);
  GenTauPhiWithDMF_LooseRho = fs->make<TH1F>(("GenTauPhiWithDMF_LooseRho"+prefix).c_str() ,"GenTauPhiWithDMF_LooseRho",100,-5,5);
  
  TauPtResponse_MediumRho = fs->make<TH1F>(("TauPtResponse_MediumRho"+prefix).c_str() ,"TauPtResponse_MediumRho",100,0.1,2.0);
  RecoTauDecayMode_MediumRho = fs->make<TH1F>(("RecoTauDecayMode_MediumRho"+prefix).c_str() ,"RecoTauDecayMode_MediumRho",15,0,15);
  GenTauDecayMode_MediumRho = fs->make<TH1F>(("GenTauDecayMode_MediumRho"+prefix).c_str() ,"GenTauDecayMode_MediumRho",15,0,15);
  reco_dm_vs_gen_MediumRho = fs->make<TH2F>(("reco_dm_vs_gen_MediumRho"+prefix).c_str() ,"reco_dm_vs_gen_MediumRho",15,0,15,15,0,15);
  GenTauPtWithDMF_MediumRho = fs->make<TH1F>(("GenTauPtWithDMF_MediumRho"+prefix).c_str(), "GenTauPtWithDMF_MediumRho",100,0,700);
  GenTauEtaWithDMF_MediumRho = fs->make<TH1F>(("GenTauEtaWithDMF_MediumRho"+prefix).c_str() ,"GenTauEtaWithDMF_MediumRho",100,-5,5);
  GenTauPhiWithDMF_MediumRho = fs->make<TH1F>(("GenTauPhiWithDMF_MediumRho"+prefix).c_str() ,"GenTauPhiWithDMF_MediumRho",100,-5,5);
  
  TauPtResponse_TightRho = fs->make<TH1F>(("TauPtResponse_TightRho"+prefix).c_str() ,"TauPtResponse_TightRho",100,0.1,2.0);
  RecoTauDecayMode_TightRho = fs->make<TH1F>(("RecoTauDecayMode_TightRho"+prefix).c_str() ,"RecoTauDecayMode_TightRho",15,0,15);
  GenTauDecayMode_TightRho = fs->make<TH1F>(("GenTauDecayMode_TightRho"+prefix).c_str() ,"GenTauDecayMode_TightRho",15,0,15);
  reco_dm_vs_gen_TightRho = fs->make<TH2F>(("reco_dm_vs_gen_TightRho"+prefix).c_str() ,"reco_dm_vs_gen_TightRho",15,0,15,15,0,15);
  
  GenTauPtWithDMF_TightRho = fs->make<TH1F>(("GenTauPtWithDMF_TightRho"+prefix).c_str(), "GenTauPtWithDMF_TightRho",100,0,700);
  GenTauEtaWithDMF_TightRho = fs->make<TH1F>(("GenTauEtaWithDMF_TightRho"+prefix).c_str() ,"GenTauEtaWithDMF_TightRho",100,-5,5);
  GenTauPhiWithDMF_TightRho = fs->make<TH1F>(("GenTauPhiWithDMF_TightRho"+prefix).c_str() ,"GenTauPhiWithDMF_TightRho",100,-5,5);

  h_RunNumber = fs->make<TH1F>(("h_RunNumber"+prefix).c_str() ,"h_RunNumber",100000,0,100000);
  h_EventNumber = fs->make<TH1F>(("h_EventNumber"+prefix).c_str() ,"h_EventNumber",100000,0,100000);
  h_LumiNumber = fs->make<TH1F>(("h_LumiNumber"+prefix).c_str() ,"h_LumiNumber",100000,0,100000);
  h_BXNumber = fs->make<TH1F>(("h_BXNumber"+prefix).c_str() ,"h_BXNumber",100,0,100);

 GenTauPtEta_ML2  = fs->make<TH2F>(("GenTauPtEta_ML2"+prefix).c_str() ,"GenTauPtEta_ML2",100,-5,5,100,0,700);
 GenTauPtEta_MM2  = fs->make<TH2F>(("GenTauPtEta_MM2"+prefix).c_str() ,"GenTauPtEta_MM2",100,-5,5,100,0,700);
 GenTauPtEta_MT2  = fs->make<TH2F>(("GenTauPtEta_MT2"+prefix).c_str() ,"GenTauPtEta_MT2",100,-5,5,100,0,700);

 GenTauPtEta_ML3  = fs->make<TH2F>(("GenTauPtEta_ML3"+prefix).c_str() ,"GenTauPtEta_ML3",100,-5,5,100,0,700);
 GenTauPtEta_MT3  = fs->make<TH2F>(("GenTauPtEta_MT3"+prefix).c_str() ,"GenTauPtEta_MT3",100,-5,5,100,0,700);

 GenTauPtEta_LIsoPtSum = fs->make<TH2F>(("GenTauPtEta_LIsoPtSum"+prefix).c_str() ,"GenTauPtEta_LIsoPtSum",100,-5,5,100,0,700);
 GenTauPtEta_MIsoPtSum = fs->make<TH2F>(("GenTauPtEta_MIsoPtSum"+prefix).c_str() ,"GenTauPtEta_MIsoPtSum",100,-5,5,100,0,700);
 GenTauPtEta_TIsoPtSum = fs->make<TH2F>(("GenTauPtEta_TIsoPtSum"+prefix).c_str() ,"GenTauPtEta_TIsoPtSum",100,-5,5,100,0,700); 

 GenTauPtEta_LIsoPtSumN = fs->make<TH2F>(("GenTauPtEta_LIsoPtSumN"+prefix).c_str() ,"GenTauPtEta_LIsoPtSumN",100,-5,5,100,0,700);
 GenTauPtEta_MIsoPtSumN = fs->make<TH2F>(("GenTauPtEta_MIsoPtSumN"+prefix).c_str() ,"GenTauPtEta_MIsoPtSumN",100,-5,5,100,0,700);
 GenTauPtEta_TIsoPtSumN = fs->make<TH2F>(("GenTauPtEta_TIsoPtSumN"+prefix).c_str() ,"GenTauPtEta_TIsoPtSumN",100,-5,5,100,0,700); 

 GenTauPtEta_LIsoPtSumN2 = fs->make<TH2F>(("GenTauPtEta_LIsoPtSumN2"+prefix).c_str() ,"GenTauPtEta_LIsoPtSumN2",100,-5,5,100,0,700);
 GenTauPtEta_MIsoPtSumN2 = fs->make<TH2F>(("GenTauPtEta_MIsoPtSumN2"+prefix).c_str() ,"GenTauPtEta_MIsoPtSumN2",100,-5,5,100,0,700);
 GenTauPtEta_TIsoPtSumN2 = fs->make<TH2F>(("GenTauPtEta_TIsoPtSumN2"+prefix).c_str() ,"GenTauPtEta_TIsoPtSumN2",100,-5,5,100,0,700); 

 GenTauPtEta_Den = fs->make<TH2F>(("GenTauPtEta_Den"+prefix).c_str() ,"GenTauPtEta_Den",100,-5,5,100,0,700); 

 GenTauPtEta_Iso1 = fs->make<TH2F>(("GenTauPtEta_Iso1"+prefix).c_str() ,"GenTauPtEta_Iso1",100,-5,5,100,0,700); 

 GenTauPtEta_Iso2 = fs->make<TH2F>(("GenTauPtEta_Iso2"+prefix).c_str() ,"GenTauPtEta_Iso2",100,-5,5,100,0,700); 

 GenTauPtEta_Iso4 = fs->make<TH2F>(("GenTauPtEta_Iso4"+prefix).c_str() ,"GenTauPtEta_Iso4",100,-5,5,100,0,700); 

 GenTauPtEta_Combined = fs->make<TH2F>(("GenTauPtEta_Combined"+prefix).c_str() ,"GenTauPtEta_Combined",100,-5,5,100,0,700); 

 GenTauPtEta_CombinedL = fs->make<TH2F>(("GenTauPtEta_CombinedL"+prefix).c_str() ,"GenTauPtEta_CombinedL",100,-5,5,100,0,700); 

 GenTauPtEta_CombinedT = fs->make<TH2F>(("GenTauPtEta_CombinedT"+prefix).c_str() ,"GenTauPtEta_CombinedT",100,-5,5,100,0,700); 

  GenTauPtEta_Cut = fs->make<TH2F>(("GenTauPtEta_Cut"+prefix).c_str() ,"GenTauPtEta_Cut",100,-5,5,100,0,700); 

  GenTauPtEtaWithDMF  = fs->make<TH2F>(("GenTauPtEtaWithDMF"+prefix).c_str() ,"GenTauPtEtaWithDMF",100,-5,5,100,0,700);

  N_Vtx_BX_PU_events = fs->make<TH1F>(("N_Vtx_BX_PU_events"+prefix).c_str() ,"N_Vtx_BX_PU_events",700,0,700);
 N_Vtx_BX_true_events = fs->make<TH1F>(("N_Vtx_BX_true_events"+prefix).c_str() ,"N_Vtx_BX_true_events",700,0,700);
 N_Vtx_BX0_PU_events = fs->make<TH1F>(("N_Vtx_BX0_PU_events"+prefix).c_str() ,"N_Vtx_BX0_PU_events",700,0,700);
 N_Vtx_BX0_true_events  = fs->make<TH1F>(("N_Vtx_BX0_true_events"+prefix).c_str() ,"N_Vtx_BX0_true_events",700,0,700); 

 N_Vtx_BX_PU_Den = fs->make<TH1F>(("N_Vtx_BX_PU_Den"+prefix).c_str() ,"N_Vtx_BX_PU_Den",700,0,700);
 N_Vtx_BX_true_Den = fs->make<TH1F>(("N_Vtx_BX_true_Den"+prefix).c_str() ,"N_Vtx_BX_true_Den",700,0,700);
 N_Vtx_BX0_PU_Den = fs->make<TH1F>(("N_Vtx_BX0_PU_Den"+prefix).c_str() ,"N_Vtx_BX0_PU_Den",700,0,700);
 N_Vtx_BX0_true_Den  = fs->make<TH1F>(("N_Vtx_BX0_true_Den"+prefix).c_str() ,"N_Vtx_BX0_true_Den",700,0,700); 



 N_Vtx_BX_PUWithDMF = fs->make<TH1F>(("N_Vtx_BX_PUWithDMF"+prefix).c_str() ,"N_Vtx_BX_PUWithDMF",700,0,700);
 N_Vtx_BX_trueWithDMF = fs->make<TH1F>(("N_Vtx_BX_trueWithDMF"+prefix).c_str() ,"N_Vtx_BX_trueWithDMF",700,0,700);
 N_Vtx_BX0_PUWithDMF = fs->make<TH1F>(("N_Vtx_BX0_PUWithDMF"+prefix).c_str() ,"N_Vtx_BX0_PUWithDMF",700,0,700);
 N_Vtx_BX0_trueWithDMF  = fs->make<TH1F>(("N_Vtx_BX0_trueWithDMF"+prefix).c_str() ,"N_Vtx_BX0_trueWithDMF",700,0,700); 


 N_Vtx_BX_PU_all = fs->make<TH1F>(("N_Vtx_BX_PU_all"+prefix).c_str() ,"N_Vtx_BX_PU_all",700,0,700);
 N_Vtx_BX_true_all = fs->make<TH1F>(("N_Vtx_BX_true_all"+prefix).c_str() ,"N_Vtx_BX_true_all",700,0,700);
 N_Vtx_BX0_PU_all = fs->make<TH1F>(("N_Vtx_BX0_PU_all"+prefix).c_str() ,"N_Vtx_BX0_PU_all",700,0,700);
 N_Vtx_BX0_true_all  = fs->make<TH1F>(("N_Vtx_BX0_true_all"+prefix).c_str() ,"N_Vtx_BX0_true_all",700,0,700); 


 N_Vtx_BX_PU_Iso1 = fs->make<TH1F>(("N_Vtx_BX_PU_Iso1"+prefix).c_str() ,"N_Vtx_BX_PU_Iso1",700,0,700);
 N_Vtx_BX_true_Iso1 = fs->make<TH1F>(("N_Vtx_BX_true_Iso1"+prefix).c_str() ,"N_Vtx_BX_true_Iso1",700,0,700);
 N_Vtx_BX0_PU_Iso1 = fs->make<TH1F>(("N_Vtx_BX0_PU_Iso1"+prefix).c_str() ,"N_Vtx_BX0_PU_Iso1",700,0,700);
 N_Vtx_BX0_true_Iso1  = fs->make<TH1F>(("N_Vtx_BX0_true_Iso1"+prefix).c_str() ,"N_Vtx_BX0_true_Iso1",700,0,700); 

 N_Vtx_BX_PU_Iso2 = fs->make<TH1F>(("N_Vtx_BX_PU_Iso2"+prefix).c_str() ,"N_Vtx_BX_PU_Iso2",700,0,700);
 N_Vtx_BX_true_Iso2 = fs->make<TH1F>(("N_Vtx_BX_true_Iso2"+prefix).c_str() ,"N_Vtx_BX_true_Iso2",700,0,700);
 N_Vtx_BX0_PU_Iso2 = fs->make<TH1F>(("N_Vtx_BX0_PU_Iso2"+prefix).c_str() ,"N_Vtx_BX0_PU_Iso2",700,0,700);
 N_Vtx_BX0_true_Iso2  = fs->make<TH1F>(("N_Vtx_BX0_true_Iso2"+prefix).c_str() ,"N_Vtx_BX0_true_Iso2",700,0,700); 
   
 N_Vtx_BX_PU_Iso4 = fs->make<TH1F>(("N_Vtx_BX_PU_Iso4"+prefix).c_str() ,"N_Vtx_BX_PU_Iso4",700,0,700);
 N_Vtx_BX_true_Iso4 = fs->make<TH1F>(("N_Vtx_BX_true_Iso4"+prefix).c_str() ,"N_Vtx_BX_true_Iso4",700,0,700);
 N_Vtx_BX0_PU_Iso4 = fs->make<TH1F>(("N_Vtx_BX0_PU_Iso4"+prefix).c_str() ,"N_Vtx_BX0_PU_Iso4",700,0,700);
 N_Vtx_BX0_true_Iso4  = fs->make<TH1F>(("N_Vtx_BX0_true_Iso4"+prefix).c_str() ,"N_Vtx_BX0_true_Iso4",700,0,700); 

 N_Vtx_BX_PU_LIsoPtSum = fs->make<TH1F>(("N_Vtx_BX_PU_LIsoPtSum"+prefix).c_str() ,"N_Vtx_BX_PU_LIsoPtSum",700,0,700);
 N_Vtx_BX_true_LIsoPtSum = fs->make<TH1F>(("N_Vtx_BX_true_LIsoPtSum"+prefix).c_str() ,"N_Vtx_BX_true_LIsoPtSum",700,0,700);
 N_Vtx_BX0_PU_LIsoPtSum = fs->make<TH1F>(("N_Vtx_BX0_PU_LIsoPtSum"+prefix).c_str() ,"N_Vtx_BX0_PU_LIsoPtSum",700,0,700);
 N_Vtx_BX0_true_LIsoPtSum  = fs->make<TH1F>(("N_Vtx_BX0_true_LIsoPtSum"+prefix).c_str() ,"N_Vtx_BX0_true_LIsoPtSum",700,0,700); 

  N_Vtx_BX_PU_MIsoPtSum = fs->make<TH1F>(("N_Vtx_BX_PU_MIsoPtSum"+prefix).c_str() ,"N_Vtx_BX_PU_MIsoPtSum",700,0,700);
 N_Vtx_BX_true_MIsoPtSum = fs->make<TH1F>(("N_Vtx_BX_true_MIsoPtSum"+prefix).c_str() ,"N_Vtx_BX_true_MIsoPtSum",700,0,700);
 N_Vtx_BX0_PU_MIsoPtSum = fs->make<TH1F>(("N_Vtx_BX0_PU_MIsoPtSum"+prefix).c_str() ,"N_Vtx_BX0_PU_MIsoPtSum",700,0,700);
 N_Vtx_BX0_true_MIsoPtSum  = fs->make<TH1F>(("N_Vtx_BX0_true_MIsoPtSum"+prefix).c_str() ,"N_Vtx_BX0_true_MIsoPtSum",700,0,700); 


 N_Vtx_BX_PU_TIsoPtSum = fs->make<TH1F>(("N_Vtx_BX_PU_TIsoPtSum"+prefix).c_str() ,"N_Vtx_BX_PU_TIsoPtSum",700,0,700);
 N_Vtx_BX_true_TIsoPtSum = fs->make<TH1F>(("N_Vtx_BX_true_TIsoPtSum"+prefix).c_str() ,"N_Vtx_BX_true_TIsoPtSum",700,0,700);
 N_Vtx_BX0_PU_TIsoPtSum = fs->make<TH1F>(("N_Vtx_BX0_PU_TIsoPtSum"+prefix).c_str() ,"N_Vtx_BX0_PU_TIsoPtSum",700,0,700);
 N_Vtx_BX0_true_TIsoPtSum  = fs->make<TH1F>(("N_Vtx_BX0_true_TIsoPtSum"+prefix).c_str() ,"N_Vtx_BX0_true_TIsoPtSum",700,0,700); 


 N_Vtx_BX_PU_LIsoPtSumN = fs->make<TH1F>(("N_Vtx_BX_PU_LIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX_PU_LIsoPtSumN",700,0,700);
 N_Vtx_BX_true_LIsoPtSumN = fs->make<TH1F>(("N_Vtx_BX_true_LIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX_true_LIsoPtSumN",700,0,700);
 N_Vtx_BX0_PU_LIsoPtSumN = fs->make<TH1F>(("N_Vtx_BX0_PU_LIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX0_PU_LIsoPtSumN",700,0,700);
 N_Vtx_BX0_true_LIsoPtSumN  = fs->make<TH1F>(("N_Vtx_BX0_true_LIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX0_true_LIsoPtSumN",700,0,700); 

  N_Vtx_BX_PU_MIsoPtSumN = fs->make<TH1F>(("N_Vtx_BX_PU_MIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX_PU_MIsoPtSumN",700,0,700);
 N_Vtx_BX_true_MIsoPtSumN = fs->make<TH1F>(("N_Vtx_BX_true_MIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX_true_MIsoPtSumN",700,0,700);
 N_Vtx_BX0_PU_MIsoPtSumN = fs->make<TH1F>(("N_Vtx_BX0_PU_MIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX0_PU_MIsoPtSumN",700,0,700);
 N_Vtx_BX0_true_MIsoPtSumN  = fs->make<TH1F>(("N_Vtx_BX0_true_MIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX0_true_MIsoPtSumN",700,0,700); 


 N_Vtx_BX_PU_TIsoPtSumN = fs->make<TH1F>(("N_Vtx_BX_PU_TIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX_PU_TIsoPtSumN",700,0,700);
 N_Vtx_BX_true_TIsoPtSumN = fs->make<TH1F>(("N_Vtx_BX_true_TIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX_true_TIsoPtSumN",700,0,700);
 N_Vtx_BX0_PU_TIsoPtSumN = fs->make<TH1F>(("N_Vtx_BX0_PU_TIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX0_PU_TIsoPtSumN",700,0,700);
 N_Vtx_BX0_true_TIsoPtSumN  = fs->make<TH1F>(("N_Vtx_BX0_true_TIsoPtSumN"+prefix).c_str() ,"N_Vtx_BX0_true_TIsoPtSumN",700,0,700); 


 N_Vtx_BX_PU_LIsoPtSumN2 = fs->make<TH1F>(("N_Vtx_BX_PU_LIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX_PU_LIsoPtSumN2",700,0,700);
 N_Vtx_BX_true_LIsoPtSumN2 = fs->make<TH1F>(("N_Vtx_BX_true_LIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX_true_LIsoPtSumN2",700,0,700);
 N_Vtx_BX0_PU_LIsoPtSumN2 = fs->make<TH1F>(("N_Vtx_BX0_PU_LIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX0_PU_LIsoPtSumN2",700,0,700);
 N_Vtx_BX0_true_LIsoPtSumN2  = fs->make<TH1F>(("N_Vtx_BX0_true_LIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX0_true_LIsoPtSumN2",700,0,700); 

  N_Vtx_BX_PU_MIsoPtSumN2 = fs->make<TH1F>(("N_Vtx_BX_PU_MIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX_PU_MIsoPtSumN2",700,0,700);
 N_Vtx_BX_true_MIsoPtSumN2 = fs->make<TH1F>(("N_Vtx_BX_true_MIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX_true_MIsoPtSumN2",700,0,700);
 N_Vtx_BX0_PU_MIsoPtSumN2 = fs->make<TH1F>(("N_Vtx_BX0_PU_MIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX0_PU_MIsoPtSumN2",700,0,700);
 N_Vtx_BX0_true_MIsoPtSumN2  = fs->make<TH1F>(("N_Vtx_BX0_true_MIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX0_true_MIsoPtSumN2",700,0,700); 

  
 N_Vtx_BX_PU_TIsoPtSumN2 = fs->make<TH1F>(("N_Vtx_BX_PU_TIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX_PU_TIsoPtSumN2",700,0,700);
 N_Vtx_BX_true_TIsoPtSumN2 = fs->make<TH1F>(("N_Vtx_BX_true_TIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX_true_TIsoPtSumN2",700,0,700);
 N_Vtx_BX0_PU_TIsoPtSumN2 = fs->make<TH1F>(("N_Vtx_BX0_PU_TIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX0_PU_TIsoPtSumN2",700,0,700);
 N_Vtx_BX0_true_TIsoPtSumN2  = fs->make<TH1F>(("N_Vtx_BX0_true_TIsoPtSumN2"+prefix).c_str() ,"N_Vtx_BX0_true_TIsoPtSumN2",200,0, 200); 


 N_Vtx_BX_PU_Combined = fs->make<TH1F>(("N_Vtx_BX_PU_Combined"+prefix).c_str() ,"N_Vtx_BX_PU_Combined",700,0,700);
 N_Vtx_BX_true_Combined = fs->make<TH1F>(("N_Vtx_BX_true_Combined"+prefix).c_str() ,"N_Vtx_BX_true_Combined",700,0,700);
 N_Vtx_BX0_PU_Combined = fs->make<TH1F>(("N_Vtx_BX0_PU_Combined"+prefix).c_str() ,"N_Vtx_BX0_PU_Combined",700,0,700);
 N_Vtx_BX0_true_Combined  = fs->make<TH1F>(("N_Vtx_BX0_true_Combined"+prefix).c_str() ,"N_Vtx_BX0_true_Combined",700,0,700); 



 N_Vtx_BX_PU_CombinedL = fs->make<TH1F>(("N_Vtx_BX_PU_CombinedL"+prefix).c_str() ,"N_Vtx_BX_PU_CombinedL",700,0,700);
 N_Vtx_BX_true_CombinedL = fs->make<TH1F>(("N_Vtx_BX_true_CombinedL"+prefix).c_str() ,"N_Vtx_BX_true_CombinedL",700,0,700);
 N_Vtx_BX0_PU_CombinedL = fs->make<TH1F>(("N_Vtx_BX0_PU_CombinedL"+prefix).c_str() ,"N_Vtx_BX0_PU_CombinedL",700,0,700);
 N_Vtx_BX0_true_CombinedL  = fs->make<TH1F>(("N_Vtx_BX0_true_CombinedL"+prefix).c_str() ,"N_Vtx_BX0_true_CombinedL",700,0,700); 



 N_Vtx_BX_PU_CombinedT = fs->make<TH1F>(("N_Vtx_BX_PU_CombinedT"+prefix).c_str() ,"N_Vtx_BX_PU_CombinedT",700,0,700);
 N_Vtx_BX_true_CombinedT = fs->make<TH1F>(("N_Vtx_BX_true_CombinedT"+prefix).c_str() ,"N_Vtx_BX_true_CombinedT",700,0,700);
 N_Vtx_BX0_PU_CombinedT = fs->make<TH1F>(("N_Vtx_BX0_PU_CombinedT"+prefix).c_str() ,"N_Vtx_BX0_PU_CombinedT",700,0,700);
 N_Vtx_BX0_true_CombinedT  = fs->make<TH1F>(("N_Vtx_BX0_true_CombinedT"+prefix).c_str() ,"N_Vtx_BX0_true_CombinedT",700,0,700); 


 N_Vtx_BX_PU_ML2 = fs->make<TH1F>(("N_Vtx_BX_PU_ML2"+prefix).c_str() ,"N_Vtx_BX_PU_ML2",700,0,700);
 N_Vtx_BX_true_ML2 = fs->make<TH1F>(("N_Vtx_BX_true_ML2"+prefix).c_str() ,"N_Vtx_BX_true_ML2",700,0,700);
 N_Vtx_BX0_PU_ML2 = fs->make<TH1F>(("N_Vtx_BX0_PU_ML2"+prefix).c_str() ,"N_Vtx_BX0_PU_ML2",700,0,700);
 N_Vtx_BX0_true_ML2  = fs->make<TH1F>(("N_Vtx_BX0_true_ML2"+prefix).c_str() ,"N_Vtx_BX0_true_ML2",700,0,700); 


 N_Vtx_BX_PU_MT2 = fs->make<TH1F>(("N_Vtx_BX_PU_MT2"+prefix).c_str() ,"N_Vtx_BX_PU_MT2",700,0,700);
 N_Vtx_BX_true_MT2 = fs->make<TH1F>(("N_Vtx_BX_true_MT2"+prefix).c_str() ,"N_Vtx_BX_true_MT2",700,0,700);
 N_Vtx_BX0_PU_MT2 = fs->make<TH1F>(("N_Vtx_BX0_PU_MT2"+prefix).c_str() ,"N_Vtx_BX0_PU_MT2",700,0,700);
 N_Vtx_BX0_true_MT2  = fs->make<TH1F>(("N_Vtx_BX0_true_MT2"+prefix).c_str() ,"N_Vtx_BX0_true_MT2",700,0,700); 

 N_Vtx_BX_PU_MM2 = fs->make<TH1F>(("N_Vtx_BX_PU_MM2"+prefix).c_str() ,"N_Vtx_BX_PU_MM2",700,0,700);
 N_Vtx_BX_true_MM2 = fs->make<TH1F>(("N_Vtx_BX_true_MM2"+prefix).c_str() ,"N_Vtx_BX_true_MM2",700,0,700);
 N_Vtx_BX0_PU_MM2 = fs->make<TH1F>(("N_Vtx_BX0_PU_MM2"+prefix).c_str() ,"N_Vtx_BX0_PU_MM2",700,0,700);
 N_Vtx_BX0_true_MM2  = fs->make<TH1F>(("N_Vtx_BX0_true_MM2"+prefix).c_str() ,"N_Vtx_BX0_true_MM2",700,0,700); 


 N_Vtx_BX_PU_ML3 = fs->make<TH1F>(("N_Vtx_BX_PU_ML3"+prefix).c_str() ,"N_Vtx_BX_PU_ML3",700,0,700);
 N_Vtx_BX_true_ML3 = fs->make<TH1F>(("N_Vtx_BX_true_ML3"+prefix).c_str() ,"N_Vtx_BX_true_ML3",700,0,700);
 N_Vtx_BX0_PU_ML3 = fs->make<TH1F>(("N_Vtx_BX0_PU_ML3"+prefix).c_str() ,"N_Vtx_BX0_PU_ML3",700,0,700);
 N_Vtx_BX0_true_ML3  = fs->make<TH1F>(("N_Vtx_BX0_true_ML3"+prefix).c_str() ,"N_Vtx_BX0_true_ML3",700,0,700); 


 N_Vtx_BX_PU_MT3 = fs->make<TH1F>(("N_Vtx_BX_PU_MT3"+prefix).c_str() ,"N_Vtx_BX_PU_MT3",700,0,700);
 N_Vtx_BX_true_MT3 = fs->make<TH1F>(("N_Vtx_BX_true_MT3"+prefix).c_str() ,"N_Vtx_BX_true_MT3",700,0,700);
 N_Vtx_BX0_PU_MT3 = fs->make<TH1F>(("N_Vtx_BX0_PU_MT3"+prefix).c_str() ,"N_Vtx_BX0_PU_MT3",700,0,700);
 N_Vtx_BX0_true_MT3  = fs->make<TH1F>(("N_Vtx_BX0_true_MT3"+prefix).c_str() ,"N_Vtx_BX0_true_MT3",700,0,700); 


 N_Vtx_BX_PU_EL3 = fs->make<TH1F>(("N_Vtx_BX_PU_EL3"+prefix).c_str() ,"N_Vtx_BX_PU_EL3",700,0,700);
 N_Vtx_BX_true_EL3 = fs->make<TH1F>(("N_Vtx_BX_true_EL3"+prefix).c_str() ,"N_Vtx_BX_true_EL3",700,0,700);
 N_Vtx_BX0_PU_EL3 = fs->make<TH1F>(("N_Vtx_BX0_PU_EL3"+prefix).c_str() ,"N_Vtx_BX0_PU_EL3",700,0,700);
 N_Vtx_BX0_true_EL3  = fs->make<TH1F>(("N_Vtx_BX0_true_EL3"+prefix).c_str() ,"N_Vtx_BX0_true_EL3",700,0,700); 


 
 N_Vtx_BX_PU_EM3 = fs->make<TH1F>(("N_Vtx_BX_PU_EM3"+prefix).c_str() ,"N_Vtx_BX_PU_EM3",700,0,700);
 N_Vtx_BX_true_EM3 = fs->make<TH1F>(("N_Vtx_BX_true_EM3"+prefix).c_str() ,"N_Vtx_BX_true_EM3",700,0,700);
 N_Vtx_BX0_PU_EM3 = fs->make<TH1F>(("N_Vtx_BX0_PU_EM3"+prefix).c_str() ,"N_Vtx_BX0_PU_EM3",700,0,700);
 N_Vtx_BX0_true_EM3  = fs->make<TH1F>(("N_Vtx_BX0_true_EM3"+prefix).c_str() ,"N_Vtx_BX0_true_EM3",700,0,700); 

    

 N_Vtx_BX_PU_ET3 = fs->make<TH1F>(("N_Vtx_BX_PU_ET3"+prefix).c_str() ,"N_Vtx_BX_PU_ET3",700,0,700);
 N_Vtx_BX_true_ET3 = fs->make<TH1F>(("N_Vtx_BX_true_ET3"+prefix).c_str() ,"N_Vtx_BX_true_ET3",700,0,700);
 N_Vtx_BX0_PU_ET3 = fs->make<TH1F>(("N_Vtx_BX0_PU_ET3"+prefix).c_str() ,"N_Vtx_BX0_PU_ET3",700,0,700);
 N_Vtx_BX0_true_ET3  = fs->make<TH1F>(("N_Vtx_BX0_true_ET3"+prefix).c_str() ,"N_Vtx_BX0_true_ET3",700,0,700); 


 N_Vtx_BX_PU_Cut = fs->make<TH1F>(("N_Vtx_BX_PU_Cut"+prefix).c_str() ,"N_Vtx_BX_PU_Cut",700,0,700);
 N_Vtx_BX_true_Cut = fs->make<TH1F>(("N_Vtx_BX_true_Cut"+prefix).c_str() ,"N_Vtx_BX_true_Cut",700,0,700);
 N_Vtx_BX0_PU_Cut = fs->make<TH1F>(("N_Vtx_BX0_PU_Cut"+prefix).c_str() ,"N_Vtx_BX0_PU_Cut",700,0,700);
 N_Vtx_BX0_true_Cut  = fs->make<TH1F>(("N_Vtx_BX0_true_Cut"+prefix).c_str() ,"N_Vtx_BX0_true_Cut",700,0,700); 

 
}


NEWDecayMode::~NEWDecayMode()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void NEWDecayMode::Fill(const edm::Event& iEvent) {
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
 
    PUInfo_true_wo = 0;                                                                                            
    PUInfo = 0;
    PUInfo_Bunch0 = 0;
    PUInfo_true = 0;

   for (PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
     PUInfo += PVI->getPU_NumInteractions();
     PUInfo_true_wo = PVI->getTrueNumInteractions();
     if(PVI->getBunchCrossing()== 0){
       PUInfo_Bunch0 += PVI->getPU_NumInteractions();
       PUInfo_true = PVI->getTrueNumInteractions();
     }
   }

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
   
   bool isZtautau=false;
   isZtautau = IsZTauTau (_genParticles) ;
   
   int  nGoodVtx = 0;
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){
     
     if((vtxIt->isValid()) && !(vtxIt->isFake())) {
   
        if(vtxIt->ndof() < 4.) continue; 
        if(abs(vtxIt->z()) > 24.) continue;
       // if(passRecoVertexCuts(*vtxIt))
       double vtxdxy = sqrt((vtxIt->x()*vtxIt->x()) + (vtxIt->y()*vtxIt->y()));
       if(vtxdxy >= 2.0) continue; 
    
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
     

	 N_Vtx_BX_PU_events->Fill(PUInfo);
         N_Vtx_BX_true_events->Fill(PUInfo_true_wo);

	 N_Vtx_BX0_PU_events->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_events->Fill(PUInfo_true);

     for(reco::GenJetCollection::const_iterator gentaujet = genTauJets->begin(); gentaujet !=  genTauJets->end(); ++gentaujet) { 
       

	 N_Vtx_BX_PU_all->Fill(PUInfo);
         N_Vtx_BX_true_all->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_all->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_all->Fill(PUInfo_true);



       if(gentaujet->pt() <= 20 ) continue;
        if(fabs(gentaujet->eta()) <= etacutmin) continue; 
       if(fabs(gentaujet->eta()) >= etacut) continue;
       tauGenJetDecayModeInt = -999;
tauGenJetDecayModeIntfor3X3 = -999;
 tauGenJetDecayModeIntfor3X3reco  = -999;
         tauGenJetDecayModeIntfor3X3reco1  = -999; 
       std::string tauGenJetDecayMode = JetMCTagUtils::genTauDecayMode(*gentaujet);
       
       if(tauGenJetDecayMode=="muon") continue;
       if(tauGenJetDecayMode=="electron") continue;
       
       GenTauPt_Den->Fill(gentaujet->pt());
       GenTauEta_Den->Fill(gentaujet->eta());
       GenTauPhi_Den->Fill(gentaujet->phi());
       GenTauPtEta_Den->Fill(gentaujet->eta(),gentaujet->pt());

       Nvtx_Den->Fill(PUInfo_true);
       NGood_Den->Fill(nGoodVtx);

	 N_Vtx_BX_PU_Den->Fill(PUInfo);
         N_Vtx_BX_true_Den->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_Den->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_Den->Fill(PUInfo_true);

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
       GenTauPtEtaWithDMF->Fill(gentaujet->eta(),gentaujet->pt());       
       GenTauPiZeroCandidatesDMF->Fill(tauCandidate->signalPiZeroCandidates().size());
       GenTauHadronCandidatesDMF->Fill(tauCandidate->signalTauChargedHadronCandidates().size());

	 N_Vtx_BX_PUWithDMF->Fill(PUInfo);
         N_Vtx_BX_trueWithDMF->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PUWithDMF->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_trueWithDMF->Fill(PUInfo_true);

	 GenTauPtEtaWithDMF->Fill(gentaujet->eta(),gentaujet->pt());

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

       hNeutralIsoPtSumWeight1_vtx_dmf->Fill(PUInfo_true,(*_nw1)[tauCandidate] );
       hNeutralIsoPtSumWeight2_vtx_dmf->Fill(PUInfo_true,(*_nw2)[tauCandidate] );
       hNeutralIsoPtSumWeight1NQ_vtx_dmf->Fill(PUInfo_true,(*_nw1nq)[tauCandidate] );
       hNeutralIsoPtSumWeight2NQ_vtx_dmf->Fill(PUInfo_true,(*_nw2nq)[tauCandidate] );
       hNeutralHadronIsoPtSum_vtx_dmf->Fill(PUInfo_true,(*_h1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1_vtx_dmf->Fill(PUInfo_true,(*_hw1)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2_vtx_dmf->Fill(PUInfo_true,(*_hw2)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight1NQ_vtx_dmf->Fill(PUInfo_true,(*_hw1nq)[tauCandidate] );
       hNeutralHadronIsoPtSumWeight2NQ_vtx_dmf->Fill(PUInfo_true,(*_hw2nq)[tauCandidate] );
       hChargedIsoPtSum_vtx_dmf->Fill(PUInfo_true,(*_rawc)[tauCandidate] );
       hNeutralIsoPtSum_vtx_dmf->Fill(PUInfo_true,(*_rawn)[tauCandidate] );
       hPUcorrPtSum_vtx_dmf->Fill(PUInfo_true,(*_rawpu)[tauCandidate] );

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

       if(tauGenJetDecayMode=="oneProng0Pi0") { tauGenJetDecayModeIntfor3X3 = 0;}
if(tauGenJetDecayMode=="threeProng0Pi0") { tauGenJetDecayModeIntfor3X3 = 2;}
  if((tauGenJetDecayMode=="oneProng1Pi0") || (tauGenJetDecayMode=="oneProng2Pi0" )) { tauGenJetDecayModeIntfor3X3 = 1;}

 if(tauCandidate->decayMode() == 0) {tauGenJetDecayModeIntfor3X3reco = 0;}
if((tauCandidate->decayMode() == 1) || (tauCandidate->decayMode() == 2)) {tauGenJetDecayModeIntfor3X3reco=1;}            
 
      if(tauCandidate->decayMode() == 10) {tauGenJetDecayModeIntfor3X3reco = 2;}

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
       reco_dm_vs_gen_dm1->Fill(tauGenJetDecayModeIntfor3X3, tauGenJetDecayModeIntfor3X3reco);
       Nvtx_DM->Fill(PUInfo_true);
       NGood_DM->Fill(nGoodVtx);
       
       /// other definitions


       double iso = (((*_rawc)[tauCandidate]) + ((*_nw2nq)[tauCandidate]));

       // isolation first option                                                                                                    


       if(iso < 1.) {
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
	 Nvtx_Iso1->Fill(PUInfo_true);
	 NGood_Iso1->Fill(nGoodVtx);
   GenTauPtEta_Iso1->Fill(gentaujet->eta(),gentaujet->pt());  
	 N_Vtx_BX_PU_Iso1->Fill(PUInfo);
         N_Vtx_BX_true_Iso1->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_Iso1->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_Iso1->Fill(PUInfo_true);

      
       }


       if(iso < 2.) {

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
	 Nvtx_Iso2->Fill(PUInfo_true);
	 NGood_Iso2->Fill(nGoodVtx);
	 GenTauPtEta_Iso2->Fill(gentaujet->eta(),gentaujet->pt());    

	 N_Vtx_BX_PU_Iso2->Fill(PUInfo);
         N_Vtx_BX_true_Iso2->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_Iso2->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_Iso2->Fill(PUInfo_true);

       }

       if(iso < 4.) {
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
	 Nvtx_Iso4->Fill(PUInfo_true);
         NGood_Iso4->Fill(nGoodVtx);
	 GenTauPtEta_Iso4->Fill(gentaujet->eta(),gentaujet->pt()); 

	 N_Vtx_BX_PU_Iso4->Fill(PUInfo);
         N_Vtx_BX_true_Iso4->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_Iso4->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_Iso4->Fill(PUInfo_true);

       }


       if((*_rawc)[tauCandidate] < 4.) {
	 
	 
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
	 Nvtx_LIsoPtSum->Fill(PUInfo_true);
	 NGood_LIsoPtSum->Fill(nGoodVtx);
	 GenTauPtEta_LIsoPtSum->Fill(gentaujet->eta(),gentaujet->pt()); 

	 N_Vtx_BX_PU_LIsoPtSum->Fill(PUInfo);
         N_Vtx_BX_true_LIsoPtSum->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_LIsoPtSum->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_LIsoPtSum->Fill(PUInfo_true);



       }
       
       
       if((*_rawc)[tauCandidate] < 2.) {
	 
	 
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
	 Nvtx_MIsoPtSum->Fill(PUInfo_true);
	 NGood_MIsoPtSum->Fill(nGoodVtx);
	 GenTauPtEta_MIsoPtSum->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_MIsoPtSum->Fill(PUInfo);
         N_Vtx_BX_true_MIsoPtSum->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_MIsoPtSum->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_MIsoPtSum->Fill(PUInfo_true);

       }


       if((*_rawn)[tauCandidate] < 4.) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_LIsoPtSumN->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_LIsoPtSumN->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
 }
	 
	 RecoTauDecayMode_LIsoPtSumN->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_LIsoPtSumN->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_LIsoPtSumN->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
 
	 GenTauPtWithDMF_LIsoPtSumN->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_LIsoPtSumN->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_LIsoPtSumN->Fill(gentaujet->phi());
	 Nvtx_LIsoPtSumN->Fill(PUInfo_true);
	 NGood_LIsoPtSumN->Fill(nGoodVtx);
	 GenTauPtEta_LIsoPtSumN->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_LIsoPtSumN->Fill(PUInfo);
         N_Vtx_BX_true_LIsoPtSumN->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_LIsoPtSumN->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_LIsoPtSumN->Fill(PUInfo_true);

       }

       if((*_rawn)[tauCandidate] < 2.) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MIsoPtSumN->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_MIsoPtSumN->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_MIsoPtSumN->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MIsoPtSumN->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_MIsoPtSumN->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_MIsoPtSumN->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MIsoPtSumN->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MIsoPtSumN->Fill(gentaujet->phi());
	 Nvtx_MIsoPtSumN->Fill(PUInfo_true);
	 NGood_MIsoPtSumN->Fill(nGoodVtx);
	 GenTauPtEta_MIsoPtSumN->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_MIsoPtSumN->Fill(PUInfo);
         N_Vtx_BX_true_MIsoPtSumN->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_MIsoPtSumN->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_MIsoPtSumN->Fill(PUInfo_true);

       }


       if((*_rawn)[tauCandidate] < 1.) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_TIsoPtSumN->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_TIsoPtSumN->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_TIsoPtSumN->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_TIsoPtSumN->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_TIsoPtSumN->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_TIsoPtSumN->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_TIsoPtSumN->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_TIsoPtSumN->Fill(gentaujet->phi());
	 Nvtx_TIsoPtSumN->Fill(PUInfo_true);
	 NGood_TIsoPtSumN->Fill(nGoodVtx);
	 GenTauPtEta_TIsoPtSumN->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_TIsoPtSumN->Fill(PUInfo);
         N_Vtx_BX_true_TIsoPtSumN->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_TIsoPtSumN->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_TIsoPtSumN->Fill(PUInfo_true);

       }



       if((*_nw2nq)[tauCandidate] < 4.) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_LIsoPtSumN2->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_LIsoPtSumN2->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
 }
	 
	 RecoTauDecayMode_LIsoPtSumN2->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_LIsoPtSumN2->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_LIsoPtSumN2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
 
	 GenTauPtWithDMF_LIsoPtSumN2->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_LIsoPtSumN2->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_LIsoPtSumN2->Fill(gentaujet->phi());
	 Nvtx_LIsoPtSumN2->Fill(PUInfo_true);
	 NGood_LIsoPtSumN2->Fill(nGoodVtx);
	 GenTauPtEta_LIsoPtSumN2->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_LIsoPtSumN2->Fill(PUInfo);
         N_Vtx_BX_true_LIsoPtSumN2->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_LIsoPtSumN2->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_LIsoPtSumN2->Fill(PUInfo_true);

       }

       if((*_nw2nq)[tauCandidate] < 2.) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_MIsoPtSumN2->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_MIsoPtSumN2->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_MIsoPtSumN2->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_MIsoPtSumN2->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_MIsoPtSumN2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_MIsoPtSumN2->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_MIsoPtSumN2->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_MIsoPtSumN2->Fill(gentaujet->phi());
	 Nvtx_MIsoPtSumN2->Fill(PUInfo_true);
	 NGood_MIsoPtSumN2->Fill(nGoodVtx);
	 GenTauPtEta_MIsoPtSumN2->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_MIsoPtSumN2->Fill(PUInfo);
         N_Vtx_BX_true_MIsoPtSumN2->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_MIsoPtSumN2->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_MIsoPtSumN2->Fill(PUInfo_true);

       }


       if((*_nw2nq)[tauCandidate] < 1.) {
	 
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_TIsoPtSumN2->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_TIsoPtSumN2->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	   
	 }
	 
	 RecoTauDecayMode_TIsoPtSumN2->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_TIsoPtSumN2->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_TIsoPtSumN2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 
	 GenTauPtWithDMF_TIsoPtSumN2->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_TIsoPtSumN2->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_TIsoPtSumN2->Fill(gentaujet->phi());
	 Nvtx_TIsoPtSumN2->Fill(PUInfo_true);
	 NGood_TIsoPtSumN2->Fill(nGoodVtx);
	 GenTauPtEta_TIsoPtSumN2->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_TIsoPtSumN2->Fill(PUInfo);
         N_Vtx_BX_true_TIsoPtSumN2->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_TIsoPtSumN2->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_TIsoPtSumN2->Fill(PUInfo_true);


       }

 

       if(((*_enew)[tauCandidate] > 0.5 ) && ((*_mv31)[tauCandidate] > 0.5 ) && (*_rawc)[tauCandidate] < 2.) {
	 
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
	 Nvtx_Combined->Fill(PUInfo_true);
	 NGood_Combined->Fill(nGoodVtx);
	 GenTauPtEta_Combined->Fill(gentaujet->eta(),gentaujet->pt());


	 N_Vtx_BX_PU_Combined->Fill(PUInfo);
         N_Vtx_BX_true_Combined->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_Combined->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_Combined->Fill(PUInfo_true);

       }
//

       if(((*_enew)[tauCandidate] > 0.5 ) && ((*_mv31)[tauCandidate] > 0.5 ) && (*_rawc)[tauCandidate] < 4.) {
	 
	 if(gentaujet->pt() != 0) {
	   TauPtResponse_CombinedL->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_CombinedL->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	 }
	 
	 RecoTauDecayMode_CombinedL->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_CombinedL->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_CombinedL->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 GenTauPtWithDMF_CombinedL->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_CombinedL->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_CombinedL->Fill(gentaujet->phi());
	 Nvtx_CombinedL->Fill(PUInfo_true);
	 NGood_CombinedL->Fill(nGoodVtx);
	 GenTauPtEta_CombinedL->Fill(gentaujet->eta(),gentaujet->pt());


	 N_Vtx_BX_PU_CombinedL->Fill(PUInfo);
         N_Vtx_BX_true_CombinedL->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_CombinedL->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_CombinedL->Fill(PUInfo_true);

       }

//

       if(((*_enew)[tauCandidate] > 0.5 ) && ((*_mv31)[tauCandidate] > 0.5 ) && (*_rawc)[tauCandidate] < 1) {

	 if(gentaujet->pt() != 0) {
	   TauPtResponse_CombinedT->Fill(tauCandidate->pt()/gentaujet->pt());
	   TES_CombinedT->Fill(gentaujet->pt(), tauCandidate->pt()/gentaujet->pt());
	 }
	 
	 RecoTauDecayMode_CombinedT->Fill(tauCandidate->decayMode());
	 GenTauDecayMode_CombinedT->Fill(tauGenJetDecayModeInt);
	 reco_dm_vs_gen_CombinedT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	 GenTauPtWithDMF_CombinedT->Fill(gentaujet->pt());
	 GenTauEtaWithDMF_CombinedT->Fill(gentaujet->eta());
	 GenTauPhiWithDMF_CombinedT->Fill(gentaujet->phi());
	 Nvtx_CombinedT->Fill(PUInfo_true);
	 NGood_CombinedT->Fill(nGoodVtx);
	 GenTauPtEta_CombinedT->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_CombinedT->Fill(PUInfo);
         N_Vtx_BX_true_CombinedT->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_CombinedT->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_CombinedT->Fill(PUInfo_true);

 }

//
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
	 Nvtx_TIsoPtSum->Fill(PUInfo_true);
	 NGood_TIsoPtSum->Fill(nGoodVtx);
	 GenTauPtEta_TIsoPtSum->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_TIsoPtSum->Fill(PUInfo);
         N_Vtx_BX_true_TIsoPtSum->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_TIsoPtSum->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_TIsoPtSum->Fill(PUInfo_true);

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
	 Nvtx_ML2->Fill(PUInfo_true);
         NGood_ML2->Fill(nGoodVtx);
	 GenTauPtEta_ML2->Fill(gentaujet->eta(),gentaujet->pt());


	 N_Vtx_BX_PU_ML2->Fill(PUInfo);
         N_Vtx_BX_true_ML2->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_ML2->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_ML2->Fill(PUInfo_true);

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

	 Nvtx_MM2->Fill(PUInfo_true);
         NGood_MM2->Fill(nGoodVtx);
	 GenTauPtEta_MM2->Fill(gentaujet->eta(),gentaujet->pt());


	 N_Vtx_BX_PU_MM2->Fill(PUInfo);
         N_Vtx_BX_true_MM2->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_MM2->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_MM2->Fill(PUInfo_true);

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
	 Nvtx_MT2->Fill(PUInfo_true);
         NGood_MT2->Fill(nGoodVtx);
	 GenTauPtEta_MT2->Fill(gentaujet->eta(),gentaujet->pt());


	 N_Vtx_BX_PU_MT2->Fill(PUInfo);
         N_Vtx_BX_true_MT2->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_MT2->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_MT2->Fill(PUInfo_true);

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
	 Nvtx_ML3->Fill(PUInfo_true);
         NGood_ML3->Fill(nGoodVtx);
	 GenTauPtEta_ML3->Fill(gentaujet->eta(),gentaujet->pt());


	 N_Vtx_BX_PU_ML3->Fill(PUInfo);
         N_Vtx_BX_true_ML3->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_ML3->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_ML3->Fill(PUInfo_true);



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
	 Nvtx_MT3->Fill(PUInfo_true);
         NGood_MT3->Fill(nGoodVtx);
	 GenTauPtEta_MT3->Fill(gentaujet->eta(),gentaujet->pt());

	 N_Vtx_BX_PU_MT3->Fill(PUInfo);
         N_Vtx_BX_true_MT3->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_MT3->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_MT3->Fill(PUInfo_true);


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
	 Nvtx_Cut->Fill(PUInfo_true);
         NGood_Cut->Fill(nGoodVtx);
	 GenTauPtEta_Cut->Fill(gentaujet->eta(),gentaujet->pt());


	 N_Vtx_BX_PU_Cut->Fill(PUInfo);
         N_Vtx_BX_true_Cut->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_Cut->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_Cut->Fill(PUInfo_true);

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
	 Nvtx_EL3->Fill(PUInfo_true);
         NGood_EL3->Fill(nGoodVtx);

	 N_Vtx_BX_PU_EL3->Fill(PUInfo);
         N_Vtx_BX_true_EL3->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_EL3->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_EL3->Fill(PUInfo_true);

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
	 Nvtx_EM3->Fill(PUInfo_true);
         NGood_EM3->Fill(nGoodVtx);

	 N_Vtx_BX_PU_EM3->Fill(PUInfo);
         N_Vtx_BX_true_EM3->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_EM3->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_EM3->Fill(PUInfo_true);


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
	 Nvtx_ET3->Fill(PUInfo_true);
         NGood_ET3->Fill(nGoodVtx);

	 N_Vtx_BX_PU_ET3->Fill(PUInfo);
         N_Vtx_BX_true_ET3->Fill(PUInfo_true_wo);
	 N_Vtx_BX0_PU_ET3->Fill(PUInfo_Bunch0);
         N_Vtx_BX0_true_ET3->Fill(PUInfo_true);

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
	 Nvtx_LIso3Hits->Fill(PUInfo_true);
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
	 Nvtx_MIso3Hits->Fill(PUInfo_true);
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
	 Nvtx_TIso3Hits->Fill(PUInfo_true);
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
	 Nvtx_LIso->Fill(PUInfo_true);
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
	 Nvtx_MIso->Fill(PUInfo_true);
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
	 Nvtx_TIso->Fill(PUInfo_true);
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
	 Nvtx_VLChar->Fill(PUInfo_true);
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
	 Nvtx_LChar->Fill(PUInfo_true);
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
	 Nvtx_MChar->Fill(PUInfo_true);
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
	 Nvtx_LooseRho->Fill(PUInfo_true);
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
	 Nvtx_MediumRho->Fill(PUInfo_true);
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
	 Nvtx_TightRho->Fill(PUInfo_true);
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
	 Nvtx_TChar->Fill(PUInfo_true);
         NGood_TChar->Fill(nGoodVtx);

       }


       }
       }


       }
 
   }
   }


     
  



// ------------ method called once each job just before starting event loop  ------------
bool NEWDecayMode::OverlapWithGenTau(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc, int &index ) {
   double drtmp = _TauToGenMatchingDeltaR;
   bool genTaufound = false;
   index = -1;
   for ( unsigned iTau = 0; iTau < taujetcol->size(); ++iTau ) {
     reco::PFTauRef tauCandidate(taujetcol,iTau);
     if(tauCandidate->pt() <= 20) continue;
     if(fabs(tauCandidate->eta()) <=  etacutmin) continue;
     if(fabs(tauCandidate->eta()) >= etacut) continue;
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


bool NEWDecayMode::OverlapWithGenTauForOther(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc, edm::Handle<reco::PFTauDiscriminator>  disc1 ,int &index ) {
   double drtmp = _TauToGenMatchingDeltaR;
   bool genTaufound = false;
   index = -1;
   for ( unsigned iTau = 0; iTau < taujetcol->size(); ++iTau ) {
     reco::PFTauRef tauCandidate(taujetcol,iTau);
     if(tauCandidate->pt() <= 20) continue;
     if(fabs(tauCandidate->eta()) <=  etacutmin) continue;
     if(fabs(tauCandidate->eta()) >= etacut) continue;
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

bool NEWDecayMode::IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles){
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

