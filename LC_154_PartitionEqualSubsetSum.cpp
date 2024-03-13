#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // bool solveUsingRec(vector<int>& arr, int i, int sum, int target) {
    //     if (i >= arr.size())
    //         return 0;
    //     if (sum > target)
    //         return 0;
    //     if (sum == target)
    //         return 1;

    //     // recursion
    //     bool inc = solveUsingRec(arr, i + 1, sum + arr[i], target);
    //     bool exc = solveUsingRec(arr, i + 1, sum, target);
    //     return inc || exc;
    // }

    // bool solveUsingMemo(vector<int>& arr, int i, int sum, int &target, vector<vector<int>>&
    // dp) {
    //     if (i >= arr.size())
    //         return 0;
    //     if (sum > target)
    //         return 0;
    //     if (sum == target)
    //         return 1;
    //     if(dp[i][sum] != -1) return dp[i][sum];

    //     // recursion
    //     bool inc = solveUsingMemo(arr, i + 1, sum + arr[i], target, dp);
    //     bool exc = solveUsingMemo(arr, i + 1, sum, target, dp);
    //     return dp[i][sum] = inc || exc;
    // }

    // int solveUsingTabu(vector<int>& arr, int &target){
    //     int n = arr.size();
    //     vector<vector<int>>dp(n+2, vector<int>(target+1, 0));
    //     for(int row = 0; row<=n; row++){
    //         dp[row][target] = 1;
    //     }

    //     for(int idx = n-1; idx>=0; idx--){
    //         for(int s = target; s>=0; s--){
    //             bool inc = 0;
    //             if(s+arr[idx] <= target)
    //                 inc = dp[idx + 1][s + arr[idx]];
    //             bool exc = dp[idx + 1][s];
    //             dp[idx][s] = inc || exc;
    //         }
    //     }

    //     return dp[0][0];
    // }

    int solveUsingTabuSpaceOpti(vector<int> &arr, int &target)
    {
        int n = arr.size();
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);

        curr[target] = 1;
        next[target] = 1;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int s = target; s >= 0; s--)
            {
                bool inc = 0;
                if (s + arr[idx] <= target)
                    inc = next[s + arr[idx]];
                bool exc = next[s];
                curr[s] = inc || exc;
            }
            next = curr;
        }

        return next[0];
    }

    bool canPartition(vector<int> &nums)
    {
        int i = 0, sum = 0;
        for (int k = 0; k < nums.size(); k++)
        {
            sum += nums[k];
        }
        if (sum & 1)
            return false; // odd sum means can't be partitioned
        int target = sum / 2;
        int currSum = 0;
        // return solveUsingRec(nums, i, currSum, target);
        // vector<vector<int>>dp(nums.size()+1, vector<int>(target+1, -1));
        // return solveUsingMemo(nums, i, currSum, target, dp);
        // return solveUsingTabu(nums, target);
        return solveUsingTabuSpaceOpti(nums, target);
    }
};

int main()
{
    vector<int> arr = {1, 5, 11, 5};
    Solution obj;
    cout << obj.canPartition(arr) << endl;
    return 0;
}