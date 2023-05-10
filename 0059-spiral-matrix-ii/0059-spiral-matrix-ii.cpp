#define pb push_back
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int dir=1;
        int l=0, r=n-1, t=0, b=n-1;
        n*=n;
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.pb(i);
        }
        int k=0;
        while(l<=r && t<=b){
            if(dir==1){
                for(int i=l;i<=r;i++){
                    ans[t][i]=nums[k++];
                }
                dir=2;
                t++;
            }else if(dir==2){
                for(int i=t;i<=b;i++){
                    ans[i][r]=nums[k++];
                }
                dir=3;
                r--;
            }else if(dir==3){
                for(int i=r;i>=l;i--){
                    ans[b][i]=nums[k++];
                }
                dir=4;
                b--;
            }else if(dir==4){
                for(int i=b;i>=t;i--){
                    ans[i][l]=nums[k++];
                }
                dir=1;
                l++;
            }
        }
        return ans;
    }
};