//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isValid(int x, int y, int n, int m){
    if(x>=0 && y>=0 && x<n && y<m) return true;
    
    return false;
}
void dfs(int x, int y, vector<vector<char>> &res,vector<vector<char>> mat,int dx[],int dy[],int n, int m){
    res[x][y]='O';
    
    for(int i=0; i<4; i++){
        int Nrow = x+dx[i];
        int Ncol = y+dy[i];
        if(isValid(Nrow,Ncol,n,m) && mat[Nrow][Ncol]=='O' && res[Nrow][Ncol]=='X'){
            dfs(Nrow,Ncol,res,mat,dx,dy,n,m);
        }
    }
    
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> res(n,vector<char>(m,'X'));
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0; i<n; i++){
            if(mat[i][0]=='O' && res[i][0]=='X'){
                dfs(i,0,res,mat,dx,dy,n,m);
            }
            if(mat[i][m-1]=='O' && res[i][m-1]=='X'){
                dfs(i,m-1,res,mat,dx,dy,n,m);
            }
        }
        for(int i=0; i<m; i++){
            if(mat[0][i]=='O' && res[0][i]=='X'){
                dfs(0,i,res,mat,dx,dy,n,m);
            }
            if(mat[n-1][i]=='O' && res[n-1][i]=='X'){
                dfs(n-1,i,res,mat,dx,dy,n,m);
            }
        }
        return res;
        
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