class Solution {
public:
    int f(vector<int>&ar,int p){
        int n = ar.size();
        int curr_sum = 0, split=1;
        for(int i=0;i<n;i++){
            if(ar[i]+curr_sum<=p){
                curr_sum+=ar[i];
            }else{
                split++;
                curr_sum = ar[i];
            }
        }
        return split;
    }
    
    int splitArray(vector<int>& nums, int k) { 
        int st = *max_element(nums.begin(), nums.end());
        int en = accumulate(nums.begin(), nums.end(), 0); // k==1
        // for(int i=st;i<=en;i++){
        //     int cntsplits = f(nums, i);
        //     if(cntsplits == k){
        //         return i;
        //     }
        // }
        // return st;
        while(st<=en){
            int mid = st+(en-st)/2;
            int cntsplits = f(nums,mid);
            if(cntsplits>k){
                st = mid+1;
            }else{
                en = mid-1;
            }
        }
        return st;
    }
};