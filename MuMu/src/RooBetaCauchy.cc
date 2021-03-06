/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Implementation of the Beta-Cauchy PDF. 

#include "Riostream.h" 

#include "JPsi/MuMu/interface/RooBetaCauchy.h" 
#include "RooAbsReal.h" 
#include "RooAbsCategory.h" 
#include <math.h> 
#include "TMath.h" 

ClassImp(RooBetaCauchy) 

 RooBetaCauchy::RooBetaCauchy(const char *name, const char *title, 
                        RooAbsReal& _x,
                        RooAbsReal& _mean,
                        RooAbsReal& _width,
                        RooAbsReal& _beta,
                        RooAbsReal& _theta) :
   RooAbsPdf(name,title), 
   x("x","x",this,_x),
   mean("mean","mean",this,_mean),
   width("width","width",this,_width),
   beta("beta","Asymmetry Parameter",this,_beta),
   theta("theta","Kurtosis Parameter",this,_theta)
 { 
 } 


 RooBetaCauchy::RooBetaCauchy(const RooBetaCauchy& other, const char* name) :  
   RooAbsPdf(other,name), 
   x("x",this,other.x),
   mean("mean",this,other.mean),
   width("width",this,other.width),
   beta("beta",this,other.beta),
   theta("theta",this,other.theta)
 { 
 } 



 Double_t RooBetaCauchy::evaluate() const 
 { 
   // For the definition of the Beta morph, see
   // http://www.statistik.wiso.uni-erlangen.de/forschung/d0064.pdf
   // The Beta-Hyperbolic Secant (BHS) Distribution
   // Matthias J. Fischer, David Vaughan
   const static double epsilon = 1e-2;
   
   // Absorb the location and scale parameters
   double t = (x - mean) / width;

   // This is the Cauchy density w/o the 1/(pi*width) normalization factor
   double f = 1. / (1. + t*t);

   // This is the Cauchy CDF properly normalized
   double F = 0.5 + TMath::ATan(t) / TMath::Pi();

   // Make sure that the CDF value is sane.
   if (F <= 0) {
     Error("RooBetaGshPdf::evaluate", "Illegal CDF value: %g", F);
     F = epsilon;
   }

   if (1 <= F) {
     Error("RooBetaGshPdf::evaluate", "Illegal CDF value: %g", F);
     F = 1 - epsilon;
   }

   // Make sure that beta_ and theta_ are in allowed range.
   double beta_ = beta > 0 ? beta : 0;
   double theta_ = theta;

   if (theta_ <= -beta_) 
     theta_ = -beta_ + 1e-2;
   else if (beta_ <= theta_)
     theta_ = beta_ - 1e-2;

   // Calculate the morphing weight of the Beta PDF
   std::cout << "x, p, q: " << F << ", " << beta_ + theta_ << ", "
	     << beta_ - theta_ << std::endl;

   // Calculate the morphing weight of the Beta PDF
   double w = TMath::BetaDist(F, beta + theta, beta - theta);
              
   return f * w; 
 } 



