class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int> mp;
        int n = s.length(), ans=-1;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                ans=max(ans, (i-mp[s[i]])-1);
            }else{
                mp[s[i]]=i;
            }
        }
        return ans;
    }
};