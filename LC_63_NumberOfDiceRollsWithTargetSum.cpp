#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mod = 1000000007;
    // int solveUsingRec(int n, int k, int target){
    //     // base cases
    //     if(target < 0) return 0;
    //     if(n == 0 && target != 0) return 0;
    //     if(n == 0 && target == 0) return 1;

    //     /// calculation
    //     int ans = 0;
    //     for(int i = 1; i <= k; i++){
    //         ans = ans + solveUsingRec(n - 1, k, target - i);
    //     }
    //     return ans;
    // }

    // int solveUsingMemo(int n, int k, int target, vector<vector<int>>& dp) {
    //     // base cases
    //     if (target < 0)
    //         return 0;
    //     if (n == 0 && target != 0)
    //         return 0;
    //     if (n == 0 && target == 0)
    //         return 1;
    //     if (dp[n][target] != -1)
    //         return dp[n][target];

    //     // calculation
    //     int ans = 0;
    //     for (int i = 1; i <= k; i++) {
    //         ans = (ans + solveUsingMemo(n - 1, k, target - i, dp)) % mod;
    //     }
    //     return dp[n][target] = ans; 
    // }

    // int solveUsingTabu(int n, int k, int target) {
    //     vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    //     // when all dice have been used and we have reached the target amount 
    //     // then we get 1 as ans as it is a base case 
    //     dp[n][target] = 1; // we're doing (dice = dice + 1) so that's why n as row idx

    //     for(int dice = n-1; dice >= 0; dice--){
    //         for(int sum = target; sum >= 0 ; sum--){
    //             int ans = 0;
    //             for (int face = 1; face <= k; face++) {
    //                 int tempAns = 0;
    //                 if(sum + face <= target) tempAns = dp[dice + 1][sum + face];
    //                 ans = (ans + tempAns) % mod;
    //             }
    //             dp[dice][sum] = ans; 
    //         }
    //     }
    //     return dp[0][0];
    // }

    int solveUsingTabuSpaceOpti(int n, int k, int target) {
        vector<int> curr(target+1, 0);
        vector<int> next(target+1, 0);
        
        next[target] = 1; 

        for(int dice = n-1; dice >= 0; dice--){
            for(int sum = target; sum >= 0 ; sum--){
                int ans = 0;
                for (int face = 1; face <= k; face++) {
                    int tempAns = 0;
                    if(sum + face <= target) tempAns = next[sum + face];
                    ans = (ans + tempAns) % mod;
                }
                curr[sum] = ans; 
            }
            next = curr;
        }
        return next[0];
    }

    int numRollsToTarget(int n, int k, int target) {
        // return solveUsingRec(n, k, target);
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // return solveUsingMemo(n, k, target, dp);
        // return solveUsingTabu(n, k, target);
        return solveUsingTabuSpaceOpti(n, k, target);
    }
};

int main() {
    Solution sol;
    cout << sol.numRollsToTarget(1, 6, 3) << endl;
    cout << sol.numRollsToTarget(2, 6, 7) << endl;
    cout << sol.numRollsToTarget(2, 5, 10) << endl;
    cout << sol.numRollsToTarget(30, 30, 500) << endl;
    return 0;
}