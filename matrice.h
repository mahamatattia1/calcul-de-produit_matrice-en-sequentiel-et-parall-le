#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef int elttype;

typedef struct matrix {
  size_t col;
  size_t row;
  elttype* data;
} matrix;

matrix* init_mx(matrix* __m);
matrix* init_mx_d(matrix* __m, const elttype* data);

void free_matrix(matrix* __m);

matrix* new_matrix(size_t __r, size_t __c);
matrix* new_matrix_d(size_t __r, size_t __c, const elttype* __data);

elttype* get_mx_row(const matrix* __m, size_t __rnum, elttype* __row);

elttype* get_mx_column(const matrix* __m, size_t __cnum, elttype* __col);

matrix* matrix_p(const matrix* __m1, const matrix* __m2);

#endif
