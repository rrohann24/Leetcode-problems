class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n,0);
        unordered_map<long long,vector<long long>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
            
            for(auto it: mp){
               vector<long long> indexes = it.second;
               //int num = it.first;
               long long totSum=0;
               for(int i=0; i<indexes.size(); i++) totSum+=indexes[i];
               long long preSum=0;
               for(int i=0; i<indexes.size(); i++){
                   int index = indexes[i];
                   long long postSum = totSum-preSum-index;
                   ans[index]+= (index*(long long)i) - preSum;
                   ans[index]+= postSum - (index*(long long)(indexes.size()-i-1));
                   preSum+=index;
               }
            }
            //ans[i] = i*cntL - leftSum + rightSum - i*cntR;
        
        return ans;
    }
};