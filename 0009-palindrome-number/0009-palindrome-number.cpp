class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long int z = 0;
        long long int a=x;
        while(x!=0){
            z=z*10+x%10;
            x/=10;
        }
        if(a==z)return true;
        return false;
    }
};