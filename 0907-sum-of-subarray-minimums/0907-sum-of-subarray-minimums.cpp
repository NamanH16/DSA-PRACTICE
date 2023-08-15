class Solution {
public:
    const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n,-1),right(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i]=i-st.top(); // distance between the min and current element
            }else{
                left[i]=i+1;
            }
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=st.top()-i;
            }else{
                right[i]=n-i;
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            long long res=(left[i]*right[i])%MOD;
            res=(res*arr[i])%MOD;
            ans=(ans+res)%MOD;
        }
        return ans;
    }
};