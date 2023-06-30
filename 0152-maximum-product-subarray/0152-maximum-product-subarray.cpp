class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int front=1, back=1;
        int n=nums.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            front *= nums[i];
            back *= nums[n-i-1];
            ans = max({ans, front, back});
            if(front==0)front=1;
            if(back==0)back=1;
        }
        return ans;
    }
};