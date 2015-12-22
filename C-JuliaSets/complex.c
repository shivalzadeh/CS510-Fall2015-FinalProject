#include<stdio.h>
#include"complex.h"

// we Set here  a complex number
void set_complex(COMPLEX *c, long double a, long double b){
  c->x=a;
  c->y=b;
}

// we want to Multiply two complex numbers
COMPLEX mult2(COMPLEX *a, COMPLEX *b){
  COMPLEX z;
  z.x=(a->x)*(b->x)-(a->y)*(b->y);
  z.y=(a->x)*(b->y)+(a->y)*(b->x);
  return z;
}

// we want to Square a complex number
COMPLEX square(COMPLEX *a){
  return mult2(a,a);
}

// at this part we want to Add two complex numbers
COMPLEX add2(COMPLEX *a, COMPLEX *b){
  COMPLEX z;
  z.x=(a->x)+(b->x);
  z.y=(a->y)+(b->y);
  return z;
}

// we use  juliamap to two complex numbers
COMPLEX juliamap(COMPLEX *a, COMPLEX *b){
  COMPLEX c = square(a);
  return add2(&c,b);
}

// Outputs the square of the module of a complex
long double square_mod(COMPLEX *a){
  return (a->x)*(a->x) + (a->y)*(a->y);
}

// it prints a complex number
void complex_print(COMPLEX *a){
  if ((a->y)<0){
    printf("%Lf%Lfi",a->x,a->y);
  }
  else{
    printf("%Lf+%Lfi",a->x,a->y);
  }
}
