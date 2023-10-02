#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    // brute tc: O(nlogn), sc: O(1)
    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());
    // return s == t;

    // hash table tc:O(n + m), sc: O(1)
    int freqTable[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        freqTable[s[i]]++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        freqTable[t[i]]--;
    }

    for (int i = 0; i < 256; i++)
    {
        if (freqTable[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "anagram", t = "nagaram";
    cout << isAnagram(s, t) << endl;
    return 0;
}