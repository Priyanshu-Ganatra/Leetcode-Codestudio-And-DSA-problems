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
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// tc: O(n) and sc: O(n)
vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        // finding the answer for curr elem
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

// tc : O(n) and sc: O(n)
int largestRectangleArea(vector<int> &heights)
{
    int size = heights.size();
    vector<int> next = nextSmallerElement(heights, size);
    for (int i = 0; i < size; i++)
    {
        if (next[i] == -1)
        {
            next[i] = heights.size();
        }
    }
    vector<int> prev = prevSmallerElement(heights, size);
    vector<int> area(size);
    for (int i = 0; i < size; i++) 
    {
        int width = next[i] - prev[i] - 1;
        int length = heights[i];
        int currArea = width * length;
        area[i] = currArea;
    }

    int maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi, area[i]);
    }
    return maxi;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}