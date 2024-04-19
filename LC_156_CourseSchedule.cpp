#include <bits/stdc++.h>
using namespace std;

void topoSortBfs(int n, vector<int> &topoSort, unordered_map<int, list<int>>& adjList)
{
    queue<int> q;
    unordered_map<int, int> indegree;
    // calculate indegree of all nodes
    for (auto i : adjList)
    {
        for (auto nbr : i.second)
        {
            indegree[nbr]++;
        }
    }
    // push all nodes with 0 indegree in queue
    for (int node = 0; node < n; node++)
    {
        if (indegree[node] == 0)
        {
            q.push(node);
        }
    }

    // start bfs
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        topoSort.push_back(frontNode);

        for (auto nbr : adjList[frontNode])
        {
            indegree[nbr]--;

            // if indegree of a node becomes 0, push it in queue
            if (indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adj;
    for (vector<int> i : prerequisites)
    {
        int u = i[0];
        int v = i[1];
        adj[v].push_back(u);
    }

    vector<int> topoSort;
    topoSortBfs(numCourses, topoSort, adj);
    if (topoSort.size() == numCourses)
    {
        return true;
    }
    return false;
}

int main ()
{
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    int numCourses = 2;
    if (canFinish(numCourses, prerequisites))
    {
        cout << "Can finish";
    }
    else
    {
        cout << "Cannot finish";
    }
    return 0;
}