#include "complex.h"

complex createComplex(double real, double im, complex* container){
    container->real = real;
    container->im = im;
    return* container;
}
complex complex_summ(complex a, complex b){
    complex c;
    c.real = a.real + b.real;
    c.im = a.im + b.im;
    return c;
}
complex complex_minus(complex a, complex b){
    complex c;
    c.real = a.real - b.real;
    c.im = a.im - b.im;
    return c;
}
complex complex_multiply(complex a, complex b){
    complex c;
    c.real = a.real * b.real - a.im * b.im;
    c.im = a.real * b.im + a.im * b.real;
    return c;
}
complex complex_division(complex a, complex b){
    complex c;
    c.real  = (a.real * b.real + a.im * b.im) / (b.real * b.real + b.im * b.im);
    c.im = (a.im * b.real - a.real * b.im) / (b.real * b.real + b.im * b.im);
    return c;
}
complex complex_multiplyOnAlpha(complex a, double alpha){
    complex c;
    c.real = a.real * alpha;
    c.im = a.im * alpha;
    return c;
}
void printComplexNumber(complex* a){
    printf(" complex(%.3f + %.3fi)\n", a->real, a->im);
}

