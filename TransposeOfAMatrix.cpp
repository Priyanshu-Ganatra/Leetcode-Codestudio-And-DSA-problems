#include <bits/stdc++.h>
using namespace std;

void transpose(int arr[][4], int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = row; col < cols; col++)
        {
            swap(arr[row][col], arr[col][row]);
        }
    }
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    transpose(arr, 4, 4);
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}
