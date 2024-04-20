#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, map<pair<int, int>, bool> &vis, int oldColor, vector<vector<int>> &ans)
{
    if (x >= 0 && x < ans.size() && y >= 0 && y < ans[0].size() && !vis[{x, y}] && ans[x][y] == oldColor)
    {
        return true;
    }
    return false;
}

void dfs(int oldColor, int newColor, int sr, int sc, vector<vector<int>> &image, map<pair<int, int>, bool> &vis, vector<vector<int>> &ans)
{
    vis[{sr, sc}] = true;
    ans[sr][sc] = newColor;

    // loop through the four directions i.e. up, right, down, left
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
    {
        int newX = sr + dx[i];
        int newY = sc + dy[i];
        if (isSafe(newX, newY, vis, oldColor, ans))
        {
            dfs(oldColor, newColor, newX, newY, image, vis, ans);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> ans = image;
    int oldColor = image[sr][sc];
    int newColor = color;
    map<pair<int, int>, bool> vis;

    dfs(oldColor, newColor, sr, sc, image, vis, ans);
    return ans;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}