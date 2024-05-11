#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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