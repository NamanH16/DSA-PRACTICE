class Solution {
public:
    int solve(vector<int>& prices, int i,int buy,int capacity,vector<vector<vector<int>>> &dp){
        if(i==prices.size() || capacity==0)return 0;
        if(dp[i][buy][capacity]!=-1)return dp[i][buy][capacity];
        int profit = INT_MIN;
        if(buy==0){
            profit = max(solve(prices, i+1, 0, capacity, dp), -prices[i]+solve(prices, i+1, 1, capacity, dp));
        }
        if(buy==1){
            profit = max(solve(prices, i+1, 1, capacity, dp), prices[i]+solve(prices, i+1, 0, capacity-1, dp));
        }
        return dp[i][buy][capacity] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return solve(prices,0,0,2,dp);
    }
};