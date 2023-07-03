class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;

        for(int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
        
        vector<vector<int>> ans;
        for(int i=2;i+i<=n;i++){
            if(sieve[i]){
                int target = n-i;
                if(target>1 && sieve[target]){
                    ans.push_back({i,target});
                }
            }
        }
        return ans;
    }
};