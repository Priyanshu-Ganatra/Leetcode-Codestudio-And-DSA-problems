#include <bits/stdc++.h>
using namespace std;

void solve(string &s, char c, int i, int &ans)
{
    // base case
    if (i >= s.length())
        return;
    // calculation
    if (s[i] == c)
    {
        ans = i;
    }
    solve(s, c, i + 1, ans);
}

int main()
{
    string str = "abcabcabc";
    char c = 'c';
    int ans = -1;
    solve(str, c, 0, ans);
    cout << "Last occurence of " << c << " is at index: ";
    cout << ans;
    return 0;
}
