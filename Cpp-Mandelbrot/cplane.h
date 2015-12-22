#ifndef __MPLANE_H
#define __CPLANE_H

// Includes libraries
#include <boost/numeric/ublas/matrix.hpp>
#include <complex>

// Defines types
typedef std::complex<long double> COMPLEX;

// Defines a class called cplane
class cplane {
  public:
    long int rows;
    long int cols;
    boost::numeric::ublas::matrix<std::complex<long double> > mat;
};

// we show functions defined in the .cpp file
void set(cplane &, const long double, const long double, const long double, const long double);
cplane constructor(const long double, const long double, const long double, const long double, const long int, const long int);
void print_cplane(cplane &);

#endif
