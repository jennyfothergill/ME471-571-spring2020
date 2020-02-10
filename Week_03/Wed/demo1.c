#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv)
{
    MPI_Status status;
    MPI_Init(&argc, &argv);

    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int nprocs;
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    int tag = 0;
    if (my_rank == 0)
    {
        for(int p =1; p < nprocs; p++)
        {
            int dest = p;
            char message[100];
            sprintf(message, "Hello processor %d!\n", my_rank);
            MPI_Send(message, strlen(message)+1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
        }
    }
    else
    {
        int sender = 0;
        int count;
        char message[100];
        MPI_Recv(message, 100, MPI_CHAR, sender, tag, MPI_COMM_WORLD, &status);
        printf("Rank %d : %s", my_rank, message); 
    }
     
    MPI_Finalize();

}
