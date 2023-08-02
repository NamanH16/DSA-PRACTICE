class Solution {
public:
    void solve(vector<int>& nums,int i,vector<vector<int>> &ans){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int k=i;k<nums.size();k++){
            swap(nums[k],nums[i]);
            solve(nums,i+1,ans);
            swap(nums[k],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums, 0, ans);
        return ans;
    }
};