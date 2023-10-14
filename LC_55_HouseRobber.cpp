#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int n, int idx)
{
    // base case
    if (idx >= n)
    {
        return 0;
    }

    // rob this house
    int opt1 = nums[idx] + solve(nums, n, idx + 2); // add the current house's money and move to the next to next house as we can't rob adjacent houses

    // don't rob this house
    int opt2 = 0 + solve(nums, n, idx + 1); // don't add the current house's money and move to the next house

    int ans = max(opt1, opt2);
    return ans;
}

// recursive solution, gives TLE on leetcode. we'll use DP to optimize it in future
int rob(vector<int> &nums)
{
    int n = nums.size();
    return solve(nums, n, 0);
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << "Maximum amount that can be robbed: ";
    cout << rob(nums) << endl;
    return 0;
}
