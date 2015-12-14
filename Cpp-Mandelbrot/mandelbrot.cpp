#include <iostream>
#include "cplane.hpp"
#include "julia.h"

//This is the main program to generate data points for the mandelbrot visualization

int main (int argc, char **argv) {
/************************************************************************************
* Function: int main()
* Input : xmin, xmax, ymin, ymax, xpoints, ypoints
* Output : Returns 0 on success
* Procedure: Performs operations on complex numbers and prints results.
************************************************************************************/

// exploit namespaces to simplify code
  using namespace boost::numeric::ublas;
  using std::cout; using std::endl;
  std::cout.sync_with_stdio(false);

// check for input parameters
if ( argc != 7) {
cout << " The program is expecting 6 input parameters, you entered :" <<  argc-1 << endl;
   return(-1);
};


// Initialize all the parameters
CPLANE cplane;
int MAXITER=256;
char *e;
VALUE xmin  = strtold(argv[1], &e);
VALUE xmax = strtold(argv[2], &e);
VALUE ymin = strtold(argv[3], &e);
VALUE ymax = strtold(argv[4], &e);
INDEX xpoints = strtoul(argv[5], &e, 0);
INDEX ypoints = strtoul(argv[6], &e,0);

MAT_TYPE mat;
MAT_VALUE c_val, z_val;
INDEX rows, cols;
mat = cplane.set_matrix(xmin,xmax,ymin,ymax,xpoints,ypoints);
//cplane.print_matrix(mat);

//Traverse through the matrix
 for(rows=0; rows<ypoints; rows++) {
    for(cols=0; cols<xpoints; cols++) {
    //c_val = cplane.get_value(mat,rows,cols);
    c_val = mat(rows,cols);
    // Initialize the z_val 
    z_val.real()=0.0;
    z_val.imag()=0.0;
    int m = 0;
    while (1) {
          z_val = juliamap(c_val,z_val);
          ++m;
         // cout <<"Absolute Value  " << abs(z_val) << endl;
          if (abs(z_val.real()+z_val.imag()) > 2) {
             cout << c_val.real() << "," << c_val.imag()<< "," << m << endl ;
             break;
           }
           else if ( m >= MAXITER) {
             cout << c_val.real() << "," << c_val.imag()<< "," << 0 << endl ;
             break;
           };
      }; /* end of while loop */
    }; /* end of cols */
  }; /* end of rows */

//comp_val = cplane.get_value(mat,1,0);
return 0;
}
