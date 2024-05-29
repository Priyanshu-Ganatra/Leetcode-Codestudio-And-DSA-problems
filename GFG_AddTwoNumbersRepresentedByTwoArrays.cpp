//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string calc_Sum(int *a, int n, int *b, int m)
    {
        int carry = 0;
        string ans;
        int i = n - 1, j = m - 1;

        while (i >= 0 and j >= 0)
        {
            int x = a[i] + b[j] + carry;
            int digit = x % 10;
            carry = x / 10;
            ans.push_back(digit + '0');
            i--;
            j--;
        }
        while (i >= 0)
        {
            int x = a[i] + 0 + carry;
            int digit = x % 10;
            carry = x / 10;
            ans.push_back(digit + '0');
            i--;
        }
        while (j >= 0)
        {
            int x = 0 + b[j] + carry;
            int digit = x % 10;
            carry = x / 10;
            ans.push_back(digit + '0');
            j--;
        }
        if (carry)
            ans.push_back(carry + '0');

        while (ans[ans.size() - 1] == '0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.calc_Sum(a, n, b, m) << endl;
    }
    return 0;
}
// } Driver Code Ends