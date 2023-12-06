//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long max_e(long long x, long long y){
        if(x>y) return x;
        return y;
    }
    long long min_e(long long x, long long y){
        if(x<y) return x;
        return y;
    }
    long long f(int s, int e,int arr[], int n,vector<vector<int>> &dp){
        if(s>e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int a1 = arr[s] + f(s+2,e,arr,n,dp);
        int a2 = min_e(a1,arr[s] + f(s+1,e-1,arr,n,dp));
        int a3 = arr[e] + f(s,e-2,arr,n,dp);
        int a4 = min_e(a3,arr[e] + f(s+1,e-1,arr,n,dp));
        return dp[s][e] = max_e(a2,a4);
        
    }
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,n-1,arr,n,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends