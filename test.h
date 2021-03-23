#ifndef LAB1_TEST_H
#define LAB1_TEST_H
#include "UI.h"
#include "matrix.h"
#include "complex.h"
#include "algebra_int.h"
#include "algebra_double.h"
#include "algebra_complex.h"
#include "algebra_other.h"
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
    complex _summ = complex_summ(a, b);
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

void __testInitMatrix_double(int size, matrix_double* mx){
    double** values;
    values = (double**)calloc(size, sizeof(double*));
    for (int i = 0; i < size; ++i) {
        values[i] = (double*)calloc(size, sizeof(double));
        for (int j = 0; j < size; ++j) {
            values[i][j] = (double)(rand() % 10) + (double)(rand() % 100) / 100;
        }
    }
    mx->MATRIX->size = size;
    mx->MATRIX->values = (void**)values;
}

void __testInitMatrix_complex(int size, matrix_complex* mx){
    complex** values;
    values = (complex**)calloc(size, sizeof(complex*));
    for (int i = 0; i < size; ++i) {
        values[i] = (complex*)calloc(size, sizeof(complex));
        for (int j = 0; j < size; ++j) {
            double randDouble1 = (double)((rand() % 10) +  (double)(rand() % 100) / 100);
            double randDouble2 = (double)((rand() % 10) +  (double)(rand() % 100) / 100);
            values[i][j] = createComplex(randDouble1, randDouble2, &values[i][j]);
        }
    }
    mx->MATRIX->size = size;
    mx->MATRIX->values = (void**)values;
}


static char *rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}
char* rand_string_alloc(size_t size)
{
    char *s = malloc(size + 1);
    if (s) {
        rand_string(s, size);
    }
    return s;
}
void __testInitMatrix_other(int size, int length, matrix_other* mx){
    char*** values = (char***)calloc(size, sizeof(char*));
    for (int i = 0; i < size; ++i) {
        values[i] = (char**)calloc(size, sizeof(char*));
        for (int j = 0; j < size; ++j) {
            values[i][j] = (char*)calloc(length, sizeof(char));
            // put random count letters
            values[i][j] = rand_string_alloc(length);
            printf("\n");
        }
    }
    mx->MATRIX->size = size;
    mx->MATRIX->values = (void**)values;
}

void testMatrix_int(){

    printf("[TEST_MATRIX_OPERATIONS_INT]");
    matrix ROOT_A, ROOT_B, ROOT_CONTAINER_INT;
    struct matrix_int A = {&ROOT_A};
    struct matrix_int B = {&ROOT_B};
    struct matrix_int container_int = {
            &ROOT_CONTAINER_INT,
            &summInt,
            &minusInt,
            &multiplyOnAlphaInt,
            &multiplyInt,
            &getDeterminantInt,
            &transposeMatrixInt
    };


    __testInitMatrix_int(3, &A);
    __testInitMatrix_int(3, &B);


    printf("\nA ");
    printMatrix_int(&A);
    printf("\nB ");
    printMatrix_int(&B);

    container_int.summ_int(&A, &B, &container_int);
    printf("\nSumm A + B ");
    printMatrix_int(&container_int);

    printf("\nSubstraction A - B ");
    container_int.minus_int(&A, &B, &container_int);
    printMatrix_int(&container_int);


    int alpha = 2;
    printf("\nMultiplied A on %d ", alpha);
    container_int.multiplyOnAlpha_int(&A, alpha, &container_int);
    printMatrix_int(&container_int);

    printf("\nMultiply A * B ");
    container_int.multiply_int(&A, &B, &container_int);
    printMatrix_int(&container_int);


    printf("\nGet determinant A ");
    int det = container_int.getDeterminant_int(&A);
    printf("\nDet(A) = %d\n", det);


    printf("\nTranspose A ");
    container_int.transpose_int(&A, &container_int);
    printMatrix_int(&container_int);


//    need delete memory matrices A, B and container
//    free(&A);
//    free(&B);
//    free(&container);
}
void testMatrix_double(){
    printf("\n[TEST_MATRIX_OPERATIONS_DOUBLE]");


    matrix ROOT_C, ROOT_D, ROOT_CONTAINER;
    struct matrix_double C = {&ROOT_C};
    struct matrix_double D = {&ROOT_D};
    struct matrix_double container_double = {
            &ROOT_CONTAINER,
            &summDouble,
            &minusDouble,
            &multiplyOnAlphaDouble,
            &multiplyDouble,
            &getDeterminantDouble,
            &transposeMatrixDouble,
            &reverseMatrixDouble
    };


    __testInitMatrix_double(3, &C);
    __testInitMatrix_double(3, &D);

    printf("\nC ");
    printMatrix_double(&C);
    printf("\nB ");
    printMatrix_double(&D);

    container_double.summ_double(&C, &D, &container_double);
    printf("\nSumm C + D ");
    printMatrix_double(&container_double);

    printf("\nSubstraction C - D ");
    container_double.minus_double(&C, &D, &container_double);
    printMatrix_double(&container_double);

    double alpha = 3.1;
    printf("\nMultiplied C on %.2f ", alpha);
    container_double.multiplyOnAlpha_double(&C, alpha, &container_double);
    printMatrix_double(&container_double);

    printf("\nMultiply C * D ");
    container_double.multiply_double(&C, &D, &container_double);
    printMatrix_double(&container_double);

    printf("\nGet determinant C ");
    double* det = container_double.getDeterminant_double(&C);
    printf("\nDet(C) = %.2f\n", det);

    printf("\nTranspose C ");
    container_double.transpose_double(&C, &container_double);
    printMatrix_double(&container_double);

    printf("\nReversed C ");
    container_double.reverseMatrix_double(&C, &container_double);
    printMatrix_double(&container_double);
}
void testMatrix_complex(){
    printf("\n[TEST_MATRIX_OPERATIONS_COMPLEX]");


    int size = 3;
    matrix ROOT_A, ROOT_B, ROOT_CONTAINER;
    struct matrix_complex A = {&ROOT_A};
    struct matrix_complex B = {&ROOT_B};
    struct matrix_complex container_complex = {
            &ROOT_CONTAINER,
            &summComplex,
            &minusComplex,
            &multiplyOnAlphaComplex,
            &multiplyComplex
    };

    container_complex.MATRIX->size = size;
    __testInitMatrix_complex(size, &A);
    __testInitMatrix_complex(size, &B);

    printf("\nA ");
    printMatrix_complex(&A);
    printf("\nB ");
    printMatrix_complex(&B);

    printf("\nMatrix A + B ");
    container_complex.summ_complex(&A, &B, &container_complex);
    printMatrix_complex(&container_complex);

    printf("\nMatrix A - B ");
    container_complex.minus_complex(&A, &B, &container_complex);
    printMatrix_complex(&container_complex);

    double alpha = 3.1;
    printf("\nMultiply on alpha = %.2f ", alpha);
    container_complex.multiplyOnAlpha_complex(&A, alpha, &container_complex);
    printMatrix_complex(&container_complex);

    printf("\nMatrix A * B ");
    container_complex.multiply_complex(&A, &B, &container_complex);
    printMatrix_complex(&container_complex);

}
void testMatrix_other(){
    printf("\n[TEST_MATRIX_OPERATIONS_OTHERTYPES]");

    int size = 3;
    int length = 10;
    matrix ROOT_A, ROOT_B, ROOT_CONTAINER;
    struct matrix_other A = {&ROOT_A};
    struct matrix_other B = {&ROOT_B};
    struct matrix_other container_other = {
            &ROOT_CONTAINER,
            &summOther,
            &multiplyOnAlphaOther
    };

    container_other.MATRIX->size = size;
    __testInitMatrix_other(size, length, &A);
    __testInitMatrix_other(size, length, &B);

    printf("\nA ");
    printMatrix_other(&A);
    printf("\nB ");
    printMatrix_other(&B);

    printf("\nMatrix A + B (concat)\n");
    container_other.summ_other(&A, &B, &container_other);
    printMatrix_other(&container_other);

    printMatrix_other(&A);
    int alpha = 2;
    printf("\nMatrix A * alpha = %d\n", alpha);
    container_other.multiplyOnAlpha_other(&A, alpha, &container_other);
    printMatrix_other(&container_other);



}
void tests(){
    printf("[TEST]\n\n");


//    testComplexNumbers();

    printf("[TEST_MATRIX_OPERATIONS]\n\n");
    testMatrix_int();
    testMatrix_double();
    testMatrix_complex();
    testMatrix_other();

}

#endif //LAB1_TEST_H