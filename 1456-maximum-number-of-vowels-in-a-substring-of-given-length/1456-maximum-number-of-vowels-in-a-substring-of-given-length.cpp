class Solution {
private:
    bool helper(char s){
        if(s=='a'||s=='i'||s=='e'||s=='o'||s=='u'){
            return true;
        }
        return false;
    }
    
public:
    int maxVowels(string s, int k) {
        int ans=0, curr=0,n=s.length();
        for(int i=0;i<n;i++){
            curr+=helper(s[i]);
            if(i>=k){
                curr-=helper(s[i-k]);
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};