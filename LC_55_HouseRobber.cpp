#include <bits/stdc++.h>
using namespace std;

// tc: O(2^n) sc: O(n)
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

// tc: O(2^n) sc: O(n).
// int solveUsingRecursion(vector<int>& nums, int n, int idx) {
//     // base case
//     if(idx >= n){
//         return 0;
//     }

//     // rob this house
//     int opt1 = nums[idx] + solveUsingRecursion(nums, n, idx + 2);

//     // don't rob this house
//     int opt2 = 0 + solve(nums, n, idx + 1);

//     int ans = max(opt1, opt2);
//     return ans;
// }

// tc: O(n) sc: O(n)
// int solveUsingMemo(vector<int> &nums, int &n, int idx, vector<int> &dp)
// {
//     // base case
//     if (idx >= n)
//     {
//         return 0;
//     }

//     // if ans already exists then return it
//     if (dp[idx] != -1)
//         return dp[idx];

//     // rob this house
//     int opt1 = nums[idx] + solveUsingMemo(nums, n, idx + 2, dp);

//     // don't rob this house
//     int opt2 = 0 + solveUsingMemo(nums, n, idx + 1, dp);

//     dp[idx] = max(opt1, opt2);
//     return dp[idx];
// }

// tc: O(n) sc: O(n)
// int solveUsingTabulation(vector<int> &nums, int &n, vector<int> &dp)
// {
//     dp[n - 1] = nums[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//     {
//         int tempAns = 0;
//         if (i + 2 < n)
//             tempAns = dp[i + 2];
//         int rob = nums[i] + tempAns;
//         int dontRob = 0 + dp[i + 1];
//         dp[i] = max(rob, dontRob);
//     }
//     return dp[0];
// }

// tc: O(n) sc: O(1)
int solveUsingTabulationSpaceOpti(vector<int> &nums, int &n)
{
    int prev = nums[n - 1];
    int prevPrev = 0;
    int curr = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int tempAns = 0;
        if (i + 2 < n)
            tempAns = prevPrev;
        int rob = nums[i] + tempAns;
        int dontRob = 0 + prev;
        curr = max(rob, dontRob);

        // shifting pointers back
        prevPrev = prev;
        prev = curr;
    }
    return prev;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    // return solveUsingRecursion(nums, n, 0);
    vector<int> dp(n, -1);
    // return solveUsingMemo(nums, n, 0, dp);
    // return solveUsingTabulation(nums, n, dp);
    return solveUsingTabulationSpaceOpti(nums, n);
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << "Maximum amount that can be robbed: ";
    cout << rob(nums) << endl;
    return 0;
}
