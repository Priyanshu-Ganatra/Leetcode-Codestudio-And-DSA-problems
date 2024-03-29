#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bfs(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size(), n = grid[0].size(), mins = 0, tot = 0, cnt = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                    tot++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        // this is just to move to the 4 directions
        // to visit the 4 directions we must add moveX[i], moveY[i] to the current index
        // [row][col]
        // [+0][+1] == move right
        // [+0][+(-1)] == move left
        // [+1][+0] == move down
        // [+(-1)][+0] == move up
        int moveX[4] = {0, 0, 1, -1};
        int moveY[4] = {1, -1, 0, 0};

        while (!q.empty())
        {
            // getting the current number of rotten tomatoes in the queue
            int k = q.size();
            cnt += k;

            // consdering all rotten tomatoes in the queue
            while (k--)
            {
                // row and col of current rotten tomato
                int row = q.front().first, col = q.front().second;
                q.pop();

                // considering the 4 directions
                for (int i = 0; i < 4; ++i)
                {
                    int newX = row + moveX[i], newY = col + moveY[i];
                    // if the new indexes are outta boundry, or the value at them is
                    // not a fresh tomato then just skip that value
                    if (newX < 0 || newY < 0 || newX >= m || newY >= n ||
                        grid[newX][newY] != 1)
                        continue;

                    grid[newX][newY] = 2; // marking the new coordinate tomato as rotten
                    q.push({newX, newY});
                }
            }
            // some fresh tomato(es) was/were just rottened
            if (!q.empty())
                mins++;
        }
        // check if all tomatoes were rottened
        return tot == cnt ? mins : -1;
    }

    // tc: O(m*n)*4, sc: O(m*n)
    int orangesRotting(vector<vector<int>> &grid)
    {
        return bfs(grid);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << s.orangesRotting(grid) << endl;
    return 0;
}