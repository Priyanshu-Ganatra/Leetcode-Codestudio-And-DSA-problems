#include <bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

bool validPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            // remove 1 char either from left or right
            // check palindrome for remaining string after removal
            bool ans1 = checkPalindrome(s, i + 1, j); // remove ith char
            bool ans2 = checkPalindrome(s, i, j - 1); // remove jth char
            return ans1 || ans2;
        }
    }
    return true;
}

int main()
{
    string s = "abca";
    cout << validPalindrome(s) << endl;
    return 0;
}