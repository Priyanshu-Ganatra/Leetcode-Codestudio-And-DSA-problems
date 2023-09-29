#include <bits/stdc++.h>
using namespace std;

void print2ndDiagonal(int arr[3][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i][n-i-1] << " ";
    }
}

int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    print2ndDiagonal(arr, 3);
}