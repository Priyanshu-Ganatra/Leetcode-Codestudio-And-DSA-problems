#include <bits/stdc++.h>
using namespace std;

bool f(int i, string &str)
{
    if (i >= str.size() / 2)
        return true;
    if (str[i] != str[str.size() - i - 1])
        return false;
    return f(i + 1, str);
}
bool isPalindrome(string &str)
{
    return f(0, str);
}

int main()
{
    string s = "abca";
    cout << isPalindrome(s) << endl;
    return 0;
}