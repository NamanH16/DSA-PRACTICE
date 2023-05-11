class Solution {
private:
    int f(vector<int>& nums1, vector<int>& nums2, int m,int n, vector<vector<int>> &dp){
        if(m==0 || n==0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        if(nums1[m-1]==nums2[n-1]){
            dp[m][n] = 1+f(nums1,nums2,m-1,n-1,dp);
        }else{
            dp[m][n]=max(f(nums1,nums2,m-1,n,dp), f(nums1,nums2,m,n-1,dp));
        }
        return dp[m][n];
    }
    
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // Recursion
        int m = nums1.size(), n=nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return f(nums1,nums2,m,n,dp);
    }
};