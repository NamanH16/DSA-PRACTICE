//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        int mxlen=-1; 
        long long int sum=0;
        unordered_map<long long int,int>mp;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==k){
                mxlen=max(mxlen,i+1);
            }
            long long int target = sum-k;
            if(mp.find(target)!=mp.end()){
                mxlen=max(mxlen,i-mp[target]);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return mxlen==-1?0:mxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends