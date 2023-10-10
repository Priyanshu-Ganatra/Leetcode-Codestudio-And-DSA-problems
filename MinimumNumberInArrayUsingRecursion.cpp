#include <bits/stdc++.h>
using namespace std;

void findMin(int arr[], int n, int index, int &min)
{
    if (index >= n)
    {
        return;
    }
    if (arr[index] < min)
    {
        min = arr[index];
    }
    findMin(arr, n, index + 1, min);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int min = INT_MAX;
    findMin(arr, n, 0, min);
    cout << "Minimum element in the array is: ";
    cout << min << endl;
    return 0;
}