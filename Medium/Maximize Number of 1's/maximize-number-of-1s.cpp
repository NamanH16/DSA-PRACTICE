//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int nums[], int n, int m) {
        // code here
        int zerocnt=0, mxones = INT_MIN, st=0;
        for(int en=0;en<n;en++){
            if(nums[en]==0){
                zerocnt++;
            }
            while(zerocnt>m){
                if(nums[st]==0){
                    zerocnt--;
                }
                st++;
            }
            mxones=max(mxones, en-st+1);
        }
        return mxones;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends