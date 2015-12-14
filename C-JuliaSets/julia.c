#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "cplane.h"

/* This is the main program that calls various functions to create data points for juliset */

int main(int argc, char **argv)
{
/************************************************************************************
* Function: int main()
* Input : xmin, xmax, ymin, ymax, xpoints, ypoints, creal, and cimag
* Output : Returns 0 on success
* Procedure: Performs operations on complex numbers and prints results.
************************************************************************************/

// check for input parameters
if ( argc != 9) {
   printf ( " The program is expecting 8 input parameters, you entered :%d \n", argc -1);
   return(-1);
}

// Initialize all the parameters
CPLANE cp;
int MAXITER=256;
char *e;
INDEX rows,cols;
complex c, z, v;
VALUE xmin  = strtold(argv[1], &e);
VALUE xmax = strtold(argv[2], &e);
VALUE ymin = strtold(argv[3], &e);
VALUE ymax = strtold(argv[4], &e);
INDEX xpoints = strtoul(argv[5], &e, 0);
INDEX ypoints = strtoul(argv[6], &e,0);
VALUE creal = strtold(argv[7], &e);
VALUE cimag = strtold(argv[8], &e);
c.x = creal;
c.y = cimag;

// create a new plane
cp = new_cplane(xmin,xmax,ymin,ymax,xpoints,ypoints);
// print_matrix(&cp);

// Traverse through the plane
  for(rows=0; rows<ypoints; rows++) {
    for(cols=0; cols<xpoints; cols++) {
    v = get ( &cp, rows,cols); 
    z.x = v.x;
    z.y = v.y;
    int m = 0;
    while (1) {
          // printf("The absolute values is %d \n", abs(z.x+z.y));
          z = juliamap(z,c);
          m = ++m;
          if (abs(z.x+z.y) > 2) {
             printf("%Lf,%Lf,%d \n", v.x, v.y, m);
             break;
           }
           else if ( m >= MAXITER) {
             printf("%Lf,%Lf,%d \n", v.x, v.y, 0);
             break;
           }
      } /* end of while loop */
    } /* end of cols */
  } /* end of rows */

// clean up memory
delete_cplane(cp);
return 0;
}
