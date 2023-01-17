//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool check(int node, vector<int> adj[],vector<int> &vis){
        vis[node]=1;
        //curdfs[node]=1;
        vis[node]++;
        for(int i=0; i<adj[node].size();i++){
            if(!vis[adj[node][i]]){
                if(check(adj[node][i],adj,vis)) return true;
            }
            else if(vis[adj[node][i]]==2) return true;
        }
        //curdfs[node] = 0;
        vis[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        //vector<bool> curdfs(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                check(i,adj,vis);
            }
        }
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(vis[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends