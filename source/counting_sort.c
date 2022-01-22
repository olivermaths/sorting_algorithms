#include <stdio.h>

void printArray(int arr[], int size)
{

    for (short i = 0; i < size; i++)
    {
        printf("%i, ", arr[i]);
    }
    printf("\n");
}

void counting_sort(int arr[], int n, int k)
{
    int narr[n];
    int b[k + 1];

    for (int i = 0; i <= k; i++)
    {
        b[i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        b[arr[j]]++;
    }

    for (int i = 0; i <= k; i++)
    {
        b[i] = b[i] + b[i - 1];
    }
    for (int i = (n - 1); i >= 0; i--)
    {
        narr[b[arr[i]]] = arr[i];
        b[arr[i]]--;
        printArray(narr, n);
        printArray(b, k + 1);
        printf("Next\n");
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] == narr[i];
    }
}

int main()
{
    int arr[] = {4, 3, 5, 5, 4, 5, 3, 2, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    counting_sort(arr, size, 5);
}