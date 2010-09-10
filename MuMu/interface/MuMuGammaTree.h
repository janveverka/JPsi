#ifndef JPsi_MuMu_MuMuGammaTree_h
#define JPsi_MuMu_MuMuGammaTree_h

#include <TTree.h>
#include "JPsi/MuMu/interface/DimuonsTree.h"

class MuMuGammaTree : public DimuonsTree {
public:
  MuMuGammaTree(TTree *tree=0);
  ~MuMuGammaTree();
  void initGamma(TTree*);
  void initGammaLeafVariables();

  const static unsigned char maxPhotons = -1;
  const static unsigned char maxMuMuGammas = -1;  // 255

  // event leafs
  unsigned char nPhotons;
  unsigned char nMuMuGammas;

  // MuMuGamma leafs
  float mmgMass[maxMuMuGammas];
  unsigned char mmgDimuon[maxMuMuGammas];
  unsigned char mmgPhoton[maxMuMuGammas];
  float mmgDeltaRNear[maxMuMuGammas];

  // photon leafs
  float phoPt[maxPhotons];
  float phoEta[maxPhotons];
  float phoPhi[maxPhotons];
  float phoEcalIso[maxPhotons];
  float phoHcalIso[maxPhotons];
  float phoTrackIso[maxPhotons];
  float phoSigmaIetaIeta[maxPhotons];
  float phoHadronicOverEm[maxPhotons];

private:
  TTree *tree_;
};

#endif