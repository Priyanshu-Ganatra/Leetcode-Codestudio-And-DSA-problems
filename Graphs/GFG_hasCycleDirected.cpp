//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // bool checkCycle(int src, unordered_map<int, bool>& vis, unordered_map<int, bool>& dfsTrack, vector<int> adj[]){
    //     vis[src] = true;
    //     dfsTrack[src] = true;

    //     for(auto nbr: adj[src]){
    //         if(!vis[nbr]){
    //             bool ans = checkCycle(nbr, vis, dfsTrack, adj);
    //             if(ans) return true;
    //         }
    //         else if(vis[nbr] == 1 && dfsTrack[nbr] == 1){
    //             // cycle present
    //             return true;
    //         }
    //     }

    //     // backtrack
    //     dfsTrack[src] = false;
    //     return false;
    // }
    
    void topoSortBfs(int n, vector<int> &topoSort, vector<int> adjList[]){
        queue<int> q;
        unordered_map<int, int> indegree;
        // calculate indegree of all nodes
        for (int i = 0; i < n; ++i) {
            for (auto nbr : adjList[i]) {
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
            topoSort.push_back(frontNode);

            for(auto nbr: adjList[frontNode]){
                indegree[nbr]--;

                // if indegree of a node becomes 0, push it in queue
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }
    
    bool isCyclic(int V, vector<int> adjList[]) {
        // unordered_map<int, bool> vis;
        // unordered_map<int, bool> dfsTrack;  
        
        // for(int node = 0; node < V; node++){
        //     if(!vis[node]){
        //         bool isCyclic = checkCycle(node, vis, dfsTrack, adj);
        //         if(isCyclic) return true;
        //     }
        // }
        // return false;
        
        vector<int> topoSort;
        topoSortBfs(V, topoSort, adjList);
        
        if(topoSort.size() == V) return 0;
        else return 1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends