class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int iniColor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            image[r][c] = color;
            vis[r][c] = 1;
            int rr[] = {0,-1,0,1};
            int cc[] = {-1, 0, 1, 0};
            for(int i = 0; i < 4; i++){
                int nrow = r + rr[i];
                int ncol = c + cc[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == iniColor && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};