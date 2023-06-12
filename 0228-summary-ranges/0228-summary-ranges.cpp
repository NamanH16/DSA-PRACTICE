class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string >ans;
        int n = nums.size();
        if(n==0)return ans;
        for(int i=0;i<n;i++){
            int st = nums[i];
            while(i+1<n && nums[i]+1==nums[i+1]){
                i++;
            }
            if(st!=nums[i]){
                ans.push_back(to_string(st)+"->"+to_string(nums[i]));
            }else{
                ans.push_back(to_string(st));
            }
        }
        return ans;
    }
};