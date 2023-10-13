#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    // this checks if the array is sorted or not
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            cnt++;
        }
    }
    // this checks if the array is rotated or not
    if (nums[n - 1] > nums[0])
    {
        cnt++;
    }
    // if cnt   is less than or equal to 1 then the array is sorted and rotated because if the array is sorted then cnt will be 0 and if the array is rotated then cnt will be 1
    return cnt <= 1;
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << check(nums) << endl;
    return 0;
}