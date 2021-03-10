#ifndef LAB1_OPERATIONSMATRIX_H
#define LAB1_OPERATIONSMATRIX_H
#include "matrix.h"

int pow(int base, int power){
    int res = 1;
    for (int i = 0; i < power; ++i) {
        res *= base;
    }
    return res;
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

// -----------------------------------------------------------------------------------------------------------------
// --------------------------------------------------/ Matrix Operations /------------------------------------------
// -----------------------------------------------------------------------------------------------------------------


// --------------------------------------------------------/ INT /--------------------------------------------------




void summInt(matrix_int* A, matrix_int* B, matrix_int* summed){
    int **A_values, **B_values, **summed_values;
    A_values = (int**)A->MATRIX->values;
    B_values = (int**)B->MATRIX->values;
    int size = A->MATRIX->size;
    if(A->MATRIX->size == B->MATRIX->size){
        summed_values = (int**)calloc(size, sizeof(int*));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = (int*)calloc(size, sizeof(int));
            for (int j = 0; j < A->MATRIX->size; ++j) {
                summed_values[i][j] = A_values[i][j] + B_values[i][j];
            }
        }
    }else{
        summed->MATRIX->isNull = 1;
    }
    summed->MATRIX->values = (void**)summed_values;
    summed->MATRIX->size = size;

//    free(A_values);
//    free(B_values);
}

void minusInt(matrix_int* A, matrix_int* B, matrix_int* summed){
    int **A_values, **B_values, **summed_values;
    A_values = (int**)A->MATRIX->values;
    B_values = (int**)B->MATRIX->values;
    int size = A->MATRIX->size;
    if(A->MATRIX->size == B->MATRIX->size){
        summed_values = (int**)calloc(size, sizeof(int*));
        for (int i = 0; i < size; ++i) {
            summed_values[i] = (int*)calloc(size, sizeof(int));
            for (int j = 0; j < A->MATRIX->size; ++j) {
                summed_values[i][j] = A_values[i][j] - B_values[i][j];
            }
        }
    }else{
        summed->MATRIX->isNull = 1;
    }
    summed->MATRIX->values = (void**)summed_values;
    summed->MATRIX->size = size;

//    free(A_values);
//    free(B_values);
}


void multiplyOnAlphaInt(matrix_int* Matrix, double alpha, matrix_int* multiplied){
    // for the reason void -> double multiply double
    double** valuesOrigin = (double**)    Matrix->MATRIX->values;
    double** valuesMult   = (double**)multiplied->MATRIX->values;
    for (int i = 0; i < Matrix->MATRIX->size; ++i)
        for (int j = 0; j < Matrix->MATRIX->size; ++j)
            valuesMult[i][j] = valuesOrigin[i][j] * alpha;

    multiplied->MATRIX->values = (void**)valuesMult;

//    free(valuesMult);
//    free(valuesOrigin);
}

void multiplyInt(matrix_int* A, matrix_int* B, matrix_int* Result){
    int** valuesA       = (int**)A->MATRIX->values;
    int** valuesB       = (int**)B->MATRIX->values;
    int** valuesResult  = (int**)Result->MATRIX->values;
    // Поскольку матрицы квадратные, имеем право проверять их на равенство size
    if(A->MATRIX->size == A->MATRIX->size){
        int size = A->MATRIX->size;
        Result->MATRIX->values = (int**)calloc(size, sizeof(int*));
        for (int i = 0; i < size; ++i){
            Result->MATRIX->values[i] = (int*)calloc(size, sizeof(int));
            for (int j = 0; j < size; ++j){
                for (int k = 0; k < size; ++k)
                    valuesResult[i][j] += valuesA[i][k] * valuesB[k][j];
            }
        }
        Result->MATRIX->size = size;
        Result->MATRIX->values = (void**)valuesResult;
    }else{
        Result->MATRIX->isNull = 1;
    }
}

matrix_int __getMatrixWithoutRowAndCol(matrix_int* MatrixA, int row, int col, matrix_int* newMatrix) {
    int offsetRow = 0; //Смещение индекса строки в матрице
    int offsetCol = 0; //Смещение индекса столбца в матрице
    int size = MatrixA->MATRIX->size - 1;
    int** valuesA = (int**)MatrixA->MATRIX->values;
    int** valuesNew = (int**)calloc((size - 1), sizeof(int*));
    for(int i = 0; i < size - 1; i++) {
        //Пропустить row-ую строку
        if(i == row) {
            offsetRow = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
        }
        offsetCol = 0; //Обнулить смещение столбца
        valuesNew[i] = (int*)calloc((size - 1), sizeof(int));
        for(int j = 0; j <  - 1; j++) {
            //Пропустить col-ый столбец
            if(j == col) {
                offsetCol = 1; //Встретили нужный столбец, проускаем его смещением
            }
            valuesNew[i][j] = valuesA[i + offsetRow][j + offsetCol];
        }
    }
    newMatrix->MATRIX->size = size;
    newMatrix->MATRIX->values = (void**)valuesNew;

    return *newMatrix;
}


int getDeterminantInt(matrix_int MatrixA) {
    int size = MatrixA.MATRIX->size;
    int** values = (int**)MatrixA.MATRIX->values;

    if (MatrixA.MATRIX->size == 2) {
        return values[0][0] * values[1][1] - values[0][1] * values[1][0];
    } else {
        int res = 0;
        for (int i = 0; i < size; ++i) {
            int itemMult = values[i][0];
            printf("Run function and res = %d, size = %d, itemMult = %d", res, size, itemMult);
            matrix_int subMatrix;
            subMatrix = __getMatrixWithoutRowAndCol(&MatrixA, i, 0, &subMatrix);
            printMatrix_int(&subMatrix);
            res += pow(-1, i) * itemMult * getDeterminantInt(subMatrix);
        }
        return res;
    }
}

void transposeMatrixInt(matrix_int* MatrixA, matrix_int* Result){
    void** values = MatrixA->MATRIX->values;
    int size = MatrixA->MATRIX->size;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            if(i != j){
                swap(&values[i][j], &values[j][i]);
            }
        }
    }
    Result->MATRIX->size = size;
    Result->MATRIX->values = values;
}

//matrix reverseMatrixInt(matrix_int* MatrixA){
//    int detA = getDeterminantInt(*MatrixA);
//    matrix reversedMatrix;
//    reversedMatrix.size = MatrixA.size;
//    if(detA != 0){
//        reversedMatrix.values = (int**)calloc(reversedMatrix.size, sizeof(int*));
//        for (int i = 0; i < reversedMatrix.size; ++i) {
//            reversedMatrix.values[i] = (int*)calloc(reversedMatrix.size, sizeof(int));
//            for (int j = 0; j < reversedMatrix.size; ++j) {
//                matrix AlgAdd;
//                AlgAdd = getMatrixWithoutRowAndCol(&MatrixA, i, j, &AlgAdd);
//                int tmpDet = determinant(AlgAdd);
//                reversedMatrix.values[i][j] = pow(-1, i + j) * tmpDet;
//            }
//        }
//
//        return transposeMatrix(&(MultiplyOnNum(&reversedMatrix, 1.0/(double)detA)));
//    }else{
//        matrix IsNull;
//        IsNull.isNull = 1;
//        return IsNull;
//    }
//}


#endif //LAB1_OPERATIONSMATRIX_H
