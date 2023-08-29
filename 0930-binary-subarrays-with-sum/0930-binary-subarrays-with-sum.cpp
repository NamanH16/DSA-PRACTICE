class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum=0,ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==goal){
                ans++;
            }
            if(mp.find(sum-goal)!=mp.end()){
                ans+=mp[sum-goal];
            }
            mp[sum]++;
        }
        return ans;
    }
};