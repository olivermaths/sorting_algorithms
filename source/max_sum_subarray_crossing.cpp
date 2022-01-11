
#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::vector;

int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }

vector<int> max_sum_subarray(vector<int> &array, int left, int mid, int right)
{
    int sum = 0;
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    int max_right = 0;
    int max_left = 0;

    for (int i = mid; i >= 0; i--)
    {
        sum = sum + array[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (int j = mid + 1; j <= right; j++)
    {
        sum = sum + array[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }

    return {max_left, max_right, max((left_sum + right_sum), left_sum, right_sum)};
}

vector<int> find_maximum_subarray(vector<int> &array, int left, int right)
{
    if (left == right)
    {
        return {left, right, array[left]};
    }
    else
    {
        int mid = (left + right) / 2;
        vector<int> left_result = find_maximum_subarray(array, left, mid);
        vector<int> right_result = find_maximum_subarray(array, mid + 1, right);
        vector<int> crossing_result = max_sum_subarray(array, left, mid, right);

        if (left_result[2] >= right_result[2] && left_result[2] >= crossing_result[2])
        {
            return left_result;
        }
        else if (right_result[2] >= left_result[2] && right_result[2] >= crossing_result[2])
        {
            return right_result;
        }
        else
        {
            return crossing_result;
        }
    }
    return {};
}

int main()
{

    vector<int> array = {13, -3, -25, -20, 1, -16, -20, -18, -20, 7, 12, -5, -22, 15, -4, 9};
    vector<int> result = find_maximum_subarray(array, 0, array.size() - 1);

    printf("Start Index | End Index | Biggest Number or Sum\n");
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << std::endl;

    return 0;
}
