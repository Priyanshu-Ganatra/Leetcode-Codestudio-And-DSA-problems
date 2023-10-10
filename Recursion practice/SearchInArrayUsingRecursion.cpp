#include <bits/stdc++.h>
using namespace std;

// linear search using recursion
int search(int arr[], int n, int key, int index)
{
    if (index == n)
    {
        return -1;
    }
    if (arr[index] == key)
    {
        return index;
    }
    return search(arr, n, key, index + 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int key = 3;
    cout << key << " found at index: ";
    cout << search(arr, n, key, 0) << endl;
    return 0;
}