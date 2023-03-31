//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isValid(int x, int y, int n, int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> qu;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    qu.push({{i,j},0});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,+1};
        int res=INT_MIN;
        int cnt=0;
        while(!qu.empty()){
            int x = qu.front().first.first;
            int y = qu.front().first.second;
            int tim = qu.front().second;
            qu.pop();
            res = max(res,tim);
            
            
            for(int i=0; i<4; i++){
                int Nrow = x + dx[i];
                int Ncol = y + dy[i];
                if(isValid(Nrow,Ncol,n,m) && grid[Nrow][Ncol]==1 && !vis[Nrow][Ncol]){
                    qu.push({{Nrow,Ncol},tim+1});
                    vis[Nrow][Ncol]=1;
                    cnt++;
                }
            }
            
        }
        if(fresh==cnt) return res;
        return -1;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends