#include <stdio.h>
#include "complex.h"
/* This program is the definition of various functions that can be performed on compled numbers */

// multiply two complex numbers
complex mult2(complex a,  complex b) {
	complex temp;
	temp.x = a.x*b.x - a.y*b.y;
	temp.y = a.x*b.y+a.y*b.x;
	return(temp);
}

// square two complex numbers
complex square(complex a) {
	complex temp;
	temp.x = a.x*a.x - a.y*a.y;
	temp.y = 2*a.x*a.y;
	return(temp);
}

// add two complex numbers
complex add2(complex a, complex b) {
	complex temp;
	temp.x = a.x + b.x;
	temp.y = a.y+b.y;
	return(temp);
}

// Run a juliamap function on two complex numbers
complex juliamap(complex a, complex b) {
	complex temp;
	temp = add2(square(a),b);
	return(temp);
}

//print a complex number
void complex_print(complex z) {
	printf ("%Lf+i%Lf ",z.x,z.y);
}
