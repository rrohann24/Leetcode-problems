//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
class Solution {
  public:
  bool isValid(int x, int y, int n, int m){
      if(x>=0 && x<n && y>=0 && y<m) return true;
      
      return false;
  }
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<int>>& grid,vector<pair<int,int>> &path,int xo,int yo){
        vis[x][y]=1;
        int n = grid.size();
        int m = grid[0].size();
        int disX = x-xo;
        int disY = y-yo;
        path.push_back({disX,disY});
        //vector<int> dis;
        for(int i=0; i<4; i++){
            int nrow = x+dx[i];
            int ncol = y+dy[i];
            if(isValid(nrow,ncol,n,m) && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                //int dist = abs(nrow-x) + abs(ncol-y);
                dfs(nrow,ncol,vis,grid,path,xo,yo);
            }
            
        }
        //st.insert(dis);
        
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
                    dfs(i,j,vis,grid,path,i,j);
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