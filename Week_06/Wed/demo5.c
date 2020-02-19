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
    if (my_rank == 0)
    {
        /* Send a message to each proc! */
        for(int p = 1; p < nprocs; p++)
        {
            int tag = 0;
            int dest = p;
            {
                double x = random_number();
                printf("Sending %f to rank %d\n",x,p);
                MPI_Send(&x,1,MPI_DOUBLE,dest,tag,MPI_COMM_WORLD);
                printf("Done sending to processor %d\n",p);                
            }
        }
    }
    else if (my_rank == 1)
    {
        int sender = 0;
        {
            double x;
            printf("Processor %d is waiting to receive a message\n",my_rank);
            MPI_Recv(&x,1,MPI_DOUBLE,sender,tag,MPI_COMM_WORLD,MPI_STATUS_IGNORE); 
            printf("Rank %d received %f\n",my_rank,x);            
        }
    }

    MPI_Finalize();
}