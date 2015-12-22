// Includes the header complex.h
#include "complex.h"

// Uses abstract types inside cplane
typedef struct cplane {
  unsigned long int rows;
  unsigned long int cols;
  COMPLEX *mat;
} CPLANE;

// Declares the functions defined on the .c file
CPLANE new_cplane(const unsigned long int, const unsigned long int);
void delete_cplane(CPLANE);
COMPLEX get(const CPLANE *, const unsigned long int, const unsigned long int);
void set(CPLANE *, const long double, const long double, const long double, const long double);
CPLANE constructor(const long double, const long double, const long double, const long double, const unsigned long int, const unsigned long int);
void print_cplane(const CPLANE *);
