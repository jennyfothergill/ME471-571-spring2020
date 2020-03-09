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
        int dest = 1;
        {
<<<<<<< HEAD
            int dest = p;
            {
                int tag = 0;
                double x = random_number();
                printf("Sending %f to rank %d\n",x,p);
                MPI_Send(&x,1,MPI_DOUBLE,dest,tag,MPI_COMM_WORLD);
                printf("Done sending to processor %d\n",p);                
            }
            {
                int tag = 1;
                int a = 12345;
                printf("Sending %d to rank %d\n",a,p);
                MPI_Send(&a,1,MPI_INTEGER,dest,tag,MPI_COMM_WORLD);
                printf("Done sending to processor %d\n",p);                
            }
=======
            int tag = 0;
            double x = random_number();
            printf("Sending %f to rank %d\n",x,dest);
            MPI_Send(&x,1,MPI_DOUBLE,dest,tag,MPI_COMM_WORLD);
            printf("Done sending to processor %d\n",dest);                
        }
        {
            int tag = 1;
            int a = 12345;
            printf("Sending %d to rank %d\n",a,dest);
            MPI_Send(&a,1,MPI_INTEGER,dest,tag,MPI_COMM_WORLD);
            printf("Done sending %d to rank %d\n",a,dest);
>>>>>>> 3ef383a1dbd5c59753a8a87367255fd73a1d51e7
        }
    }
    else if (my_rank == 1)
    {
        int sender = 0;
        {
            int tag = 1;
            int a;
            printf("Processor %d is waiting to receive an int\n",my_rank);
            MPI_Recv(&a,1,MPI_INTEGER,sender,tag,MPI_COMM_WORLD,MPI_STATUS_IGNORE); 
            printf("Rank %d received %d\n",my_rank,a);            
        }
        {
<<<<<<< HEAD
            double x;
            int tag = 0;
=======
            int tag = 0;
            double x;
>>>>>>> 3ef383a1dbd5c59753a8a87367255fd73a1d51e7
            printf("Processor %d is waiting to receive a double\n",my_rank);
            MPI_Recv(&x,1,MPI_DOUBLE,sender,tag,MPI_COMM_WORLD,MPI_STATUS_IGNORE); 
            printf("Rank %d received %f\n",my_rank,x);            
        }
    }

    MPI_Finalize();
}
