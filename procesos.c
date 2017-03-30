#include <stdio.h>
#include <string.h>
#include <mpi.h>

const int MAX_STRING = 100;

int main(void){

	char greeting[MAX_STRING];
	int comm_sz;
	int my_rank;
	int ball = 0;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	while (ball < 5)
	{

		if(ball==0){
			if(ball <10){
				ball++;
				MPI_Send(ball,1,MPI_INT,0,0,MPI_COMM_WORLD);
			}else break;
		}else{
			if(ball<=10){
				MPI_Recv(ball,1,MPI_INT,1,0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				ball++;
			}else break;
		}
		/* code */
	}
}