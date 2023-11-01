#include <bits/stdc++.h>
using namespace std;

void countArrangementHelper(vector<int> &v, int &n, int &ans, int currNum)
{
    // base case
    if (currNum == n + 1) // if currNum reaches end of array then push to ans
    {
        // printing the possible arrangement
        for (int i = 1; i <= n; i++)
        {
            cout << v[i] << ' ';
        }
        cout << '\n';
        ans++; // increment ans
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        // if current number is not used and either current number is divisible by index or index is divisible by current number
        if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0))
        {
            v[i] = currNum; // mark current number as used in array
            countArrangementHelper(v, n, ans, currNum + 1); // recursive call for next number
            v[i] = 0; // backtrack
        }
    }
}

int countArrangement(int n)
{
    vector<int> v(n+1); 
    int ans = 0;
    countArrangementHelper(v, n, ans, 1);
    return ans;
}

int main()
{
    int n = 2;
    cout << "Number of beautiful arrangements for " << n << " is: ";
    cout << countArrangement(n);
}
