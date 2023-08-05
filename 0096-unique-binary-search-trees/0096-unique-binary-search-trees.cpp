class Solution {
public:
    int solve(int l,int h){
        if(l>=h){
            return 1;
        }
        int tot = 0;
        for(int i=l;i<=h;i++){
            tot += solve(l, i-1)*solve(i+1, h);
        }
        return tot;
    }
    int numTrees(int n) {
        return solve(1, n);
    }
};