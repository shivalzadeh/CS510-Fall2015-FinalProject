#ifndef __JULIA_CPP
#define __JULIA_CPP

// Include header 
#include "julia.h"

// we use juliamap to two complex numbers
COMPLEX juliamap(COMPLEX &z, COMPLEX &c){
  return (z * z) + c;
}

#endif
