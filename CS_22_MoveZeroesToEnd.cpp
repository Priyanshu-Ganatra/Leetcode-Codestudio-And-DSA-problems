#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> a)
{
    // Brute: TC: O(2n), SC: O(n)
    //   vector<int> temp;
    //   for (int i = 0; i < n; i++) {
    //     if (a[i] != 0)
    //       temp.push_back(a[i]);
    //   }
    //   int zerosToBeAdded = n - temp.size();
    //   for (int i = 0; i < zerosToBeAdded; i++) {
    //       temp.push_back(0);
    //   }
    //   return temp;

    // Two pointers
    // Optimal: TC: O(n), SC: O(1)
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return a;
    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[j], a[i]);
            j++;
        }
    }
    return a;
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
    vector<int> ans = moveZeros(n, a);
    cout << "The array after moving all the zeros to the end is: ";
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}