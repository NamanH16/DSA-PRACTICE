class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, ans = 0, mxOccur=INT_MIN;
        unordered_map<int,int>mp;
        for(int j=0;j<s.length();j++){
            mp[s[j]]++;
            mxOccur = max(mxOccur, mp[s[j]]);
            if((j-i+1)-mxOccur>k){
                mp[s[i]]--;
                i++;
            }else{
                ans = max(ans, j-i+1);                
            }
        }
        return ans;
    }
};