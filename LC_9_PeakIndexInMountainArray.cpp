#include <bits/stdc++.h>
using namespace std;

// easy to understand
int peakIndexInMountainArray(vector<int> &a)
{
    int ans = -1;
    int start = 0;
    int end = a.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        // currently in A portion
        // peak exists in right portion
        if (a[mid + 1] > a[mid])
        {
            start = mid + 1;
        }
        // currently in B portion
        // peak exists in left portion
        else if (a[mid - 1] > a[mid])
        {
            end = mid - 1;
        }
        else
        {
            // It must be Peak
            ans = mid;
            break;
        }
    }
    return ans;
}

// a little bit tricky
// int peakIndexInMountainArray(vector<int> &arr)
// {
//     int n = arr.size();
//     int s = 0;
//     int e = n - 1;
//     while (s < e)
//     {
//         int mid = s + (e - s) / 2;
//         if (arr[mid] < arr[mid + 1])
//         {
//             // currently in A portion
//             // peak exists in right portion
//             s = mid + 1;
//         }
//         else
//         {
//             // currently either on peak element or in B portion
//             e = mid;
//         }
//     }
//     return s;
// }

int main()
{
    vector<int> arr = {0, 2, 1, 0};
    cout << peakIndexInMountainArray(arr) << endl;
    return 0;
}