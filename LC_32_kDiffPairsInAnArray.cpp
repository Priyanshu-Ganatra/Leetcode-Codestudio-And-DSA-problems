#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &nums, int start, int x)
{
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == x)
        {
            return mid;
        }
        else if (x > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int findPairs(vector<int> &nums, int k)
{
    // 2 pointers, tc(n*logn) & sc: O(n)
    // sort(nums.begin(), nums.end());
    // set<pair<int,int>> ans;
    // int i = 0, j = 1;
    // while(j < nums.size()){
    //     int diff = nums[j] - nums[i];
    //     if(diff == k){
    //         ans.insert({nums[i], nums[j]});
    //         i++, j++;
    //     }
    //     else if(diff > k){
    //         i++;
    //     }
    //     else{
    //         j++;
    //     }
    //     if(i == j) j++; // edge case when k = 0, the pairs should not have same indexes
    // }
    // return ans.size();

    // binary search, tc: O(n*logn) & sc: O(n)
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (bs(nums, i + 1, nums[i] + k) != -1)
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }
    return ans.size();
}

int main()
{
    vector<int> nums = {3, 1, 4, 1, 5};
    int k = 2;
    cout << findPairs(nums, k) << endl;
    return 0;
}