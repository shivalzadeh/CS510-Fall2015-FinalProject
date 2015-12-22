#ifndef __CPLANE_CPP
#define __CPLANE_CPP

// Includes the header
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "cplane.h"

// just for simplifying the code
using namespace std;
using namespace boost::numeric::ublas;

// Sets a cplane
void set(cplane &cp, const long double xmin, const long double xmax, const long double ymin, const long double ymax){
  const long double xstep = (xmax - xmin)/(cp.cols - 1);
  const long double ystep = (ymax - ymin)/(cp.rows - 1);
  long int i, j;
  COMPLEX z;
  for (i=0; i<cp.rows; i++){
    for (j=0; j<cp.cols; j++){
        real(z) = xmin + j * xstep;
        imag(z) = imag(z)=ymin + i * ystep;
        cp.mat(i,j) = z;
    }
  }
}

// allocates space and calls the function set
cplane constructor(const long double xmin, const long double xmax, const long double ymin, const long double ymax, const long int xpoints, const long int ypoints){
  cplane c;
  c.rows = ypoints;
  c.cols = xpoints;

    c.mat.resize(c.rows, c.cols);
    set(c, xmin, xmax, ymin, ymax);
  
  return c;
}

// Prints a cplane
void print_cplane(cplane &cp){
  long int i, j;
  cout << "Cplane (rows: " << cp.rows << ", cols: " << cp.cols << ")" << endl;
  for(i=0; i<cp.rows; i++) {
    for(j=0; j<cp.cols; j++) {
     cout << cp.mat(i,j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

#endif
