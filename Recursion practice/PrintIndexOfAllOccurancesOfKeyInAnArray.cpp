#include <bits/stdc++.h>
using namespace std;

vector<int> search(int arr[], int n, int key, int index)
{
    if (index == n)
    {
        return {};
    }
    vector<int> res = search(arr, n, key, index + 1);
    if (arr[index] == key)
    {
        res.push_back(index);
    }
    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 5};
    int n = 5;
    int key = 3;
    vector<int> res = search(arr, n, key, 0);
    cout << key << " found at indices: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    } // Ans: 3 2, as this is head recursion and we are pushing the indices in the vector after the recursive call
    cout << endl;
    return 0;
}