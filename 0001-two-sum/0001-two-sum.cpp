class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = target-nums[i];
            if(mp.find(x)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[x]);
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};