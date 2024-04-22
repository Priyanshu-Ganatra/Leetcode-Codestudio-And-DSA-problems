#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

class Graph
{
public:
    // ex: a : list(<b, 5>, <c, 3>, <d, 2>....)
    unordered_map<char, list<pair<char, int>>> adjList;
    void addEdge(char u, char v, bool isDirectional, int wt)
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

    void bellmanFord(char src, int n)
    {
        vector<int> dist(n, INT_MAX);
        dist[src - 'A'] = 0;

        // n-1 relaxations
        for (int i = 0; i < n - 1; i++)
        {
            // traverse each entry (a vertex and edges starting from that vertex) and each neighbour of that entry
            for (auto a : adjList) // a is an entry in the adjList
            {
                for (auto b : a.second) // a.second is list of neighbours where each neighbour is a pair of char and int
                {
                    char u = a.first;
                    char v = b.first;
                    int wt = b.second;
                    if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
                    {
                        dist[v - 'A'] = dist[u - 'A'] + wt;
                    }
                }
            }
        }
        // shortest distance from src to all other vertices after n-1 relaxations is stored in dist array
        // check for negative weight cycle
        // do 1 more relaxation
        bool hasNegativeCycle = false;
        for (auto a : adjList) // a is an entry in the adjList
        {
            for (auto b : a.second) // a.second is list of neighbours where each neighbour is a pair of char and int
            {
                char u = a.first;
                char v = b.first;
                int wt = b.second;
                if (dist[u - 'A'] != INT_MAX && dist[u - 'A'] + wt < dist[v - 'A'])
                {
                    hasNegativeCycle = true;
                    break;
                }
            }
        }

        if (hasNegativeCycle)
        {
            cout << "Graph has negative weight cycle\n";
        }
        else
        {
            cout << "Shortest distance from src (A) to all other vertices: \n";
            char c = 'A';
            for (int i = 0; i < n; i++)
            {
                cout << "Vertex: " << c << " Distance: " << dist[i] << endl;
                c++;
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge('A', 'B', true, -1);
    g.addEdge('B', 'E', true, 2);
    g.addEdge('E', 'D', true, -3);
    g.addEdge('D', 'C', true, 5);
    g.addEdge('A', 'C', true, 4);
    g.addEdge('B', 'C', true, 3);
    g.addEdge('B', 'D', true, 2);
    g.addEdge('D', 'B', true, 1);
    // g.printGraph();
    g.bellmanFord('A', 5);
    return 0;
}