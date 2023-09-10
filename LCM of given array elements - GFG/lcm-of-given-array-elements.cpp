//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long gcd(long long a,long long b){
      return b==0?a:gcd(b,a%b);
  }
  long long lcm(long long a,long long b){
      return (a*b)/gcd(a,b);
  }
    int lcmOfArray(int N , int A[]) {
        // code here
        long long MOD=1000000007;
        long long ans=1;
        for(int i=0;i<N;i++){
            ans=lcm(ans,A[i])%MOD;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout<<ob.lcmOfArray(N,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends