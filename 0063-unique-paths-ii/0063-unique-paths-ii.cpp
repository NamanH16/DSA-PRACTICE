class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& g,vector<vector<int>> &dp){
        if(i<0||j<0||g[i][j]==1)return 0;
        if(i==0 && j==0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int left = solve(i-1,j,g,dp);
        int up = solve(i,j-1,g,dp);
        return dp[i][j]=left+up;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(m-1, n-1, obstacleGrid, dp);
    }
};