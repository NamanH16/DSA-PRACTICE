class Solution {
public:
    int solve(int ind,int prev_ind,vector<int>&nums,vector<vector<int>> &dp){
        // base
        if(ind==nums.size()){
            return 0;
        }
        // cache
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        // compute
        int notTake = solve(ind+1, prev_ind,nums,dp);
        int take = -1;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            take = 1+solve(ind+1, ind,nums, dp);
        }
        // save n return
        return dp[ind][prev_ind+1]=max(take,notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1, nums,dp);
        // f(prev, curr)
    }
};