#include <bits/stdc++.h>
using namespace std;

void printSubarrays_util(vector<int> &nums, int s, int e)
{
    // base case
    if (e == nums.size())
    {
        return;
    }

    // calculation
    for (int i = s; i <= e; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    // recursive call
    printSubarrays_util(nums, s, e + 1);
}

// tc: O(n^2) and sc: O(n)
void printSubarrays(vector<int> &nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        int end = start;
        printSubarrays_util(nums, start, end);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << "All subarrays of the given array are: " << endl;
    printSubarrays(nums);
    return 0;
}