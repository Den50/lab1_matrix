cmake_minimum_required(VERSION 3.17)
project(lab1 C)


set(CMAKE_C_STANDARD 11)
add_executable(lab1 main.c matrix.h errorExceptions.h test.h UI.h complex.h algebra.h algebra_int.h algebra_double.h algebra_complex.h algebra_other.h)
