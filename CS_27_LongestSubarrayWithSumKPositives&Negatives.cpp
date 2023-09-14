#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int> &a, int k)
{
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxLen = i + 1;
        }
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(len, maxLen);
        }
        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "The length of the longest subarray with sum k is: ";
    cout << getLongestSubarray(arr, k) << endl;
    return 0;
}