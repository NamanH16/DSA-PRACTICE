class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int l=0, ans=0;
        for(int r=1;r<colors.size();r++){
            if(colors[l]==colors[r]){
                if(neededTime[l]<neededTime[r]){
                    ans += neededTime[l];
                    l = r;
                }else{
                    ans += neededTime[r];
                }
            }else{
                l=r;
            }
        }
        return ans;
    }
};