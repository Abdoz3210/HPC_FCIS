#include <iostream>
#include <mpi.h>

using namespace std;

int main(){
    MPI_Init(NULL,NULL);
    int size, rank,n;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
   
    int* data =new int[15];
    int* sums  =new int[3] {0,0,0};
    int* localdata =new int[5];
    int localsum=0 ,totalsum =0;
    
    if(rank == 0){
        for (int i = 0; i <15 ;i++)
            data[i]=i+1;
    }
    
    MPI_Scatter(data ,5 ,MPI_INT,localdata,5 ,MPI_INT , 0 ,MPI_COMM_WORLD);

    for (int i = 0 ; i<5; ++i)
        localsum += localdata[i];
    cout << "Local sum = "<<localsum<<endl;
    MPI_Gather(&localsum,1,MPI_INT,sums , 1, MPI_INT,0, MPI_COMM_WORLD);

    if (rank ==0 ){
        for(int i=0 ; i < size ;i++)
            totalsum += sums[i];
        cout<< "Total Sum = "<< totalsum<<endl;
    }
    MPI_Finalize();
    return 0;
}