#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N)
{
    // code here
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    // yaha answer ulta calculate hoga array mein
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int val = ans[j] * i + carry;
            ans[j] = val % 10;
            carry = val / 10;
        }

        // if carry exits
        while (carry)
        {
            ans.push_back(carry % 10); // storing multiple digits of carry
            carry /= 10;
        }
    }
    // ans ko seedha kr diya
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int N;
    cin >> N;
    vector<int> ans = factorial(N);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    return 0;
}