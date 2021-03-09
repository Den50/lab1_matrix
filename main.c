#include <stdio.h>
#include <stdlib.h>
#include "OperationsMatrix.h"


// Prototypes function
matrix InitializationMartix(matrix* Matrix);
void switchOperation(matrix* MatrixA, matrix* MatrixB);

int main(void) {
    // Create two Matrix N * N
    matrix MatrixA, MatrixB, _m;
    printf("Please enter N for matrixA size of N*N: ");
    MatrixA = InitializationMartix(&MatrixA);

//    printf("Please enter N for matrixB size of M*M: ");
//    MatrixB = InitializationMartix(&MatrixB);

    printf("A ");
    PrintMatrix(&MatrixA);
    printf("\n");
//    printf("B ");
//    PrintMatrix(&MatrixB);
//    printf("\n");

    printf("%d", determinant(MatrixA));

//    matrix summedMatrix;
//    summedMatrix = Summ(&summedMatrix, &MatrixA, &MatrixB);
//    printf("Summ ");
//    PrintMatrix(&summedMatrix);


//    MatrixA = MultiplyOnNum(&MatrixA, 2.0);
//    PrintMatrix(&MatrixA);

//    matrix multMatrixAB;
//    multMatrixAB = Multiply(&multMatrixAB, &MatrixA, &MatrixB);
//    printf("Multipied matrix from A and B ");
//    PrintMatrix(&multMatrixAB);
    return 0;
}





void switchOperation(matrix* MatrixA, matrix* MatrixB){
//    char arr[3];
    printf("\nOperation: ");
//    scanf("%s", &arr);
    MatrixA->values[0][0] = 999;

//    if(arr[0] == 'A' && arr[2] == 'B' || arr[0] == 'B' && arr[2] == 'A'){
//        printf("%c", arr[1]);
//        switch(arr[1]){
//            case '+':
//                PrintMatrix(Summ(MatrixA, MatrixB));break;
//            case '*':
//                PrintMatrix(Multiply(MatrixA, MatrixB));break;
//        }
//    }

//    int n = 0;
//    while(n != -1){
//        printf("Please enter operation from list with operations: ");
//        while(scanf("%d",&n) != 1)
//        {
//            printf("Number incorrect! Please enter operation one more time: ");
//            while(getchar() != '\n');
//        }
//    }

}