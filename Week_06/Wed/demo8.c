#include <stdio.h>
#include <mpi.h>

#include "array_util.h"

int main(int argc, char** argv)
{

    MPI_Init(&argc, &argv);

    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int nprocs;
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    int tag = 0;
    random_seed();

    int root = 7;
    double x = my_rank;                
    printf("Rank %d : My x is %f\n", my_rank, x);
    // root is the sender (node 0)
    MPI_Bcast(&x,1,MPI_DOUBLE,root,MPI_COMM_WORLD);                
    printf("Rank %d : Now my x is %f\n", my_rank, x);

    MPI_Finalize();
}
