#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        // tc: O(n^2) & sc(1)
        // int n = nums.size();
        // for(int i = 0; i<n; i++){
        //     int lsum = 0, rsum = 0, pivot = 0;
        //     for(int j=0; j<i; j++) lsum += nums[j];
        //     for(int j=i+1; j<n; j++) rsum += nums[j];
        //     if(lsum == rsum) return i;
        // }
        // return -1;

        // tc: O(n) & sc(n)
        // vector<int> lsum(nums.size(), 0);
        // vector<int> rsum(nums.size(), 0);
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     lsum[i] = lsum[i - 1] + nums[i - 1];
        // }
        // for (int j = nums.size() - 2; j >= 0; j--)
        // {
        //     rsum[j] = rsum[j + 1] + nums[j + 1];
        // }
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (lsum[i] == rsum[i])
        //         return i;
        // }
        // return -1;

        // tc: O(n) & sc(1)
        int totalWeightOnLeft = 0;
        int totalWeightOnRight = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int currentWeight = nums[i];
            totalWeightOnRight -= currentWeight;
            if (totalWeightOnLeft == totalWeightOnRight)
            {
                // balance is met on both sides
                return i;
            }
            totalWeightOnLeft += currentWeight;
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << obj.pivotIndex(nums) << endl;
    return 0;
}