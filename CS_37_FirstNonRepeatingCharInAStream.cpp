#include <bits/stdc++.h>
using namespace std;

vector<char> firstNonRepeating(string stream)
{
    vector<char> ans;
    queue<char> q;
    int freq[26] = {0};

    // traverse input stream, increase freq count of current char, add it to queue
    // remove it from queue if it is repeating (freq more than 1), this will help
    // to constrain the comparisons as we remove the repeating char, we need not to
    // worry about it in the next iteration.
    // if the current char isn't repeating add it to ans and stop
    for (int i = 0; i < stream.length(); i++)
    {
        char ch = stream[i];
        freq[ch - 'a']++;
        q.push(ch);

        // finding answer
        while (!q.empty())
        {
            char frontChar = q.front();
            if (freq[frontChar - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                // freq = 1, this is the answer
                ans.push_back(frontChar);
                break;
            }
        }
        // here either the entire while loop has exhausted indicating that all chars
        // were repeated, or the 1st non-repeating char was encountered and loop broke
    }
    return ans;
}

int main()
{
    string stream = "bbabcbcab ";
    vector<char> ans = firstNonRepeating(stream);
    for (auto ch : ans)
        cout << ch << " ";
    cout << endl;
    return 0;
}
