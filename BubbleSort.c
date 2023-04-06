#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr [], int n);
void printArray(int arr [], int n);
void fillArray(int arr [], int);

int main(int argc, char **argv)
{
    int n;
    int * arr;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

     arr = (int*)malloc(n * sizeof(int));

    fillArray(arr,n);

   // printf("Unsorted array\n");
    //printArray(arr,n);

    printf("Sorting array....\n");

    clock_t start = clock(); // Start the timer
    bubbleSort(arr, n);
    clock_t end = clock(); // Stop the timer

    //printf("Sorted array:\n");
    //printArray(arr,n);

    free(arr);

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed time in seconds
    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}

void fillArray(int arr [], int n)
{
    //seed the random number generator with the current time
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = rand();

    
}

void bubbleSort(int arr[], int n)
{
    int temp;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                //swap the elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
        printf("\n");
    }
}