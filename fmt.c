
#include "fmt.h"

#include <stdio.h>

void print_mx(const matrix* m) {
  elttype* data = m->data;
  size_t mx_size = m->row * m->col;

  int width = get_width(m->data, mx_size);

  for (size_t i = 0; i < mx_size; i += m->col) {
    printf("|");
    for (size_t j = i; j < (m->col + i); ++j) {
      printf("%*d", width, data[j]);
    }
    printf("  |\n");
    // printf("\n");
  }
  fflush(stdout);
}

size_t get_width(const elttype* items, size_t len) {
  int max = 0;
  char s[MAX_NB_LEN] = {0};

  for (size_t i = 0; i < len; ++i) {
    int l = sprintf(s, "%d", items[i]);

    max = (max < l) ? l : max;
  }

  return max + 2;
}
