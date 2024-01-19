#include <bits/stdc++.h>
using namespace std;

// printing dp table
void print(vector<vector<int>> &dp)
{
    for (auto row : dp)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}

// tc: O(2^n) sc: O(n)
// int solvesingRecursion(int capacity, vector<int> &wt, vector<int> &profit, int i, int &n){
//     // base case
//     if(i >= n){
//         return 0;
//     }

//     // inc/exc
//     int inc = 0;
//     if(wt[i] <= capacity){
//         inc = profit[i] + solvesingRecursion(capacity-wt[i], wt, profit, i+1, n);
//     }
//     int exc = 0 + solvesingRecursion(capacity, wt, profit, i+1, n);
//     return max(inc, exc);
// }

// tc: O(n*capacity) sc: O(n*capacity)
// int solvesingMemo(int capacity, vector<int> &wt, vector<int> &profit, int i, int &n, vector<vector<int>> &dp)
// {
//     // base case
//     if (i >= n)
//     {
//         return 0;
//     }

//     // check if already calculated
//     if (dp[capacity][i] != -1)
//     {
//         return dp[capacity][i];
//     }

//     // inc/exc
//     int inc = 0;
//     if (wt[i] <= capacity)
//     {
//         inc = profit[i] + solvesingMemo(capacity - wt[i], wt, profit, i + 1, n, dp);
//     }
//     int exc = 0 + solvesingMemo(capacity, wt, profit, i + 1, n, dp);
//     dp[capacity][i] = max(inc, exc);
//     return dp[capacity][i];
// }

// tc: O(n*capacity) sc: O(n*capacity)
// int solveUsingTabu(int capacity, vector<int> &wt, vector<int> &profit, vector<vector<int>> &dp, int &n)
// {
//     for (int row = 0; row <= capacity; row++)
//     {
//         dp[row][n] = 0;
//     }

//     for (int i = 0; i <= capacity; i++)
//     {
//         for (int j = n-1; j >= 0; j--)
//         {
//             // inc/exc
//             int inc = 0;
//             if (wt[j] <= i)
//             {
//                 inc = profit[j] + dp[i - wt[j]][j + 1];
//             }
//             int exc = 0 + dp[i][j + 1];
//             dp[i][j] = max(inc, exc);
//         }
//     }
//     return dp[capacity][0];
// }

// tc: O(n*capacity) sc: O(capacity)
// int solveUsingTabuSpaceOpti(int capacity, vector<int> &wt, vector<int> &profit, int &n)
// {
//     vector<int> nextCol(capacity + 1, 0);
//     vector<int> currCol(capacity + 1, -1);

//     for (int j = n - 1; j >= 0; j--)
//     {
//         for (int i = 0; i <= capacity; i++)
//         {
//             // inc/exc
//             int inc = 0;
//             if (wt[j] <= i)
//             {
//                 inc = profit[j] + nextCol[i - wt[j]];
//             }
//             int exc = 0 + nextCol[i];
//             currCol[i] = max(inc, exc);
//         }
//         nextCol = currCol;
//     }
//     return currCol[capacity];
// }

// tc: O(n*capacity) sc: O(capacity)
int solveUsingTabuSpaceOpti2(int capacity, vector<int> &wt, vector<int> &profit, int &n)
{
    vector<int> nextCol(capacity + 1, 0);
    // vector<int> currCol(capacity + 1, -1);

    for (int j = n - 1; j >= 0; j--)
    {
        for (int i = capacity; i >= 0; i--)
        {
            // inc/exc
            int inc = 0;
            if (wt[j] <= i)
            {
                inc = profit[j] + nextCol[i - wt[j]];
            }
            int exc = 0 + nextCol[i];
            nextCol[i] = max(inc, exc);
        }
        
    }
    return nextCol[capacity];
}

int knapsack(vector<int> weight, vector<int> profit, int n, int capacity)
{
    int i = 0;
    // return solvesingRecursion(capacity, weight, profit, i, n);
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, -1));
    // return solveUsingMemo(capacity, weight, profit, i, n, dp);
    // int ans = solveUsingTabu(capacity, weight, profit, dp, n);
    // int ans = solveUsingTabuSpaceOpti(capacity, weight, profit, n);
    int ans = solveUsingTabuSpaceOpti2(capacity, weight, profit, n);
    cout << "DP table:" << endl;
    print(dp);
    cout << endl;
    cout << "Max profit:" << endl;
    return ans;
}

int main()
{
    vector<int> weight = {1, 2, 3};
    vector<int> profit = {10, 15, 40};
    int n = weight.size();
    int capacity = 6;
    cout << knapsack(weight, profit, n, capacity) << endl;
    return 0;
}