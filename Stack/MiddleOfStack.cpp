#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans){
    if(pos == 1){
        ans = st.top();
        return;
    }
    int elem = st.top();
    st.pop();
    solve(st, --pos, ans);
    st.push(elem); // backtrack
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    int size = st.size();
    int mid;
    if(st.empty()){
        cout << "Stack empty!";
        return 0;
    }
    if (size & 1) // odd
    {
        mid = (size/2) + 1;
    }
    else // even
    {
        mid = (size/2);
    }
    int ans = 0;
    solve(st, mid, ans);
    cout << "Middle element: " << ans;
}
