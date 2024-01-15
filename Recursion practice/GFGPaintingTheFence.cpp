#include <bits/stdc++.h>
using namespace std;

// tc: O(2^n) sc: O(n)
// long long solveUsingRecursion(int n, int k)
// {
//     // base case
//     if (n == 1)
//     {
//         return k;
//     }
//     if (n == 2)
//     {
//         return k + k * (k - 1);
//     }
//     // k-1 is because we can't have more than 2 consecutive fences of same color in a row
//     long long ans = (k - 1) * (solveUsingRecursion(n - 2, k) + solveUsingRecursion(n - 1, k));
//     return ans;
// }

// tc: O(n*k) sc: O(n)
// long long solveUsingMemo(int n, int k, vector<long long> &dp)
// {
//     // base case
//     if (n == 1)
//     {
//         return k;
//     }
//     if (n == 2)
//     {
//         return k + k * (k - 1);
//     }

//     // check if already calculated
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }

//     // k-1 is because we can't have more than 2 consecutive fences of same color in a row
//     dp[n] = (k - 1) * (solveUsingMemo(n - 2, k, dp) + solveUsingMemo(n - 1, k, dp));
//     return dp[n];
// }

// tc: O(n) sc: O(n)
// long long solveUsingTabulation(int n, int k, vector<long long> &dp){
//     // base case
//     dp[1] = k;
//     dp[2] = k + k * (k - 1);

//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = (k - 1) * (dp[i - 2] + dp[i - 1]);
//     }
//     return dp[n];
// }

// tc: O(n) sc: O(1)
long long solveUsingTabulationSpaceOpti(int n, int k)
{
    // base case
    long long prev2 = k;
    long long prev1 = k + k * (k - 1);
    long long curr = 0;

    if (n == 1)
    {
        return prev2;
    }
    if (n == 2)
    {
        return prev1;
    }

    for (int i = 3; i <= n; i++)
    {
        curr = (k - 1) * (prev1 + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

long long countWays(int n, int k)
{
    // return solveUsingRecursion(n, k);
    vector<long long> dp(n + 1, -1);
    // return solveUsingMemo(n, k, dp);
    // return solveUsingTabulation(n, k, dp);
    return solveUsingTabulationSpaceOpti(n, k);
}

// hardcoded main function
int main()
{
    int n = 3, k = 2;
    cout << "Number of ways to paint the fence such that at most 2 adjacent fences have same color: " << endl;
    cout << countWays(n, k) << endl;
    return 0;
}