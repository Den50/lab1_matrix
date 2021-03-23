#ifndef LAB1_ALGEBRA_OTHER_H
#define LAB1_ALGEBRA_OTHER_H

#include "matrix.h"
char* concat(const char *s1, const char *s2);
void summOther(matrix_other* A, matrix_other* B, matrix_other* container);
void multiplyOnAlphaOther(matrix_other* Matrix, int alpha, matrix_other* multiplied);

#endif //LAB1_ALGEBRA_OTHER_H