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
};

int main()
{
    Graph g;
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(1, 3, false);
    g.addEdge(2, 3, false);
    return 0;
}