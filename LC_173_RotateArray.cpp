#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tc : O(n), sc : O(n)
    void method1(vector<int> &nums, int n, int k)
    {
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int newi = (i + k) % n;
            ans[newi] = nums[i];
        }
        nums = ans;
    }

    // tc : O(n), sc : O(1)
    void method2(vector<int> &nums, int n, int k)
    {
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.begin() + n);
        reverse(nums.begin(), nums.end());
    }

    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        // method1(nums, n, k);
        method2(nums, n, k);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    sol.rotate(nums, k);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}