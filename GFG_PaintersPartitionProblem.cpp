#include <bits/stdc++.h>
using namespace std;

bool isPossibleSol(int a[], int n, int k, long long mid)
{
    long long timeSum = 0;
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
        {
            return false;
        }
        if (a[i] + timeSum > mid)
        {
            cnt++;
            timeSum = a[i];
            if (cnt > k)
                return false;
        }
        else
        {
            timeSum += a[i];
        }
    }
    return true;
}
long long minTime(int arr[], int n, int k)
{
    // code here
    // return minimum time
    long long start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        end += arr[i];
    }
    long long ans = -1;

    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        if (isPossibleSol(arr, n, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << minTime(a, n, k) << endl;
    }
    return 0;
}