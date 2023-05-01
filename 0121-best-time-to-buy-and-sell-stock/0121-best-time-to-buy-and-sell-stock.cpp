class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // we need max profit, i.e. max diff possible
        // for this max-min is our ans
        int n = prices.size();
        int mn=INT_MAX, mxdiff=INT_MIN;
        for(int i=0;i<n;i++){
            if(mn>prices[i]){
                mn=prices[i];
            }
            if(prices[i]-mn>mxdiff){
                mxdiff=prices[i]-mn;
            }
        }
        return mxdiff;
    }
};