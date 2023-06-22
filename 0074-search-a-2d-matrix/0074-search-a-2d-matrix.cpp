class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int st=0, en=(m*n)-1;
        while(st<=en){
            int mid = st+(en-st)/2;
            if(matrix[mid/n][mid%n]==target){
                return true;
            }
            if(matrix[mid/n][mid%n]<target){
                st=mid+1;
            }else{
                en=mid-1;
            }
        }
        return false;
    }
};