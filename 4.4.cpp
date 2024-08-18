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
    int N, root, k = 0;
    root = 0;
    double x[10], max_number=0;
    for (int i = 0; i < 10; i++) {
        x[i] = 0; //max_number[i] = 0;
    }
    
    if (rank == root) {
        cout << "My rank is 0" << endl;
        cout << "Array:" << endl;
        for (int i = 0; i < 10; i++) {
           // x[i] = rand() % 100;
           x[i] = cos(i * (rand() % 10) * 00.1); 
            cout << " x[" << i << "] = " << x[i] << endl;
        }
        cout << endl;
    }
    MPI_Bcast(x, 10, MPI_DOUBLE, root, MPI_COMM_WORLD);
    
        if (rank > 0) {
            for (int i = 0; i < 10; i++) {
                x[i] = x[i] * rank;
                if (x[i] > max_number) max_number = x[i];
            }
            MPI_Send(&max_number, 1, MPI_DOUBLE, root, 0, MPI_COMM_WORLD);
        }

        else if (rank == root) 
            for (rank = 1; rank < size; rank++) {
                MPI_Recv(&max_number, 1, MPI_DOUBLE, rank, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                cout << "Max number of proc " << rank << " is " << max_number << endl;
            }
        
   MPI_Finalize();
}
