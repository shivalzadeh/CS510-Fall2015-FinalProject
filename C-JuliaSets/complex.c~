#include <stdio.h>
#include "complex.h"
#include <stdlib.h>

char *complex_to_str(ComplexNumber z){
	char *tagstr=malloc(z.x+z.y);
	sprintf(tagstr, "%1.10Lf+%1.10Lfi", z.x, z.y);
	printf("String %s \n", tagstr);
	return tagstr;
}

ComplexNumber juliamap(ComplexNumber z, ComplexNumber c){
	ComplexNumber result;
	result = add2(square(z),c);
	return result;
}

ComplexNumber add2(ComplexNumber a, ComplexNumber b){

	ComplexNumber result;
	result.x=a.x+b.x;
	result.y=a.y+b.y;
	return result;
}



ComplexNumber mult2(ComplexNumber a, ComplexNumber b){
	ComplexNumber result;
	result.x=((a.x*b.x)-(a.y*b.y));
	result.y=((a.x*b.y)+(b.x*a.y));
	return result;
};

ComplexNumber square (ComplexNumber a){
	ComplexNumber result;
	result.x=(a.x*a.x)-(a.y*a.y);
	result.y=a.y*a.y;
	return result; 
};
