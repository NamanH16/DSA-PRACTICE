class Solution {
public:
    bool same(string s){
        if(s.length()==1)return true;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]!=s[i+1])return false;
        }
        return true;
    }
    int maximumLength(string s) {
        int ans = -1, n = s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string x=s.substr(i, j-i+1);
                int cnt=0;
                if(same(x)){
                    int found = s.find(x);
                    while(found!=string::npos){
                        cnt++;
                        found = s.find(x, found+1);
                    }
                }
                if(cnt>=3){
                    int pp = x.length();
                    ans = max(ans, pp);
                }
            }
        }
        return ans;
    }
};