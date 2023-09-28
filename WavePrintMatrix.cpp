#include <bits/stdc++.h>
using namespace std;

void wavePrintMatrix(vector<vector<int>> &v)
{
    int m = v.size();    // no of rows
    int n = v[0].size(); // no of cols
    for (int startCol = 0; startCol < n; startCol++)
    {
        if (startCol % 2 == 0)
        {
            // top to bottom
            for (int i = 0; i < m; i++)
            {
                cout << v[i][startCol] << " ";
            }
        }
        else
        {
            // bottom to top
            for (int i = m - 1; i >= 0; i--)
            {
                cout << v[i][startCol] << " ";
            }
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};
    wavePrintMatrix(v);
    return 0;
}