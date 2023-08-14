class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n), ss(n);
        ps[0]=nums[0];
        for(int i=1;i<n;i++){
            ps[i]=ps[i-1]+nums[i];
        }
        ss[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            ss[i]=ss[i+1]+nums[i];
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(ss[i]==ps[i]){
                ans=i;
                break;
            }
        }
        return ans;
    }
};