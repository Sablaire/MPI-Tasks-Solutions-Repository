#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int rank, size;
    int buf;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) { buf = 100; }
    else { buf = 0; }
    MPI_Bcast(&buf, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0) cout << "Process 0 sent number " << buf << endl;
    else cout << "Process " << rank <<" received number " << buf << " from process 0 (with using MPI_Bcast)" << endl;   
    MPI_Finalize();
}
