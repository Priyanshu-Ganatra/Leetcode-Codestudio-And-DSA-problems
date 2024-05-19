#include <bits/stdc++.h>
using namespace std;

// tc = O(2^n * n), sc = O(2^n)
vector<string> subsequences(string str)
{
    int n = str.length();
    vector<string> ans;
    //  for n = 3, (1<<n) i.e. 2^3 will be 8
    for (int num = 1; num < (1 << n); num++)
    {
        // use num to create subseqences
        string temp = "";
        // num -> set bit -> index -> char -> include
        for (int i = 0; i < n; i++)
        {
            // i -> index
            char ch = str[i];
            // if there's a set bit at i idx in the num then include the char at that
            // index
            int mask = (1 << i);
            if (num & mask)
            {
                temp.push_back(ch);
            }
        }
        ans.push_back(temp);
    }
    for (auto s : ans)
        cout << s << endl;
    return ans;
}

int main()
{
    string str;
    cin >> str;
    subsequences(str);
    return 0;
}