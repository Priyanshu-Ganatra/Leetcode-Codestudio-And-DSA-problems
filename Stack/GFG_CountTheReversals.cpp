#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{
    // if the size of string is odd, then it's not possible to make pairs
    if (s.size() & 1)
        return -1;

    int ans = 0;
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    // if stack isn't empty yet, the expression is unbalanced
    // we'll now count the amount of braces reversals that'll make it balanced
    while (!st.empty())
    {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        if (a == b)
            ans += 1;
        else
            ans += 2;
    }
    return ans;
}

int main()
{
    string s = "}{{}}{{{";
    cout << countRev(s) << endl;
    return 0;
}