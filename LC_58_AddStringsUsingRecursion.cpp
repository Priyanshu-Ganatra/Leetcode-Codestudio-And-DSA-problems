#include <bits/stdc++.h>
using namespace std;

// this will calculate the sum of two strings using recursion in reverse order
void addRE(string &num1, int p1, string &num2, int p2, string &ans, int carry = 0)
{
    // base case
    if (p1 < 0 && p2 < 0)
    {
        if (carry != 0)
        {
            ans.push_back(carry + '0');
        }
        return;
    }

    // calculation
    // if p1 is valid then take the value else take 0
    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    // if p2 is valid then take the value else take 0
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
    int csum = n1 + n2 + carry;
    int digit = csum % 10;
    carry = csum / 10;
    ans.push_back(digit + '0');

    // recursive call
    addRE(num1, p1 - 1, num2, p2 - 1, ans, carry);
}

// tc: Θ(n+1*k) where n is the length of the longest string and k is the number of recursive calls
// sc: Θ(n+1*m)
string addStrings(string num1, string num2)
{
    string ans = "";
    addRE(num1, num1.length() - 1, num2, num2.length() - 1, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string num1 = "11";
    string num2 = "11";
    cout << "Sum of " << num1 << " and " << num2 << " is: ";
    cout << addStrings(num1, num2) << endl;
    return 0;
}