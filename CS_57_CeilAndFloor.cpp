#include <bits/stdc++.h>
using namespace std;

int getFloor(vector<int> &a, int n, int x)
{
    int ans = -1, low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] <= x)
        {
            ans = a[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int getCeil(vector<int> &nums, int n, int target)
{
    int low = 0, high = n - 1, ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
        {
            ans = nums[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    return {getFloor(a, n, x), getCeil(a, n, x)};
}

int main()
{
    vector<int> a = {1, 2, 8, 10, 10, 12, 19};
    int n = a.size();
    int x = 5;
    pair<int, int> ans = getFloorAndCeil(a, n, x);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}