#ifndef LAB1_UI_H
#define LAB1_UI_H


matrix InitializationMartix(matrix* Matrix){
    scanf("%d", &Matrix->size);
    Matrix->values = (int**)malloc(Matrix->size * sizeof(int*));

    for (int i = 0; i < Matrix->size; ++i) {
        Matrix->values[i] = (int*)malloc(Matrix->size * sizeof(int));
        for (int j = 0; j < Matrix->size; ++j) {
            scanf("%d", &Matrix->values[i][j]);
        }
    }
    return *Matrix;
}



#endif //LAB1_UI_H
