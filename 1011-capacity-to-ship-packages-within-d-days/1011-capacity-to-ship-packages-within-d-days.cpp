class Solution {
public:
    int f(vector<int>& we, int mx){
        int curr_weight = 0, days = 1;
        for(int i=0;i<we.size();i++){
            if(curr_weight+we[i]<=mx){
                curr_weight+=we[i];
            }else{
                days++;
                curr_weight = we[i];
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        // min capacity = max weight of containers available
        int i = *max_element(weights.begin(), weights.end());
        int j = accumulate(weights.begin(), weights.end(), 0);
        while(i<=j){
            int m = i+(j-i)/2;
            int no_of_days = f(weights, m);
            if(no_of_days<=days){
                j = m-1;
            }else{
                i = m+1;
            }
        }
        return i;
    }
};