#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
int main(int argc, char** argv) {
	MPI_Init(&argc, &argv);
	int rank, size, total_sum = 0, summ_on_proc = 0;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int a[8]; int b[2];
	if (rank == 0) {
		cout << "Array: " << endl;
		for (int i = 0; i < 8; i++) { cin >> a[i]; }}
	MPI_Barrier(MPI_COMM_WORLD);
	if (rank == 0) {
		cout << endl << "Array: ";
			for (int i = 0; i < 8; i++) 	cout << a[i] << " "; cout << endl;	}
	MPI_Scatter(a, 2, MPI_INT, b, 2, MPI_INT, 0, MPI_COMM_WORLD);
	cout << "I'm rank " << rank << "; my numbers are " << b[0]  << " and " << b[1] << endl;
	summ_on_proc = b[0] + b[1];
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Reduce(&summ_on_proc, &total_sum, 1, MPI_INT, MPI_SUM, 2, MPI_COMM_WORLD);
	if (rank == 2)
		cout << endl << "I'm rank " << rank << 	"; total sum is " << total_sum <<  endl;
	MPI_Finalize();
	return 0;
}
