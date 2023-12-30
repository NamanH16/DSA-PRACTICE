class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        for(auto x:words){
            for(int i=0;i<x.length();i++){
                mp[x[i]]++;
            }
        }
        int n = words.size();
        for(auto x:mp){
            if(x.second%n!=0){
                return false;
            }
        }
        return true;
    }
};