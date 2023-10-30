#include <bits/stdc++.h>
using namespace std;

void combinationSumHelper(vector<int> &candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int index)
{
    // base cases
    if (target == 0) // target is achieved
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0) // target is not achieved, this happens when we choose an element greater than the current target value
    {
        return;
    }

    // recursive cases
    // for every recursive call we will start from the current index until the end of the array, thus ignoring the elements before the current index as they are already considered
    for (int i = index; i < candidates.size(); i++)
    {
        if(i > index && candidates[i] == candidates[i - 1]) continue; // skip the duplicates by checking if the current element is same as the previous element
        temp.push_back(candidates[i]); // choose the element
        // i + 1 bcoz we can't choose the same element again and if the target is negative then we will 
        // simply return and then we will backtrack (i.e. remove the current element from the temp vector) and move to the next element in the for loop
        combinationSumHelper(candidates, target - candidates[i], temp, ans, i + 1); 
        temp.pop_back();
    }
}

// tc: O(2^N) sc: O(N)
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;                                       // to store the current combination
    combinationSumHelper(candidates, target, temp, ans, 0); // 0 is the starting index
    set<vector<int>> s(ans.begin(), ans.end());
    ans.clear();
    for (auto i : s)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> ans = combinationSum2(candidates, target);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
