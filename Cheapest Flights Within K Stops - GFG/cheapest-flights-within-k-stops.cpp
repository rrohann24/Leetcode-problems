//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dis(n,1e9);
        dis[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int dist = it.second.second;
            //if(stops>k) continue; //
            
            for(auto iter : adj[node]){
                if(dist+iter.second<dis[iter.first] && stops<=k){
                    dis[iter.first]=dist+iter.second;
                    q.push({stops+1,{iter.first,dis[iter.first]}});
                }
            }
            
        }
        if(dis[dst]==1e9) return -1;
        return dis[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends