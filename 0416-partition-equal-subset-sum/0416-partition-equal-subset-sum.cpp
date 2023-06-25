class Solution {
public:
    bool solve(int index, int target,vector<int>&nums, vector<vector<int>> &dp){
        if(index==0){
            if(nums[0]==target){
                return true;
            }
            return false;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        bool notTake = solve(index-1, target, nums, dp);
        bool take = false;
        if(nums[index]<=target){
            take = solve(index-1, target-nums[index], nums, dp);
        }
        return dp[index][target]=(take|notTake);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1){
            return false;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return solve(n-1,sum/2,nums,dp);
    }
};