#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
    // brute: tc - O(n) and sc - O(n)
    string ans = "";
    int idx = 0;
    while (idx < s.length())
    {
        if (ans.length() > 0 && ans[ans.length() - 1] == s[idx])
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[idx]);
        }
        idx++;
    }
    return ans;
}

int main()
{
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;
    return 0;
}