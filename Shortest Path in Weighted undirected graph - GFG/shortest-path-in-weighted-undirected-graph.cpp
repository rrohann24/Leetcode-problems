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
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            int dis = edges[i][2];
            adj[n1].push_back({dis,n2});
            adj[n2].push_back({dis,n1});
        }
        priority_queue<ppi,vector<ppi>, greater<ppi>> pq;
        pq.push({0,1});    // {dist,node}
        vector<int> par(n+1,-1);
        vector<int> dis(n+1,1e9);
        dis[1]=0;
        while(!pq.empty()){
            ppi top = pq.top();
            pq.pop();
            int node = top.second;
            int dist = top.first;
            for(int i=0; i<adj[node].size(); i++){
                if(dist+adj[node][i].first<dis[adj[node][i].second]){
                   dis[adj[node][i].second] = dist+adj[node][i].first;
                   pq.push({dis[adj[node][i].second],adj[node][i].second});
                   par[adj[node][i].second] = node;
                }
            }
        }
        vector<int> ans;
        int currNode = n;
        while(par[currNode]!=-1){
            ans.push_back(currNode);
            currNode = par[currNode];
        }
        if(currNode!=1) return {-1};
        ans.push_back(currNode);
        reverse(ans.begin(),ans.end());
        return ans;
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