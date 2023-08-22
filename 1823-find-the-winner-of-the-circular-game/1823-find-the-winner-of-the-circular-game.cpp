class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()!=1){
            int z=k;
            while(z>1){
                int x = q.front();
                q.pop();
                q.push(x);
                z--;
            }
            q.pop();
        }
        return q.front();
    }
};