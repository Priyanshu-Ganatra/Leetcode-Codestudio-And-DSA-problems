#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxi;
}

int main()
{
    cout << "Array: ";
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
    cout << "Max consecutive ones: ";
    cout << findMaxConsecutiveOnes(nums);
    return 0;
}