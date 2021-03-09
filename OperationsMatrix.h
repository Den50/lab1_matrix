#ifndef LAB1_OPERATIONSMATRIX_H
#define LAB1_OPERATIONSMATRIX_H



//
// Standart functions
//
int pow(int base, int power){
    int res = 1;
    for (int i = 0; i < power; ++i) {
        res *= base;
    }
    return res;
}

void PrintMatrix(matrix* Matrix){
    printf("Matrix:  \n");
    for (int i = 0; i < Matrix->size; ++i) {
        for(int j = 0; j < Matrix->size; ++j){
            printf("%d ", Matrix->values[i][j]);
        }
        printf("\n");
    }
}
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

//
// functions for matrix operations
//
matrix Summ(matrix* summedMatrix, matrix* _matrixA, matrix* _matrixB){
    if(_matrixA->size == _matrixB->size){
        summedMatrix->size = _matrixA->size;
        summedMatrix->values = (int**)calloc(_matrixA->size, sizeof(int*));
        for (int i = 0; i < _matrixA->size; ++i) {
            summedMatrix->values[i] = (int*)calloc(_matrixA->size, sizeof(int));
            for (int j = 0; j < _matrixA->size; ++j) {
                summedMatrix->values[i][j] = _matrixA->values[i][j] + _matrixB->values[i][j];
            }
        }
    }else{
//        summedMatrix->isNull = 1;
    }

    return *summedMatrix;
}

matrix MultiplyOnNum(matrix* Matrix, double alpha){
    for (int i = 0; i < Matrix->size; ++i)
        for (int j = 0; j < Matrix->size; ++j)
            Matrix->values[i][j] *= alpha;
    return *Matrix;
}

matrix Multiply(matrix* ResultMatrix,matrix* MatrixA, matrix* MatrixB){
    // Поскольку матрицы квадратные, имеем право проверять их на равенство size
    if(MatrixA->size == MatrixB->size){
        ResultMatrix->size = MatrixA->size;
        ResultMatrix->values = (int**)malloc(ResultMatrix->size * sizeof(int*));
        for (int i = 0; i < MatrixB->size; ++i){
            ResultMatrix->values[i] = (int*)malloc(ResultMatrix->size * sizeof(int));
            for (int j = 0; j < MatrixB->size; ++j){
                ResultMatrix->values[i][j] = 0;
                for (int k = 0; k < MatrixB->size; ++k)
                    ResultMatrix->values[i][j] += MatrixA->values[i][k] * MatrixB->values[k][j];
            }
        }
    }else{
//        ResultMatrix->isNull = 1;
    }
    return *ResultMatrix;
}


matrix getMatrixWithoutRowAndCol(matrix* MatrixA, int row, int col, matrix* newMatrix) {
    int offsetRow = 0; //Смещение индекса строки в матрице
    int offsetCol = 0; //Смещение индекса столбца в матрице
    newMatrix->size = MatrixA->size - 1;
    newMatrix->values = (int**)calloc((MatrixA->size - 1), sizeof(int*));
    for(int i = 0; i < MatrixA->size-1; i++) {
        //Пропустить row-ую строку
        if(i == row) {
            offsetRow = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
        }
        offsetCol = 0; //Обнулить смещение столбца
        newMatrix->values[i] = (int*)calloc((MatrixA->size - 1), sizeof(int));
        for(int j = 0; j < MatrixA->size-1; j++) {
            //Пропустить col-ый столбец
            if(j == col) {
                offsetCol = 1; //Встретили нужный столбец, проускаем его смещением
            }
            newMatrix->values[i][j] = MatrixA->values[i + offsetRow][j + offsetCol];
        }
    }
    return *newMatrix;
}


int determinant(matrix MatrixA) {
    if (MatrixA.size == 2) {
        return MatrixA.values[0][0] * MatrixA.values[1][1] - MatrixA.values[0][1] * MatrixA.values[1][0];
    } else {
        int res = 0;
        for (int i = 0; i < MatrixA.size; ++i) {
            int itemMult = MatrixA.values[i][0];
            matrix subMatrix;
            subMatrix = getMatrixWithoutRowAndCol(&MatrixA, i, 0, &subMatrix);
            res += pow(-1, i) * itemMult * determinant(subMatrix);
        }
        return res;
    }
}

matrix transposeMatrix(matrix* MatrixA){
    for (int i = 0; i < MatrixA->size; ++i) {
        for (int j = i; j < MatrixA->size; ++j) {
            if(i != j){
                swap(&MatrixA->values[i][j], &MatrixA->values[j][i]);
            }
        }
    }
    return *MatrixA;
}

matrix reverseMatrix(matrix MatrixA){
    int detA = determinant(MatrixA);
    matrix reversedMatrix;
    reversedMatrix.size = MatrixA.size;
    if(detA != 0){
        reversedMatrix.values = (int**)calloc(reversedMatrix.size, sizeof(int*));
        for (int i = 0; i < reversedMatrix.size; ++i) {
            reversedMatrix.values[i] = (int*)calloc(reversedMatrix.size, sizeof(int));
            for (int j = 0; j < reversedMatrix.size; ++j) {
                matrix AlgAdd;
                AlgAdd = getMatrixWithoutRowAndCol(&MatrixA, i, j, &AlgAdd);
                int tmpDet = determinant(AlgAdd);
                reversedMatrix.values[i][j] = pow(-1, i + j) * tmpDet;
            }
        }

        return transposeMatrix(&(MultiplyOnNum(&reversedMatrix, 1.0/(double)detA)));
    }else{
        matrix IsNull;
        IsNull.isNull = 1;
        return IsNull;
    }
}


#endif //LAB1_OPERATIONSMATRIX_H
