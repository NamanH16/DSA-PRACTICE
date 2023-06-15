class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int a=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                a=i;
                break;
            }
        }
        if(a<0){
            reverse(nums.begin(), nums.end());
        }else{
            int k=-1;
            for(k=n-1;k>=0;k--){
                if(nums[a]<nums[k]){
                    break;
                }
            }
            swap(nums[a],nums[k]);
            reverse(nums.begin()+a+1, nums.end());
        }
    }
};