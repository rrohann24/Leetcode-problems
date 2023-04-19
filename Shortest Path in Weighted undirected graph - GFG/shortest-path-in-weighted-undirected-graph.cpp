//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  typedef pair<int,int> ppi;
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<ppi> adj[n+1];
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> dist(n+1,1e9);
        vector<int> par(n+1,-1);
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        pq.push({0,1}); //dis,node
        dist[1]=0;
        while(!pq.empty()){
            ppi node = pq.top();
            pq.pop();
            int dis = node.first;
            int currNode = node.second;
            for(auto it: adj[currNode]){
                int wt = it.second;
                int adjNode = it.first;
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis+wt;
                    pq.push({dis+wt,adjNode});
                    par[adjNode] = currNode;
                }
            }
        }
        vector<int> res;
        int node=n;
        while(par[node]!=-1){
            res.push_back(node);
            node = par[node];
        }
        if(node!=1) return {-1};
        res.push_back(node);
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends