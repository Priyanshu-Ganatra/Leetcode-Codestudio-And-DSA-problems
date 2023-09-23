#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &m)
{
    vector<int> ans;
    int rows = m.size();
    int cols = m[0].size();
    int totalElems = rows * cols;

    int startingRow = 0;
    int endingCol = cols - 1;
    int endingRow = rows - 1;
    int startingCol = 0;

    int count = 0;
    while (count < totalElems)
    {
        // push starting row
        for (int i = startingCol; i <= endingCol && count < totalElems; i++)
        {
            ans.push_back(m[startingRow][i]);
            count++;
        }
        startingRow++;
        // push ending col
        for (int i = startingRow; i <= endingRow && count < totalElems; i++)
        {
            ans.push_back(m[i][endingCol]);
            count++;
        }
        endingCol--;
        // push ending row
        for (int i = endingCol; i >= startingCol && count < totalElems; i--)
        {
            ans.push_back(m[endingRow][i]);
            count++;
        }
        endingRow--;
        // push starting column
        for (int i = endingRow; i >= startingRow && count < totalElems; i--)
        {
            ans.push_back(m[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main()
{
    vector<vector<int>> m = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};
    vector<int> ans = spiralOrder(m);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}