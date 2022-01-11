#include <stdio.h>
#include <limits.h>

int max(int a, int b) { return (a > b) ? a : b; }

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    int array[] = {13, -3, -25, -20, 1, -16, -20, -18, -20, 7, 12, -5, -22, 15, -4, 9};
    int arr_size = sizeof(array) / sizeof(array[0]);
    int result = maxSubArraySum(array, arr_size);
    printf("\n%i\n", result);
}