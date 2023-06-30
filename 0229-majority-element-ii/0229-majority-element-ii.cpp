class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int n = nums.size();
        vector<int> ans;
        for(auto x:mp){
            if(x.second>n/3){
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};