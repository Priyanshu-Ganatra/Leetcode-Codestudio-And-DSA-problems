#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    // brute: tc: O(n + n/2) & sc: O(2n)
    // int n = nums.size();
    // vector<int> ans;
    // vector<int> neg;
    // vector<int> pos;
    // for(auto it:nums){
    //     if(it>0) pos.push_back(it);
    //     else neg.push_back(it);
    // }

    // for(int i = 0; i < n/2; i++){
    //     ans.push_back(pos[i]);
    //     ans.push_back(neg[i]);
    // }
    // return ans;

    // Two pointers optimal solution: tc & sc: O(n)
    int n = nums.size();
    vector<int> ans(n);
    int even = 0, odd = 1;
    for (auto elem : nums)
    {
        if (elem > 0)
        {
            ans[even] = elem;
            even += 2;
        }
        else
        {
            ans[odd] = elem;
            odd += 2;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> ans = rearrangeArray(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}