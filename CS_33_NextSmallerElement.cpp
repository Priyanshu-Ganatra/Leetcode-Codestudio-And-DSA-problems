#include <bits/stdc++.h>
using namespace std;

// tc: O(n) and sc: O(n)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        // finding the answer for curr elem
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = nextSmallerElement(arr, arr.size());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}