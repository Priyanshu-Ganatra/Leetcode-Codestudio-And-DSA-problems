#include <bits/stdc++.h>
using namespace std;

// top-down approach
// rec + memoization
// tc - O(n) and sc - O(n)
// int solveUsingMemo(int n, vector<int> &dp)
// {
//     // base case
//     if (n == 0 || n == 1)
//         return n;

//     // step 3 - if ans already exists then return it
//     if (dp[n] != -1)
//         return dp[n];

//     // recursive relation
//     // step 2 - store and return using dp array
//     dp[n] = solveUsingMemo(n - 1, dp) + solveUsingMemo(n - 2, dp);
//     return dp[n];
// }

int solveUsingTabulation(int n)
{
    // step 1 - create dp array
    vector<int> dp(n + 1, -1);
    // step 2 - analyse base case & fill dp array
    dp[0] = 0;
    if (n == 0)
        return dp[0];
    dp[1] = 1;
    // step 3 - fill the remaining dp array
    // array size = n+1
    // indexes upto => n
    // 0 & 1 indexes are alread filled
    // remaining indexes 2 -> n
    for (int i = 2; i <= n; i++)
    {
        // copy paste the recursive logic
        // replace recursive calls with dp array
        // make sure indexing in dp array is using looping variable "i"
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // return ans
    return dp[n];
}

int fib(int n)
{
    // // step 1 - create dp array (Memoization)
    // vector<int> dp(n+1, -1);
    // return solveUsingMemo(n, dp);
    return solveUsingTabulation(n);
}

int main()
{
    int n = 10;
    cout << "Fibonacci number at index " << n << " is: ";
    cout << fib(n) << endl;
    return 0;
}