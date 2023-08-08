#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// This will work even if the element is duplicated more than once
int main()
{
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8};
    int n = arr.size();
    int hash[n] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
        if (hash[arr[i]] >= 2)
        {
            cout<<arr[i];
            return 0;
        }
    }
}

// This will work only if the element is duplicated only once and doesn't have any other duplicates
// int main()
// {
//     int ans = 0;
//     int arr[] = {1, 1, 2, 3, 4};
//     for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
//     {
//         ans = ans^arr[i];
//     }

//     for (int i = 1; i < sizeof(arr)/sizeof(int); i++)
//     {
//         ans = ans^i;
//     }
//     cout<<ans;
// return 0;
// }