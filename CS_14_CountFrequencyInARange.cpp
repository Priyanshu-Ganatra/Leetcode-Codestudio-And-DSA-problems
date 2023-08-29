#include <bits/stdc++.h>
using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums)
{
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        ans[nums[i] - 1]++;
    }
    return ans;
}

int main()
{
    int n, x;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the range of elements in the array: ";
    cin >> x;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ans = countFrequency(n, x, nums); // this returns the frequency of each element in the array from 1 to n
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " -> " << ans[i] << endl;
    }
    return 0;
}