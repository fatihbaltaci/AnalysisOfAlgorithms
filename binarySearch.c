#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a,b) { int temp; temp = a; a = b; b = temp; }

int random_number(int , int );      //randomise numbers
int Partition(int* , int , int );
void quickSort(int* , int , int );

int main()
{
    clock_t start1, stop1, start2, stop2;
    int i,j,k = 0;
    double duration;  // how many ms does the program runs
    int N = 300; // max. row and column of the square matrix
    int sensitivity = 10000;    //This is for the loops. It's required because if we don't make a loop while calling binary search function the result give us 0.00000, but if we use loop for sensitivity times then it gives us a double number like 126,456. At the end of the main we divide by sensitivity and we find the correct solution.

    int* Array = (int*)malloc(N*sizeof(int));

	//start2 and stop2 is calculating the time that required for randomise number for "sensitivity" times.
    start2 = clock();
    for(j = 0 ; j < sensitivity ; j++)
        for( i = 0 ; i < N ; i++)
        {
            Array[i] = random_number(i, N)%1000;
        }
    stop2 = clock();

    quickSort(Array, 0, N-1);

    start1 = clock();
    for(i = 0 ; i < sensitivity ; i++)
    {
        for( j = 0 ; j < N ; j++)
        {
            Array[j] = random_number(j, N)%1000;
        }
        quickSort(Array, 0, N-1);
        BinarySearch(Array, 5000, 0, N-1);
    }
    stop1 = clock();

    duration = (double)(1000 * ((stop1-start1) - (stop2-start2))/CLK_TCK) / sensitivity;
    printf("\n%4d ---> %4.8f ms \n", N, duration);

    return 0;
}

int BinarySearch(int Array[], int value, int left, int right  )
{
    int mid;
    while(left <=right)
    {
        mid = ((right - left) / 2) + left;
        if(Array[mid] == value)
            return mid;
        if(value < Array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}


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

void quickSort(int* A, int low, int high)
{
    int pivot_location;
    if(low < high)
    {
        pivot_location = Partition(A, low, high);
        quickSort(A, low, pivot_location - 1);
        quickSort(A, pivot_location + 1, high);
    }
}

int Partition(int* A, int low, int high)
{
    int pivot = A[low];
    int leftwall = low;
    int i;

    for(i = low+1 ; i <= high ; i++)
    {
        if(A[i] < pivot)
        {
            leftwall = leftwall + 1;
            SWAP(A[i], A[leftwall]);
        }
    }
    SWAP(A[low], A[leftwall]);

    return leftwall;
}
