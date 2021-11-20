#ifndef MX_PRODUCT_UTILS_H
#define MX_PRODUCT_UTILS_H
#include "matrix.h"

int end_clock(char* msg);

void start_clock();

int rand_i(int max);

matrix* gen_matrix(size_t __row, size_t __col);

void fill_with_rand(matrix* __matrix, size_t __len, int __max);
#endif
