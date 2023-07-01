class Solution {
public:
    int dp[1005][1005];
    int solve(string s, string t,int i,int j){
        // base case
        if(j<0)return 1;
        if(i<0)return 0;
        
        // cache
        if(dp[i][j]!=-1)return dp[i][j];
        
        // compute
        if(s[i]==t[j]){
            return dp[i][j]=solve(s,t,i-1,j)+solve(s,t,i-1,j-1);
        }else{
            return dp[i][j]=solve(s,t,i-1,j);
        }
        
        // save and return
    }
    
    int numDistinct(string s, string t) {
        int n=s.length(), m=t.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,t,n-1,m-1);
    }
};