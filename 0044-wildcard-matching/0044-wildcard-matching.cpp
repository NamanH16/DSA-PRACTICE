class Solution {
public:
    bool solve(string &a,string &b,int i,int j,vector<vector<int>> &dp){
        if(i<0 && j<0)return true;
        if(j<0)return false;
        if(i<0){
            for(int k=0;k<=j;k++){
                if(b[k]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(a[i]==b[j] || b[j]=='?'){
            return dp[i][j]=solve(a,b,i-1,j-1,dp);
        }else if(b[j]=='*'){
            // * can represent either empty or any string
            return dp[i][j]=(solve(a,b,i,j-1,dp)||solve(a,b,i-1,j,dp));
        }else{
            return dp[i][j]=false;
        }
    }
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,p,n-1,m-1,dp);
    }
};