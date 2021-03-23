#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H
#include "string.h"
typedef struct matrix{
    void** values;
    int size;
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
//    void* (*reverseMatrix_int)(struct matrix_int* A, struct matrix_int* container);
} matrix_int;

typedef struct matrix_double{
    matrix* MATRIX;
    void* (*summ_double)(struct matrix_double* this, struct matrix_double* other, struct matrix_double* container);
    void* (*minus_double)(struct matrix_double* this, struct matrix_double* other, struct matrix_double* container);
    void* (*multiplyOnAlpha_double)(struct matrix_double* this, double alpha, struct matrix_double* container);
    void* (*multiply_double)(struct matrix_double* this, struct matrix_double* other, struct matrix_double* container);
    double* (*getDeterminant_double)(struct matrix_double* this);
    void* (*transpose_double)(struct matrix_double* A, struct matrix_double* container);
    void* (*reverseMatrix_double)(struct matrix_double* A, struct matrix_double* container);
} matrix_double;


typedef struct matrix_complex{
    matrix* MATRIX;
    void* (*summ_complex)(struct matrix_complex* this, struct matrix_complex* other, struct matrix_complex* container);
    void* (*minus_complex)(struct matrix_complex* this, struct matrix_complex* other, struct matrix_complex* container);
    void* (*multiplyOnAlpha_complex)(struct matrix_complex* this, double alpha, struct matrix_complex* container);
    void* (*multiply_complex)(struct matrix_complex* this, struct matrix_complex* other, struct matrix_complex* container);
} matrix_complex;

typedef struct matrix_other{
    matrix* MATRIX;
    void* (*summ_other)(struct matrix_other* this, struct matrix_other* other, struct matrix_other* container);
    void* (*multiplyOnAlpha_other)(struct matrix_other* this, int alpha, struct matrix_other* container);
} matrix_other;


void swap();



#endif //LAB1_MATRIX_H