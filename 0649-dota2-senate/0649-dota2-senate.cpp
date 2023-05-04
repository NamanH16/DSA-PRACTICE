class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> qr, qd;
        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                qr.push(i);
            }else{
                qd.push(i);
            }
        }
        while(!qr.empty() && !qd.empty()){
            int a = qr.front();
            int b = qd.front();
            qr.pop();
            qd.pop();
            if(a<b){
                qr.push(a+n);
            }else{
                qd.push(b+n);
            }
        }
        return (qr.size()>qd.size())?"Radiant":"Dire";
    }
};