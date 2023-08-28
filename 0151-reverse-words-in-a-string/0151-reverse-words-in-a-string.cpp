class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        stringstream ss(s);
        string t;
        while(ss>>t){
            ans.push_back(t);
        }
        string sol="";
        for(int i=ans.size()-1;i>=0;i--){
            if(i!=ans.size()-1)sol+=" ";
            sol+=ans[i];
        }
        return sol;
    }
};