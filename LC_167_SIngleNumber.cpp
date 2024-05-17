#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
            ans ^= x;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << s.singleNumber(nums) << "\n";
    return 0;
}