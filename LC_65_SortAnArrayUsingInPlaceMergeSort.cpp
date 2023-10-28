#include <bits/stdc++.h>
using namespace std;

void mergeInPlace(vector<int> &arr, int low, int mid, int high)
{
    int totalLen = high - low + 1;
    int gap = (totalLen / 2) + (totalLen % 2); // same as ceil(totalLen/2), used to calculate gap between elements to be compared
    while (gap > 0)
    {
        int i = low, j = low + gap;
        while (j <= high)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
            i++;
            j++;
        }
        gap = (gap <= 1) ? 0 : (gap / 2) + (gap % 2); // this means that if gap is 1, then it will be made 0, else it will be made half of its value
    }    
}

// tc : O(nlogn) sc : O(1)
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low == high)
        return;
    int mid = (low + high) >> 1;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    mergeInPlace(arr, low, mid, high);
}

vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11};
    cout << "Array before sorting: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    int n = arr.size();
    sortArray(arr);
    cout << "\nArray after sorting: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}