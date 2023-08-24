class Solution {
public:
    const int MOD = 1e9+7;
    int countPairs(vector<int>& deliciousness) {
        long long int n = deliciousness.size();
        long long int ans=0;
        unordered_map<int,int>mp;
        for(int i:deliciousness){
            for(int j=1;j<=pow(2,22);j*=2){
                if(mp.find(j-i)!=mp.end()){
                    ans+=mp[j-i];
                }
            }
            mp[i]++;
        }
        return ans%MOD;
    }
};