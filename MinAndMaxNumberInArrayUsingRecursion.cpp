#include <bits/stdc++.h>
using namespace std;

void findMinMax(int arr[], int n, int index, int &min, int &max)
{
    if (index >= n)
    {
        return;
    }
    if (arr[index] < min)
    {
        min = arr[index];
    }
    if (arr[index] > max)
    {
        max = arr[index];
    }
    findMinMax(arr, n, index + 1, min, max);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int min = INT_MAX;
    int max = INT_MIN;
    findMinMax(arr, n, 0, min, max);
    cout << "Minimum element in the array is: ";
    cout << min << endl;
    cout << "Maximum element in the array is: ";
    cout << max << endl;
    return 0;
}