class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,char> mp;
        unordered_map<char,char> mp2;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end() && mp2.find(t[i])==mp2.end()){
                mp[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }
            if(mp[s[i]]!=t[i] || mp2[t[i]]!=s[i]){
                return false;
            }
        }
        return true;
    }
};