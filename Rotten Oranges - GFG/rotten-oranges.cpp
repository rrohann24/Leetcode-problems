//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int cntFresh=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                
                if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }
        
        
        int res=-1;
        //int timer=0;
        int cnt=0;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int tm = q.front().second;
            q.pop();
            if(i-1>=0 && grid[i-1][j]==1 && vis[i-1][j]==0){
                vis[i-1][j]=2;
                //vis[i-1][j]=1;
                q.push({{i-1,j},tm+1});
                cnt++;
            }
            if(i+1<n && grid[i+1][j]==1 && vis[i+1][j]==0){
                //grid[i+1][j]=2;
                vis[i+1][j]=2;
                //timer++;
                q.push({{i+1,j},tm+1});
                cnt++;
            }
            if(j-1>=0 && grid[i][j-1]==1 && vis[i][j-1]==0){
                //grid[i][j-1]=2;
                vis[i][j-1]=2;
                cnt++;
                q.push({{i,j-1},tm+1});
            }
            if(j+1<m && grid[i][j+1]==1 && vis[i][j+1]==0){
                //grid[i][j+1]=2;
                vis[i][j+1]=2;
                //timer++;
                q.push({{i,j+1},tm+1});
                cnt++;
            }
            res = max(res,tm);
        }
        if(cnt!=cntFresh) return -1;
        return res;
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