#ifndef LAB1_UI_H
#define LAB1_UI_H
#include "matrix.h"
#include "complex.h"

matrix_int initialization_martix_int(matrix_int* Matrix);
matrix_double initialization_martix_double(matrix_double* Matrix);
matrix_complex initialization_martix_complex(matrix_complex* Matrix);
matrix_other initialization_martix_other(matrix_other* mx);

void printMatrix_int(matrix_int* Matrix);
void printMatrix_double(matrix_double* Matrix);
void printMatrix_complex(matrix_complex* Matrix);
void printMatrix_other(matrix_other* Matrix);

void chooseType(int* type);
void chooseOperation(int type, int* operation);
void conveyor(int type, int operation, matrix* RA, matrix* RB, matrix* RC);

void UI();
#endif //LAB1_UI_H