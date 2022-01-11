#include <iostream>
#include <vector>

// increasing function
void insertion_sort(std::vector<int> &arr)
{
    std::vector<int>::iterator it;
    int j, key;

    for (it = arr.begin(); it != arr.end(); it++)
    {
        key = *it;
        j = (it - arr.begin()) - 1;
        while (j >= 0 && arr.at(j) > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    for (int element : arr)
    {
        std::cout << element << " ";
    }
}

// decreasing function
void insertion_sort_decreasing(std::vector<int> &arr)
{
    std::vector<int>::iterator it;
    int j, key;

    for (it = arr.begin(); it != arr.end(); it++)
    {
        key = *it;
        j = (it - arr.begin()) - 1;
        while (j >= 0 && arr.at(j) < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (int element : arr)
    {
        std::cout << element << " ";
    }
}

int main()
{
    // The arr to be sorted.
    std::vector<int> arr = {5, 4, 3, 2, 1, 66, 44, 0, 7, 99, 5};
    // the sort functions.
    std::cout << "increasing sorted: ";
    insertion_sort(arr);
    std::cout << std::endl;
    std::cout << "decreasing sorted: ";
    insertion_sort_decreasing(arr);
    std::cout << std::endl;
    return 0;
}
