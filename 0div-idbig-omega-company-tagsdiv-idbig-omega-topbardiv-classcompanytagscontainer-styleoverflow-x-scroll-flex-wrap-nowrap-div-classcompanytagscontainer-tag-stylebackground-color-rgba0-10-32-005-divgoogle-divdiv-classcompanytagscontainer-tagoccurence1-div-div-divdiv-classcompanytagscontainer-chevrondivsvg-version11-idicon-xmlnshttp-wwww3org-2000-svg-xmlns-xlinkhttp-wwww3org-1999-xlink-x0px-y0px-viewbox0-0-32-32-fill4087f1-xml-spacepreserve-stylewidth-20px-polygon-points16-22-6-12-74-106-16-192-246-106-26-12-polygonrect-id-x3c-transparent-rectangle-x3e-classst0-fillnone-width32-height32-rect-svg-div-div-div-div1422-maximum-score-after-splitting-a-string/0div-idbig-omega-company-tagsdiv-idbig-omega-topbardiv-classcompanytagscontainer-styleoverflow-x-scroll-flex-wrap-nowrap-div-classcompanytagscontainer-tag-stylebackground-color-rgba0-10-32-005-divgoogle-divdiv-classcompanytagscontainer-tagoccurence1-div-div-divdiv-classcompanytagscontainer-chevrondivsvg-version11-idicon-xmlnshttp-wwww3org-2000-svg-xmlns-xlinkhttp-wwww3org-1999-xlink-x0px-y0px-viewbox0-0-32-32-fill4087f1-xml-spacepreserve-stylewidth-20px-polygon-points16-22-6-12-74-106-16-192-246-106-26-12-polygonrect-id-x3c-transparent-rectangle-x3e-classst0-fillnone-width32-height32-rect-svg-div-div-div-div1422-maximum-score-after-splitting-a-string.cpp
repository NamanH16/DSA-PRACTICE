class Solution {
public:
    int zz(string x){
        int cnt=0;
        for(char z:x){
            if(z=='0'){
                cnt++;
            }
        }
        return cnt;
    }
    
    int oo(string x){
        int cnt=0;
        for(char z:x){
            if(z=='1'){
                cnt++;
            }
        }
        return cnt;
    }
    
    int maxScore(string s) {
        int mx = 0;
        for(int i=0;i<s.length()-1;i++){
            mx = max(mx, zz(s.substr(0, i+1))+oo(s.substr(i+1, s.length())));
        }
        return mx;
    }
};