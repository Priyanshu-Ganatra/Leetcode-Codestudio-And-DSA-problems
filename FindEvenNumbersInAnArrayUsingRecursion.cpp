#include <bits/stdc++.h>
using namespace std;

void findEvenNumbers(int arr[], int n, int index, vector<int> &evens)
{
    if (index >= n)
    {
        return;
    }
    if (!(arr[index] & 1))
    {
        evens.push_back(arr[index]);
    }
    findEvenNumbers(arr, n, index + 1, evens);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    vector<int> evens;
    findEvenNumbers(arr, n, 0, evens);
    cout << "Even numbers in the array are: ";
    for (int i = 0; i < evens.size(); i++)
    {
        cout << evens[i] << " ";
    }
    cout << endl;
    return 0;
}