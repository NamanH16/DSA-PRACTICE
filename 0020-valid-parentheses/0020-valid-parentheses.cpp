class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            int x = s[i];
            if(x=='(' || x=='[' || x=='{'){
                st.push(x);
            }else{
                if((!st.empty() && x==')' && st.top()=='(')||(!st.empty() && x=='}' && st.top()=='{')||(!st.empty() && x==']' && st.top()=='[')){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.size()==0;
    }
};