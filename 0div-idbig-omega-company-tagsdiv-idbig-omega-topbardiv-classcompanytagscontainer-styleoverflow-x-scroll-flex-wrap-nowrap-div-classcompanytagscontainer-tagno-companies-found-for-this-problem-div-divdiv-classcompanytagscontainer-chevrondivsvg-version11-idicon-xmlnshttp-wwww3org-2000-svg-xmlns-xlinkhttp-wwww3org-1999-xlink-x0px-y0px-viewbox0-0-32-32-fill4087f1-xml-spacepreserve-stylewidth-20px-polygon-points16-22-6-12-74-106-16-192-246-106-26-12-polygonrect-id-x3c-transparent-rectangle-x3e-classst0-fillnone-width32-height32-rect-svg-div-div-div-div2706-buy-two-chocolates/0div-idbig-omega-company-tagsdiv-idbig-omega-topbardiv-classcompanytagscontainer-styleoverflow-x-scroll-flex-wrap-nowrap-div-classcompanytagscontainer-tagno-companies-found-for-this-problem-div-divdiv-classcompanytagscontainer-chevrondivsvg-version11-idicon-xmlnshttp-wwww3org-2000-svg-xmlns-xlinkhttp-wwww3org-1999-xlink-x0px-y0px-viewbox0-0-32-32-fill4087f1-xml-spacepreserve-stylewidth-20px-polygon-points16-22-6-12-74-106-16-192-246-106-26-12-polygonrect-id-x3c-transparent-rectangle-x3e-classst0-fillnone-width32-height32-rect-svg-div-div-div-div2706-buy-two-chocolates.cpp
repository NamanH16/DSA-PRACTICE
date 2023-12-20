class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mn = INT_MAX, smn = INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(mn>prices[i]){
                smn=mn;
                mn=prices[i];
            }else if(smn>=prices[i]){
                smn=prices[i];
            }
        }
        return  money-(mn+smn)<0?money:money-(mn+smn);
    }
};