#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    long long sum = arr[0];
    int left = 0, right = 0, count = 0;
    int n = arr.size();

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
            count++;
        right++;
        if (right < n)
            sum += arr[right];
    }

    return count;
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
    cout << "The number of subarrays with sum k is: ";
    cout << findAllSubarraysWithGivenSum(arr, k) << endl;
    return 0;
}