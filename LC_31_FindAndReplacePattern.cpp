#include <bits/stdc++.h>
using namespace std;

// this function normalizes all the words and patterns into a similar format,
// so that we can compare them and find the solution.
// ex.: str = "prr", mapping[p] = 'a', mapping[r] = 'b'.
// then updates the string a/c to mapping of each char,
// mapping[p] = 'a' -> str[0] = mapping[p],
// mapping[r] = 'b' -> str[1] = mapping[r]
// thus "prr" gets converted to "abb"
class Solution
{
public:
    void createMappingAndUpdate(string &s)
    {
        unordered_map<char, char> m;
        char c = 'a';
        for (auto it : s)
        {
            if (!m.count(it))
            {
                m[it] = c++;
            }
        }
        for (auto i = 0; i < s.size(); i++)
        {
            s[i] = m[s[i]];
        }
    }

    // Tc: O(N×L) & Sc: O(N*L) where N is the number of words and L is the length of each word.
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        string p = pattern;
        createMappingAndUpdate(p);
        vector<string> ans;

        for (string s : words)
        {
            string copy = s;
            createMappingAndUpdate(copy);

            if (copy == p)
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";
    vector<string> res = s.findAndReplacePattern(words, pattern);
    for (string str : res)
    {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}