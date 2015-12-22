#include <iostream>
#include <string>
#include <sstream>
#include "cplane.h"
#include "julia.h"

#define MAXITER 256

using namespace std;

// Declare a function
int iterate(COMPLEX, COMPLEX &);
 
// main function
int main(void) {
 
  // Define variables
  long int i, j, out;
  long int xpoints, ypoints;
  long double xmin, xmax, ymin, ymax;
  cplane a;

  // Receive the inputs
  cout << "Please give me a number as a minimum value for x-axis: ";
  cin >> xmin;
  cout << endl;
  cout << "Please give me a number as a maximum value for x-axis: ";
  cin >> xmax;
  cout << endl;
  cout << "please give me a number as a minimum value for y-axis: ";
  cin >> ymin;
  cout << endl;
  cout << "Please give me a number as a maximum value for y-axis: ";
  cin >> ymax;
  cout << endl;
  cout << "Please give me a number as a number of points in x-axis: ";
  cin >> xpoints;
  cout << endl;
  cout << "Please give me a number as a number of in y-axis: ";
  cin >> ypoints;
  cout << endl;

  // we make a appropriate cplane
  a = constructor(xmin, xmax, ymin, ymax, xpoints, ypoints);

  // Receive and print the output of the cplane
  cout << "x, y, out" << endl;
  for(i=0; i<ypoints; i++){
    for(j=0; j<xpoints; j++){
      out = iterate((0, 0), a.mat(i, j));
      cout << real(a.mat(i, j)) << ", " << imag(a.mat(i, j)) << ", " << out << endl;
    }
  }

  // Destruct matrix when done
  a.mat.clear();

  return 0;
}
 
// Iterate the function juliamap
int iterate(COMPLEX z, COMPLEX &c){
  long int i, j, n;
  n=0;
  while(true){
    z = juliamap(z, c);
    n=n+1;
    if(abs(z)>2){
      return n;
    }
    else if(n>=MAXITER){
      return 0;
    }
  }
}
