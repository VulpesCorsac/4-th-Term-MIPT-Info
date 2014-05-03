#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv)
{
  int size, rank;
  char str_send[strlen("HELLO WORLD!\n")] = "Hello World!\n";
  char str_recv[strlen("HELLO WORLD!\n")];


  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  
  if (rank == 0) {
    MPI_Send(str_send, strlen(str_send) + 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
  }
  if (rank == 1) {
    MPI_Recv(str_recv, strlen("HELLO WORLD!\n") + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  printf("My rank is %d, our size is %d. %s", rank, size, str_recv);
  MPI_Finalize();
  
  return 0;
}
