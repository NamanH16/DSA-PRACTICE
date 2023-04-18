class Solution {
public:
    int addMinimum(string word) {
        int n = word.length();
        int i=0, cnt=0, req=0;
        while(i<n){
            cnt=0;
            if(word[i]=='a'){
                cnt++;
                i++;
            }
            if(i<n && word[i]=='b'){
                cnt++;
                i++;
            }
            if(i<n && word[i]=='c'){
                cnt++;
                i++;
            }
            req+=3-cnt;
        }
        return req;
    }
};