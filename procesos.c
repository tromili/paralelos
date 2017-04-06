#include <stdio.h>
#include <string.h>
#include <mpi.h>

const int MAX_STRING = 100;

int main(void){

	//char greeting[MAX_STRING];
	int comm_sz;
	int my_rank;
	int ball = 0;
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

	if(ball==0 && my_rank ==0)
		if(ball <10){
			printf("\nProceso 0:");
			printf("%d",ball);
			ball++;	
			MPI_Send(&ball,1,MPI_INT,1,0,MPI_COMM_WORLD);
		}//else break;
	while (ball < 5)
	{

		
		if(my_rank==1){
			MPI_Recv(&ball,1,MPI_INT,0,0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("\nProceso 1:");
			printf("%d",ball);
			printf("\n");
			//ball = ballc;
			ball++;
			MPI_Send(&ball,1,MPI_INT,0,0,MPI_COMM_WORLD);
		}else{
			MPI_Recv(&ball,1,MPI_INT,1,0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("\nProceso 0:");
			printf("%d",ball);
			//ball = ballc;
			ball++;
			MPI_Send(&ball,1,MPI_INT,1,0,MPI_COMM_WORLD);
		}//else break;
		
		/* code */
	}
}