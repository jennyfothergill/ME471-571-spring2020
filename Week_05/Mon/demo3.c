#include <stdio.h>
#include <mpi.h>

#include "array_util.h"

int main(int argc, char** argv)
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
    char message[100];
    if (my_rank == 0)
    {
        /* Send a message to each proc! */
        for(int p = 1; p < nprocs; p++)
        {
            int dest = p;
<<<<<<< HEAD
            // double x = random_number();
            double x[3];
            x[0] = random_number();
            x[1] = random_number();
            x[2] = random_number();
            //printf("Sending %f to rank %d\n", x, p);
            printf("Sending %f %f %f to rank %d\n", x[0], x[1], x[2], p);
            // MPI_Send(&x, 1, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
            MPI_Send(&x, 3, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD);
=======
            double x = random_number();
            int a = 3;
            sprintf(message,"Hello Processor %d",p);
            printf("Sending %f to rank %d\n",x[0],p);
            MPI_Send(x,3,MPI_DOUBLE,dest,tag,MPI_COMM_WORLD);
>>>>>>> 3ef383a1dbd5c59753a8a87367255fd73a1d51e7
        }
    }
    else
    {
        int sender = 0;
        double x[3];
<<<<<<< HEAD
        //MPI_Recv(&x, 1, MPI_DOUBLE, sender, tag, MPI_COMM_WORLD, &status);
        MPI_Recv(&x, 3, MPI_DOUBLE, sender, tag, MPI_COMM_WORLD, &status);

// The line below is used to easily comment/uncomment code
#if 0
        int count, ierror;
        if (MPI_Get_count(&status, MPI_DOUBLE, &count) != 3)
=======
        MPI_Recv(x,3,MPI_DOUBLE,sender,tag,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
#if 0
        int count;
        int ierror = MPI_Get_count(&status,MPI_DOUBLE,&count);
        if (ierror != 0 || count != 3)
>>>>>>> 3ef383a1dbd5c59753a8a87367255fd73a1d51e7
        {
            printf()
        }
<<<<<<< HEAD
        // printf("Rank %d received %f\n", my_rank, x);
        printf("Rank %d received %f %f %f\n", my_rank, x[0], x[1], x[2]);
=======
#endif
        printf("Rank %d received %f\n",my_rank,x[0]);
>>>>>>> 3ef383a1dbd5c59753a8a87367255fd73a1d51e7
    }
# endif

    MPI_Finalize();
}
