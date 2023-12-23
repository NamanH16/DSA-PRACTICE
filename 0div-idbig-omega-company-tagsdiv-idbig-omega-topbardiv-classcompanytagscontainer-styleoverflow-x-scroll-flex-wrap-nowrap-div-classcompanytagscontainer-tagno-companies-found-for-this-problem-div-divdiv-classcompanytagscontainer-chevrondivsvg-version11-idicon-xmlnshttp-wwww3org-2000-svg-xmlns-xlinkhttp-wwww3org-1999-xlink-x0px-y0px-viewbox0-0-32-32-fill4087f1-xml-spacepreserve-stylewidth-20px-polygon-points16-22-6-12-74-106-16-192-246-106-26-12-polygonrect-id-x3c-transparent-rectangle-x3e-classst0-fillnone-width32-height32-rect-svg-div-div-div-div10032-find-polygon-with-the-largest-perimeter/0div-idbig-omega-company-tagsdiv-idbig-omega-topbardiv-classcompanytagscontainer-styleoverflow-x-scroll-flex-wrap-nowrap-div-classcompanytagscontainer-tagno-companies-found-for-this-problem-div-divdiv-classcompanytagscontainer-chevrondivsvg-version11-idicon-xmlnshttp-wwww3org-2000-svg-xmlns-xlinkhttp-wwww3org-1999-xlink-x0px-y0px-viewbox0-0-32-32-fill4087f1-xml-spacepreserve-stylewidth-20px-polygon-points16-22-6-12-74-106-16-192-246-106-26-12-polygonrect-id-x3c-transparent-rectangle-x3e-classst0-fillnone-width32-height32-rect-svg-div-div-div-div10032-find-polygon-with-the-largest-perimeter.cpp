class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long s = accumulate(nums.begin(),nums.end(), 0LL);
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=2;i--){
            s-=nums[i];
            if(s>nums[i])return s+nums[i];
        }
        return -1;
    }
};