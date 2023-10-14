#include <bits/stdc++.h>
using namespace std;

void findSubsequences(string inp, string out, int idx)
{
    // answer has been built in the output string
    if (idx >= inp.length())
    {
        if (out == "")
        {
            cout << "*empty_str*";
        }

        cout << out << endl;
        return;
    }
    char ch = inp[idx];
    // exclude the current character
    findSubsequences(inp, out, idx + 1);

    // include the current character
    out.push_back(ch);
    findSubsequences(inp, out, idx + 1);
}

int main()
{
    string inp = "abc";
    string out = "";
    int idx = 0;
    cout << "All subsequences of " << inp << " are: " << endl;
    findSubsequences(inp, out, idx);
    return 0;
}
