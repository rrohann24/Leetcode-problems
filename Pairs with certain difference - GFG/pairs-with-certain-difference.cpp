//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        // Your code goes here   
        sort(arr,arr+N);
        int cur =arr[N-1];
        int j=N-2;
        int ans=0;
        while(j>=0){
            if(cur-arr[j]<K){
                ans+=arr[j]+cur;
                if(j-1>=0) cur = arr[j-1];
                j-=2;
            }
            else{
                cur=arr[j];
                j--;
            }
            
        }
        return ans;   // 3 5 9 10 12 15 17
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends