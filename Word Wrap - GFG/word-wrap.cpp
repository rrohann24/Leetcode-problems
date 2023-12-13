//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int f(int i,vector<int> &nums, int s, int k,vector<vector<int>> &dp){
        int n = nums.size();
        if(i==n) return 0;
        if(i==n-1){
            if(s==k){
                return 0;
            }
            else{
                if(nums[i]+1<=s) return 0;
                
                else return s*s;
            }
        }
        if(dp[i][s]!=-1) return dp[i][s];
        int ans = INT_MAX;
        if(s!=k){
            ans=s*s + f(i,nums,k,k,dp);
        }
        if(nums[i]+1<=s){
            if(s!=k) return dp[i][s]=min(ans,f(i+1,nums,s-nums[i]-1,k,dp));
            if(s==k) return dp[i][s]=min(ans,f(i+1,nums,s-nums[i],k,dp));
        }
        return dp[i][s] =ans;
        
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return f(0,nums,k,k,dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends