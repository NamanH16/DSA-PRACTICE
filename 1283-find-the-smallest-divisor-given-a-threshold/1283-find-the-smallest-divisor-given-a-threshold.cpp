class Solution {
public:
    int f(vector<int> &arr, int div) {
        long long n = arr.size(); //size of array
        //Find the summation of division values:
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(arr[i]) / (double)(div));
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        // the result should be less than threshold value
        if(nums.size()>threshold)return -1;
        long long i = 1, j = *max_element(nums.begin(), nums.end()), ans=0;
        while(i<=j){
            long long m = i+(j-i)/2;
            if(f(nums, m)>threshold){
                i = m+1;
            }else{
                ans = m;
                j = m-1;
            }
        }
        return ans;
    }
};