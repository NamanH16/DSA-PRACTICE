class Solution {
public:
    int solve(int amt,vector<int>&c,int i,vector<vector<int>> &dp){
        if(i==0){
            if(amt%c[i]==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][amt]!=-1)return dp[i][amt];
        int notTake = solve(amt, c, i-1, dp);
        int take = 0;
        if(amt>=c[i]){
            take = solve(amt-c[i],c,i,dp);
        }
        return dp[i][amt]=take+notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(amount, coins, n-1, dp);
    }
};