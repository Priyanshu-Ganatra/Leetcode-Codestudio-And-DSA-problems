#include <bits/stdc++.h>
using namespace std;

// tc: O(log (m*n))
bool searchMatrix(vector<vector<int>> &m, int target)
{
    int row = m.size();
    int col = m[0].size();
    int n = row * col;

    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int rowIndex = mid / col;
        int colIndex = mid % col;
        int curr = m[rowIndex][colIndex];

        if (curr == target)
        {
            return true;
        }
        else if (target > curr)
        {
            // right
            s = mid + 1;
        }
        else
        {
            // left
            e = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> m = {{1, 3, 5, 7},
                             {10, 11, 16, 20},
                             {23, 30, 34, 60}};
    int target = 3;
    cout << searchMatrix(m, target) << endl;
    return 0;
}