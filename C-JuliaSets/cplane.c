//library
#include <stdio.h>
#include <stdlib.h>
#include "cplane.h" 

// Initializes matrix
CPLANE new_cplane(const unsigned long int xp, const unsigned long int yp){
  CPLANE c;
  c.rows = yp;
  c.cols = xp;
  c.mat = (COMPLEX *)calloc(yp * xp, sizeof(COMPLEX));
  if (c.mat == NULL) {
    fprintf(stderr, "The Matrix size is not correct\n");
  }
  return c;
}

//Frees allocated memory after its use to avoid memory leak
void delete_cplane(CPLANE c){
  free(c.mat);
}

// Gets an specific element of c.mat 
COMPLEX get(const CPLANE *c, const unsigned long int row, const unsigned long int col){
  if (row < 0 || col < 0 || row >= c->rows || col >= c->cols) {
    fprintf(stderr, "ERROR: indexing cplane outside bounds\n");
    COMPLEX a;
    set_complex(&a,0,0);
    return a;
  }
  return *(c->mat + c->cols * row + col);
}

// Sets cplane
void set(CPLANE *c, const long double  xmin, const long double xmax, const long double ymin, const long double ymax){
  // Defines the step size for x and y directions
  const long double xstep = (xmax - xmin)/(c->cols - 1);
  const long double ystep = (ymax - ymin)/(c->rows - 1);
  // we use counters
  unsigned long int i, j;
  // Sets the mat part of the cplane
  for (i=0; i<(c->rows); i++){
    for (j=0; j<(c->cols); j++){
      set_complex(c->mat + (c->cols * i) + j, xmin + j * xstep, ymin + i * ystep);
    }
  }
}

//we call function set the again
CPLANE constructor(const  long double xmin, const long double xmax, const long double ymin, const long double ymax, const unsigned long int xpoints, const unsigned long int ypoints){
  // Creates a new CPLANE 
  CPLANE c = new_cplane(xpoints,ypoints);  

    set(&c,xmin, xmax, ymin, ymax);
  return c;
}

// Prints a cplane
void print_cplane(const CPLANE *cp){
  unsigned long int i, j;
  printf("Cplane (rows: %ld, cols: %ld) \n", cp->rows, cp->cols);
  for(i=0; i<(cp->rows); i++) {
    for(j=0; j<(cp->cols); j++) {
      // Prints values of matrix 
      COMPLEX z = get(cp, i, j);
      complex_print(&z);
      printf(" ");
    }
    puts("");
  }
  puts("");
}
