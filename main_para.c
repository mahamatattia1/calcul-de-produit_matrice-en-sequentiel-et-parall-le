#include <mpi/mpi.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int comm_size;
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    MPI_Finalize();
}
