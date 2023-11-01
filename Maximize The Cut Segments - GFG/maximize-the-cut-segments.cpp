//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int f(int n, int x,int y, int z,vector<int> &dp){
        //int mini = min(x,min(y,z));
        if(n==0) return 0;
        if(n<0){
            return INT_MIN;
        }
        //if(n%mini==0) return n/mini;
        if(dp[n]!=INT_MIN) return dp[n];
        //int ans=INT_MIN;
            dp[n]= max(dp[n],1+f(n-x,x,y,z,dp));
            dp[n]= max(dp[n],1+f(n-y,x,y,z,dp));
            dp[n] = max(dp[n],1+f(n-z,x,y,z,dp));
        return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,INT_MIN);
        //if(dp[n]<0) return 0;
        int v = f(n,x,y,z,dp);
        return (dp[n]>=0) ? dp[n] : 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends