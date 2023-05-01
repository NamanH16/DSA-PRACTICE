class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int curr_sum=0, best_so_far=INT_MIN;
        for(int i=0;i<n;i++){
            curr_sum+=nums[i];
            if(curr_sum>best_so_far){
                best_so_far=curr_sum;
            }
            if(curr_sum<0){
                curr_sum=0;
            }
        }
        return best_so_far;
    }
};