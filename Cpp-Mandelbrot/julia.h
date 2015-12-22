#ifndef __JULIA_H
#define __JULIA_H

// Includes library 
#include <complex>

// Defines a type
typedef std::complex<long double> COMPLEX;

//functions defined in .cpp file
COMPLEX juliamap(COMPLEX &, COMPLEX &);
 
#endif
