//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    
public:
vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    bool isValid(int row,int col, int n){
        if(row>=0 && row<n && col>=0 && col<n) return true;
        
        return false;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        DisjointSet ds(n*n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                int node = n*i + j;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int k=0; k<4; k++){
                    int adjR = i+dr[k];
                    int adjC = j+dc[k];
                    if(isValid(adjR,adjC,n) && grid[adjR][adjC]==1){
                        int adjNode = n*adjR + adjC;
                        if(ds.findUPar(node)!=ds.findUPar(adjNode)){
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
        set<int> st;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) continue;
                
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int k=0; k<4; k++){
                    int adjR = i+dr[k];
                    int adjC = j+dc[k];
                    
                    if(isValid(adjR,adjC,n) && grid[adjR][adjC]==1){
                        int adjNode = n*adjR + adjC;
                        int par = ds.findUPar(adjNode);
                        st.insert(par);
                    }
                }
                int count=0;
                for(auto it: st){
                    count+=ds.size[it];
                }
                count++;
                ans=max(count,ans);
                st.clear();
                
            }
        }
        if(ans==INT_MIN) return n*n;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends