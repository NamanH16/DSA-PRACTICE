class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, en=nums.size()-1,ans=nums.size();
        while(st<=en){
            int m = st+(en-st)/2;
            if(nums[m]>=target){
                ans=m;
                en=m-1;
            }else{
                st=m+1;
            }
        }
        return ans;
    }
};