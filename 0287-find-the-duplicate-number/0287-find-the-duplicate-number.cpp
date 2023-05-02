class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Brute Force(O(n^2))
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             return nums[i];
        //         }
        //     }
        // }
        // return -1;
        
        // Better
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                return nums[i];
            }
        }
        return -1;
    }
};