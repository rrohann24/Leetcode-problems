class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adj[n];
        vector<int> indeg(n,0);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i]==0) q.push(i);
        }
        int visited=0;
        vector<vector<int>> counts(n,vector<int>(26));
        for(int i=0; i<n; i++){
            counts[i][colors[i]-'a']++;
        }
        int maxCnt=0;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            visited++;
            
            for(auto it: adj[node]){
                indeg[it]--;
                for(int i=0; i<26; i++){
    counts[it][i] = max(counts[it][i], counts[node][i]+(i==colors[it]-'a' ? 1:0));
                
                }
                
                if(indeg[it]==0) q.push(it);
                
            }
            for(int i=0; i<26; i++){
                    maxCnt = max(maxCnt,counts[node][i]);
                }
        }
        return visited==n ? maxCnt : -1;
    }
};