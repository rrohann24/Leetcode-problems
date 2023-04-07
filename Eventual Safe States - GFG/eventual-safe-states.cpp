//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfs(int node, vector<int> &vis,vector<int> adj[]){
        vis[node]=1;
        vis[node]++;
        
        for(auto it: adj[node]){
            if(vis[it]==2) return true;
            
            else if(vis[it]==0){
                if(dfs(it,vis,adj)) return true;
            }
        }
        
        vis[node]--;
        return false;
        
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        /*vector<int> vis(V,0);
        vector<int> safe(V,1);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
             bool check = dfs(i,vis,adj);
            }
        }
        vector<int> ans;
        for(int i=0; i<V; i++) if(vis[i]==1) ans.push_back(i);
        
        return ans;*/
        vector<int> ans;
        vector<int> indeg(V);
        vector<int> revAdj[V];
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                revAdj[it].push_back(i);
                indeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V ;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: revAdj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
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