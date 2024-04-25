#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

class Graph
{
public:
    // ex: a : list(<b, 5>, <c, 3>, <d, 2>....)
    unordered_map<int, list<pair<int, int>>> adjList;
    void addEdge(int u, int v, bool isDirectional, int wt)
    {
        if (isDirectional)
        {
            // u -> v edge
            adjList[u].push_back(make_pair(v, wt));
        }
        else
        {
            // u <-> v edge
            adjList[u].push_back(make_pair(v, wt));
            adjList[v].push_back(make_pair(u, wt));
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
                cout << "(" << neighbour.first << ", " << neighbour.second << "), ";
            }
            cout << endl;
        }
    }

    // tc : O(n^3) and sc : O(n^2)
    void floydWarshall(int n)
    {
        vector<vector<int>> distance(n, vector<int> (n, 1e9));
        // set diagonal elements to 0
        for(int i = 0; i < n; i++)
        {
            distance[i][i] = 0;
        }
        // fill the distance matrix with the weights
        for(auto i : adjList)
        {
            int u = i.first; // source
            for(auto neighbour : i.second) // i.second is a list of pairs of neighbours i.e {v, wt}
            {
                int v = neighbour.first;
                int wt = neighbour.second;
                distance[u][v] = wt;
            }
        }
        // main logic - helper nodes
        for(int helper = 0; helper < n ; helper++){
            for(int src = 0; src < n; src++){
                for(int dest = 0; dest < n; dest++){
                    distance[src][dest] = min(distance[src][dest], distance[src][helper] + distance[helper][dest]);
                }
            }
        }

        // print the distance matrix
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << distance[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, true, 3);
    g.addEdge(1, 0, true, 2);
    g.addEdge(0, 3, true, 5);
    g.addEdge(1, 3, true, 4);
    g.addEdge(3, 2, true, 2);
    g.addEdge(2, 1, true, 1);
    g.floydWarshall(4);
    return 0;
}