#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr)
{
    int l = 0, h = arr.size() - 1, m = (l + h) / 2;
    while (l < h)
    {
        if (m % 2 == 1)
        {
            m--;
        }
        if (arr[m] != arr[m + 1])
        {
            h = m;
        }
        else
        {
            l = m + 2;
        }
        m = (l + h) / 2;
    }
    return arr[l];
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "The single element in the array is: ";
    cout << getSingleElement(arr) << endl;
    return 0;
}