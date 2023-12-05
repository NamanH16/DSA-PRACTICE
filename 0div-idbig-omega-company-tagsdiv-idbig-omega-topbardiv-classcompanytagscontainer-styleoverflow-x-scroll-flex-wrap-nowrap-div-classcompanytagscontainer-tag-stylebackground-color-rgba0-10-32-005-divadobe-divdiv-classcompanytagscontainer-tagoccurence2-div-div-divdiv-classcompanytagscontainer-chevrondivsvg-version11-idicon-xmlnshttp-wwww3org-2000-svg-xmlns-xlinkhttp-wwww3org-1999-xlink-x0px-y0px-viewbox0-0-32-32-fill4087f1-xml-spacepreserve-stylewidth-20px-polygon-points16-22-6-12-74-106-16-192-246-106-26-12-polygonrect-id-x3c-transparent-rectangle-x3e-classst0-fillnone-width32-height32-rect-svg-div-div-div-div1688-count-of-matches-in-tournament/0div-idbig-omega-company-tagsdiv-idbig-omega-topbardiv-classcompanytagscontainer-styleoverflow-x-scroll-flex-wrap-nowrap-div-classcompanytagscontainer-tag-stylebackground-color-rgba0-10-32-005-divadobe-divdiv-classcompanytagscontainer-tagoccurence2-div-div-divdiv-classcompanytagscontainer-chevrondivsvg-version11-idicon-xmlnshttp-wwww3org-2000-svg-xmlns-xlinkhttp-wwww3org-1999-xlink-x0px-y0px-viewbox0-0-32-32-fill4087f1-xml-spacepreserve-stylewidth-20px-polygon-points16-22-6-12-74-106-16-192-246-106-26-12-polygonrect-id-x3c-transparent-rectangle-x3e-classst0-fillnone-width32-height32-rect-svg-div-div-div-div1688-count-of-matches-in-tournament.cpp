class Solution {
public:
    int numberOfMatches(int n) {
        if(n==2)return 1;
        int x=n;
        int m=n/2, ans=0;
        while(n>1){
            ans+=m;
            n-=m;
        }
        return (x&1)?ans:ans-1;
    }
};