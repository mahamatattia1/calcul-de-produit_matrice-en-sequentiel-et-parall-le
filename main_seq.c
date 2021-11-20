#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "fmt.h"
#include "matrix.h"
#include "utils.h"

#define RAND_M 5
#define MAX_MSG_LEN 256
#define ROW1 10
#define COL1 10

#define ROW2 10
#define COL2 12

int main() {
  srand(time(NULL));

  matrix* m1 = gen_matrix(ROW1, COL1);
  if (m1 == NULL) return EXIT_FAILURE;
  fill_with_rand(m1, (ROW1 * COL1), RAND_M);

  matrix* m2 = gen_matrix(ROW2, COL2);
  if (m2 == NULL) {
    free_matrix(m1);
    return EXIT_FAILURE;
  }
  fill_with_rand(m2, ROW2 * COL2, RAND_M);

  printf("Matrice1\n");
  print_mx(m1);
  printf("\n");

  printf("Matrice2\n");
  print_mx(m2);
  char msg[MAX_MSG_LEN] = {0};

  start_clock();

  matrix* prod = matrix_p(m1, m2);

  end_clock(msg);

  if (prod != NULL) {
    printf("\n\n");
    printf("Matrice1 * Matrice2\n");
    print_mx(prod);

    free_matrix(prod);
    prod = NULL;
  }
  printf("%s\n", msg);

  free_matrix(m1);
  m1 = NULL;
  free_matrix(m2);
  m2 = NULL;

  return EXIT_SUCCESS;
}
