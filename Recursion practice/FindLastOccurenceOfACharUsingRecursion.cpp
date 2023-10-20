#include <bits/stdc++.h>
using namespace std;

// tc : O(n) & sc : O(n)
// left to right
// void solve(string &s, char c, int i, int &ans)
// {
//     // base case
//     if (i >= s.length())
//         return;
//     // calculation
//     if (s[i] == c)
//     {
//         ans = i;
//     }
//     solve(s, c, i + 1, ans);
// }

// tc : O(n) & sc : O(n)
// right to left 
void solve(string &s, char c, int i, int &ans)
{
    // base case
    if (i < 0)
        return;
    // calculation
    if (s[i] == c)
    {
        ans = i;
        return;
    }
    solve(s, c, i - 1, ans);
}

int main()
{
    string str = "abcabcabc";
    char c = 'c';
    int ans = -1;
    // solve(str, c, 0, ans); // left to right
    solve(str, c, str.length() - 1, ans); // right to left 
    cout << "Last occurence of " << c << " in string \"" << str << "\" is at index: ";
    cout << ans;
    return 0;
}
