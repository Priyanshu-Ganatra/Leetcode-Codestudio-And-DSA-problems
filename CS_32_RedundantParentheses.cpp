#include <bits/stdc++.h>
using namespace std;

// tc: O(n) | sc: O(n)
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            bool isOpPresent = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    isOpPresent = 1;
                }
                st.pop();
            }
            // here either stack has become empty or its top has '('
            st.pop(); // remove the '('

            if (!isOpPresent)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    string s = "((a+b))";
    cout << findRedundantBrackets(s) << endl;
    return 0;
}