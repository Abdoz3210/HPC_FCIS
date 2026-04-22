#include <iostream>
#include <mpi.h>

using namespace std;

int main(){
    MPI_Init(NULL,NULL);
    int size,rank;
    
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    int data =1;
    int data2 = 9;

    if (rank == 0){

        MPI_Send(&data, 1 , MPI_INT , 1 , 0 , MPI_COMM_WORLD );
        MPI_Status status;
        MPI_Recv(&data, 1 , MPI_INT , 1 , 0 ,MPI_COMM_WORLD,&status);
        printf("pong\n");
    }else if (rank == 1 ){
        MPI_Status status;

        MPI_Recv(&data , 1 , MPI_INT, 0 ,0 ,MPI_COMM_WORLD,&status);
        printf("ping\n");
        
        MPI_Send(&data , 1 , MPI_INT, 0 ,0 , MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}