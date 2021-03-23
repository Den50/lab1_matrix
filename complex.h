#ifndef LAB1_COMPLEX_H
#define LAB1_COMPLEX_H
#include <stdio.h>

// this module contain struct and functions for work with complex numbers

// functions:
// add(a, b) -> (a_R + b_R) + (a_C + b_C)i
// minus(a, b) -> (a_R - b_R) + (a_C - b_C)i
// multiply(a, b) -> (a_R * b_C - a_C * b_R) - (a_C * b_C + a_R * b_R)i
// division(a, b) -> (a_R + b_R) + (a_C + b_C)i
// multiplyOnAlpha(a, alpha) -> (a_R + b_R) + (a_C + b_C)i


struct Complex{
    double real;
    double im;
    int imaginaryUnit;
};
typedef struct Complex complex;

complex createComplex(double real, double im, complex* container);
complex complex_summ(complex a, complex b);
complex complex_minus(complex a, complex b);
complex complex_multiply(complex a, complex b);
complex complex_division(complex a, complex b);
complex complex_multiplyOnAlpha(complex a, double alpha);
void printComplexNumber(complex* a);


#endif //LAB1_COMPLEX_H
