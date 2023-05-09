#define pb push_back
#define loop(x,n) for(int x = 0; x < n; ++x)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        vector<int> ans;
        int n = ma.size();
        int m = ma[0].size();
        int l=0, r=m-1, t=0, b=n-1;
        int dir=1;
        while(l<=r && t<=b){
            if(dir==1){
                for(int i=l;i<=r;i++){
                    ans.pb(ma[t][i]);
                }
                dir=2;
                t++;
            }else if(dir==2){
                for(int i=t;i<=b;i++){
                    ans.pb(ma[i][r]);
                }
                dir=3;
                r--;
            }else if(dir==3){
                for(int i=r;i>=l;i--){
                    ans.pb(ma[b][i]);
                }
                dir=4;
                b--;
            }else if(dir==4){
                for(int i=b;i>=t;i--){
                    ans.pb(ma[i][l]);
                }
                dir=1;
                l++;
            }
        }
        return ans;
    }
};