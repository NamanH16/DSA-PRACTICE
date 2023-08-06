class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        if(n==0) return "";
        int st=0,mx = 1;
        for(int i=0;i<n;)
        {
            int j=i,k=i;
            while(j<n-1 && s[j]==s[j+1]){
                j++;
            }
            i = j+1;
            while(k>0 && j<n-1 && s[j+1]==s[k-1]){
                j++;
                k--;
            }
            if(j-k+1>mx){
                mx=j-k+1;
                st=k;
            }
        }
        return s.substr(st,mx);    
    }
};