#include "./ETauFakeRate.h"                                                                                                                                        
#include "DataFormats/TrackReco/interface/HitPattern.h"

ETauFakeRate::ETauFakeRate(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
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
  //h_RPC_FourthStation_etag1p2 = fs->make<TH1F>(("h_RPC_FourthStation_etag1p2"+prefix).c_str() ,"h_RPC_FourthStation_etag1p2",15,0,15);

  Nvtx_den = fs->make<TH1F>(("Nvtx_den"+prefix).c_str() ,"Nvtx_den",200,0,200);
  NGood_den = fs->make<TH1F>(("NGood_den"+prefix).c_str() ,"NGood_den",200,0,200);
  
  //

  Nvtx_num = fs->make<TH1F>(("Nvtx_num"+prefix).c_str() ,"Nvtx_num",200,0,200);
  NGood_num = fs->make<TH1F>(("NGood_num"+prefix).c_str() ,"NGood_num",200,0,200);

  Nvtx_numM = fs->make<TH1F>(("Nvtx_numM"+prefix).c_str() ,"Nvtx_numM",200,0,200);
  NGood_numM = fs->make<TH1F>(("NGood_numM"+prefix).c_str() ,"NGood_numM",200,0,200);

   Nvtx_numT = fs->make<TH1F>(("Nvtx_numT"+prefix).c_str() ,"Nvtx_numT",200,0,200);
  NGood_numT = fs->make<TH1F>(("NGood_numT"+prefix).c_str() ,"NGood_numT",200,0,200);

  Nvtx_numM_Cut = fs->make<TH1F>(("Nvtx_numM_Cut"+prefix).c_str() ,"Nvtx_numM_Cut",200,0,200);
  NGood_numM_Cut = fs->make<TH1F>(("NGood_numM_Cut"+prefix).c_str() ,"NGood_numM_Cut",200,0,200);
  
  Nvtx_numM_tight = fs->make<TH1F>(("Nvtx_numM_tight"+prefix).c_str() ,"Nvtx_numM_tight",200,0,200);
  NGood_numM_tight = fs->make<TH1F>(("NGood_numM_tight"+prefix).c_str() ,"NGood_numM_tight",200,0,200);

  Nvtx_numM_medium = fs->make<TH1F>(("Nvtx_numM_medium"+prefix).c_str() ,"Nvtx_numM_medium",200,0,200);
  NGood_numM_medium = fs->make<TH1F>(("NGood_numM_medium"+prefix).c_str() ,"NGood_numM_medium",200,0,200);

  //

  Nvtx_num_MV = fs->make<TH1F>(("Nvtx_num_MV"+prefix).c_str() ,"Nvtx_num_MV",200,0,200);
  NGood_num_MV = fs->make<TH1F>(("NGood_num_MV"+prefix).c_str() ,"NGood_num_MV",200,0,200);
  //
  Nvtx_num_Cut_MV = fs->make<TH1F>(("Nvtx_num_Cut_MV"+prefix).c_str() ,"Nvtx_num_Cut_MV",200,0,200);
  NGood_num_Cut_MV = fs->make<TH1F>(("NGood_num_Cut_MV"+prefix).c_str() ,"NGood_num_Cut_MV",200,0,200);
  
  Nvtx_num_tight_MV = fs->make<TH1F>(("Nvtx_num_tight_MV"+prefix).c_str() ,"Nvtx_num_tight_MV",200,0,200);
  NGood_num_tight_MV = fs->make<TH1F>(("NGood_num_tight_MV"+prefix).c_str() ,"NGood_num_tight_MV",200,0,200);

  Nvtx_num_medium_MV = fs->make<TH1F>(("Nvtx_num_medium_MV"+prefix).c_str() ,"Nvtx_num_medium_MV",200,0,200);
  NGood_num_medium_MV = fs->make<TH1F>(("NGood_num_medium_MV"+prefix).c_str() ,"NGood_num_medium_MV",200,0,200);
  //

  Nvtx_numM_MV = fs->make<TH1F>(("Nvtx_numM_MV"+prefix).c_str() ,"Nvtx_numM_MV",200,0,200);
  NGood_numM_MV = fs->make<TH1F>(("NGood_numM_MV"+prefix).c_str() ,"NGood_numM_MV",200,0,200);
  //
  Nvtx_numM_Cut_MV = fs->make<TH1F>(("Nvtx_numM_Cut_MV"+prefix).c_str() ,"Nvtx_numM_Cut_MV",200,0,200);
  NGood_numM_Cut_MV = fs->make<TH1F>(("NGood_numM_Cut_MV"+prefix).c_str() ,"NGood_numM_Cut_MV",200,0,200);
  
  Nvtx_numM_tight_MV = fs->make<TH1F>(("Nvtx_numM_tight_MV"+prefix).c_str() ,"Nvtx_numM_tight_MV",200,0,200);
  NGood_numM_tight_MV = fs->make<TH1F>(("NGood_numM_tight_MV"+prefix).c_str() ,"NGood_numM_tight_MV",200,0,200);

  Nvtx_numM_medium_MV = fs->make<TH1F>(("Nvtx_numM_medium_MV"+prefix).c_str() ,"Nvtx_numM_medium_MV",200,0,200);
  NGood_numM_medium_MV = fs->make<TH1F>(("NGood_numM_medium_MV"+prefix).c_str() ,"NGood_numM_medium_MV",200,0,200);
  

  //start here 

  Nvtx_numT_Cut = fs->make<TH1F>(("Nvtx_numT_Cut"+prefix).c_str() ,"Nvtx_numT_Cut",200,0,200);
  NGood_numT_Cut = fs->make<TH1F>(("NGood_numT_Cut"+prefix).c_str() ,"NGood_numT_Cut",200,0,200);
  
  Nvtx_numT_tight = fs->make<TH1F>(("Nvtx_numT_tight"+prefix).c_str() ,"Nvtx_numT_tight",200,0,200);
  NGood_numT_tight = fs->make<TH1F>(("NGood_numT_tight"+prefix).c_str() ,"NGood_numT_tight",200,0,200);

  Nvtx_numT_medium = fs->make<TH1F>(("Nvtx_numT_medium"+prefix).c_str() ,"Nvtx_numT_medium",200,0,200);
  NGood_numT_medium = fs->make<TH1F>(("NGood_numT_medium"+prefix).c_str() ,"NGood_numT_medium",200,0,200);
  
  Nvtx_numT_MV = fs->make<TH1F>(("Nvtx_numT_MV"+prefix).c_str() ,"Nvtx_numT_MV",200,0,200);
  NGood_numT_MV = fs->make<TH1F>(("NGood_numT_MV"+prefix).c_str() ,"NGood_numT_MV",200,0,200);
  //
  Nvtx_numT_Cut_MV = fs->make<TH1F>(("Nvtx_numT_Cut_MV"+prefix).c_str() ,"Nvtx_numT_Cut_MV",200,0,200);
  NGood_numT_Cut_MV = fs->make<TH1F>(("NGood_numT_Cut_MV"+prefix).c_str() ,"NGood_numT_Cut_MV",200,0,200);
  
  Nvtx_numT_tight_MV = fs->make<TH1F>(("Nvtx_numT_tight_MV"+prefix).c_str() ,"Nvtx_numT_tight_MV",200,0,200);
  NGood_numT_tight_MV = fs->make<TH1F>(("NGood_numT_tight_MV"+prefix).c_str() ,"NGood_numT_tight_MV",200,0,200);

  Nvtx_numT_medium_MV = fs->make<TH1F>(("Nvtx_numT_medium_MV"+prefix).c_str() ,"Nvtx_numT_medium_MV",200,0,200);
  NGood_numT_medium_MV = fs->make<TH1F>(("NGood_numT_medium_MV"+prefix).c_str() ,"NGood_numT_medium_MV",200,0,200);
  
  // stop here
  Nvtx_num_Cut = fs->make<TH1F>(("Nvtx_num_Cut"+prefix).c_str() ,"Nvtx_num_Cut",200,0,200);
  NGood_num_Cut = fs->make<TH1F>(("NGood_num_Cut"+prefix).c_str() ,"NGood_num_Cut",200,0,200);
  
  Nvtx_num_tight = fs->make<TH1F>(("Nvtx_num_tight"+prefix).c_str() ,"Nvtx_num_tight",200,0,200);
  NGood_num_tight = fs->make<TH1F>(("NGood_num_tight"+prefix).c_str() ,"NGood_num_tight",200,0,200);

  Nvtx_num_medium = fs->make<TH1F>(("Nvtx_num_medium"+prefix).c_str() ,"Nvtx_num_medium",200,0,200);
  NGood_num_medium = fs->make<TH1F>(("NGood_num_medium"+prefix).c_str() ,"NGood_num_medium",200,0,200);
  
  ///  
  Nvtx_DMF = fs->make<TH1F>(("Nvtx_DMF"+prefix).c_str() ,"Nvtx_DMF",200,0,200);
  NGood_DMF = fs->make<TH1F>(("NGood_DMF"+prefix).c_str() ,"NGood_DMF",200,0,200);
  
  h_PfTau_pT_DMF = fs->make<TH1F>(("h_PfTau_pT_DMF"+prefix).c_str() ,"h_PfTau_pT_DMF",100,0,700);
  h_PfTau_Eta_DMF = fs->make<TH1F>(("h_PfTau_Eta_DMF"+prefix).c_str() ,"h_PfTau_Eta_DMF",100,-5,5);
  h_PfTau_Phi_DMF = fs->make<TH1F>(("h_PfTau_Phi_DMF"+prefix).c_str() ,"h_PfTau_Phi_DMF",100,-5,5);
  h_genElectron_pT_DMF = fs->make<TH1F>(("h_genElectron_pT_DMF"+prefix).c_str() ,"h_genElectron_pT_DMF",100,0,700);
  h_genElectron_Eta_DMF = fs->make<TH1F>(("h_genElectron_Eta_DMF"+prefix).c_str() ,"h_genElectron_Eta_DMF",100,-5,5);
  h_genElectron_Phi_DMF = fs->make<TH1F>(("h_genElectron_Phi_DMF"+prefix).c_str() ,"h_genElectron_Phi_DMF",100,-5,5); 

  h_PfTau_pT_den = fs->make<TH1F>(("h_PfTau_pT_den"+prefix).c_str() ,"h_PfTau_pT_den",100,0,700);
  h_PfTau_Eta_den = fs->make<TH1F>(("h_PfTau_Eta_den"+prefix).c_str() ,"h_PfTau_Eta_den",100,-5,5);
  h_PfTau_Phi_den = fs->make<TH1F>(("h_PfTau_Phi_den"+prefix).c_str() ,"h_PfTau_Phi_den",100,-5,5);
  h_genElectron_pT_den = fs->make<TH1F>(("h_genElectron_pT_den"+prefix).c_str() ,"h_genElectron_pT_den",100,0,700);
  h_genElectron_Eta_den = fs->make<TH1F>(("h_genElectron_Eta_den"+prefix).c_str() ,"h_genElectron_Eta_den",100,-5,5);
  h_genElectron_Phi_den = fs->make<TH1F>(("h_genElectron_Phi_den"+prefix).c_str() ,"h_genElectron_Phi_den",100,-5,5); 


  h_PfTau_pT_num = fs->make<TH1F>(("h_PfTau_pT_num"+prefix).c_str() ,"h_PfTau_pT_num",100,0,700);
  h_PfTau_Eta_num = fs->make<TH1F>(("h_PfTau_Eta_num"+prefix).c_str() ,"h_PfTau_Eta_num",100,-5,5);
  h_PfTau_Phi_num = fs->make<TH1F>(("h_PfTau_Phi_num"+prefix).c_str() ,"h_PfTau_Phi_num",100,-5,5);
  h_genElectron_pT_num = fs->make<TH1F>(("h_genElectron_pT_num"+prefix).c_str() ,"h_genElectron_pT_num",100,0,700);
  h_genElectron_Eta_num = fs->make<TH1F>(("h_genElectron_Eta_num"+prefix).c_str() ,"h_genElectron_Eta_num",100,-5,5); 
  h_genElectron_Phi_num = fs->make<TH1F>(("h_genElectron_Phi_num"+prefix).c_str() ,"h_genElectron_Phi_num",100,-5,5); 
 
  h_PfTau_pT_num_MV = fs->make<TH1F>(("h_PfTau_pT_num_MV"+prefix).c_str() ,"h_PfTau_pT_num_MV",100,0,700);
  h_PfTau_Eta_num_MV = fs->make<TH1F>(("h_PfTau_Eta_num_MV"+prefix).c_str() ,"h_PfTau_Eta_num_MV",100,-5,5);
  h_PfTau_Phi_num_MV = fs->make<TH1F>(("h_PfTau_Phi_num_MV"+prefix).c_str() ,"h_PfTau_Phi_num_MV",100,-5,5);
  h_genElectron_pT_num_MV = fs->make<TH1F>(("h_genElectron_pT_num_MV"+prefix).c_str() ,"h_genElectron_pT_num_MV",100,0,700);
  h_genElectron_Eta_num_MV = fs->make<TH1F>(("h_genElectron_Eta_num_MV"+prefix).c_str() ,"h_genElectron_Eta_num_MV",100,-5,5); 
  h_genElectron_Phi_num_MV = fs->make<TH1F>(("h_genElectron_Phi_num_MV"+prefix).c_str() ,"h_genElectron_Phi_num_MV",100,-5,5); 
 

  h_PfTau_pT_num_tight = fs->make<TH1F>(("h_PfTau_pT_num_tight"+prefix).c_str() ,"h_PfTau_pT_num_tight",100,0,700);
  h_PfTau_Eta_num_tight = fs->make<TH1F>(("h_PfTau_Eta_num_tight"+prefix).c_str() ,"h_PfTau_Eta_num_tight",100,-5,5);
  h_PfTau_Phi_num_tight = fs->make<TH1F>(("h_PfTau_Phi_num_tight"+prefix).c_str() ,"h_PfTau_Phi_num_tight",100,-5,5);
  h_genElectron_pT_num_tight = fs->make<TH1F>(("h_genElectron_pT_num_tight"+prefix).c_str() ,"h_genElectron_pT_num_tight",100,0,700);
  h_genElectron_Eta_num_tight = fs->make<TH1F>(("h_genElectron_Eta_num_tight"+prefix).c_str() ,"h_genElectron_Eta_num_tight",100,-5,5); 
  h_genElectron_Phi_num_tight = fs->make<TH1F>(("h_genElectron_Phi_num_tight"+prefix).c_str() ,"h_genElectron_Phi_num_tight",100,-5,5); 


  h_PfTau_pT_num_tight_MV = fs->make<TH1F>(("h_PfTau_pT_num_tight_MV"+prefix).c_str() ,"h_PfTau_pT_num_tight_MV",100,0,700);
  h_PfTau_Eta_num_tight_MV = fs->make<TH1F>(("h_PfTau_Eta_num_tight_MV"+prefix).c_str() ,"h_PfTau_Eta_num_tight_MV",100,-5,5);
  h_PfTau_Phi_num_tight_MV = fs->make<TH1F>(("h_PfTau_Phi_num_tight_MV"+prefix).c_str() ,"h_PfTau_Phi_num_tight_MV",100,-5,5);
  h_genElectron_pT_num_tight_MV = fs->make<TH1F>(("h_genElectron_pT_num_tight_MV"+prefix).c_str() ,"h_genElectron_pT_num_tight_MV",100,0,700);
  h_genElectron_Eta_num_tight_MV = fs->make<TH1F>(("h_genElectron_Eta_num_tight_MV"+prefix).c_str() ,"h_genElectron_Eta_num_tight_MV",100,-5,5); 
  h_genElectron_Phi_num_tight_MV = fs->make<TH1F>(("h_genElectron_Phi_num_tight_MV"+prefix).c_str() ,"h_genElectron_Phi_num_tight_MV",100,-5,5); 



  h_PfTau_pT_num_medium = fs->make<TH1F>(("h_PfTau_pT_num_medium"+prefix).c_str() ,"h_PfTau_pT_num_medium",100,0,700);
  h_PfTau_Eta_num_medium = fs->make<TH1F>(("h_PfTau_Eta_num_medium"+prefix).c_str() ,"h_PfTau_Eta_num_medium",100,-5,5);
 h_PfTau_Phi_num_medium = fs->make<TH1F>(("h_PfTau_Phi_num_medium"+prefix).c_str() ,"h_PfTau_Phi_num_medium",100,-5,5);
  h_genElectron_pT_num_medium = fs->make<TH1F>(("h_genElectron_pT_num_medium"+prefix).c_str() ,"h_genElectron_pT_num_medium",100,0,700);
  h_genElectron_Eta_num_medium = fs->make<TH1F>(("h_genElectron_Eta_num_medium"+prefix).c_str() ,"h_genElectron_Eta_num_medium",100,-5,5); 
  h_genElectron_Phi_num_medium = fs->make<TH1F>(("h_genElectron_Phi_num_medium"+prefix).c_str() ,"h_genElectron_Phi_num_medium",100,-5,5);   


  //

   h_PfTau_pT_num_medium_MV = fs->make<TH1F>(("h_PfTau_pT_num_medium_MV"+prefix).c_str() ,"h_PfTau_pT_num_medium_MV",100,0,700);
  h_PfTau_Eta_num_medium_MV = fs->make<TH1F>(("h_PfTau_Eta_num_medium_MV"+prefix).c_str() ,"h_PfTau_Eta_num_medium_MV",100,-5,5);
 h_PfTau_Phi_num_medium_MV = fs->make<TH1F>(("h_PfTau_Phi_num_medium_MV"+prefix).c_str() ,"h_PfTau_Phi_num_medium_MV",100,-5,5);
  h_genElectron_pT_num_medium_MV = fs->make<TH1F>(("h_genElectron_pT_num_medium_MV"+prefix).c_str() ,"h_genElectron_pT_num_medium_MV",100,0,700);
  h_genElectron_Eta_num_medium_MV = fs->make<TH1F>(("h_genElectron_Eta_num_medium_MV"+prefix).c_str() ,"h_genElectron_Eta_num_medium_MV",100,-5,5); 
  h_genElectron_Phi_num_medium_MV = fs->make<TH1F>(("h_genElectron_Phi_num_medium_MV"+prefix).c_str() ,"h_genElectron_Phi_num_MVmedium",100,-5,5);   

  //
  h_PfTau_pT_num_Cut = fs->make<TH1F>(("h_PfTau_pT_num_Cut"+prefix).c_str() ,"h_PfTau_pT_num_Cut",100,0,700);
 h_PfTau_Eta_num_Cut = fs->make<TH1F>(("h_PfTau_Eta_num_Cut"+prefix).c_str() ,"h_PfTau_Eta_num_Cut",100,-5,5);
  h_PfTau_Phi_num_Cut = fs->make<TH1F>(("h_PfTau_Phi_num_Cut"+prefix).c_str() ,"h_PfTau_Phi_num_Cut",100,-5,5);
  h_genElectron_pT_num_Cut = fs->make<TH1F>(("h_genElectron_pT_num_Cut"+prefix).c_str() ,"h_genElectron_pT_num_Cut",100,0,700);
  h_genElectron_Eta_num_Cut = fs->make<TH1F>(("h_genElectron_Eta_num_Cut"+prefix).c_str() ,"h_genElectron_Eta_num_Cut",100,-5,5); 
 h_genElectron_Phi_num_Cut = fs->make<TH1F>(("h_genElectron_Phi_num_Cut"+prefix).c_str() ,"h_genElectron_Phi_num_Cut",100,-5,5); 
 

 h_PfTau_pT_num_Cut_MV = fs->make<TH1F>(("h_PfTau_pT_num_Cut_MV"+prefix).c_str() ,"h_PfTau_pT_num_Cut_MV",100,0,700);
 h_PfTau_Eta_num_Cut_MV = fs->make<TH1F>(("h_PfTau_Eta_num_Cut_MV"+prefix).c_str() ,"h_PfTau_Eta_num_Cut_MV",100,-5,5);
  h_PfTau_Phi_num_Cut_MV = fs->make<TH1F>(("h_PfTau_Phi_num_Cut_MV"+prefix).c_str() ,"h_PfTau_Phi_num_Cut_MV",100,-5,5);
  h_genElectron_pT_num_Cut_MV = fs->make<TH1F>(("h_genElectron_pT_num_Cut_MV"+prefix).c_str() ,"h_genElectron_pT_num_Cut_MV",100,0,700);
  h_genElectron_Eta_num_Cut_MV = fs->make<TH1F>(("h_genElectron_Eta_num_Cut_MV"+prefix).c_str() ,"h_genElectron_Eta_num_Cut_MV",100,-5,5); 
 h_genElectron_Phi_num_Cut_MV = fs->make<TH1F>(("h_genElectron_Phi_num_Cut_MV"+prefix).c_str() ,"h_genElectron_Phi_num_Cut_MV",100,-5,5); 
 
// for medium

  h_PfTau_pT_numM_MV = fs->make<TH1F>(("h_PfTau_pT_numM_MV"+prefix).c_str() ,"h_PfTau_pT_numM_MV",100,0,700);
  h_PfTau_Eta_numM_MV = fs->make<TH1F>(("h_PfTau_Eta_numM_MV"+prefix).c_str() ,"h_PfTau_Eta_numM_MV",100,-5,5);
  h_PfTau_Phi_numM_MV = fs->make<TH1F>(("h_PfTau_Phi_numM_MV"+prefix).c_str() ,"h_PfTau_Phi_numM_MV",100,-5,5);
  h_genElectron_pT_numM_MV = fs->make<TH1F>(("h_genElectron_pT_numM_MV"+prefix).c_str() ,"h_genElectron_pT_numM_MV",100,0,700);
  h_genElectron_Eta_numM_MV = fs->make<TH1F>(("h_genElectron_Eta_numM_MV"+prefix).c_str() ,"h_genElectron_Eta_numM_MV",100,-5,5); 
  h_genElectron_Phi_numM_MV = fs->make<TH1F>(("h_genElectron_Phi_numM_MV"+prefix).c_str() ,"h_genElectron_Phi_numM_MV",100,-5,5); 
 

  h_PfTau_pT_numM = fs->make<TH1F>(("h_PfTau_pT_numM"+prefix).c_str() ,"h_PfTau_pT_numM",100,0,700);
  h_PfTau_Eta_numM = fs->make<TH1F>(("h_PfTau_Eta_numM"+prefix).c_str() ,"h_PfTau_Eta_numM",100,-5,5);
  h_PfTau_Phi_numM = fs->make<TH1F>(("h_PfTau_Phi_numM"+prefix).c_str() ,"h_PfTau_Phi_numM",100,-5,5);
  h_genElectron_pT_numM = fs->make<TH1F>(("h_genElectron_pT_numM"+prefix).c_str() ,"h_genElectron_pT_numM",100,0,700);
  h_genElectron_Eta_numM = fs->make<TH1F>(("h_genElectron_Eta_numM"+prefix).c_str() ,"h_genElectron_Eta_numM",100,-5,5); 
  h_genElectron_Phi_numM = fs->make<TH1F>(("h_genElectron_Phi_numM"+prefix).c_str() ,"h_genElectron_Phi_numM",100,-5,5); 


  h_PfTau_pT_numM_tight = fs->make<TH1F>(("h_PfTau_pT_numM_tight"+prefix).c_str() ,"h_PfTau_pT_numM_tight",100,0,700);
  h_PfTau_Eta_numM_tight = fs->make<TH1F>(("h_PfTau_Eta_numM_tight"+prefix).c_str() ,"h_PfTau_Eta_numM_tight",100,-5,5);
  h_PfTau_Phi_numM_tight = fs->make<TH1F>(("h_PfTau_Phi_numM_tight"+prefix).c_str() ,"h_PfTau_Phi_numM_tight",100,-5,5);
  h_genElectron_pT_numM_tight = fs->make<TH1F>(("h_genElectron_pT_numM_tight"+prefix).c_str() ,"h_genElectron_pT_numM_tight",100,0,700);
  h_genElectron_Eta_numM_tight = fs->make<TH1F>(("h_genElectron_Eta_numM_tight"+prefix).c_str() ,"h_genElectron_Eta_numM_tight",100,-5,5); 
  h_genElectron_Phi_numM_tight = fs->make<TH1F>(("h_genElectron_Phi_numM_tight"+prefix).c_str() ,"h_genElectron_Phi_numM_tight",100,-5,5); 


  h_PfTau_pT_numM_tight_MV = fs->make<TH1F>(("h_PfTau_pT_numM_tight_MV"+prefix).c_str() ,"h_PfTau_pT_numM_tight_MV",100,0,700);
  h_PfTau_Eta_numM_tight_MV = fs->make<TH1F>(("h_PfTau_Eta_numM_tight_MV"+prefix).c_str() ,"h_PfTau_Eta_numM_tight_MV",100,-5,5);
  h_PfTau_Phi_numM_tight_MV = fs->make<TH1F>(("h_PfTau_Phi_numM_tight_MV"+prefix).c_str() ,"h_PfTau_Phi_numM_tight_MV",100,-5,5);
  h_genElectron_pT_numM_tight_MV = fs->make<TH1F>(("h_genElectron_pT_numM_tight_MV"+prefix).c_str() ,"h_genElectron_pT_numM_tight_MV",100,0,700);
  h_genElectron_Eta_numM_tight_MV = fs->make<TH1F>(("h_genElectron_Eta_numM_tight_MV"+prefix).c_str() ,"h_genElectron_Eta_numM_tight_MV",100,-5,5); 
  h_genElectron_Phi_numM_tight_MV = fs->make<TH1F>(("h_genElectron_Phi_numM_tight_MV"+prefix).c_str() ,"h_genElectron_Phi_numM_tight_MV",100,-5,5); 



  h_PfTau_pT_numM_medium = fs->make<TH1F>(("h_PfTau_pT_numM_medium"+prefix).c_str() ,"h_PfTau_pT_numM_medium",100,0,700);
  h_PfTau_Eta_numM_medium = fs->make<TH1F>(("h_PfTau_Eta_numM_medium"+prefix).c_str() ,"h_PfTau_Eta_numM_medium",100,-5,5);
 h_PfTau_Phi_numM_medium = fs->make<TH1F>(("h_PfTau_Phi_numM_medium"+prefix).c_str() ,"h_PfTau_Phi_numM_medium",100,-5,5);
  h_genElectron_pT_numM_medium = fs->make<TH1F>(("h_genElectron_pT_numM_medium"+prefix).c_str() ,"h_genElectron_pT_numM_medium",100,0,700);
  h_genElectron_Eta_numM_medium = fs->make<TH1F>(("h_genElectron_Eta_numM_medium"+prefix).c_str() ,"h_genElectron_Eta_numM_medium",100,-5,5); 
  h_genElectron_Phi_numM_medium = fs->make<TH1F>(("h_genElectron_Phi_numM_medium"+prefix).c_str() ,"h_genElectron_Phi_numM_medium",100,-5,5);   


  //

   h_PfTau_pT_numM_medium_MV = fs->make<TH1F>(("h_PfTau_pT_numM_medium_MV"+prefix).c_str() ,"h_PfTau_pT_numM_medium_MV",100,0,700);
  h_PfTau_Eta_numM_medium_MV = fs->make<TH1F>(("h_PfTau_Eta_numM_medium_MV"+prefix).c_str() ,"h_PfTau_Eta_numM_medium_MV",100,-5,5);
 h_PfTau_Phi_numM_medium_MV = fs->make<TH1F>(("h_PfTau_Phi_numM_medium_MV"+prefix).c_str() ,"h_PfTau_Phi_numM_medium_MV",100,-5,5);
  h_genElectron_pT_numM_medium_MV = fs->make<TH1F>(("h_genElectron_pT_numM_medium_MV"+prefix).c_str() ,"h_genElectron_pT_numM_medium_MV",100,0,700);
  h_genElectron_Eta_numM_medium_MV = fs->make<TH1F>(("h_genElectron_Eta_numM_medium_MV"+prefix).c_str() ,"h_genElectron_Eta_numM_medium_MV",100,-5,5); 
  h_genElectron_Phi_numM_medium_MV = fs->make<TH1F>(("h_genElectron_Phi_numM_medium_MV"+prefix).c_str() ,"h_genElectron_Phi_numM_MVmedium",100,-5,5);   

  //
  h_PfTau_pT_numM_Cut = fs->make<TH1F>(("h_PfTau_pT_numM_Cut"+prefix).c_str() ,"h_PfTau_pT_numM_Cut",100,0,700);
 h_PfTau_Eta_numM_Cut = fs->make<TH1F>(("h_PfTau_Eta_numM_Cut"+prefix).c_str() ,"h_PfTau_Eta_numM_Cut",100,-5,5);
  h_PfTau_Phi_numM_Cut = fs->make<TH1F>(("h_PfTau_Phi_numM_Cut"+prefix).c_str() ,"h_PfTau_Phi_numM_Cut",100,-5,5);
  h_genElectron_pT_numM_Cut = fs->make<TH1F>(("h_genElectron_pT_numM_Cut"+prefix).c_str() ,"h_genElectron_pT_numM_Cut",100,0,700);
  h_genElectron_Eta_numM_Cut = fs->make<TH1F>(("h_genElectron_Eta_numM_Cut"+prefix).c_str() ,"h_genElectron_Eta_numM_Cut",100,-5,5); 
 h_genElectron_Phi_numM_Cut = fs->make<TH1F>(("h_genElectron_Phi_numM_Cut"+prefix).c_str() ,"h_genElectron_Phi_numM_Cut",100,-5,5); 
 

 h_PfTau_pT_numM_Cut_MV = fs->make<TH1F>(("h_PfTau_pT_numM_Cut_MV"+prefix).c_str() ,"h_PfTau_pT_numM_Cut_MV",100,0,700);
 h_PfTau_Eta_numM_Cut_MV = fs->make<TH1F>(("h_PfTau_Eta_numM_Cut_MV"+prefix).c_str() ,"h_PfTau_Eta_numM_Cut_MV",100,-5,5);
  h_PfTau_Phi_numM_Cut_MV = fs->make<TH1F>(("h_PfTau_Phi_numM_Cut_MV"+prefix).c_str() ,"h_PfTau_Phi_numM_Cut_MV",100,-5,5);
  h_genElectron_pT_numM_Cut_MV = fs->make<TH1F>(("h_genElectron_pT_numM_Cut_MV"+prefix).c_str() ,"h_genElectron_pT_numM_Cut_MV",100,0,700);
  h_genElectron_Eta_numM_Cut_MV = fs->make<TH1F>(("h_genElectron_Eta_numM_Cut_MV"+prefix).c_str() ,"h_genElectron_Eta_numM_Cut_MV",100,-5,5); 
 h_genElectron_Phi_numM_Cut_MV = fs->make<TH1F>(("h_genElectron_Phi_numM_Cut_MV"+prefix).c_str() ,"h_genElectron_Phi_numM_Cut_MV",100,-5,5); 

 //  for tight///

  h_PfTau_pT_numT = fs->make<TH1F>(("h_PfTau_pT_numT"+prefix).c_str() ,"h_PfTau_pT_numT",100,0,700);
  h_PfTau_Eta_numT = fs->make<TH1F>(("h_PfTau_Eta_numT"+prefix).c_str() ,"h_PfTau_Eta_numT",100,-5,5);
  h_PfTau_Phi_numT = fs->make<TH1F>(("h_PfTau_Phi_numT"+prefix).c_str() ,"h_PfTau_Phi_numT",100,-5,5);
  h_genElectron_pT_numT = fs->make<TH1F>(("h_genElectron_pT_numT"+prefix).c_str() ,"h_genElectron_pT_numT",100,0,700);
  h_genElectron_Eta_numT = fs->make<TH1F>(("h_genElectron_Eta_numT"+prefix).c_str() ,"h_genElectron_Eta_numT",100,-5,5); 
  h_genElectron_Phi_numT = fs->make<TH1F>(("h_genElectron_Phi_numT"+prefix).c_str() ,"h_genElectron_Phi_numT",100,-5,5); 


  h_PfTau_pT_numT_MV = fs->make<TH1F>(("h_PfTau_pT_numT_MV"+prefix).c_str() ,"h_PfTau_pT_numT_MV",100,0,700);
  h_PfTau_Eta_numT_MV = fs->make<TH1F>(("h_PfTau_Eta_numT_MV"+prefix).c_str() ,"h_PfTau_Eta_numT_MV",100,-5,5);
  h_PfTau_Phi_numT_MV = fs->make<TH1F>(("h_PfTau_Phi_numT_MV"+prefix).c_str() ,"h_PfTau_Phi_numT_MV",100,-5,5);
  h_genElectron_pT_numT_MV = fs->make<TH1F>(("h_genElectron_pT_numT_MV"+prefix).c_str() ,"h_genElectron_pT_numT_MV",100,0,700);
  h_genElectron_Eta_numT_MV = fs->make<TH1F>(("h_genElectron_Eta_numT_MV"+prefix).c_str() ,"h_genElectron_Eta_numT_MV",100,-5,5); 
  h_genElectron_Phi_numT_MV = fs->make<TH1F>(("h_genElectron_Phi_numT_MV"+prefix).c_str() ,"h_genElectron_Phi_numT_MV",100,-5,5); 
 

  h_PfTau_pT_numT_tight = fs->make<TH1F>(("h_PfTau_pT_numT_tight"+prefix).c_str() ,"h_PfTau_pT_numT_tight",100,0,700);
  h_PfTau_Eta_numT_tight = fs->make<TH1F>(("h_PfTau_Eta_numT_tight"+prefix).c_str() ,"h_PfTau_Eta_numT_tight",100,-5,5);
  h_PfTau_Phi_numT_tight = fs->make<TH1F>(("h_PfTau_Phi_numT_tight"+prefix).c_str() ,"h_PfTau_Phi_numT_tight",100,-5,5);
  h_genElectron_pT_numT_tight = fs->make<TH1F>(("h_genElectron_pT_numT_tight"+prefix).c_str() ,"h_genElectron_pT_numT_tight",100,0,700);
  h_genElectron_Eta_numT_tight = fs->make<TH1F>(("h_genElectron_Eta_numT_tight"+prefix).c_str() ,"h_genElectron_Eta_numT_tight",100,-5,5); 
  h_genElectron_Phi_numT_tight = fs->make<TH1F>(("h_genElectron_Phi_numT_tight"+prefix).c_str() ,"h_genElectron_Phi_numT_tight",100,-5,5); 


  h_PfTau_pT_numT_tight_MV = fs->make<TH1F>(("h_PfTau_pT_numT_tight_MV"+prefix).c_str() ,"h_PfTau_pT_numT_tight_MV",100,0,700);
  h_PfTau_Eta_numT_tight_MV = fs->make<TH1F>(("h_PfTau_Eta_numT_tight_MV"+prefix).c_str() ,"h_PfTau_Eta_numT_tight_MV",100,-5,5);
  h_PfTau_Phi_numT_tight_MV = fs->make<TH1F>(("h_PfTau_Phi_numT_tight_MV"+prefix).c_str() ,"h_PfTau_Phi_numT_tight_MV",100,-5,5);
  h_genElectron_pT_numT_tight_MV = fs->make<TH1F>(("h_genElectron_pT_numT_tight_MV"+prefix).c_str() ,"h_genElectron_pT_numT_tight_MV",100,0,700);
  h_genElectron_Eta_numT_tight_MV = fs->make<TH1F>(("h_genElectron_Eta_numT_tight_MV"+prefix).c_str() ,"h_genElectron_Eta_numT_tight_MV",100,-5,5); 
  h_genElectron_Phi_numT_tight_MV = fs->make<TH1F>(("h_genElectron_Phi_numT_tight_MV"+prefix).c_str() ,"h_genElectron_Phi_numT_tight_MV",100,-5,5); 



  h_PfTau_pT_numT_medium = fs->make<TH1F>(("h_PfTau_pT_numT_medium"+prefix).c_str() ,"h_PfTau_pT_numT_medium",100,0,700);
  h_PfTau_Eta_numT_medium = fs->make<TH1F>(("h_PfTau_Eta_numT_medium"+prefix).c_str() ,"h_PfTau_Eta_numT_medium",100,-5,5);
 h_PfTau_Phi_numT_medium = fs->make<TH1F>(("h_PfTau_Phi_numT_medium"+prefix).c_str() ,"h_PfTau_Phi_numT_medium",100,-5,5);
  h_genElectron_pT_numT_medium = fs->make<TH1F>(("h_genElectron_pT_numT_medium"+prefix).c_str() ,"h_genElectron_pT_numT_medium",100,0,700);
  h_genElectron_Eta_numT_medium = fs->make<TH1F>(("h_genElectron_Eta_numT_medium"+prefix).c_str() ,"h_genElectron_Eta_numT_medium",100,-5,5); 
  h_genElectron_Phi_numT_medium = fs->make<TH1F>(("h_genElectron_Phi_numT_medium"+prefix).c_str() ,"h_genElectron_Phi_numT_medium",100,-5,5);   


  //

   h_PfTau_pT_numT_medium_MV = fs->make<TH1F>(("h_PfTau_pT_numT_medium_MV"+prefix).c_str() ,"h_PfTau_pT_numT_medium_MV",100,0,700);
  h_PfTau_Eta_numT_medium_MV = fs->make<TH1F>(("h_PfTau_Eta_numT_medium_MV"+prefix).c_str() ,"h_PfTau_Eta_numT_medium_MV",100,-5,5);
 h_PfTau_Phi_numT_medium_MV = fs->make<TH1F>(("h_PfTau_Phi_numT_medium_MV"+prefix).c_str() ,"h_PfTau_Phi_numT_medium_MV",100,-5,5);
  h_genElectron_pT_numT_medium_MV = fs->make<TH1F>(("h_genElectron_pT_numT_medium_MV"+prefix).c_str() ,"h_genElectron_pT_numT_medium_MV",100,0,700);
  h_genElectron_Eta_numT_medium_MV = fs->make<TH1F>(("h_genElectron_Eta_numT_medium_MV"+prefix).c_str() ,"h_genElectron_Eta_numT_medium_MV",100,-5,5); 
  h_genElectron_Phi_numT_medium_MV = fs->make<TH1F>(("h_genElectron_Phi_numT_medium_MV"+prefix).c_str() ,"h_genElectron_Phi_numT_MVmedium",100,-5,5);   

  //
  h_PfTau_pT_numT_Cut = fs->make<TH1F>(("h_PfTau_pT_numT_Cut"+prefix).c_str() ,"h_PfTau_pT_numT_Cut",100,0,700);
 h_PfTau_Eta_numT_Cut = fs->make<TH1F>(("h_PfTau_Eta_numT_Cut"+prefix).c_str() ,"h_PfTau_Eta_numT_Cut",100,-5,5);
  h_PfTau_Phi_numT_Cut = fs->make<TH1F>(("h_PfTau_Phi_numT_Cut"+prefix).c_str() ,"h_PfTau_Phi_numT_Cut",100,-5,5);
  h_genElectron_pT_numT_Cut = fs->make<TH1F>(("h_genElectron_pT_numT_Cut"+prefix).c_str() ,"h_genElectron_pT_numT_Cut",100,0,700);
  h_genElectron_Eta_numT_Cut = fs->make<TH1F>(("h_genElectron_Eta_numT_Cut"+prefix).c_str() ,"h_genElectron_Eta_numT_Cut",100,-5,5); 
 h_genElectron_Phi_numT_Cut = fs->make<TH1F>(("h_genElectron_Phi_numT_Cut"+prefix).c_str() ,"h_genElectron_Phi_numT_Cut",100,-5,5); 
 

 h_PfTau_pT_numT_Cut_MV = fs->make<TH1F>(("h_PfTau_pT_numT_Cut_MV"+prefix).c_str() ,"h_PfTau_pT_numT_Cut_MV",100,0,700);
 h_PfTau_Eta_numT_Cut_MV = fs->make<TH1F>(("h_PfTau_Eta_numT_Cut_MV"+prefix).c_str() ,"h_PfTau_Eta_numT_Cut_MV",100,-5,5);
  h_PfTau_Phi_numT_Cut_MV = fs->make<TH1F>(("h_PfTau_Phi_numT_Cut_MV"+prefix).c_str() ,"h_PfTau_Phi_numT_Cut_MV",100,-5,5);
  h_genElectron_pT_numT_Cut_MV = fs->make<TH1F>(("h_genElectron_pT_numT_Cut_MV"+prefix).c_str() ,"h_genElectron_pT_numT_Cut_MV",100,0,700);
  h_genElectron_Eta_numT_Cut_MV = fs->make<TH1F>(("h_genElectron_Eta_numT_Cut_MV"+prefix).c_str() ,"h_genElectron_Eta_numT_Cut_MV",100,-5,5); 
 h_genElectron_Phi_numT_Cut_MV = fs->make<TH1F>(("h_genElectron_Phi_numT_Cut_MV"+prefix).c_str() ,"h_genElectron_Phi_numT_Cut_MV",100,-5,5); 


 /// for tight ends //
  hFillTauHcal3x3OverPLead_after  = fs->make<TH1F>(("hFillTauHcal3x3OverPLead_after"+prefix).c_str() ,"hFillTauHcal3x3OverPLead_befor",1000,0,50);
  FillHOverP_after  = fs->make<TH1F>(("FillHOverP_after"+prefix).c_str() ,"FillHOverP_after",1000,0,50);
  FillEOverP_after  = fs->make<TH1F>(("FillEOverP_after"+prefix).c_str() ,"FillEOverP_brfore",1000,0,30); 
  FillGammaFraction_after = fs->make<TH1F>(("FillGammaFraction_after"+prefix).c_str() ,"FillGammaFraction_after",1000,0,5);
  


  hFillTauHcal3x3OverPLead_before  = fs->make<TH1F>(("hFillTauHcal3x3OverPLead_before"+prefix).c_str() ,"hFillTauHcal3x3OverPLead_befor",1000,0,50);
  FillHOverP_before  = fs->make<TH1F>(("FillHOverP_before"+prefix).c_str() ,"FillHOverP_before",1000,0,50);
  FillEOverP_before  = fs->make<TH1F>(("FillEOverP_before"+prefix).c_str() ,"FillEOverP_brfore",1000,0,30); 
  FillGammaFraction_before = fs->make<TH1F>(("FillGammaFraction_before"+prefix).c_str() ,"FillGammaFraction_before",1000,0,5);
  

}


ETauFakeRate::~ETauFakeRate()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called for each event  ------------
void ETauFakeRate::Fill(const edm::Event& iEvent) {
  using namespace edm;
  using namespace std;
  using namespace reco;
  using namespace pat;
  
  iEvent.getByLabel("genParticles", _genParticles); 
  
  Handle< reco::TrackCollection > track;
  iEvent.getByLabel("generalTracks", track);
  
  Handle< reco::GenJetCollection > genTauJets;
  iEvent.getByLabel("tauGenJets",genTauJets);
  
  edm::Handle<pat::JetCollection> pfjet;
  iEvent.getByLabel("selectedPatJets", pfjet);
  
  edm::Handle<std::vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel(std::string("addPileupInfo"), PupInfo);
  
  edm::Handle<reco::MuonCollection> rmuons;
  iEvent.getByLabel("muons",rmuons);

  edm::Handle<reco::VertexCollection> vtx;
  iEvent.getByLabel("offlinePrimaryVertices",vtx);
  

  //  vector<pat::Electron>                    "patElectrons"                  ""           "PATTuple"  
 
  
  iEvent.getByLabel("ak5GenJets", _genJets);
  
  
  iEvent.getByLabel("hpsPFTauProducer",_hpsTaucoll);
  //decay Mode
   iEvent.getByLabel("hpsPFTauDiscriminationByDecayModeFindingOldDMs",_dmf);
  //Muon Veto

   //Muon 2 working pint
   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection2",_mv1);
   iEvent.getByLabel("hpsPFTauDiscriminationByMediumMuonRejection2",_mv2);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection2",_mv3);
   
   // Muon 3 working points

   iEvent.getByLabel("hpsPFTauDiscriminationByLooseMuonRejection3",_mv31);
   iEvent.getByLabel("hpsPFTauDiscriminationByTightMuonRejection3",_mv32);

   //Electron Veto

   //cut bases

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
  
  
  
  bool isZEE=false;
  isZEE = IsZEE(_genParticles) ;

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
  
   
   std::vector<PileupSummaryInfo>::const_iterator PVI;
   for (PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
     PUInfo += PVI->getPU_NumInteractions();
     if(PVI->getBunchCrossing()== 0){
       PUInfo_Bunch0 += PVI->getPU_NumInteractions();
       PUInfo_true = PVI->getTrueNumInteractions();
     }
   }
   


 
  if(isZEE) {
    
      
    for(reco::GenParticleCollection::const_iterator genparticles = _genParticles->begin(); genparticles !=  _genParticles->end(); ++genparticles) {
      
      if(genparticles->pt() <= 20) continue;
      if(abs(genparticles->eta()) <= etacutmin ) continue;
      if(abs(genparticles->eta()) >= etacut ) continue;
      
      if(((abs(genparticles->pdgId()) == 11) )) {
	if(abs(genparticles->mother(0)->pdgId()) == _TauMotherId) {
	  
      
          h_genElectron_pT_den->Fill(genparticles->pt());
          h_genElectron_Eta_den->Fill(genparticles->eta());
          h_genElectron_Phi_den->Fill(genparticles->phi());
          Nvtx_den->Fill(PUInfo_true); 
          NGood_den->Fill(nGoodVtx);

    
    int index1= -1;
    if(OverlapWithGenTauForOther(genparticles->eta() , genparticles->phi() , _hpsTaucoll, _dmf ,index1 )) {
     if(index1 != -1){
     reco::PFTauRef tauCandidate(_hpsTaucoll, index1);

      h_PfTau_pT_DMF->Fill(tauCandidate->pt());
      h_PfTau_Eta_DMF->Fill(tauCandidate->eta()); 
      h_PfTau_Phi_DMF->Fill(tauCandidate->phi());
  
      h_genElectron_pT_DMF->Fill(genparticles->pt());
      h_genElectron_Eta_DMF->Fill(genparticles->eta());
      h_genElectron_Phi_DMF->Fill(genparticles->phi());    
      Nvtx_DMF->Fill(PUInfo_true);                                              
      NGood_DMF->Fill(nGoodVtx);
 
   
   // Invidiual loops
   if((tauCandidate->leadPFChargedHadrCand().isNonnull()) && (tauCandidate->leadPFChargedHadrCand()->p() > 0)) {       
     
     FillHOverP_before->Fill(tauCandidate->leadPFChargedHadrCand()->hcalEnergy()/tauCandidate->leadPFChargedHadrCand()->p());
     FillEOverP_before->Fill(tauCandidate->leadPFChargedHadrCand()->ecalEnergy()/tauCandidate->leadPFChargedHadrCand()->p());
     
   }
   
   hFillTauHcal3x3OverPLead_before->Fill(tauCandidate->hcal3x3OverPLead());
   
   // photon fraction
   
   int sumPt1 = 0;
        for ( std::vector<PFCandidatePtr>::const_iterator signalTrack =  tauCandidate->signalPFGammaCands().begin() ;signalTrack != tauCandidate->signalPFGammaCands().end(); ++signalTrack ) {
     sumPt1 += (*signalTrack)->pt();
     
   }
   
   if(tauCandidate->pt() > 0 ){ FillGammaFraction_before->Fill(sumPt1/tauCandidate->pt()); }



   if((*_rawc)[tauCandidate] < 4){
     
     
     //tau part
     if((*_ev1)[tauCandidate] > 0.5) { 
       h_PfTau_pT_num->Fill(tauCandidate->pt());
       h_PfTau_Eta_num->Fill(tauCandidate->eta());
       h_PfTau_Phi_num->Fill(tauCandidate->phi());
       
       h_genElectron_pT_num->Fill(genparticles->pt());
       h_genElectron_Eta_num->Fill(genparticles->eta());
       h_genElectron_Phi_num->Fill(genparticles->phi());    
       Nvtx_num->Fill(PUInfo_true);                                              
       NGood_num->Fill(nGoodVtx);
      
       if((*_mv31)[tauCandidate] > 0.5) {
	 h_PfTau_pT_num_MV->Fill(tauCandidate->pt());
	 h_PfTau_Eta_num_MV->Fill(tauCandidate->eta());
	 h_PfTau_Phi_num_MV->Fill(tauCandidate->phi());
	 
	 h_genElectron_pT_num_MV->Fill(genparticles->pt());
	 h_genElectron_Eta_num_MV->Fill(genparticles->eta());
	 h_genElectron_Phi_num_MV->Fill(genparticles->phi());    
	 Nvtx_num_MV->Fill(PUInfo_true);                                              
	 NGood_num_MV->Fill(nGoodVtx);
      


       }
       //Fill Reco 
     }
     
     if((*_ev2)[tauCandidate] > 0.5){ 
       h_PfTau_pT_num_medium->Fill(tauCandidate->pt());
       h_PfTau_Eta_num_medium->Fill(tauCandidate->eta());
       h_PfTau_Phi_num_medium->Fill(tauCandidate->phi());
       
       h_genElectron_pT_num_medium->Fill(genparticles->pt());
       h_genElectron_Eta_num_medium->Fill(genparticles->eta());
       h_genElectron_Phi_num_medium->Fill(genparticles->phi());
       Nvtx_num_medium->Fill(PUInfo_true);                               
       NGood_num_medium->Fill(nGoodVtx);
       
       if((*_mv31)[tauCandidate] > 0.5) {
         h_PfTau_pT_num_medium_MV->Fill(tauCandidate->pt());
         h_PfTau_Eta_num_medium_MV->Fill(tauCandidate->eta());
         h_PfTau_Phi_num_medium_MV->Fill(tauCandidate->phi());

         h_genElectron_pT_num_medium_MV->Fill(genparticles->pt());
         h_genElectron_Eta_num_medium_MV->Fill(genparticles->eta());
         h_genElectron_Phi_num_medium_MV->Fill(genparticles->phi());
         Nvtx_num_medium_MV->Fill(PUInfo_true);                            
         NGood_num_medium_MV->Fill(nGoodVtx);

       }


       //
     }
     // Tight Veto
    if((*_ev3)[tauCandidate] > 0.5) {
      h_PfTau_pT_num_tight->Fill(tauCandidate->pt());
      h_PfTau_Eta_num_tight->Fill(tauCandidate->eta());
      h_PfTau_Phi_num_tight->Fill(tauCandidate->phi());
      
      h_genElectron_pT_num_tight->Fill(genparticles->pt());
      h_genElectron_Eta_num_tight->Fill(genparticles->eta());
      h_genElectron_Phi_num_tight->Fill(genparticles->phi()); 
      Nvtx_num_tight->Fill(PUInfo_true);                               
      NGood_num_tight->Fill(nGoodVtx);
      
       if((*_mv31)[tauCandidate] > 0.5) {
         h_PfTau_pT_num_tight_MV->Fill(tauCandidate->pt());
         h_PfTau_Eta_num_tight_MV->Fill(tauCandidate->eta());
         h_PfTau_Phi_num_tight_MV->Fill(tauCandidate->phi());

         h_genElectron_pT_num_tight_MV->Fill(genparticles->pt());
         h_genElectron_Eta_num_tight_MV->Fill(genparticles->eta());
         h_genElectron_Phi_num_tight_MV->Fill(genparticles->phi());
         Nvtx_num_tight_MV->Fill(PUInfo_true);   
         NGood_num_tight_MV->Fill(nGoodVtx);

       }
    }
    
    if((*_enew)[tauCandidate] > 0.5) {
      
      h_PfTau_pT_num_Cut->Fill(tauCandidate->pt());
      h_PfTau_Eta_num_Cut->Fill(tauCandidate->eta());
      h_PfTau_Phi_num_Cut->Fill(tauCandidate->phi());
      h_genElectron_pT_num_Cut->Fill(genparticles->pt());
      h_genElectron_Eta_num_Cut->Fill(genparticles->eta());
      h_genElectron_Phi_num_Cut->Fill(genparticles->phi());
      Nvtx_num_Cut->Fill(PUInfo_true);                               
      NGood_num_Cut->Fill(nGoodVtx);
      
       if((*_mv31)[tauCandidate] > 0.5) {
         h_PfTau_pT_num_Cut_MV->Fill(tauCandidate->pt());
         h_PfTau_Eta_num_Cut_MV->Fill(tauCandidate->eta());
         h_PfTau_Phi_num_Cut_MV->Fill(tauCandidate->phi());

         h_genElectron_pT_num_Cut_MV->Fill(genparticles->pt());
         h_genElectron_Eta_num_Cut_MV->Fill(genparticles->eta());
         h_genElectron_Phi_num_Cut_MV->Fill(genparticles->phi());
         Nvtx_num_Cut_MV->Fill(PUInfo_true);    
         NGood_num_Cut_MV->Fill(nGoodVtx);

       }

    }
    
   }

   // medium


   if((*_rawc)[tauCandidate] < 2){
     
     
     //tau part
     if((*_ev1)[tauCandidate] > 0.5) { 
       h_PfTau_pT_numM->Fill(tauCandidate->pt());
       h_PfTau_Eta_numM->Fill(tauCandidate->eta());
       h_PfTau_Phi_numM->Fill(tauCandidate->phi());
       
       h_genElectron_pT_numM->Fill(genparticles->pt());
       h_genElectron_Eta_numM->Fill(genparticles->eta());
       h_genElectron_Phi_numM->Fill(genparticles->phi());    
       Nvtx_numM->Fill(PUInfo_true);                                              
       NGood_numM->Fill(nGoodVtx);
      
       if((*_mv31)[tauCandidate] > 0.5) {
	 h_PfTau_pT_numM_MV->Fill(tauCandidate->pt());
	 h_PfTau_Eta_numM_MV->Fill(tauCandidate->eta());
	 h_PfTau_Phi_numM_MV->Fill(tauCandidate->phi());
	 
	 h_genElectron_pT_numM_MV->Fill(genparticles->pt());
	 h_genElectron_Eta_numM_MV->Fill(genparticles->eta());
	 h_genElectron_Phi_numM_MV->Fill(genparticles->phi());    
	 Nvtx_numM_MV->Fill(PUInfo_true);                                              
	 NGood_numM_MV->Fill(nGoodVtx);
      


       }
       //Fill Reco 
     }
     
     if((*_ev2)[tauCandidate] > 0.5){ 
       h_PfTau_pT_numM_medium->Fill(tauCandidate->pt());
       h_PfTau_Eta_numM_medium->Fill(tauCandidate->eta());
       h_PfTau_Phi_numM_medium->Fill(tauCandidate->phi());
       
       h_genElectron_pT_numM_medium->Fill(genparticles->pt());
       h_genElectron_Eta_numM_medium->Fill(genparticles->eta());
       h_genElectron_Phi_numM_medium->Fill(genparticles->phi());
       Nvtx_numM_medium->Fill(PUInfo_true);                               
       NGood_numM_medium->Fill(nGoodVtx);
       
       if((*_mv31)[tauCandidate] > 0.5) {
         h_PfTau_pT_numM_medium_MV->Fill(tauCandidate->pt());
         h_PfTau_Eta_numM_medium_MV->Fill(tauCandidate->eta());
         h_PfTau_Phi_numM_medium_MV->Fill(tauCandidate->phi());

         h_genElectron_pT_numM_medium_MV->Fill(genparticles->pt());
         h_genElectron_Eta_numM_medium_MV->Fill(genparticles->eta());
         h_genElectron_Phi_numM_medium_MV->Fill(genparticles->phi());
         Nvtx_numM_medium_MV->Fill(PUInfo_true);                            
         NGood_numM_medium_MV->Fill(nGoodVtx);

       }


       //
     }
     // Tight Veto
    if((*_ev3)[tauCandidate] > 0.5) {
      h_PfTau_pT_numM_tight->Fill(tauCandidate->pt());
      h_PfTau_Eta_numM_tight->Fill(tauCandidate->eta());
      h_PfTau_Phi_numM_tight->Fill(tauCandidate->phi());
      
      h_genElectron_pT_numM_tight->Fill(genparticles->pt());
      h_genElectron_Eta_numM_tight->Fill(genparticles->eta());
      h_genElectron_Phi_numM_tight->Fill(genparticles->phi()); 
      Nvtx_numM_tight->Fill(PUInfo_true);                               
      NGood_numM_tight->Fill(nGoodVtx);
      
       if((*_mv31)[tauCandidate] > 0.5) {
         h_PfTau_pT_numM_tight_MV->Fill(tauCandidate->pt());
         h_PfTau_Eta_numM_tight_MV->Fill(tauCandidate->eta());
         h_PfTau_Phi_numM_tight_MV->Fill(tauCandidate->phi());

         h_genElectron_pT_numM_tight_MV->Fill(genparticles->pt());
         h_genElectron_Eta_numM_tight_MV->Fill(genparticles->eta());
         h_genElectron_Phi_numM_tight_MV->Fill(genparticles->phi());
         Nvtx_numM_tight_MV->Fill(PUInfo_true);                            
         NGood_numM_tight_MV->Fill(nGoodVtx);

       }



    }
    
    if((*_enew)[tauCandidate] > 0.5) {
      
      h_PfTau_pT_numM_Cut->Fill(tauCandidate->pt());
      h_PfTau_Eta_numM_Cut->Fill(tauCandidate->eta());
      h_PfTau_Phi_numM_Cut->Fill(tauCandidate->phi());
      h_genElectron_pT_numM_Cut->Fill(genparticles->pt());
      h_genElectron_Eta_numM_Cut->Fill(genparticles->eta());
      h_genElectron_Phi_numM_Cut->Fill(genparticles->phi());
      Nvtx_numM_Cut->Fill(PUInfo_true);                               
      NGood_numM_Cut->Fill(nGoodVtx);
      
       if((*_mv31)[tauCandidate] > 0.5) {
         h_PfTau_pT_numM_Cut_MV->Fill(tauCandidate->pt());
         h_PfTau_Eta_numM_Cut_MV->Fill(tauCandidate->eta());
         h_PfTau_Phi_numM_Cut_MV->Fill(tauCandidate->phi());

         h_genElectron_pT_numM_Cut_MV->Fill(genparticles->pt());
         h_genElectron_Eta_numM_Cut_MV->Fill(genparticles->eta());
         h_genElectron_Phi_numM_Cut_MV->Fill(genparticles->phi());
         Nvtx_numM_Cut_MV->Fill(PUInfo_true);                            
         NGood_numM_Cut_MV->Fill(nGoodVtx);

       }

    }
    
   }
   /// medium done
   // tight shuru
   


   if((*_rawc)[tauCandidate] < 1){
     
     
     //tau part
     if((*_ev1)[tauCandidate] > 0.5) { 
       h_PfTau_pT_numT->Fill(tauCandidate->pt());
       h_PfTau_Eta_numT->Fill(tauCandidate->eta());
       h_PfTau_Phi_numT->Fill(tauCandidate->phi());
       
       h_genElectron_pT_numT->Fill(genparticles->pt());
       h_genElectron_Eta_numT->Fill(genparticles->eta());
       h_genElectron_Phi_numT->Fill(genparticles->phi());    
       Nvtx_numT->Fill(PUInfo_true);                                              
       NGood_numT->Fill(nGoodVtx);
      
       if((*_mv31)[tauCandidate] > 0.5) {
	 h_PfTau_pT_numT_MV->Fill(tauCandidate->pt());
	 h_PfTau_Eta_numT_MV->Fill(tauCandidate->eta());
	 h_PfTau_Phi_numT_MV->Fill(tauCandidate->phi());
	 
	 h_genElectron_pT_numT_MV->Fill(genparticles->pt());
	 h_genElectron_Eta_numT_MV->Fill(genparticles->eta());
	 h_genElectron_Phi_numT_MV->Fill(genparticles->phi());    
	 Nvtx_numT_MV->Fill(PUInfo_true);                                              
	 NGood_numT_MV->Fill(nGoodVtx);
      


       }
       //Fill Reco 
     }
     
     if((*_ev2)[tauCandidate] > 0.5){ 
       h_PfTau_pT_numT_medium->Fill(tauCandidate->pt());
       h_PfTau_Eta_numT_medium->Fill(tauCandidate->eta());
       h_PfTau_Phi_numT_medium->Fill(tauCandidate->phi());
       
       h_genElectron_pT_numT_medium->Fill(genparticles->pt());
       h_genElectron_Eta_numT_medium->Fill(genparticles->eta());
       h_genElectron_Phi_numT_medium->Fill(genparticles->phi());
       Nvtx_numT_medium->Fill(PUInfo_true);                               
       NGood_numT_medium->Fill(nGoodVtx);
       
       if((*_mv31)[tauCandidate] > 0.5) {
         h_PfTau_pT_numT_medium_MV->Fill(tauCandidate->pt());
         h_PfTau_Eta_numT_medium_MV->Fill(tauCandidate->eta());
         h_PfTau_Phi_numT_medium_MV->Fill(tauCandidate->phi());

         h_genElectron_pT_numT_medium_MV->Fill(genparticles->pt());
         h_genElectron_Eta_numT_medium_MV->Fill(genparticles->eta());
         h_genElectron_Phi_numT_medium_MV->Fill(genparticles->phi());
         Nvtx_numT_medium_MV->Fill(PUInfo_true);                            
         NGood_numT_medium_MV->Fill(nGoodVtx);

       }


       //
     }
     // Tight Veto
    if((*_ev3)[tauCandidate] > 0.5) {
      h_PfTau_pT_numT_tight->Fill(tauCandidate->pt());
      h_PfTau_Eta_numT_tight->Fill(tauCandidate->eta());
      h_PfTau_Phi_numT_tight->Fill(tauCandidate->phi());
      
      h_genElectron_pT_numT_tight->Fill(genparticles->pt());
      h_genElectron_Eta_numT_tight->Fill(genparticles->eta());
      h_genElectron_Phi_numT_tight->Fill(genparticles->phi()); 
      Nvtx_numT_tight->Fill(PUInfo_true);                               
      NGood_numT_tight->Fill(nGoodVtx);
      
       if((*_mv31)[tauCandidate] > 0.5) {
         h_PfTau_pT_numT_tight_MV->Fill(tauCandidate->pt());
         h_PfTau_Eta_numT_tight_MV->Fill(tauCandidate->eta());
         h_PfTau_Phi_numT_tight_MV->Fill(tauCandidate->phi());

         h_genElectron_pT_numT_tight_MV->Fill(genparticles->pt());
         h_genElectron_Eta_numT_tight_MV->Fill(genparticles->eta());
         h_genElectron_Phi_numT_tight_MV->Fill(genparticles->phi());
         Nvtx_numT_tight_MV->Fill(PUInfo_true);                            
         NGood_numT_tight_MV->Fill(nGoodVtx);

       }
    }
    
    if((*_enew)[tauCandidate] > 0.5) {
      
      h_PfTau_pT_numT_Cut->Fill(tauCandidate->pt());
      h_PfTau_Eta_numT_Cut->Fill(tauCandidate->eta());
      h_PfTau_Phi_numT_Cut->Fill(tauCandidate->phi());
      h_genElectron_pT_numT_Cut->Fill(genparticles->pt());
      h_genElectron_Eta_numT_Cut->Fill(genparticles->eta());
      h_genElectron_Phi_numT_Cut->Fill(genparticles->phi());
      Nvtx_numT_Cut->Fill(PUInfo_true);                               
      NGood_numT_Cut->Fill(nGoodVtx);
      
       if((*_mv31)[tauCandidate] > 0.5) {
         h_PfTau_pT_numT_Cut_MV->Fill(tauCandidate->pt());
         h_PfTau_Eta_numT_Cut_MV->Fill(tauCandidate->eta());
         h_PfTau_Phi_numT_Cut_MV->Fill(tauCandidate->phi());

         h_genElectron_pT_numT_Cut_MV->Fill(genparticles->pt());
         h_genElectron_Eta_numT_Cut_MV->Fill(genparticles->eta());
         h_genElectron_Phi_numT_Cut_MV->Fill(genparticles->phi());
         Nvtx_numT_Cut_MV->Fill(PUInfo_true);                            
         NGood_numT_Cut_MV->Fill(nGoodVtx);

       }

    }
    
   }
     }
    }
	}
      }
    }
  }
}


   //}

// ------------ method called once each job just before starting event loop  ------------

bool ETauFakeRate::OverlapWithGenTauForOther(double Taueta , double Tauphi , edm::Handle<reco::PFTauCollection> taujetcol, edm::Handle<reco::PFTauDiscriminator>  disc ,int &index ) {
   double drtmp = _TauToGenMatchingDeltaR;
   bool genTaufound = false;
   index = -1;
   for ( unsigned iTau = 0; iTau < taujetcol->size(); ++iTau ) {
     reco::PFTauRef tauCandidate(taujetcol,iTau);
     if(tauCandidate->pt() <= 20) continue;
     if(fabs(tauCandidate->eta()) <= etacutmin) continue;
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


bool ETauFakeRate::IsZEE(edm::Handle<reco::GenParticleCollection> genParticles){
   bool isZEE = false;
  reco::GenParticleCollection::const_iterator particle;
  for (particle = genParticles->begin(); particle != genParticles->end();  particle++) {
    if ((abs(particle->pdgId()) == _TauMotherId)) {
//      std::cout<<" Z found with pdgid = "<<particle->numberOfDaughters()<<std::endl;
      int daughters  = particle->numberOfDaughters();
       for (int j = 0; j<daughters; ++j) {
        const reco::Candidate *daughter = particle->daughter(j);
         int pidg = std::abs(daughter->pdgId());
// int status = daughter->status();
         if (pidg == 11) {
           isZEE = true;
//           std::cout<<"working inside function"<<std::endl;
           break;
        }
      }
    }
  }
  return isZEE;  
}

bool ETauFakeRate::OverlapWithGenMu(double Taueta , double Tauphi ,edm::Handle<reco::GenParticleCollection> genParticles ,int  &index ) {
  double drtmp = _TauToGenMatchingDeltaR;
  int tmpindex =0 ;
  bool genTaufound = false;
  for(reco::GenParticleCollection::const_iterator genmuons=genParticles->begin(); genmuons!=genParticles->end(); ++genmuons) {
    if(((abs(genmuons->pdgId()) == 11) && (genmuons->status() ==3))) {
	 if(abs(genmuons->mother(0)->pdgId()) == _TauMotherId) {
    double dr =reco::deltaR(Taueta, Tauphi,genmuons->eta(),genmuons->phi());
    if(dr < drtmp){
      drtmp = dr;
      index = tmpindex;
      genTaufound= true;
    } 
    tmpindex++;
	 }
       }
       }
    return genTaufound;
  }
  

