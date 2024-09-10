#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& a) {
    int i = 1, j = 0, n = a.size();
    while (i < n) {
        if (a[i] == a[j]) i++;
        else swap(a[++j], a[i++]);
    }
    return j + 1;
}

int main()
{
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;
    cout << "Enter the elements of the array: ";
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = removeDuplicates(a, n);
    cout << "The number of unique elements in the array are: " << ans << endl;
    cout << "The array after removing the duplicates is: ";
    for (int i = 0; i < ans; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}