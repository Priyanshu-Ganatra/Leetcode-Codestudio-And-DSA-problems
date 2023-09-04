#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;
    // Sort first n-1 elements
    insertionSort(arr, n - 1);
    // Insert last element at its correct position
    // in sorted array.
    int last = arr[n - 1];
    int j = n - 2;
    /* Move elements of arr[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}