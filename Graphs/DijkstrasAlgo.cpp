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

    // tc = O(ElogV) and sc = O(V)
    void dijkstrasShrotestDistance(int n, int src, int dest)
    {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;

        // initial state
        st.insert({0, src});
        dist[src] = 0;

        // distance updating logic
        while (!st.empty())
        {
            auto smallestDistNode = st.begin();
            pair<int, int> smallestDistPair = *smallestDistNode;
            int smallestDistInSet = smallestDistPair.first;
            int smallestDistanceNodeInSet = smallestDistPair.second;
            st.erase(smallestDistNode);

            // update the distance of neighbours of smallestNode
            for (pair<int, int> nbrPair : adjList[smallestDistanceNodeInSet])
            {
                // in adjList, pair.first is neighbour node and pair.second is weight i.e. distance to neighbour from smallestNodeInSet
                int nbrDist = nbrPair.second;
                int nbrNode = nbrPair.first; 
                if (smallestDistInSet + nbrDist < dist[nbrNode])
                {
                    // found a shorter distance path, now update the distance of the
                    // neighbour node and insert it in the set, remove the previous
                    // entry of the node in the set and insert the new entry
                    auto previousEntry = st.find({dist[nbrNode], nbrNode});
                    if (previousEntry != st.end()) // check if node already exists in set
                    st.erase(previousEntry);
                    dist[nbrNode] = smallestDistInSet + nbrDist;
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        cout << "Shortest distance from " << src << " to " << dest << " is " << dist[dest] << endl;
    }
};

int main()
{
    Graph g;
    // u, v, weight, isDirected
    g.addEdge(1, 6, 14, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);
    // g.printAdjList();

    int src = 0;
    stack<int> topoOrder;
    unordered_map<int, bool> visited;
    // g.topoOrderDfs(src, topoOrder, visited);

    // while (!topoOrder.empty())
    // {
    //     cout << topoOrder.top() << " ";
    //     topoOrder.pop();
    // }
    int n = 6;
    g.dijkstrasShrotestDistance(n, 6, 4);
    return 0;
}