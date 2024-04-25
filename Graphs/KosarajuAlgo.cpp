#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

class Graph
{
public:
    // ex: a : list(b, c, d....)
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

    void dfs1(int node, stack<int> &ordering, unordered_map<int, bool> &visited)
    {
        visited[node] = true;
        for (auto neighbour : adjList[node])
        {
            if (!visited[neighbour])
            {
                dfs1(neighbour, ordering, visited);
            }
        }
        ordering.push(node);
    }

    void dfs2(int node, unordered_map<int, list<int>> &adjNew, unordered_map<int, bool> &visited2)
    {
        visited2[node] = true;
        cout << node << " ";
        for (auto neighbour : adjNew[node])
        {
            if (!visited2[neighbour])
            {
                dfs2(neighbour, adjNew, visited2);
            }
        }
    }

    // tc : O(V + E) + O(V + E) = O(V + E) and sc : O(V)
    int kosarajuAlgo(int n)
    {
        // step 1 : get the dependency ordering
        stack<int> ordering;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs1(i, ordering, visited);
            }
        }

        // step 2 : reverse the graph
        unordered_map<int, list<int>> adjNew;
        for (auto a : adjList)
        {
            int u = a.first;
            for (auto b : a.second)
            {
                int v = b;
                // create entry v -> u 
                adjNew[v].push_back(u);
            }
        }

        // step 3 : do dfs using ordering and count the number of SCCs
        int count = 0;
        unordered_map<int, bool> visited2;
        
        while (!ordering.empty())
        {
            int node = ordering.top();
            ordering.pop();
            if (!visited2[node])
            {
                cout << "SCC #" << count + 1 << " : ";
                dfs2(node, adjNew, visited2);
                count++;
                cout << endl;
            }
        }

        return count;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 0, true);

    g.addEdge(2, 4, true);

    g.addEdge(4, 5, true);
    g.addEdge(5, 6, true);
    g.addEdge(6, 4, true);

    g.addEdge(6, 7, true);

    int n = 8;
    int count = g.kosarajuAlgo(n);
    cout << "Number of Strongly Connected Components: " << count << endl;
    return 0;
}