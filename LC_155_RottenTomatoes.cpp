#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int bfs(vector<vector<int>> &grid)
    // {
    //     if (grid.empty())
    //         return 0;
    //     int m = grid.size(), n = grid[0].size(), mins = 0, tot = 0, cnt = 0;
    //     queue<pair<int, int>> q;

    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (grid[i][j] != 0)
    //                 tot++;
    //             if (grid[i][j] == 2)
    //                 q.push({i, j});
    //         }
    //     }

    //     // this is just to move to the 4 directions
    //     // to visit the 4 directions we must add moveX[i], moveY[i] to the current index
    //     // [row][col]
    //     // [+0][+1] == move right
    //     // [+0][+(-1)] == move left
    //     // [+1][+0] == move down
    //     // [+(-1)][+0] == move up
    //     int moveX[4] = {0, 0, 1, -1};
    //     int moveY[4] = {1, -1, 0, 0};

    //     while (!q.empty())
    //     {
    //         // getting the current number of rotten tomatoes in the queue
    //         int k = q.size();
    //         cnt += k;

    //         // consdering all rotten tomatoes in the queue
    //         while (k--)
    //         {
    //             // row and col of current rotten tomato
    //             int row = q.front().first, col = q.front().second;
    //             q.pop();

    //             // considering the 4 directions
    //             for (int i = 0; i < 4; ++i)
    //             {
    //                 int newX = row + moveX[i], newY = col + moveY[i];
    //                 // if the new indexes are outta boundry, or the value at them is
    //                 // not a fresh tomato then just skip that value
    //                 if (newX < 0 || newY < 0 || newX >= m || newY >= n ||
    //                     grid[newX][newY] != 1)
    //                     continue;

    //                 grid[newX][newY] = 2; // marking the new coordinate tomato as rotten
    //                 q.push({newX, newY});
    //             }
    //         }
    //         // some fresh tomato(es) was/were just rottened
    //         if (!q.empty())
    //             mins++;
    //     }
    //     // check if all tomatoes were rottened
    //     return tot == cnt ? mins : -1;
    // }

    // // tc: O(m*n)*4, sc: O(m*n)
    // int orangesRotting(vector<vector<int>> &grid)
    // {
    //     return bfs(grid);
    // }

    bool isSafe(int newX, int newY, vector<vector<int>> &temp)
    {
        if (newX >= 0 && newY >= 0 && newX < temp.size() && newY < temp[0].size() && temp[newX][newY] == 1)
            return true;
        return false;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        // {{x, y}, time}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> temp = grid;
        int minTime = 0;
        int n = grid.size();
        int m = grid[0].size();

        // find all rotten oranges and put in queue i.e. setting the initial state
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // all src nodes i.e. rotten oranges have time = 0
                if (temp[i][j] == 2)
                    q.push({{i, j}, 0});
            }
        }

        // bfs logic
        while (!q.empty())
        {
            auto frontNodePair = q.front();
            q.pop();
            auto frontNodeCoords = frontNodePair.first;
            int frontNodeTime = frontNodePair.second;
            int tempX = frontNodeCoords.first;
            int tempY = frontNodeCoords.second;

            // loop through the four directions i.e. up, right, down, left
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = tempX + dx[i];
                int newY = tempY + dy[i];

                if (isSafe(newX, newY, temp))
                {
                    q.push({{newX, newY}, frontNodeTime + 1});
                    minTime = frontNodeTime + 1;
                    // mark this node as rotten
                    temp[newX][newY] = 2;
                }
            }
        }

        // check whether all oranges are rotten
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (temp[i][j] == 1)
                    return -1;
            }
        }
        return minTime;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << s.orangesRotting(grid) << endl;
    return 0;
}