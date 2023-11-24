//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int f(int ind, bool check,vector<int>&nums,vector<vector<int>> &dp){
	        if(ind==nums.size()) return 0;
	        if(dp[ind][check]!=-1) return dp[ind][check];
	        int ans=1;
	        for(int i=ind+1; i<nums.size(); i++){
	            if(check){
	                if(nums[i]>nums[ind]){
	                    ans=max(ans,1+f(i,!check,nums,dp));
	                }
	            }
	            else{
	               if(nums[i]<nums[ind]){
	                    ans=max(ans,1+f(i,!check,nums,dp));
	                } 
	            }
	        }
	        
	        return dp[ind][check]=ans;
	    }
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int n = nums.size();
		    int up = 1;
		    int down = 1;
		    for(int i=1; i<n; i++){
		        if(nums[i]>nums[i-1]){
		            up = down+1;
		        }
		        if(nums[i]<nums[i-1]){
		            down = up+1;
		        }
		    }
		    return max(up,down);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends