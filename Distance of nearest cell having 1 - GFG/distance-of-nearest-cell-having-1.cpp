//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    bool isValid(int x, int y, int n, int m){
        if(x>=0 && y>=0 && x<n && y<m) return true;
        
        return false;
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> dis(n,vector<int>(m,1e9));
	    queue<pair<pair<int,int>,int>> q;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]==1){
	                dis[i][j]=0;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    int dx[] = {-1,0,1,0};
	    int dy[] = {0,1,0,-1};
	    while(!q.empty()){
	        int x = q.front().first.first;
	        int y = q.front().first.second;
	        int dist = q.front().second;
	        q.pop();
	        for(int i=0; i<4; i++){
	            int Nrow = x+dx[i];
	            int Ncol = y+dy[i];
	            if(isValid(Nrow,Ncol,n,m) && dis[Nrow][Ncol]==1e9){
	               dis[Nrow][Ncol] = dist+1;
	               q.push({{Nrow,Ncol},dist+1});
	            }
	        }
	        
	    }
	    return dis;
	    
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends