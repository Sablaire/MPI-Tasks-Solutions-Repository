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
    int N, root, k = 0;
    root = 0;

    if (rank == root) { N = 1; }
    else { 
        N = 0; 
    }
    
    MPI_Bcast(&N, 1, MPI_INT, root, MPI_COMM_WORLD);
    
    for (int i = 1; i < size; i++) {
        k = i;
        if (rank == root) { MPI_Send(&k, 1, MPI_INT, i, 0, MPI_COMM_WORLD); }
        else { MPI_Recv(&k, 1, MPI_INT, root, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); }
    }
   

    if (rank == root) { cout << "I'm process " << rank << " and I receved numbers" << endl; }
    else { cout << "I'm process " << rank << "; N = " << N << "; K = " << k << endl; }
    MPI_Finalize();
}
