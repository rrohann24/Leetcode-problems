//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int x, int y,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<pair<int,int>> &path,int xo,int yo){
        vis[x][y]=1;
        path.push_back({x-xo,y-yo});
        int n = grid.size();
        int m = grid[0].size();
        
        if(x-1>=0 && grid[x-1][y]==1 && !vis[x-1][y]){
            dfs(x-1,y,grid,vis,path,xo,yo);
        }
        if(y-1>=0 && grid[x][y-1]==1 && !vis[x][y-1]){
            dfs(x,y-1,grid,vis,path,xo,yo);
        }
        if(x+1<n && grid[x+1][y]==1 && !vis[x+1][y]){
            dfs(x+1,y,grid,vis,path,xo,yo);
        }
        if(y+1<m && grid[x][y+1]==1 && !vis[x][y+1]){
            dfs(x,y+1,grid,vis,path,xo,yo);
        }
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int,int>> path;
                    dfs(i,j,grid,vis,path,i,j);
                    st.insert(path);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends