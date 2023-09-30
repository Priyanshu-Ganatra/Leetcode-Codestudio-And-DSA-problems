#include <bits/stdc++.h>
using namespace std;

int expand(string s, int i, int j)
{
    int cnt = 0;
    while (i >= 0 && j <= s.length() && s[i] == s[j])
    {
        cnt++;
        i--;
        j++;
    }
    return cnt;
}

// tc: O(n^2) & sc O(1)
int countSubstrings(string s)
{
    // total no. of substrings = even length substrings + odd length substrings
    int totalCount = 0;

    for (int center = 0; center < s.length(); center++)
    {
        // find all odd length substrings for current position
        int oddAns = expand(s, center, center);
        // find all even length substrings for current position
        int evenAns = expand(s, center, center + 1);

        totalCount = totalCount + oddAns + evenAns;
    }
    return totalCount;
}

int main()
{
    string s = "abc";
    cout << countSubstrings(s) << endl;
    return 0;
}