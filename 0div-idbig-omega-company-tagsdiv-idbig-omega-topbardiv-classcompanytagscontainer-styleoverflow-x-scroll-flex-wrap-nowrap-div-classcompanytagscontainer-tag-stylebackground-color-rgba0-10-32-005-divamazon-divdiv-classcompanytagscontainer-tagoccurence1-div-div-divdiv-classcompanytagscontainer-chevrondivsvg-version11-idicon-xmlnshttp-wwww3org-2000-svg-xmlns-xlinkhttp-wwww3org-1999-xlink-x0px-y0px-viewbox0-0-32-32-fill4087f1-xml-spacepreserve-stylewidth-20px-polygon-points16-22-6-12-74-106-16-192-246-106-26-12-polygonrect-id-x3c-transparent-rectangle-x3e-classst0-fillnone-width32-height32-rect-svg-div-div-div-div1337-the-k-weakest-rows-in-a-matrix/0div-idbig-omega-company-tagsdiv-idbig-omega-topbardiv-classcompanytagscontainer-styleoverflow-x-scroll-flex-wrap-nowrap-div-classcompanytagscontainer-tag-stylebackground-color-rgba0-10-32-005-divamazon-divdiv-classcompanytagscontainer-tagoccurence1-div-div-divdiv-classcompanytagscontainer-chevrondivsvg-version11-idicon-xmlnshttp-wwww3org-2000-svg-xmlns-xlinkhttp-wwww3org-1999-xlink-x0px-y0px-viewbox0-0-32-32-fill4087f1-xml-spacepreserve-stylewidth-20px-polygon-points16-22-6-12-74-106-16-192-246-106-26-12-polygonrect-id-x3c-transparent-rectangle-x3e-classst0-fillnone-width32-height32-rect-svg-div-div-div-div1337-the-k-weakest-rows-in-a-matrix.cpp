class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>mp;
        vector<int> ans;
        int m = mat.size(), n=mat[0].size();
        for(int i=0;i<m;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            mp.push_back(make_pair(i,cnt));
        }
        sort(mp.begin(), mp.end(), cmp);
        for(auto x:mp){
            ans.push_back(x.first);
            k--;
            if(k==0)break;
        }
        return ans;
    }
};