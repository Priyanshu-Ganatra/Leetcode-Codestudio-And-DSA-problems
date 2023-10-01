#include <bits/stdc++.h>
using namespace std;

string decodeMessage(string key, string message)
{
    // create mapping (encoding)
    char mapping[256] = {0};
    char start = 'a';
    for (char c : key)
    {
        if (c != ' ' && mapping[c] == 0)
        {
            mapping[c] = start;
            start++;
        }
    }

    // use mapping (decoding)
    string ans;
    for (char ch : message)
    {
        if (ch == ' ')
        {
            ans.push_back(' ');
        }
        else
        {
            char decodedChar = mapping[ch];
            ans.push_back(decodedChar);
        }
    }
    return ans;
}

int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    cout << decodeMessage(key, message) << endl;
    return 0;
}