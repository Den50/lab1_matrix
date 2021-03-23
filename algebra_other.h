#ifndef LAB1_ALGEBRA_OTHER_H
#define LAB1_ALGEBRA_OTHER_H

#include "matrix.h"

// -----------------------------------------------------------------------------------------------------------------
// --------------------------------------------------/ Matrix Operations /------------------------------------------
// -----------------------------------------------------------------------------------------------------------------


// -----------------------------------------------/ OTHER MATRICES: string /----------------------------------------
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void summOther(matrix_other* A, matrix_other* B, matrix_other* container){
    int size = A->MATRIX->size;
    char ***A_values, ***B_values, ***summed_values;
    A_values = (char***)A->MATRIX->values;
    B_values = (char***)B->MATRIX->values;
    if(A->MATRIX->size == B->MATRIX->size){
        summed_values = (char***)calloc(size, sizeof(char**));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = (char**)calloc(size, sizeof(char*));
            for (int j = 0; j < size; ++j) {
                char tmp[20];
//                strcpy(tmp, A_values[i][j]);
//                strcat("ddf", tmp);
//                printf("%s", tmp);
//                summed_values[i][j] = "Adsdf";
                summed_values[i][j] = concat(A_values[i][j], B_values[i][j]);
//                strcpy(A_values[i][j], tmp);
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
            for (int k = 0; k < alpha; ++k) {
                valuesMult[i][j] = strcat(valuesMult[i][j], valuesOrigin[i][j]);
            }
        }
    }
    multiplied->MATRIX->values = (void**)valuesMult;
}

#endif //LAB1_ALGEBRA_OTHER_H