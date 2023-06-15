class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // in order to get the max profit
        // the difference should be max as well
        // mx-mn
        int mxProfit = INT_MIN, mn=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<mn){
                mn=prices[i];
            }
            if(prices[i]-mn>mxProfit){
                mxProfit=prices[i]-mn;
            }
        }
        return mxProfit;
    }
};