class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 3;
        vector<int> dp(n+2, -1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        if(dp[n]!=-1)return dp[n];
        for(int i=4;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};