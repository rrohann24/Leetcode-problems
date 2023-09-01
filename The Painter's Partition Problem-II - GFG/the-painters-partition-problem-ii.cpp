//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  bool isValid(long long mid,int arr[], int n, int k){
      int cnt=0;
      long long curr=0;
      for(int i=0; i<n; i++){
          if(arr[i]>mid) return false;
          curr+=arr[i];
          if(curr>mid){
              cnt++;
              curr=arr[i];
          }
      }
      cnt++;
      if(cnt<=k) return true;
      return false;
  }
    long long minTime(int arr[], int n, int k)
    {
        long long sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }
        long long s=1;
        long long e = sum;
        long long ans=0;
        while(s<=e){
            long long mid = s + (e-s)/2;
            if(isValid(mid,arr,n,k)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends