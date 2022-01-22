// Radix Sort in C Programming

#include <stdio.h>

void countingSort(int array[], int size, int place)
{
    int output[size + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++)
    {
        if (((array[i] / place) % 10) > max)
            max = array[i];
    }

    // COUNTING SORT START HERE, REALLY.

    int count[max + 1];

    for (int i = 0; i < max; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}

void radixsort(int array[], int size, int max)
{

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]);
    radixsort(array, n, 788);
    printArray(array, n);
}