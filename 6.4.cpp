#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	//int N = 100;
	int size, rank, prev, next, buf[2], tag1 = 1, tag2 = 2;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (size < 2){ //Досрочный выход, если процесс всего один
		printf("Error: too few processes");
		MPI_Finalize();
		exit(1); }
	MPI_Request reqs[4];
	MPI_Status stats[4];
	prev = rank - 1;
	next = rank + 1;
	if (rank == 0) prev = size - 1;
	if (rank == (size - 1)) next = 0;

	int N;
	for (int i = 0; i < size; i++) {
		if (rank == i)	N = 10 * rank;
	}

	MPI_Irecv(&N, 1, MPI_INT, (rank + 2) % size, tag1, MPI_COMM_WORLD, &reqs[0]);
	MPI_Isend(&N, 1, MPI_INT, (size + (rank - 2)) % size, tag1, MPI_COMM_WORLD, &reqs[3]);

	MPI_Waitall(2, reqs, stats);

	cout <<  "My rank is " << rank << "; I recieved " << N << " from " << (rank + 2) % size << endl;
	MPI_Finalize();
	return 0;
}
