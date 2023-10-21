#include <bits/stdc++.h>
using namespace std;

void maxProfitFinder(vector<int> &prices, int i, int &minPrice, int &maxProfit){
    // base
    if (i == prices.size())
    {
        return;
    }

    // sol for one case
    if (prices[i] < minPrice) minPrice = prices[i]; // update minPrice if current price is less than minPrice
    int todaysProfit = prices[i] - minPrice; // calculate profit for today
    if (todaysProfit > maxProfit) maxProfit = todaysProfit; // update maxProfit if today's profit is greater than maxProfit

    // recursive call
    maxProfitFinder(prices, i + 1, minPrice, maxProfit); // call for next day
}

int maxProfit(vector<int> &prices)
{
    // TLE - tc: O(n^2), sc: O(1)
    // int diff = 0;
    // for (int i = 0; i < prices.size(); i++)
    // {
    //     for (int j = i + 1; j < prices.size(); j++)
    //     {
    //         diff = max(prices[j] - prices[i], diff);
    //     }
    // }
    // return diff;

    // recursive - tc: O(n), sc: O(n)
    int minPrice = INT_MAX;
    int maxProfit = INT_MIN;
    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

int main()
{
    vector<int> v = {7,1,5,3,6,4};
    cout << maxProfit(v);
    return 0;
}