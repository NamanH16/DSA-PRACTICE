class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> g = grid;
        for(int i=0;i<grid.size();i++){
            for(int j=i;j<grid[0].size();j++){
                swap(grid[i][j], grid[j][i]);
            }
        }
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(g[i]==grid[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};