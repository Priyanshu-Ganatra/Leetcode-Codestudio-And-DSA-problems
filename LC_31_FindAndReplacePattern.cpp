#include <bits/stdc++.h>
using namespace std;

// this function normalizes all the words and patterns into a similar format,
// so that we can compare them and find the solution.
// ex.: str = "prr", mapping[p] = 'a', mapping[r] = 'b'.
// then updates the string a/c to mapping of each char,
// mapping[p] = 'a' -> str[0] = mapping[p],
// mapping[r] = 'b' -> str[1] = mapping[r]
// thus "prr" gets converted to "abb"
void createMappingAndUpdateString(string &str)
{
    // find mapping
    char start = 'a';
    char mapping[256] = {0};
    for (auto ch : str)
    {
        if (mapping[ch] == 0)
        {
            mapping[ch] = start;
            start++;
        }
    }

    // update the string
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        str[i] = mapping[ch];
    }
}

// tc: O(n*m) & sc: O(m), where n = words.size() and m = temp.size()
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> ans;
    // first normalize the pattern
    createMappingAndUpdateString(pattern);

    // check if any word matches the newly mapped pattern
    for (string s : words)
    {
        string temp = s;

        // normalize temp string to match with the pattern
        createMappingAndUpdateString(temp);
        if (temp == pattern)
        {
            // this means the current string is a valid match
            ans.push_back(s);
        }
    }
    return ans;
}

int main()
{
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";
    vector<string> ans = findAndReplacePattern(words, pattern);
    for (string s : ans)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}