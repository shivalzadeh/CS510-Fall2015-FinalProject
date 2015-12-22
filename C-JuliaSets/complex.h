//we just use abstract types 
typedef struct complex {
  long double x;
  long double y;
} COMPLEX;

// Declares the functions constructed on .c file
void set_complex(COMPLEX *, long double, long double);
COMPLEX mult2(COMPLEX *, COMPLEX *);
COMPLEX square(COMPLEX *);
COMPLEX add2(COMPLEX *,COMPLEX *);
COMPLEX juliamap(COMPLEX *, COMPLEX *);
long double square_mod(COMPLEX *);
void complex_print(COMPLEX *);
