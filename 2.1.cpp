#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int number1 = 38, number2 = 64, number3 = 17, number4 = 841;
    if (rank == 0) {
        MPI_Recv(&number1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 0 received number " << number1 << " from process 1" << endl;
        MPI_Recv(&number2, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 0 received number " << number2 << " from process 2" << endl;
        MPI_Recv(&number3, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 0 received number " << number3 << " from process 3" << endl;
        MPI_Recv(&number4, 1, MPI_INT, 4, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 0 received number " << number4 << " from process 4" << endl;
    }
    if (rank == 1) { MPI_Send(&number1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); }
    if (rank == 2) { MPI_Send(&number2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); }
    if (rank == 3) { MPI_Send(&number3, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); }
    if (rank == 4) { MPI_Send(&number4, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); }

    MPI_Finalize();
}
