class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int a = INT_MIN, b=INT_MIN, c=INT_MAX, d=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>a){
                b=a;
                a=nums[i];
            }else if(nums[i]>b){
                b = nums[i];
            }
            if(nums[i]<c){
                d=c;
                c=nums[i];
            }else if(nums[i]<d){
                d = nums[i];
            }
        }
        return ((a*b)-(c*d));
    }
};