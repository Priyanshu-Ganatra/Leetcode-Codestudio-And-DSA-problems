#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>> &matrix, int i, int j, int row, int col, int &maxi)
{
    // base case
    if (i >= row || j >= col)
    {
        return 0;
    }

    // explore all 3 directions
    int right = solve(matrix, i, j + 1, row, col, maxi);
    int diagnol = solve(matrix, i + 1, j + 1, row, col, maxi);
    int down = solve(matrix, i + 1, j, row, col, maxi);

    // check can we build sqaure form current position
    if (matrix[i][j] == '1')
    {
        // if yes, we'll take the minimum of all 3 directions and add 1 to it because we can build a square of size 1 from current position
        int ans = 1 + min(right, min(down, diagnol));
        // update the maximum square size found so far
        maxi = max(maxi, ans);
        return ans; // return the answer for that particular call
    }
    else
    {
        // if current position is 0, we can't build square from here so we return 0
        return 0;
    }
}

int maximalSquare(vector<vector<char>> &matrix)
{
    int i = 0;
    int j = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int maxi = 0;
    int ans = solve(matrix, i, j, row, col, maxi);
    return maxi * maxi;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << maximalSquare(matrix) << endl;
    return 0;
}
