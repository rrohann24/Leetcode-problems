//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public: 
    int f(int i, int j, int n, string s,bool check,vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(i==j){
            if(s[i]=='T'){
                if(check) return 1;
            }
            else{
                if(!check) return 1;
            }
            return 0;
        }
        if(dp[i][j][check]!=-1) return dp[i][j][check];
        int ans=0;
        for(int k = i+1; k<=j; k+=2){
            if(s[k]=='|'){
                int leftTrue = f(i,k-1,n,s,1,dp);
                int leftFalse = f(i,k-1,n,s,0,dp);
                int rightTrue = f(k+1,j,n,s,1,dp);
                int rightFalse = f(k+1,j,n,s,0,dp);
                if(check) ans+= leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue;
                else ans+= leftFalse*rightFalse;
            }
            else if(s[k]=='&'){
                int leftTrue = f(i,k-1,n,s,1,dp);
                int leftFalse = f(i,k-1,n,s,0,dp);
                int rightTrue = f(k+1,j,n,s,1,dp);
                int rightFalse = f(k+1,j,n,s,0,dp);
                if(check) ans+= leftTrue*rightTrue;
                else ans+= leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse;
            }
            else if(s[k]=='^'){
                int leftTrue = f(i,k-1,n,s,1,dp);
                int leftFalse = f(i,k-1,n,s,0,dp);
                int rightTrue = f(k+1,j,n,s,1,dp);
                int rightFalse = f(k+1,j,n,s,0,dp);
                if(check) ans+=leftTrue*rightFalse + leftFalse*rightTrue;
                else ans+= leftTrue*rightTrue + leftFalse*rightFalse;
            }
            else{
                continue;
            }
        }
        return dp[i][j][check] = ans%1003;
        
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(2,-1)));
        return f(0,N-1,N,S,1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends