#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int size, rank, prev, next, buf, tag1 = 1, tag2 = 2;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Request reqs[4];
	MPI_Status stats[4];
	prev = rank;
	next = rank + 1;
	if (rank == 0) prev = size - 1;
	if (rank == (size - 1)) next = 0;
	int N=100;
	int help = N,q,krug,k=0;
	krug = N / (size);
	for (int i = 1; i < N + 1; i++) {
		q = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				q = 0;
			}
		}
		if (q == 1) {
			MPI_Isend(&i, 1, MPI_INT, next, tag1, MPI_COMM_WORLD, &reqs[3]);
			if (k == rank) {
				MPI_Irecv(&buf, 1, MPI_INT, prev, tag1, MPI_COMM_WORLD, &reqs[0]);
				cout << k << " rank: divider of " << N << " - " << i << endl;
			}
			k++;
			if (k == size) {
				k = 0; 
			}
		}
	}
	MPI_Finalize();
	return 0;
}
