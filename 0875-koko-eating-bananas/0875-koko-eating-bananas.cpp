class Solution {
public:
    long long f(vector<int> &v, int hourly) {
        long long totalH = 0;
        long long n = v.size();
        //find total hours:
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
}
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int i=1, j = mx, ans = -1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(f(piles, m)<=h){
                ans = m;
                j = m-1;
            }else{
                i = m+1;
            }
        }
        return ans;
    }
};