#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{

    // base case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    int ans = (n - 1) * (solve(n - 1) + solve(n - 2));
    return ans;
}

int main()
{

    int n;
    vector<int> v = {0, 1, 2}; // possible derangements: {2, 0, 1} and {1, 2, 0}
    n = v.size();
    cout << solve(n) << endl;

    return 0;
}