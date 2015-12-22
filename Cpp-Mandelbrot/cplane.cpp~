#include "cplane.hpp"
using namespace boost::numeric::ublas;

cplane::cplane(long double xmin, long double xmax, long double ymin, long double ymax, unsigned long int xpoints, unsigned long int  ypoints): 
							Xmin(xmin), Xmax(xmax),  Ymin(ymin),  Ymax(ymax),  Xpoints(xpoints),   Ypoints(ypoints){

	long double stepx = (xmax-xmin)/xpoints;
	long double stepy = (ymax-ymin)/ypoints;
	long double x;
	long double y;
	matrix<std::complex<long double> > mat(xpoints,ypoints);
	int i;
	int j;
	i=0;
	for (x=xmin; i<xpoints; x=x+stepx){
		j=0;
		for (y=ymin; j<ypoints; y=y+stepy){
			mat(i,j) =std::complex<long double>(x, y);
			j=j+1;
		}
		i=i+1;

	}
	this->Mat =mat;
};
