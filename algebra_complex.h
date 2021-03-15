#include "matrix.h"
// -----------------------------------------------------------------------------------------------------------------
// --------------------------------------------------/ Matrix Operations /------------------------------------------
// -----------------------------------------------------------------------------------------------------------------


// --------------------------------------------------------/ COMPLEX /----------------------------------------------

void summComplex(matrix_complex* A, matrix_complex* B, matrix_complex* container){
    complex **A_values, **B_values, **summed_values;
    A_values = (complex**)A->MATRIX->values;
    B_values = (complex**)B->MATRIX->values;
    int size = A->MATRIX->size;
    if(A->MATRIX->size == B->MATRIX->size){
        summed_values = (complex**)calloc(size, sizeof(complex*));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = (complex*)calloc(size, sizeof(complex));
            for (int j = 0; j < A->MATRIX->size; ++j) {
                summed_values[i][j] = complex_summ(A_values[i][j], B_values[i][j]);
            }
        }
    }else{
        container->MATRIX->isNull = 1;
    }
    container->MATRIX->size = size;
    container->MATRIX->values = (void**)summed_values;
}
void minusComplex(matrix_complex* A, matrix_complex* B, matrix_complex* container){
    complex **A_values, **B_values, **summed_values;
    A_values = (complex**)A->MATRIX->values;
    B_values = (complex**)B->MATRIX->values;
    int size = A->MATRIX->size;
    if(A->MATRIX->size == B->MATRIX->size){
        summed_values = (complex**)calloc(size, sizeof(complex*));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = (complex*)calloc(size, sizeof(complex));
            for (int j = 0; j < A->MATRIX->size; ++j) {
                summed_values[i][j] = complex_minus(A_values[i][j], B_values[i][j]);
            }
        }
    }else{
        container->MATRIX->isNull = 1;
    }
    container->MATRIX->size = size;
    container->MATRIX->values = (void**)summed_values;
}

void multiplyOnAlphaComplex(matrix_complex* Matrix, double alpha, matrix_complex* multiplied){
    // for the reason void -> double multiply double
    int size = Matrix->MATRIX->size;
    complex** valuesOrigin = (complex**)    Matrix->MATRIX->values;
    complex** valuesMult   = (complex**)multiplied->MATRIX->values;
    for (int i = 0; i < Matrix->MATRIX->size; ++i)
        for (int j = 0; j < Matrix->MATRIX->size; ++j)
            valuesMult[i][j] = complex_multiplyOnAlpha(valuesOrigin[i][j], alpha);
    multiplied->MATRIX->values = (void**)valuesMult;
}

void multiplyComplex(matrix_complex* A, matrix_complex* B, matrix_complex* Result){
    complex** valuesA       = (complex**)A->MATRIX->values;
    complex** valuesB       = (complex**)B->MATRIX->values;
    complex** valuesResult  = (complex**)Result->MATRIX->values;
    // Поскольку матрицы квадратные, имеем право проверять их на равенство size
    if(A->MATRIX->size == A->MATRIX->size){
        int size = A->MATRIX->size;
        valuesResult = (complex**)calloc(size, sizeof(complex*));
        for (int i = 0; i < size; ++i){
            valuesResult[i] = (complex*)calloc(size, sizeof(complex));
            for (int j = 0; j < size; ++j){
                for (int k = 0; k < size; ++k)
                    valuesResult[i][j] = complex_summ(valuesResult[i][j], complex_multiply(valuesA[i][k], valuesB[k][j]));
            }
        }
        Result->MATRIX->size = size;
        Result->MATRIX->values = (void**)valuesResult;
    }else{
        Result->MATRIX->isNull = 1;
    }
}