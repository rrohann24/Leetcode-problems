// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool check(int i, vector<int> adj[], vector<int> &color){
   if(color[i]==-1){
       color[i]=1;
   }
   
   
   for(int j=0; j<adj[i].size(); j++){
       if(color[adj[i][j]]==-1){
           color[adj[i][j]]=1-color[i];
           if(!check(adj[i][j],adj,color)) return false;
       }
       else if(color[adj[i][j]]==color[i]) return false;
   }
   return true;
    
}
bool check2(int start,vector<int>adj[],vector<int>& color){
    if(color[start]==-1) color[start]=0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node]) return false;
        }
        
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    for(int i=0; i<V; i++){
	        if(color[i]==-1){
	        if(!check2(i,adj,color)) return false;
	        }
	    }
	    return true;
	    
	}

};

// { Driver Code Starts.
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends