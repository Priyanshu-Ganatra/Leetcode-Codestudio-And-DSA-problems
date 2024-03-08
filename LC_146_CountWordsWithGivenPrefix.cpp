#include <bits/stdc++.h>
using namespace std;
 
class TrieNode
{
public:
    char val;
    TrieNode *children[26];
    bool isTerminal;
    // a word can be repeated, so each time it's repeated we increase this count
    int count = 0;

    TrieNode(char val)
    {
        this->val = val;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        this->isTerminal = false;
    }
};

// tc : O(n) where n is the length of the word & sc : O(n) where n is the length of the word
void insertNode(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        root->count++;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    // recursion
    insertNode(child, word.substr(1));
}

class Solution
{
    void countChildrenWords(TrieNode *root, int &cnt)
    {
        if (root->isTerminal)
        {
            for (int i = 1; i <= root->count; i++)
            {
                cnt++;
            }
        }

        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            int index = ch - 'a';
            TrieNode *next = root->children[index];

            if (next != NULL)
            {
                // child exists
                countChildrenWords(next, cnt);
            }
        }
    }

    void countWords(TrieNode *root, string pref, int &count)
    {
        // base case
        if (pref.length() == 0)
        {
            countChildrenWords(root, count);
        }

        char ch = pref[0];
        int index;
        if (pref.size() != 0)
            index = ch - 'a';
        else
            return;
        TrieNode *next = root->children[index];

        if (next != NULL)
        {
            next = root->children[index];
        }
        else
            return;

        countWords(next, pref.substr(1), count);
    }

public:
    TrieNode *root = new TrieNode('-');
    int prefixCount(vector<string> &words, string pref)
    {
        for (auto word : words)
        {
            insertNode(root, word);
        }
        int count = 0;
        countWords(root, pref, count);
        return count;   
    }
};

int main()
{
    Solution s;
    vector<string> words = {"abc", "abcd", "abce", "abcf", "abcg", "abch"};
    string pref = "abc";
    cout << s.prefixCount(words, pref) << endl;
    return 0;
}