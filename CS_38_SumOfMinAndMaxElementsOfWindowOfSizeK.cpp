#include <bits/stdc++.h>
using namespace std;

// tc : O(n) sc : O(n)
long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
    long long ans = 0;    
    deque<int> dq1, dq2; // store the index of the maximum and minimum elements in the window  
    // process first k elements - 1st window
    for (int i = 0; i < k; i++)
    {
        // remove the elements which are smaller than the current element because they can't be the maximum element in the window
        while (!dq1.empty() && nums[i] >= nums[dq1.back()]) 
            dq1.pop_back();
        // remove the elements which are greater than the current element because they can't be the minimum element in the window
        while (!dq2.empty() && nums[i] <= nums[dq2.back()]) 
            dq2.pop_back();
        dq1.push_back(i); // add the current element as it can be the maximum element in the window and the next window
        dq2.push_back(i); // add the current element as it can be the minimum element in the window and the next window
    }
    ans += nums[dq1.front()] + nums[dq2.front()]; // add the maximum and minimum element of the previous window in the answer array


    // process remaining windows -> remove the element which is out of the window and add the new the element
    for (int i = k; i < nums.size(); i++)
    {
        // remove the front element if it is out of the window
        if (i - dq1.front() >= k) // if the maximum element is out of the window
            dq1.pop_front();
        if (i - dq2.front() >= k) // if the minimum element is out of the window
            dq2.pop_front();

        // remove the elements which are smaller than the current element because they can't be the maximum element in the window
        while (!dq1.empty() && nums[i] >= nums[dq1.back()]) 
            dq1.pop_back();

        // remove the elements which are greater than the current element because they can't be the minimum element in the window
        while (!dq2.empty() && nums[i] <= nums[dq2.back()]) 
            dq2.pop_back();
        dq1.push_back(i); // add the current element as it can be the maximum element in the window and the next window
        dq2.push_back(i); // add the current element as it can be the mimimum element in the window and the next window

        ans += nums[dq1.front()] + nums[dq2.front()]; // find the ans for the current window
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;
    int n = nums.size();
    cout << sumOfMaxAndMin(nums, n, k) << endl;
    return 0;
}