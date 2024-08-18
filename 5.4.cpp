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
    MPI_Status stat;
    MPI_Request req;
    int root = 0;
    int a[8];
    int total_sum = 0, sum = 0;
    if (rank == root) {
        for (int i = 0; i < 8; i++) {
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }
    MPI_Bcast(a, 8, MPI_INT, root, MPI_COMM_WORLD);

   
    for (int i = 0; i < 8; i++) { sum = sum + a[i]; } 

    MPI_Reduce(&sum, &total_sum, 1, MPI_INT, MPI_SUM, 2, MPI_COMM_WORLD);
        
    if (rank == 2) {
        cout << "!!! My rank is " << rank << " and array: ";
            for (int i = 0; i < 8; i++) {
                cout << a[i] << "; ";
            }
            cout << "  Sum on processor = " << sum << "; Total sum = " << total_sum << endl;
        }
    else {
         cout << "    My rank is " << rank << " and array: ";
            for (int i = 0; i < 8; i++) {
                cout << a[i] << "; ";
            }
            cout << "  Sum on processor = " << sum << "; Total sum = " << total_sum << endl;
    }
                 
   MPI_Finalize();
}
