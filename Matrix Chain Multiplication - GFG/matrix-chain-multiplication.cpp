//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int i, int j, int arr[], int N,vector<vector<int>> &dp){
    if(j==i){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i; k<=j-1; k++){
        ans = min(ans,(solve(i,k,arr,N,dp) + solve(k+1,j,arr,N,dp) + arr[i-1]*arr[k]*arr[j]));
    }
    return dp[i][j] = ans;
}
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return solve(1, N-1,arr,N,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends