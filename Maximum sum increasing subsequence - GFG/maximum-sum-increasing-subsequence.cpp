//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	   int ans=0;
	   vector<int> dp(n+1,0);
	   dp[0]=arr[0];
	   ans=dp[0];
	   for(int i=1; i<n; i++){
	       for(int j=0; j<i; j++){
	           if(arr[i]>arr[j]){
	               dp[i] = max(dp[i],arr[i]+dp[j]);
	           }
	           else{
	               dp[i] = max(dp[i],arr[i]);
	           }
	       }
	       ans=max(dp[i],ans);
	   }
	   return ans;
	    
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends