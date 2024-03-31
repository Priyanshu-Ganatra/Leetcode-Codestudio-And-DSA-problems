//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool checkCycle(int src, unordered_map<int, bool>& vis, unordered_map<int, bool>& dfsTrack, vector<int> adj[]){
        vis[src] = true;
        dfsTrack[src] = true;

        for(auto nbr: adj[src]){
            if(!vis[nbr]){
                bool ans = checkCycle(nbr, vis, dfsTrack, adj);
                if(ans) return true;
            }
            else if(vis[nbr] == 1 && dfsTrack[nbr] == 1){
                // cycle present
                return true;
            }
        }

        // backtrack
        dfsTrack[src] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, bool> vis;
        unordered_map<int, bool> dfsTrack;  
        
        for(int node = 0; node < V; node++){
            if(!vis[node]){
                bool isCyclic = checkCycle(node, vis, dfsTrack, adj);
                if(isCyclic) return true;
            }
        }
        return false;
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