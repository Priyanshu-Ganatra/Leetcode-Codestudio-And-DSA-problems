#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        return;
    }
    cout << nums[idx] << " ";
    printArray(nums, idx + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    printArray(nums, 0);
    return 0;
}