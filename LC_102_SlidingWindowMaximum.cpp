#include <bits/stdc++.h>
using namespace std;

// tc : O(n) sc : O(n)
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;    
    deque<int> q; // store the index of the maximum elements in the window  
    // process first k elements - 1st window
    for (int i = 0; i < k; i++)
    {
        // remove the elements which are smaller than the current element because they can't be the maximum element in the window
        while (!q.empty() && nums[i] >= nums[q.back()]) 
            q.pop_back();
        q.push_back(i); // add the current element as it can be the maximum element in the window and the next window
    }
    // process remaining windows -> remove the element which is out of the window and add the new the element
    for (int i = k; i < nums.size(); i++)
    {
        ans.push_back(nums[q.front()]); // add the maximum element of the previous window in the answer array
        // remove the front element if it is out of the window
        if (i - q.front() >= k)
            q.pop_front();
        // remove the elements which are smaller than the current element because they can't be the maximum element in the window
        while (!q.empty() && nums[i] >= nums[q.back()]) 
            q.pop_back();
        q.push_back(i); // add the current element as it can be the maximum element in the window and the next window
    }
    // process the last window
    ans.push_back(nums[q.front()]);
    return ans;
}