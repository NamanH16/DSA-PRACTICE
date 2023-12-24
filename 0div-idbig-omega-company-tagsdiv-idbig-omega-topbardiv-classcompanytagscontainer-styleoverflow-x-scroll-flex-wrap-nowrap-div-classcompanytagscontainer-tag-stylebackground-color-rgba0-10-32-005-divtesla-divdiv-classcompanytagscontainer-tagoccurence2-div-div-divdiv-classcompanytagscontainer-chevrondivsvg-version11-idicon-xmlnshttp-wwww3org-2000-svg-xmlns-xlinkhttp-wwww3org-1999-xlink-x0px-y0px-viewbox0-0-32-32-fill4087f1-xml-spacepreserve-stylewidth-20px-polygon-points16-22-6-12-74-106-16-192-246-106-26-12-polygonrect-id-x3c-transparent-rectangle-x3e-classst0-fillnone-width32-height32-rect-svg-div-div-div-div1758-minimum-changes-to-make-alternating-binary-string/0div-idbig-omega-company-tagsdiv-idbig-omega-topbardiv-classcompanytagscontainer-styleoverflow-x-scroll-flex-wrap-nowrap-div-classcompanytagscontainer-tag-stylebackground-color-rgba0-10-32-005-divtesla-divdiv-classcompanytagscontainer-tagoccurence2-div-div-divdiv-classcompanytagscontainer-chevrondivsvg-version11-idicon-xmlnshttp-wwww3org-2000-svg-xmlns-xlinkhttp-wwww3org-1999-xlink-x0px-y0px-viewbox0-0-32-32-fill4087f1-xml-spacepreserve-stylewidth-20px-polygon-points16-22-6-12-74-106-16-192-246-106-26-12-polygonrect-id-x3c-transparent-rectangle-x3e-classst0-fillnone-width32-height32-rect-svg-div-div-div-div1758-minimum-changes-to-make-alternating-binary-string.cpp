class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string z="", o="";
        for(int i=0;i<n;i++){
            if(i&1){
                z+='0';
                o+='1';
            }else{
                z+='1';
                o+='0';
            }
        }
        int cnt1=0, cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]!=z[i])cnt1++;
            if(s[i]!=o[i])cnt2++;
        }
        return min(cnt1,cnt2);
    }
};