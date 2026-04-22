#include <iostream>
#include <mpi.h>

using namespace std;

int main(){
    MPI_Init(NULL,NULL);
    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   
    int arr[8], localarr[2];

    if (rank == 0){
        for (int i =0; i<8 ; i++){
            arr[i]=i+1;
         }
    }

    MPI_Scatter(arr, 2 , MPI_INT,localarr, 2, MPI_INT , 0 , MPI_COMM_WORLD);

    cout << "processor "<<rank<<" recived: ";
    for(int i = 0 ; i<2 ;++i){
        cout<< localarr[i]<<" ";
    }
    cout<<endl;


    MPI_Finalize();
    return 0;
}