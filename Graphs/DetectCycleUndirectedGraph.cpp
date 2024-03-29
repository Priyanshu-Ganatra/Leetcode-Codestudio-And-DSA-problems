#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool isDirectional){
        if(isDirectional){
            // u -> v edge
            adjList[u].push_back(v);
        }
        else{
            // u <-> v edge
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        cout << "printing graph: \n";
        printGraph();
        cout << endl;
    }

    void printGraph(){
        for(auto i: adjList){
            cout << i.first << " -> ";
            for(auto neighbour: i.second){
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    bool hasCycle(int &src)
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
            int frontNode = q.front(); q.pop();

            for(auto neighbour: adjList[frontNode]){
                if(visited[neighbour] == true && parent[frontNode] != neighbour){
                    return true;
                }
                else if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(1, 3, false);
    g.addEdge(2, 4, false);
    g.addEdge(3, 4, false);
    g.addEdge(2, 5, false);
    int src = 0;
    bool hasCycle = g.hasCycle(src);
    hasCycle ? cout << "Graph has cycle" : cout << "Graph does not have cycle";
    return 0;
}