/** Bubble Sort time calculations
@Author Fatih Baltacý
22.02.2015

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a,b) { int temp; temp = a; a = b; b = temp; }

int random_number(int , int );

int main()
{
    clock_t start1, stop1, start2, stop2;
    int i,j,k;
    int swaps;  //control the sort
    double duration;  // how many ms does the program runs
    int N = 500; // max. row and column of the square matrix
    int sensitivity = 1000; //This is for the loops. It's required because if we don't make a loop while calling binary search function the result give us 0.00000, but if we use loop for sensitivity times then it gives us a double number like 126,456. At the end of the main we divide by sensitivity and we find the correct solution.

    int* bubbleArray = (int*)malloc(N*sizeof(int));     //allocating a memory for the array

    start2 = clock();
    for(j = 0 ; j < sensitivity ; j++)
        for( i = 0 ; i < N ; i++)
        {
            bubbleArray[i] = random_number(i, N)%1000;
        }
        stop2 = clock();

 printf("hello");


    start1 = clock();
    for(k = 0 ; k < sensitivity ; k++)
    {
        for( i = 0 ; i < N ; i++)
        {

            swaps = 0;
            for(j = 0 ; j < N - i ; j++)
            {
                bubbleArray[i] = random_number(j, N)%1000;
                if(bubbleArray[j] > bubbleArray[j+1])
                {
                    SWAP(bubbleArray[j], bubbleArray[j + 1]);
                    swaps = swaps + 1;
                }
            }
            if(swaps == 0)
                break;
        }

    }

    stop1 = clock();
    duration = (double)(1000 * ((stop1-start1) - (stop2-start2))/CLK_TCK) / sensitivity;
    printf("\n%4d ---> %4f ms \n", N, duration);

    return 0;

}

//create randomise numbers
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
