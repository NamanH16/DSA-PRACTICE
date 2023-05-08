class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int s=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    s+=mat[i][j];
                }
                if(i+j==m-1){
                    s+=mat[i][j];
                }
            }
        }
        if(m&1){
            s-=mat[m/2][n/2];
        }
        return s;
    }
};