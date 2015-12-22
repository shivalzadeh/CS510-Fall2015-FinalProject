// Includes libraries
#include <stdio.h>
#include "cplane.h"

// Defines a global constant
#define MAXITER 256

// Declares a function
int iterate(COMPLEX, COMPLEX *);

// the part of main function
int main(void) {

  // Defines variables to receive inputs and to work with later
  unsigned long int i, j, out;
  unsigned long int xpoints, ypoints;
  long double xmin, xmax, ymin, ymax, creal, cimag;
  COMPLEX c, z;
  CPLANE a;

  // Receives inputs
  printf("Please give me the minimum value for x-axis: ");
  scanf("%Lf", &xmin);
  printf("\n");
  printf("Please give me the maximum value for x-axis: ");
  scanf("%Lf", &xmax);
  printf("\n");
  printf("Please give me the minimum value for y-axis: ");
  scanf("%Lf", &ymin);
  printf("\n");
  printf("Please give me the maximum value for y-axis: ");
  scanf("%Lf", &ymax);
  printf("\n");
  printf("Please give me the number of points for x-axis: ");
  scanf("%ld", &xpoints);
  printf("\n");
  printf("Please give me the number of points for y-axis: ");
  scanf("%ld", &ypoints);
  printf("\n");
  printf("Please give me the value for the real part of c: ");
  scanf("%Lf", &creal);
  printf("\n");
  printf("Please give me the value for the imaginary part of c: ");
  scanf("%Lf", &cimag);
  printf("\n");

  // we make the desirable cplane
  a = constructor(xmin, xmax, ymin, ymax, xpoints, ypoints);

  // we make the complex c
  set_complex(&c, creal, cimag);

  // Receives and prints the output of the cplane
  printf("x, y, out\n");
  for(i=0; i<ypoints; i++){
    for(j=0; j<xpoints; j++){
      z = get(&a, i, j);
      out = iterate(z, &c);
      printf("%Lf, %Lf, %ld\n", z.x, z.y, out);
    }
  }

  // Destructs matrix when done
  delete_cplane(a);

  return 0;
}

// Iterates the function juliamap
int iterate(COMPLEX z, COMPLEX *c){
  unsigned long int i, j, n;
  n=0;
  for(;;){
    z = juliamap(&z, c);
    n=n+1;
    if(square_mod(&z)>4){
      return n;
    }
    else if(n>=MAXITER){
      return 0;
    }
  }
}
