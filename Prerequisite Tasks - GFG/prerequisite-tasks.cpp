//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    int m = prerequisites.size();
	    vector<int> adj[n];
            queue<int> q;
            for(int j=0; j<m; j++){
                   adj[prerequisites[j].second].push_back(prerequisites[j].first);
            }
            vector<int> indeg(n,0);
            for(int i=0; i<n; i++){
                for(auto it: adj[i]){
                    indeg[it]++;
                }
            }
            for(int i=0; i<n; i++){
                if(indeg[i]==0) q.push(i);
            }
            //vector<int> ans;
            int cnt=0;
            while(!q.empty()){
                int node = q.front();
                //ans.push_back(node);
                cnt++;
                q.pop();
                
                for(auto it:adj[node]){
                    indeg[it]--;
                    if(indeg[it]==0) q.push(it);
                }
                
            }
            if(cnt!=n) return 0;
            
            
            
            return 1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends