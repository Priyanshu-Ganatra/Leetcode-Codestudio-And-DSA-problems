#include <bits/stdc++.h>
using namespace std;

// vector<int> leftRotateBruteforceSolution(vector<int> arr, int d, int n) {
//   // suppose d = 15, i.e. 7 + 7 + 1 we know that n rotations would always
//   give us the original array back again
//   // so to get rid of these useless operations
//   // we do "d % n", so for d = 15 we only have to roate the array by 1
//   d = d % n;
//   vector<int> temp;
//   for (int i = 0; i < d; i++)
//     temp.push_back(arr[i]);
//   for (int i = d; i < n; i++)
//     arr[i - d] = arr[i];
//   for (int i = n - d; i < n; i++)
//     arr[i] = temp[i - (n - d)];
//   return arr;
// }

vector<int> leftRotateOptimalSolution(vector<int> arr, int d, int n)
{
    // suppose d = 15, i.e. 7 + 7 + 1 we know that when d = n i.e. complete array
    // is rotated,
    // it results in the same array, so o get rid of these useless operations we
    // do %, so for d = 15 we only have to roate the array by 1
    d = d % n;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.begin() + n);
    reverse(arr.begin(), arr.begin() + n);
    return arr;
}

vector<int> rotateArray(vector<int> arr, int d)
{
    int n = arr.size();
    // return leftRotateBruteforceSolution(arr, d, n); // Brute - TC: O(n+d), SC: O(d) as temp array is created
    return leftRotateOptimalSolution(arr, d, n);    // Optimal - TC: O(2n), SC: O(1)
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
    cout << "Enter the number of places by which you want to rotate the array: ";
    int d;
    cin >> d;
    vector<int> ans = rotateArray(a, d);
    cout << "The array after rotating by " << d << " places is: ";
    for (int i = 0; i < n; ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}