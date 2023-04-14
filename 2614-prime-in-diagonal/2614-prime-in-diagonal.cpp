class Solution {
private:
    bool prime(int n){
        if(n <= 1) return false;
      for (int i = 2; i * i <= n; i++){
        if (n % i == 0)return false;
      }
      return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int m = nums.size();
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            if(prime(nums[i][i])){
                ans=max(ans, nums[i][i]);
            }
             if(prime(nums[i][m-i-1])){
                ans=max(ans,nums[i][m-i-1]);
            }
        }
        return ans==INT_MIN?0:ans;
    }
};