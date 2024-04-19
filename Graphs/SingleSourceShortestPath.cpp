#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    //  Adjacency List structure: node -> (neighbour, weight)
    unordered_map<int, list<pair<int, int>>> adjList;
    void addEdge(int u, int v, int weight, bool isDirected)
    {
        // 0 = undirected, 1 = directed
        if (isDirected)
        {
            adjList[u].push_back({v, weight});
        }
        else
        {
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight});
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << "(" << neighbour.first << ", " << neighbour.second << ") ";
            }
            cout << endl;
        }
    }

    void topoOrderDfs(int src, stack<int> &topoOrder, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        for (auto neighbourPair : adjList[src])
        {
            int nbrNode = neighbourPair.first;
            if (!visited[nbrNode])
            {
                topoOrderDfs(nbrNode, topoOrder, visited);
            }
        }
        topoOrder.push(src);
    }

    void shortestPathDfs(stack<int> &topoOrder, int &n)
    {
        vector<int> dist(n, INT_MAX);
        // initialize the source node with the first element of topoOrder
        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;

        // update distance of neighbours of src node
        for (auto neighbourPair : adjList[src])
        {
            int nbrNode = neighbourPair.first;
            int nbrDist = neighbourPair.second;

            if (dist[src] + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }

        // update distance of all other nodes in the topoOrder
        while (!topoOrder.empty())
        {
            int src = topoOrder.top();
            topoOrder.pop();

            for (auto neighbourPair : adjList[src])
            {
                int nbrNode = neighbourPair.first;
                int nbrDist = neighbourPair.second;

                if (dist[src] + nbrDist < dist[nbrNode])
                {
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }

        // distance array is ready now
        cout << "Shortest distance from source node " << src << " to all other nodes: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "to node " << i << " -> " << "distance is " << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);
    // g.printAdjList();

    int src = 0;
    stack<int> topoOrder;
    unordered_map<int, bool> visited;
    g.topoOrderDfs(src, topoOrder, visited); // 0 2 4 1 3 (0 is the source node)

    // while (!topoOrder.empty())
    // {
    //     cout << topoOrder.top() << " ";
    //     topoOrder.pop();
    // }

    int n = 5; // number of nodes
    g.shortestPathDfs(topoOrder, n);

    return 0;
}