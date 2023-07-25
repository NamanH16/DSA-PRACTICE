class Solution {
public:
    int dp[303];
    int help(int i,string s,set<string> &st){
        if(i==s.length())return 1;
        string temp="";
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(help(j+1, s, st)){
                    return dp[i]=1;
                }
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto x:wordDict){
            st.insert(x);
        }
        memset(dp, -1, sizeof(dp));
        return help(0, s, st);
    }
};