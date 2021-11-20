#include "matrix.h"

#include <stdio.h>
#include <string.h>

// init allocate the memory for `matrix` of format (m, n).
// if argument is `NULL` or an error occured, the functions return `NULL`
matrix* init_mx(matrix* m) {
  if (m != NULL) {
    elttype* data = calloc((m->row * m->col), sizeof(elttype));

    if (data != NULL) {
      m->data = data;
    } else {
      return NULL;
    }
  }

  return m;
}

matrix* init_mx_d(matrix* m, const elttype* data) {
  m = init_mx(m);
  if (m != NULL) {
    memcpy(m->data, data, sizeof(elttype) * m->row * m->col);
  }

  return m;
}

matrix* new_matrix(size_t r, size_t c) {
  matrix* m = malloc(sizeof(matrix));

  if (m != NULL) {
    memset(m, 0, sizeof(matrix));
    m->data = NULL;
    m->col = c;
    m->row = r;
  }

  return m;
}

matrix* new_matrix_d(size_t r, size_t c, const elttype* data) {
  matrix* m = new_matrix(r, c);

  return init_mx_d(m, data);
}

// free_m free block allocated
void free_matrix(matrix* m) {
  if (m != NULL) {
    m->col = 0;
    m->row = 0;

    if (m->data != NULL) {
      free(m->data);
      m->data = NULL;
    }

    free(m);
  }
}

elttype* get_mx_row(const matrix* m, size_t rnum, elttype* row) {
  elttype* t_row = NULL;

  if (m != NULL && m->data != NULL) {
    if (row != NULL && rnum <= m->row) {
      t_row = row;
      memcpy(row, (m->data + (m->col * rnum)), sizeof(elttype) * m->col);
    }
  }
  return t_row;
}

elttype* get_mx_column(const matrix* m, size_t cnum, elttype* col) {
  elttype* column = NULL;

  if (m != NULL && m->data != NULL) {
    if (col != NULL && cnum <= m->col) {
      column = col;

      for (size_t i = cnum, j = 0; i < (m->col * m->row); i += m->col, ++j) {
        column[j] = m->data[i];
      }
    }
  }
  return column;
}

matrix* matrix_p(const matrix* m1, const matrix* m2) {
  if (m1 == NULL || m2 == NULL) return NULL;

  if (m1->col != m2->row) return NULL;

  if (m1->data == NULL || m2->data == NULL) return NULL;

  elttype* row = calloc(m1->col, sizeof(elttype));
  if (row == NULL) return NULL;

  elttype* col = calloc(m2->row, sizeof(elttype));
  if (col == NULL) {
    free(row);  // free row allocated
    return NULL;
  }

  matrix* mx_p = new_matrix(m1->row, m2->col);

  if (mx_p != NULL) {
    size_t mx_size = m1->row * m2->col;
    elttype* data = calloc(mx_size, sizeof(elttype));
    memset(data, 0, sizeof(elttype) * mx_size);
    mx_p->data = data;

    size_t l = 0;

    for (size_t i = 0; i < m1->row; ++i) {
      get_mx_row(m1, i, row);

      for (size_t j = 0; j < m2->col; ++j) {
        get_mx_column(m2, j, col);

        elttype sum = 0;
        size_t q = m1->col;
        for (size_t k = 0; k < q; ++k) {
          sum += (row[k] * col[k]);
        }

        mx_p->data[l] = sum;
        l++;
      }
    }
  }

  free(row);
  free(col);

  return mx_p;
