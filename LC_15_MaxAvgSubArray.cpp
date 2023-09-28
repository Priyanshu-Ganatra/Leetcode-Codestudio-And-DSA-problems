#include <bits/stdc++.h>
using namespace std;

// TC: O(n square)
double bruteForceSol(vector<int> &nums, int &k)
{
    int maxSum = INT_MIN;
    int i = 0, j = k - 1;
    while (j < nums.size())
    {
        int sum = 0;
        for (int y = i; y <= j; y++)
        {
            sum += nums[y];
        }
        maxSum = max(maxSum, sum);
        i++, j++;
    }
    double maxAvg = maxSum / (double)k;
    return maxAvg;
}

// TC: O(n)
double slidingWindowSol(vector<int> &nums, int &k)
{
    int i = 0, j = k - 1;
    int sum = 0;
    for (int y = i; y <= j; ++y)
    {
        sum += nums[y];
    }
    int maxSum = sum;
    j++;
    while (j < nums.size())
    {
        sum -= nums[i++];
        sum += nums[j++];
        maxSum = max(maxSum, sum);
    }

    double maxAvg = maxSum / (double)k;
    return maxAvg;
}

double findMaxAverage(vector<int> &nums, int k)
{
    return slidingWindowSol(nums, k);
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << findMaxAverage(nums, k);
    return 0;
}