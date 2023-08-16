class Solution {
public:
    int strStr(string haystack, string needle) {
        int x = -1;
        if(haystack.find(needle)!=string::npos){
            x=haystack.find(needle);
        }
        return x;
    }
};