class Solution {
public:
    bool check(vector<int>& dist,int speed,double hour){
        int i=0;
        double time = 0;
        for(; i<dist.size()-1; i++){
            time += ceil((double)dist[i]/speed);
        }
        time += (double)dist[i]/speed;
        return time<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {        
        int low = 1;
        int high = 10000000;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(dist, mid, hour)){
                ans = min(ans,mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};