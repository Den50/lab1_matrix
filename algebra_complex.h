#ifndef LAB1_ALGEBRA_COMPLEX_H
#define LAB1_ALGEBRA_COMPLEX_H
#include "matrix.h"
#include "complex.h"

void summComplex(matrix_complex* A, matrix_complex* B, matrix_complex* container);
void minusComplex(matrix_complex* A, matrix_complex* B, matrix_complex* container);
void multiplyOnAlphaComplex(matrix_complex* Matrix, double alpha, matrix_complex* multiplied);
void multiplyComplex(matrix_complex* A, matrix_complex* B, matrix_complex* Result);

#endif //LAB1_ALGEBRA_COMPLEX_H