//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int x,int y, vector<vector<int>> &grid,vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[x][y]=1;
        
        if(x-1>=0 && grid[x-1][y]==1 && !vis[x-1][y]){
            dfs(x-1,y,grid,vis);
        }
        if(y-1>=0 && grid[x][y-1]==1 && !vis[x][y-1]){
            dfs(x,y-1,grid,vis);
        }
        if(x+1<n && grid[x+1][y]==1 && !vis[x+1][y]){
            dfs(x+1,y,grid,vis);
        }
        if(y+1<m && grid[x][y+1]==1 && !vis[x][y+1]){
            dfs(x,y+1,grid,vis);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis);
            }
        }
        for(int i=0; i<m; i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(0,i,grid,vis);
            }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1,i,grid,vis);
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
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
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends