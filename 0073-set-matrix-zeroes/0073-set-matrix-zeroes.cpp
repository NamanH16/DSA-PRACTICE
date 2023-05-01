class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> zero(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    zero[i][j]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(zero[i][j]){
                    for(int k=0;k<n;k++){
                        matrix[k][j]=0;
                    }
                    for(int l=0;l<m;l++){
                        matrix[i][l]=0;
                    }
                }
            }
        }
    }
};