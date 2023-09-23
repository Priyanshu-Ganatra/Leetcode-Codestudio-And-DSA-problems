#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            // currently in A portion
            // peak exists in right portion
            s = mid + 1;
        }
        else
        {
            // currently either on peak element or in B portion
            e = mid;
        }
    }
    return s;
}

int main()
{
    vector<int> arr = {0, 2, 1, 0};
    cout << peakIndexInMountainArray(arr) << endl;
    return 0;
}