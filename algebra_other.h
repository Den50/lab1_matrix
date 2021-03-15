#include "matrix.h"

// -----------------------------------------------------------------------------------------------------------------
// --------------------------------------------------/ Matrix Operations /------------------------------------------
// -----------------------------------------------------------------------------------------------------------------


// -----------------------------------------------/ OTHER MATRICES: string /----------------------------------------

void summOther(matrix_other* A, matrix_other* B, matrix_other* container){
    char ***A_values, ***B_values, ***summed_values;
    A_values = (char***)A->MATRIX->values;
    B_values = (char***)B->MATRIX->values;
    int size = A->MATRIX->size;
    if(A->MATRIX->size == B->MATRIX->size){
        summed_values = (char***)calloc(size, sizeof(char**));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = (char**)calloc(size, sizeof(char*));
            for (int j = 0; j < A->MATRIX->size; ++j) {
                summed_values[i][j] = strcat(A_values[i][j], B_values[i][j]);
            }
        }
    }else{
        container->MATRIX->isNull = 1;
    }
    container->MATRIX->size = size;
    container->MATRIX->values = (void**)summed_values;
}


void multiplyOnAlphaOther(matrix_other* Matrix, int alpha, matrix_other* multiplied){
    int size = Matrix->MATRIX->size;
    char*** valuesOrigin = (char***)    Matrix->MATRIX->values;
    char*** valuesMult   = (char***)multiplied->MATRIX->values;
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            valuesMult[i][j] = (char*)calloc(sizeof(valuesOrigin[i][j])*alpha + 1, sizeof(char));
            valuesMult[i][j] = "";
            for (int k = 0; k < alpha; ++k) {
                valuesMult[i][j] = strcat(valuesMult[i][j], valuesOrigin[i][j]);
            }
        }
    }
    multiplied->MATRIX->values = (void**)valuesMult;
}