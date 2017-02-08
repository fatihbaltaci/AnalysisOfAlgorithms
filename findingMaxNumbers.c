#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number(int , int );

int main()
{
    clock_t start1, stop1, start2, stop2;
    int i,j,k;
    double duration;  // how many ms does the program runs
    int N = 1000; // max. row and column of the square matrix
    int max; //max element
    int sensitivity = 10000; //This is for the loops. It's required because if we don't make a loop while calling binary search function the result give us 0.00000, but if we use loop for sensitivity times then it gives us a double number like 126,456. At the end of the main we divide by sensitivity and we find the correct solution.

    int* arrayy = (int*)malloc(N*sizeof(int)); //allocating memory for the array

    start2 = clock();
    for(j = 0 ; j < sensitivity ; j++)
        for( i = 0 ; i < N ; i++)
        {
            arrayy[i] = random_number(i, N)%1000;
        }
    stop2 = clock();


    start1 = clock();
    max = arrayy[0];
    for(j = 0 ; j < sensitivity ; j++)
    {
        for(i = 0 ; i < N ; i++)
        {
            arrayy[i] = random_number(i, N)%1000;
            max = arrayy[0];
            if(arrayy[i+1] > max)
                max = arrayy[i+1];
        }
    }

    stop1 = clock();
    duration = (double)(1000 * ((stop1-start1) - (stop2-start2))/CLK_TCK) / sensitivity;
    printf("\n%4d ---> %4f ms \n", N, duration);

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
