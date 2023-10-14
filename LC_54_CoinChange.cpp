#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &coins, int amount)
{
    // base case
    if (amount == 0)
        return 0;
    int minimumAmountOfCoins = INT_MAX;
    if (amount < 0)
        return INT_MAX; // INT_MAX is returned to avoid the case when (amount is not divisible by any of the coins)/(when the amount is negative)

    for (int coin : coins)
    {
        // only use the current coin if its value is less than or =
        // the current amount, else the amount will be calculated
        // in negative
        if (coin <= amount)
        {
            int recAns = solve(coins, amount - coin);
            // if the amount is not possible to make with the current coin then INT_MAX will be returned by the recursive call and we don't want
            // to include that in our answer so we'll skip it and move to the next coin in the coins array to check if it is possible to make the
            // amount with that coin or not
            if (recAns != INT_MAX)
            {
                int ans = 1 + recAns; // 1 is added to include the current coin
                minimumAmountOfCoins = min(minimumAmountOfCoins, ans);
            }
        }
    }
    return minimumAmountOfCoins; // this will be triggered when none of the coins can be used to make the amount
}

// recursive solution, gives TLE on leetcode. we'll use DP to optimize it in future
int coinChange(vector<int> &coins, int amount)
{
    int ans = solve(coins, amount);
    if (ans == INT_MAX)
        return -1;
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
