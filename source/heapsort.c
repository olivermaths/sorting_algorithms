#include <stdio.h>

void swap(int* big, int* small)
{
   int temp = *small;
   *small = *big;
   *big = temp;
}




void max_heapify(int arr[], int heap_size, int index)
{
    int left = (index << 1) + 1;
    int right = (index << 1) + 2;
    int largest = index;
    if (left < heap_size && arr[left] > arr[index])
    {
        largest = left;
    }
    if (right < heap_size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(&arr[largest], &arr[index]);
        max_heapify(arr, heap_size, largest);
    }
}

void build_max_heap(int arr[], int size)
{
    short length = (size / 2) - 1;
    for (short i = length; i >= 0; i--)
    {
        max_heapify(arr, size, i);
    }
}


void heapsort(int arr[], int size){
    build_max_heap(arr, size);
    short length = size - 1;
    short heap_size = size;
    for (short i = length; i >= 0; i--)
    {
      swap(&arr[i], &arr[0]);
      heap_size -=1;
      max_heapify(arr, heap_size,  0);
    }
}


int main()
{
    //Simple example
    int arr[] = {8, 10, 14, 16, 7, 9, 3, 2, 4, 1};
    int heap_size = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, heap_size);
    for (short i = 0; i < heap_size; i++)
    {
      printf("%i, ", arr[i]);
    }
      printf("\n");
}