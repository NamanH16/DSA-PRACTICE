class Solution {
public:
    int solve(vector<int>&p,int i,int buy,vector<vector<int>> &dp){
        if(i>=p.size()){
            return 0;
        }
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=0;
        if(buy==0){
            profit = max(solve(p,i+1,0,dp), -p[i]+solve(p,i+1,1,dp));
        }
        if(buy==1){
            profit = max(solve(p,i+1,1,dp), p[i]+solve(p,i+1,0,dp));
        }
        return dp[i][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices,0, 0,dp);
    }
};