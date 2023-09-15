class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int px=abs(fx-sx);
        int py=abs(fy-sy);
        if(px==0 && py==0 && t==1)return false;
        return (min(px,py)+abs(px-py))<=t;
    }
};