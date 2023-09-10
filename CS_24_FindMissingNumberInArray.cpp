#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a, int N)
{
    int idealXOR = 0, calculatedXOR = 0;
    int n = N - 1; // as there is a missing number in the given array
    for (int i = 0; i < n; i++)
    {
        calculatedXOR = calculatedXOR ^ a[i];
        idealXOR = idealXOR ^ (i + 1);
    }
    idealXOR = idealXOR ^ N;
    return idealXOR ^ calculatedXOR;
}

int main()
{
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    vector<int> a(N-1);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N-1; i++)
        cin >> a[i];
    cout << "The missing number is: ";
    cout << missingNumber(a, N) << endl;
    return 0;
}