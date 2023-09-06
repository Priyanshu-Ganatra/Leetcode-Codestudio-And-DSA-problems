#include <bits/stdc++.h>
using namespace std;

int getSecondLargest(vector<int> &arr, int n)
{
    int largest = arr[0];
    int slargest = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            slargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }
    return slargest;
}

int getSecondSmallest(vector<int> &arr, int n)
{
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] != smallest && arr[i] < ssmallest)
        {
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    int slargest = getSecondLargest(a, n);
    int ssmallest = getSecondSmallest(a, n);
    return {slargest, ssmallest};
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
    vector<int> ans = getSecondOrderElements(n, a);
    cout << "Second largest: " << ans[0] << ", Second smallest: " << ans[1] << endl;
    return 0;
}