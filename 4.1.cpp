#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    double array[5];
    double sum = 0.0;

    if (rank == 0) {
        cout << "Nabor iz 5 chisel: ";
        for (int i = 0; i < 5; i++) {
            array[i] = rand() % 100;
            cout << array[i] << "; ";
        }
        cout << endl;
    }
    MPI_Bcast(array, 5, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank != 0) {
        for (int i = 0; i < 5; i++) {
            sum = sum + array[i];
        }
        sum = sum * rank;
        MPI_Send(&sum, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }

    else if (rank == 0) {
        for (rank = 1; rank < size; rank++) {
            MPI_Recv(&sum, 1, MPI_DOUBLE, rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            cout << "Processor " << rank << " otpravil chislo " << sum << endl;
        }
    }
        
   MPI_Finalize();
}
