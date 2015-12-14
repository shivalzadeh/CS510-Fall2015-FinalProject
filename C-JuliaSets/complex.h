/* This file is header definition for complex planes. This will be called by all the programs in the Juliset directory*/ 

/* structure to store the complex numbers */
struct COMPLEX {
 long double x;
 long double y;
};

typedef struct COMPLEX complex;

/* Function declaration */
complex mult2( complex a,  complex b);
complex square(complex a);
complex add2( complex a,  complex b);
complex juliamap( complex a,  complex b);
void complex_print(const complex z) ;
void test(void);
