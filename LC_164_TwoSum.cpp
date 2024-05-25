#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tc : O(nlogn) & sc : O(n)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = i;
            int value = nums[i];
            pair<int, int> p = {value, index};
            temp.push_back(p);
        }
        sort(temp.begin(), temp.end());

        int s = 0, e = nums.size() - 1;

        while (s < e)
        {
            int sum = temp[s].first + temp[e].first;
            if (sum == target)
            {
                return {temp[s].second, temp[e].second};
            }
            else if (sum > target)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        return {};
    }

    // tc : O(n) & sc : O(n)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     unordered_map<int, int> numMap;
    //     int n = nums.size();

    //     for (int i = 0; i < n; i++) {
    //         int complement = target - nums[i];
    //         if (numMap.count(complement)) {
    //             return {numMap[complement], i};
    //         }
    //         numMap[nums[i]] = i;
    //     }

    //     return {}; // No solution found
    // }

    // tc: O(n^2) & sc: O(1)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     for(int i = 0; i<n; i++){
    //         for(int j = 0; j<n; j++){
    //             if(i == j) continue;

    //             if(nums[i] + nums[j] == target) return {i, j};
    //         }
    //     }
    //     return {};
    // }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = sol.twoSum(nums, target);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}