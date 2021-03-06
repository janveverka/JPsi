/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef JPSI_MUMU_INTERFACE_ROOTRUNCATEDEXPONENTIAL_H
#define JPSI_MUMU_INTERFACE_ROOTRUNCATEDEXPONENTIAL_H

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class RooTruncatedExponential : public RooAbsPdf {
public:
  RooTruncatedExponential() {} ; 
  RooTruncatedExponential(const char *name, const char *title,
	      RooAbsReal& _x,
	      RooAbsReal& _mean,
	      RooAbsReal& _xmin,
	      RooAbsReal& _xmax,
	      RooAbsReal& _alpha,
	      RooAbsReal& _epsilon);
  RooTruncatedExponential(const RooTruncatedExponential& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooTruncatedExponential(*this,newname); }
  inline virtual ~RooTruncatedExponential() { }

protected:

  RooRealProxy x ;
  RooRealProxy mean ;
  RooRealProxy xmin ;
  RooRealProxy xmax ;
  RooRealProxy alpha ;
  RooRealProxy epsilon ;
  
  Double_t evaluate() const ;

private:

  ClassDef(RooTruncatedExponential,1) // Your description goes here...
};
 
#endif
