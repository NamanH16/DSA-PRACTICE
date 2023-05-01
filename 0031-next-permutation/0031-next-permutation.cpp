class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), ind1=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind1=i;
                break;
            }
        }
        if(ind1<0){
            reverse(nums.begin(),nums.end());
        }else{
            int k=0;
            for(k=n-1;k>=0;k--){
                if(nums[ind1]<nums[k]){
                    break;
                }
            }
            swap(nums[ind1],nums[k]);
            reverse(nums.begin()+ind1+1,nums.end());
        }
    }
};