class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = strs.size();
        string i=strs[0], j=strs[n-1];
        string ans="";
        for(int k=0;k<min(i.length(),j.length());k++){
            if(i[k]!=j[k])return ans;
            ans+=i[k];        
        }
        return ans;
    }
};