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
    double cmplx;
    int imaginaryUnit;
};
typedef struct Complex complex;

complex add(complex a, complex b){
    complex c;
    c.real = a.real + b.real;
    c.cmplx = a.cmplx + b.cmplx;
    return c;
}
complex add(complex a, complex b){
    complex c;
    c.real = a.real - b.real;
    c.cmplx = a.cmplx - b.cmplx;
    return c;
}

complex multiply(complex a, complex b){
    complex c;
    c.real = a.real * b.real - a.cmplx * b.cmplx;
    c.real = a.real * b.cmplx + a.cmplx * b.real;
    return c;
}

complex division(complex a, complex b){
    complex c;
    c.real  = (a.real * b.real + a.cmplx * b.cmplx) / (b.real * b.real + b.cmplx * b.cmplx);
    c.cmplx = (a.cmplx * b.real - a.real * b.cmplx) / (b.real * b.real + b.cmplx * b.cmplx);
    return c;
}

complex multiplyOnAlpha(complex a, double alpha){
    complex c;
    c.real = a.real * alpha;
    c.cmplx = a.cmplx * alpha;
    return c;
}



#endif //LAB1_COMPLEX_H
