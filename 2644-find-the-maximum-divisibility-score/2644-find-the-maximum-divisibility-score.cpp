class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        vector<int>cnt(divisors.size(),0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<divisors.size();j++){
                if(nums[i]%divisors[j]==0){
                    cnt[j]++;
                }
            }
        }
        int mxcnt=-1, ans=-1;
        for(int i=0;i<divisors.size();i++){
            if(cnt[i]>mxcnt||(cnt[i]==mxcnt && divisors[i]<ans)){
                mxcnt=cnt[i];
                ans=divisors[i];
            }
        }
        return ans;
    }
};