#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s, int k)
{
    string ans = "";
    int idx = 0;
    while (idx < s.length())
    {
        int temp = k - 1;
        bool isRepeated = false;
        while (temp)
        {
            if (idx + temp >= s.length())
            {
                break;
            }

            if (s[idx] == s[idx + temp])
            {
                isRepeated = true;
            }
            else
            {
                isRepeated = false;
            }
            --temp;
        }

        if (!isRepeated)
        {
            ans.push_back(s[idx]);
            idx++;
        }
        else
        {
            idx += k;
        }
    }
    return ans;
}

int countCharactersWithKOrMoreOccurrences(const string input, int k)
{
    unordered_map<char, int> charCount;

    // Count the occurrences of each character in the input string
    for (char c : input)
    {
        charCount[c]++;
    }

    int count = 0;

    // Iterate through the character count map and count characters that appear k or more times
    for (const auto &pair : charCount)
    {
        if (pair.second >= k)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int k = 3;
    string s = "deeedbbcccbdaa";
    int cnt = countCharactersWithKOrMoreOccurrences(s, k);
    for (int i = 0; i < cnt; i++)
    {
        s = removeDuplicates(s, k);
    }
    cout << s << endl;
    return 0;
}