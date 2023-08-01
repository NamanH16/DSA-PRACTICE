class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int target = nums[i]+nums[j]+nums[k];
                if(target==0){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }else if(target<0){
                    j++;
                }else{
                    k--;
                }
            }
            
        }
        vector<vector<int>> ans;
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};