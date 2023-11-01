//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int f(int i, int j, int n, int m, string s1, string s2,vector<vector<int>> &dp){
        
        if(i==n || j==m) return 0;
        if(n==0 || m==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return (1+f(i+1,j+1,n,m,s1,s2,dp));
        }
        return max(f(i+1,j,n,m,s1,s2,dp),f(i,j+1,n,m,s1,s2,dp));
    }
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i][j],max(dp[i+1][j],dp[i][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends