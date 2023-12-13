class Solution {
public:
    int func(int a,int b,int m){
        int res=1;
        for(int i=1;i<=b;i++){
            res = (res*a)%m;
        }
        return res;
    }
    
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for(int i=0;i<variables.size();i++){
            int base = func(variables[i][0], variables[i][1], 10);
            int exp = variables[i][2];
            if(func(base, exp, variables[i][3]) == target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};