#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tc: O(2^n) & sc: O(n)
    // int solveUsingRec(vector<int>& nums, int curr, int prev) {
    //     if (curr >= nums.size())
    //         return 0;
    //     int inc = 0;
    //     if (prev == -1 || nums[curr] > nums[prev]) {
    //         inc += 1 + solveUsingRec(nums, curr + 1, curr);
    //     }
    //     int exc = 0 + solveUsingRec(nums, curr + 1, prev);

    //     return max(inc, exc);
    // }

    // tc: O(n^2) & sc: O(n^2)
    // int solveUsingMemo(vector<int>& nums, int curr, int prev,
    // vector<vector<int>>& dp) {
    //     if (curr >= nums.size())
    //         return 0;
    //     // very imp, index shifting i.e. prev + 1 as prev is initially -1
    //     which is invalid idx if (dp[curr][prev + 1] != -1)
    //         return dp[curr][prev + 1];

    //     int inc = 0;
    //     if (prev == -1 || nums[curr] > nums[prev]) {
    //         inc += 1 + solveUsingMemo(nums, curr + 1, curr, dp);
    //     }
    //     int exc = 0 + solveUsingMemo(nums, curr + 1, prev, dp);

    //     return dp[curr][prev + 1] = max(inc, exc);
    // }

    // tc: O(n^2) & sc: O(n^2)
    // int solveUsingTabu(vector<int>& nums, int n) {
    //     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    //     for (int curr = n - 1; curr >= 0; curr--) {
    //         for (int prev = curr - 1; prev >= -1; prev--) {
    //             int inc = 0;
    //             if (prev == -1 || nums[curr] > nums[prev]) {
    //                 // curr + 1 = index shifting
    //                 inc += 1 + dp[curr + 1][curr + 1];
    //             }
    //             // prev + 1 = index shifting
    //             int exc = 0 + dp[curr + 1][prev + 1];
    //             dp[curr][prev + 1] = max(inc, exc);
    //         }
    //     }
    //     // -1 is the column we want to access but it'd give address error
    //     // so we shift the index by ading 1
    //     return dp[0][-1 + 1];
    // }

    // tc: O(n^2) & sc: O(2n)
    // int solveUsingTabuSpaceOpti(vector<int>& nums, int n) {
    //     vector<int> currRow(n + 1, 0);
    //     vector<int> nextRow(n + 1, 0);

    //     for (int curr = n - 1; curr >= 0; curr--) {
    //         for (int prev = curr - 1; prev >= -1; prev--) {
    //             int inc = 0;
    //             if (prev == -1 || nums[curr] > nums[prev]) {
    //                 // curr + 1 = index shifting
    //                 inc += 1 + nextRow[curr + 1];
    //             }
    //             // prev + 1 = index shifting
    //             int exc = 0 + nextRow[prev + 1];
    //             currRow[prev + 1] = max(inc, exc);
    //         }
    //         // shifting
    //         nextRow = currRow;
    //     }
    //     return nextRow[0];
    // }

    // tc: O(nlogn) & sc: O(n)
    int solveUsingBS(vector<int> &nums, int &n)
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ans.back())
                ans.push_back(nums[i]);
            else
            {
                // a num greater than/equal to curr num exists in the ans array
                // so we replace it with the curr num
                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int> &nums)
    {
        int curr = 0, prev = -1;
        // return solveUsingRec(nums, curr, prev);
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solveUsingMemo(nums, curr, prev, dp);
        // return solveUsingTabu(nums, n);
        // return solveUsingTabuSpaceOpti(nums, n);
        return solveUsingBS(nums, n);
    }
};

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    cout << s.lengthOfLIS(nums) << endl;
    return 0;
}