class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p=0,n=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                return 0;
            }else if(nums[i]<0){
                n++;
            }else if(nums[i]>0){
                p++;
            }
        }
        if(n&1){
            return -1;
        }else{
            return 1;
        }
    }
};