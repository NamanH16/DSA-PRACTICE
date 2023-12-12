class Solution {
public:
    int countTestedDevices(vector<int>& bp) {
        int n = bp.size(), ans=0;
        for(int i=0;i<n;i++){
            if(bp[i]==0){
                continue;
            }else{
                for(int j=i+1;j<n;j++){
                    if(bp[j]==0){
                        continue;
                    }else{
                        bp[j]--;
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};