#include "./JetTauFakeRateFullSimonEta40.h"                                                                                                                                        
#include "DataFormats/TrackReco/interface/HitPattern.h"

JetTauFakeRateFullSimonEta40::JetTauFakeRateFullSimonEta40(std::string prefix,edm::Service<TFileService> fs,const edm::ParameterSet& iConfig)
{
  
  //now do what ever initialization is needed
 JetCorrectionService = iConfig.getParameter<std::string> ("JetCorrectionService"); 
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

  //h_RPC_FourthStation_etag1p2 = fs->make<TH1F>(("h_RPC_FourthStation_etag1p2"+prefix).c_str() ,"h_RPC_FourthStation_etag1p2",15,0,15);
  DR_After_Matching = fs->make<TH1F>(("DR_After_Matching"+prefix).c_str() ,"DR_After_Matching",500,0,8);
  h_Den_JetPt = fs->make<TH1F>(("h_Den_JetPt"+prefix).c_str() ,"h_Den_JetPt",100,0,700);
  h_DMF_JetPt = fs->make<TH1F>(("h_DMF_JetPt"+prefix).c_str() ,"h_DMF_JetPt",100,0,700);
  
  h_gen_pt_pure  = fs->make<TH1F>(("h_gen_pt_pure"+prefix).c_str() ,"h_gen_pt_pure",200,0,1400);
  h_gen_eta_pure = fs->make<TH1F>(("h_gen_eta_pure"+prefix).c_str() ,"h_gen_eta_pure",100,-5,5);
  h_gen_phi_pure = fs->make<TH1F>(("h_gen_phi_pure"+prefix).c_str() ,"h_gen_phi_pure",100,-5,5);
  
  h_pfjet_pt_pure  = fs->make<TH1F>(("h_pfjet_pt_pure"+prefix).c_str() ,"h_pfjet_pt_pure",200,0,1400);
  h_pfjet_eta_pure = fs->make<TH1F>(("h_pfjet_eta_pure"+prefix).c_str() ,"h_pfjet_eta_pure",100,-5,5);
  h_pfjet_phi_pure = fs->make<TH1F>(("h_pfjet_phi_pure"+prefix).c_str() ,"h_pfjet_phi_pure",100,-5,5);

  h_VLooseChar_GenJetPt  = fs->make<TH1F>(("h_VLooseChar_GenJetPt"+prefix).c_str() ,"h_VLooseChar_GenJetPt",100,0,700);
  h_VLooseChar_GenJetEta  = fs->make<TH1F>(("h_VLooseChar_GenJetEta"+prefix).c_str() ,"h_VLooseChar_GenJetEta",100,-4,4);
  h_VLooseChar_GenJetPhi  = fs->make<TH1F>(("h_VLooseChar_GenJetPhi"+prefix).c_str() ,"h_VLooseChar_GenJetPhi",100,-4,4);
  h_VLooseChar_DR = fs->make<TH1F>(("h_VLooseChar_DR"+prefix).c_str() ,"h_VLooseChar_DR",500,0,8);


  h_LooseChar_GenJetPt  = fs->make<TH1F>(("h_LooseChar_GenJetPt"+prefix).c_str() ,"h_LooseChar_GenJetPt",100,0,700);
  h_LooseChar_GenJetEta  = fs->make<TH1F>(("h_LooseChar_GenJetEta"+prefix).c_str() ,"h_LooseChar_GenJetEta",100,-4,4);
  h_LooseChar_GenJetPhi  = fs->make<TH1F>(("h_LooseChar_GenJetPhi"+prefix).c_str() ,"h_LooseChar_GenJetPhi",100,-4,4);
  h_LooseChar_DR = fs->make<TH1F>(("h_LooseChar_DR"+prefix).c_str() ,"h_LooseChar_DR",500,0,8);


  h_MediumChar_GenJetPt  = fs->make<TH1F>(("h_MediumChar_GenJetPt"+prefix).c_str() ,"h_MediumChar_GenJetPt",100,0,700);
  h_MediumChar_GenJetEta  = fs->make<TH1F>(("h_MediumChar_GenJetEta"+prefix).c_str() ,"h_MediumChar_GenJetEta",100,-4,4);
  h_MediumChar_GenJetPhi  = fs->make<TH1F>(("h_MediumChar_GenJetPhi"+prefix).c_str() ,"h_MediumChar_GenJetPhi",100,-4,4);
  h_MediumChar_DR = fs->make<TH1F>(("h_MediumChar_DR"+prefix).c_str() ,"h_MediumChar_DR",500,0,8);


  h_TightChar_GenJetPt  = fs->make<TH1F>(("h_TightChar_GenJetPt"+prefix).c_str() ,"h_TightChar_GenJetPt",100,0,700);
  h_TightChar_GenJetEta  = fs->make<TH1F>(("h_TightChar_GenJetEta"+prefix).c_str() ,"h_TightChar_GenJetEta",100,-4,4);
  h_TightChar_GenJetPhi  = fs->make<TH1F>(("h_TightChar_GenJetPhi"+prefix).c_str() ,"h_TightChar_GenJetPhi",100,-4,4);
  h_TightChar_DR = fs->make<TH1F>(("h_TightChar_DR"+prefix).c_str() ,"h_TightChar_DR",500,0,8);



  h_Loose3_GenJetPt  = fs->make<TH1F>(("h_Loose3_GenJetPt"+prefix).c_str() ,"h_Loose3_GenJetPt",100,0,700);
  h_Loose3_GenJetEta  = fs->make<TH1F>(("h_Loose3_GenJetEta"+prefix).c_str() ,"h_Loose3_GenJetEta",100,-4,4);
  h_Loose3_GenJetPhi  = fs->make<TH1F>(("h_Loose3_GenJetPhi"+prefix).c_str() ,"h_Loose3_GenJetPhi",100,-4,4);
  h_Loose3_DR = fs->make<TH1F>(("h_Loose3_DR"+prefix).c_str() ,"h_Loose3_DR",500,0,8);


  h_Medium3_GenJetPt  = fs->make<TH1F>(("h_Medium3_GenJetPt"+prefix).c_str() ,"h_Medium3_GenJetPt",100,0,700);
  h_Medium3_GenJetEta  = fs->make<TH1F>(("h_Medium3_GenJetEta"+prefix).c_str() ,"h_Medium3_GenJetEta",100,-4,4);
  h_Medium3_GenJetPhi  = fs->make<TH1F>(("h_Medium3_GenJetPhi"+prefix).c_str() ,"h_Medium3_GenJetPhi",100,-4,4);
  h_Medium3_DR = fs->make<TH1F>(("h_Medium3_DR"+prefix).c_str() ,"h_Medium3_DR",500,0,8);


  h_Tight3_GenJetPt  = fs->make<TH1F>(("h_Tight3_GenJetPt"+prefix).c_str() ,"h_Tight3_GenJetPt",100,0,700);
  h_Tight3_GenJetEta  = fs->make<TH1F>(("h_Tight3_GenJetEta"+prefix).c_str() ,"h_Tight3_GenJetEta",100,-4,4);
  h_Tight3_GenJetPhi  = fs->make<TH1F>(("h_Tight3_GenJetPhi"+prefix).c_str() ,"h_Tight3_GenJetPhi",100,-4,4);
  h_Tight3_DR = fs->make<TH1F>(("h_Tight3_DR"+prefix).c_str() ,"h_Tight3_DR",500,0,8);

  //
  h_Iso2_GenJetPt  = fs->make<TH1F>(("h_Iso2_GenJetPt"+prefix).c_str() ,"h_Iso2_GenJetPt",100,0,700);
  h_Iso2_GenJetEta  = fs->make<TH1F>(("h_Iso2_GenJetEta"+prefix).c_str() ,"h_Iso2_GenJetEta",100,-4,4);
  h_Iso2_GenJetPhi  = fs->make<TH1F>(("h_Iso2_GenJetPhi"+prefix).c_str() ,"h_Iso2_GenJetPhi",100,-4,4);
  h_Iso2_DR = fs->make<TH1F>(("h_Iso2_DR"+prefix).c_str() ,"h_Iso2_DR",500,0,8);

  h_Iso4_GenJetPt  = fs->make<TH1F>(("h_Iso4_GenJetPt"+prefix).c_str() ,"h_Iso4_GenJetPt",100,0,700);
  h_Iso4_GenJetEta  = fs->make<TH1F>(("h_Iso4_GenJetEta"+prefix).c_str() ,"h_Iso4_GenJetEta",100,-4,4);
  h_Iso4_GenJetPhi  = fs->make<TH1F>(("h_Iso4_GenJetPhi"+prefix).c_str() ,"h_Iso4_GenJetPhi",100,-4,4);
  h_Iso4_DR = fs->make<TH1F>(("h_Iso4_DR"+prefix).c_str() ,"h_Iso4_DR",500,0,8);


  h_Iso1_GenJetPt  = fs->make<TH1F>(("h_Iso1_GenJetPt"+prefix).c_str() ,"h_Iso1_GenJetPt",100,0,700);
  h_Iso1_GenJetEta  = fs->make<TH1F>(("h_Iso1_GenJetEta"+prefix).c_str() ,"h_Iso1_GenJetEta",100,-4,4);
  h_Iso1_GenJetPhi  = fs->make<TH1F>(("h_Iso1_GenJetPhi"+prefix).c_str() ,"h_Iso1_GenJetPhi",100,-4,4);
  h_Iso1_DR = fs->make<TH1F>(("h_Iso1_DR"+prefix).c_str() ,"h_Iso1_DR",500,0,8);


  h_MIsoPtSum_GenJetPt  = fs->make<TH1F>(("h_MIsoPtSum_GenJetPt"+prefix).c_str() ,"h_MIsoPtSum_GenJetPt",100,0,700);
  h_MIsoPtSum_GenJetEta  = fs->make<TH1F>(("h_MIsoPtSum_GenJetEta"+prefix).c_str() ,"h_MIsoPtSum_GenJetEta",100,-4,4);
  h_MIsoPtSum_GenJetPhi  = fs->make<TH1F>(("h_MIsoPtSum_GenJetPhi"+prefix).c_str() ,"h_MIsoPtSum_GenJetPhi",100,-4,4);
  h_MIsoPtSum_DR = fs->make<TH1F>(("h_MIsoPtSum_DR"+prefix).c_str() ,"h_MIsoPtSum_DR",500,0,8);


  h_TIsoPtSum_GenJetPt  = fs->make<TH1F>(("h_TIsoPtSum_GenJetPt"+prefix).c_str() ,"h_TIsoPtSum_GenJetPt",100,0,700);
  h_TIsoPtSum_GenJetEta  = fs->make<TH1F>(("h_TIsoPtSum_GenJetEta"+prefix).c_str() ,"h_TIsoPtSum_GenJetEta",100,-4,4);
  h_TIsoPtSum_GenJetPhi  = fs->make<TH1F>(("h_TIsoPtSum_GenJetPhi"+prefix).c_str() ,"h_TIsoPtSum_GenJetPhi",100,-4,4);
  h_TIsoPtSum_DR = fs->make<TH1F>(("h_TIsoPtSum_DR"+prefix).c_str() ,"h_TIsoPtSum_DR",500,0,8);


  h_LIsoPtSum_GenJetPt  = fs->make<TH1F>(("h_LIsoPtSum_GenJetPt"+prefix).c_str() ,"h_LIsoPtSum_GenJetPt",100,0,700);
  h_LIsoPtSum_GenJetEta  = fs->make<TH1F>(("h_LIsoPtSum_GenJetEta"+prefix).c_str() ,"h_LIsoPtSum_GenJetEta",100,-4,4);
  h_LIsoPtSum_GenJetPhi  = fs->make<TH1F>(("h_LIsoPtSum_GenJetPhi"+prefix).c_str() ,"h_LIsoPtSum_GenJetPhi",100,-4,4);
  h_LIsoPtSum_DR = fs->make<TH1F>(("h_LIsoPtSum_DR"+prefix).c_str() ,"h_LIsoPtSum_DR",500,0,8);



  //

  h_DMF_GenJetPt  = fs->make<TH1F>(("h_DMF_GenJetPt"+prefix).c_str() ,"h_DMF_GenJetPt",100,0,700);
  h_DMF_GenJetEta  = fs->make<TH1F>(("h_DMF_GenJetEta"+prefix).c_str() ,"h_DMF_GenJetEta",100,-4,4);
  h_DMF_GenJetPhi  = fs->make<TH1F>(("h_DMF_GenJetPhi"+prefix).c_str() ,"h_DMF_GenJetPhi",100,-4,4);
  h_DMF_DR = fs->make<TH1F>(("h_DMF_DR"+prefix).c_str() ,"h_DMF_DR",500,0,8);


  h_Den_GenJetPt  = fs->make<TH1F>(("h_Den_GenJetPt"+prefix).c_str() ,"h_Den_GenJetPt",100,0,700);
  h_Den_GenJetEta  = fs->make<TH1F>(("h_Den_GenJetEta"+prefix).c_str() ,"h_Den_GenJetEta",100,-4,4);
  h_Den_GenJetPhi  = fs->make<TH1F>(("h_Den_GenJetPhi"+prefix).c_str() ,"h_Den_GenJetPhi",100,-4,4);
  h_Den_DR = fs->make<TH1F>(("h_Den_DR"+prefix).c_str() ,"h_Den_DR",500,0,8);


  //


  
  h_Loose3_JetPt = fs->make<TH1F>(("h_Loose3_JetPt"+prefix).c_str() ,"h_Loose3_JetPt",100,0,700);
  h_Medium3_JetPt = fs->make<TH1F>(("h_Medium3_JetPt"+prefix).c_str() ,"h_Medium3_JetPt",100,0,700);
  h_Tight3_JetPt = fs->make<TH1F>(("h_Tight3_JetPt"+prefix).c_str() ,"h_Tight3_JetPt",100,0,700);
  h_VLooseChar_JetPt = fs->make<TH1F>(("h_VLooseChar_JetPt"+prefix).c_str() ,"h_VLooseChar_JetPt",100,0,700);
  h_LooseChar_JetPt = fs->make<TH1F>(("h_LooseChar_JetPt"+prefix).c_str() ,"h_LooseChar_JetPt",100,0,700);
  h_MediumChar_JetPt = fs->make<TH1F>(("h_MediumChar_JetPt"+prefix).c_str() ,"h_MediumChar_JetPt",100,0,700);
  h_TightChar_JetPt = fs->make<TH1F>(("h_TightChar_JetPt"+prefix).c_str() ,"h_TightChar_JetPt",100,0,700);

  h_Den_TauPt = fs->make<TH1F>(("h_Den_TauPt"+prefix).c_str() ,"h_Den_TauPt",100,0,700);
  h_DMF_TauPt = fs->make<TH1F>(("h_DMF_TauPt"+prefix).c_str() ,"h_DMF_TauPt",100,0,700);

  h_Loose3_TauPt = fs->make<TH1F>(("h_Loose3_TauPt"+prefix).c_str() ,"h_Loose3_TauPt",100,0,700);
  h_Medium3_TauPt = fs->make<TH1F>(("h_Medium3_TauPt"+prefix).c_str() ,"h_Medium3_TauPt",100,0,700);
  h_Tight3_TauPt = fs->make<TH1F>(("h_Tight3_TauPt"+prefix).c_str() ,"h_Tight3_TauPt",100,0,700);
  h_VLooseChar_TauPt = fs->make<TH1F>(("h_VLooseChar_TauPt"+prefix).c_str() ,"h_VLooseChar_TauPt",100,0,700);
  h_LooseChar_TauPt = fs->make<TH1F>(("h_LooseChar_TauPt"+prefix).c_str() ,"h_LooseChar_TauPt",100,0,700);
  h_MediumChar_TauPt = fs->make<TH1F>(("h_MediumChar_TauPt"+prefix).c_str() ,"h_MediumChar_TauPt",100,0,700);
  h_TightChar_TauPt = fs->make<TH1F>(("h_TightChar_TauPt"+prefix).c_str() ,"h_TightChar_TauPt",100,0,700);


  h_LIsoPtSum_JetPt = fs->make<TH1F>(("h_LIsoPtSum_JetPt"+prefix).c_str() ,"h_LIsoPtSum_JetPt",100,0,700); 
  h_LIsoPtSum_JetEta = fs->make<TH1F>(("h_LIsoPtSum_JetEta"+prefix).c_str() ,"h_LIsoPtSum_JetEta",100,-4,4);
  h_LIsoPtSum_JetPhi = fs->make<TH1F>(("h_LIsoPtSum_JetPhi"+prefix).c_str() ,"h_LIsoPtSum_JetPhi",100,-4,4);

  h_TIsoPtSum_JetPt = fs->make<TH1F>(("h_TIsoPtSum_JetPt"+prefix).c_str() ,"h_TIsoPtSum_JetPt",100,0,700); 
  h_TIsoPtSum_JetEta = fs->make<TH1F>(("h_TIsoPtSum_JetEta"+prefix).c_str() ,"h_TIsoPtSum_JetEta",100,-4,4);
  h_TIsoPtSum_JetPhi = fs->make<TH1F>(("h_TIsoPtSum_JetPhi"+prefix).c_str() ,"h_TIsoPtSum_JetPhi",100,-4,4);

  h_MIsoPtSum_JetPt = fs->make<TH1F>(("h_MIsoPtSum_JetPt"+prefix).c_str() ,"h_MIsoPtSum_JetPt",100,0,700); 
  h_MIsoPtSum_JetEta = fs->make<TH1F>(("h_MIsoPtSum_JetEta"+prefix).c_str() ,"h_MIsoPtSum_JetEta",100,-4,4);
  h_MIsoPtSum_JetPhi = fs->make<TH1F>(("h_MIsoPtSum_JetPhi"+prefix).c_str() ,"h_MIsoPtSum_JetPhi",100,-4,4);

  h_LIsoPtSum_TauPt = fs->make<TH1F>(("h_LIsoPtSum_TauPt"+prefix).c_str() ,"h_LIsoPtSum_TauPt",100,0,700); 
  h_LIsoPtSum_TauEta = fs->make<TH1F>(("h_LIsoPtSum_TauEta"+prefix).c_str() ,"h_LIsoPtSum_TauEta",100,-4,4);
  h_LIsoPtSum_TauPhi = fs->make<TH1F>(("h_LIsoPtSum_TauPhi"+prefix).c_str() ,"h_LIsoPtSum_TauPhi",100,-4,4);

  h_TIsoPtSum_TauPt = fs->make<TH1F>(("h_TIsoPtSum_TauPt"+prefix).c_str() ,"h_TIsoPtSum_TauPt",100,0,700); 
  h_TIsoPtSum_TauEta = fs->make<TH1F>(("h_TIsoPtSum_TauEta"+prefix).c_str() ,"h_TIsoPtSum_TauEta",100,-4,4);
  h_TIsoPtSum_TauPhi = fs->make<TH1F>(("h_TIsoPtSum_TauPhi"+prefix).c_str() ,"h_TIsoPtSum_TauPhi",100,-4,4);

  h_MIsoPtSum_TauPt = fs->make<TH1F>(("h_MIsoPtSum_TauPt"+prefix).c_str() ,"h_MIsoPtSum_TauPt",100,0,700); 
  h_MIsoPtSum_TauEta = fs->make<TH1F>(("h_MIsoPtSum_TauEta"+prefix).c_str() ,"h_MIsoPtSum_TauEta",100,-4,4);
  h_MIsoPtSum_TauPhi = fs->make<TH1F>(("h_MIsoPtSum_TauPhi"+prefix).c_str() ,"h_MIsoPtSum_TauPhi",100,-4,4);


  h_Iso2_TauPt = fs->make<TH1F>(("h_Iso2_TauPt"+prefix).c_str() ,"h_Iso2_TauPt",100,0,700);
  h_Iso4_TauPt = fs->make<TH1F>(("h_Iso4_TauPt"+prefix).c_str() ,"h_Iso4_TauPt",100,0,700);
  h_Iso1_TauPt = fs->make<TH1F>(("h_Iso1_TauPt"+prefix).c_str() ,"h_Iso1_TauPt",100,0,700);


  h_Iso2_JetPt = fs->make<TH1F>(("h_Iso2_JetPt"+prefix).c_str() ,"h_Iso2_JetPt",100,0,700);
  h_Iso4_JetPt = fs->make<TH1F>(("h_Iso4_JetPt"+prefix).c_str() ,"h_Iso4_JetPt",100,0,700);
  h_Iso1_JetPt = fs->make<TH1F>(("h_Iso1_JetPt"+prefix).c_str() ,"h_Iso1_JetPt",100,0,700);


  h_Den_JetEta = fs->make<TH1F>(("h_Den_JetEta"+prefix).c_str() ,"h_Den_JetEta",100,-4,4);
  h_DMF_JetEta = fs->make<TH1F>(("h_DMF_JetEta"+prefix).c_str() ,"h_DMF_JetEta",100,-4,4);

  h_Loose3_JetEta = fs->make<TH1F>(("h_Loose3_JetEta"+prefix).c_str() ,"h_Loose3_JetEta",100,-4,4);
  h_Medium3_JetEta = fs->make<TH1F>(("h_Medium3_JetEta"+prefix).c_str() ,"h_Medium3_JetEta",100,-4,4);
  h_Tight3_JetEta = fs->make<TH1F>(("h_Tight3_JetEta"+prefix).c_str() ,"h_Tight3_JetEta",100,-4,4);
  h_VLooseChar_JetEta = fs->make<TH1F>(("h_VLooseChar_JetEta"+prefix).c_str() ,"h_VLooseChar_JetEta",100,-4,4);
  h_LooseChar_JetEta = fs->make<TH1F>(("h_LooseChar_JetEta"+prefix).c_str() ,"h_LooseChar_JetEta",100,-4,4);
  h_MediumChar_JetEta = fs->make<TH1F>(("h_MediumChar_JetEta"+prefix).c_str() ,"h_MediumChar_JetEta",100,-4,4);
  h_TightChar_JetEta = fs->make<TH1F>(("h_TightChar_JetEta"+prefix).c_str() ,"h_TightChar_JetEta",100,-4,4)
;
  h_Iso1_JetPhi = fs->make<TH1F>(("h_Iso1_JetPhi"+prefix).c_str() ,"h_Iso1_JetPhi",100,-4,4);
  h_Iso4_JetPhi = fs->make<TH1F>(("h_Iso4_JetPhi"+prefix).c_str() ,"h_Iso4_JetPhi",100,-4,4);
  h_Iso2_JetPhi = fs->make<TH1F>(("h_Iso2_JetPhi"+prefix).c_str() ,"h_Iso2_JetPhi",100,-4,4);

  h_Iso1_JetEta = fs->make<TH1F>(("h_Iso1_JetEta"+prefix).c_str() ,"h_Iso1_JetEta",100,-4,4);
  h_Iso4_JetEta = fs->make<TH1F>(("h_Iso4_JetEta"+prefix).c_str() ,"h_Iso4_JetEta",100,-4,4);
  h_Iso2_JetEta = fs->make<TH1F>(("h_Iso2_JetEta"+prefix).c_str() ,"h_Iso2_JetEta",100,-4,4);


  h_Iso1_TauPhi = fs->make<TH1F>(("h_Iso1_TauPhi"+prefix).c_str() ,"h_Iso1_TauPhi",100,-4,4);
  h_Iso4_TauPhi = fs->make<TH1F>(("h_Iso4_TauPhi"+prefix).c_str() ,"h_Iso4_TauPhi",100,-4,4);
  h_Iso2_TauPhi = fs->make<TH1F>(("h_Iso2_TauPhi"+prefix).c_str() ,"h_Iso2_TauPhi",100,-4,4);

  h_Iso1_TauEta = fs->make<TH1F>(("h_Iso1_TauEta"+prefix).c_str() ,"h_Iso1_TauEta",100,-4,4);
  h_Iso4_TauEta = fs->make<TH1F>(("h_Iso4_TauEta"+prefix).c_str() ,"h_Iso4_TauEta",100,-4,4);
  h_Iso2_TauEta = fs->make<TH1F>(("h_Iso2_TauEta"+prefix).c_str() ,"h_Iso2_TauEta",100,-4,4);


  h_Den_TauEta = fs->make<TH1F>(("h_Den_TauEta"+prefix).c_str() ,"h_Den_TauEta",100,-4,4);
   h_DMF_TauEta = fs->make<TH1F>(("h_DMF_TauEta"+prefix).c_str() ,"h_DMF_TauEta",100,-4,4);
  h_Loose3_TauEta = fs->make<TH1F>(("h_Loose3_TauEta"+prefix).c_str() ,"h_Loose3_TauEta",100,-4,4);
  h_Medium3_TauEta = fs->make<TH1F>(("h_Medium3_TauEta"+prefix).c_str() ,"h_Medium3_TauEta",100,-4,4);
  h_Tight3_TauEta = fs->make<TH1F>(("h_Tight3_TauEta"+prefix).c_str() ,"h_Tight3_TauEta",100,-4,4);
  h_VLooseChar_TauEta = fs->make<TH1F>(("h_VLooseChar_TauEta"+prefix).c_str() ,"h_VLooseChar_TauEta",100,-4,4);
  h_LooseChar_TauEta = fs->make<TH1F>(("h_LooseChar_TauEta"+prefix).c_str() ,"h_LooseChar_TauEta",100,-4,4);
  h_MediumChar_TauEta = fs->make<TH1F>(("h_MediumChar_TauEta"+prefix).c_str() ,"h_MediumChar_TauEta",100,-4,4);
  h_TightChar_TauEta = fs->make<TH1F>(("h_TightChar_TauEta"+prefix).c_str() ,"h_TightChar_TauEta",100,-4,4);


  h_Den_JetPhi = fs->make<TH1F>(("h_Den_JetPhi"+prefix).c_str() ,"h_Den_JetPhi",100,-4,4);
  h_DMF_JetPhi = fs->make<TH1F>(("h_DMF_JetPhi"+prefix).c_str() ,"h_DMF_JetPhi",100,-4,4);
  h_Loose3_JetPhi = fs->make<TH1F>(("h_Loose3_JetPhi"+prefix).c_str() ,"h_Loose3_JetPhi",100,-4,4);
  h_Medium3_JetPhi = fs->make<TH1F>(("h_Medium3_JetPhi"+prefix).c_str() ,"h_Medium3_JetPhi",100,-4,4);
  h_Tight3_JetPhi = fs->make<TH1F>(("h_Tight3_JetPhi"+prefix).c_str() ,"h_Tight3_JetPhi",100,-4,4);
  h_VLooseChar_JetPhi = fs->make<TH1F>(("h_VLooseChar_JetPhi"+prefix).c_str() ,"h_VLooseChar_JetPhi",100,-4,4);
  h_LooseChar_JetPhi = fs->make<TH1F>(("h_LooseChar_JetPhi"+prefix).c_str() ,"h_LooseChar_JetPhi",100,-4,4);
  h_MediumChar_JetPhi = fs->make<TH1F>(("h_MediumChar_JetPhi"+prefix).c_str() ,"h_MediumChar_JetPhi",100,-4,4);
  h_TightChar_JetPhi = fs->make<TH1F>(("h_TightChar_JetPhi"+prefix).c_str() ,"h_TightChar_JetPhi",100,-4,4);


  h_Den_TauPhi = fs->make<TH1F>(("h_Den_TauPhi"+prefix).c_str() ,"h_Den_TauPhi",100,-4,4);
  h_DMF_TauPhi = fs->make<TH1F>(("h_DMF_TauPhi"+prefix).c_str() ,"h_DMF_TauPhi",100,-4,4);
  h_Loose3_TauPhi = fs->make<TH1F>(("h_Loose3_TauPhi"+prefix).c_str() ,"h_Loose3_TauPhi",100,-4,4);
  h_Medium3_TauPhi = fs->make<TH1F>(("h_Medium3_TauPhi"+prefix).c_str() ,"h_Medium3_TauPhi",100,-4,4);
  h_Tight3_TauPhi = fs->make<TH1F>(("h_Tight3_TauPhi"+prefix).c_str() ,"h_Tight3_TauPhi",100,-4,4);
  h_VLooseChar_TauPhi = fs->make<TH1F>(("h_VLooseChar_TauPhi"+prefix).c_str() ,"h_VLooseChar_TauPhi",100,-4,4);
  h_LooseChar_TauPhi = fs->make<TH1F>(("h_LooseChar_TauPhi"+prefix).c_str() ,"h_LooseChar_TauPhi",100,-4,4);
  h_MediumChar_TauPhi = fs->make<TH1F>(("h_MediumChar_TauPhi"+prefix).c_str() ,"h_MediumChar_TauPhi",100,-4,4);
  h_TightChar_TauPhi = fs->make<TH1F>(("h_TightChar_TauPhi"+prefix).c_str() ,"h_TightChar_TauPhi",100,-4,4);



  h_Den_JetToTauPt = fs->make<TH1F>(("h_Den_JetToTauPt"+prefix).c_str() ,"h_Den_JetToTauPt",100,-2,2);
  h_DMF_JetToTauPt = fs->make<TH1F>(("h_DMF_JetToTauPt"+prefix).c_str() ,"h_DMF_JetToTauPt",100,-2,2); 
  h_Loose3_JetToTauPt = fs->make<TH1F>(("h_Loose3_JetToTauPt"+prefix).c_str() ,"h_Loose3_JetToTauPt",100,-2,2);
  h_Medium3_JetToTauPt = fs->make<TH1F>(("h_Medium3_JetToTauPt"+prefix).c_str() ,"h_Medium3_JetToTauPt",100,-2,2);
  h_Tight3_JetToTauPt = fs->make<TH1F>(("h_Tight3_JetToTauPt"+prefix).c_str() ,"h_Tight3_JetToTauPt",100,-2,2);
  h_VLooseChar_JetToTauPt = fs->make<TH1F>(("h_VLooseChar_JetToTauPt"+prefix).c_str() ,"h_VLooseChar_JetToTauPt",100,-2,2);
  h_LooseChar_JetToTauPt = fs->make<TH1F>(("h_LooseChar_JetToTauPt"+prefix).c_str() ,"h_LooseChar_JetToTauPt",100,-2,2);
  h_MediumChar_JetToTauPt = fs->make<TH1F>(("h_MediumChar_JetToTauPt"+prefix).c_str() ,"h_MediumChar_JetToTauPt",100,-2,2);
  h_TightChar_JetToTauPt = fs->make<TH1F>(("h_TightChar_JetToTauPt"+prefix).c_str() ,"h_TightChar_JetToTauPt",100,-2,2);

  h_Den_NVtx  = fs->make<TH1F>(("h_Den_NVtx"+prefix).c_str() ,"h_Den_NVtx",400,0,400);
  h_Den_NGood  = fs->make<TH1F>(("h_Den_NGood"+prefix).c_str() ,"h_Den_NGood",400,0,400);
  h_Den_NBest  = fs->make<TH1F>(("h_Den_NBest"+prefix).c_str() ,"h_Den_NBest",400,0,400);

  h_Loose3_NVtx  = fs->make<TH1F>(("h_Loose3_NVtx"+prefix).c_str() ,"h_Loose3_NVtx",400,0,400);
  h_Loose3_NGood  = fs->make<TH1F>(("h_Loose3_NGood"+prefix).c_str() ,"h_Loose3_NGood",400,0,400);
  h_Loose3_NBest  = fs->make<TH1F>(("h_Loose3_NBest"+prefix).c_str() ,"h_Loose3_NBest",400,0,400);

  h_DMF_NVtx  = fs->make<TH1F>(("h_DMF_NVtx"+prefix).c_str() ,"h_DMF_NVtx",400,0,400);
  h_DMF_NGood  = fs->make<TH1F>(("h_DMF_NGood"+prefix).c_str() ,"h_DMF_NGood",400,0,400);
  h_DMF_NBest  = fs->make<TH1F>(("h_DMF_NBest"+prefix).c_str() ,"h_DMF_NBest",400,0,400);

  h_Medium3_NVtx  = fs->make<TH1F>(("h_Medium3_NVtx"+prefix).c_str() ,"h_Medium3_NVtx",400,0,400);
  h_Medium3_NGood  = fs->make<TH1F>(("h_Medium3_NGood"+prefix).c_str() ,"h_Medium3_NGood",400,0,400);
  h_Medium3_NBest  = fs->make<TH1F>(("h_Medium3_NBest"+prefix).c_str() ,"h_Medium3_NBest",400,0,400);

  h_Tight3_NVtx  = fs->make<TH1F>(("h_Tight3_NVtx"+prefix).c_str() ,"h_Tight3_NVtx",400,0,400);
  h_Tight3_NGood  = fs->make<TH1F>(("h_Tight3_NGood"+prefix).c_str() ,"h_Tight3_NGood",400,0,400);
  h_Tight3_NBest  = fs->make<TH1F>(("h_Tight3_NBest"+prefix).c_str() ,"h_Tight3_NBest",400,0,400);

  h_VLooseChar_NVtx  = fs->make<TH1F>(("h_VLooseChar_NVtx"+prefix).c_str() ,"h_VLooseChar_NVtx",400,0,400);
  h_VLooseChar_NGood  = fs->make<TH1F>(("h_VLooseChar_NGood"+prefix).c_str() ,"h_VLooseChar_NGood",400,0,400);
  h_VLooseChar_NBest  = fs->make<TH1F>(("h_VLooseChar_NBest"+prefix).c_str() ,"h_VLooseChar_NBest",400,0,400);


  h_LooseChar_NVtx  = fs->make<TH1F>(("h_LooseChar_NVtx"+prefix).c_str() ,"h_LooseChar_NVtx",400,0,400);
  h_LooseChar_NGood  = fs->make<TH1F>(("h_LooseChar_NGood"+prefix).c_str() ,"h_LooseChar_NGood",400,0,400);
  h_LooseChar_NBest  = fs->make<TH1F>(("h_LooseChar_NBest"+prefix).c_str() ,"h_LooseChar_NBest",400,0,400);

  h_MediumChar_NVtx  = fs->make<TH1F>(("h_MediumChar_NVtx"+prefix).c_str() ,"h_MediumChar_NVtx",400,0,400);
  h_MediumChar_NGood  = fs->make<TH1F>(("h_MediumChar_NGood"+prefix).c_str() ,"h_MediumChar_NGood",400,0,400);
  h_MediumChar_NBest  = fs->make<TH1F>(("h_MediumChar_NBest"+prefix).c_str() ,"h_MediumChar_NBest",400,0,400);

  h_TightChar_NVtx  = fs->make<TH1F>(("h_TightChar_NVtx"+prefix).c_str() ,"h_TightChar_NVtx",400,0,400);
  h_TightChar_NGood  = fs->make<TH1F>(("h_TightChar_NGood"+prefix).c_str() ,"h_TightChar_NGood",400,0,400);
  h_TightChar_NBest  = fs->make<TH1F>(("h_TightChar_NBest"+prefix).c_str() ,"h_TightChar_NBest",400,0,400);

  h_Iso1_NVtx  = fs->make<TH1F>(("h_Iso1_NVtx"+prefix).c_str() ,"h_Iso1_NVtx",400,0,400);
  h_Iso1_NGood  = fs->make<TH1F>(("h_Iso1_NGood"+prefix).c_str() ,"h_Iso1_NGood",400,0,400);
  h_Iso1_NBest  = fs->make<TH1F>(("h_Iso1_NBest"+prefix).c_str() ,"h_Iso1_NBest",400,0,400);


  h_Iso4_NVtx  = fs->make<TH1F>(("h_Iso4_NVtx"+prefix).c_str() ,"h_Iso4_NVtx",400,0,400);
  h_Iso4_NGood  = fs->make<TH1F>(("h_Iso4_NGood"+prefix).c_str() ,"h_Iso4_NGood",400,0,400);
  h_Iso4_NBest  = fs->make<TH1F>(("h_Iso4_NBest"+prefix).c_str() ,"h_Iso4_NBest",400,0,400);


  h_TIsoPtSum_NVtx  = fs->make<TH1F>(("h_TIsoPtSum_NVtx"+prefix).c_str() ,"h_TIsoPtSum_NVtx",400,0,400);
  h_TIsoPtSum_NGood  = fs->make<TH1F>(("h_TIsoPtSum_NGood"+prefix).c_str() ,"h_TIsoPtSum_NGood",400,0,400);
  h_TIsoPtSum_NBest  = fs->make<TH1F>(("h_TIsoPtSum_NBest"+prefix).c_str() ,"h_TIsoPtSum_NBest",400,0,400);

  h_LIsoPtSum_NVtx  = fs->make<TH1F>(("h_LIsoPtSum_NVtx"+prefix).c_str() ,"h_LIsoPtSum_NVtx",400,0,400);
  h_LIsoPtSum_NGood  = fs->make<TH1F>(("h_LIsoPtSum_NGood"+prefix).c_str() ,"h_LIsoPtSum_NGood",400,0,400);
  h_LIsoPtSum_NBest  = fs->make<TH1F>(("h_LIsoPtSum_NBest"+prefix).c_str() ,"h_LIsoPtSum_NBest",400,0,400);

  h_MIsoPtSum_NVtx  = fs->make<TH1F>(("h_MIsoPtSum_NVtx"+prefix).c_str() ,"h_MIsoPtSum_NVtx",400,0,400);
  h_MIsoPtSum_NGood  = fs->make<TH1F>(("h_MIsoPtSum_NGood"+prefix).c_str() ,"h_MIsoPtSum_NGood",400,0,400);
  h_MIsoPtSum_NBest  = fs->make<TH1F>(("h_MIsoPtSum_NBest"+prefix).c_str() ,"h_MIsoPtSum_NBest",400,0,400);


  h_Iso2_NVtx  = fs->make<TH1F>(("h_Iso2_NVtx"+prefix).c_str() ,"h_Iso2_NVtx",400,0,400);
  h_Iso2_NGood  = fs->make<TH1F>(("h_Iso2_NGood"+prefix).c_str() ,"h_Iso2_NGood",400,0,400);
  h_Iso2_NBest  = fs->make<TH1F>(("h_Iso2_NBest"+prefix).c_str() ,"h_Iso2_NBest",400,0,400);




  h_Fill_DZ   = fs->make<TH1F>(("h_Fill_DZ"+prefix).c_str() ,"h_Fill_DZ",400,0,10);
  
   h_VLooseChar_Response  = fs->make<TH1F>(("h_VLooseChar_Response"+prefix).c_str() ,"h_VLooseChar_Response",5000,0,50);
   h_LooseChar_Response  = fs->make<TH1F>(("h_LooseChar_Response"+prefix).c_str() ,"h_LooseChar_Response",5000,0,50);
   h_MediumChar_Response  = fs->make<TH1F>(("h_MediumChar_Response"+prefix).c_str() ,"h_MediumChar_Response",5000,0,50);
   h_TightChar_Response  = fs->make<TH1F>(("h_TightChar_Response"+prefix).c_str() ,"h_TightChar_Response",5000,0,50);

   h_Loose3_Response  = fs->make<TH1F>(("h_Loose3_Response"+prefix).c_str() ,"h_Loose3_Response",5000,0,50);
   h_Medium3_Response  = fs->make<TH1F>(("h_Medium3_Response"+prefix).c_str() ,"h_Medium3_Response",5000,0,50);
   h_Tight3_Response  = fs->make<TH1F>(("h_Tight3_Response"+prefix).c_str() ,"h_Tight3_Response",5000,0,50);

   h_Iso2_Response  = fs->make<TH1F>(("h_Iso2_Response"+prefix).c_str() ,"h_Iso2_Response",5000,0,50);
   h_Iso4_Response  = fs->make<TH1F>(("h_Iso4_Response"+prefix).c_str() ,"h_Iso4_Response",5000,0,50);
   h_Iso1_Response  = fs->make<TH1F>(("h_Iso1_Response"+prefix).c_str() ,"h_Iso1_Response",5000,0,50);


   h_Den_Response  = fs->make<TH1F>(("h_Den_Response"+prefix).c_str() ,"h_Den_Response",5000,0,50);
   h_DMF_Response  = fs->make<TH1F>(("h_DMF_Response"+prefix).c_str() ,"h_DMF_Response",5000,0,50);

   h_LIsoPtSum_Response  = fs->make<TH1F>(("h_LIsoPtSum_Response"+prefix).c_str() ,"h_LIsoPtSum_Response",5000,0,50);

    h_MIsoPtSum_Response  = fs->make<TH1F>(("h_MIsoPtSum_Response"+prefix).c_str() ,"h_MIsoPtSum_Response",5000,0,50);

   h_TIsoPtSum_Response  = fs->make<TH1F>(("h_TIsoPtSum_Response"+prefix).c_str() ,"h_TIsoPtSum_Response",5000,0,50);

}


JetTauFakeRateFullSimonEta40::~JetTauFakeRateFullSimonEta40()
{
  
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)
  
}


//
// member functions
//

// ------------ method called for each event  ------------
void JetTauFakeRateFullSimonEta40::Fill(const edm::Event& iEvent,const edm::EventSetup& iSetup) {
  using namespace edm;
  using namespace std;
  using namespace reco;
  using namespace pat;
 
 
  iEvent.getByLabel("genParticles", _genParticles); 
  
  Handle< reco::TrackCollection > track;
  iEvent.getByLabel("generalTracks", track);

  Handle< reco::GenJetCollection > genTauJets , ak5jets;
  iEvent.getByLabel("tauGenJets",genTauJets);
  iEvent.getByLabel("ak5GenJets",ak5jets);
  
  
  edm::Handle<std::vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel(std::string("addPileupInfo"), PupInfo);
  
  edm::Handle<reco::MuonCollection> rmuons;
  iEvent.getByLabel("muons",rmuons);
  
  edm::Handle<reco::VertexCollection> vtx;
  iEvent.getByLabel("offlinePrimaryVertices",vtx);

  //  vector<pat::Muon>                    "patMuons"                  ""           "PATTuple"  
 
  
  
  
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

  // vertices

/*        size_t numVertices = vtx->size();
        for ( size_t idxVertex = 0; idxVertex < numVertices; ++idxVertex ) {
       
        if(idxVertex == 0) {
        const reco::Vertex::Point& recVertexPosition = vtx->at(idxVertex).position();
         PVz = recVertexPosition.z();

         cout<<"PVz"<<PVz<<endl;

         }
        }

*/

  int  nGoodVtx = 0; 
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){ 

      if((vtxIt->isValid()) && !(vtxIt->isFake())) {
     
         nGoodVtx++;
    }
   }

   int  nBestVtx = 0;
   for( reco::VertexCollection::const_iterator vtxIt = vtx->begin(); vtxIt != vtx->end(); ++vtxIt){

      if((vtxIt->isValid()) && !(vtxIt->isFake())) {

       if(vtxIt->ndof() < 4.) continue; 
       if(abs(vtxIt->z()) > 24.) continue;
     // if(passRecoVertexCuts(*vtxIt))
      double vtxdxy = sqrt((vtxIt->x()*vtxIt->x()) + (vtxIt->y()*vtxIt->y()));
      if(vtxdxy >= 2.0) continue; 
     nBestVtx++;
    }
  }

  edm::Handle<reco::PFJetCollection>  pfjets;
  iEvent.getByLabel("ak5PFJets", pfjets);



for (reco::PFJetCollection::const_iterator jet2 = pfjets->begin(); jet2 != pfjets->end(); ++jet2) {
     
      h_pfjet_pt_pure->Fill(jet2->pt());
      h_pfjet_eta_pure->Fill(jet2->eta());
      h_pfjet_phi_pure->Fill(jet2->phi());  
 
}



  

  const JetCorrector* corrector = JetCorrector::getJetCorrector(JetCorrectionService,iSetup);
  
  
  
  for ( unsigned iTau = 0; iTau < _hpsTaucoll->size(); ++iTau ) {
    reco::PFTauRef tauCandidate(_hpsTaucoll, iTau);
    
    bool TauEtaCuts = false;
    bool RecoptCut = false;
    bool DecayModeFinding = false;
    bool IsoDiscL = false;    
    bool IsoDiscM = false;  
    bool IsoDiscT = false;  
    
    bool IsoDiscVLC = false;
    bool IsoDiscLC   = false;
    bool IsoDiscMC = false;
    bool IsoDiscTC = false;
    

      
    if(abs(tauCandidate->eta()) < 4.0) TauEtaCuts = true;
    
    if((tauCandidate->pt()) > 20) RecoptCut = true;
    
    if((*_dmf)[tauCandidate] > 0.5) DecayModeFinding = true; 
    
    
    if((*_iso4)[tauCandidate] > 0.5) IsoDiscL = true;
    if((*_iso5)[tauCandidate] > 0.5) IsoDiscM = true;
    if((*_iso6)[tauCandidate] > 0.5) IsoDiscT = true; 
    
    
    if((*_hpsTau)[tauCandidate] > 0.5) IsoDiscVLC = true; 
    
    if((*_hpsTau1)[tauCandidate] > 0.5) IsoDiscLC = true; 

    if((*_hpsTau2)[tauCandidate] > 0.5) IsoDiscMC = true; 

    if((*_hpsTau3)[tauCandidate] > 0.5) IsoDiscTC = true; 
    
    reco::Candidate::LorentzVector rawJetP4 = tauCandidate->jetRef()->p4();
    reco::Candidate::LorentzVector corrJetP4 = rawJetP4;
    
    double jec = corrector->correction(*(tauCandidate->jetRef()),iEvent,iSetup);
    
    corrJetP4 *= jec;
    
    ////  denominator Tau Pt > 20 and eta < 2.3
    
    //denominator Jet Pt 20 and Eta < 2.3

    if((corrJetP4.pt() > 20) && (fabs(corrJetP4.eta()) < 4.0) ){


  if ( vtx->size() >= 1 ) {
        const reco::Vertex::Point& vertexPos = vtx->at(0).position();


        std::vector<reco::PFCandidatePtr> pfCands = tauCandidate->jetRef()->getPFConstituents();
         double temppt = -999;
        for ( std::vector<reco::PFCandidatePtr>::const_iterator jetConstituent = pfCands.begin(); jetConstituent != pfCands.end(); ++jetConstituent ) {
         if((*jetConstituent)->trackRef().isNonnull()) {
 
           if(((*jetConstituent)->trackRef()->pt()) > temppt ) {  
           temppt = ((*jetConstituent)->trackRef()->pt());
           zof = ((*jetConstituent)->trackRef()->dz(vertexPos));  
      } 
   }
 
  }
}      


    
      if(abs(zof) >= 0.2 ) continue;

// gen part here 

      if((matchToGenJet(corrJetP4.eta(), corrJetP4.phi(),ak5jets ).first)) {
       reco::Candidate::LorentzVector unsmearedMomentum = matchToGenJet(corrJetP4.eta(), corrJetP4.phi(),ak5jets).second;  
        h_Den_GenJetEta->Fill(unsmearedMomentum.eta());
        h_Den_GenJetPhi->Fill(unsmearedMomentum.phi());
        h_Den_GenJetPt->Fill(unsmearedMomentum.pt()); 
        h_Den_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
        h_Den_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());

      h_Fill_DZ->Fill(abs(zof));         
      h_Den_JetPt->Fill(rawJetP4.pt());
      h_Den_JetEta->Fill(rawJetP4.eta());
      h_Den_JetPhi->Fill(rawJetP4.phi());
      h_Den_NVtx->Fill(vtx->size());
      h_Den_NGood->Fill(nGoodVtx);
      h_Den_NBest->Fill(nBestVtx);
      h_Den_TauPt->Fill(corrJetP4.pt());
      h_Den_TauEta->Fill(corrJetP4.eta());
      h_Den_TauPhi->Fill(corrJetP4.phi());
 
if(TauEtaCuts && RecoptCut && DecayModeFinding) {
     
h_DMF_GenJetEta->Fill(unsmearedMomentum.eta());
h_DMF_GenJetPhi->Fill(unsmearedMomentum.phi());
h_DMF_GenJetPt->Fill(unsmearedMomentum.pt()); 
h_DMF_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
h_DMF_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());

 
h_DMF_JetPt->Fill(rawJetP4.pt());
h_DMF_JetEta->Fill(rawJetP4.eta());   
h_DMF_JetPhi->Fill(rawJetP4.phi());
h_DMF_NVtx->Fill(vtx->size());
h_DMF_NGood->Fill(nGoodVtx);
h_DMF_NBest->Fill(nBestVtx);
h_DMF_TauPt->Fill(corrJetP4.pt());
h_DMF_TauEta->Fill(corrJetP4.eta());
h_DMF_TauPhi->Fill(corrJetP4.phi());
  
     
      
      if(IsoDiscL) {

h_Loose3_GenJetEta->Fill(unsmearedMomentum.eta());
h_Loose3_GenJetPhi->Fill(unsmearedMomentum.phi());
h_Loose3_GenJetPt->Fill(unsmearedMomentum.pt()); 
h_Loose3_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
h_Loose3_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());


	h_Loose3_JetPt->Fill(rawJetP4.pt());
	h_Loose3_JetEta->Fill(rawJetP4.eta());
	h_Loose3_JetPhi->Fill(rawJetP4.phi());   
	h_Loose3_NVtx->Fill(vtx->size());
	h_Loose3_NGood->Fill(nGoodVtx);
	h_Loose3_NBest->Fill(nBestVtx);
	
	h_Loose3_TauPt->Fill(corrJetP4.pt());
	h_Loose3_TauEta->Fill(corrJetP4.eta());
	h_Loose3_TauPhi->Fill(corrJetP4.phi());
	
      }


      if(IsoDiscM) {

h_Medium3_GenJetEta->Fill(unsmearedMomentum.eta());
h_Medium3_GenJetPhi->Fill(unsmearedMomentum.phi());
h_Medium3_GenJetPt->Fill(unsmearedMomentum.pt()); 
h_Medium3_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
h_Medium3_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());

	h_Medium3_JetPt->Fill(rawJetP4.pt());
	h_Medium3_JetEta->Fill(rawJetP4.eta());
	h_Medium3_JetPhi->Fill(rawJetP4.phi());  
	h_Medium3_NVtx->Fill(vtx->size());
	h_Medium3_NGood->Fill(nGoodVtx);
	h_Medium3_NBest->Fill(nBestVtx);
	
	h_Medium3_TauPt->Fill(corrJetP4.pt());
	h_Medium3_TauEta->Fill(corrJetP4.eta());
	
	h_Medium3_TauPhi->Fill(corrJetP4.phi());
	
      }
      
      
      if(IsoDiscT) {

	h_Tight3_GenJetEta->Fill(unsmearedMomentum.eta());
	h_Tight3_GenJetPhi->Fill(unsmearedMomentum.phi());
	h_Tight3_GenJetPt->Fill(unsmearedMomentum.pt()); 
	h_Tight3_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
	h_Tight3_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());
	
	h_Tight3_JetPt->Fill(rawJetP4.pt());
	h_Tight3_JetEta->Fill(rawJetP4.eta());
	h_Tight3_JetPhi->Fill(rawJetP4.phi()); 
	h_Tight3_NVtx->Fill(vtx->size());
	h_Tight3_NGood->Fill(nGoodVtx);
	h_Tight3_NBest->Fill(nBestVtx);
	
	h_Tight3_TauPt->Fill(corrJetP4.pt());
	h_Tight3_TauEta->Fill(corrJetP4.eta());
	h_Tight3_TauPhi->Fill(corrJetP4.phi());
	
      }
      
      if(IsoDiscVLC) {

	h_VLooseChar_GenJetEta->Fill(unsmearedMomentum.eta());
	h_VLooseChar_GenJetPhi->Fill(unsmearedMomentum.phi());
	h_VLooseChar_GenJetPt->Fill(unsmearedMomentum.pt()); 
	h_VLooseChar_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
	h_VLooseChar_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());

	h_VLooseChar_JetPt->Fill(rawJetP4.pt());
	h_VLooseChar_JetEta->Fill(rawJetP4.eta());
	h_VLooseChar_JetPhi->Fill(rawJetP4.phi());

	
	h_VLooseChar_NVtx->Fill(vtx->size());
	h_VLooseChar_NGood->Fill(nGoodVtx);
	h_VLooseChar_NBest->Fill(nBestVtx);
	
	h_VLooseChar_TauPt->Fill(corrJetP4.pt());
	h_VLooseChar_TauEta->Fill(corrJetP4.eta());
	h_VLooseChar_TauPhi->Fill(corrJetP4.phi());
	
      }
      
      if(IsoDiscLC) {

	h_LooseChar_GenJetEta->Fill(unsmearedMomentum.eta());
	h_LooseChar_GenJetPhi->Fill(unsmearedMomentum.phi());
	h_LooseChar_GenJetPt->Fill(unsmearedMomentum.pt()); 
	h_LooseChar_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
	h_LooseChar_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());                                                          
	
	
	h_LooseChar_NVtx->Fill(vtx->size());
	h_LooseChar_NGood->Fill(nGoodVtx);
	h_LooseChar_NBest->Fill(nBestVtx);
	
	
	h_LooseChar_JetPt->Fill(rawJetP4.pt());
	h_LooseChar_JetEta->Fill(rawJetP4.eta());
	h_LooseChar_JetPhi->Fill(rawJetP4.phi());
	
        h_LooseChar_TauPt->Fill(corrJetP4.pt());
	h_LooseChar_TauEta->Fill(corrJetP4.eta());
	h_LooseChar_TauPhi->Fill(corrJetP4.phi());

	
      }
      
      if(IsoDiscMC) {

h_MediumChar_GenJetEta->Fill(unsmearedMomentum.eta());
h_MediumChar_GenJetPhi->Fill(unsmearedMomentum.phi());
h_MediumChar_GenJetPt->Fill(unsmearedMomentum.pt()); 
h_MediumChar_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
h_MediumChar_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());                                                          


	h_MediumChar_NVtx->Fill(vtx->size());
	h_MediumChar_NGood->Fill(nGoodVtx);
	h_MediumChar_NBest->Fill(nBestVtx);
	
	
	h_MediumChar_JetPt->Fill(rawJetP4.pt());
	h_MediumChar_JetEta->Fill(rawJetP4.eta());
	h_MediumChar_JetPhi->Fill(rawJetP4.phi());
	
        h_MediumChar_TauPt->Fill(corrJetP4.pt());
	h_MediumChar_TauEta->Fill(corrJetP4.eta());
	h_MediumChar_TauPhi->Fill(corrJetP4.phi());

	    }

	    if(IsoDiscTC) {

h_TightChar_GenJetEta->Fill(unsmearedMomentum.eta());
h_TightChar_GenJetPhi->Fill(unsmearedMomentum.phi());
h_TightChar_GenJetPt->Fill(unsmearedMomentum.pt()); 
h_TightChar_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
h_TightChar_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());  

	      h_TightChar_NVtx->Fill(vtx->size());
	      h_TightChar_NGood->Fill(nGoodVtx);
	      h_TightChar_NBest->Fill(nBestVtx);

	      h_TightChar_JetPt->Fill(rawJetP4.pt());
	      h_TightChar_JetEta->Fill(rawJetP4.eta());
	      h_TightChar_JetPhi->Fill(rawJetP4.phi());

	      h_TightChar_TauPt->Fill(corrJetP4.pt());
	      h_TightChar_TauEta->Fill(corrJetP4.eta());
	      h_TightChar_TauPhi->Fill(corrJetP4.phi());

	      

	    }

            if(((*_rawc)[tauCandidate]) < 4) {

	      h_LIsoPtSum_GenJetEta->Fill(unsmearedMomentum.eta());
	      h_LIsoPtSum_GenJetPhi->Fill(unsmearedMomentum.phi());
	      h_LIsoPtSum_GenJetPt->Fill(unsmearedMomentum.pt());
	      h_LIsoPtSum_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
	      h_LIsoPtSum_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());

              h_LIsoPtSum_NVtx->Fill(vtx->size());
              h_LIsoPtSum_NGood->Fill(nGoodVtx);
              h_LIsoPtSum_NBest->Fill(nBestVtx);

              h_LIsoPtSum_JetPt->Fill(rawJetP4.pt());
              h_LIsoPtSum_JetEta->Fill(rawJetP4.eta());
              h_LIsoPtSum_JetPhi->Fill(rawJetP4.phi());

              h_LIsoPtSum_TauPt->Fill(corrJetP4.pt());
              h_LIsoPtSum_TauEta->Fill(corrJetP4.eta());
              h_LIsoPtSum_TauPhi->Fill(corrJetP4.phi());


            }

	    //

            if(((*_rawc)[tauCandidate]) < 2) {

	      h_MIsoPtSum_GenJetEta->Fill(unsmearedMomentum.eta());
	      h_MIsoPtSum_GenJetPhi->Fill(unsmearedMomentum.phi());
	      h_MIsoPtSum_GenJetPt->Fill(unsmearedMomentum.pt());
	      h_MIsoPtSum_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
	      h_MIsoPtSum_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());

              h_MIsoPtSum_NVtx->Fill(vtx->size());
              h_MIsoPtSum_NGood->Fill(nGoodVtx);
              h_MIsoPtSum_NBest->Fill(nBestVtx);

              h_MIsoPtSum_JetPt->Fill(rawJetP4.pt());
              h_MIsoPtSum_JetEta->Fill(rawJetP4.eta());
              h_MIsoPtSum_JetPhi->Fill(rawJetP4.phi());

              h_MIsoPtSum_TauPt->Fill(corrJetP4.pt());
              h_MIsoPtSum_TauEta->Fill(corrJetP4.eta());
              h_MIsoPtSum_TauPhi->Fill(corrJetP4.phi());


            }

	    //
            if(((*_rawc)[tauCandidate]) < 1) {

	      h_TIsoPtSum_GenJetEta->Fill(unsmearedMomentum.eta());
	      h_TIsoPtSum_GenJetPhi->Fill(unsmearedMomentum.phi());
	      h_TIsoPtSum_GenJetPt->Fill(unsmearedMomentum.pt());
	      h_TIsoPtSum_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
	      h_TIsoPtSum_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());

              h_TIsoPtSum_NVtx->Fill(vtx->size());
              h_TIsoPtSum_NGood->Fill(nGoodVtx);
              h_TIsoPtSum_NBest->Fill(nBestVtx);

              h_TIsoPtSum_JetPt->Fill(rawJetP4.pt());
              h_TIsoPtSum_JetEta->Fill(rawJetP4.eta());
              h_TIsoPtSum_JetPhi->Fill(rawJetP4.phi());

              h_TIsoPtSum_TauPt->Fill(corrJetP4.pt());
              h_TIsoPtSum_TauEta->Fill(corrJetP4.eta());
              h_TIsoPtSum_TauPhi->Fill(corrJetP4.phi());


            }



	    ///
       double iso = (((*_rawc)[tauCandidate]) + ((*_nw2nq)[tauCandidate]));

      if(iso < 1) {

	h_Iso1_GenJetEta->Fill(unsmearedMomentum.eta());
	h_Iso1_GenJetPhi->Fill(unsmearedMomentum.phi());
	h_Iso1_GenJetPt->Fill(unsmearedMomentum.pt());
	h_Iso1_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
	h_Iso1_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());
	
	h_Iso1_NVtx->Fill(vtx->size());
	h_Iso1_NGood->Fill(nGoodVtx);
	h_Iso1_NBest->Fill(nBestVtx);
	h_Iso1_JetPt->Fill(rawJetP4.pt());
	h_Iso1_JetEta->Fill(rawJetP4.eta());
	h_Iso1_JetPhi->Fill(rawJetP4.phi());
	
	h_Iso1_TauPt->Fill(corrJetP4.pt());
	h_Iso1_TauEta->Fill(corrJetP4.eta());                                                                               
	h_Iso1_TauPhi->Fill(corrJetP4.phi());
	
	
      }

      //

      if(iso < 2) {

	h_Iso2_GenJetEta->Fill(unsmearedMomentum.eta());
	h_Iso2_GenJetPhi->Fill(unsmearedMomentum.phi());
	h_Iso2_GenJetPt->Fill(unsmearedMomentum.pt());
	h_Iso2_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
	h_Iso2_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());
	
	h_Iso2_NVtx->Fill(vtx->size());
	h_Iso2_NGood->Fill(nGoodVtx);
	h_Iso2_NBest->Fill(nBestVtx);
	h_Iso2_JetPt->Fill(rawJetP4.pt());
	h_Iso2_JetEta->Fill(rawJetP4.eta());
	h_Iso2_JetPhi->Fill(rawJetP4.phi());
	
	h_Iso2_TauPt->Fill(corrJetP4.pt());
	h_Iso2_TauEta->Fill(corrJetP4.eta());                                                                               
	h_Iso2_TauPhi->Fill(corrJetP4.phi());
	
	
      }
      //      

      if(iso < 4) {

	h_Iso4_GenJetEta->Fill(unsmearedMomentum.eta());
	h_Iso4_GenJetPhi->Fill(unsmearedMomentum.phi());
	h_Iso4_GenJetPt->Fill(unsmearedMomentum.pt());
	h_Iso4_DR->Fill(reco::deltaR(corrJetP4.eta(),corrJetP4.phi() , unsmearedMomentum.eta(),unsmearedMomentum.phi()));
	h_Iso4_Response->Fill(corrJetP4.pt()/unsmearedMomentum.pt());
	
	h_Iso4_NVtx->Fill(vtx->size());
	h_Iso4_NGood->Fill(nGoodVtx);
	h_Iso4_NBest->Fill(nBestVtx);
	h_Iso4_JetPt->Fill(rawJetP4.pt());
	h_Iso4_JetEta->Fill(rawJetP4.eta());
	h_Iso4_JetPhi->Fill(rawJetP4.phi());
	
	h_Iso4_TauPt->Fill(corrJetP4.pt());
	h_Iso4_TauEta->Fill(corrJetP4.eta());                                                                               
	h_Iso4_TauPhi->Fill(corrJetP4.phi());
	
	
      }

 

	  }
}
      }	  
    }
}


// ------------ method called once each job just before starting event loop  ------------


pair<bool, reco::Candidate::LorentzVector> JetTauFakeRateFullSimonEta40::matchToGenJet(double jeteta , double jetphi , edm::Handle<reco::GenJetCollection> ak5jets) {                        
  double drtmp = _TauToGenMatchingDeltaR;
//  bool jetfound = false;
  bool isGenMatched = false;
  reco::Candidate::LorentzVector theGenObject(0,0,0,0);
  for(reco::GenJetCollection::const_iterator genjet = ak5jets->begin();genjet != ak5jets->end();++genjet) {

    if(genjet->pt() <= 20) continue;
    if(fabs(genjet->eta()) >= 4.0) continue;
      double dr = reco::deltaR(jeteta, jetphi,genjet->eta(),genjet->phi());
      if(dr < drtmp) {
	drtmp = dr;
        isGenMatched = true;
        theGenObject = genjet->p4(); 
      }
  } // gen jet
 
 pair<bool, reco::Candidate::LorentzVector> GenMatchedInformation(isGenMatched,theGenObject);
  return GenMatchedInformation;

}



bool JetTauFakeRateFullSimonEta40::OverlapWithGenJet(double jeteta , double jetphi ,edm::Handle<reco::GenJetCollection> ak5jets ,int  &index,const edm::Event& iEvent,const edm::EventSetup& iSetup ) {
  double drtmp = _TauToGenMatchingDeltaR;
  int tmpindex =0 ;
  bool jetfound = false;
  
  for (reco::GenJetCollection::const_iterator jet1 = ak5jets->begin(); jet1 != ak5jets->end(); ++jet1) {
    
    double dr =reco::deltaR(jeteta, jetphi,jet1->eta(),jet1->phi());
    //    cout<<"dr"<<dr<<endl;
    if(dr < drtmp){
      //     cout<<"dr"<<dr<<endl;
      drtmp = dr;
      index = tmpindex;
      jetfound= true;
    } 
    tmpindex++;
  }
  return jetfound;
}


