#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int newi = (i + k) % n;
        ans[newi] = nums[i];
    }
    nums = ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
    cout << "The rotated array is: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}