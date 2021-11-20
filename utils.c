#include "utils.h"

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>

#include "string.h"

static clock_t st_time;
static clock_t en_time;
static struct tms st_cpu;
static struct tms en_cpu;

void start_clock() { st_time = times(&st_cpu); }

int end_clock(char* msg) {
  en_time = times(&en_cpu);

  return sprintf(msg,
                 "\n==> Real Time: %jd, User Time %jd, System Time %jd <==\n\n",
                 (intmax_t)(en_time - st_time),
                 (intmax_t)(en_cpu.tms_utime - st_cpu.tms_utime),
                 (intmax_t)(en_cpu.tms_stime - st_cpu.tms_stime));
}

matrix* gen_matrix(size_t row, size_t col) {
  matrix* m = malloc(sizeof(matrix));

  if (m != NULL) {
    memset(m, 0, sizeof(matrix));
    m->data = NULL;

    elttype* data = calloc(row * col, sizeof(elttype));
    if (data != NULL) {
      memset(data, 0, sizeof(elttype) * (row * col));
      m->row = row;
      m->col = col;
      m->data = data;
    } else {
      free_matrix(m);
      m = NULL;
    }
  }

  return m;
}

void fill_with_rand(matrix* m, size_t len, int max) {
  for (size_t i = 0; i < len; ++i) {
    m->data[i] = (elttype)rand_i(max);
  }
}

int rand_i(int max) { return rand() % max; }
