#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
{
    int n = grid.size();
    int m = grid[0].size();
    if (x < 0 || x >= n || y < 0 || y >= m || vis[{x, y}] == true || grid[x][y] == '0')
    {
        return false;
    }
    return true;
}

void bfs(int srcX, int srcY, vector<vector<char>> &grid, map<pair<int, int>, bool> &vis)
{
    queue<pair<int, int>> q;
    // initialize the queue
    q.push({srcX, srcY});
    vis[{srcX, srcY}] = true;

    while (!q.empty())
    {
        pair<int, int> frontNodePair = q.front();
        q.pop();
        int tempX = frontNodePair.first;
        int tempY = frontNodePair.second;

        // loop through the four directions i.e. up, right, down, left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newX = tempX + dx[i];
            int newY = tempY + dy[i];

            // check if the new coordinates are valid
            if (isSafe(newX, newY, grid, vis))
            {
                q.push({newX, newY});
                vis[{newX, newY}] = true;
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int count = 0;
    // queue<pair<int, int>> q;
    map<pair<int, int>, bool> vis;
    // loop through the grid
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[{i, j}] && grid[i][j] == '1')
            {
                bfs(i, j, grid, vis);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    cout << numIslands(grid) << endl;
    return 0;
}