#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;
    void addEdge(T u, T v, bool isDirectional, T wt)
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

    // void printGraph(){
    //     for(auto i: adjList){
    //         cout << i.first << " -> ";
    //         for(auto neighbour: i.second){
    //             cout << "(" << neighbour.first << ", " << neighbour.second << "), ";
    //         }
    //         cout << endl;
    //     }
    // }

    // tc - O(V + E) | sc - O(V)
    void bfsTraversal(T start, unordered_map<T, bool> &visited)
    {
        // queue for bfs
        queue<T> q;
        // initial step
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            // go to all neighbours of frontNode
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour.first])
                {
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                }
            }
        }
    }

    void dfsTraversal(T start, unordered_map<T, bool> &visited)
    {
        visited[start] = true;
        cout << start << " ";

        for (auto neightbour : adjList[start])
        {
            T node = neightbour.first;
            if (!visited[node])
            {
                dfsTraversal(node, visited);
            }
        }
    }
};

int main()
{
    Graph<char> g;
    // visited map
    unordered_map<char, bool> visited;
    // // component 1
    // g.addEdge('a', 'b', 1, 5);
    // g.addEdge('b', 'c', 1, 5);

    // // component 2
    // g.addEdge('d', 'e', 1, 5);

    // // component 3
    // g.addEdge('f', 'f', 1, 5);
    // int noOfComponents = 0;

    // for (char node = 'a'; node <= 'f'; node++)
    // {
    //     if (!visited[node])
    //     {
    //         noOfComponents++;
    //         g.dfsTraversal(node, visited);
    //     }
    // }

    // component 1
    g.addEdge('a', 'b', 1, 5);

    // component 2
    g.addEdge('c', 'd', 1, 5);
    g.addEdge('c', 'e', 1, 5);
    g.addEdge('d', 'e', 1, 5);
    g.addEdge('e', 'f', 1, 5);

    int noOfComponents = 0;
    
    for (char node = 'a'; node <= 'f'; node++)
    {
        if (!visited[node])
        {
            noOfComponents++;
            g.bfsTraversal(node, visited);
        }
    }
    cout << "\nNo of components: " << noOfComponents << endl;
    return 0;
}