#include <bits/stdc++.h>
using namespace std;

// tc: O(n) | sc: O(n)
bool isValid(string s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (st.empty())
            st.push(ch);
        else
        {
            if ((ch == ')' && st.top() == '(') || (ch == ']' && st.top() == '[') || (ch == '}' && st.top() == '{'))
            {
                st.pop();
            }
            else
                st.push(ch);
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    string s = "([)]";
    cout << isValid(s) << endl;
    return 0;
}