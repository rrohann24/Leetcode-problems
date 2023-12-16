//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // int solve(int i, int cnt, int k, int a[], int n,vector<vector<int>> &dp){
    //     if(i==n || cnt>=2*k){
    //         return 0;
    //     }
    //     if(dp[i][cnt]!=-1) return dp[i][cnt];
    //     if(cnt%2==0){
    //         return dp[i][cnt] = max(-a[i] + solve(i+1,cnt+1,k,a,n,dp), solve(i+1,cnt,k,a,n,dp));
    //     }
    //     else{
    //         return dp[i][cnt] = max(a[i]+solve(i+1,cnt+1,k,a,n,dp),solve(i+1,cnt,k,a,n,dp));
    //     }
        
    // }
    int maxProfit(int K, int N, int a[]) {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(2*K+1,0));
        for(int cnt=2*K-1; cnt>=0; cnt--){
            for(int i=N-1; i>=0; i--){
                if(cnt%2==0){
            dp[i][cnt] = max(-a[i] + dp[i+1][cnt+1], dp[i+1][cnt]);
        }
        else{
            dp[i][cnt] = max(a[i]+dp[i+1][cnt+1],dp[i+1][cnt]);
        }
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends