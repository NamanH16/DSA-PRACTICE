class Solution {
public:
    int dp[505][505];
    int rec(int i,int j,vector<int> &arr){
        // base case
        if(i+1==j){
            return max(arr[i], arr[j]);
        }
        // cache
        if(dp[i][j]!=-1)return dp[i][j];
        // compute
        int ans = max(arr[i]+min(rec(i+2,j,arr), rec(i+1, j-1, arr)), arr[j]+min(rec(i+1, j-1, arr), rec(i,j-2, arr)));
        // save and return 
        return dp[i][j]=ans;
    }
    
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        int temp = rec(0, piles.size()-1, piles);
        int sum = accumulate(piles.begin(), piles.end(), 0);
        int diff = sum-temp;
        if(diff<temp){
            return true;
        }
        return false;
    }
};