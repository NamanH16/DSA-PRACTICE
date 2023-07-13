class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0, en = nums.size()-1;
        int ans = INT_MAX;
        while(st<=en){
            int mid = (st+en)>>1;
            if(nums[st]<=nums[mid]){
                ans = min(ans, nums[st]);
                st = mid+1;
            }else{
                ans = min(ans, nums[mid]);
                en = mid-1;
            }
        }
        return ans;
    }
};