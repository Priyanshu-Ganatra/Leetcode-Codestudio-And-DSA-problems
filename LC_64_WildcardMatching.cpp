#include <bits/stdc++.h>
using namespace std;

bool isMatchingHelper(string &s, int si, string &p, int pi)
{
    // base cases
    if (si == s.size() && pi == p.size())
        return true;
    if (si == s.size() & pi < p.size())
    {
        while (pi < p.size())
        {
            if (p[pi] != '*')
                return false;
            pi++;
        }
        return true;
    }

    // single char matching
    if (s[si] == p[pi] || p[pi] == '?')
    {
        return isMatchingHelper(s, si + 1, p, pi + 1);
    }
    // multi-char matching i.e. '*' is encountered in pattern
    if (p[pi] == '*')
    {
        // treat '*' as null char, by matching s[si] with p[pi + 1]
        bool caseA = isMatchingHelper(s, si, p, pi + 1);
        // let '*' consume 1 char, by ignoring s[si] and matching s[si + 1]
        // with p[pi]
        bool caseB = isMatchingHelper(s, si + 1, p, pi);
        return caseA || caseB;
    }
    // chars doesn't match
    return false;
}

// tc : O(2^(max(|s|, |p|))) & sc : O(n)
// recursive solution gives TLE for large inputs, will solve with DP in the future
bool isMatch(string s, string p)
{
    int si = 0; // ptr index for s
    int pi = 0; // ptr index for p

    return isMatchingHelper(s, si, p, pi);
}

int main()
{
    // harcode 
    string s = "abbaaaabbbbbababbbbbbbbaaabaabbabaabbaaabbbbabbbbab";
    string p = "a*aaba***b**a*a********b";
    cout << "s: " << s << endl;
    cout << "p: " << p << endl;
    cout << "Does s match p? :" << endl;
    if(isMatch(s, p))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}