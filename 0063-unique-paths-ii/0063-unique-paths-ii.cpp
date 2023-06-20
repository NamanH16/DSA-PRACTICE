class Solution {
public:
    int f(int m, int n, vector<vector<int>>& grid,vector<vector<int>> &dp){
        // Sequence is v.v.imp
        if(m<0 or n<0 or grid[m][n]==1) return 0;
		if(m==0 && n==0) return 1;
        if(dp[m][n]!=-1)return dp[m][n];
        int left=f(m,n-1,grid, dp);
        int up=f(m-1,n,grid, dp);
        return dp[m][n]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m-1,n-1,grid, dp);
    }
};