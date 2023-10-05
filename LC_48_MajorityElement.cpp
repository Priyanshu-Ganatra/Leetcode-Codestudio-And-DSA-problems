#include <bits/stdc++.h>
using namespace std;

// Boyer-Moore Voting Algorithm O(n) time O(1) space
int majorityElement(vector<int> &nums)
{
    int counter = 0, majority;
    for (int num : nums)
    {
        if (!counter)
        {
            majority = num;
        }
        counter += num == majority ? 1 : -1;
    }
    return majority;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    cout << majorityElement(nums) << endl;
    return 0;
}