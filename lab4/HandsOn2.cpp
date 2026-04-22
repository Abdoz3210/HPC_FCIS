#include <iostream>
#include <mpi.h>
// Do not use 'using namespace std;' in global scope to prevent namespace pollution.
using namespace std;

int main(int argc,char **argv) { 
    
    MPI_Init(NULL, NULL); 
    int Size, myId;
    MPI_Comm_size(MPI_COMM_WORLD, &Size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myId);
    if (myId == 0) {
    
        int Data[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        MPI_Send(&Data[5], 5, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&Data[10], 5, MPI_INT, 2, 0, MPI_COMM_WORLD);
        
        int sum =0;
        for (int i =0; i < 5; i++) {
            sum += Data[i];
        }
        MPI_Status status;

        int sum1, sum2;
        MPI_Recv(&sum1, 1, MPI_INT, 1,0, MPI_COMM_WORLD, &status);
        MPI_Recv(&sum2, 1, MPI_INT, 2,0, MPI_COMM_WORLD, &status);
        cout << "Process 0 sum array:" << sum + sum1 + sum2 << endl;

    }
    else if (myId <= 2) {
        int Data[5];
        MPI_Status astatus;
        MPI_Recv(&Data, 5, MPI_INT, 0, 0, MPI_COMM_WORLD, &astatus);
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += Data[i];
        }
        MPI_Send(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    
    }
    MPI_Finalize();
    return 0;


}