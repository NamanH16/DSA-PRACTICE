class Solution {
public:
    void solve(int i, vector<string> &ans, string output, string mapping[],string digits){
        if(i>=digits.length()){
            ans.push_back(output);
            return;
        }
        int num = digits[i]-'0';
        string val = mapping[num];
        
        for(int j=0;j<val.length();j++){
            output.push_back(val[j]);
            solve(i+1, ans, output, mapping, digits);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) { 
        vector<string> ans;
        if(digits.length()==0)return ans;
        string output="";
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0, ans, output, mapping, digits);
        return ans;
    }
};