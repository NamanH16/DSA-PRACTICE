class Solution {
private:
    int len(int n){
        if(n<0){
            n*=-1;
            int cnt=0;
            while(n!=0){
                n/=10;
                cnt++;
            }
            return cnt+1;
        }
        if(n==0)return 1;
        int cnt=0;
        while(n!=0){
            n/=10;
            cnt++;
        }
        return cnt;
    }
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            int leng=0;
            for(int j=0;j<n;j++){
                leng=max(leng,len(grid[j][i]));
            }          
            ans.push_back(leng);
        }
        return ans;
    }
};