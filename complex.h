#ifndef LAB1_COMPLEX_H
#define LAB1_COMPLEX_H

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



#endif //LAB1_COMPLEX_H
