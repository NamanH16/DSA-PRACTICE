class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        stringstream ss(s);
        string tmp;
        while(ss>>tmp){
            temp.push_back(tmp);
        }
        string ans="";
        for(int i=temp.size()-1;i>=0;i--){
            if(i!=temp.size()-1)ans+=" ";
            ans+=temp[i];
        }
        return ans;
    }
};