#include <bits/stdc++.h>
using namespace std;

// tc : O(n1 + n2 + n3) sc : O(min(n1 + n2 + n3))
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<int> ans;
    set<int> s;
    int i, j, k;
    i = j = k = 0;
    int n1 = a.size();
    int n2 = b.size();
    int n3 = c.size();
    while (i < n1 && j < n2 && k < n3)
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            s.insert(a[i]);
            i++, j++, k++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < c[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    for (auto i : s)
    {
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    cout << "Array 1: ";
    vector<int> a = {1, 5, 10, 20, 40, 80};
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Array 2: ";
    vector<int> b = {6, 7, 20, 80, 100};
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    cout << endl;
    cout << "Array 3: ";
    vector<int> c = {3, 4, 15, 20, 30, 70, 80, 120};
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << endl;
    cout << "Common elements: ";
    vector<int> ans = findCommonElements(a, b, c);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
} 