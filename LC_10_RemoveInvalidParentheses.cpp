#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string &s, unordered_set<string> &ans, int invalidOpen, int invalidClose, int bal, int index, string &output)
    {
        if (index >= s.length())
        {
            if (invalidOpen == 0 && invalidClose == 0 && bal == 0)
            {
                ans.insert(output);
            }
            return;
        }

        if (s[index] != '(' && s[index] != ')')
        {
            // a letter found, just include it
            output.push_back(s[index]);
            solve(s, ans, invalidOpen, invalidClose, bal, index + 1, output);
            // backtrack
            output.pop_back();
        }
        else
        {
            // 2 cases -> ( or )
            // Open bracket
            if (s[index] == '(')
            {
                // inc/exc
                // remove current bracket
                if (invalidOpen > 0)
                {
                    solve(s, ans, invalidOpen - 1, invalidClose, bal, index + 1, output);
                }
                // not remove current bracket
                output.push_back(s[index]);
                solve(s, ans, invalidOpen, invalidClose, bal + 1, index + 1, output);
                // backtrack
                output.pop_back();
            }
            else if (s[index] == ')')
            {
                // inc/exc
                // remove current bracket
                if (invalidClose > 0)
                {
                    solve(s, ans, invalidOpen, invalidClose - 1, bal, index + 1, output);
                }
                // **IMP**
                // not remove current bracket
                if (bal > 0)
                {
                    // opening bracket is present
                    output.push_back(')');
                    solve(s, ans, invalidOpen, invalidClose, bal - 1, index + 1, output);
                    // backtrack
                    output.pop_back();
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> ans;
        int invalidOpen = 0, invalidClose = 0, balance = 0, index = 0;
        string output = "";

        for (auto ch : s)
        {
            if (ch == '(')
            {
                invalidOpen++;
            }
            else if (ch == ')')
            {
                if (invalidOpen > 0)
                {
                    invalidOpen--;
                }
                else
                {
                    invalidClose++;
                }
            }
        }

        solve(s, ans, invalidOpen, invalidClose, balance, index, output);
        return vector<string>(ans.begin(), ans.end());
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.removeInvalidParentheses("()())()");
    for (auto str : ans)
    {
        cout << str << " ";
    }
    return 0;
}