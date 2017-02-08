/** This is a program that calculates two matrices multiplication
@Author: Fatih Baltacý

22.02.2015

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int random_number(int , int );

int main()
{
    clock_t start, stop;
    int i,j,k;
    int duration;  // how many ms does the program runs
    int N = 500; // max. row and column of the square matrix
	
	//No need to make a loop because it gives us time. So we didn't use sensitivity variable

    int** firstMatrix = (int**)malloc(N*sizeof(int*));
    for(i = 0 ; i < N ; i++)
        firstMatrix[i] = (int*)malloc(N * sizeof(int));

    int** secondMatrix = (int**)malloc(N*sizeof(int*));
    for(i = 0 ; i < N ; i++)
        secondMatrix[i] = (int*)malloc(N * sizeof(int));

    int** resultMatrix = (int**)malloc(N*sizeof(int*));
    for(i = 0 ; i < N ; i++)
        resultMatrix[i] = (int*)malloc(N * sizeof(int));

    //Filling 2D arrays with random numbers
    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            firstMatrix[i][j] = random_number(i, N);
            secondMatrix[i][j] = random_number(j, N);
        }
    }

    start = clock();
    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < N ; j++)
        {
            resultMatrix[i][j] = 0 ;
            for( k = 0 ; k < N ; k++)
            {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
    stop = clock();
    duration = (int)(1000 * (stop-start)/CLK_TCK);
    printf("\n%4d ---> %4d ms \n", N, duration);


    return 0;
}



//Calculates random numbers, changes every running time
 int random_number(int min_num, int max_num)
        {
            int result=0,low_num=0,hi_num=0;
            if(min_num<max_num)
            {
                low_num=min_num;
                hi_num=max_num+1; // this is done to include max_num in output.
            }else{
                low_num=max_num+1;// this is done to include max_num in output.
                hi_num=min_num;
            }
            srand(time(NULL));
            result = (rand()%(hi_num-low_num))+low_num;
            return result;
        }
