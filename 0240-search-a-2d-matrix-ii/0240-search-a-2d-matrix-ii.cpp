class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int st = 0;
        int en = n-1;
        while(st<m && en>=0){
            if(matrix[st][en]==target){
                return true;
            }else if(matrix[st][en]>target){
                en--;
            }else{
                st++;
            }
        }
        return false;
    }
};