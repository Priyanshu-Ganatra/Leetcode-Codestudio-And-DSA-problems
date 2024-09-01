#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& a) {
        vector<int> ans;
        int n = a.size();

        // -ve marking method i,e. visiting method
        // tc: O(n) and sc: O(1)
        // for (int i = 0; i < n; i++) {
        //     int idx = abs(a[i]);
        //     if (a[idx - 1] > 0) {
        //         a[idx - 1] *= -1;
        //     }
        // }
        // for (int i = 0; i < n; i++) {
        //     if (a[i] > 0)
        //         ans.push_back(i + 1);
        // }

        // sort + swap method
        // tc: O(n) and sc: O(1)
        int i = 0;
        while (i < n) {
            int idx = a[i] - 1;
            if (a[i] != a[idx]) {
                swap(a[i], a[idx]);
            } else
                i++;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] != i + 1)
                ans.push_back(i + 1);
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