class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posindex= 0, negindex = 1;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[posindex]=nums[i];
                posindex+=2;
            }
            if(nums[i]<0){
                ans[negindex]=nums[i];
                negindex+=2;
            }
        }
        return ans;
    }
};