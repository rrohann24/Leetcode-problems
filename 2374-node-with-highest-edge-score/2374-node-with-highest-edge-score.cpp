class Solution {
public:
    typedef long long ll;
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<ll> res(n,0);
        for(int i=0; i<n; i++){
            res[edges[i]]+=i;
        }
        ll maxE = INT_MIN;
        ll ans=0;
        for(int i=0; i<n; i++){
            if(res[i]>maxE){
                maxE=res[i];
                ans=i;
            }
        }
        return (int)ans;
    }
};