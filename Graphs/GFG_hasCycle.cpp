#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // bfs
    bool solve(int &src, unordered_map<int, bool> &visited, vector<int> adj[])
    {
        queue<int> q;
        unordered_map<int, int> parent;
        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto neighbour : adj[frontNode])
            {
                if (visited[neighbour] == true && parent[frontNode] != neighbour)
                {
                    return true;
                }
                else if (!visited[neighbour])
                {
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        unordered_map<int, bool> visited;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool ans = solve(i, visited, adj);
                if (ans == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int V = 4;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);
    Solution obj;
    if (obj.isCycle(V, adj))
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is not present" << endl;
    }

    return 0;
}