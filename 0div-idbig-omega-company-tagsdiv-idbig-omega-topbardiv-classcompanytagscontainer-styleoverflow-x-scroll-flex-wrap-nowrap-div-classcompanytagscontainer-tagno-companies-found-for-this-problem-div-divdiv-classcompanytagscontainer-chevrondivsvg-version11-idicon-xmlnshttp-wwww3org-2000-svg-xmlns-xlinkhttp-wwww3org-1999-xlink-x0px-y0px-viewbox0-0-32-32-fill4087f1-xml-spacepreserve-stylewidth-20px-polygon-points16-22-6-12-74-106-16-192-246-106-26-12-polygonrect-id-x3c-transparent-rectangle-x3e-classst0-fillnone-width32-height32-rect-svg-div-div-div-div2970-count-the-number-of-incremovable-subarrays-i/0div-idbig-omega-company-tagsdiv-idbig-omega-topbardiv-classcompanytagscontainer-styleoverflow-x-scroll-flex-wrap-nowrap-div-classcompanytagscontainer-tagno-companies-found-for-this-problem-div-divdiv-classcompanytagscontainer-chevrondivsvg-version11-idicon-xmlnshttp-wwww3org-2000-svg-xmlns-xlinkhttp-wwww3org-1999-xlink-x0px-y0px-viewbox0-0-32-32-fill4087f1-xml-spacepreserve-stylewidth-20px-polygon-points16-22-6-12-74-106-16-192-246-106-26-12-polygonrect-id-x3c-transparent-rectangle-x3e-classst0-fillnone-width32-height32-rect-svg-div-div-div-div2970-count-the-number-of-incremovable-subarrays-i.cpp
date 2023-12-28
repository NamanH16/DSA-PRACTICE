class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                bool ok = true;
                int prev=-1;
                for(int k=0;k<n;k++){
                    if(k>=i && k<=j){
                        
                    }else{
                        ok &= (prev<nums[k]);
                        prev=nums[k];
                    }
                }
                if(ok)ans++;
            }
        }
        return ans;
    }
};