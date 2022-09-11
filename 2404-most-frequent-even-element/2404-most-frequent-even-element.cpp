class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        //priority_queue<int> pq;
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2==0){
                mp[nums[i]]++;
            }
        }
        //if(mp.size()==0) return 0;
        int maxE = -1;
        int ans=-1;
        for(auto it:mp){
            if(it.second>maxE){
                maxE=it.second;
                ans=it.first;
            }
            else if(it.second==maxE){
                ans = min(ans,it.first);
            }
        }
        return ans;
    }
};