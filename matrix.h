#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H

struct _Matrix{
    int size;
    void** values;
    void isNull;
    void isZero;
    void isOne;
    void* (*multiply)(struct _Matrix* MatrixA, struct _Matrix* MatrixB, struct _Matrix* MatrixC); // output -> C = A * B, where A, B, C <- matrices
    void* (*summ)(struct _Matrix* MatrixA, struct _Matrix* MatrixB, struct _Matrix* MatrixC);     // output -> C = A + B, where A, B, C <- matrices
    void* (*multiplyOnAlpha)(struct _Matrix* MatrixA, void* alpha, struct _Matrix* MatrixC);      // output -> C = alpha * A, where A, C <- matrix, alpha <- (int | double | float)
    void* (*getDeterminant)(struct _Matrix* Matrix);                                              // output -> det = Det(A), where det <- (int | double | float), A - matrix
    void* (*transpose)(struct _Matrix* Matrix, struct _Matrix* MatrixC);                          // output -> B = T(A), where A, B <- matrices
    void* (*reverseMatrix)(struct _Matrix* Matrix, struct _Matrix* MatrixC);                      // output -> B = A**(-1), where A, B <- matrices
};

typedef struct _Matrix matrix;


#endif //LAB1_MATRIX_H
