#include <bits/stdc++.h>
using namespace std;

// tc : O(n*m) & sc: O(1)
string removeOccurrences(string &s, string &part)
{
    while (s.find(part) != string::npos)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(s, part) << endl;
}