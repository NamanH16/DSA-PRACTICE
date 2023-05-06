#define MOD 1000000007
class Solution {
private:
    long power(int a,int b){
        // a^b = a*a*a---- b times
        if(b==0)return 1;
        if(b==1)return a;
        long ans=1;
        if(b%2==0){
            ans = power(a,b/2);
            ans*=ans;
        }else{
            ans=power(a,b-1);
            ans*=a;
        }
        return ans%MOD;
    }
    
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0,j=n-1,ans=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans += (power(2,(j-i)));
                ans = ans%MOD;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};