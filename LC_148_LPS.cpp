#include <bits/stdc++.h>
using namespace std;

int solveUsingTabuSpaceOpti(string &a, string &b, int i, int j)
{
    vector<int> curr(a.length() + 1, 0);
    vector<int> next(a.length() + 1, 0);

    for (int j = b.length() - 1; j >= 0; j--)
    {
        for (int i = a.length() - 1; i >= 0; i--)
        {
            if (a[i] == b[j])
            {
                curr[i] = 1 + next[i + 1];
            }
            else
            {
                curr[i] = 0 + max(curr[i + 1], next[i]);
            }
        }
        next = curr;
    }
    return next[0];
} 

int longestPalindromeSubseq(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return solveUsingTabuSpaceOpti(s, rev, 0, 0);
}

int main()
{
    string s = "bbbab";
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}