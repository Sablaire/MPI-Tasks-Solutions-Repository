#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int kolvo = 0;
    
    kolvo = size+5;
    double* k = new double[kolvo];
    double* otvet = new double[kolvo];

    for (int i = 0; i < kolvo; i++) 
    {
        k[i] = 0.0;
        otvet[i] = 0.0;
    }

    if (rank == 0)
        for (int i = 0; i < kolvo; i++) k[i] = i * i;

    if (rank > 0)
        for (int i = 0; i < kolvo; i++)  k[i] = i * rank;

    for (int i = 0; i < kolvo; i++) MPI_Reduce(k, otvet, kolvo, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    
    if (rank == 0) {
        cout << "_____________________" << endl;
        for (int i = 0; i < kolvo; i++) {
            cout << "rank=" << rank << "; Summa[" << i << "] = " << otvet[i] << "; " << endl;
        }
    }
    else if (rank > 0)
    {
        for (int i = 0; i < kolvo; i++) {
            cout << "rank=" << rank << "; k[" << i << "] = " << k[i] << "; " << endl;
        }
    }
   
   MPI_Finalize();
}
