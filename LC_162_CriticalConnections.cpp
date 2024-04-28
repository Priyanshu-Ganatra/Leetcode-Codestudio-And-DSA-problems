#include <bits/stdc++.h>
using namespace std;

void solve(int src, int parent, unordered_map<int, list<int>> &adj, int timer, vector<vector<int>> &ans, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis)
{
    vis[src] = true;
    tin[src] = low[src] = timer;
    timer++;

    // neighbour traversal
    for (auto neighbour : adj[src])
    {
        if (neighbour == parent)
        {
            continue;
        }

        if (!vis[neighbour])
        {
            solve(neighbour, src, adj, timer, ans, tin, low, vis);
            // low update
            low[src] = min(low[src], low[neighbour]);
            // bridge testing
            if (low[neighbour] > tin[src])
            {
                ans.push_back({src, neighbour});
            }
        }
        else
        {
            // one more way found 
            // no need of bridge testing
            // only update the low[src] value
            low[src] = min(low[src], low[neighbour]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    unordered_map<int, list<int>> adj;
    for (auto connection : connections)
    {
        int u = connection[0];
        int v = connection[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // main logic 
    int timer = 1;
    vector<vector<int>> ans;
    vector<int> low(n, 0);
    vector<int> tin(n, 0);
    int src = 0;
    int parent = -1;
    unordered_map<int, bool> vis;
    solve(src, parent, adj, timer, ans, tin, low, vis);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> result = criticalConnections(n, connections);
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