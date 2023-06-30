//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int f(vector<int> &a,int xorval,int index,int k,vector<vector<int>> &dp){
        if(index<0){
            if(xorval==k){
                return 1;
            }
            return 0;
        }
        if(dp[index][xorval]!=-1)return dp[index][xorval];
        int notPick = f(a,xorval,index-1,k,dp);
        int pick = f(a, xorval^a[index], index-1,k,dp);
        return dp[index][xorval]=pick+notPick;
    }
    
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        vector<vector<int>> dp(N, vector<int>(1000, -1));
        return f(arr,0,N-1,K, dp);    
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends