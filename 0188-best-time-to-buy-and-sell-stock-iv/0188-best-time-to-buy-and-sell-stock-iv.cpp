class Solution {
public:
    int solve(vector<int>&p,int i,int buy,int cap,vector<vector<vector<int>>> &dp){
        if(cap==0 || i==p.size())return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        int profit = -1;
        if(buy==0){
            // can buy or can't
            profit = max(solve(p, i+1, 0, cap, dp), -p[i]+solve(p, i+1, 1, cap, dp));
        }
        if(buy==1){
            profit = max(solve(p, i+1, 1, cap, dp), p[i]+solve(p, i+1, 0, cap-1, dp));
        }
        return dp[i][buy][cap]=profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices, 0, 0, k, dp);
    }
};