#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &nums)
{
    int s = 0;
    int n = nums.size();
    int e = n - 1;
    // Example (This function also works for non-rotated sorted array):
    // 2 4 6 8 10 - arr
    // 0 1 2 3 4 - index
    // ans = 4, as 10 i.e. pivot is at index 4
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        // corner case
        if (s == e)
        {
            return s;
        }

        if (mid + 1 < n && nums[mid] > nums[mid + 1])
        {
            return mid;
        }
        else if (mid - 1 >= 0 && nums[mid - 1] > nums[mid])
        {
            return mid - 1;
        }
        else if (nums[s] > nums[mid])
        { // we're currently on portion B
            // ans is in left portion
            e = mid - 1;
        }
        else
        { // we're currently on portion A
            // ans is in right portion
            s = mid + 1;
        }
    }
    return -1;
}

int binarySearch(vector<int> &arr, int s, int e, int target)
{
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int search(vector<int> &arr, int target)
{
    int pivot = findPivot(arr);
    int n = arr.size();
    int ans = -1;

    // search in A
    if (target >= arr[0] && target <= arr[pivot])
    {
        ans = binarySearch(arr, 0, pivot, target);
    }
    else
    {
        ans = binarySearch(arr, pivot + 1, n - 1, target);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 7;
    cout << search(arr, target) << endl;
    return 0;
}