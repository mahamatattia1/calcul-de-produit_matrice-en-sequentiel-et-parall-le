#ifndef FMT_H
#define FMT_H

#include "matrix.h"

#define MAX_NB_LEN 16

void print_mx(const matrix* __m);

size_t get_width(const elttype* __items, size_t __len);

#endif
