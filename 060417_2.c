#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int *globaldata=NULL;
    int localdata;
    int *array = malloc(size * sizeof(int));
    for (int i=0; i<size; i++)
        array[i] = 2*i+1;
    globaldata = malloc(size * sizeof(int) );
    if (rank == 0) {
        printf("Array  data: ");
            for (int i=0; i<size; i++)
                printf("%d ", array[i]);
            printf("\n");
        for (int i=0; i<size; i++)
            globaldata[i] = i;

        printf("Processor %d has data: ", rank);
        for (int i=0; i<size; i++)
            printf("%d ", globaldata[i]);
        printf("\n");
    }

    MPI_Scatter(globaldata, 1, MPI_INT, &localdata, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Processor %d has data %d\n", rank, localdata);
   // localdata *= 2;
    localdata *= array[localdata];

    printf("Processor %d multi the data, now has %d\n", rank, localdata);

    MPI_Allgather(&localdata, 1, MPI_INT, globaldata, 1, MPI_INT, MPI_COMM_WORLD);

  

    int result = 0;
    //if (rank == 0) {
        printf("Processor %d has data: ", rank);
        for (int i=0; i<size; i++)
            result += globaldata[i];
        printf("%d ", result);
        printf("\n");
   // }

    if (rank == 0)
        free(globaldata);

    MPI_Finalize();
    return 0;
}