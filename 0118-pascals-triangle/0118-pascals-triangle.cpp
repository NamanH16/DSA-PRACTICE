class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>sol(numRows);
        for(int i=0;i<numRows;i++){
            sol[i].resize(i+1);
            sol[i][0]=sol[i][i]=1;
            for(int j=1;j<i;j++){
                sol[i][j]=sol[i-1][j-1]+sol[i-1][j];
            }
        }
        return sol;
    }
};