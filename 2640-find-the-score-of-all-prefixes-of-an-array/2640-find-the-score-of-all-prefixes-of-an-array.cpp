typedef long long ll;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> premax(n);
        int mx = INT_MIN;
        vector<long long int> pre;
        for(int i=0;i<n;i++){
            long long int s=0;
            premax[i]=nums[i]+max(mx,nums[i]);
            s+=premax[i];
            mx=max(mx,nums[i]);
            pre.push_back(s);
        }
        //pre = {4,6,14,12,20}
        ll x=0;
        vector<ll> ans;
        for(int i=0;i<pre.size();i++){
            x+=pre[i];
            ans.push_back(x);
        }
        return ans;
    }
};