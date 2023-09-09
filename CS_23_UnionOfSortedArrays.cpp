#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // Brute: TC: O(n1logn + n2logn) + O(n1 + n2) SC: O(n1 + n2) + O(n1 + n2)
    //   set<int> st;
    //   vector<int> temp;
    //   for (int i = 0; i < a.size(); i++) {
    //     st.insert(a[i]);
    //   }
    //   for (int i = 0; i < b.size(); i++) {
    //     st.insert(b[i]);
    //   }
    //   for (auto x : st)
    //     temp.push_back(x);
    //   return temp;

    // Optimal:
    int n1 = a.size();
    int n2 = b.size();
    int i = 0, j = 0;
    vector<int> unionArr;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    // still some elements are left in array 2
    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    // still some elements are left in array 1
    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3};
    vector<int> ans = sortedArray(a, b);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}