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

    double n1 = 1.1, n2 = 2.2, n3 = 3.3, n4 = 4.4, n5 = 5.5, n6 = 6.6;
    if (rank == 0) {
        MPI_Send(&n1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&n2, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
        MPI_Send(&n3, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
        MPI_Send(&n4, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
        MPI_Send(&n5, 1, MPI_INT, 5, 0, MPI_COMM_WORLD);
        MPI_Send(&n6, 1, MPI_INT, 6, 0, MPI_COMM_WORLD);
    }

    if (rank == 1) { 
        MPI_Recv(&n1, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 1 received number " << n1 << " from process 0" << endl;}
    if (rank == 2) {
        MPI_Recv(&n2, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 2 received number " << n2 << " from process 0" << endl;}
    if (rank == 3) {
        MPI_Recv(&n3, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 3 received number " << n3 << " from process 0" << endl;}
    if (rank == 4) {
        MPI_Recv(&n4, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 4 received number " << n4 << " from process 0" << endl;}
    if (rank == 5) {
        MPI_Recv(&n5, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 5 received number " << n5 << " from process 0" << endl;}
    if (rank == 6) {
        MPI_Recv(&n6, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process 6 received number " << n6 << " from process 0" << endl;}
       
    MPI_Finalize();
}
