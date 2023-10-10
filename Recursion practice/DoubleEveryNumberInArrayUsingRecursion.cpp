#include <bits/stdc++.h>
using namespace std;

void doubleEveryNumber(int arr[], int n, int index)
{
    if (index >= n)
    {
        return;
    }
    arr[index] *= 2;
    doubleEveryNumber(arr, n, index + 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    doubleEveryNumber(arr, n, 0);
    cout << "Array after doubling every number: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}