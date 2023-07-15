class Solution {
public:
    // in order to get min time, we need to start the rot from every beginning rotting tree
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans = -1;
        vector<int> dir1 = {-1, 0, 1, 0};
        vector<int> dir2 = {0, -1, 0, 1};
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int newR = r + dir1[i];
                    int newC = c + dir2[i];
                    if(newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1) {
                        grid[newR][newC] = 2;
                        q.push({newR, newC});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh > 0) {
            return -1;
        }
        if(ans == -1) {
            return 0;
        }
        return ans;
    }
};