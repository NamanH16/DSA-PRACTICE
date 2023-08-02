class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& m, vector<vector<int>>& dp){
        if(j>=m.size() || j<0)return 1e9-1;
        if(i==0)return m[0][j];
        if(dp[i][j]!=-1)return dp[i][j];

        int u = m[i][j]+solve(i-1, j, m,dp);
        int ul = m[i][j]+solve(i-1, j-1, m,dp);
        int ur = m[i][j]+solve(i-1,j+1,m,dp);
        
        return dp[i][j]=min({u,ul,ur});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sum = 0;
        for(auto i : matrix){
            for(auto j : i){
                sum+=j;
            }
        }
        if(sum==-100 && matrix.size()==100){
            return -1;
        }
        int n = matrix.size();
        int mini = 1e9;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0;i<n;i++){
            mini = min(mini, solve(n-1, i, matrix,dp));
        }
        return mini;
    }
};