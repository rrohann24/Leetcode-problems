//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int x,int y, vector<vector<char>> mat,vector<vector<int>> &vis){
        int n = mat.size();
        int m = mat[0].size();
        vis[x][y]=1;
        //mat[x][y]='X';
        
        if(x-1>=0 && mat[x-1][y]=='O' && vis[x-1][y]==0){
            dfs(x-1,y,mat,vis);
        }
        if(y-1>=0 && mat[x][y-1]=='O' && vis[x][y-1]==0){
            dfs(x,y-1,mat,vis);
        }
        if(x+1<n && mat[x+1][y]=='O' && vis[x+1][y]==0){
            dfs(x+1,y,mat,vis);
        }
        if(y+1<m && mat[x][y+1]=='O' && vis[x][y+1]==0){
            dfs(x,y+1,mat,vis);
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<m; i++){
            if(mat[0][i]=='O' && vis[0][i]==0){
                dfs(0,i,mat,vis);
            }
        }
        for(int i=0; i<n; i++){
            if(mat[i][0]=='O' && vis[i][0]==0){
                dfs(i,0,mat,vis);
            }
        }
        for(int i=0; i<m; i++){
            if(mat[n-1][i]=='O' && vis[n-1][i]==0){
                dfs(n-1,i,mat,vis);
            }
        }
        for(int i=0; i<n; i++){
            if(mat[i][m-1]=='O' && vis[i][m-1]==0){
                dfs(i,m-1,mat,vis);
            }
        }
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(mat[i][j]=='O' && vis[i][j]==0){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends