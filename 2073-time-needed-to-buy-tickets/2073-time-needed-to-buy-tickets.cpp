class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int n = tickets.size();
        for(int i=0;i<n;i++){
            q.push(make_pair(tickets[i], i));
        }
        int time=0;
        while(!q.empty()){
            pair<int,int> temp = q.front();
            q.pop();
            temp.first--;
            time++;
            if(temp.first==0 && temp.second==k){
                break;
            }else if(temp.first!=0){
                q.push({temp.first, temp.second});
            }
        }
        return time;
    }
};