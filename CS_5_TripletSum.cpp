#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

// TLE wala solution
int main()
{
    vector<int> arr = {10, 5, 5, 5, 2};
    int n = arr.size();
    int tripletSum = 12;

    set<vector<int>> visited;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == tripletSum)
                {
                    vector<int> triplet;
                    triplet.push_back(arr[i]);
                    triplet.push_back(arr[j]);
                    triplet.push_back(arr[k]);
                    sort(triplet.begin(), triplet.end());
                    // Check if the triplet is already present in the set or not before pushing it into the set and the answer vector array (ans), if it is not present, then push it into the set and the answer vector array (ans)
                    if (visited.find(triplet) == visited.end())
                    {
                        ans.push_back(triplet);
                        visited.insert(triplet);
                    }
                }
            }
        }
    }
    cout << "Answer: ";
    for (auto &vector : ans)
    {
        for (auto &vectorElem : vector)
        {
            cout << vectorElem << ' ';
        }
    }
}