class Solution {
public:
    int solve(string s,int sign,int i,long res){
        if(sign*res>=INT_MAX){
            return INT_MAX;
        }
        if(sign*res<=INT_MIN){
            return INT_MIN;
        }
        if(i>=s.size() || s[i]<'0' || s[i]>'9'){
            return sign*res;
        }
        res = solve(s, sign, i+1, res*10+(s[i]-'0'));
        return res;
    }
    
    int myAtoi(string s) {
        int n=s.length(), sign=1, i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        }else if(s[i]=='+'){
            sign=1;     
            i++;   
        }
        return solve(s,sign,i,0);
    }
};