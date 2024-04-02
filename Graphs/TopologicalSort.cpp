// Topological sort is a linear ordering of vertices such that for every directed edge u -> v, 
// vertex u comes before v in the ordering.

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

    void topoSortDfs(int src, map<int, bool> &visited, stack<int> &s){
        visited[src] = true;

        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                topoSortDfs(nbr, visited, s);
            }
        }

        s.push(src);
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 4, true);
    g.addEdge(3, 5, true);
    g.addEdge(4, 6, true);
    g.addEdge(5, 6, true);
    g.addEdge(6, 7, true);
    g.printGraph();

    int n = 8;
    map<int, bool> visited;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
            g.topoSortDfs(i, visited, s);
        }
    }

    cout << "Topological sort: ";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}