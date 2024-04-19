#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool isDirectional)
    {
        if (isDirectional)
        {
            // u -> v edge
            adjList[u].push_back(v);
        }
        else
        {
            // u <-> v edge
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // cout << "printing graph: \n";
        // printGraph();
        // cout << endl;
    }

    void printGraph()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto neighbour : i.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    void shortestPathBfs(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (int neighbour : adjList[front])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }
        // parent map is ready
        vector<int> ans;    
        while (dest != -1)
        {
            ans.push_back(dest);
            dest = parent[dest];
        }

        reverse(ans.begin(), ans.end());
        cout << "Shortest path from src to dest is: ";
        for (auto i : ans)
        {
            cout << i;
            if(i != ans.back())
                cout << " -> ";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 4, false);
    g.addEdge(0, 3, false);
    g.addEdge(0, 6, false);
    g.addEdge(4, 1, false);
    g.addEdge(3, 5, false);
    g.addEdge(6, 2, false);
    g.addEdge(1, 5, false);
    g.addEdge(2, 5, false);

    g.shortestPathBfs(0, 5);
    return 0;
}