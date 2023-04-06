#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int n);
void printArray(int arr[], int n);
void fillArray(int arr[], int n);

int main(int argc, char **argv)
{
    int n;
    int * arr;
    cout << "Enter the size of the array: ";
    cin >> n;

    arr = new int[n];

    fillArray(arr, n);

    // cout << "Unsorted array" << endl;
    // printArray(arr, n);

    cout << "Sorting array...." << endl;

    clock_t start = clock(); // Start the timer
    bubbleSort(arr, n);
    clock_t end = clock(); // Stop the timer

    // cout << "Sorted array:" << endl;
    // printArray(arr, n);

    delete[] arr;

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed time in seconds
    cout << "Time taken: " << cpu_time_used << " seconds" << endl;

    return 0;
}

void fillArray(int arr[], int n)
{
    // seed the random number generator with the current time
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap the elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
