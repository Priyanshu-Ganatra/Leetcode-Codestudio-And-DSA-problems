#include <bits/stdc++.h>
using namespace std;

void dfs(int src, unordered_map<int, bool> &vis, int n, vector<vector<int>> &isConnected)
{
    vis[src] = true;
    // this node's neighbours will be in every column of this node's row
    int cols = n;
    int row = src;
    for (int nbrColIdx = 0; nbrColIdx < cols; nbrColIdx++)
    {
        if (isConnected[row][nbrColIdx] == 1)
        {
            if (!vis[nbrColIdx])
            {
                dfs(nbrColIdx, vis, n, isConnected);
            }
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    int cnt = 0;
    unordered_map<int, bool> vis;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, n, isConnected);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << findCircleNum(isConnected) << endl;
    return 0;
}