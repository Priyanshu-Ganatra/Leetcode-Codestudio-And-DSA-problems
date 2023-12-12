#include <bits/stdc++.h>
using namespace std;

// tc
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{
    queue<int> q; // store the index of the negative elements in the window
    vector<int> ans; // store the answer elements
    // process first k elements - 1st window
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0) 
            q.push(i);
    }

    // process remaining windows -> remove the element which is out of the window and add the new e lement
    for (int i = k; i < n; i++)
    {
        // before further processing, add the negative element of the previous window in the answer arra if it exists in the queue
        if (!q.empty())
            ans.push_back(arr[q.front()]);
        else
            ans.push_back(0);
        // remove the front element if it is out of the window
        if (i - q.front() >= k)
            q.pop();
        // add the new element if it is negative, i.e. consider it for the next window if is negative
        if (arr[i] < 0)
            q.push(i);
    }

    // process the last window
    if (!q.empty())
        ans.push_back(arr[q.front()]);
    else
        ans.push_back(0);

    return ans;
}

int main()
{
    vector<int> arr = {2, -5, 4, -1, -2, 0, 5};
    int k = 3;
    int n = arr.size();
    vector<int> ans = firstNegativeInteger(arr, k, n);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}