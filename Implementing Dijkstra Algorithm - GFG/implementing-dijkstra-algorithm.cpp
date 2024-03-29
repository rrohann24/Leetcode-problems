// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    typedef pair<int,int> ppi;
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        vector<int> dis(V,INT_MAX);
        dis[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            ppi front = pq.top();
            pq.pop();
            int node = front.second;
            int dist = front.first;
            for(int i=0; i<adj[node].size();i++){
                if(dist+adj[node][i][1]<dis[adj[node][i][0]]){
                    dis[adj[node][i][0]]=dist+adj[node][i][1];
                    pq.push({dis[adj[node][i][0]],adj[node][i][0]});
                }
            }
            
        }
        return dis;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends