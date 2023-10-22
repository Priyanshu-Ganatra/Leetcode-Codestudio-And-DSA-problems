#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int idx, int n)
{
    // base case
    if (idx > n)
    {
        return 0;
    }

    // rob this house
    int opt1 = nums[idx] + solve(nums, idx + 2, n);

    // don't rob this house
    int opt2 = 0 + solve(nums, idx + 1, n);

    int ans = max(opt1, opt2);
    return ans;
}

// recursive solution, gives TLE on leetcode. we'll use DP to optimize it in future
// tc: O(2^n) sc: O(n)
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    int opt1 = solve(nums, 0, n - 2);
    int opt2 = solve(nums, 1, n - 1);

    int ans = max(opt1, opt2);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << "Maximum amount that can be robbed: ";
    cout << rob(nums) << endl;
    return 0;
}