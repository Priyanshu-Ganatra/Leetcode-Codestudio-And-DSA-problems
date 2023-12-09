#include <bits/stdc++.h>
using namespace std;

// tc: O(n) | sc: O(n)
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    // step 1: push all the people in the stack
    for (int i = 0; i < n; i++)
    {
        st.push(i); 
    }
    
    // step 2: run discard method, to get a possible celebrity
    while (st.size() != 1)
    {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        // if a knows b, a can't be a celebrity
        if (M[a][b] == 1)
        {
            // a isn't a celebrity, b might be
            st.push(b);
        }
        else
        {
            // b isn't a celebrity, a might be
            st.push(a);
        }
    }
    // step 3: check if the possible celebrity is actually a celebrity
    int possibleCelebrity = st.top(); st.pop();
    // celebrity knows no one
    for (int i = 0; i < n; i++)
    {
        if (M[possibleCelebrity][i] == 1)
        {
            return -1;
        }
    }
    // everyone knows celebrity
    for (int i = 0; i < n; i++)
    {
        if (M[i][possibleCelebrity] == 0 && i != possibleCelebrity)
        {
            return -1;
        }
    }
    return possibleCelebrity; // possibleCelebrity is a celebrity
}

int main()
{
    vector<vector<int>> M = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    cout << "Celebrity:" << endl;
    cout << celebrity(M, 3) << endl;
    return 0;
}