class Solution {
public:
    int solve(string &a,string &b,int i,int j,vector<vector<int>> &dp){
        if(i<0){
            int s=0;
            for(int p=0;p<=j;p++){
                s+=(int)(b[p]);
            }
            return s;
        }
        if(j<0){
            int s=0;
            for(int p=0;p<=i;p++){
                s+=(int)(a[p]);
            }
            return s;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j] = solve(a,b,i-1,j-1,dp);
        }else{
            return dp[i][j] = min((int)(a[i])+solve(a,b,i-1,j,dp),(int)(b[j])+solve(a,b,i,j-1,dp));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return solve(s1,s2,n-1,m-1,dp);
    }
};