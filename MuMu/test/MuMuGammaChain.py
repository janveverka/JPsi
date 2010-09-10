from basicRoot import *

inputFiles = """
MuMuGammaTree_Mu_Run2010A-PromptReco-v4_140400-140401_NoJson.root
MuMuGammaTree_Mu_Run2010A-Jun14thReReco_v1_135803-137436.root
MuMuGammaTree_Mu_Run2010A-PromptReco-v4_140160-140399.root
MuMuGammaTree_MinimumBias_Commissioning10-SD_Mu-Jun14thSkim_v1_132440-137028.root
MuMuGammaTree_Mu_Run2010A-Jul16thReReco-v1_139559-140159.root
MuMuGammaTree_Mu_Run2010A-PromptReco-v4_137437-139558.root
""".split()

chain = TChain("MuMuGammaTree/mmg")

for f in inputFiles:
  print "Loading ", f
  chain.Add(f)

print "Total entries in the chain:", chain.GetEntries()



#####################################################################
#####################################################################
#####################################################################
# MONTE CARLO
inputFilesMC = """
MuMuGammaTree_ZJets-madgraph.root
""".split()

chainMC = TChain("MuMuGammaTree/mmg")

for f in inputFilesMC:
  print "Loading ", f
  chainMC.Add(f)

print "Total entries in the MC chain:", chainMC.GetEntries()

if __name__ == "__main__": import user
