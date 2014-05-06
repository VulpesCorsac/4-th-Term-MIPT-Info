#include <stdio.h>
#include <mpi.h>
#include <math.h>

// MPI_Send(void *msg, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm);
// MPI_Comm_rank();
// MPI_FLOAT
// MPI_STATUS_IGNORE
// MPI_Recv(msg, count , datatype, int source MPI_ANY_SOURCE, int tag, MPI_Comm comm, MPI_Status status);


int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	int num,rnk;
	MPI_Comm_size(MPI_COMM_WORLD, &num);
	MPI_Comm_rank(MPI_COMM_WORLD, &rnk);
	printf("%d from %d\n", rnk, num);

	const int N = 1000000;
	if (rnk == 0) {
		int nr = 0;
		float summ = 0;
		while (nr < num-1) {
			float r;
			MPI_Recv(&r, 1, MPI_FLOAT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			summ += r;
			nr++;
		 }
		printf("%.8f", summ * 4);
	} else {
		int si = rnk;
		float summ = 0;
		while (si < N) {
			double x1 = si / ((double)N);
			double x2 = (si+1) / ((double)N);
			double y1 = sqrt(1 - x1*x1);
			double y2 = sqrt(1 - x2*x2);
			summ += (x2 - x1) * (y1 + y2) * 0.5;
			si += num - 1;
		  }
		MPI_Send(&summ, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
	}

	MPI_Finalize();
}
