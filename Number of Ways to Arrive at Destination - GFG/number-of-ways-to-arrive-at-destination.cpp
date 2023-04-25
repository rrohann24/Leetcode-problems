//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  typedef long long ll;
  
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // code here
        vector<pair<ll,ll>> adj[n];
         int m = roads.size();
         for(int i=0; i<m; i++){
             ll u= roads[i][0];
             ll v = roads[i][1];
             ll wt = roads[i][2];
             adj[u].push_back({v,wt});
             adj[v].push_back({u,wt});
         }
        vector<ll> dist(n,1e15);
        vector<ll> ways(n,0);
        ways[0]=1;
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        int mod = (int)(1e9 + 7);
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            auto iter = pq.top();
            pq.pop();
            ll node = iter.second;
            ll dis = iter.first;
            for(auto it :adj[node]){
                ll adjNode = it.first;
                ll wt = it.second;
                if(dis+wt<dist[adjNode]){
                    dist[adjNode]=dis+wt;
                    pq.push({dis+wt,adjNode});
                    ways[adjNode]+=ways[node];
                }
                else if(dis+wt==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends