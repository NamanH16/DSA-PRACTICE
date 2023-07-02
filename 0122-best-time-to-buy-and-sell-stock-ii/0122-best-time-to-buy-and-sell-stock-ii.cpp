class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0)return 0;
        int i=0, j=1, ans=0;
        while(j<n){
            if(prices[j]>prices[i]){
                ans+=(prices[j]-prices[i]);
            }
            i++;j++;
        }
        return ans;
    }
};