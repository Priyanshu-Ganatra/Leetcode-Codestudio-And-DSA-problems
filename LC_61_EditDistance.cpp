#include <bits/stdc++.h>
using namespace std;

int solve(string &word1, string &word2, int i, int j)
{
    // base cases
    // if we reach the end of any of the strings, we return the length of the remaining string
    if (i >= word1.length())
    {
        return word2.length() - j;
    }
    if (j >= word2.length())
    {
        return word1.length() - i;
    }

    int ans = 0;
    if (word1[i] == word2[j]) // if characters are same, no operation is required
    {
        ans = 0 + solve(word1, word2, i + 1, j + 1);
    }
    else // if characters are not same, we have 3 options: insert, remove, replace (all 3 are equally valid) and we'll take the minimum of all 3 options as our answer for that particular call
    {
        // insert
        int opt1 = 1 + solve(word1, word2, i, j + 1); // we don't increment i because we want to insert the character at jth position of word2 in word1
        // remove
        int opt2 = 1 + solve(word1, word2, i + 1, j); // we don't increment j because we want to remove the character at ith position of word1
        // replace
        int opt3 = 1 + solve(word1, word2, i + 1, j + 1); // we increment both i and j because we want to replace the character at ith position of word1 with the character at jth position of word2 and then move forward
        ans = min(opt1, min(opt2, opt3));                 // as required by the question we take the minimum of all 3 options
    }
    return ans; // return the answer for that particular call
}

// recursive solution, gives TLE, we'll use DP to optimize it in future
// tc: O(3^n) sc: O(n)
int minDistance(string word1, string word2)
{
    int i = 0;
    int j = 0;
    int ans = solve(word1, word2, i, j);
    // horse -> rorse (replace 'h' with 'r')
    // rorse -> rose (remove 'r')
    // rose -> ros (remove 'e')
    return ans;
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";
    cout << "Minimum number of operations required to convert word1 to word2: ";
    cout << minDistance(word1, word2) << endl;
    return 0;
}