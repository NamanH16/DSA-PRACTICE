#define pb push_back
class Solution {
public:
    int solve(vector<int> &arr){
        int n = arr.size();
        if(n==0)return 0;
        if(n==1) return arr[0];
        if(n==2) return max(arr[0], arr[1]);
        vector<int> dp(n+1);
        dp[0]=arr[0];
        for(int i=1;i<n;i++){
            int pick = arr[i];
            if(i>=2)pick+=dp[i-2];
            int unpick = dp[i-1];
            dp[i]=max(pick, unpick);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        // 2 cases - when 1st house robbed and other- when 2nd house robbed
        vector<int> temp1, temp2;
        int n = nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0)temp1.pb(nums[i]);
            if(i!=n-1)temp2.pb(nums[i]);
        }
        return max(solve(temp1), solve(temp2));
    }
};