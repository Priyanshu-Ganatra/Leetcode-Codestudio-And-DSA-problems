#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(n^2)
    double bruteForceSol(vector<int>& nums, int& k) {
        int maxSum = INT_MIN;
        int i = 0, j = k - 1;
        while (j < nums.size()) {
            int sum = 0;
            sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
            maxSum = max(maxSum, sum);
            i++, j++;
        }
        
        return maxSum / (double)k;
    }

    // TC: O(n)
    double slidingWindowSol(vector<int>& nums, int& k) {
        int i = 0, j = k - 1;
        int sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);

        int maxSum = sum;
        while (j < nums.size()) {
            if (j + 1 == nums.size())
                break;
            sum -= nums[i++];
            sum += nums[++j];
            maxSum = max(maxSum, sum);
        }

        return maxSum / (double)k;
    }

    double findMaxAverage(vector<int>& nums, int k) {
        // return bruteForceSol(nums, k);
        return slidingWindowSol(nums, k);
    }
};

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    Solution obj;
    cout << "Maximum average subarray of size " << k << " is: " << obj.findMaxAverage(nums, k) << endl;
    return 0;
}