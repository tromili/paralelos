#include <stdio.h>
#define  m  3
#define  c  2
#define  n  4 

#define nn 18
#define BlockSize  3

void  three_nested_loop(){
	int i, j, k;
     // first matrix...
     int x[m][c] = {{1,2},{3,4},{5,6}};
     // second matrix...
     int y[c][n] = {{7,8,9,10},{11,12,13,14}};
     // for storing the matrix product result...
     int z[m][n];
     for(i=0; i<m; i++)
            for(j=0; j<n; j++)
            {
                   z[i][j] = 0;
                   for(k=0; k<c; k++)
                   		z[i][j] += x[i][k] * y[k][j];
            }
     printf("\nMultiply matrix x and matrix y,");
     printf("\nMatrix x is 3x2, and matrix y is 2x4,");
     printf("\nso, the result, z should be matrix 3x4\n");
     printf("\nThe matrix product is:  \n");
     printf("\nMultiply matrix x and matrix y,");
     printf("\nMultiply matrix x and matrix y,");

     
     for (i=0; i<m; i++)
     {
     	printf("\n");
            for(j=0; j<n; j++){
            	printf("%d",z[i][j]);
            	printf(" ");
            }
            // printf(z[i][j]);
     }
     printf("\n");
}

double min(double a, double b) {
    return a<b ? a : b;
}

void six_nested_loop(){
	int i1,j1, k1, i, j, k;
	int a[nn][nn] = {{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2}};
     // second matrix...
    int b[nn][nn] = {{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2},{1,2,2},{3,4,2},{5,6,2}};
	
	int cc[nn][nn];
	for( i1=0;i1<(nn/BlockSize);++i1)
	{
		for(j1=0;j1<(nn/BlockSize);++j1)
		{

			for(k1=0;k1<(nn/BlockSize);++k1)
			{

				for(i=i1;i<min(i1+BlockSize-1,nn);++i)
				{

					for(j=j1;j<min(j1+BlockSize-1,nn);++j)
					{

						for(k=k1;k<min(k1+BlockSize-1,nn);++k)
						{ 
              
							cc[i][j] = cc[i][j] + a[i][k] * b[k][j];
							printf("%d",cc[i][j]);
							printf(" ");
						}
					}
				}
			}
		}
    }
    printf("\n");
}


int main()
{
   // printf() displays the string inside quotation
   
	three_nested_loop();
	printf("\n");
	six_nested_loop();
    return 0; 
}