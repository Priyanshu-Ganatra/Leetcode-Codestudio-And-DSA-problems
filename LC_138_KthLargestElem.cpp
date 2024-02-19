#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    // process 1st k elements
    for (int i = 0; i < k; i++)
    {
        int elem = nums[i];
        pq.push(elem);
    }

    for (int i = k; i < nums.size(); i++)
    {
        int elem = nums[i];
        if (elem > pq.top())
        {
            pq.pop();
            pq.push(elem);
        }
    }
    return pq.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}