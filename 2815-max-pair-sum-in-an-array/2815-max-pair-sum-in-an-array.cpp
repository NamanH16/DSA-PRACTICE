class Solution {
public:
    bool f(int x,int y){
        int mx=INT_MIN, m2x=INT_MIN;
        while(x>0){
            int m = x%10;
            mx=max(mx,m);
            x/=10;
        }
        while(y>0){
            int m = y%10;
            m2x=max(m2x,m);
            y/=10;
        }
        return mx==m2x;
    }
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(f(nums[i],nums[j])){
                    //cout << nums[i] << " " << nums[j] << '\n';
                    ans=max(ans,nums[i]+nums[j]);
                }
            }
        }
        return ans==INT_MIN?-1:ans;
    }
};