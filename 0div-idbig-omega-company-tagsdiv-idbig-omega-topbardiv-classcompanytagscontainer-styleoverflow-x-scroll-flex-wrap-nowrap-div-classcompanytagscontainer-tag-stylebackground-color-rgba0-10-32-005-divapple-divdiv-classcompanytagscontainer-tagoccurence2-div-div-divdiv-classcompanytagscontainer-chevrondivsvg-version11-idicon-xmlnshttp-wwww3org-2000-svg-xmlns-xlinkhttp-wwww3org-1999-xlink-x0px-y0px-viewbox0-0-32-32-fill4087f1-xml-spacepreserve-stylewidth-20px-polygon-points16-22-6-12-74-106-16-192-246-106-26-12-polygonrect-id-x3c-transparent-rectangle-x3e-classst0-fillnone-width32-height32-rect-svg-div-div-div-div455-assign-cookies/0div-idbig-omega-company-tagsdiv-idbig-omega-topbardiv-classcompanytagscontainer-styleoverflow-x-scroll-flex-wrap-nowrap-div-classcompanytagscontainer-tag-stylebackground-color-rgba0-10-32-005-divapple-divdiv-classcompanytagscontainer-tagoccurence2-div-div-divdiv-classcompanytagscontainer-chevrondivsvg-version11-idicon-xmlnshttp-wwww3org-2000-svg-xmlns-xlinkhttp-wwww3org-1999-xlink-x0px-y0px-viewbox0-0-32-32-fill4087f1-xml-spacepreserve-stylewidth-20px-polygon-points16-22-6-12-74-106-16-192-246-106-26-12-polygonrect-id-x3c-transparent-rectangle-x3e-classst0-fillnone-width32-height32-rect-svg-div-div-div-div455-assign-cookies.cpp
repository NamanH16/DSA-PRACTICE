class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0, j=0, m=g.size(), n=s.size(), cnt=0;
        while(i<m && j<n){
            if(s[j]>=g[i]){
                cnt++;
                j++;i++;
            }else{
                j++;
            }
        }
        return cnt;
    }
};