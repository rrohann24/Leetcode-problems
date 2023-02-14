//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  typedef pair<int,pair<int,int>> ppi;
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> eff(n,vector<int>(m,1e9));
        eff[0][0]=0;
        
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            ppi front = pq.top();
            pq.pop();
            int diff = front.first;
            int x = front.second.first;
            int y =front.second.second;
            if(x==n-1 && y==m-1) return diff;
            if(x+1<n){
                int newEff = max(abs(heights[x+1][y]-heights[x][y]),diff);
                if(newEff<eff[x+1][y]){
                    eff[x+1][y]=newEff;
                    pq.push({eff[x+1][y],{x+1,y}});
                }
                
            }
            if(x-1>=0){
                int newEff = max(abs(heights[x-1][y]-heights[x][y]),diff);
                if(newEff<eff[x-1][y]){
                    eff[x-1][y]=newEff;
                    pq.push({eff[x-1][y],{x-1,y}});
                }
                
            }
            if(y+1<m){
                int newEff = max(abs(heights[x][y+1]-heights[x][y]),diff);
                if(newEff<eff[x][y+1]){
                    eff[x][y+1]=newEff;
                    pq.push({eff[x][y+1],{x,y+1}});
                }
                
            }
            if(y-1>=0){
                int newEff = max(abs(heights[x][y-1]-heights[x][y]),diff);
                if(newEff<eff[x][y-1]){
                    eff[x][y-1]=newEff;
                    pq.push({eff[x][y-1],{x,y-1}});
                }
                
            }
        }
        //if(dis[destination.first][destination.second]==1e9) return -1;
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends