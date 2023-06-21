class Solution {
public:
    int solve(int index, vector<int> &coins, int amt,vector<vector<int>> &dp){
        if(dp[index][amt]!=-1)return dp[index][amt];
        if(index==0){
           if(amt%coins[0]==0){
                return (amt/coins[0]);
            }else{
                return INT_MAX-1;
            }
        }
        int notTake = solve(index-1, coins, amt,dp);
        int take = INT_MAX;
        if(coins[index]<=amt){
            take = 1+solve(index, coins, amt-coins[index],dp);
        }
        return dp[index][amt]= min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = -1;
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        ans = solve(n-1,coins,amount,dp);
        if(ans==INT_MAX || ans == INT_MAX-1){
            return -1;
        }
         return ans;
    }
};