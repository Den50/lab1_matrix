#ifndef LAB1_UI_H
#define LAB1_UI_H
#include "matrix.h"

matrix_int initializationMartix_int(matrix_int* Matrix){
    int** values;
    int size;
    Matrix->MATRIX = (matrix*)calloc(1, sizeof(matrix));

    printf("Enter count elements: \n");
    scanf("%d", &size);

    values = (int**)calloc(size, sizeof(int*));
    Matrix->MATRIX->values = (void**)calloc(size, sizeof(void*));

    printf("Enter values for matrix: \n");
    for (int i = 0; i < size; ++i) {
        values[i] = (int*)calloc(size, sizeof(int));
        Matrix->MATRIX->values[i] = (void*)calloc(size, sizeof(void));
        for (int j = 0; j < size; ++j) {
            scanf("%d", &(values[i][j]));
        }
    }
    Matrix->MATRIX->values = values;
    Matrix->MATRIX->size = size;
    return *Matrix;
}

void printMatrix_int(matrix_int* Matrix){
    int** values = (int**)Matrix->MATRIX->values;

    printf("matrix:  \n");
    for (int i = 0; i < Matrix->MATRIX->size; ++i) {
        for(int j = 0; j < Matrix->MATRIX->size; ++j){
            printf("%d ", values[i][j]);
        }
        printf("\n");
    }
}


// -----------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------/ UI /----------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------


void chooseType(int* type){
    printf("Choose type for elements: \n");
    printf("1. Int \n");
    printf("2. Double \n");
    printf("3. Complex \n");
    printf("4. Other \n");
    scanf("%d", &type);
}

void chooseOperation_int(int* operation){
    printf("Choose operation for elements: \n");
    printf("1. Summ \n");
    printf("2. Minus \n");
    printf("3. Multiply \n");
    printf("4. Multiply on alpha \n");
    printf("5. Get determinant \n");
    printf("6. Get transpose matrix \n");
    printf("7. Get reverse matrix \n");
    scanf("%d", &operation);
}






#endif //LAB1_UI_H
