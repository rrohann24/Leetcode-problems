//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int findMaxSum(vector<int>& a){
      //Code Here
      int n = a.size();
      vector<int> dp(n,0);
      int mx = 0;
      int smx = 0;
      dp[0] = a[0];
      int ans=dp[0];
      for(int i=1; i<n; i++){
        if(i-2>=0){
            mx = max(mx,dp[i-2]);
        }
        if(i-3>=0){
            smx = max(smx,dp[i-3]);
        }
        dp[i] = max(dp[i],a[i]+mx);
          
        dp[i] = max(dp[i],a[i]+a[i-1]+smx);
          
         ans=max(ans,dp[i]);
      }
      return ans;
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends