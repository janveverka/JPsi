//--*-C++-*--
/*
  Author: Jan Veverka

  Calculates the shortest interval (x_lo, x_hi) containing at least the given
  fraction in (0,1] of the given elements [first, last).

*/
#ifndef JPSI_MUMU_MODALINTERVAL_H
#define JPSI_MUMU_MODALINTERVAL_H

#include <algorithm>
#include <vector>

#include "TObject.h"

namespace cit {
  class ModalInterval : public TObject {

  public:
    typedef std::vector<double>::const_iterator const_iterator;
    ModalInterval();
    ModalInterval(const_iterator first, const_iterator last,
                  double fraction = 1.);
    ModalInterval(size_t n, double* first, double fraction);
    virtual ~ModalInterval();

    void   getInterval(double& lower, double& upper);
    double getLowerBound();
    double getUpperBound();
    double getSize();

    template<typename T>
    void
    readData(T first, T last) {
      updated_  = false;

      /// Check if [first, last) is not empty.
      if (first >= last) {
        /// There is no data available.
        x_.resize(0);
        initBounds();
        updated_ = true;
        return;
      }

      x_.resize(last - first);

      /// Set the first and last to include the left-most interval
      initBounds();

      /// Copy the source data to a new vector to sort it
      std::copy(first, last, x_.begin());

      /// Sort the data
      std::sort(x_.begin(), x_.end());
    }
//     void readData(const_iterator first, const_iterator last);
    void readData(size_t n, double* first);
    void setFraction(double fraction);

  protected:
    /// Calculates the interval.
    void get();
    /// Sets the interval bounds to the left most interval.
    void initBounds();

    /// Interval contains at least fraction_ of the total entries.
    double fraction_;
    /// Has the interval been calculated?
    bool   updated_;
    /// Sorted copy of the input data.
    std::vector<double> x_;
    /// Interval lower und upper bounds as pointers to elements of x_.
    const_iterator lower_;
    const_iterator upper_;

    ClassDef(ModalInterval,0)

  };
} // end of namespace cit
#endif