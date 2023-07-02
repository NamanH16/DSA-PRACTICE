class Solution {
public:
    int dp[505][505];
    int solve(string a, string b, int i,int j){
        // base 
        if(i<0)return j+1;
        if(j<0)return i+1;
        //cache
        if(dp[i][j]!=-1)return dp[i][j];
        // compute
        if(a[i]==b[j]){
            return dp[i][j] = solve(a,b,i-1,j-1);
        }else{
            int insert = 1+solve(a, b, i, j-1);
            int delet = 1+solve(a,b,i-1, j);
            int replace = 1+solve(a, b, i-1, j-1);
            
            return dp[i][j]=min(insert, min(delet, replace));
        }
        //save n return  
        
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, n-1, m-1);
    }
};