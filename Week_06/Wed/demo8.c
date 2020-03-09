#include <stdio.h>
#include <mpi.h>

#include "array_util.h"

int main(int argc, char** argv)
{
<<<<<<< HEAD

=======
>>>>>>> 3ef383a1dbd5c59753a8a87367255fd73a1d51e7
    MPI_Init(&argc, &argv);

    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int nprocs;
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    random_seed();

<<<<<<< HEAD
    int root = 7;
    double x = my_rank;                
    printf("Rank %d : My x is %f\n", my_rank, x);
    // root is the sender (node 0)
    MPI_Bcast(&x,1,MPI_DOUBLE,root,MPI_COMM_WORLD);                
    printf("Rank %d : Now my x is %f\n", my_rank, x);

=======
    double x;                
    if (my_rank == 0)
    {
        x = 3.14158;    
    }
    //printf("Rank %d : My value is %e\n",my_rank,x);
    int root = 0;
    MPI_Bcast(&x,1,MPI_DOUBLE,root,MPI_COMM_WORLD);         
             
    printf("Rank %d : Now my value is %f\n",my_rank,x);
>>>>>>> 3ef383a1dbd5c59753a8a87367255fd73a1d51e7
    MPI_Finalize();
}
