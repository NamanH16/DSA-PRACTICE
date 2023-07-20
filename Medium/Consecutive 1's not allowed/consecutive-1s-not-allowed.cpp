//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
const int MOD = 1e9+7;
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    vector<ll> dp(n+1,-1);
	    if(n<=0)return 0;
	    if(n==1 || n==2)return n+1;
	    if(n==3)return 5;
	    dp[0]=0;
	    dp[1] = 2;
	    dp[2] = 3;
	    dp[3] = 5;
	    if(dp[n]!=-1)return dp[n];
	    for(int i=4;i<=n;i++){
	        dp[i] = (dp[i-1]%MOD + dp[i-2]%MOD)%MOD;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends