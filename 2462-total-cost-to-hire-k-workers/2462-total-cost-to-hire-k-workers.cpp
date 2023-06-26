class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int can) {
        priority_queue<int,vector<int>,greater<int>> pq1, pq2;
        int cnt=0;
        int i=0, j=costs.size()-1;
        long long ans = 0; 
        while(cnt<k){
            while(pq1.size()<can && i<=j){
                pq1.push(costs[i++]);
            }
            while(pq2.size()<can && j>=i){
                pq2.push(costs[j--]);
            }
            int cost1 = pq1.size()>0?pq1.top():INT_MAX;
            int cost2 = pq2.size()>0?pq2.top():INT_MAX;
            if(cost1<=cost2){
               ans += cost1;
               pq1.pop();
            }
            else{
              ans += cost2;
              pq2.pop();
            }

            cnt++;
        }
        return ans;
    }
};