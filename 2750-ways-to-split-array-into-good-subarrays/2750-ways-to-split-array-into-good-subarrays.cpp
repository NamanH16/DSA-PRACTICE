const int MOD = 1e9+7;
class Solution {
public:
    int solve(int index, int count ,vector<int> &nums, vector<vector<int>> &dp){
        if(index<0){
            if(count==1){
                return 1;
            }
            return 0;
        }
        if(nums[index]==1)count++;
        if(count>1)return 0;
        if(dp[index][count]!=-1)return dp[index][count];
        int pick = solve(index-1, count ,nums, dp);
        int notPick = 0;
        if(count==1){
            notPick = solve(index-1, 0,nums, dp);
        }
        return dp[index][count]=(pick+notPick)%MOD;
    }
    
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(n-1, 0 ,nums, dp);
    }
};