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

// tc: O(n*m) and sc: O(n*m)
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> v; // int matrix as we need to find max area using histogram solution
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) // rows
    {
        vector<int> temp;
        for (int j = 0; j < m; j++) // cols
        {
            temp.push_back(matrix[i][j] - '0'); // converting char to int
        }
        v.push_back(temp); // pushing each converted row to v
    }

    int area = largestRectangleArea(v[0]); // finding max area for first row
    for (int i = 1; i < n; i++) // starting from second row as we have already found max area for first row
    {
        for (int j = 0; j < m; j++) // cols
        {
            if (v[i][j] == 1) // if current elem is 1 then only we need to update it
            {
                // let's update current row with values from previous row
                if (v[i][j]) // if current elem is 1 then only we need to update it
                {
                    v[i][j] += v[i - 1][j]; // adding the previous row value to current row value
                }
                else
                {
                    v[i][j] = 0; // if current elem is 0 then we don't need to update it as the histogram will be 0 if its base is 0
                }
            }
        }
        area = max(area, largestRectangleArea(v[i])); // finding max area for current row
    }
    return area; // returning max area
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(matrix) << endl;
    return 0;
}