#include <bits/stdc++.h>
using namespace std;

// tc : O(n) & sc : O(1)
string reorganizeString(string s)
{
    int hash[26] = {0};
    
    for(int i = 0; i < s.size(); i++)
        hash[s[i] - 'a']++;
    
    // find the max frequency character
    char maxFreqChar;
    int maxFreq = 0;
    for(int i = 0; i < 26; i++)
    {
        if(hash[i] > maxFreq)
        {
            maxFreq = hash[i];
            maxFreqChar = i + 'a';
        }
    }

    int index = 0;
    while(maxFreq>0 && index < s.size())
    {
        s[index] = maxFreqChar;
        index += 2;
        maxFreq--;
    }

    if(maxFreq != 0) return "";
    
    hash[maxFreqChar - 'a'] = 0; // to avoid the maxFreqChar to be considered again

    // fill the remaining characters
    for(int i = 0; i < 26; i++)
    {
        while(hash[i] > 0)
        {
            if(index >= s.size()) index = 1;
            s[index] = i + 'a';
            index += 2;
            hash[i]--;
        }
    }
    return s;
}

int main()
{
    string s = "aab";
    cout << reorganizeString(s) << endl;
    return 0;
}