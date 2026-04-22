#include <iostream>
#include <mpi.h>

using namespace std;
int main(){

    MPI_Init(NULL,NULL);
    int size, rank ;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0 ){
    int* dataarr = new int[10] {1,2,3,4,5,6,7,8,9,10};
    MPI_Send(dataarr , 10 , MPI_INT, 1 , 0 , MPI_COMM_WORLD);
    }
    else if (rank ==1 ){
        int* dataarr = new int[10];
        MPI_Status status ;
        MPI_Recv(dataarr , 10, MPI_INT, 0 , 0 , MPI_COMM_WORLD, &status);
        printf(" process 1 Recivbe Array: \n");
        for (int i =0 ; i<10 ;i++){
            printf("%d\n", dataarr[i]);
        }
    }
    MPI_Finalize();
    return 0;
}