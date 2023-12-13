//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalin(string s){
        string rev = s;
        reverse(rev.begin(),rev.end());
        return s==rev;
    }
    int f(int ind, string s,vector<int> &dp){
        if(ind>=s.size()) return 0;
        if(isPalin(s.substr(ind))) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int n = s.size();
        int ans=INT_MAX;
        for(int j = ind; j<n; j++){
            if(isPalin(s.substr(ind,j-ind+1))){
                ans=min(ans,1+f(j+1,s,dp));
            }
        }
        return dp[ind]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n,INT_MAX);
        string rev = str;
        reverse(rev.begin(),rev.end());
        //return f(0,str,dp);
        dp[n-1]=0;
        for(int i=n-2; i>=0; i--){
            if(str.substr(i)==rev.substr(0,n-i)){
                dp[i]=0;
                continue;
            }
            for(int j=i; j<n; j++){
                if(str.substr(i,j-i+1)==rev.substr(n-1-j,j-i+1)){
                    dp[i] = min(dp[i],1 + dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends