#include <iostream>
#include <mpi.h>

using namespace std;

int main(){
    MPI_Init(NULL,NULL);
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   
    int arr[6];
    if (rank == 0){
        for (int i =0; i<6 ; i++){
            arr[i]=i+1;
         }
    }

    MPI_Bcast(arr, 6 , MPI_INT , 0 , MPI_COMM_WORLD);

    cout << "processor "<<rank<<" recived: ";
    for(int i = 0 ; i<6 ;++i){
        cout<< arr[i]<<" ";
    }
    cout<<endl;


    MPI_Finalize();
    return 0;
}