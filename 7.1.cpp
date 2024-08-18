#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	int rank, size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double number, recv_numbers[100], max_number = 0;
	srand((unsigned)time(NULL) + rank * size);
	number = rand() % 100;
	int root = 0;
	MPI_Gather(&number, 1, MPI_DOUBLE, recv_numbers, 1, MPI_DOUBLE, root, MPI_COMM_WORLD);

	if (rank == root) {
		cout << "Chisla na ranke 0: ";
		for (int i = 0; i < size; i++)
			cout << recv_numbers[i] << ";";
		cout << endl;
	}
	if (rank == root)
		for (int i = 0; i < size; i++)
			if (recv_numbers[i] > max_number) max_number = recv_numbers[i];
	MPI_Barrier(MPI_COMM_WORLD);
	if (rank == 0 ) cout << "Max = " << max_number;
	MPI_Finalize();
	return 0;
}
