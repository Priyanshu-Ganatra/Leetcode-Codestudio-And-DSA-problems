//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // bfs
    bool solve(int &src, unordered_map<int, bool>& visited, vector<int> adj[]){
        queue<int> q;
        unordered_map<int, int> parent;
        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        while(!q.empty()){
            int frontNode = q.front(); q.pop();
            
            for(auto nbr : adj[frontNode]){
                // old method to detect cycle
                // if(visited[nbr] && parent[frontNode] != nbr){
                //     return true;
                // }
                
                // new method to detect cycle
                if(nbr == parent[frontNode]) continue;
                if(visited[nbr]){
                    return true;
                }
                // new method ends
                
                else if(!visited[nbr]){
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                    q.push(nbr);
                }
            }
        }
        return false;
    }
    
    // dfs
    // bool solve(int &src, unordered_map<int, bool>& vis, vector<int> adj[], int parent){
    //     vis[src] = true;
        
    //     for(auto nbr : adj[src]){
    //         if(nbr == parent) continue;
            
    //         if(!vis[nbr]){
    //             bool ans = solve(nbr, vis, adj, src);
    //             if(ans) return true;
    //         }
    //         else if(vis[nbr]){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // bfs
        unordered_map<int, bool> visited;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                bool ans = solve(i, visited, adj);
                if(ans == true) return true;
            }
        }
        return false;
        
        // dfs
        // unordered_map<int, bool> visited;
        // for(int i = 0; i < V; i++){
        //     if(!visited[i]){
        //         int parent = -1;
        //         bool ans = solve(i, visited, adj, parent);
        //         if(ans == true) return true;
        //     }
        // }
        // return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends