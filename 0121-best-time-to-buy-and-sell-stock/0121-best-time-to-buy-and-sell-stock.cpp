class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int ans = INT_MIN, mn = INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<mn){
                mn=arr[i];
            }
            if(arr[i]-mn>ans){
                ans=max(ans, arr[i]-mn);
            }
        }
        return ans;
    }
};