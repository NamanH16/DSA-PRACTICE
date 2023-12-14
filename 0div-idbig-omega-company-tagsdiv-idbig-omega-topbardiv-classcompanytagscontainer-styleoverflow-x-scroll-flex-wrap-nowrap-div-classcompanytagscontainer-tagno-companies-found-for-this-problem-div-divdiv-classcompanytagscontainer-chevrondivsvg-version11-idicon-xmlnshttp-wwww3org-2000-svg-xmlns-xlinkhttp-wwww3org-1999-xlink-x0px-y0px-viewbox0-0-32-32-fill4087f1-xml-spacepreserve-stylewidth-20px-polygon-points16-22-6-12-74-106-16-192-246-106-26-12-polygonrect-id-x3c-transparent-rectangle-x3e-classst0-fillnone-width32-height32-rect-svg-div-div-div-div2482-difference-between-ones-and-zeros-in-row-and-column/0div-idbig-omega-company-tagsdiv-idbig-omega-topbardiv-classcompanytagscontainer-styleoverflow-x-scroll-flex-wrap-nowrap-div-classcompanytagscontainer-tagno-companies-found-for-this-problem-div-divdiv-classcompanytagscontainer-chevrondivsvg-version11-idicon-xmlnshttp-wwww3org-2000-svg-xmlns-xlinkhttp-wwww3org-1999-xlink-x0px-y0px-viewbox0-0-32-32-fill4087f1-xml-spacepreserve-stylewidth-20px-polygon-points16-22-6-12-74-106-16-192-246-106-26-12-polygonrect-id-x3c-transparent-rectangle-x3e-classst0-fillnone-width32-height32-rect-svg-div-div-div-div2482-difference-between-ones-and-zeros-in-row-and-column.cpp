class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        vector<int> onesCol(m), zerosCol(m),onesRow(n), zerosRow(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    zerosCol[i]++;
                    zerosRow[j]++;
                }else{
                    onesCol[i]++;
                    onesRow[j]++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = onesRow[j]+onesCol[i]-zerosRow[j]-zerosCol[i];
            }
        }
        return ans;
    }
};