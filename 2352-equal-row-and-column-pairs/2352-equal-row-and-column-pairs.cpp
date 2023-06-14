class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        for(vector<int> row: grid){
            mp[row]++;
        }
        int n = grid.size(), m = grid[0].size(),ans=0;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<m;j++){
                temp.push_back(grid[j][i]);
            }
            ans+=mp[temp];
        }
        return ans;
    }
};