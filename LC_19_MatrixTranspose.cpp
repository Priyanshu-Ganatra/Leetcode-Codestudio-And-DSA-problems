#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    // Creating auxiliary matrix of size nXm... n=matrix[0].size and m=matrix.size()
    vector<vector<int>> res(matrix[0].size(), vector<int>(matrix.size())); // row is matrix[0].size() and col is matrix.size() because we are transposing the matrix

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            res[j][i] = matrix[i][j];
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    vector<vector<int>> res = transpose(matrix);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}