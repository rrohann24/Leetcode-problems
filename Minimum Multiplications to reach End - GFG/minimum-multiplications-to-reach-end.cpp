//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    typedef pair<int,int> ppi;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dis(99999,1e9);
        dis[start]=0;
        queue<ppi> pq;
        pq.push({0,start});
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int dist = it.first;
            int node = it.second;
            for(int i=0; i<arr.size(); i++){
                int child = (node*arr[i])%100000;
                if(dist+1<dis[child]){
                    dis[child] = dist+1;
                    pq.push({dist+1,child});
                }
            }
        }
        if(dis[end]==1e9) return -1;
        return dis[end];
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends