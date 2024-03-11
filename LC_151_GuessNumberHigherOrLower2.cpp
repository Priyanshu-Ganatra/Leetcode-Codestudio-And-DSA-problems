#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int solveUsingRecursion(int start, int end){
    //     // base case
    //     if(start >= end){ 
    //         // out of range or only 1 no. in range (start == end), then 0 penalty
    //         return 0;
    //     }

    //     int ans = INT_MAX;
    //     for(int i = start; i<=end ; i++){
    //         // adding 'i' bcoz what if 'i' is the wrong guess? Then we have to pay
    //         // 'i' amount as penalty, then divide the range in two parts on both sides 
    //         // of 'i' and take the maximum penalty we get out of them as we consider
    //         // the worst case
    //         // then out of all of the numbers ('i') I guess I want to get the min
    //         // amount of loss i.e. min amount of money that guarantees my win anyways
    //         ans = min(ans, i + max(solveUsingRecursion(start, i-1), 
    //                                solveUsingRecursion(i+1, end)));
    //         // i.e. my answer is the min amount I must carry to win the game out of
    //         // all the worst (maximizing our penalty) cases
    //     }
    //     return ans;
    // }

    int solveUsingMemo(int start, int end, vector<vector<int>> &dp){
        // base case
        if(start >= end){ 
            // out of range or only 1 no. in range (start == end), then 0 penalty
            return 0;
        }
        if(dp[start][end] != -1) return dp[start][end]; 

        int ans = INT_MAX;
        for(int i = start; i<=end ; i++){
            // adding 'i' bcoz what if 'i' is the wrong guess? Then we have to pay
            // 'i' amount as penalty, then divide the range in two parts on both sides 
            // of 'i' and take the maximum penalty we get out of them as we consider
            // the worst case
            // then out of all of the numbers ('i') I guess I want to get the min
            // amount of loss i.e. min amount of money that guarantees my win anyways
            ans = min(ans, i + max(solveUsingMemo(start, i-1, dp), 
                                   solveUsingMemo(i+1, end, dp)));
            // i.e. my answer is the min amount I must carry to win the game out of
            // all the worst (maximizing our penalty) cases
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int solveUsingTabu(int &n){
        vector<vector<int>> dp(n+2, vector<int>(n+1, 0));
        for(int s = n-1; s>=1; s--){
            for(int e = 1; e<=n; e++){
                if(s>=e) continue;
                int ans = INT_MAX;
                for(int i = s; i<=e ; i++){
                    // adding 'i' bcoz what if 'i' is the wrong guess? Then we have to pay
                    // 'i' amount as penalty, then divide the range in two parts on both 
                    // sides 
                    // of 'i' and take the maximum penalty we get out of them as we consider
                    // the worst case
                    // then out of all of the numbers ('i') I guess I want to get the min
                    // amount of loss i.e. min amount of money that guarantees my win //
                    // anyways
                    ans = min(ans, i + max(dp[s][i-1], dp[i+1][e]));
                    // i.e. my answer is the min amount I must carry to win the game out of
                    // all the worst (maximizing our penalty) cases
                }
                dp[s][e] = ans;
                    
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        int start = 1, end = n;
        // return solveUsingRecursion(start, end);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return solveUsingMemo(start, end, dp); 
        return solveUsingTabu(n); 
    }
};

int main() {
    int n = 10;
    Solution s;
    cout << s.getMoneyAmount(n) << endl;
    return 0;
}