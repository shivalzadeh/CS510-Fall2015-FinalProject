#include "cplane.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void iterate(ComplexNumber z,ComplexNumber c);

int main(int argc, char **argv){
	if(argc< 9){
	 return 1;
	}
        long double xmin = atoi(argv[1]); 
	long double xmax= atoi(argv[2]); 
	long double ymin= atoi(argv[3]); 
	long double  ymax= atoi(argv[4]); 
	unsigned long int xpoints= atoi(argv[5]); 
	unsigned long int ypoints= atoi(argv[6]); 
	long double  creal= atoi(argv[7]); 
	long double cimag= atoi(argv[8]);	
	CPLANE* cpl = CPLANE_new(xmin, xmax, ymin, ymax, xpoints, ypoints);
	ComplexNumber COMPLEX;
	COMPLEX.x=creal;
	COMPLEX.y=cimag;
	int i =0;
	int j =0;
		
	for(i=0;i<xpoints;i++){
		for(j=0;j<ypoints;j++){
			ComplexNumber c =*(cpl[0].mat+j+i);
			iterate(c,COMPLEX);
		}	
	}
	return 0;
}

int MAXITER=256;

void iterate(ComplexNumber z,ComplexNumber c){
        int out=0;
        while(1>0){         
            if(sqrt((z.x*z.x)+(z.y*z.y))>=2){
		printf("%1.10Lf, %1.10Lf, %d \n",z.x,z.y, out);                
		break;
	    }
            else if(out>=MAXITER){
		printf("%1.10Lf, %1.10Lf, %d \n",z.x,z.y, out);         
		break;
	    }
            z=juliamap(z,c);
            out= out+1;
	}
}
