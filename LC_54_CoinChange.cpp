#include <bits/stdc++.h>
using namespace std;

// tc: O(n^amount) sc: O(n)
// int solveUsingRecursion(vector<int> &coins, int amount)
// {
//     // base cases
//     // if amount = 0 then I don't need to use no coin so I return 0
//     if (amount == 0)
//         return 0;
//     int minimumAmountOfCoins = INT_MAX;
//     // when the amount becomes negative we return minimumAmountOfCoins i.e. INT_MAX
//     if (amount < 0)
//         return minimumAmountOfCoins;

//     for (int coin : coins)
//     {
//         // only use the current coin if its value is less than or =
//         // the current amount, else the amount will be calculated
//         // in negative
//         if (coin <= amount)
//         {
//             int recAns = solveUsingRecursion(coins, amount - coin);
//             // if the amount is not possible to make with the current coin
//             // then INT_MAX will be returned by the recursive call and we
//             // don't want to include that in our answer so we'll skip it and
//             // move to the next coin in the coins array to check if it is
//             // possible to make the amount with that coin or not
//             if (recAns != minimumAmountOfCoins)
//             {
//                 int ans = 1 + recAns; // 1 is added to include the current coin
//                 minimumAmountOfCoins = min(minimumAmountOfCoins, ans);
//             }
//         }
//     }
//     return minimumAmountOfCoins;
// }

// tc: O(n * amount) sc: O(n)
// int solveUsingMemo(vector<int> &coins, int amount, vector<int> &dp)
// {
//     // base cases
//     // if amount = 0 then I don't need to use no coin so I return 0
//     if (amount == 0)
//         return 0;
//     int minimumAmountOfCoins = INT_MAX;
//     // when the amount becomes negative we return minimumAmountOfCoins i.e. INT_MAX
//     if (amount < 0)
//         return minimumAmountOfCoins;

//     // if ans already exists then return it
//     if (dp[amount] != -1)
//         return dp[amount];

//     for (int coin : coins)
//     {
//         // only use the current coin if its value is less than or =
//         // the current amount, else the amount will be calculated
//         // in negative
//         if (coin <= amount)
//         {
//             int recAns = solveUsingMemo(coins, amount - coin, dp);
//             // if the amount is not possible to make with the current coin
//             // then INT_MAX will be returned by the recursive call and we
//             // don't want to include that in our answer so we'll skip it and
//             // move to the next coin in the coins array to check if it is
//             // possible to make the amount with that coin or not
//             if (recAns != INT_MAX)
//             {
//                 int ans = 1 + recAns; // 1 is added to include the current coin
//                 minimumAmountOfCoins = min(minimumAmountOfCoins, ans);
//             }
//         }
//     }
//     dp[amount] = minimumAmountOfCoins;
//     return dp[amount];
// }

// tc: O(n * amount) sc: O(n)
int solveUsingTabulation(vector<int> &coins, int &amount, vector<int> &dp)
{
    int n = amount; // n is the amount
    dp[0] = 0; // base case
    for (int i = 1; i <= n; i++) // i is the current amount
    {
        int minimumAmountOfCoins = INT_MAX; // minimum amount of coins required to make the current amount
        // for each coin in the coins array check if it is possible to make the current amount with it or not
        for (int coin : coins)
        {
            // only use the current coin if its value is less than or = the current amount, else the amount will be calculated in negative
            if (coin <= i)
            {
                int minCoinsTillNow = dp[i - coin]; // minimum amount of coins required to make the amount till now
                if (minCoinsTillNow != INT_MAX) 
                {
                    int ans = 1 + minCoinsTillNow;
                    minimumAmountOfCoins = min(minimumAmountOfCoins, ans);
                }
            }
        }
        dp[i] = minimumAmountOfCoins;
    }
    return dp[n];
}

int coinChange(vector<int> &coins, int amount)
{
    // int ans = solveUsingRecursion(coins, amount);
    int n = amount;
    vector<int> dp(n + 1, -1);
    // int ans = solveUsingMemo(coins, amount, dp);
    int ans = solveUsingTabulation(coins, amount, dp);
    if (ans == INT_MAX)
        return -1;
    else
        return ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum number of coins required to make " << amount << " is: ";
    cout << coinChange(coins, amount) << endl;
    return 0;
}
