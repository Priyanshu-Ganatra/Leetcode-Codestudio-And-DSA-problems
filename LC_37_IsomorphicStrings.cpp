#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int hash[256] = {0}; // stores mapping of s[i] to t[i]
    bool isCharMapped[256] = {0}; // stores if t[i] is already mapped to some char in s[

    for(int i = 0; i<s.size(); i++){
        if (hash[s[i]] == 0 && isCharMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            isCharMapped[t[i]] = true;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] != t[i])
            return false;
    }
    return true;
}

int main()
{
    string s = "egg", t = "add";
    cout << isIsomorphic(s, t) << endl;
    return 0;
}