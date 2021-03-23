#ifndef LAB1_ALGEBRA_H
#define LAB1_ALGEBRA_H

int pow(int base, int power){
    int res = 1;
    for (int i = 0; i < power; ++i) {
        res *= base;
    }
    return res;
}

//void swap(void *a, void *b, size_t width)
//{
//    void *temp = malloc(width);
//    memcpy(temp, b, width);
//    memcpy(b, a, width);
//    memcpy(a, temp, width);
//    free(temp);
//}
#include "algebra_int.h"
#include "algebra_double.h"
#include "algebra_complex.h"

#include "algebra_other.h"
#endif //LAB1_ALGEBRA_H