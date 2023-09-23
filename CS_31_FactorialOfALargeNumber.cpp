#include <bits/stdc++.h>
using namespace std;

// On GFG, this is the solution:
// vector<int> factorial(int N)
// {
//     // code here
//     vector<int> ans;
//     ans.push_back(1);
//     int carry = 0;
//     for (int i = 2; i <= N; i++)
//     {
//         for (int j = 0; j < ans.size(); j++)
//         {
//             int val = ans[j] * i + carry;
//             ans[j] = val % 10;
//             carry = val / 10;
//         }

//         // if carry exits
//         while (carry)
//         {
//             ans.push_back(carry % 10);
//             carry /= 10;
//         }
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
// }

// On codestudio, this is the solution:
void multiply(string &s, int x)
{
    int carry = 0, prod = 1;
    for (int i = 0; i < s.length(); i++)
    {
        prod = (x * (s[i] - '0')) + carry;
        carry = prod / 10;
        prod = prod % 10;
        s[i] = char(prod + '0');
    }
    while (carry)
    {
        s.push_back(char((carry % 10) + '0'));
        carry /= 10;
    }
}
string calculateFactorial(int n)
{
    string ans = "1";
    for (int i = 2; i <= n; i++)
    {
        multiply(ans, i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    string ans = calculateFactorial(n);
    cout << ans << endl;
    return 0;
}
