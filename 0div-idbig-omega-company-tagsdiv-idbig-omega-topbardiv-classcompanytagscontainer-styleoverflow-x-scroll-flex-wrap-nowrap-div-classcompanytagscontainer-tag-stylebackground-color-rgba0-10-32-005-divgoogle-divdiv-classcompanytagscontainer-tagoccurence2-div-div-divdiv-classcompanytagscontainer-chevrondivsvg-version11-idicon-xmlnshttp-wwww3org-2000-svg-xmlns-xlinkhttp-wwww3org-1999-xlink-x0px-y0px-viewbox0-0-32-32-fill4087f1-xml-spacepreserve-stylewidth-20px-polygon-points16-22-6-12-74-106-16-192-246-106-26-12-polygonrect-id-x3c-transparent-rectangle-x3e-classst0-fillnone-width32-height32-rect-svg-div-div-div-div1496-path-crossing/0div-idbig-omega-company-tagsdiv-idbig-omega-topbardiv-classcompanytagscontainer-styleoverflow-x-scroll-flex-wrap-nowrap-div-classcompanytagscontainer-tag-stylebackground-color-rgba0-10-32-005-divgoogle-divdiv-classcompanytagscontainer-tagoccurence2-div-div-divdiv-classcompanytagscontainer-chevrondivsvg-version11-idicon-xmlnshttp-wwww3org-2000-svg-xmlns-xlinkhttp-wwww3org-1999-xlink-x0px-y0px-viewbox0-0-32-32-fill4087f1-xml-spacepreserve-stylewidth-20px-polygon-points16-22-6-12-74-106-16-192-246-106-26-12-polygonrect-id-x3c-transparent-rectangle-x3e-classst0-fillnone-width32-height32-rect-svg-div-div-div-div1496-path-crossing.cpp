class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        st.insert({0,0});
        int i=0, j=0;
        for(char x:path){
            if(x=='N'){
                j++;
            }else if(x=='S'){
                j--;
            }else if(x=='E'){
                i++;
            }else{
                i--;
            }
            if(st.find({i, j})!=st.end()){
                return true;
            }else st.insert({i, j});
        }
        return false;
    }
};