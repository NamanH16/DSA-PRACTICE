class Solution {
public:
    const int MOD = 1000000007;
    long long rev(long long x){
        long long ans=0;
        while(x>0){
            ans=ans*10+x%10;
            x/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,long>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]-rev(nums[i])]++;
        }
        long ans=0;
        for(auto& pair : mp)  // with each value, we can form n*(n-1)/2 pairs
		    ans = (ans + (pair.second * (pair.second - 1)) / 2) % 1000000007; 
        return ans;
    }
};