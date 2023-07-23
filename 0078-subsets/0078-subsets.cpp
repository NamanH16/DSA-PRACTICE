class Solution {
public:
    void solve(int i,vector<vector<int>> &ans, vector<int> nums,vector<int> output){
        if(i>=nums.size()){
            ans.push_back(output);
            return;
        }
        // exclude
        solve(i+1, ans, nums, output);
        
        // include
        output.push_back(nums[i]);
        solve(i+1, ans, nums, output);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, ans, nums, output);
        return ans;
    }
};