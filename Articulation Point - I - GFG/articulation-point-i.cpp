//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node,int timer,vector<int> adj[], vector<int> &vis, vector<int> &tim, vector<int> &low,vector<int> &res, int par){
      vis[node]=1;
      tim[node]=low[node]=timer;
      timer++;
      int child=0;
      for(auto it: adj[node]){
          if(it==par) continue;
          if(!vis[it]){
              dfs(it,timer,adj,vis,tim,low,res,node);
              low[node] = min(low[node],low[it]);
              
              if(low[it]>=tim[node] && par!=-1){
                  res[node]=1;
              }
              child++;
          }
          else{
              low[node] = min(low[node],tim[it]);
          }
      }
      if(child>1 && par==-1){
          res[node]=1;
      }
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code hereve
        vector<int> vis(V,0);
        vector<int> tim(V,-1);
        vector<int> low(V,-1);
        vector<int> res(V,-1);
        
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(i,0,adj,vis,tim,low,res,-1);
        }
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(res[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends