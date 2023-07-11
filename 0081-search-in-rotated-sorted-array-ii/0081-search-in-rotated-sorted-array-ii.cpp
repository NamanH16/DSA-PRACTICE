class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high=n-1;
        while(low<=high){
            int mid = low +(high - low)/2;
            if(nums[mid]==target) return true;
            // for edge case for duplicate elements
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++, high--;
                continue;
            }
            // check for left half is sorted?
            if(nums[low] <= nums[mid]){
                // target is in left part so reduce right part search space
                if(nums[low] <= target && target <= nums[mid]){
                    high= mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
            // check for right part 
            if(nums[mid] <= target && target <=nums[high]){
                low = mid+1;
            }
            else{
            high = mid -1;
            }
        }
       
    }
    return false;
    }
};