#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // tc: O(n), sc: O(1)
    vector<int> findDisappearedNumbers(vector<int> &a)
    {
        int i = 0, n = a.size();
        vector<int> ans;
        while (i < n)
        {
            if (a[i] != a[a[i] - 1])
                swap(a[i], a[a[i] - 1]);
            else
                i++;
        }
        i = 0;
        while (i < n)
        {
            if (a[i] != i + 1)
                ans.push_back(i + 1);
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> a = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans = obj.findDisappearedNumbers(a);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}