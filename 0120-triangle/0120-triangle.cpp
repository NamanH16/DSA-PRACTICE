class Solution {
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& tri,vector<vector<int>> &dp){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==n-1){
            return tri[i][j];
        }
        int down = tri[i][j]+solve(i+1, j,n,m ,tri,dp);
        int downright = tri[i][j]+solve(i+1, j+1,n,m, tri,dp);
        
        return dp[i][j]=min(down , downright);
    }
    
    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        int m = tri.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0,0,n,m,tri,dp);
    }
};