//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  typedef pair<int,pair<int,int>> ppi;
  bool isValid(int x,int y, int n, int m){
      if(x>=0 && x<n && y>=0 && y<m) return true;
      
      return false;
  }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        queue<ppi> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        pq.push({0,source});
        dist[source.first][source.second]=0;
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!pq.empty()){
            ppi top=pq.front();
            pq.pop();
            int dis = top.first;
            int x = top.second.first;
            int y = top.second.second;
            for(int i=0; i<4; i++){
                if(isValid(x+dx[i],y+dy[i],n,m) && grid[x+dx[i]][y+dy[i]]==1){
                    if(dis+1<dist[x+dx[i]][y+dy[i]]){
                        dist[x+dx[i]][y+dy[i]]=dis+1;
                        pq.push({dis+1,{x+dx[i],y+dy[i]}});
                    }
                }
            }
        }
        if(dist[destination.first][destination.second]==1e9) return -1;
        return dist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends