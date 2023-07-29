class Solution {
public:
    int reverse(int x) {
         long long int ans = 0,temp = x;
        while(temp!=0)
        {
            ans = ans*10+temp%10;
            temp/=10;
        }
        if(ans < INT_MIN || ans > INT_MAX)
            return 0;
        return ans;
    }
};