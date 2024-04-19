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

    void topoSortBfs(int n){
        queue<int> q;
        unordered_map<int, int> indegree;
        // calculate indegree of all nodes
        for (auto i: adjList)
        {
            for (auto nbr: i.second)
            {
                indegree[nbr]++;
            }
        }
        // push all nodes with 0 indegree in queue
        for (int node = 0; node < n; node++)
        {
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        // start bfs
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            for(auto nbr: adjList[frontNode]){
                indegree[nbr]--;

                // if indegree of a node becomes 0, push it in queue
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }
};

int main(){
    Graph g;
    // dfs
    // g.addEdge(0, 1, true);
    // g.addEdge(1, 2, true);
    // g.addEdge(2, 3, true);
    // g.addEdge(3, 4, true);
    // g.addEdge(3, 5, true);
    // g.addEdge(4, 6, true);
    // g.addEdge(5, 6, true);
    // g.addEdge(6, 7, true);
    // dfs end

    // bfs
    g.addEdge(0, 2, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 3, true);
    g.addEdge(2, 4, true);
    g.addEdge(3, 5, true);
    g.addEdge(4, 5, true);
    g.addEdge(5, 6, true);
    g.addEdge(5, 7, true);
    // bfs end

    // bfs
    g.printGraph();
    int n = 8;
    g.topoSortBfs(n);
    // bfs end

    // dfs
    // g.printGraph();
    // int n = 8;
    // unordered_map<int, bool> visited;
    // stack<int> s;

    // for (int i = 0; i < n; i++)
    // {
    //     if(!visited[i]){
    //         // g.topoSortDfs(i, visited, s);
    //         g.topoSortDfs(i, visited, s);
    //     }
    // }

    // cout << "Topological sort: ";
    // while(!s.empty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // dfs end

    return 0;
}