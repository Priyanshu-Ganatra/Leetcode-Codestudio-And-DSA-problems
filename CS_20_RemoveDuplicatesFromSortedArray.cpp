#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n)
{
    // remember the array is sorted
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        // if we find an element not equal to previous unique element, we do the in-place change
        // of the newly found element one place after the previously found unique element
        // and now the newly found unique element becomes the previously found unique element
        // for further searching of another unique element if there exists one
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    // In the end, the i pointer would be standing at a position where the last unique element
    // stands, and since the index starts with 0 and we want the no. of unique elements in the
    // array, we return (i+1)
    return (i + 1);
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