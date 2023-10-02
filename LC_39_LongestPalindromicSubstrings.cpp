#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

string longestPalindrome(string s)
{
    // brute - tc: O(n^3) & sc: O(1), I'll implement the optimized DP based solution in the future
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                string temp = s.substr(i, j - i + 1);
                if (temp.size() > ans.size())
                    ans = temp;
            }
        }
    }
    return ans;
}

int main()
{
    string s = "babad";
    cout << longestPalindrome(s) << endl;
    return 0;
}
