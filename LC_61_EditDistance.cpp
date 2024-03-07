#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // tc: O(3^n) sc: O(n)
    // int solveUsingRecursion(string &word1, string &word2, int i, int j)
    // {
    //     // base cases
    //     // if we reach the end of any of the strings, we return
    //     // the length of the remaining string
    //     if (i >= word1.length())
    //     {
    //         return word2.length() - j;
    //     }
    //     if (j >= word2.length())
    //     {
    //         return word1.length() - i;
    //     }

    //     int ans = 0;
    //     // if characters are same, no operation is required
    //     if (word1[i] == word2[j])
    //     {
    //         ans = 0 + solveUsingRecursion(word1, word2, i + 1, j + 1);
    //     }
    //     // if characters are not same, we have 3 options: insert, remove,
    //     // replace (all 3 are equally valid) and we'll take the minimum of
    //     all
    //     // 3 options as our answer for that particular call
    //     else
    //     {
    //         // insert
    //         // we don't increment i because we want to insert the character
    //         // at jth position of word2 in word1
    //         int opt1 = 1 + solveUsingRecursion(word1, word2, i, j + 1);
    //         // remove
    //         // we don't increment
    //         // j because we want to remove the character at ith position
    //         // of word1
    //         int opt2 = 1 + solveUsingRecursion(word1, word2, i + 1, j);
    //         // replace
    //         // we increment both i and j because we want to replace the
    //         // character at ith position of word1 with the character at jth
    //         // position of word2 and then move forward
    //         int opt3 = 1 + solveUsingRecursion(word1, word2, i + 1, j + 1);
    //         // as required by the question we take the minimum of all 3
    //         options ans = min(opt1, min(opt2, opt3));
    //     }
    //     return ans; // return the answer for that particular call
    // }

    // int solveUsingMemo(string& word1, string& word2, int i, int j,
    //                    vector<vector<int>>& dp) {
    //     // base cases
    //     // if we reach the end of any of the strings, we return
    //     // the length of the remaining string
    //     if (i >= word1.length()) {
    //         return word2.length() - j;
    //     }
    //     if (j >= word2.length()) {
    //         return word1.length() - i;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     int ans = 0;
    //     // if characters are same, no operation is required
    //     if (word1[i] == word2[j]) {
    //         ans = 0 + solveUsingMemo(word1, word2, i + 1, j + 1, dp);
    //     }
    //     // if characters are not same, we have 3 options: insert, remove,
    //     // replace (all 3 are equally valid) and we'll take the minimum of
    //     // all
    //     // 3 options as our answer for that particular call
    //     else {
    //         // insert
    //         // we don't increment i because we want to insert the character
    //         // at jth position of word2 in word1
    //         int opt1 = 1 + solveUsingMemo(word1, word2, i, j + 1, dp);
    //         // remove
    //         // we don't increment
    //         // j because we want to remove the character at ith position
    //         // of word1
    //         int opt2 = 1 + solveUsingMemo(word1, word2, i + 1, j, dp);
    //         // replace
    //         // we increment both i and j because we want to replace the
    //         // character at ith position of word1 with the character at jth
    //         // position of word2 and then move forward
    //         int opt3 = 1 + solveUsingMemo(word1, word2, i + 1, j + 1, dp);
    //         // as required by the question we take the minimum of all 3
    //         // options
    //         ans = min(opt1, min(opt2, opt3));
    //     }
    //     return dp[i][j] = ans; // return the answer for that particular call
    // }

    int solveUsingTabu(string &a, string &b, vector<vector<int>> &dp)
    {
        for (int col = 0; col <= b.length(); col++)
        {
            dp[a.length()][col] = b.length() - col;
        }
        for (int row = 0; row <= a.length(); row++)
        {
            dp[row][b.length()] = a.length() - row;
        }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 0 + dp[i + 1][j + 1];
                }
                else
                {
                    // insert
                    // we don't increment i because we want to insert the character
                    // at jth position of word2 in word1
                    int opt1 = 1 + dp[i][j + 1];
                    // remove
                    // we don't increment
                    // j because we want to remove the character at ith position
                    // of word1
                    int opt2 = 1 + dp[i + 1][j];
                    // replace
                    // we increment both i and j because we want to replace the
                    // character at ith position of word1 with the character at jth
                    // position of word2 and then move forward
                    int opt3 = 1 + dp[i + 1][j + 1];
                    // as required by the question we take the minimum of all 3
                    // options
                    ans = min(opt1, min(opt2, opt3));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int solveUsingTabuSpaceOpti(string a, string b)
    {
        vector<int> curr(a.length() + 1, 0);
        vector<int> next(a.length() + 1, 0);

        for (int row = 0; row <= a.length(); row++)
        {
            next[row] = a.length() - row;
        }

        for (int j = b.length() - 1; j >= 0; j--)
        {
            // fill the last cell of curr col
            // most imp line
            curr[a.length()] = b.length() - j;
            ;
            for (int i = a.length() - 1; i >= 0; i--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 0 + next[i + 1];
                }
                else
                {
                    // insert
                    // we don't increment i because we want to insert the character
                    // at jth position of word2 in word1
                    int opt1 = 1 + next[i];
                    // remove
                    // we don't increment
                    // j because we want to remove the character at ith position
                    // of word1
                    int opt2 = 1 + curr[i + 1];
                    // replace
                    // we increment both i and j because we want to replace the
                    // character at ith position of word1 with the character at jth
                    // position of word2 and then move forward
                    int opt3 = 1 + next[i + 1];
                    // as required by the question we take the minimum of all 3
                    // options
                    ans = min(opt1, min(opt2, opt3));
                }
                curr[i] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2)
    {
        int i = 0;
        int j = 0;
        // int ans = solveUsingRecursion(word1, word2, i, j);
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, -1));
        // int ans = solveUsingMemo(word1, word2, i, j, dp);
        int ans = solveUsingTabuSpaceOpti(word1, word2);
        return ans;
    }
};

int main()
{
    string word1 = "horse";
    string word2 = "ros";
    Solution obj;
    cout << obj.minDistance(word1, word2) << endl;
    return 0;
}