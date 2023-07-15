class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long sum = 0;
        long long ans = INT_MIN;
        int i = 0, j = 0;
        int n = nums.size();
        while(j<n){
            sum += nums[j];
            mp[nums[j]]++;
            if(j-i+1==k){
                if(mp.size()==k){
                    ans = max(sum , ans);
                }
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans==INT_MIN?0:ans;
    }
};