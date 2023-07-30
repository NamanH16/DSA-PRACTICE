class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        set<int> t;
        for(int i=0;i<n;i++){
            t.insert(nums[i]);
        }
        int tot_dis = t.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            set<int> temp;
            for(int j=i;j<n;j++){
                temp.insert(nums[j]);
                if(temp.size()==tot_dis)cnt++;
            }
        }
        return cnt;
    }
};