import array
import ROOT
ROOT.gSystem.Load('libJPsiMuMu')
ROOT.gROOT.ProcessLine('#include "JPsi/MuMu/interface/ModalInterval.h"')

## Get some toy data
n = 10000
ROOT.gROOT.ProcessLine('vector<double> data')
data = ROOT.data
data.reserve(n)
for i in range(n):
  data.push_back(ROOT.gRandom.Gaus(0,1))

## Create the ModalInterval object
mi = ROOT.cit.ModalInterval(data.begin(), data.end(), 1)

## Pring the full range of toy data
print "[", mi.getLowBound(), ",", mi.getHighBound(), "]"

## Print the range corresponding to n effective sigma
nsigma = 0.5
fraction = 1 - ROOT.TMath.Prob(nsigma*nsigma, 1)
mi.setFraction(fraction)
print "[", mi.getLowBound(), ",", mi.getHighBound(), "]"