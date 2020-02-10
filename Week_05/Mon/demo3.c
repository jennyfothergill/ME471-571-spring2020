#include <stdio.h>
#include <mpi.h>

#include "array_util.h"

void main(int argc, char** argv)
{
    /* MPI variables */
    MPI_Status status;

    MPI_Init(&argc, &argv);

    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int nprocs;
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    int tag = 0;
    random_seed();
    if (my_rank == 0)
    {
        /* Send a message to each proc! */
        for(int p = 1; p < nprocs; p++)
        {
            int dest = p;
            double x[3];
            x[0] = random_number();
            x[1] = random_number();
            x[2] = random_number();
            printf("Sending %f to rank %d\n",x[0],p);
            MPI_Send(x,3,MPI_DOUBLE,dest,tag,MPI_COMM_WORLD);
        }
    }
    else
    {
        int sender = 0;
        double x[3];
        MPI_Recv(x,2,MPI_DOUBLE,sender,tag,MPI_COMM_WORLD,&status);
#if 1        
        int count;
        int ierror = MPI_Get_count(&status,MPI_DOUBLE,&count);
        if (count != 3)
        {
            printf("ierror = %d; Did not receive all info\n",ierror);
            exit(0);
        }
#endif        
        printf("Rank %d received %f\n",my_rank,x[0]);
    }

    MPI_Finalize();
}