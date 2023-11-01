//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    typedef long long ll;
    ll countWays(int n, int k){
        // code here
        ll mod = 1e9+7;
        vector<ll> dp(n+1,0);
        dp[1] = k;
        dp[2] = (k + (k*(k-1))%mod)%mod;
        for(int i=3; i<=n; i++){
            dp[i] = ((k-1)*(dp[i-1] +dp[i-2])%mod)%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends