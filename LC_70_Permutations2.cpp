#include <bits/stdc++.h>
using namespace std;

void permuteUniqueHelper(vector<int> &nums, vector<vector<int>> &ans, int start)
{
    // base case
    if (start == nums.size()) // if start reaches end of array then push to ans
    {
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> visited;
    for (int i = start; i < nums.size(); i++) // for each index in array from start to end of array 
    {
        if (visited.find(nums[i]) != visited.end()) // if already visited then skip
        {
            continue;
        }
        visited[nums[i]] = true; // mark current element as visited
        swap(nums[i], nums[start]); // swap current index with start index
        permuteUniqueHelper(nums, ans, start + 1); // recursive call for next index to be swapped
        swap(nums[i], nums[start]); // backtrack to original array because we need to swap with other elements
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;
    permuteUniqueHelper(nums, ans, 0);
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ans = permuteUnique(nums);
    for (auto &vector : ans)
    {
        for (auto &vectorElem : vector)
        {
            cout << vectorElem << ' ';
        }
    }
}