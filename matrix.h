#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H


typedef struct matrix{
    int size;
    void** values;
    int isNull;
    int isZero;
    int isOne;
} matrix;



// typedef void (*initMatrix)(matrix* A);                                              // initialization matrix
// typedef matrix (*summ)(matrix* MatrixA, matrix* MatrixB, matrix* MatrixC);          // output -> C = A + B, where A, B, C <- matrices
// typedef void (*minus)(matrix* MatrixA, matrix* MatrixB, matrix* MatrixC);           // output -> C = A - B, where A, B, C <- matrices
// typedef void (*multiply)(matrix* MatrixA, matrix* MatrixB, matrix* MatrixC);        // output -> C = A * B, where A, B, C <- matrices
// typedef void (*multiplyOnAlpha)(matrix* MatrixA, void* alpha, matrix* MatrixC);     // output -> C = alpha * A, where A, C <- matrix, alpha <- (int | double | float)
// typedef void (*getDeterminant)(matrix* Matrix);                                     // output -> det = Det(A), where det <- (int | double | float), A - matrix
// typedef void (*transpose)(matrix* Matrix, matrix* MatrixC);                         // output -> B = T(A), where A, B <- matrices
// typedef void (*reverseMatrix)(matrix* Matrix, matrix* MatrixC);                     // output -> B = A**(-1), where A, B <- matrices

// SHELLS

typedef struct matrix_int{
    matrix* MATRIX;
//    initMatrix initMatrix_int;
    void* (*summ_int)(struct matrix_int* this, struct matrix_int* other, struct matrix_int* container);
    void* (*minus_int)(struct matrix_int* this, struct matrix_int* other, struct matrix_int* container);
    void* (*multiplyOnAlpha_int)(struct matrix_int* this, double alpha, struct matrix_int* container);
    void* (*multiply_int)(struct matrix_int* this, struct matrix_int* other, struct matrix_int* container);
    int*  (*getDeterminant_int)(struct matrix_int* this);
    void* (*transpose_int)(struct matrix_int* A, struct matrix_int* container);
    void* (*reverseMatrix_int)(struct matrix_int* A, struct matrix_int* container);
} matrix_int;

//typedef struct{
//    matrix* MATRIX;
//    initMatrix initMatrix_double;
//    summ summ_double;
//    minus minus_double;
//    multiply multiply_double;
//    multiplyOnAlpha multiplyOnAlpha_double;
//    getDeterminant getDeterminant_double;
//    transpose transpose_double;
//    reverseMatrix reverseMatrix_double;
//} matrix_double;
//
//typedef struct{
//    matrix* MATRIX;
//    initMatrix initMatrix_complex;
//    summ summ_complex;
//    minus minus_complex;
//    multiply multiply_complex;
//    multiplyOnAlpha multiplyOnAlpha_complex;
//} matrix_complex;
//
//typedef struct{
//    matrix* MATRIX;
//    initMatrix initMatrix_other;
//    summ summ_other;
//    multiplyOnAlpha multiplyOnAlpha_other;
//} matrix_other;





#endif //LAB1_MATRIX_H
