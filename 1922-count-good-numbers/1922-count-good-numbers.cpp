const int MOD = 1e9+7;
class Solution {
public:
    long long power(long long a,long long b){
        if(b==0)return 1;
        long long ans = power(a, b/2);
        ans *= ans;
        ans %= MOD;
        if(b&1){
            ans*=a;
            ans%=MOD;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long oddPlaces = n/2;
        long long evenPlaces = n/2 + n%2;
        return (power(5,evenPlaces)*power(4,oddPlaces))%MOD;
    }
};