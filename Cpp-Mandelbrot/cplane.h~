#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

// This program is definition of the complex plane 
typedef unsigned long int INDEX;
typedef long double VALUE;
typedef std::complex<long double> MAT_VALUE;
typedef boost::numeric::ublas::matrix<std::complex<long double> > MAT_TYPE;  

// class definition of complex plane
class CPLANE {
	private:
		VALUE xmin;
		VALUE xmax;
		VALUE ymin;
		VALUE ymax;
		INDEX xpoints;
		INDEX ypoints;
		MAT_TYPE mat;
	public:
		MAT_TYPE set_matrix(VALUE , VALUE , VALUE , VALUE , INDEX , INDEX );
		MAT_VALUE get_value(MAT_TYPE, INDEX, INDEX);
		void print_matrix(MAT_TYPE);
};
