#include <iostream>
#include <mpi.h>

using namespace std;

int main(){
    MPI_Init(NULL,NULL);
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   
    int gatherarr[6], arr[2];
    for (int i =0; i<2 ; i++){
        arr[i]=rank * 2 + i + 1;
    }

     
    MPI_Gather(&arr, 2 , MPI_INT,&gatherarr, 2, MPI_INT , 0 , MPI_COMM_WORLD);
     
    if (rank == 0){
        cout << "processor "<<rank<<" recived: ";
        for(int i = 0 ; i<6 ; i++){
            cout << gatherarr[i] << " ";
        }
        cout << endl;
    }
    
    
    MPI_Finalize();
    return 0;
}