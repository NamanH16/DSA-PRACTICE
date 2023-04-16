class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int mxCount=-1;
        int y=-1;
        vector<int>ans;
        int i,j;
        for(i=0;i<n;i++){
            int cnt=0;
            for(j=0;j<m;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            if(cnt>mxCount){
                mxCount=cnt;
                y=i;
            }
        }
        ans.push_back(y);
        ans.push_back(mxCount);
        return ans;
    }
};