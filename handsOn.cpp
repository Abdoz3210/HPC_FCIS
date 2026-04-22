#include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    if (size != 4) {
        if (rank == 0) {
            cout << "This program requires exactly 4 processes." << endl;
        }
        MPI_Finalize();
        return 0;
    }
    
    int data = 0;
    MPI_Status status;
    
    int prev = (rank - 1 + size) % size;
    int next = (rank + 1) % size;
    
    MPI_Sendrecv(&data, 1, MPI_INT, next, 0,
                 &data, 1, MPI_INT, prev, 0,
                 MPI_COMM_WORLD, &status);
    
    data++;
    cout << "Process " << rank << " received " << data-1 
         << ", incremented to " << data << endl;
    
    MPI_Finalize();
    return 0;
}
