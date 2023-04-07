//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    void dfs(int node, vector<int>& vis, vector<int> adj[],stack<int>& st){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(node);
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
            vector<int> adj[n];
            queue<int> q;
            for(int j=0; j<m; j++){
                   adj[prerequisites[j][1]].push_back(prerequisites[j][0]);
            }
            vector<int> indeg(n,0);
            for(int i=0; i<n; i++){
                for(auto it: adj[i]){
                    indeg[it]++;
                }
            }
            for(int i=0; i<n; i++){
                if(indeg[i]==0) q.push(i);
            }
            vector<int> ans;
            while(!q.empty()){
                int node = q.front();
                ans.push_back(node);
                q.pop();
                
                for(auto it:adj[node]){
                    indeg[it]--;
                    if(indeg[it]==0) q.push(it);
                }
                
            }
            if(ans.size()!=n) return {};
            
            
            
            return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends