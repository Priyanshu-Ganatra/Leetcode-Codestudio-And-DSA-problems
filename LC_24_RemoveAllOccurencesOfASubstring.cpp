#include <bits/stdc++.h>
using namespace std;

void solve(string &s, string part)
{
    int pos = s.find(part);
    if (pos != string::npos)
    {
        // part string ha been located
        // now we remove it
        string left_part = s.substr(0, pos);
        string right_part = s.substr(pos + part.size(), s.size()); // pos + part.size() because we want to remove the part string 
        s = left_part + right_part;
        return solve(s, part);
    }
    else{
        // base case - all the occurences of part string has been removed
        return;
    }
}

// recursive approach - tc : O(n^2) & sc: O(n/m)
// tc breakdown:
// 1. find() - O(n*m)
// 2. left part - O(n)
// 3. right part - O(n)
// 4. concatenation - O(n)
// 5. recursion - O(n/m)
// total = O(n*m * n/m) = O(n^2) - n is the length of string and m is the length of part string
string removeOccurrences(string s, string part)
{
    solve(s, part);
    return s;
}

// tc : O(n*m) & sc: O(1) - non recursive
// string removeOccurrences(string &s, string &part)
// {
//     while (s.find(part) != string::npos)
//     {
//         s.erase(s.find(part), part.length());
//     }
//     return s;
// }a

int main()
{
    string s = "daabcbaabcbc";
    string part = "abc";
    cout << removeOccurrences(s, part) << endl;
}