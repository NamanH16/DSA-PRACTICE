class Solution {
public:
    int f(vector<int>&p,int i,int buy,int fee,vector<vector<int>> &dp){
        if(i==p.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        int profit=-1;
        if(buy==0){
            profit=max(f(p,i+1,0,fee,dp),-p[i]+f(p,i+1,1,fee,dp));
        }
        if(buy==1){
            profit=max(f(p,i+1,1,fee,dp),p[i]-fee+f(p,i+1,0,fee,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(prices, 0, 0, fee, dp);
    }
};