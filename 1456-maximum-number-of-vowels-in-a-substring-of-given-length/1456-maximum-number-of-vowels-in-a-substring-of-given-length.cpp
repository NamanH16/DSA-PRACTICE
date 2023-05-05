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
        int i=0, j = 0;
        while(j<n){
            curr+=helper(s[j++]);
            if(j-i==k){
                ans = max(ans, curr);
                curr-=helper(s[i++]);
            }
        }
        return ans;
    }
};