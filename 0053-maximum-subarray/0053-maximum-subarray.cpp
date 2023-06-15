class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_sum=0, best=INT_MIN;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            if(curr_sum>best){
                best=curr_sum;
            }
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        return best;
    }
};