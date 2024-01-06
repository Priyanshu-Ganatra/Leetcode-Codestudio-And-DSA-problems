#include <bits/stdc++.h>
using namespace std;

// int solveUsingRecursion(int n, int x, int y, int z)
// {
//     // base cases
//     if (n == 0)
//         return 0; // 0 cuts are required to make 0 length rod
//     if (n < 0)
//         return INT_MIN; // INT_MIN is returned to avoid the case when (n is not divisible by any of x, y, z)/(n is negative)

//     // 1 is added to include the current cut and then we recursively call for the remaining length of the rod
//     int option1 = 1 + solveUsingRecursion(n - x, x, y, z);
//     int option2 = 1 + solveUsingRecursion(n - y, x, y, z);
//     int option3 = 1 + solveUsingRecursion(n - z, x, y, z);

//     int finalAns = max(option1, max(option2, option3)); // maximum of the three options is returned
//     return finalAns;
// }

// top-down memoization
// tc - O(n) and sc - O(n)
int solveUsingMemo(int n, int x, int y, int z, vector<int> &dp)
{
    // base cases
    if (n == 0)
        return 0; // 0 cuts are required to make 0 length rod
    if (n < 0)
        return INT_MIN; // INT_MIN is returned to avoid the case when (n is not divisible by any of x, y, z)/(n is negative)

    // step 3 - if ans already exists then return it
    if (dp[n] != -1)
        return dp[n];

    // 1 is added to include the current cut and then we recursively call for the remaining length of the rod
    int option1 = 1 + solveUsingMemo(n - x, x, y, z, dp);
    int option2 = 1 + solveUsingMemo(n - y, x, y, z, dp);
    int option3 = 1 + solveUsingMemo(n - z, x, y, z, dp);

    dp[n] = max(option1, max(option2, option3)); // maximum of the three options is returned
    // step 2 - return using dp array
    return dp[n];
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    // return solveUsingRecursion(n, x, y, z);
    // step 1 - create dp array
    vector<int> dp(n + 1, -1);
    int ans = solveUsingMemo(n, x, y, z, dp);

    // if ans is negative then return 0
    if (ans < 0)
        return 0;
    return ans;
}

int main()
{
    int n = 5, x = 1, y = 2, z = 3;
    cout << "Maximum number of cuts: ";
    cout << maximizeTheCuts(n, x, y, z);
    return 0;
}
