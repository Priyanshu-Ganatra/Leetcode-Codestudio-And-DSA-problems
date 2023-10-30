#include <bits/stdc++.h>
using namespace std;

int maxSubArrayHelper(vector<int> &v, int s, int e)
{
    if (s == e) // base case
        return v[s]; 
    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN; // max border sum for left and right subarray
    int mid = s + ((e - s) >> 1);

    int maxLeftSum = maxSubArrayHelper(v, s, mid); // max subarray sum for left subarray
    int maxRightSum = maxSubArrayHelper(v, mid + 1, e); // max subarray sum for right subarray

    // Max cross border sum for left and right subarray
    int leftBorderSum = 0, rightBorderSum = 0; // max border sum for left and right border
    for (int i = mid; i >= s; i--)
    {
        leftBorderSum += v[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    for (int i = mid + 1; i <= e; i++)
    {
        rightBorderSum += v[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
    return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}

// Divide and Conquer approach 
// tc: O(nlogn) sc: O(logn)
int maxSubArray(vector<int> &nums)
{
    return maxSubArrayHelper(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum:" << endl;
    cout << maxSubArray(nums) << endl;
    return 0;
}