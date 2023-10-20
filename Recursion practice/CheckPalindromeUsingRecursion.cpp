#include <bits/stdc++.h>
using namespace std;

// tc : O(n) sc : O(n)
bool isPalindrome(string &str, int s, int e)
{
    // base case
    if(s >= e) return true;

    // calculation
    if (str[s] != str[e])
    {
        return false;
    }

    // recursive call
    return isPalindrome(str, s + 1, e - 1);
}

int main()
{
    string str = "racecar"; 
    cout << "Is " << str << " a palindrome? ";
    string ans = (isPalindrome(str, 0, str.length() - 1)) ? "Yes" : "No";
    cout << ans;
    return 0;
}