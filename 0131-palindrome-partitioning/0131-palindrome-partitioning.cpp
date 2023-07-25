class Solution {
private:
    void solve(int i,string s,vector<string>&ds, vector<vector<string>>&ans){
        if(i >= s.length()){
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(isPalindrome(s, i, j)){
                ds.push_back(s.substr(i, j-i+1));
                solve(j+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0, s, ds, ans);
        return ans;
    }
};