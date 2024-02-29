#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char val;
    TrieNode *children[26];
    bool isTerminal;

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

// tc : O(n) where n is the length of the word & sc : O(1)
bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
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
        return false;
    }

    // recursion
    return searchWord(child, word.substr(1));
}

// if word is present in the trie, then delete it and return true else return false
// tc : O(n) where n is the length of the word & sc : O(1)
bool deleteWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        if (root->isTerminal)
        {
            root->isTerminal = false;
            return true;
        }
        else
        {
            return false;
        }
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
        return false;
    }

    // recursion
    bool ans = deleteWord(child, word.substr(1));

    // if child node is useless, then delete it
    if (child->isTerminal == false)
    {
        for (int i = 0; i < 26; i++)
        {
            if (child->children[i] != NULL)
            {
                return ans;
            }
        }
        delete child;
        root->children[index] = NULL;
    }

    return ans;
}

int main()
{
    TrieNode *root = new TrieNode('-');
    insertNode(root, "hello");
    insertNode(root, "hell");
    insertNode(root, "world");
    string word = "hell";
    if (searchWord(root, word))
    {
        cout << "\"" << word << "\""
             << " is present in the trie" << endl;
    }
    else
    {
        cout << "\"" << word << "\""
             << " is not present in the trie" << endl;
    }

    if (deleteWord(root, word) == true)
    {
        cout << "\"" << word << "\""
             << " is deleted from the trie" << endl;
    }
    else
    {
        cout << "\"" << word << "\""
             << " is not present in the trie so can't delete" << endl;
    }

    if (searchWord(root, word))
    {
        cout << "\"" << word << "\""
             << " is still present in the trie" << endl;
    }
    else
    {
        cout << "\"" << word << "\""
             << " is now not present in the trie" << endl;
    }
    return 0;
}
