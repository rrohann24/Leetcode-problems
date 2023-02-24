//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    typedef pair<int,int> ppi;
    void dij(vector<ppi> adj[],int s,int n,vector<vector<int>> &dist){
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        //vector<int> dist(n,1e9);
        dist[s][s]=0;
        pq.push({dist[s][s],s});
        while(!pq.empty()){
            ppi first = pq.top();
            pq.pop();
            int node = first.second;
            int dis = first.first;
            for(int i=0; i<adj[node].size();i++){
                if(dis+adj[node][i].first<dist[s][adj[node][i].second]){
                    dist[s][adj[node][i].second]=dis+adj[node][i].first;
                    pq.push({dist[s][adj[node][i].second],adj[node][i].second});
                }
            }
        }
    }
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
                     vector<ppi> adj[n];
                     
        for(int i=0; i<edges.size(); i++){
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            int dis = edges[i][2];
            adj[n1].push_back({dis,n2});
            adj[n2].push_back({dis,n1});
        }
                     
        vector<vector<int>> dist(n,vector<int>(n,1e9));             
                     
        for(int i=0; i<n; i++){
            
            dij(adj,i,n,dist);
        }
        int city=-1;
        int cityCnt=n+1;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cityCnt){
                    cityCnt = cnt;
                    city=i;
                }
        }
        return city;
                     
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends