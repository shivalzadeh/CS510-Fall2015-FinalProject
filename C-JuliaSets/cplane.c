#include <stdio.h>
#include <stdlib.h>
#include "complex.h"
#include "cplane.h"

// Constructor that initializes cplane in a sensible way
CPLANE new_cplane(const VALUE xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax, const INDEX xpoints, const INDEX ypoints ) {
  CPLANE c;
  c.mat = (complex *)calloc(ypoints * xpoints, sizeof(complex));
  if (c.mat == NULL) {
    fprintf(stderr, "Failed to allocate new_matrix\n");
  }

  // set the default value of the matrix
  INDEX rows, cols;
  complex v;
  VALUE col_inc = ((xmax - xmin)+1)/ xpoints;
  VALUE row_inc = ((ymax - ymin)+1)/ ypoints;
  c.xmin = xmin;
  c.xmax = xmax;
  c.ymin = ymin;
  c.ymax = ymax;
  c.xpoints = xpoints;
  c.ypoints = ypoints;

 // printf("Matrix (row_inc: %Lf, col_inc: %Lf, maxrows: %lu, maxcols: %lu \n", row_inc, col_inc, ypoints, xpoints);

// set the values in the matrix
  for(rows=0; rows<ypoints; rows++) {
    for(cols=0; cols<xpoints; cols++) {
      v.x = xmin + cols*col_inc;
      v.y = ymin + rows*row_inc;
      set(&c,rows,cols,v); 
     }
  }
  return c;
} 

// free memory
void delete_cplane(CPLANE c) {
  // Free memory that was allocated, to avoid memory leak
  free(c.mat);
}

// set values in the matrix
void set(CPLANE *c, const INDEX row, const INDEX col, const complex  v) {
  // Find the pointer to the block of memory containing
  // the matrix mat, then jump forward row number of rows
  // and col number of columns.  Inside that block of memory
  // insert the value v.
  if (row < 0 || col < 0 || row >= c->ypoints || col >= c->xpoints) {
    fprintf(stderr, "ERROR: indexing matrix outside bounds");
    return;
  }
  *(c->mat + (c->xpoints * row) + col) = v;
//   print_value(get(c, row, col));
}

// get values from a matrix
complex get(const CPLANE *c, const INDEX row, const INDEX col) {
  // Find the pointer to the block of memory containing
  // the matrix mat, then jump forward row number of rows
  // and col number of columns.  Return the value inside.
  complex zero;
  zero.x = 1;
  zero.y = 1;
  if (row < 0 || col < 0 || row >= c->ypoints || col >= c->xpoints) {
    fprintf(stderr, "ERROR: indexing matrix outside bounds");
    return zero;
  }
   return *(c->mat + (c->xpoints * row) + col);
}

// Abstraction layer in case implementation of VALUE changes later
void print_value(const complex v) {
  complex_print(v);
}

// print a matrix
void print_matrix(const CPLANE *c) {
  INDEX rows, cols, maxr, maxc;
  maxr = c->ypoints;
  maxc = c->xpoints;

//  printf("Matrix (rows: %lu, cols: %lu) \n", maxr, maxc);
  for(rows=0; rows<maxr; rows++) {
    for(cols=0; cols<maxc; cols++) {
      print_value(get(c, rows, cols));
      printf(",\t");
    }
    printf("\n");
  }
}
