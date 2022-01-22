#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *f, int *s)
{
    int temp = *f;
    *f = *s;
    *s = temp;
}

int partition(int arr[], int p, int r)
{

    int x = arr[r]; // 1
    int q = p - 1;  // -1
    for (short j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            q++;
            swap(&arr[q], &arr[j]);
        }
    }

    swap(&arr[q + 1], &arr[r]);
    return q + 1;
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

// RANDOMIZED QUICK SORT
int randomized_partition(int arr[], int p, int r)
{
    srand(time(0));
    int i = (p + rand() / (RAND_MAX / (r - p + 1) + 1));
    swap(&arr[r], &arr[i]);
    return partition(arr, p, r);
}

//
void randomized_quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = randomized_partition(arr, p, r);
        randomized_quickSort(arr, p, q - 1);
        randomized_quickSort(arr, q + 1, r);
    }
}

int main()
{
    int arr[] = {8, 10, 14, 16, 7, 9, 3, 2, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    // randomized_quickSort(arr, 0,size - 1);

    for (short i = 0; i < size; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf("\n");
}