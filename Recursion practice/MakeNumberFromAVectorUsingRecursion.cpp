#include <bits/stdc++.h>
using namespace std;

int makeNumber(vector<int> &v, int n, int i)
{
    if (i == n)
        return 0;
    int ans = makeNumber(v, n, i + 1);
    ans = ans * 10 + v[n - i - 1];
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int n = v.size();
    int ans = makeNumber(v, n, 0);
    cout << "Number made from above vector is: " << ans;
    return 0;
}