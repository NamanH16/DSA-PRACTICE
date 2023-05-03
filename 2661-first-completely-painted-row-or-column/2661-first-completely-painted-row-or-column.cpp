class Solution {
public:
    int firstCompleteIndex(vector<int>& a, vector<vector<int>>& ma) {
        unordered_map<int,int> mpr,mpc,mprc,mpcc;
        int n = ma.size();
        int m = ma[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpr[ma[i][j]]=i;
                mpc[ma[i][j]]=j;
            }
        }
        for(int i=0;i<a.size();i++){
            int x = a[i];
            mprc[mpr[x]]++;
            mpcc[mpc[x]]++;
            if(mprc[mpr[x]]==m || mpcc[mpc[x]]==n){
                return i;
            }
        }
        return -1;
    }
};