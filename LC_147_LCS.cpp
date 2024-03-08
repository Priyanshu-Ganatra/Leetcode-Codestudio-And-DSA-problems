#include <bits/stdc++.h>
using namespace std;

// int solveUsingRec(string a, string b, int i, int j) {
//     if (i >= a.size() || j >= b.size())
//         return 0;

//     int ans = 0;
//     if (a[i] == b[j]) {
//         ans = 1 + solveUsingRec(a, b, i + 1, j + 1);
//     } else {
//         ans = 0 + max(solveUsingRec(a, b, i + 1, j),
//                       solveUsingRec(a, b, i, j + 1));
//     }
//     return ans;
// }

// int solveUsingMemo(string& a, string& b, int i, int j,
//                    vector<vector<int>>& dp) {
//     if (i >= a.size() || j >= b.size())
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];

//     int ans = 0;
//     if (a[i] == b[j]) {
//         ans = 1 + solveUsingMemo(a, b, i + 1, j + 1, dp);
//     } else {
//         ans = 0 + max(solveUsingMemo(a, b, i + 1, j, dp),
//                       solveUsingMemo(a, b, i, j + 1, dp));
//     }
//     return dp[i][j] = ans;
// }

// int solveUsingTabu(string& a, string& b, int i, int j) {
//     vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1,
//     0)); for (int i = a.length() - 1; i >= 0; i--) {
//         for (int j = b.length() - 1; j >= 0; j--) {
//             int ans = 0;
//             if (a[i] == b[j]) {
//                 ans = 1 + dp[i + 1][j + 1];
//             } else {
//                 ans = 0 + max(dp[i + 1][j], dp[i][j + 1]);
//             }
//             dp[i][j] = ans;
//         }
//     }
//     return dp[0][0];
// }

int solveUsingTabuSpaceOpti(string &a, string &b, int i, int j)
{
    vector<int> curr(a.length() + 1, 0);
    vector<int> next(a.length() + 1, 0);

    for (int j = b.length() - 1; j >= 0; j--)
    {
        for (int i = a.length() - 1; i >= 0; i--)
        {
            if (a[i] == b[j])
            {
                curr[i] = 1 + next[i + 1];
            }
            else
            {
                curr[i] = 0 + max(curr[i + 1], next[i]);
            }
        }
        next = curr;
    }
    return next[0];
}

int longestCommonSubsequence(string text1, string text2)
{
    int i = 0;
    int j = 0;
    // return solveUsingRec(text1, text2, i, j);
    // vector<vector<int>> dp(text1.length(),
    //                        vector<int>(text2.length(), -1));
    // return solveUsingMemo(text1, text2, i, j, dp);
    // return solveUsingTabu(text1, text2, i, j);
    return solveUsingTabuSpaceOpti(text1, text2, i, j);
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";
    cout << longestCommonSubsequence(text1, text2) << endl;
    return 0;
} 