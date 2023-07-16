class Solution {
public:
    bool possible(vector<int>& bloomDay, int m, int k,int p){
        long long cnt=0, no_of_bouquets=0;
        long long n = bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=p){
                cnt++;
            }else{
                no_of_bouquets += (cnt/k);
                cnt=0;
            }
        }
        no_of_bouquets += (cnt/k);
        return no_of_bouquets>=m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m*1LL*k*1LL > n)return -1;
        int i = *min_element(bloomDay.begin(), bloomDay.end()), j = *max_element(bloomDay.begin(), bloomDay.end());
        while(i<=j){
            int mid = i+(j-i)/2;
            if(possible(bloomDay, m, k, mid)){
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return i;
    }
};