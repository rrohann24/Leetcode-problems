//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  typedef pair<pair<int,int>,int> ppi;
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[source.first][source.second]=0;
        queue<ppi> pq;
        pq.push({source,0});
        while(!pq.empty()){
            ppi front = pq.front();
            pq.pop();
            int x = front.first.first;
            int y = front.first.second;
            int dist =front.second;
            if(x+1<n && grid[x+1][y]==1){
                if(dis[x+1][y]>dist+1){
                    dis[x+1][y]=dist+1;
                    pq.push({{x+1,y},dist+1});
                }
            }
            if(x-1>=0 && grid[x-1][y]==1){
                if(dis[x-1][y]>dist+1){
                    dis[x-1][y]=dist+1;
                    pq.push({{x-1,y},dist+1});
                }
            }
            if(y+1<m && grid[x][y+1]==1){
                if(dis[x][y+1]>dist+1){
                    dis[x][y+1]=dist+1;
                    pq.push({{x,y+1},dist+1});
                }
            }
            if(y-1>=0 && grid[x][y-1]==1){
                if(dis[x][y-1]>dist+1){
                    dis[x][y-1]=dist+1;
                    pq.push({{x,y-1},dist+1});
                }
            }
        }
        if(dis[destination.first][destination.second]==1e9) return -1;
        return dis[destination.first][destination.second];
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