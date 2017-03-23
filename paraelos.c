#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define  m  3
#define  c  2
#define  n  4 

#define nn 18
#define BlockSize  3

//https://codeyarns.com/2013/09/17/how-to-profile-cc-code-using-valgrind-and-kcachegrind/
void  three_nested_loop(){


    int rm = rand()%100;
    int rc = rand()%100;
    int rn = rand()%100;

    int x[rm][rc];
     // second matrix...
    int y[rc][rn];

    printf("%d ",rm);
    printf("%d ",rc);
    printf("%d ",rn);
    printf(" ");

    for (int ic = 0; ic < rm; ++ic)
    {
        for (int jc = 0; jc < rc; ++jc)
        {
            x[ic][jc] = rand()%100;
        }
    }

    for (int ic = 0; ic < rc; ++ic)
    {
        for (int jc = 0; jc < rn; ++jc)
        {
            y[ic][jc] = rand()%100;
        }
    }

    clock_t t1, t2;

    t1 = clock();   

 
	int i, j, k;
     // first matrix...
     
     // for storing the matrix product result...
     int z[rm][rn];
     for(i=0; i<rm; i++)
            for(j=0; j<rn; j++)
            {
                   z[i][j] = 0;
                   for(k=0; k<rc; k++)
                   		z[i][j] += x[i][k] * y[k][j];
            }
     printf("\nMultiply matrix x and matrix y,");
     printf("\nMatrix x is 3x2, and matrix y is 2x4,");
     printf("\nso, the result, z should be matrix 3x4\n");
     printf("\nThe matrix product is:  \n");
     printf("\nMultiply matrix x and matrix y,");
     printf("\nMultiply matrix x and matrix y,");

     
     for (i=0; i<rm; i++)
     {
     	printf("\n");
            for(j=0; j<rn; j++){
            	printf("%d",z[i][j]);
            	printf(" ");
            }
            // printf(z[i][j]);
     }
     printf("\n");
    
    t2 = clock();   

    float diff = ((float)(t2 - t1) / 1000000.0F ) * 1000;   
    printf("%f",diff);  
    printf("\n");
}

double min(double a, double b) {
    return a<b ? a : b;
}

void six_nested_loop(){
	int i1,j1, k1, i, j, k;

    int rm = rand()%50;
    int rc = rand()%50;
    int rn = rand()%50;

    int a[rm][rc];
     // second matrix...
    int b[rc][rn];

    printf("%d ",rm);
    printf("%d ",rc);
    printf("%d ",rn);
    printf("\n ");

    for (int ic = 0; ic < rn; ++ic)
    {
        for (int jc = 0; jc < rn; ++jc)
        {
            a[ic][jc] = rand()%50;
        }
    }

    for (int ic = 0; ic < rn; ++ic)
    {
        for (int jc = 0; jc < rn; ++jc)
        {
            b[ic][jc] = rand()%50;
        }
    }

    clock_t t1, t2;

    t1 = clock();   
	
    int cc[rn][rn];
	for( i1=0;i1<(rn/BlockSize);++i1)
	{
		for(j1=0;j1<(rn/BlockSize);++j1)
		{

			for(k1=0;k1<(rn/BlockSize);++k1)
			{

				for(i=i1;i<min(i1+BlockSize-1,rn);++i)
				{

					for(j=j1;j<min(j1+BlockSize-1,rn);++j)
					{

						for(k=k1;k<min(k1+BlockSize-1,rn);++k)
						{ 
              
							cc[i][j] = cc[i][j] + a[i][k] * b[k][j];
							//printf("%d",cc[i][j]);
							//printf(" ");
						}
					}
				}
			}
		}
    }
    printf("\n");

    t2 = clock();   

    float diff = ((float)(t2 - t1) / 1000000.0F ) * 1000;   
    printf("%f",diff);  
    printf("\n");
}


int main()
{
   // printf() displays the string inside quotation
   
	//three_nested_loop();
	//printf("\n");
	six_nested_loop();
    return 0; 
}