#include "./TauIDChecks_newDMU4p0.h"                                                                                                                                        
  

TauIDChecks_newDMU4p0::TauIDChecks_newDMU4p0(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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


  TauPtResponse_DM = fs->make<TH1F>(("TauPtResponse_DM"+prefix).c_str() ,"TauPtResponse_DM",100,0.1,2.0);

 TauPtResponse_ML2 = fs->make<TH1F>(("TauPtResponse_ML2"+prefix).c_str() ,"TauPtResponse_ML2",100,0.1,2.0);

 TauPtResponse_MM2 = fs->make<TH1F>(("TauPtResponse_MM2"+prefix).c_str() ,"TauPtResponse_MM2",100,0.1,2.0);


 TauPtResponse_MT2= fs->make<TH1F>(("TauPtResponse_MT2"+prefix).c_str() ,"TauPtResponse_MT2",100,0.1,2.0);

 TauPtResponse_ML3 = fs->make<TH1F>(("TauPtResponse_ML3"+prefix).c_str() ,"TauPtResponse_ML3",100,0.1,2.0);

 TauPtResponse_MT3= fs->make<TH1F>(("TauPtResponse_MT3"+prefix).c_str() ,"TauPtResponse_MT3",100,0.1,2.0);

 TauPtResponse_EL3 = fs->make<TH1F>(("TauPtResponse_EL3"+prefix).c_str() ,"TauPtResponse_EL3",100,0.1,2.0);

 TauPtResponse_EM3 = fs->make<TH1F>(("TauPtResponse_EM3"+prefix).c_str() ,"TauPtResponse_EM3",100,0.1,2.0);

 TauPtResponse_ET3 = fs->make<TH1F>(("TauPtResponse_ET3"+prefix).c_str() ,"TauPtResponse_ET3",100,0.1,2.0);


 TauPtResponse_LIso3Hits = fs->make<TH1F>(("TauPtResponse_LIso3Hits"+prefix).c_str() ,"TauPtResponse_LIso3Hits",100,0.1,2.0);

 TauPtResponse_MIso3Hits = fs->make<TH1F>(("TauPtResponse_MIso3Hits"+prefix).c_str() ,"TauPtResponse_MIso3Hits",100,0.1,2.0);

 TauPtResponse_TIso3Hits = fs->make<TH1F>(("TauPtResponse_TIso3Hits"+prefix).c_str() ,"TauPtResponse_TIso3Hits",100,0.1,2.0);


 TauPtResponse_LIso = fs->make<TH1F>(("TauPtResponse_LIso"+prefix).c_str() ,"TauPtResponse_LIso",100,0.1,2.0);

 TauPtResponse_MIso = fs->make<TH1F>(("TauPtResponse_MIso"+prefix).c_str() ,"TauPtResponse_MIso",100,0.1,2.0);

 TauPtResponse_TIso = fs->make<TH1F>(("TauPtResponse_TIso"+prefix).c_str() ,"TauPtResponse_TIso",100,0.1,2.0);

 TauPtResponse_LooseIsowLT = fs->make<TH1F>(("TauPtResponse_LooseIsowLT"+prefix).c_str() ,"TauPtResponse_LooseIsowLT",100,0.1,2.0);

 TauPtResponse_LooseIsowoLT = fs->make<TH1F>(("TauPtResponse_LooseIsowoLT"+prefix).c_str() ,"TauPtResponse_LooseIsowoLT",100,0.1,2.0);
 TauPtResponse_MediumIsowLT = fs->make<TH1F>(("TauPtResponse_MediumIsowLT"+prefix).c_str() ,"TauPtResponse_MediumIsowLT",100,0.1,2.0);
 TauPtResponse_MediumIsowoLT = fs->make<TH1F>(("TauPtResponse_MediumIsowoLT"+prefix).c_str() ,"TauPtResponse_MediumIsowoLT",100,0.1,2.0);
 TauPtResponse_TightIsowLT = fs->make<TH1F>(("TauPtResponse_TightIsowLT"+prefix).c_str() ,"TauPtResponse_TightIsowLT",100,0.1,2.0);
 TauPtResponse_TightIsowoLT = fs->make<TH1F>(("TauPtResponse_TightIsowoLT"+prefix).c_str() ,"TauPtResponse_TightIsowoLT",100,0.1,2.0);
 TauPtResponse_VTightIsowLT = fs->make<TH1F>(("TauPtResponse_VTightIsowLT"+prefix).c_str() ,"TauPtResponse_VTightIsowLT",100,0.1,2.0);
 TauPtResponse_VTightIsowoLT = fs->make<TH1F>(("TauPtResponse_VTightIsowoLT"+prefix).c_str() ,"TauPtResponse_VTightIsowoLT",100,0.1,2.0);

 TauPtResponse_VVTightIsowLT = fs->make<TH1F>(("TauPtResponse_VVTightIsowLT"+prefix).c_str() ,"TauPtResponse_VVTightIsowLT",100,0.1,2.0);
 TauPtResponse_VVTightIsowoLT = fs->make<TH1F>(("TauPtResponse_VVTightIsowoLT"+prefix).c_str() ,"TauPtResponse_VVTightIsowoLT",100,0.1,2.0);





 npuVertices_ =fs->make<TH1I>(("npuVertices"+prefix).c_str() , "npuVertices" , 500,   0.0, 500.0);
 ootnpuVertices_ =fs->make<TH1I>(("ootnpuVertices"+prefix).c_str() , "ootnpuVertices" , 500,   0.0, 500.0);

  RecoTauDecayMode_DM = fs->make<TH1F>(("RecoTauDecayMode_DM"+prefix).c_str() ,"RecoTauDecayMode_DM",15,0,15);
  GenTauDecayMode_DM = fs->make<TH1F>(("GenTauDecayMode_DM"+prefix).c_str() ,"GenTauDecayMode_DM",15,0,15);
  reco_dm_vs_gen_dm = fs->make<TH2F>(("reco_dm_vs_gen_dm"+prefix).c_str() ,"reco_dm_vs_gen_dm",15,0,15,15,0,15);



  RecoTauDecayMode_ML2 = fs->make<TH1F>(("RecoTauDecayMode_ML2"+prefix).c_str() ,"RecoTauDecayMode_ML2",15,0,15);
  GenTauDecayMode_ML2 = fs->make<TH1F>(("GenTauDecayMode_ML2"+prefix).c_str() ,"GenTauDecayMode_ML2",15,0,15);
  reco_dm_vs_gen_ML2 = fs->make<TH2F>(("reco_dm_vs_gen_ML2"+prefix).c_str() ,"reco_dm_vs_gen_ML2",15,0,15,15,0,15);

  RecoTauDecayMode_MM2 = fs->make<TH1F>(("RecoTauDecayMode_MM2"+prefix).c_str() ,"RecoTauDecayMode_MM2",15,0,15);
  GenTauDecayMode_MM2 = fs->make<TH1F>(("GenTauDecayMode_MM2"+prefix).c_str() ,"GenTauDecayMode_MM2",15,0,15);
  reco_dm_vs_gen_MM2 = fs->make<TH2F>(("reco_dm_vs_gen_MM2"+prefix).c_str() ,"reco_dm_vs_gen_MM2",15,0,15,15,0,15);

  RecoTauDecayMode_MT2 = fs->make<TH1F>(("RecoTauDecayMode_MT2"+prefix).c_str() ,"RecoTauDecayMode_MT2",15,0,15);
  GenTauDecayMode_MT2 = fs->make<TH1F>(("GenTauDecayMode_MT2"+prefix).c_str() ,"GenTauDecayMode_MT2",15,0,15);
  reco_dm_vs_gen_MT2 = fs->make<TH2F>(("reco_dm_vs_gen_MT2"+prefix).c_str() ,"reco_dm_vs_gen_MT2",15,0,15,15,0,15);

  RecoTauDecayMode_ML3 = fs->make<TH1F>(("RecoTauDecayMode_ML3"+prefix).c_str() ,"RecoTauDecayMode_ML3",15,0,15);
  GenTauDecayMode_ML3 = fs->make<TH1F>(("GenTauDecayMode_ML3"+prefix).c_str() ,"GenTauDecayMode_ML3",15,0,15);
  reco_dm_vs_gen_ML3 = fs->make<TH2F>(("reco_dm_vs_gen_ML3"+prefix).c_str() ,"reco_dm_vs_gen_ML3",15,0,15,15,0,15);


  RecoTauDecayMode_MT3 = fs->make<TH1F>(("RecoTauDecayMode_MT3"+prefix).c_str() ,"RecoTauDecayMode_MT3",15,0,15);
  GenTauDecayMode_MT3 = fs->make<TH1F>(("GenTauDecayMode_MT3"+prefix).c_str() ,"GenTauDecayMode_MT3",15,0,15);
  reco_dm_vs_gen_MT3 = fs->make<TH2F>(("reco_dm_vs_gen_MT3"+prefix).c_str() ,"reco_dm_vs_gen_MT3",15,0,15,15,0,15);

  RecoTauDecayMode_EL3 = fs->make<TH1F>(("RecoTauDecayMode_EL3"+prefix).c_str() ,"RecoTauDecayMode_EL3",15,0,15);
  GenTauDecayMode_EL3 = fs->make<TH1F>(("GenTauDecayMode_EL3"+prefix).c_str() ,"GenTauDecayMode_EL3",15,0,15);
  reco_dm_vs_gen_EL3 = fs->make<TH2F>(("reco_dm_vs_gen_EL3"+prefix).c_str() ,"reco_dm_vs_gen_EL3",15,0,15,15,0,15);


  RecoTauDecayMode_EM3 = fs->make<TH1F>(("RecoTauDecayMode_EM3"+prefix).c_str() ,"RecoTauDecayMode_EM3",15,0,15);
  GenTauDecayMode_EM3 = fs->make<TH1F>(("GenTauDecayMode_EM3"+prefix).c_str() ,"GenTauDecayMode_EM3",15,0,15);
  reco_dm_vs_gen_EM3 = fs->make<TH2F>(("reco_dm_vs_gen_EM3"+prefix).c_str() ,"reco_dm_vs_gen_EM3",15,0,15,15,0,15);

  RecoTauDecayMode_ET3 = fs->make<TH1F>(("RecoTauDecayMode_ET3"+prefix).c_str() ,"RecoTauDecayMode_ET3",15,0,15);
  GenTauDecayMode_ET3 = fs->make<TH1F>(("GenTauDecayMode_ET3"+prefix).c_str() ,"GenTauDecayMode_ET3",15,0,15);
  reco_dm_vs_gen_ET3 = fs->make<TH2F>(("reco_dm_vs_gen_ET3"+prefix).c_str() ,"reco_dm_vs_gen_ET3",15,0,15,15,0,15);

  RecoTauDecayMode_LIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_LIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_LIso3Hits",15,0,15);
  GenTauDecayMode_LIso3Hits = fs->make<TH1F>(("GenTauDecayMode_LIso3Hits"+prefix).c_str() ,"GenTauDecayMode_LIso3Hits",15,0,15);
  reco_dm_vs_gen_LIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_LIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_LIso3Hits",15,0,15,15,0,15);

  RecoTauDecayMode_MIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_MIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_MIso3Hits",15,0,15);
  GenTauDecayMode_MIso3Hits = fs->make<TH1F>(("GenTauDecayMode_MIso3Hits"+prefix).c_str() ,"GenTauDecayMode_MIso3Hits",15,0,15);
  reco_dm_vs_gen_MIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_MIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_MIso3Hits",15,0,15,15,0,15);

  RecoTauDecayMode_TIso3Hits = fs->make<TH1F>(("RecoTauDecayMode_TIso3Hits"+prefix).c_str() ,"RecoTauDecayMode_TIso3Hits",15,0,15);
  GenTauDecayMode_TIso3Hits = fs->make<TH1F>(("GenTauDecayMode_TIso3Hits"+prefix).c_str() ,"GenTauDecayMode_TIso3Hits",15,0,15);
  reco_dm_vs_gen_TIso3Hits = fs->make<TH2F>(("reco_dm_vs_gen_TIso3Hits"+prefix).c_str() ,"reco_dm_vs_gen_TIso3Hits",15,0,15,15,0,15);

  RecoTauDecayMode_LIso = fs->make<TH1F>(("RecoTauDecayMode_LIso"+prefix).c_str() ,"RecoTauDecayMode_LIso",15,0,15);
  GenTauDecayMode_LIso = fs->make<TH1F>(("GenTauDecayMode_LIso"+prefix).c_str() ,"GenTauDecayMode_LIso",15,0,15);
  reco_dm_vs_gen_LIso = fs->make<TH2F>(("reco_dm_vs_gen_LIso"+prefix).c_str() ,"reco_dm_vs_gen_LIso",15,0,15,15,0,15);

  RecoTauDecayMode_MIso = fs->make<TH1F>(("RecoTauDecayMode_MIso"+prefix).c_str() ,"RecoTauDecayMode_MIso",15,0,15);
  GenTauDecayMode_MIso = fs->make<TH1F>(("GenTauDecayMode_MIso"+prefix).c_str() ,"GenTauDecayMode_MIso",15,0,15);
  reco_dm_vs_gen_MIso = fs->make<TH2F>(("reco_dm_vs_gen_MIso"+prefix).c_str() ,"reco_dm_vs_gen_MIso",15,0,15,15,0,15);

  RecoTauDecayMode_TIso = fs->make<TH1F>(("RecoTauDecayMode_TIso"+prefix).c_str() ,"RecoTauDecayMode_TIso",15,0,15);
  GenTauDecayMode_TIso = fs->make<TH1F>(("GenTauDecayMode_TIso"+prefix).c_str() ,"GenTauDecayMode_TIso",15,0,15);
  reco_dm_vs_gen_TIso = fs->make<TH2F>(("reco_dm_vs_gen_TIso"+prefix).c_str() ,"reco_dm_vs_gen_TIso",15,0,15,15,0,15);


  RecoTauDecayMode_LooseIsowLT = fs->make<TH1F>(("RecoTauDecayMode_LooseIsowLT"+prefix).c_str() ,"RecoTauDecayMode_LooseIsowLT",15,0,15);
  GenTauDecayMode_LooseIsowLT = fs->make<TH1F>(("GenTauDecayMode_LooseIsowLT"+prefix).c_str() ,"GenTauDecayMode_LooseIsowLT",15,0,15);
  reco_dm_vs_gen_LooseIsowLT = fs->make<TH2F>(("reco_dm_vs_gen_LooseIsowLT"+prefix).c_str() ,"reco_dm_vs_gen_LooseIsowLT",15,0,15,15,0,15);

  RecoTauDecayMode_MediumIsowLT = fs->make<TH1F>(("RecoTauDecayMode_MediumIsowLT"+prefix).c_str() ,"RecoTauDecayMode_MediumIsowLT",15,0,15);
  GenTauDecayMode_MediumIsowLT = fs->make<TH1F>(("GenTauDecayMode_MediumIsowLT"+prefix).c_str() ,"GenTauDecayMode_MediumIsowLT",15,0,15);
  reco_dm_vs_gen_MediumIsowLT = fs->make<TH2F>(("reco_dm_vs_gen_MediumIsowLT"+prefix).c_str() ,"reco_dm_vs_gen_MediumIsowLT",15,0,15,15,0,15);

  RecoTauDecayMode_TightIsowLT = fs->make<TH1F>(("RecoTauDecayMode_TightIsowLT"+prefix).c_str() ,"RecoTauDecayMode_TightIsowLT",15,0,15);
  GenTauDecayMode_TightIsowLT = fs->make<TH1F>(("GenTauDecayMode_TightIsowLT"+prefix).c_str() ,"GenTauDecayMode_TightIsowLT",15,0,15);
  reco_dm_vs_gen_TightIsowLT = fs->make<TH2F>(("reco_dm_vs_gen_TightIsowLT"+prefix).c_str() ,"reco_dm_vs_gen_TightIsowLT",15,0,15,15,0,15);

  RecoTauDecayMode_VTightIsowLT = fs->make<TH1F>(("RecoTauDecayMode_VTightIsowLT"+prefix).c_str() ,"RecoTauDecayMode_VTightIsowLT",15,0,15);
  GenTauDecayMode_VTightIsowLT = fs->make<TH1F>(("GenTauDecayMode_VTightIsowLT"+prefix).c_str() ,"GenTauDecayMode_VTightIsowLT",15,0,15);
  reco_dm_vs_gen_VTightIsowLT = fs->make<TH2F>(("reco_dm_vs_gen_VTightIsowLT"+prefix).c_str() ,"reco_dm_vs_gen_VTightIsowLT",15,0,15,15,0,15);

  RecoTauDecayMode_VVTightIsowLT = fs->make<TH1F>(("RecoTauDecayMode_VVTightIsowLT"+prefix).c_str() ,"RecoTauDecayMode_VVTightIsowLT",15,0,15);
  GenTauDecayMode_VVTightIsowLT = fs->make<TH1F>(("GenTauDecayMode_VVTightIsowLT"+prefix).c_str() ,"GenTauDecayMode_VVTightIsowLT",15,0,15);
  reco_dm_vs_gen_VVTightIsowLT = fs->make<TH2F>(("reco_dm_vs_gen_VVTightIsowLT"+prefix).c_str() ,"reco_dm_vs_gen_VVTightIsowLT",15,0,15,15,0,15);


  RecoTauDecayMode_LooseIsowoLT = fs->make<TH1F>(("RecoTauDecayMode_LooseIsowoLT"+prefix).c_str() ,"RecoTauDecayMode_LooseIsowoLT",15,0,15);
  GenTauDecayMode_LooseIsowoLT = fs->make<TH1F>(("GenTauDecayMode_LooseIsowoLT"+prefix).c_str() ,"GenTauDecayMode_LooseIsowoLT",15,0,15);
  reco_dm_vs_gen_LooseIsowoLT = fs->make<TH2F>(("reco_dm_vs_gen_LooseIsowoLT"+prefix).c_str() ,"reco_dm_vs_gen_LooseIsowoLT",15,0,15,15,0,15);

  RecoTauDecayMode_MediumIsowoLT = fs->make<TH1F>(("RecoTauDecayMode_MediumIsowoLT"+prefix).c_str() ,"RecoTauDecayMode_MediumIsowoLT",15,0,15);
  GenTauDecayMode_MediumIsowoLT = fs->make<TH1F>(("GenTauDecayMode_MediumIsowoLT"+prefix).c_str() ,"GenTauDecayMode_MediumIsowoLT",15,0,15);
  reco_dm_vs_gen_MediumIsowoLT = fs->make<TH2F>(("reco_dm_vs_gen_MediumIsowoLT"+prefix).c_str() ,"reco_dm_vs_gen_MediumIsowoLT",15,0,15,15,0,15);

  RecoTauDecayMode_TightIsowoLT = fs->make<TH1F>(("RecoTauDecayMode_TightIsowoLT"+prefix).c_str() ,"RecoTauDecayMode_TightIsowoLT",15,0,15);
  GenTauDecayMode_TightIsowoLT = fs->make<TH1F>(("GenTauDecayMode_TightIsowoLT"+prefix).c_str() ,"GenTauDecayMode_TightIsowoLT",15,0,15);
  reco_dm_vs_gen_TightIsowoLT = fs->make<TH2F>(("reco_dm_vs_gen_TightIsowoLT"+prefix).c_str() ,"reco_dm_vs_gen_TightIsowoLT",15,0,15,15,0,15);

  RecoTauDecayMode_VTightIsowoLT = fs->make<TH1F>(("RecoTauDecayMode_VTightIsowoLT"+prefix).c_str() ,"RecoTauDecayMode_VTightIsowoLT",15,0,15);
  GenTauDecayMode_VTightIsowoLT = fs->make<TH1F>(("GenTauDecayMode_VTightIsowoLT"+prefix).c_str() ,"GenTauDecayMode_VTightIsowoLT",15,0,15);
  reco_dm_vs_gen_VTightIsowoLT = fs->make<TH2F>(("reco_dm_vs_gen_VTightIsowoLT"+prefix).c_str() ,"reco_dm_vs_gen_VTightIsowoLT",15,0,15,15,0,15);

  RecoTauDecayMode_VVTightIsowoLT = fs->make<TH1F>(("RecoTauDecayMode_VVTightIsowoLT"+prefix).c_str() ,"RecoTauDecayMode_VVTightIsowoLT",15,0,15);
  GenTauDecayMode_VVTightIsowoLT = fs->make<TH1F>(("GenTauDecayMode_VVTightIsowoLT"+prefix).c_str() ,"GenTauDecayMode_VVTightIsowoLT",15,0,15);
  reco_dm_vs_gen_VVTightIsowoLT = fs->make<TH2F>(("reco_dm_vs_gen_VVTightIsowoLT"+prefix).c_str() ,"reco_dm_vs_gen_VVTightIsowoLT",15,0,15,15,0,15);


//  GenTauPtWithoutDMF = fs->make<TH1F>(("GenTauPtWithoutDMF", "GenTauPtWithoutDMF",100,0,700);
//  GenTauEtaWithoutDMF = fs->make<TH1F>(("GenTauEtaWithoutDMF", "GenTauEtaWithoutDMF",100,-5,5);
//  GenTauPhiWithoutDMF = fs->make<TH1F>(("GenTauPhiWithoutDMF", "GenTauPhiWithoutDMF",100,-5,5);

  GenTauPtWithoutDMF = fs->make<TH1F>(("GenTauPtWithoutDMF"+prefix).c_str(), "GenTauPtWithoutDMF",100,0,700); 
 GenTauEtaWithoutDMF = fs->make<TH1F>(("GenTauEtaWithoutDMF"+prefix).c_str() ,"GenTauEtaWithoutDMF",100,-5,5);
 GenTauPhiWithoutDMF = fs->make<TH1F>(("GenTauPhiWithoutDMF"+prefix).c_str() ,"GenTauPhiWithoutDMF",100,-5,5);


 GenTauPtWithoutDMF_eta1p47 = fs->make<TH1F>(("GenTauPtWithoutDMF_eta1p47"+prefix).c_str(), "GenTauPtWithoutDMF_eta1p47",100,0,700); 
 GenTauEtaWithoutDMF_eta1p47 = fs->make<TH1F>(("GenTauEtaWithoutDMF_eta1p47"+prefix).c_str() ,"GenTauEtaWithoutDMF_eta1p47",100,-5,5);
 GenTauPhiWithoutDMF_eta1p47 = fs->make<TH1F>(("GenTauPhiWithoutDMF_eta1p47"+prefix).c_str() ,"GenTauPhiWithoutDMF_eta1p47",100,-5,5);
 
 
 
 GenTauPtWithoutDMF_etag1p47 = fs->make<TH1F>(("GenTauPtWithoutDMF_etag1p47"+prefix).c_str(), "GenTauPtWithoutDMF_etag1p47",100,0,700); 
 GenTauEtaWithoutDMF_etag1p47 = fs->make<TH1F>(("GenTauEtaWithoutDMF_etag1p47"+prefix).c_str() ,"GenTauEtaWithoutDMF_etag1p47",100,-5,5);
 GenTauPhiWithoutDMF_etag1p47 = fs->make<TH1F>(("GenTauPhiWithoutDMF_etag1p47"+prefix).c_str() ,"GenTauPhiWithoutDMF_etag1p47",100,-5,5);
 

  GenTauPtWithDMF = fs->make<TH1F>(("GenTauPtWithDMF"+prefix).c_str() ,"GenTauPtWithDMF",100,0,700);
  GenTauEtaWithDMF = fs->make<TH1F>(("GenTauEtaWithDMF"+prefix).c_str() ,"GenTauEtaWithDMF",100,-5,5);
  GenTauPhiWithDMF = fs->make<TH1F>(("GenTauPhiWithDMF"+prefix).c_str() ,"GenTauPhiWithDMF",100,-5,5);


  GenTauPtWithDMF_ML2 = fs->make<TH1F>(("GenTauPtWithDMF_ML2"+prefix).c_str() ,"GenTauPtWithDMF_ML2" ,100,0,700);
  GenTauEtaWithDMF_ML2 = fs->make<TH1F>(("GenTauEtaWithDMF_ML2"+prefix).c_str() ,"GenTauEtaWithDMF_ML2" ,100,-5,5);
  GenTauPhiWithDMF_ML2 = fs->make<TH1F>(("GenTauPhiWithDMF_ML2"+prefix).c_str() ,"GenTauPhiWithDMF_ML2" ,100,-5,5);

  GenTauPtWithDMF_MM2 = fs->make<TH1F>(("GenTauPtWithDMF_MM2"+prefix).c_str() ,"GenTauPtWithDMF_MM2" ,100,0,700);
  GenTauEtaWithDMF_MM2 = fs->make<TH1F>(("GenTauEtaWithDMF_MM2"+prefix).c_str() ,"GenTauEtaWithDMF_MM2" ,100,-5,5);
  GenTauPhiWithDMF_MM2 = fs->make<TH1F>(("GenTauPhiWithDMF_MM2"+prefix).c_str() ,"GenTauPhiWithDMF_MM2" ,100,-5,5);

  GenTauPtWithDMF_MT2 = fs->make<TH1F>(("GenTauPtWithDMF_MT2"+prefix).c_str() ,"GenTauPtWithDMF_MT2" ,100,0,700);
  GenTauEtaWithDMF_MT2 = fs->make<TH1F>(("GenTauEtaWithDMF_MT2"+prefix).c_str() ,"GenTauEtaWithDMF_MT2" ,100,-5,5);
  GenTauPhiWithDMF_MT2 = fs->make<TH1F>(("GenTauPhiWithDMF_MT2"+prefix).c_str() ,"GenTauPhiWithDMF_MT2" ,100,-5,5);

  GenTauPtWithDMF_ML3 = fs->make<TH1F>(("GenTauPtWithDMF_ML3"+prefix).c_str() ,"GenTauPtWithDMF_ML3" ,100,0,700);
  GenTauEtaWithDMF_ML3 = fs->make<TH1F>(("GenTauEtaWithDMF_ML3"+prefix).c_str() ,"GenTauEtaWithDMF_ML3" ,100,-5,5);
  GenTauPhiWithDMF_ML3 = fs->make<TH1F>(("GenTauPhiWithDMF_ML3"+prefix).c_str() ,"GenTauPhiWithDMF_ML3" ,100,-5,5);
	  
  GenTauPtWithDMF_MT3 = fs->make<TH1F>(("GenTauPtWithDMF_MT3"+prefix).c_str() ,"GenTauPtWithDMF_MT3" ,100,0,700);
  GenTauEtaWithDMF_MT3 = fs->make<TH1F>(("GenTauEtaWithDMF_MT3"+prefix).c_str() ,"GenTauEtaWithDMF_MT3" ,100,-5,5);
  GenTauPhiWithDMF_MT3 = fs->make<TH1F>(("GenTauPhiWithDMF_MT3"+prefix).c_str() ,"GenTauPhiWithDMF_MT3" ,100,-5,5);
    	  
  GenTauPtWithDMF_EL3 = fs->make<TH1F>(("GenTauPtWithDMF_EL3"+prefix).c_str() ,"GenTauPtWithDMF_EL3" ,100,0,700);
  GenTauEtaWithDMF_EL3 = fs->make<TH1F>(("GenTauEtaWithDMF_EL3"+prefix).c_str() ,"GenTauEtaWithDMF_EL3" ,100,-5,5);
  GenTauPhiWithDMF_EL3 = fs->make<TH1F>(("GenTauPhiWithDMF_EL3"+prefix).c_str() ,"GenTauPhiWithDMF_EL3" ,100,-5,5);

  GenTauPtWithDMF_EM3 = fs->make<TH1F>(("GenTauPtWithDMF_EM3"+prefix).c_str() ,"GenTauPtWithDMF_EM3" ,100,0,700);
  GenTauEtaWithDMF_EM3 = fs->make<TH1F>(("GenTauEtaWithDMF_EM3"+prefix).c_str() ,"GenTauEtaWithDMF_EM3" ,100,-5,5);
  GenTauPhiWithDMF_EM3 = fs->make<TH1F>(("GenTauPhiWithDMF_EM3"+prefix).c_str() ,"GenTauPhiWithDMF_EM3" ,100,-5,5);

  GenTauPtWithDMF_ET3 = fs->make<TH1F>(("GenTauPtWithDMF_ET3"+prefix).c_str() ,"GenTauPtWithDMF_ET3" ,100,0,700);
  GenTauEtaWithDMF_ET3 = fs->make<TH1F>(("GenTauEtaWithDMF_ET3"+prefix).c_str() ,"GenTauEtaWithDMF_ET3" ,100,-5,5);
  GenTauPhiWithDMF_ET3 = fs->make<TH1F>(("GenTauPhiWithDMF_ET3"+prefix).c_str() ,"GenTauPhiWithDMF_ET3" ,100,-5,5);


  GenTauPtWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_LIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_LIso3Hits" ,100,-5,5);
  GenTauPhiWithDMF_LIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_LIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_LIso3Hits" ,100,-5,5);

  GenTauPtWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_MIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_MIso3Hits" ,100,-5,5);
  GenTauPhiWithDMF_MIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_MIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_MIso3Hits" ,100,-5,5);

  GenTauPtWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauPtWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauPtWithDMF_TIso3Hits" ,100,0,700);
  GenTauEtaWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauEtaWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauEtaWithDMF_TIso3Hits" ,100,-5,5);
  GenTauPhiWithDMF_TIso3Hits = fs->make<TH1F>(("GenTauPhiWithDMF_TIso3Hits"+prefix).c_str() ,"GenTauPhiWithDMF_TIso3Hits" ,100,-5,5);



  GenTauPtWithDMF_LIso = fs->make<TH1F>(("GenTauPtWithDMF_LIso"+prefix).c_str() ,"GenTauPtWithDMF_LIso" ,100,0,700);
  GenTauEtaWithDMF_LIso = fs->make<TH1F>(("GenTauEtaWithDMF_LIso"+prefix).c_str() ,"GenTauEtaWithDMF_LIso" ,100,-5,5);
  GenTauPhiWithDMF_LIso = fs->make<TH1F>(("GenTauPhiWithDMF_LIso"+prefix).c_str() ,"GenTauPhiWithDMF_LIso" ,100,-5,5);

  GenTauPtWithDMF_MIso = fs->make<TH1F>(("GenTauPtWithDMF_MIso"+prefix).c_str() ,"GenTauPtWithDMF_MIso" ,100,0,700);
  GenTauEtaWithDMF_MIso = fs->make<TH1F>(("GenTauEtaWithDMF_MIso"+prefix).c_str() ,"GenTauEtaWithDMF_MIso" ,100,-5,5);
  GenTauPhiWithDMF_MIso = fs->make<TH1F>(("GenTauPhiWithDMF_MIso"+prefix).c_str() ,"GenTauPhiWithDMF_MIso" ,100,-5,5);

  GenTauPtWithDMF_TIso = fs->make<TH1F>(("GenTauPtWithDMF_TIso"+prefix).c_str() ,"GenTauPtWithDMF_TIso" ,100,0,700);
  GenTauEtaWithDMF_TIso = fs->make<TH1F>(("GenTauEtaWithDMF_TIso"+prefix).c_str() ,"GenTauEtaWithDMF_TIso" ,100,-5,5);
  GenTauPhiWithDMF_TIso = fs->make<TH1F>(("GenTauPhiWithDMF_TIso"+prefix).c_str() ,"GenTauPhiWithDMF_TIso" ,100,-5,5);

  GenTauPtWithDMF_LooseIsowLT = fs->make<TH1F>(("GenTauPtWithDMF_LooseIsowLT"+prefix).c_str() ,"GenTauPtWithDMF_LooseIsowLT" ,100,0,700);
  GenTauEtaWithDMF_LooseIsowLT = fs->make<TH1F>(("GenTauEtaWithDMF_LooseIsowLT"+prefix).c_str() ,"GenTauEtaWithDMF_LooseIsowLT" ,100,-5,5);
  GenTauPhiWithDMF_LooseIsowLT = fs->make<TH1F>(("GenTauPhiWithDMF_LooseIsowLT"+prefix).c_str() ,"GenTauPhiWithDMF_LooseIsowLT" ,100,-5,5);

  GenTauPtWithDMF_LooseIsowoLT = fs->make<TH1F>(("GenTauPtWithDMF_LooseIsowoLT"+prefix).c_str() ,"GenTauPtWithDMF_LooseIsowoLT" ,100,0,700);
  GenTauEtaWithDMF_LooseIsowoLT = fs->make<TH1F>(("GenTauEtaWithDMF_LooseIsowoLT"+prefix).c_str() ,"GenTauEtaWithDMF_LooseIsowoLT" ,100,-5,5);
  GenTauPhiWithDMF_LooseIsowoLT = fs->make<TH1F>(("GenTauPhiWithDMF_LooseIsowoLT"+prefix).c_str() ,"GenTauPhiWithDMF_LooseIsowoLT" ,100,-5,5);

  GenTauPtWithDMF_MediumIsowLT = fs->make<TH1F>(("GenTauPtWithDMF_MediumIsowLT"+prefix).c_str() ,"GenTauPtWithDMF_MediumIsowLT" ,100,0,700);
  GenTauEtaWithDMF_MediumIsowLT = fs->make<TH1F>(("GenTauEtaWithDMF_MediumIsowLT"+prefix).c_str() ,"GenTauEtaWithDMF_MediumIsowLT" ,100,-5,5);
  GenTauPhiWithDMF_MediumIsowLT = fs->make<TH1F>(("GenTauPhiWithDMF_MediumIsowLT"+prefix).c_str() ,"GenTauPhiWithDMF_MediumIsowLT" ,100,-5,5);


  GenTauPtWithDMF_MediumIsowoLT = fs->make<TH1F>(("GenTauPtWithDMF_MediumIsowoLT"+prefix).c_str() ,"GenTauPtWithDMF_MediumIsowoLT" ,100,0,700);
  GenTauEtaWithDMF_MediumIsowoLT = fs->make<TH1F>(("GenTauEtaWithDMF_MediumIsowoLT"+prefix).c_str() ,"GenTauEtaWithDMF_MediumIsowoLT" ,100,-5,5);
  GenTauPhiWithDMF_MediumIsowoLT = fs->make<TH1F>(("GenTauPhiWithDMF_MediumIsowoLT"+prefix).c_str() ,"GenTauPhiWithDMF_MediumIsowoLT" ,100,-5,5);



  GenTauPtWithDMF_TightIsowLT = fs->make<TH1F>(("GenTauPtWithDMF_TightIsowLT"+prefix).c_str() ,"GenTauPtWithDMF_TightIsowLT" ,100,0,700);
  GenTauEtaWithDMF_TightIsowLT = fs->make<TH1F>(("GenTauEtaWithDMF_TightIsowLT"+prefix).c_str() ,"GenTauEtaWithDMF_TightIsowLT" ,100,-5,5);
  GenTauPhiWithDMF_TightIsowLT = fs->make<TH1F>(("GenTauPhiWithDMF_TightIsowLT"+prefix).c_str() ,"GenTauPhiWithDMF_TightIsowLT" ,100,-5,5);


  GenTauPtWithDMF_TightIsowoLT = fs->make<TH1F>(("GenTauPtWithDMF_TightIsowoLT"+prefix).c_str() ,"GenTauPtWithDMF_TightIsowoLT" ,100,0,700);
  GenTauEtaWithDMF_TightIsowoLT = fs->make<TH1F>(("GenTauEtaWithDMF_TightIsowoLT"+prefix).c_str() ,"GenTauEtaWithDMF_TightIsowoLT" ,100,-5,5);
  GenTauPhiWithDMF_TightIsowoLT = fs->make<TH1F>(("GenTauPhiWithDMF_TightIsowoLT"+prefix).c_str() ,"GenTauPhiWithDMF_TightIsowoLT" ,100,-5,5);


  GenTauPtWithDMF_VTightIsowLT = fs->make<TH1F>(("GenTauPtWithDMF_VTightIsowLT"+prefix).c_str() ,"GenTauPtWithDMF_VTightIsowLT" ,100,0,700);
  GenTauEtaWithDMF_VTightIsowLT = fs->make<TH1F>(("GenTauEtaWithDMF_VTightIsowLT"+prefix).c_str() ,"GenTauEtaWithDMF_VTightIsowLT" ,100,-5,5);
  GenTauPhiWithDMF_VTightIsowLT = fs->make<TH1F>(("GenTauPhiWithDMF_VTightIsowLT"+prefix).c_str() ,"GenTauPhiWithDMF_VTightIsowLT" ,100,-5,5);


  GenTauPtWithDMF_VTightIsowoLT = fs->make<TH1F>(("GenTauPtWithDMF_VTightIsowoLT"+prefix).c_str() ,"GenTauPtWithDMF_VTightIsowoLT" ,100,0,700);
  GenTauEtaWithDMF_VTightIsowoLT = fs->make<TH1F>(("GenTauEtaWithDMF_VTightIsowoLT"+prefix).c_str() ,"GenTauEtaWithDMF_VTightIsowoLT" ,100,-5,5);
  GenTauPhiWithDMF_VTightIsowoLT = fs->make<TH1F>(("GenTauPhiWithDMF_VTightIsowoLT"+prefix).c_str() ,"GenTauPhiWithDMF_VTightIsowoLT" ,100,-5,5);

  GenTauPtWithDMF_VVTightIsowLT = fs->make<TH1F>(("GenTauPtWithDMF_VVTightIsowLT"+prefix).c_str() ,"GenTauPtWithDMF_VVTightIsowLT" ,100,0,700);
  GenTauEtaWithDMF_VVTightIsowLT = fs->make<TH1F>(("GenTauEtaWithDMF_VVTightIsowLT"+prefix).c_str() ,"GenTauEtaWithDMF_VVTightIsowLT" ,100,-5,5);
  GenTauPhiWithDMF_VVTightIsowLT = fs->make<TH1F>(("GenTauPhiWithDMF_VVTightIsowLT"+prefix).c_str() ,"GenTauPhiWithDMF_VVTightIsowLT" ,100,-5,5);


  GenTauPtWithDMF_VVTightIsowoLT = fs->make<TH1F>(("GenTauPtWithDMF_VVTightIsowoLT"+prefix).c_str() ,"GenTauPtWithDMF_VVTightIsowoLT" ,100,0,700);
  GenTauEtaWithDMF_VVTightIsowoLT = fs->make<TH1F>(("GenTauEtaWithDMF_VVTightIsowoLT"+prefix).c_str() ,"GenTauEtaWithDMF_VVTightIsowoLT" ,100,-5,5);
  GenTauPhiWithDMF_VVTightIsowoLT = fs->make<TH1F>(("GenTauPhiWithDMF_VVTightIsowoLT"+prefix).c_str() ,"GenTauPhiWithDMF_VVTightIsowoLT" ,100,-5,5);


   ///// write 
  GenTauPtWithDMF_eta1p47_0 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_0"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_0",100,0,700);
  GenTauEtaWithDMF_eta1p47_0 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_0"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_0",100,-5,5);
  GenTauPhiWithDMF_eta1p47_0 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_0"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_0",100,-5,5);
  GenTauPtWithDMF_eta1p47_1 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_1"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_1",100,0,700);
  GenTauEtaWithDMF_eta1p47_1 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_1"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_1",100,-5,5);
  GenTauPhiWithDMF_eta1p47_1 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_1"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_1",100,-5,5);
 
  GenTauPtWithDMF_eta1p47_2 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_2"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_2",100,0,700);
  GenTauEtaWithDMF_eta1p47_2 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_2"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_2",100,-5,5);
  GenTauPhiWithDMF_eta1p47_2 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_2"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_2",100,-5,5);
      
  GenTauPtWithDMF_eta1p47_10 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_10"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_10",100,0,700);
  GenTauEtaWithDMF_eta1p47_10 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_10"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_10",100,-5,5);
  GenTauPhiWithDMF_eta1p47_10 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_10"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_10",100,-5,5);
 
  GenTauPtWithDMF_eta1p47_11 = fs->make<TH1F>(("GenTauPtWithDMF_eta1p47_11"+prefix).c_str() ,"GenTauPtWithDMF_eta1p47_11",100,0,700);
  GenTauEtaWithDMF_eta1p47_11 = fs->make<TH1F>(("GenTauEtaWithDMF_eta1p47_11"+prefix).c_str() ,"GenTauEtaWithDMF_eta1p47_11",100,-5,5);
  GenTauPhiWithDMF_eta1p47_11 = fs->make<TH1F>(("GenTauPhiWithDMF_eta1p47_11"+prefix).c_str() ,"GenTauPhiWithDMF_eta1p47_11",100,-5,5);
 

  GenTauPtWithDMF_etag1p47_0 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_0"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_0",100,0,700);
  GenTauEtaWithDMF_etag1p47_0 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_0"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_0",100,-5,5);
  GenTauPhiWithDMF_etag1p47_0 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_0"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_0",100,-5,5);
  GenTauPtWithDMF_etag1p47_1 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_1"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_1",100,0,700);
  GenTauEtaWithDMF_etag1p47_1 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_1"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_1",100,-5,5);
  GenTauPhiWithDMF_etag1p47_1 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_1"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_1",100,-5,5);
 
  GenTauPtWithDMF_etag1p47_2 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_2"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_2",100,0,700);
  GenTauEtaWithDMF_etag1p47_2 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_2"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_2",100,-5,5);
  GenTauPhiWithDMF_etag1p47_2 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_2"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_2",100,-5,5);
      
  GenTauPtWithDMF_etag1p47_10 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_10"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_10",100,0,700);
  GenTauEtaWithDMF_etag1p47_10 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_10"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_10",100,-5,5);
  GenTauPhiWithDMF_etag1p47_10 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_10"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_10",100,-5,5);
 
  GenTauPtWithDMF_etag1p47_11 = fs->make<TH1F>(("GenTauPtWithDMF_etag1p47_11"+prefix).c_str() ,"GenTauPtWithDMF_etag1p47_11",100,0,700);
  GenTauEtaWithDMF_etag1p47_11 = fs->make<TH1F>(("GenTauEtaWithDMF_etag1p47_11"+prefix).c_str() ,"GenTauEtaWithDMF_etag1p47_11",100,-5,5);
  GenTauPhiWithDMF_etag1p47_11 = fs->make<TH1F>(("GenTauPhiWithDMF_etag1p47_11"+prefix).c_str() ,"GenTauPhiWithDMF_etag1p47_11",100,-5,5);
 
 GenTauPtWithDMF_0 = fs->make<TH1F>(("GenTauPtWithDMF_0"+prefix).c_str() ,"GenTauPtWithDMF_0",100,0,700);
  GenTauEtaWithDMF_0 = fs->make<TH1F>(("GenTauEtaWithDMF_0"+prefix).c_str() ,"GenTauEtaWithDMF_0",100,-5,5);
  GenTauPhiWithDMF_0 = fs->make<TH1F>(("GenTauPhiWithDMF_0"+prefix).c_str() ,"GenTauPhiWithDMF_0",100,-5,5);
  GenTauPtWithDMF_1 = fs->make<TH1F>(("GenTauPtWithDMF_1"+prefix).c_str() ,"GenTauPtWithDMF_1",100,0,700);
  GenTauEtaWithDMF_1 = fs->make<TH1F>(("GenTauEtaWithDMF_1"+prefix).c_str() ,"GenTauEtaWithDMF_1",100,-5,5);
  GenTauPhiWithDMF_1 = fs->make<TH1F>(("GenTauPhiWithDMF_1"+prefix).c_str() ,"GenTauPhiWithDMF_1",100,-5,5);
 
  GenTauPtWithDMF_2 = fs->make<TH1F>(("GenTauPtWithDMF_2"+prefix).c_str() ,"GenTauPtWithDMF_2",100,0,700);
  GenTauEtaWithDMF_2 = fs->make<TH1F>(("GenTauEtaWithDMF_2"+prefix).c_str() ,"GenTauEtaWithDMF_2",100,-5,5);
  GenTauPhiWithDMF_2 = fs->make<TH1F>(("GenTauPhiWithDMF_2"+prefix).c_str() ,"GenTauPhiWithDMF_2",100,-5,5);
      
  GenTauPtWithDMF_10 = fs->make<TH1F>(("GenTauPtWithDMF_10"+prefix).c_str() ,"GenTauPtWithDMF_10",100,0,700);
  GenTauEtaWithDMF_10 = fs->make<TH1F>(("GenTauEtaWithDMF_10"+prefix).c_str() ,"GenTauEtaWithDMF_10",100,-5,5);
  GenTauPhiWithDMF_10 = fs->make<TH1F>(("GenTauPhiWithDMF_10"+prefix).c_str() ,"GenTauPhiWithDMF_10",100,-5,5);
 
  GenTauPtWithDMF_11 = fs->make<TH1F>(("GenTauPtWithDMF_11"+prefix).c_str() ,"GenTauPtWithDMF_11",100,0,700);
  GenTauEtaWithDMF_11 = fs->make<TH1F>(("GenTauEtaWithDMF_11"+prefix).c_str() ,"GenTauEtaWithDMF_11",100,-5,5);
  GenTauPhiWithDMF_11 = fs->make<TH1F>(("GenTauPhiWithDMF_11"+prefix).c_str() ,"GenTauPhiWithDMF_11",100,-5,5);
 

		  
}


TauIDChecks_newDMU4p0::~TauIDChecks_newDMU4p0()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void TauIDChecks_newDMU4p0::Fill(const edm::Event& iEvent) {
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
  npuVertices_->Fill(npuVertices);
  ootnpuVertices_->Fill(ootnpuVertices);

  iEvent.getByLabel("ak5GenJets", _genJets);
  

  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  //decay Mode
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFindingNewDMs",_dmf);
  //Muon Veto


   //Muon 2 working pint
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection2",_mv1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumMuonRejection2",_mv2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection2",_mv3);
   
   // Muon 3 working points

   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection3",_mv31);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection3",_mv32);

   //Electron Veto

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

    iEvent.getByLabel("hpsPFTauDiscriminationByLooseIsolationMVA3newDMwLT",_losIsowLT);
    iEvent.getByLabel("hpsPFTauDiscriminationByLooseIsolationMVA3newDMwoLT",_losIsowoLT);

    iEvent.getByLabel("hpsPFTauDiscriminationByMediumIsolationMVA3newDMwLT",_medIsowLT);
    iEvent.getByLabel("hpsPFTauDiscriminationByMediumIsolationMVA3newDMwoLT",_medIsowoLT);

    iEvent.getByLabel("hpsPFTauDiscriminationByTightIsolationMVA3newDMwLT",_TightIsowLT);
    iEvent.getByLabel("hpsPFTauDiscriminationByTightIsolationMVA3newDMwoLT",_TightIsowoLT);
   
    iEvent.getByLabel("hpsPFTauDiscriminationByVTightIsolationMVA3newDMwLT",_VTightIsowLT);
     iEvent.getByLabel("hpsPFTauDiscriminationByVTightIsolationMVA3newDMwLT",_VTightIsowoLT);
     
     iEvent.getByLabel("hpsPFTauDiscriminationByVVTightIsolationMVA3newDMwLT",_VVTightIsowLT);
     iEvent.getByLabel("hpsPFTauDiscriminationByVVTightIsolationMVA3newDMwoLT",_VVTightIsowoLT);

   
   
   bool isZtautau=false;
   isZtautau = IsZTauTau (_genParticles) ;
   
   //isZtautau=true;
   
   if(isZtautau) {
     
     for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
       reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
       
       bool TauEtaCuts = false;
       bool RecoptCut = false;
       bool DecayModeFinding = false;
       
       
       if((abs(tauCandidate->eta()) < 3.0)) TauEtaCuts = true;
       
       if((tauCandidate->pt()) > 20) RecoptCut = true;
       
       if((*_dmf)[tauCandidate] > 0.5) DecayModeFinding = true; 
       
       if( (TauEtaCuts) && (RecoptCut) ) { 
	 int igentau = 0;
	 int index  = -1;
	 if(OverlapWithGenTau( tauCandidate->eta() , tauCandidate->phi() , genTauJets , index ) && index != -1 ){
	   for(reco::GenJetCollection::const_iterator gentaujet = genTauJets->begin(); gentaujet !=  genTauJets->end(); ++gentaujet) {
	     if(igentau == index) {
	       tauGenJetDecayModeInt = -999;
	       
	       //just to cross confirm	       
	       if(reco::deltaR(gentaujet->eta(), gentaujet->phi(), tauCandidate->eta(), tauCandidate->phi()) < _TauToGenMatchingDeltaR) {
		 
		 GenTauPtWithoutDMF->Fill(gentaujet->pt());
		 GenTauEtaWithoutDMF->Fill(gentaujet->eta());
		 GenTauPhiWithoutDMF->Fill(gentaujet->phi());
		 
     if(fabs(gentaujet->eta()) < 1.47) {
        GenTauPtWithoutDMF_eta1p47->Fill(gentaujet->pt());
        GenTauEtaWithoutDMF_eta1p47->Fill(gentaujet->eta());
        GenTauPhiWithoutDMF_eta1p47->Fill(gentaujet->phi());
     
       }

      if(fabs(gentaujet->eta()) > 1.47) {
         GenTauPtWithoutDMF_etag1p47->Fill(gentaujet->pt());
         GenTauEtaWithoutDMF_etag1p47->Fill(gentaujet->eta());
         GenTauPhiWithoutDMF_etag1p47->Fill(gentaujet->phi());
      
        }
  
		 if(DecayModeFinding) {
		   
		   std::string tauGenJetDecayMode = JetMCTagUtils::genTauDecayMode(*gentaujet);
		   
		   
		   if(tauGenJetDecayMode=="muon") continue;
		   if(tauGenJetDecayMode=="electron") continue;
		   
		   if(gentaujet->pt() != 0) {
		     TauPtResponse_DM->Fill(tauCandidate->pt()/gentaujet->pt());
		   }
		   
		   
		   //   cout<<" pat Decay Mode ::  "<<tauCandidate->decayMode()<<endl;
		   
		   //    cout<<"tauGenJetDecayMode::"<<tauGenJetDecayMode<<endl;
		   
		   
		   if(tauGenJetDecayMode=="oneProng0Pi0") {
		     tauGenJetDecayModeInt=0;
		       GenTauPtWithDMF_0->Fill(gentaujet->pt());
           GenTauEtaWithDMF_0->Fill(gentaujet->eta());
           GenTauPhiWithDMF_0->Fill(gentaujet->phi());


           if(fabs(gentaujet->eta()) < 1.47) {
		       GenTauPtWithDMF_eta1p47_0->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_eta1p47_0->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_eta1p47_0->Fill(gentaujet->phi());
		       

		     }
		     if(fabs(gentaujet->eta()) > 1.47) {
		       GenTauPtWithDMF_etag1p47_0->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_etag1p47_0->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_etag1p47_0->Fill(gentaujet->phi());
		     } 
		   }
		   
		   if(tauGenJetDecayMode=="oneProng1Pi0") {
		     tauGenJetDecayModeInt=1;
           GenTauPtWithDMF_1->Fill(gentaujet->pt());
           GenTauEtaWithDMF_1->Fill(gentaujet->eta());
           GenTauPhiWithDMF_1->Fill(gentaujet->phi());


		     if(fabs(gentaujet->eta()) < 1.47) {
		       GenTauPtWithDMF_eta1p47_1->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_eta1p47_1->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_eta1p47_1->Fill(gentaujet->phi());
		       

		     }
		     if(fabs(gentaujet->eta()) > 1.47) {
		       GenTauPtWithDMF_etag1p47_1->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_etag1p47_1->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_etag1p47_1->Fill(gentaujet->phi());
		     } 
		  		  
		   }
		   
		   if(tauGenJetDecayMode=="oneProng2Pi0") {
		     tauGenJetDecayModeInt=2;
            GenTauPtWithDMF_2->Fill(gentaujet->pt());
            GenTauEtaWithDMF_2->Fill(gentaujet->eta());
            GenTauPhiWithDMF_2->Fill(gentaujet->phi());

           
		     if(fabs(gentaujet->eta()) < 1.47) {
		       GenTauPtWithDMF_eta1p47_2->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_eta1p47_2->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_eta1p47_2->Fill(gentaujet->phi());
		       
		       
		     }
		     if(fabs(gentaujet->eta()) > 1.47) {
		       GenTauPtWithDMF_etag1p47_2->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_etag1p47_2->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_etag1p47_2->Fill(gentaujet->phi());
		     } 
		  
		   }
		   
		   if(tauGenJetDecayMode=="threeProng0Pi0") {
		     tauGenJetDecayModeInt=10;
            GenTauPtWithDMF_10->Fill(gentaujet->pt());
             GenTauEtaWithDMF_10->Fill(gentaujet->eta());
            GenTauPhiWithDMF_10->Fill(gentaujet->phi());

		     if(fabs(gentaujet->eta()) < 1.47) {
		       GenTauPtWithDMF_eta1p47_10->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_eta1p47_10->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_eta1p47_10->Fill(gentaujet->phi());
		       

		     }
		     if(fabs(gentaujet->eta()) > 1.47) {
		       GenTauPtWithDMF_etag1p47_10->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_etag1p47_10->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_etag1p47_10->Fill(gentaujet->phi());
		     } 
		  
		   }
		   
		   if(tauGenJetDecayMode=="threeProng1Pi0") {
		     tauGenJetDecayModeInt=11;
           GenTauPtWithDMF_11->Fill(gentaujet->pt());
           GenTauEtaWithDMF_11->Fill(gentaujet->eta());
           GenTauPhiWithDMF_11->Fill(gentaujet->phi());

		     if(fabs(gentaujet->eta()) < 1.47) {
		       GenTauPtWithDMF_eta1p47_11->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_eta1p47_11->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_eta1p47_11->Fill(gentaujet->phi());
		       

		     }
		     if(fabs(gentaujet->eta()) > 1.47) {
		       GenTauPtWithDMF_etag1p47_11->Fill(gentaujet->pt());  
		       GenTauEtaWithDMF_etag1p47_11->Fill(gentaujet->eta());
		       GenTauPhiWithDMF_etag1p47_11->Fill(gentaujet->phi());
		     } 
		  
		   }
		   
		   RecoTauDecayMode_DM->Fill(tauCandidate->decayMode());
		   GenTauDecayMode_DM->Fill(tauGenJetDecayModeInt);
		   
		   reco_dm_vs_gen_dm->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		   
		   GenTauPtWithDMF->Fill(gentaujet->pt());	  
		   GenTauEtaWithDMF->Fill(gentaujet->eta());
		   GenTauPhiWithDMF->Fill(gentaujet->phi());
		   
		   
		   /////////////////////////////////////////////////////////////////////////////////
		   
		   
		   ////////// DMF v/s Eta Phi /////////////////////////
		   
		   if((*_mv1)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_ML2->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_ML2->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_ML2->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_ML2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_ML2->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_ML2->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_ML2->Fill(gentaujet->phi());
		   }
		   
		   
		   
		   if((*_mv2)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MM2->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MM2->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MM2->Fill(tauGenJetDecayModeInt);
		     
		     reco_dm_vs_gen_MM2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_MM2->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MM2->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MM2->Fill(gentaujet->phi());
		   }
		   
		   
		   if((*_mv3)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MT2->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MT2->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MT2->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MT2->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     GenTauPtWithDMF_MT2->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MT2->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MT2->Fill(gentaujet->phi());
		   }
		   
	    
		   if((*_mv31)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_ML3->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
	      RecoTauDecayMode_ML3->Fill(tauCandidate->decayMode());
	      GenTauDecayMode_ML3->Fill(tauGenJetDecayModeInt);
	      reco_dm_vs_gen_ML3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
	      
	      GenTauPtWithDMF_ML3->Fill(gentaujet->pt());	  
	      GenTauEtaWithDMF_ML3->Fill(gentaujet->eta());
	      GenTauPhiWithDMF_ML3->Fill(gentaujet->phi());
	    }
	    
	    
		   if((*_mv32)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MT3->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MT3->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MT3->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MT3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_MT3->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MT3->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MT3->Fill(gentaujet->phi());
		   }
		   
		   
		   if((*_ev1)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_EL3->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_EL3->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_EL3->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_EL3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_EL3->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_EL3->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_EL3->Fill(gentaujet->phi());
		   }
		   
	    
	    
		   if((*_ev2)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_EM3->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_EM3->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_EM3->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_EM3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_EM3->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_EM3->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_EM3->Fill(gentaujet->phi());
		   }

		   if((*_ev3)[tauCandidate] > 0.5) {
		     
		     //    cout<<"1"<<endl;  
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_ET3->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_ET3->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_ET3->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_ET3->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_ET3->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_ET3->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_ET3->Fill(gentaujet->phi());
		   }
		   
		   
		   if((*_iso4)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_LIso3Hits->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_LIso3Hits->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_LIso3Hits->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_LIso3Hits->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_LIso3Hits->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_LIso3Hits->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_LIso3Hits->Fill(gentaujet->phi());
		   }
		   
		   if((*_iso5)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MIso3Hits->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MIso3Hits->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MIso3Hits->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MIso3Hits->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_MIso3Hits->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MIso3Hits->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MIso3Hits->Fill(gentaujet->phi());
		   }
		   
		   if((*_iso6)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_TIso3Hits->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_TIso3Hits->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_TIso3Hits->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_TIso3Hits->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_TIso3Hits->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_TIso3Hits->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_TIso3Hits->Fill(gentaujet->phi());
		   }
		   
		   
		   if((*_iso1)[tauCandidate] > 0.5) {
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_LIso->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_LIso->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_LIso->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_LIso->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_LIso->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_LIso->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_LIso->Fill(gentaujet->phi());
		     
		   }
		   
		   if((*_iso2)[tauCandidate] > 0.5) {

		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MIso->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MIso->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MIso->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MIso->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_MIso->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MIso->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MIso->Fill(gentaujet->phi());
		     
		   }
		   
		   
		   if((*_iso3)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_TIso->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_TIso->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_TIso->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_TIso->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_TIso->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_TIso->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_TIso->Fill(gentaujet->phi());
		     
		   }
		   
		   if((*_losIsowLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_LooseIsowLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		    
		     RecoTauDecayMode_LooseIsowLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_LooseIsowLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_LooseIsowLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_LooseIsowLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_LooseIsowLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_LooseIsowLT->Fill(gentaujet->phi());
		     
		   }
		 

		   if((*_losIsowoLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_LooseIsowoLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_LooseIsowoLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_LooseIsowoLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_LooseIsowoLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_LooseIsowoLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_LooseIsowoLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_LooseIsowoLT->Fill(gentaujet->phi());
		   }
		   
		   
			   if((*_medIsowLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MediumIsowLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MediumIsowLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MediumIsowLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MediumIsowLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_MediumIsowLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MediumIsowLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MediumIsowLT->Fill(gentaujet->phi());
		   }
	


	   if((*_medIsowoLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_MediumIsowoLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_MediumIsowoLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_MediumIsowoLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_MediumIsowoLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_MediumIsowoLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_MediumIsowoLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_MediumIsowoLT->Fill(gentaujet->phi());
		   }
	   
		   if((*_TightIsowLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_TightIsowLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_TightIsowLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_TightIsowLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_TightIsowLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     
		     GenTauPtWithDMF_TightIsowLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_TightIsowLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_TightIsowLT->Fill(gentaujet->phi());
		   }
		  

		   if((*_TightIsowoLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_TightIsowoLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_TightIsowoLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_TightIsowoLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_TightIsowoLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     
		     GenTauPtWithDMF_TightIsowoLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_TightIsowoLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_TightIsowoLT->Fill(gentaujet->phi());
		   }



		   //
		   if((*_VTightIsowLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_VTightIsowLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_VTightIsowLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_VTightIsowLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_VTightIsowLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     
		     GenTauPtWithDMF_VTightIsowLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_VTightIsowLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_VTightIsowLT->Fill(gentaujet->phi());
		   }
		  

		   if((*_VTightIsowoLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_VTightIsowoLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_VTightIsowoLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_VTightIsowoLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_VTightIsowoLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     
		     GenTauPtWithDMF_VTightIsowoLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_VTightIsowoLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_VTightIsowoLT->Fill(gentaujet->phi());
		   }

		   if((*_VVTightIsowLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_VVTightIsowLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_VVTightIsowLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_VVTightIsowLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_VVTightIsowLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     GenTauPtWithDMF_VVTightIsowLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_VVTightIsowLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_VVTightIsowLT->Fill(gentaujet->phi());
		     
		   }
		  

		   if((*_VVTightIsowoLT)[tauCandidate] > 0.5) {
		     
		     if(gentaujet->pt() != 0) {
		       TauPtResponse_VVTightIsowoLT->Fill(tauCandidate->pt()/gentaujet->pt());
		     }
		     
		     RecoTauDecayMode_VVTightIsowoLT->Fill(tauCandidate->decayMode());
		     GenTauDecayMode_VVTightIsowoLT->Fill(tauGenJetDecayModeInt);
		     reco_dm_vs_gen_VVTightIsowoLT->Fill(tauGenJetDecayModeInt,tauCandidate->decayMode());
		     
		     
		     GenTauPtWithDMF_VVTightIsowoLT->Fill(gentaujet->pt());	  
		     GenTauEtaWithDMF_VVTightIsowoLT->Fill(gentaujet->eta());
		     GenTauPhiWithDMF_VVTightIsowoLT->Fill(gentaujet->phi());
		   }


		   
		 }
	       }    
	     }
    igentau++;
	   }
	 }
       }
     }
     
   }  
}


// ------------ method called once each job just before starting event loop  ------------
bool TauIDChecks_newDMU4p0::OverlapWithGenTau(double Taueta , double Tauphi ,edm::Handle<std::vector< reco::GenJet > > genTauJets ,int  &index     ) {
   double drtmp = _TauToGenMatchingDeltaR;
   int tmpindex =0 ;
   bool genTaufound = false;
   for(std::vector<reco::GenJet>::const_iterator genJetItr=genTauJets->begin(); genJetItr!=genTauJets->end(); ++genJetItr) {
 
     double dr =reco::deltaR(Taueta, Tauphi,genJetItr->eta(),genJetItr->phi());
     if(dr < drtmp){
       drtmp = dr;
       index = tmpindex;
       genTaufound= true;
     }
     tmpindex++;
   }
   return genTaufound;
 }

bool TauIDChecks_newDMU4p0::IsZTauTau(edm::Handle<reco::GenParticleCollection> genParticles){
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

