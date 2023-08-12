class Solution {
public:
    int beautySum(string s) {
        int n = s.length(),ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                int mini=500,maxi=0;
                mp[s[j]]++;
                for(auto x:mp){
                    maxi=max(maxi,x.second);
                    mini=min(mini,x.second);
                }
                ans+=(maxi-mini);
            }
            mp.clear();
        }
        return ans;
    }
};