#ifndef LAB1_TEST_H
#define LAB1_TEST_H
#include "UI.h"
#include "matrix.h"
#include "complex.h"
#include "algebra.h"
//#include "OperationsMatrix.h"

// test complex module
void testComplexNumbers(){
    printf("[TEST_COMPLEX_NUMBERS]\n");

    // create two complex numbers: a = 5.1 + 2.2i; b = 9.3 + 4.4i
    complex a = {5.1, 2.2, 0};
    complex b = {9.3, 4.4, 0};

    // print these numbers:
    printf("a ->");
    printComplexNumber(&a); // a -> complex(5.100 + 2.200i)
    printf("b ->");
    printComplexNumber(&b); // b -> complex(9.300 + 4.400i)

    // add complex numbers:
    complex _summ = complex_add(a, b);
    printf("summ ->");
    printComplexNumber(&_summ); // summ -> complex(14.400 + 6.600i)

    // minus complex numbers:
    complex _minus = complex_minus(a, b);
    printf("substraction ->");
    printComplexNumber(&_minus); // substraction -> complex(-4.200 + -2.200i)

    // multiply complex numbers:
    complex _multiplied = complex_multiply(a, b);
    printf("multiplied ->");
    printComplexNumber(&_multiplied); //multiplied -> complex(37.750 + 42.900i)

    // multiply complex numbers:
    complex _divisioned = complex_division(a, b);
    printf("divisioned ->");
    printComplexNumber(&_divisioned); // divisioned -> complex(0.540 + -0.019i)

    // multiply on alpha complex numbers:
    complex _divisionedOnAlpha = complex_multiplyOnAlpha(a, 0.5);
    printf("divisioned on alpha = 0.5 ->");
    printComplexNumber(&_divisionedOnAlpha); //divisioned on alpha = 0.5 -> complex(2.550 + 1.100i)
}

void __testInitMatrix_int(int size, matrix_int* mx){
    int** values;
    values = (int**)calloc(size, sizeof(int*));
    for (int i = 0; i < size; ++i) {
        values[i] = (int*)calloc(size, sizeof(int));
        for (int j = 0; j < size; ++j) {
            values[i][j] = rand() % 10;
        }
    }
    mx->MATRIX->size = size;
    mx->MATRIX->values = (void**)values;
}


void testMatrix_int(){
    printf("[TEST_MATRIX_OPERATIONS]\n");

    matrix ROOTA, ROOTB, ROOT_CONTAINER;
    struct matrix_int A = {&ROOTA};
    struct matrix_int B = {&ROOTB};
    struct matrix_int container = {&ROOT_CONTAINER, &summInt, &minusInt, &multiplyOnAlphaInt, &multiplyInt, &getDeterminantInt, &transposeMatrixInt};


    __testInitMatrix_int(3, &A);
    __testInitMatrix_int(3, &B);


    printf("\nA ");
    printMatrix_int(&A);
    printf("\nB ");
    printMatrix_int(&B);

    container.summ_int(&A, &B, &container);
    printf("\nSumm A + B ");
    printMatrix_int(&container);

    printf("\nSubstraction A - B ");
    container.minus_int(&A, &B, &container);
    printMatrix_int(&container);


    double alpha = 2.0;
    printf("\nMultiplied A on %.2f ", alpha);
    container.multiplyOnAlpha_int(&A, alpha, &container);
    printMatrix_int(&container);

    printf("\nMultiply A * B ");
    container.multiply_int(&A, &B, &container);
    printMatrix_int(&container);


//    printf("\nGet determinant A ");
//    int det = container.getDeterminant_int(&A);
//    printf("Det(A) = %d", det);

    printf("\nTranspose A ");
    container.transpose_int(&A, &container);
    printMatrix_int(&container);


//    need delete memory matrices A, B and container
//    free(&A);
//    free(&B);
//    free(&container);
}


void tests(){
    printf("[TEST]\n\n");

//    testComplexNumbers();
    testMatrix_int();
}

#endif //LAB1_TEST_H
