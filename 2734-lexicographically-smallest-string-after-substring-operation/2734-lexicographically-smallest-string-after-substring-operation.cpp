class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        int i=0;
        while(i<n && s[i]=='a'){
            i++;
        }
        if(i==n){
            s[s.size()-1]='z';
            return s;
        }
        while(i<s.size() && s[i]!='a'){
            s[i]--;i++;
        }
        return s;
    }
};