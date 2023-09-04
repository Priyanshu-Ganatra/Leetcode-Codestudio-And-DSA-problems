#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    // [left...mid]
    // [mid+1...high]
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if there are still some elements left in either of the arrays to be merged
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // Now copy the elements from temp to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low]; // i-low because temp starts from 0 and arr starts from low index (not 0) in the original array (arr)
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};
    cout << "Array before sorting: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}