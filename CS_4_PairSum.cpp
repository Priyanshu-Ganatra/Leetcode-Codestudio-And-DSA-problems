#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int s = 5;
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << "Answer: " << endl;
    for (auto &vector : ans)
    {
        for (auto &vectorElem : vector)
        {
            cout << vectorElem << ' ';
        }
        cout << endl;
    }
}