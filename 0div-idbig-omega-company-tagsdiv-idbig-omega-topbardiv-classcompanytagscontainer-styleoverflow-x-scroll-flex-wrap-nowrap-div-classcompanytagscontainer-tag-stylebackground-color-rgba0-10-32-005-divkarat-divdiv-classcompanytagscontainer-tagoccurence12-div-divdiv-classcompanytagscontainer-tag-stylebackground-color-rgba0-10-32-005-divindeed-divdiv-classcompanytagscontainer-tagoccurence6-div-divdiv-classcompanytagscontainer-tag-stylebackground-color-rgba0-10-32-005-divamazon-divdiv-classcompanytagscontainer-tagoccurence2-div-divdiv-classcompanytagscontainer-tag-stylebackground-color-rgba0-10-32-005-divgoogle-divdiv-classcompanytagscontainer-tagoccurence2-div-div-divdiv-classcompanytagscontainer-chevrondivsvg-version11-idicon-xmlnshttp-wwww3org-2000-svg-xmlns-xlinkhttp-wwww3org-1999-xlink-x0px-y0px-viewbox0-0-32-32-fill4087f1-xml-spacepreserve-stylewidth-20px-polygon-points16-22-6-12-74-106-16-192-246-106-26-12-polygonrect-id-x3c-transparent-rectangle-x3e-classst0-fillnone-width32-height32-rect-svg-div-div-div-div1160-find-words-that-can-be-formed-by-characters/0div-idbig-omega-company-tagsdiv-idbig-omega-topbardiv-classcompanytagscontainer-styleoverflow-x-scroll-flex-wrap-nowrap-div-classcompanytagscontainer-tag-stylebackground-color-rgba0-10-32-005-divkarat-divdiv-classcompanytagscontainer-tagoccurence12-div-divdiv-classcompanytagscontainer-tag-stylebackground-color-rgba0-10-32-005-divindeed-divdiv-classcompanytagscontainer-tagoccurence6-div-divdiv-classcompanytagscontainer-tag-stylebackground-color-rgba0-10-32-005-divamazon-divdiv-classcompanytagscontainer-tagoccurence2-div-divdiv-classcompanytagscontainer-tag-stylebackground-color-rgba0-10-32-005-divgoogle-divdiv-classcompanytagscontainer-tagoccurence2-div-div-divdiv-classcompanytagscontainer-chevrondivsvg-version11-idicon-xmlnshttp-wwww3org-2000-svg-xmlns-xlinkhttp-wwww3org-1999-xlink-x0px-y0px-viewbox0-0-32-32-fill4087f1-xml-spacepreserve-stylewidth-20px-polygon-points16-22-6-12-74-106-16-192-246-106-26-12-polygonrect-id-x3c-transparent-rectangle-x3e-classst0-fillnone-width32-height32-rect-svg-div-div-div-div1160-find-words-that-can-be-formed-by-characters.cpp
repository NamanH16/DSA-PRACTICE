class Solution {
public:
    bool check(string s,string m){
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<m.length();i++){
            if(mp.find(m[i])!=mp.end()){
                mp[m[i]]--;
                if(mp[m[i]]==0){
                    mp.erase(m[i]);
                }
            }
        }
        for(auto x:mp){
            if(x.second>0){
                return  false;
            }
        }
        return true;
    }
    
    int countCharacters(vector<string>& words, string chars) {
        long ans=0;
        for(auto x:words){
            ans+=(check(x, chars))?x.length():0;
        }
        return ans;
    }
};