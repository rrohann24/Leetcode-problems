//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        // code here
        //int n = Matrix.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int j=0; j<n; j++){
            dp[n-1][j] = Matrix[n-1][j];
            ans=max(ans,dp[n-1][j]);
        }
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
            dp[i][j] = max(dp[i][j],Matrix[i][j]+dp[i+1][j]);
            if(j+1<n) dp[i][j] = max(dp[i][j],Matrix[i][j]+dp[i+1][j+1]);
            if(j-1>=0) dp[i][j] = max(dp[i][j],Matrix[i][j]+dp[i+1][j-1]);
            if(i==0){
                ans=max(ans,dp[i][j]);
            }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends