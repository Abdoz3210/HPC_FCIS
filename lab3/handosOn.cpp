#include <iostream>
#include <mpi.h>

using namespace std;
int main() {
  MPI_Init(NULL, NULL);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  // cout<< rank <<"  "<< size <<endl;

  MPI_Status status;
  if (size != 4) {
    if (rank == 0) {
      cout << "4 processors required" << endl;
    }
    MPI_Finalize();
    return 0;
  }

  int data;
  if (rank == 0) {
    data = 0;

    MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&data, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, &status);
    data++;
    cout << "Process 0 Recived data " << data << endl;
  } else if (rank == 1) {
    MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    cout << "Process 1 Recived data " << data << endl;
    data++;
    MPI_Send(&data, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);

  }

  else if (rank == 2) {
    MPI_Recv(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
    cout << "Process 2 Recived data " << data << endl;
    data++;
    MPI_Send(&data, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
  } else if (rank == 3) {
    MPI_Recv(&data, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
    cout << "Process 3 Recived data " << data << endl;
    data++;
    MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
  }

  MPI_Finalize();
  return 0;
}
/*
    0----> 1
    A       |
    |       |
    |       |
    |       v
    3 <---- 2

*/