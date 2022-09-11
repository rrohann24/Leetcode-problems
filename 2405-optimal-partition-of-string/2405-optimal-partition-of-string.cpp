class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        int ans=0;
        int i=0;
        int c=0;
        while(i<n){
            if(mp.count(s[i])<1){
                mp[s[i]]++;
                i++;
            }
            else{
                mp.clear();
                ans++;
                //c=0;
            }
            //i++;
        }
        return ans+1;
    }
};