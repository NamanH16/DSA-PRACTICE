class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size()<3){
            return -1;
        }
        int l = 0, h = arr.size()-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(arr[m]<arr[m+1]){
                l=m+1; 
            }else{
                h=m-1;
            }
        }
        return l;
    }
};