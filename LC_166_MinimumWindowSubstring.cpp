#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int len1 = s.length();
        int len2 = t.length();

        if (len1 < len2)
            return "";

        int ansIndex = -1;
        int ansLen = INT_MAX;

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        // store freq of each char in t
        for (char c : t)
        {
            tMap[c]++;
        }
        // count variable to keep track of how many chars in t are present in the current window
        int count = 0, start = 0, end = 0;
        while (end < s.length())
        {
            char ch = s[end];
            // update sMap
            sMap[ch]++;
            // check if the current char is present in t
            if (sMap[ch] <= tMap[ch])
            {
                count++;
            }

            if (count == len2)
            {
                // window found with all chars of t, now minimize the window
                // minimize only when the char on s index is extra
                while (sMap[s[start]] > tMap[s[start]])
                {
                    sMap[s[start]]--;
                    start++;
                }
                // update the answer
                int windowLen = end - start + 1;
                if (windowLen < ansLen)
                {
                    ansLen = windowLen;
                    ansIndex = start;
                }
            }
            end++;
        }

        if (ansIndex == -1)
            return "";
        else
            return s.substr(ansIndex, ansLen);
    }
};

int main()
{
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << endl;
    return 0;
}