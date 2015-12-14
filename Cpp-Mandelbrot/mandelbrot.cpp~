#include "julia.h"
#include "cplane.hpp"
#include <boost/numeric/ublas/matrix.hpp>
using namespace boost::numeric::ublas;
using namespace std;

void iterate(std::complex<long double> c,std::complex<long double> z);
int main (int argc, char* argv[])
{
	if(argc< 7){
		cout << "Error Not enogh arguments \n";
	 return 1;
	}
        long double xmin = atoi(argv[1]); 
	long double xmax= atoi(argv[2]); 
	long double ymin= atoi(argv[3]); 
	long double  ymax= atoi(argv[4]); 
	unsigned long int xpoints= atoi(argv[5]); 
	unsigned long int ypoints= atoi(argv[6]); 

	cplane cp(xmin, xmax, ymin, ymax, xpoints, ypoints);
	int i =0;
	int j =0;
	 for(matrix<std::complex<long double> >::iterator1 it1 = cp.Mat.begin1(); it1 != cp.Mat.end1(); ++it1) {
	    for(matrix<std::complex<long double> >::iterator2 it2 = it1.begin(); it2 !=it1.end(); ++it2) {
			iterate(0,*it2);
		}	
	}

	return 0;	
}


void iterate(std::complex<long double> c,std::complex<long double> z){
        int out=0;
        while(1>0){         
            if(sqrt((z.real()*z.real() )+(z.imag()*z.imag()))>=2){
		std::cout << z.real() << "," << z.imag() << "," << out << "\n";                
		break;
	    }
            else if(out>=256){
		std::cout << z.real() << "," << z.imag() << "," << out << "\n";                
		break;
	    }
            z=juliamap(z,c);
            out= out+1;
	}
}
