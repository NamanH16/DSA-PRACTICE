class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int prev = -1, n = arr.size(),cnt=0;
        for(auto x:arr){
            if(x==prev){
                cnt++;
            }else{
                prev=x;
                cnt=1;
            }
            if(cnt>arr.size()/4){
                return x;
            }
        }
        return -1;
    }
};