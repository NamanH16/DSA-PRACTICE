//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long dp[1005][1005];
    long long rec(int i,int j,int arr[]){
        // base case
        if(i+1==j){
            return max(arr[i], arr[j]);
        }
        // cache
        if(dp[i][j]!=-1)return dp[i][j];
        // compute
        long long ans = max(arr[i]+min(rec(i+2,j,arr), rec(i+1, j-1, arr)), arr[j]+min(rec(i+1, j-1, arr), rec(i,j-2, arr)));
        // save and return 
        return dp[i][j]=ans;
    }
    
    long long maximumAmount(int arr[], int n){
        // Your code here
        memset(dp, -1, sizeof(dp));
        return rec(0,n-1,arr);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends