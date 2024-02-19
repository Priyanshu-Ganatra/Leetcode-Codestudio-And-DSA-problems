#include <bits/stdc++.h>
using namespace std;

class Info
{
public:
    char val;
    int count;
    Info(char ch, int cnt)
    {
        val = ch;
        count = cnt;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->count < b->count;
    }
};

// tc : O(n) & sc : O(1)
// string reorganizeString(string s)
// {
//     int hash[26] = {0};

//     for(int i = 0; i < s.size(); i++)
//         hash[s[i] - 'a']++;

//     // find the max frequency character
//     char maxFreqChar;
//     int maxFreq = 0;
//     for(int i = 0; i < 26; i++)
//     {
//         if(hash[i] > maxFreq)
//         {
//             maxFreq = hash[i];
//             maxFreqChar = i + 'a';
//         }
//     }

//     int index = 0;
//     while(maxFreq>0 && index < s.size())
//     {
//         s[index] = maxFreqChar;
//         index += 2;
//         maxFreq--;
//     }

//     if(maxFreq != 0) return "";

//     hash[maxFreqChar - 'a'] = 0; // to avoid the maxFreqChar to be considered again

//     // fill the remaining characters
//     for(int i = 0; i < 26; i++)
//     {
//         while(hash[i] > 0)
//         {
//             if(index >= s.size()) index = 1;
//             s[index] = i + 'a';
//             index += 2;
//             hash[i]--;
//         }
//     }
//     return s;
// }

string reorganizeString(string s)
{
    int freq[26] = {0};

    // count freq of all chars in s
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        freq[ch - 'a']++;
    }

    // push all chars in max heap
    priority_queue<Info *, vector<Info *>, compare> maxHeap;
    // push all chars with freq > 0 in heap
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            Info *temp = new Info(i + 'a', freq[i]);
            maxHeap.push(temp);
        }
    }

    string ans = "";
    while (maxHeap.size() > 1)
    {
        Info *first = maxHeap.top();
        maxHeap.pop();
        Info *second = maxHeap.top();
        maxHeap.pop();

        ans.push_back(first->val);
        first->count--;
        ans.push_back(second->val);
        second->count--;

        if (first->count > 0)
        {
            maxHeap.push(first);
        }
        if (second->count > 0)
        {
            maxHeap.push(second);
        }
    }

    // if 1 char remains
    if (maxHeap.size() == 1)
    {
        Info *first = maxHeap.top();
        maxHeap.pop();

        ans.push_back(first->val);
        first->count--;

        if (first->count != 0)
        {
            // ans isn't possible
            return "";
        }
    }
    return ans;
}

int main()
{
    string s = "aab";
    cout << reorganizeString(s) << endl;
    return 0;
}