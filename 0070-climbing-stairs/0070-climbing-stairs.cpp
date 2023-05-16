class Solution {
public:
    int helper(vector<int> &mem, int n){
        if(n==0)return 0;
        if(mem[n]!=-1)return mem[n];
        int ans=-1;
        if(n==1){
            return 1;
        }else if(n==2){
            return 2;
        }else{
            mem[n]=helper(mem,n-1)+helper(mem,n-2);
        }
        ans=mem[n];
        return ans;
    }
    
    int climbStairs(int n) {
        vector<int> mem(n+1, -1);
        return helper(mem,n);
    }
};