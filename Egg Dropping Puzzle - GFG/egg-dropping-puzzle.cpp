//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n, int f,vector<vector<int>> &dp){
        if(n==1) return f;
        if(f==0 || f==1) return f;
        if(dp[n][f]!=-1) return dp[n][f];
        int ans=INT_MAX;
        for(int i=1; i<f; i++){
            int temp = 1 + max(solve(n-1,i-1,dp),solve(n,f-i,dp));
            ans=min(ans,temp);
        }
        return dp[n][f] = ans;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends