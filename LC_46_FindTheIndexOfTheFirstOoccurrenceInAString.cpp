#include <bits/stdc++.h>
using namespace std;

// sliding window - tc: O(mn) & sc: O(1)
int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (haystack[i + j] != needle[j])
                break;
            if (j == m - 1)
                return i;
        }
    }
    return -1;
}

int main()
{
    string haystack = "hello", needle = "ll";
    cout << strStr(haystack, needle) << endl;
    return 0;
}
