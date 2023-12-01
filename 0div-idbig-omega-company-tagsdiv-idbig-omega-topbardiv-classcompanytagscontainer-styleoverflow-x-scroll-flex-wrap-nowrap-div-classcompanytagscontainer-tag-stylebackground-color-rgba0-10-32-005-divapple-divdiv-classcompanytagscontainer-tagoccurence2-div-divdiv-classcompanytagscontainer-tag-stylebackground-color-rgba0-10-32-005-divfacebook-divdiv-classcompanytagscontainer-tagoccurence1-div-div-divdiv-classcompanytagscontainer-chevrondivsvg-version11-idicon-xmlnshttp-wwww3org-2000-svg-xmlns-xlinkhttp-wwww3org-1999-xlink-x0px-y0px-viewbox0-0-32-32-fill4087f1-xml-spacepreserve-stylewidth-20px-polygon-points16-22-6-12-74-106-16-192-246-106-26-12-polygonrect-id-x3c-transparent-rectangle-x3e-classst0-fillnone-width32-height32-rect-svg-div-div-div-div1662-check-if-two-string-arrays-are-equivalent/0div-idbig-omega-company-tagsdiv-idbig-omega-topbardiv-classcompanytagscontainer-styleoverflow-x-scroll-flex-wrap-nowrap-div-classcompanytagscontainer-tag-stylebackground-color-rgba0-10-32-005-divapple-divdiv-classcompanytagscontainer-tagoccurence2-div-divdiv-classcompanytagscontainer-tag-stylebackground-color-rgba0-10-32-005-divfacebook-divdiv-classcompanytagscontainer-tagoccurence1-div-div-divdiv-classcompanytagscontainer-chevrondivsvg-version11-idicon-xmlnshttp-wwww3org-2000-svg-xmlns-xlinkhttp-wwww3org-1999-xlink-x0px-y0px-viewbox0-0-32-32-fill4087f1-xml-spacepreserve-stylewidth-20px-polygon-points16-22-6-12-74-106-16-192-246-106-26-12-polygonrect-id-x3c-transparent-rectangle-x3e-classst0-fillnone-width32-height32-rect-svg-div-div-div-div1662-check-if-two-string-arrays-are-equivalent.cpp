class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s="", c="";
        for(auto x:word1){
            s+=x;
        }
        for(auto x:word2){
            c+=x;
        }
        return s==c;
    }
};