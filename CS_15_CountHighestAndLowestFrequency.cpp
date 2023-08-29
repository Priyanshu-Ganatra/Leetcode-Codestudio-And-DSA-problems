#include <bits/stdc++.h>
using namespace std;

vector<int> getFrequencies(vector<int> &v)
{
    int n = v.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }
    int max = INT_MIN, min = INT_MAX;
    int x = 0, y = 0;
    for (auto it : mp)
    {
        if (it.second > max)
        {
            max = it.second;
            x = it.first;
        }
        if (it.second < min)
        {
            min = it.second;
            y = it.first;
        }
    }
    return {x, y};
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans = getFrequencies(v);
    cout << "The element with the highest frequency is: " << ans[0] << endl;
    cout << "The element with the lowest frequency is: " << ans[1] << endl;
    return 0;
}