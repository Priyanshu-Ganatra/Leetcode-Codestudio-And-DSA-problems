#include <bits/stdc++.h>
using namespace std;

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    vector<int> ans;
    int sum = 0;
    int carry = 0;
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];

        sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0 || j >= 0 || carry != 0)
    {
        if (i >= 0)
        {
            int sum = a[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            i--;
        }
        else if (j >= 0)
        {
            int sum = b[j] + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            j--;
        }
        else if (carry != 0)
        {
            int sum = carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> a = {9, 9, 9, 9, 9, 9, 9};
    vector<int> b = {1, 6, 8, 9, 9, 9, 9, 9};
    vector<int> ans = findArraySum(a, a.size(), b, b.size());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}