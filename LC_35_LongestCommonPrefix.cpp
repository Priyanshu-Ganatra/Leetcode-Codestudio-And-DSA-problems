#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    string ans;
    int i = 0;
    while (true)
    {
        char ch = 0;
        for (auto str: strs)
        {
            if (i >= str.size())
            {
                // out of bounds 
                ch = 0;
                break;
            }
            if(ch == 0)
            {
                ch = str[i];
            }
            else if(str[i] != ch)
            {
                ch = 0;
                break;
            }
        }
        if(ch == 0)
        {
            break;
        }
        ans.push_back(ch);
        i++;
    }
    return ans;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}
