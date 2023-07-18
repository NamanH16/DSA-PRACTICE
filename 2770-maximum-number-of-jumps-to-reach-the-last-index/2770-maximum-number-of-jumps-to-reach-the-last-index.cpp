class Solution {
int f(int ind, int prev,int &target,int &n,vector<int> &nums, vector<vector<int>> &dp){
        //Base Condition
        if(ind == n-1){
            long long lowh = ((-1)*(long long)target + (long long)nums[prev]);
            long long highh = ((long long)target + (long long)nums[prev]);
            
            if(nums[ind] <= highh && lowh <= nums[ind]) return 1;
            else return -1e9;
        }
        
        if(dp[ind][prev] != -1) return dp[ind][prev];
        
        long long nontake = f(ind+1,prev,target,n,nums,dp); // non-take
        
        long long low = ((-1)*(long long)target + (long long)nums[prev]);
        long long high = ((long long)target + (long long)nums[prev]);
        
        long long take = -1e9;
        if(nums[ind] <= high && low <= nums[ind]) take = 1 + f(ind+1,ind,target,n,nums,dp); // take
        
        return dp[ind][prev] = (int) max(take,nontake);
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int ans = f(1,0,target,n,nums,dp);
        
        return (ans < 0) ? -1 : ans;
    }
};