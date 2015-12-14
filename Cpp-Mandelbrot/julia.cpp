#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "julia.h"

//This program is used to define various functions on complex numbers

// multiply two complex numbers
MAT_VALUE mult2( MAT_VALUE compx_n1, MAT_VALUE compx_n2) {
        MAT_VALUE temp;
        temp = compx_n1*compx_n2;
        return (temp);
};

// take square of a complex number
MAT_VALUE square(MAT_VALUE compx_n1) {
	MAT_VALUE temp;
	temp = std::pow(compx_n1,2);
	return (temp);
};

// add two complex numbers
MAT_VALUE add2(MAT_VALUE compx_n1, MAT_VALUE compx_n2) {
	MAT_VALUE temp;
	temp = compx_n1+compx_n2;
	return (temp);
};

// run juliamap function on two complex numbers
MAT_VALUE juliamap(MAT_VALUE compx_n1, MAT_VALUE compx_n2) {
	MAT_VALUE temp;
	temp = add2(square(compx_n1),compx_n2); 
        return (temp);
};

