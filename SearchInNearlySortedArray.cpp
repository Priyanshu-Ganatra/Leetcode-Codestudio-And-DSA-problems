#include <bits/stdc++.h>
using namespace std;

int searchInNearlySortedArray(int arr[], int n, int target)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s<=e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (mid - 1 >= s && arr[mid - 1] == target)
        {
            return mid - 1;
        }
        else if (mid + 1 <= e && arr[mid + 1] == target)
        {
            return mid + 1;
        }
        else if (arr[mid] > target)
        {
            // left
            e = mid - 2; // - 2 as we have already checked mid - 1
        }
        else
        {
            // right
            s = mid + 2; // + 2 as we have already checked mid + 1
        }   
    }
    
    return -1;
}

int main()
{
    int arr[] = {20, 10, 30, 50, 40, 70, 60};
    int n = 7;
    int target = 60;
    int idx = searchInNearlySortedArray(arr, n, target);

    if (idx != -1)
    {
        cout << "Element found at index " << idx << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}